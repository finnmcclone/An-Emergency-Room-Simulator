#ifndef NURSE_H
#define NURSE_H

#include "Worker.h"

class Nurse : public Worker {//inherits from Worker
private:

public:
	Nurse();//constructor
	int available(int currentTime);//returns 2 if available. returns 0 if unavailable
};

#endif