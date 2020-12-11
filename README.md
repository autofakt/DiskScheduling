# DiskScheduling
To compare the performance of disk scheduling algorithms FIFO and SSTF
Objective:
To compare the performance of disk scheduling algorithms FIFO and SSTF.

Specification:
The program compares the disk scheduling algorithms First-in-first-out (FIFO) and Shortest-seek-time-first (STTF) in terms of traversing a set of tracks input by the user, and calculates the number of tracks traversed, the longest delay experienced by a track, and the average delay of all tracks processed later than originally scheduled. A menu controls the operations, and each choice calls the appropriate procedure, where the choices are: 1) Enter parameters; 2) Schedule disk tracks to traverse; 3) Quit program and free memory.

Assignment:
A disk consists of n concentric tracks, numbered 0 through n - 1.
A disk scheduling algorithms accepts a sequence of m integers in the range [0 : n - 1], where each 
integer t is a request to seek to track t.
Each scheduling algorithm generates an ordering according to which the m requests are serviced and calculates: 
(i) the number of tracks traversed; (ii) the longest delay experienced by a track; (iii) the average delay of all tracks 
processed later than originally scheduled.

Ex: Assuming the r/w head starts at track 0, FIFO processes a given sequence of tracks, 
(1, 5, 3, 2, 6, 4), in the given order and thus no track experiences any delay or speedup. 
SSTF processes the same sequence in the order (1, 2, 3, 4, 5, 6). Tracks 2 and 4 are processed 
earlier than under FIFO. The preferential treatment is at the expense of track 5, which is delayed 
by 3 steps, and track 6, which is delayed by 1 step. In the above example, track 5 was delayed by 3 
steps and track 6 by 1 step. The average delay is (3 + 1)/2 = 2.
