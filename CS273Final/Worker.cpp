#include "Worker.h"

void Worker::heal(int currentTime, int severity)
{
	//sets availableTime to the currentTime + the time to treat (severity of the patient)
	availableTime = currentTime + severity;
}
