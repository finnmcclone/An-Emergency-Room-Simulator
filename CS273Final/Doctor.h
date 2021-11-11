#ifndef DOCTOR_H
#define DOCTOR_H

#include "Worker.h"

class Doctor : public Worker {//inherits from Worker
private:

public:
	Doctor();//constructor
	int available(int currentTime);//returns 1 if available. returns 0 if unavailable
};

#endif