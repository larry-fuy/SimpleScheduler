// Simulator for the scheduler
#include"simulator.hpp"
#include<cstdlib>

void
Simulator::run() {
  // This is the time-driven simulation algorithm.
  // The basic idea is to pick a job and put it on the available node
  for (auto i = 0; i < sim_time; ++i) {
    // job and resource at each time
    Job new_job = get_input_job(i);
    resource_t new_resource = get_input_resource();

    // scheduler updates jobs and resources
    sch->update_jobs(new_job);
    sch->update_resources(new_resource);

    // simulator update jobs and resources for statistics
    update(new_job, new_resource, i);

    // schedule
    vector<Job> sch_j;
    vector<int> sch_r;
    sch->run(sch_j, sch_r);

    // run job on a node
    run_job(sch_j, sch_r, i);
  }
}

void 
Simulator::collect() {
  // utilization average twice. 
  // 1) along the number of resources
  // 2) along the time 
  // Todo : it seems a bug here
  util_file << "average utilization: " << endl;
  vector<double> util_sum(num_node, 0);
  for (size_t i = 0; i < sim_time; ++i) {
     for (size_t j = 0; j < num_node; ++j) {
        util_sum[j] += double(resources_util[i][j]) / num_cpus; 
     }
  }
  
  for (size_t i = 0; i < num_node; ++i) {
     util_file << util_sum[i] / sim_time << endl;
  }
  
  // latency 
  latency_file << " average latency: " << endl;
  int latency_sum = 0;
  for_each(begin(jobs), end(jobs), [&latency_sum](Job j) { latency_sum += j.exec - j.start;});
  latency_file << long(latency_sum) / long(sim_time) << endl;

  // log
  for (const auto& job : jobs) {
    log_file << "job : " << job.Id 
	     << " size : " << job.size
	     << "  start : " << job.start 
	     << "  exec : " << job.exec
	     << " node : " << job.node
	     << endl;
  }
}

void
Simulator::run_job(vector<Job> sch_j, vector<int> sch_r, int time) {
  // no job scheduled
  if (sch_j.empty() && sch_r.empty()) return;
  
  // job schedule
  for (size_t i = 0; i < sch_j.size(); ++i) {
    jobs[sch_j[i].start].exec = time;
    jobs[sch_j[i].start].node = sch_r[i];
    // resources are used
    resources_util[time][sch_r[i]] += sch_j[i].size;
  }
}  

Job
Simulator::get_input_job(int time) {
  // generate a job with random size
  Job j;
  j.Id = time;
  j.size = rand() % max_size + 1;
  j.start = time;
  j.exec = sim_time + 1;
  j.node = -1;
  return j;
}

int
Simulator::get_input_resource() {
  // generate a resource
  return rand() % num_node;
}

void
Simulator::update(Job new_job, resource_t new_resource, int time) {
  jobs[time] = new_job;
  resources_util[time][new_resource]++;
}
