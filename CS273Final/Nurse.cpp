#include "Nurse.h"

Nurse::Nurse()//constructor
{
	//sets availableTime to the starting time
	availableTime = 0;
}

int Nurse::available(int currentTime)
{
	//if the currentTime is or is past the availableTime, the nurse is available
	if (currentTime >= availableTime) {
		return 2;
	}
	return 0;
}
