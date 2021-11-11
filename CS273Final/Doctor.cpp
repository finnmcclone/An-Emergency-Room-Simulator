#include "Doctor.h"

Doctor::Doctor()//constructor
{
	availableTime = 0;//sets availableTime to the start
}

int Doctor::available(int currentTime)
{
	//if the currentTime is or is past the availableTime, the doctor is available
	if (currentTime >= availableTime) {
		return 1;
	}
	return 0;
}
