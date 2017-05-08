/**
 * Arman Ashrafian
 * CS 1C
 * Design Patterns Extra Credit
 * 5-8-2017
 */

#include "JobQueue.h"


int main() {

    JobQueue* jb = JobQueue::getInstance();

    int jobNumber;
    Job newJob;

    jb->addJob("Job1");
    jb->addJob("Job2");
    jb->addJob("Job3");
    jb->addJob("Job4");
    jobNumber = jb->addJob("Job5");

    jb->printQueue();
    std::cout << std::endl;

    std::cout << jobNumber << " jobs in the queue\n" << std::endl;

    jb->cancelJob(3);
    jb->cancelJob();

    std::cout << "Jobs in the queue after cancelJob(3) and cancelJob():\n" << std::endl;
    jb->printQueue();

   std::cout << std::endl << "cancelJob(6): ";
   jb->cancelJob(6);
   std::cout << "\n";

   // cancel remaining jobs
   jb->cancelJob();
   jb->cancelJob();
   jb->cancelJob();

   std::cout << "\nCalling cancelJob() on empty queue: ";
   jb->cancelJob();

   return 0;
}
