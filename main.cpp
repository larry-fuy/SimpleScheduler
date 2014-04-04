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
  Job* job = new Job();
  Scheduler* sch = new FCFS();
  Simulator sim(sch, job, SIMU_TIME, NUM_NODE, NUM_CPUS);

  // run simulator
  sim.run();

  // output the statistics of cluster 
  sim.collect();

  // output the statistics of jobs
  job->collect();
}
