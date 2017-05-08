/**
 * Arman Ashrafian
 * CS 1C
 * Design Patterns Extra Credit
 * 5-8-2017
 */

#ifndef EXTRACREDIT_JOBQUEUE_H
#define EXTRACREDIT_JOBQUEUE_H

#include <iostream>
#include <string>
#include <vector>

/** Job **/
struct Job {
	int jobNumber;
	std::string jobName;
};

class JobQueue {
public:
	/** Constructor **/
    JobQueue();

    /** Singeleton: Get Instance **/
    static JobQueue* getInstance();

    /** Add Job
     * Adds job to the queue
     * Returns the job number
     */
    int addJob(std::string jobName);

    /** Cancel Job
     * Cancels specified job, cancels first
     * job in the queue if no job number is specified
     */
    void cancelJob(int jobNumber = 0);

    /** Print Queue
     * Outputs the contents of the queue
     */
    void printQueue();


private:
    std::vector<Job> queue; /** Queue Data Structure */

    static bool created;			/** True if instance of JobQueue has been created */
    static JobQueue *myInstance;	/** Pointer to the JobQueue instance (Singleton) */
};


#endif //EXTRACREDIT_JOBQUEUE_H
