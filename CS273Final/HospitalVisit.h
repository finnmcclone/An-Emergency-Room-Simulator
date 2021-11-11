#ifndef HOSPITALVISIT_H
#define HOSPITALVISIT_H

#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

class HospitalVisit {
private:
	int severity;//severity of patient
	int entranceTime;//time admited to hospital
	int timeHealed;//time started treated by doctor
public:
	HospitalVisit(int currentTime);//constuctor
	void healed(int currentTime);//sets timeHealed
	int getSeverity();//returns severity
	int getTime();//returns total time at hospital
	void print();//prints record of visit
};

#endif