#include "HospitalVisit.h"

HospitalVisit::HospitalVisit(int currentTime) {//constructor
	entranceTime = currentTime;//sets entranceTime to currentTime

	//randomly assigns severity level
	int i = rand() % 10;
	if (i < 1) {//16-20
		severity = 16 + i / 2;
	}
	else if (i < 3) {//11-15
		severity = 11 + i / 2;
	}
	else {//1-10
		severity = i + 1;
	}

	//sets time heald to be negative in the instance that the patient is never treated
	timeHealed = -21;
}

void HospitalVisit::healed(int currentTime)
{
	//sets timeHealed to the currentTime
	timeHealed = currentTime;
}

int HospitalVisit::getSeverity()
{
	//returns the severity of the patient
	return severity;
}

int HospitalVisit::getTime()
{
	//returns the total time the patient was in the hospital
	return timeHealed + severity - entranceTime;
}

void HospitalVisit::print()
{
	//prints record of visit
	cout << "Time Admitted: " << entranceTime << endl;
	cout << "Time Cared For: " << timeHealed << endl;
	cout << "Severity: " << severity << endl;
}
