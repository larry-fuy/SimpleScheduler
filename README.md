SimpleScheduler
===============

Schedulers design and evaluation in simple case 

Problem
===============
[SCENARIO]
As a fearless distributed systems engineer at Mesosphere, you have a great idea for a new resource-scheduling algorithm for large-scale data centers. Assume that the current scheduler is a simple first-come, first-served model which doesn't always yield optimal results. To convince your co-workers of the merits of your new scheduler, you must write a simulator that demonstrates how your scheduler outperforms the default on at least one set of test data.

[INPUTS]
Available resources can be represented as a simple integer stream, for example:
2 7 1 8 2 8 1 8 2 8 4 5 9 0 4 5 2 3 5 3 6 ...
Which should be interpreted as:
A resource unit is available on compute node #2,
A resource unit is available on compute node #7,
A resource unit is available on compute node #1,
and so on. Each node can have multiple resource units (e.g. multiple cpus).

As these resources become available, the scheduler assigns them to incoming jobs of various sizes. For example, a job of size two requires two units from the resource stream to run - the compute node origin of the resources used is not important. Incoming job requests can also be represented as an integer stream, for example: 3 1 4 1 5 9.

[OUTPUT]
To prove that your scheduling algorithm satisfies its objective, print out the final schedule and any useful statistics. That may be enough to convince your co-workers, but feel free to elaborate.

