#include "JobQueue.h"

int main() {

    JobQueue* jb = JobQueue::getInstance();

    int jobNumber;

    jb->addJob("Job1");
    jb->addJob("Job2");
    jb->addJob("Job3");
    jb->addJob("Job4");
    jobNumber = jb->addJob("Job5");

    jb->printQueue();
    std::cout << '\n';

    std::cout << jobNumber << " jobs in the queue\n" << std::endl;

    jb->cancelJob();
    jb->cancelJob(3);



    std::cout << "Jobs in the queue after cancelJob() and cancelJob(3)\n" << std::endl;
    jb->printQueue();

    return 0;
}