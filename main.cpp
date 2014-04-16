// Simulator for the scheduler
#include"job.hpp"
#include"scheduler.hpp"
#include"simulator.hpp"

// simulation parameters
// Todo : read parameters from configuration file
const int SIMU_TIME = 100;
const size_t NUM_NODE = 8;
const size_t NUM_CPUS = 8;
const size_t MAX_SIZE = 4;   // max size of the job, in real world no such limit

int main() {

  // initialization
  Scheduler* sch = new FCFS(NUM_NODE);
  Simulator sim(sch, SIMU_TIME, NUM_NODE, NUM_CPUS, MAX_SIZE);
  // run simulator
  sim.run();
  // output the statistics of cluster 
  sim.collect();
}
