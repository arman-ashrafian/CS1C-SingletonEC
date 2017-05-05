#ifndef EXTRACREDIT_JOBQUEUE_H
#define EXTRACREDIT_JOBQUEUE_H

#include <iostream>
#include <string>
#include <vector>

class JobQueue {
public:
    JobQueue();

    static JobQueue* getInstance();

    int addJob(std::string jobName);

    void cancelJob(int jobNumber = 0);

    void printQueue();


private:
    std::vector<std::string> queue;

    static bool created;
    static JobQueue *myInstance;
};


#endif //EXTRACREDIT_JOBQUEUE_H
