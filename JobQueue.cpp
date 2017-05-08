/**
 * Arman Ashrafian
 * CS 1C
 * Design Patterns Extra Credit
 * 5-8-2017
 */

#include "JobQueue.h"
#include <exception>

class InvalidRequest : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Invalid Request on Queue";
	}
} InvalidRequest;


bool JobQueue::created = false;
JobQueue* JobQueue::myInstance = NULL;

JobQueue::JobQueue() {}

JobQueue* JobQueue::getInstance() {
    if(!created) {
        myInstance = new JobQueue();
        created = true;
    }
    return myInstance;
}

int JobQueue::addJob(std::string jobName) {
	Job newJob;
	newJob.jobName = jobName;
	newJob.jobNumber = queue.size() + 1;
    queue.push_back(newJob);

    return newJob.jobNumber;
}


void JobQueue::cancelJob(int jobNumber) {

	try {
		if(queue.size() == 0) {
			throw InvalidRequest;
		}

		else if(jobNumber == 0) {
	        // remove the first job
	        queue.erase(queue.begin());
	    } else {
	        // remove specified job
	    	int jobIndex = -1;
	    	for(int i = 0; i < queue.size(); i++) {
	    		if(queue.at(i).jobNumber == jobNumber) {
	    			jobIndex = i;
	    		}
	    	}
	    	if(jobIndex == -1) throw InvalidRequest;

	        queue.erase(queue.begin() + jobIndex);
	    }

	}
	catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void JobQueue::printQueue() {
    for(unsigned int i = 0; i < queue.size(); i++) {
    	std::cout << queue.at(i).jobNumber << "\t" << queue.at(i).jobName
    			  << std::endl;
    }
}

