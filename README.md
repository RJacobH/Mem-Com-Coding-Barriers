# Mem-Com-Coding-Barriers
Solutions for question 2 of the Mem-Com-Coding assignment

Below is an explanation of the goals of my code as well as answers to the written part of this assignment.


(a) Implementation
  In theory this isn't that difficult. I made a little intro that deals with user input well, and puts the necessary information into variables the code could understand. I wrote code for the Centralized Barrier that I'm proud of, but didn't manage to make working Dissemination Barrier code, and didn't progress at all with the MCS Barrier code. Since I only wrote the spine of the whole code, and the Centralized Barrier code, I'll just talk about what I did with that for a bit.
  
One of the things I want to bring to attention is the way I stored and accessed the thread IDs. I created a global variable d (for dictionary), which is a pointer to some unsigned long data. It gets allocated enough data with calloc to store however many threads are being used. It stores two pieces of info for each thread, an integer that marks the ordinal assignment of that thread, and the address of the thread in memory. This dictionary is used to maintain comprehensibility of the thread for both the user and the machine. 

Another thing that is worth noting is the apparent necessity to include sleep or usleep at several key places in the code. They are mainly used while threads are spinning. If they aren't there, or the values are too low (or too high), each thread except the last one seems to be cut off (for the Centralized Barrier at least).


(b) Correctness Testing
For the Centralized Barrier to be correct, it needs to refrain from allowing any thread past the barrier until all threads have reached the barrier. This is the case for my code as the sense is reversed when the Pth of P threads reaches the barrier. This will only happen once all the threads are at the barrier. So it is correct.


(c) Performance Testing
  I did not do this.
  
  
(d) Graphing
  I did not do this.
  
  
(e) Analysis
  Each of the barrier types offers benefits and drawbacks. Centralized Barriers are extremely space efficient, and so can be the right choice when there are very few threads that need to be synchronized. However, they perform very poorly with larger numbers of threads. Dissemination Barriers are great in their ability to have extremely consistent runtime, but take up relatively large space to do so. MCS Barriers achieve theoretical minimum messages, and are space efficient. Although they do have a little bit more overhead than Centralized Barriers. For any but the smallest sets of threads, I would rely on MCS barriers.
  
I don't feel able to make real insights about the hardware or scheduler of my computer given my lack of significant data. However, it appears there are upwards of 3,400 Threads available on my computer based on the Activity Monitor's data. I'm sure there are significantly more that are relatively invisible to the user.
