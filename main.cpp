// Simulator for the scheduler
#include<iostream>
#include"scheduler.hpp"
#include"simulator.hpp"
#include"job.hpp"

int main() {
  // simulation time
  const int SIMU_TIME = 10000;
  const size_t NUM_NODE = 16;
  const size_t NUM_CPUS = 4;

  // initialization
  Jobs* jobs = new Jobs(SIMU_TIME);
  Scheduler* sch = new FCFS();
  Simulator sim(sch, jobs, SIMU_TIME, NUM_NODE, NUM_CPUS);
  // generate jobs
  jobs->generate();

  // run simulator
  sim.run();

  // output the statistics of cluster 
  sim.collect();

  // output the statistics of jobs
  jobs->collect();
}
