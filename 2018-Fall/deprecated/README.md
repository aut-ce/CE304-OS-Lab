# OS-Lab

## Introduction
Operating Systems Laboratory Materials. In this course we try to do some C and system programming in Ubuntu.

## Syllabus
1. Introduction to Linux
2. [Linux Kernel Module](s2/)
3. Bash Programming
4. Threads and Processes
5. Inter-Process Communication
6. Synchronization
7. Deadlock
8. Scheduling
9. OpenMP

## Final Project
Students built a synchronized queue earlier. They use this with the sample client-server application,
that they learned it in the TCP programming session, for adding a pipeline to the requests handling stage
of their TCP's client-server application.

As an example when a request comes, the program accepts then adds it into the queue.
Handlers are in the running state and read the shared queue within a loop, therefore,
they read the request in the random fashion next send its response.
