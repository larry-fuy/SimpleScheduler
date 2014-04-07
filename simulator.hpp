#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>


#include"job.hpp"
#include"scheduler.hpp"

using namespace std;

typedef vector<vector<int>> resources_util_t;

class Simulator {
private:
  Scheduler* sch;
  int sim_time;
  size_t num_node;
  size_t num_cpus;
  size_t max_size; 

  resources_util_t resources_util;
  jobs_t jobs;

  // For results
  ofstream util_file;
  ofstream latency_file;
  ofstream log_file;

public:
  Simulator(Scheduler* s, const int t, const size_t nn, const size_t nc, const size_t sz) :
    sch(s), sim_time(t), num_node(nn), num_cpus(nc), max_size(sz) {
    resources_util.resize(sim_time, vector<int>(num_node, 0));
    jobs.resize(sim_time);
    // utilization file
    util_file.open("util.txt");
    // latency file
    latency_file.open("latency.txt");
    // file to log
    log_file.open("log.txt");
    log_file << "simulation time : " << sim_time << endl
	     << "number of node : " << num_node << endl
	     << "number_cpus : " << num_cpus << endl
	     << "job max size : " << max_size << endl;
    log_file << endl;
  }

  ~Simulator() { 
    util_file.close(); 
    latency_file.close();
    log_file.close();
  }

  // run simulator
  void run();
  
  // put job on the resources the scheduller pick
  void run_job(jobs_t j, resources_t r, int time);
  
  // update when new job and resource available
  void update(Job j, resource_t r, int time);

  // one input  job
  Job get_input_job(int time);
  
  // one input resource
  int get_input_resource();  

  // collect statistics
  void collect();
};
