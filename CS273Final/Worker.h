#ifndef WORKER_H
#define WORKER_H

class Worker {//parent class of nurse and doctor
private:
	
public:
	virtual int available(int currentTime) = 0;//pure virtual method to give status worker
	void heal(int currentTime, int severity);//sets available time
protected:
	int availableTime;//gives time when worker is next available
};

#endif