#pragma once
#include<vector>
#include<algorithm>

#include"job.hpp"
#include"scheduler.hpp"
#include"simulator.hpp"

using namespace std;

typedef vector<vector<int>> utilization_t;

class Simulator {
private:
  Scheduler* sch;
  Job* job;
  int sim_time;
  size_t num_node;
  size_t num_cpus;

  utilization_t util;

public:
  Simulator(Scheduler* s, Job* j, const int t, const size_t nn, const size_t nc) :
    sch(s), sim_time(t), num_node(nn), num_cpus(nc) {
    // initialize the utilization
  };

  ~Simulator() {};

  // run simulator
  void run();

  // collect statistics
  void collect();
};
