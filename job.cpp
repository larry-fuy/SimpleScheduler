// Job
#include "job.hpp"

void
Jobs::collect() {
}

void
Jobs::generate() {
  // generate random size jobs 
  for (auto i = 0; i < time; ++i) {
    Job j;
    j.start = i;
    j.length = rand() % max_size;
    j.end = 0;
    job_queue.push_back(j);
  }
}
