#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>


#include"job.hpp"
#include"scheduler.hpp"

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
  // for results
  ofstream util_file;
  vector<vector<int>> cluster;
  vector<int> resources;

public:
  Simulator(Scheduler* s, Jobs* j, const int t, const size_t nn, const size_t nc) :
    sch(s), sim_time(t), num_node(nn), num_cpus(nc) {
    resources.resize(sim_time);

    // utilization file
    util_file.open("util.dat");

    // cluster init
    for (auto i = 0; i < num_node; ++i)
      cluster.push_back(vector<int>(num_cpus, 0));

    // resource input generate or  it can be read from files
    for (auto i = 0; i < sim_time; ++i) 
      resources[i] = rand() % num_node;
  };

  ~Simulator() { 
    util_file.close();
};

  // run simulator
  void run();

  // collect statistics
  void collect();
};
