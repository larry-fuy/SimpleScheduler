// Jobs
#pragma once
#include<vector>
#include<cstdlib>

using namespace std;
struct Job {
    int length; // size
    int start;  // staring time
    int end;   // end time
  };

class Jobs {
  int time;
  int max_size; 
  vector<Job> job_queue;

public:
  Jobs(int t) : time(t), max_size(10) {};

  Jobs(int t, int s) : time(t), max_size(s)  {};

  // generate the random size jobs set, however this can be read from files.
  void generate();
  // collect statistics
  void collect();
  // get a job from the job sets
  Job get_job(int i);
};
