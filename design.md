Problem 
=============== 

 Assume that the current scheduler is a simple first-come,
first-served model which doesn't always yield optimal results. To
convince your co-workers of the merits of your new scheduler, you must
write a simulator that demonstrates how your scheduler outperforms the
default on at least one set of test data.

* INPUTS : Available resources can be represented as a simple integer stream, for example:
2 7 1 8 2 8 1 8 2 8 4 5 9 0 4 5 2 3 5 3 6 ...
Which should be interpreted as:
A resource unit is available on compute node #2,
A resource unit is available on compute node #7,
A resource unit is available on compute node #1,
and so on. Each node can have multiple resource units (e.g. multiple cpus).

As these resources become available, the scheduler assigns them to
incoming jobs of various sizes. For example, a job of size two
requires two units from the resource stream to run - the compute node
origin of the resources used is not important. Incoming job requests
can also be represented as an integer stream, for example: 3 1 4 1 5
9.

* OUTPUT : To prove that your scheduling algorithm satisfies its
objective, print out the final schedule and any useful
statistics. That may be enough to convince your co-workers, but feel
free to elaborate.

Assumptions 
=============== 

1.  A job is assume to have a resources requirement. We assume the job
can run one multiple CPUS but sticks on one node.  And the job is not
preemptable. Again it is the consideration of performance and may not
be true in real world.

2. A node has multiple resources, in current stage we only assume the
resource is CPU.
 

Algorithm 
=============== 

The algorithm used here is a very simple "time driven" algorithm. The
time increase one unit and simulator forward one step to generate
resources and jobs. However in large scale simulation, this algorithm
is highly inefficient. A better algorithm is an event driven
algorithm, which sees new reources and new jobs as events. The events
are stored in a queue, the simulator will pick the top element of the
queue to ask scheduler to make decision. This algorithm is generally
used in the some famous simulators. However considering time limit,
time-driven algorithm is easier to be implented. But there is no
difficulty to implement the event-driven algorithm given enough
time.

The detailed algorithm :
intialize simulator, jobs and resources

	while ( t < simulation_time) 
      	  	pick the first job from the job queue (scheduler)
      	  	put the job the first availabe resources (first fit)
	end

simulator collects statistics of resources



Architecture
===============

There are 3 classes, Simulator, Scheduler and Job.
* Simulator works for 1) generate job and resources input, 2) run simulation, 3) collect statistcs
* Scheduler works for choosing jobs on suitable resources
* Job only provide a type ( may extent to have other properties)

Note: the resource and job set may be read from the file or other external sources (Todo) . 

Build and run
===============
1.  make

2.  run simu

3.  results in util.dat and jobs.dat


Results 
=============== 

1.  util.txt includes average utilization of each node along simulation time

2.  jobs.txt include average latency of all jobs 

3.  There are many metrics to compare scheduling algorithm. For
example, in real-time systems which is my major research topic, it
uses missratio, how many jobs missed their deadlines. In this case, I
choose two common metrics to represent performance of the scheduler:
utilzation of the cluster and latency of the jobs.

* Utlization means how much resources are consumed by the
workload. In this case, I choos a coarse granuality index to show
it. Given a node with 4 CPUs, if 3 of them are used, the utilization
is 3 / 4 = 75%. Since this is a coarse granuality, it may not be a
good index for the true utilization. In real-world systems or
simulator, the counter of CPU usage is often used for this purpose.

* Latency means the time between tasks starting and put to executing. This
is a important index from the perspective of the client. In batch
systems, this index reflects the system throughtput.  c) There are
many other metrics to show how good a scheduling algorithm is, for
example, queue length. Again due the simplicity of htis case and
timing issue, I choose the above two indexs.

