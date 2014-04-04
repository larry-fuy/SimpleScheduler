// Scheduler
#pragma once
#include<queue>
#include<algorithm>

#include "job.hpp"

using namespace std;

//base class
class Scheduler {
public:
  Scheduler() {};
  virtual Job get_job() {};
  virtual Job set_job() {};
  virtual ~Scheduler() {};
};

// First come first serve scheduler
class FCFS: public Scheduler {
public:
  FCFS(queue<Job>* j) : jobs(j) {}
  virtual Job get_job() {
    Job j = jobs->front();
    jobs->pop();
    return j;
  }
  virtual void set_job(Job j) {
    jobs->push(j);
  }
  virtual ~FCFS() { }
private:
  queue<Job>* jobs;
};

// 
