
#include "JobQueue.h"


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
    queue.push_back(jobName);
    return queue.size();
}


void JobQueue::cancelJob(int jobNumber) {
    if(jobNumber == 0) {
        // remove the first job
        queue.erase(queue.begin());
    } else {
        // remove specified job
        queue.erase(queue.begin() + jobNumber - 2);
    }
}

void JobQueue::printQueue() {
    for(auto j : queue) {
        std::cout << j << std::endl;
    }
}

