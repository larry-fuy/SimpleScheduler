// Simulator for the scheduler
#include"simulator.hpp"

void
Simulator::run() {
  // This is the time-driven simulation algorithm.
  // The basic idea is to pick a job and put it on the available node
  for (auto i = 0; i < sim_time; ++i) {
    // pick a job the first availabe resources to run a job. 
    if (resources[i] != -1) {
      // the resources is not availabe now. 
      cluster[resources[i]][0] = 1;
      // the scheduler chose a job on the resources
    }
    
  }

}

void 
Simulator::collect() {
  util_file << "average utilization:" << endl;
}
