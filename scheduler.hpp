// Scheduler
#pragma once
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>

#include "job.hpp"

using namespace std;

typedef vector<int> resources_t;
typedef int resource_t;
typedef queue<Job> jobs_que_t;
typedef vector<Job> jobs_t;

//abstract class
class Scheduler {
public:
  virtual void run(jobs_t& jobs, resources_t& resources) = 0;
  virtual void update_jobs(Job j) = 0;
  virtual void update_resources(resource_t r) = 0;
};

// First come first serve scheduler
class FCFS: public Scheduler {
public:
  FCFS(int num_node)  {
    resources.resize(num_node, 0); 
  };
  ~FCFS() {};

  virtual void update_jobs(Job j)  {
    jobs_que.push(j);
  }
  
  virtual void update_resources(resource_t r) {
        resources[r]++;
  }

  virtual void run(jobs_t& jobs, resources_t& resources);

 private:
  jobs_que_t jobs_que;
  resources_t resources;
};

// 
