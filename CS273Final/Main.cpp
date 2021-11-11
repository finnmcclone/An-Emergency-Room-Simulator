//names: Finn McClone, Spencer Gariano, and James Holtz
//course: CS273
//project: Final


//hospital simulaiton


#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
using std::queue;
using std::priority_queue;
using std::map;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::pair;

#include "Doctor.h"
#include "HospitalVisit.h"
#include "Nurse.h"
#include "Worker.h"

int main() {
	//use file to make map of names
	std::ifstream simVille;
	simVille.open("Residents_of_273ville.txt");
	string name;

	//maps for accessing id numbers, hospital records, and people;
	int numPeople = 0;
	map<string, int> people;
	map<int, vector<HospitalVisit*>> hospitalRecords;
	map<int, string> IdNumber;

	//empty record to place with every person
	vector<HospitalVisit*> emptyRecord;
	//reads through the .txt file of names to generate people and id numbers
	for (int i = 1;  getline(simVille, name); i++) {
		numPeople++;
		people.insert(pair<string, int>(name, i));
		IdNumber.insert(pair<int, string>(i, name));
		hospitalRecords.insert(pair<int, vector<HospitalVisit*>>(i, emptyRecord));
	}

	
	//request num of doctors, nurses, and patients per hour
	int numDoctor;
	cout << "Enter number of doctors: ";
	cin >> numDoctor;

	int numNurse;
	cout << "Enter number of nurses: ";
	cin >> numNurse;

	int patientsPerHour;
	cout << "Enter number of patients per hour: ";
	cin >> patientsPerHour;

	//vector of workers
	vector<Worker*> workers;
	int numWorkers = numDoctor + numNurse;

	//add the doctros to workers
	for (int i = 0; i < numDoctor; i++) {
		workers.push_back(new Doctor);
	}
	//add the nurses to the workers
	for (int i = 0; i < numNurse; i++) {
		workers.push_back(new Nurse);
	}

	//queues for available workers
	queue<Worker*> availableDoc;
	queue<Worker*> availableNur;
	//queues fro new patients and to sort  patients into high and low severity
	priority_queue<HospitalVisit*> highSeverity;
	priority_queue<HospitalVisit*> lowSeverity;
	priority_queue<HospitalVisit*> waitingRoom;


	//loop of simulation
	for (int time = 0; time < 60 * 24 * 7; time++) {//each loop is one min. Simulation lasts one week
		//get finished workers and place in respective queues
		for (int i = 0; i < numWorkers; i++) {
			if (workers[i]->available(time) == 1) {
				availableDoc.push(workers[i]);
			}
			else if (workers[i]->available(time) == 2) {
				availableNur.push(workers[i]);
			}

		}

		//make new patient
		if (rand() % 60 + 1 <= patientsPerHour) {
			int patient = rand() % numPeople + 1;
			hospitalRecords[patient].push_back(new HospitalVisit(time));
			waitingRoom.push(hospitalRecords[patient].back());
		}

		//sorts new patients into queues of severity
		while (!waitingRoom.empty()) {
			if (waitingRoom.top()->getSeverity() > 10) {
				highSeverity.push(waitingRoom.top());
				waitingRoom.pop();
			}
			else {
				lowSeverity.push(waitingRoom.top());
				waitingRoom.pop();
			}
		}

		//assigns high severity patients to doctors
		while (!highSeverity.empty() && !availableDoc.empty()) {
			availableDoc.front()->heal(time, highSeverity.top()->getSeverity());
			highSeverity.top()->healed(time);
			availableDoc.pop();
			highSeverity.pop();
		}
		//assigns low severity patients to nurses
		while (!lowSeverity.empty() && !availableNur.empty()) {
			availableNur.front()->heal(time, lowSeverity.top()->getSeverity());
			lowSeverity.top()->healed(time);
			availableNur.pop();
			lowSeverity.pop();
		}
		//assigns low severity patients to doctors
		while (!lowSeverity.empty() && !availableDoc.empty()) {
			availableDoc.front()->heal(time, lowSeverity.top()->getSeverity());
			lowSeverity.top()->healed(time);
			availableDoc.pop();
			lowSeverity.pop();
		}

		//remove left over workers
		while (!availableDoc.empty()) {
			availableDoc.pop();
		}
		while (!availableNur.empty()) {
			availableNur.pop();
		}
	}

	//used to find average time and output
	float totalT = 0;
	int numOfRecords = 0;
	int numNotServed = 0;
	//used to get list of patients who where treated at the hospital
	bool hasRecord;
	vector<string> peopleWithRecords;

	//loops through all people and their hospital visits to find average time
	for (int i = 0; i < numPeople; i++) {
		hasRecord = false;
		for (int j = 0; j < hospitalRecords[i + 1].size(); j++) {
			if (hospitalRecords[i + 1][j]->getTime() > 0) {
				totalT += hospitalRecords[i + 1][j]->getTime();
				numOfRecords++;
				hasRecord = true;
			}
			else {
				//number of patients who were not treated
				numNotServed++;
			}
		}
		if (hasRecord) {
			peopleWithRecords.push_back(IdNumber[i+1]);
		}
	}

	//output average time
	system("CLS");
	cout << "Average Time Per Visit: " << totalT / numOfRecords << endl;
	cout << "Number Of Visits Not Completed: " << numNotServed << endl;

	//output people treated
	cout << "People Treated: " << endl;
	for (int i = 0; i < peopleWithRecords.size(); i++) {
		cout << "\"" << peopleWithRecords[i] << "\"" << " ";
	}
	cout << "\n\n";

	//asks userif they want to see any specific persons hospital record
	while (true) {
		cout << "Input name of who you want to see records of.\nStop by inputing \"0\"\n";
		string name;
		cin >> name;
		if (name == "0") {
			break;
		}
		cout << "The records of " << name << ":" << endl;
		for (int i = 0; i < hospitalRecords[people[name]].size(); i++) {
			cout << "Visit: " << i+1 << endl;
			hospitalRecords[people[name]][i]->print();
		}
		cout << "\n\n";
	}

	return 0;
}