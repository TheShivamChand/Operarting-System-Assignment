# Operarting-System-Assignment
In the traffic intersection problem, vehicles are trying to pass through an
intersection of two roads, one north/south, the other east/west, without
colliding. Each vehicle arrives at the intersection from one of four
directions (north, south, east, or west), called it’s origin . It is trying to pass
through the intersection and exit in some direction other than its origin,
called it’s destination.
Each arriving vehicle is simulated by a thread, and the intersection is a
critical section. Each vehicle (thread) enters the intersection (critical
section) and eventually leaves. However, you may not change this file in
any way. The vehicle simulation works by creating a fixed number of
concurrent threads. Each thread simulates a sequence of vehicles
attempting to pass through the intersection. In a loop, each thread
generates a random vehicle (randomly choosing an origin and destination
for the vehicle) and then enters and leaves the critical section to simulate
the vehicle passing through the intersection. Threads then sleep for a
configurable period of time before generating another random vehicle and
repeating the process. Each thread simulates one vehicle at a time.
However, since there are multiple concurrent threads, there may be
multiple vehicles attempting to enter the critical section (intersection) c
ncurrently.
The job is to synchronize the vehicles so that they do not collide in the
intersection.
