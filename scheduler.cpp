// Scheduler
#include "scheduler.hpp"
#include <iostream>

void
FCFS::run(jobs_t& sch_j, resources_t& sch_r) {
  
  while( !jobs_que.empty() ) {
    bool find = false;
    Job j = jobs_que.front();
    for (size_t i = 0; i < resources.size(); ++i) {
      // first fit 
      if (resources[i] >= j.size) {
        sch_j.push_back(j);
	sch_r.push_back(i);
	jobs_que.pop();
	resources[i] -= j.size;
	find = true;
        break;
      }
    }
    // not find fit resource
    if (!find) break;
  }
    
}
