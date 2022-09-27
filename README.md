# COP-4534-Project2-Queue-Simulation
Project 2 - A Queue Simulation

The purpose of this assignment is to explore several ideas:

-Event-driven programming.

-Modeling and simulation

-Analytical Models
 

**Event-driven programming is a fundamental model of computation in which the program responds to events in certain ways.**

**Real-time programming is a special type of event-driven programming in which there are absolute (computable) upper limits on the amount of time the program can take to respond to events.**

 

  For our problem, we will assume that we have been hired by a local company to consider the throughput for a new service center that may have a varying number 
(let's call it M) of service channels. We will simulate customers passing through this system by using **BOTH a priority queue and a standard FIFO queue.**
Your program MUST work as specified here.
```
The customers will arrive randomly with times following the Poisson distribution. Suppose a store averages 10 arrivals per hour. 

  The Poisson distribution can be used to determine the probability of no arrivals, 1 arrival, 5 arrivals, 15 arrivals, 
  etc., given that average. 

  The Poisson distribution can be transformed into a continuous probability distribution 
  called a negative exponential distribution (which we will use) 
  which produces random time intervals which, when run in large numbers, will yield an appropriate average time. 

  For instance, if average arrivals are 3 per time unit (which we will NOT specify, could be milli-seconds, seconds, or hours), 
  the average of a large number of time intervals generated with the negative exponential distribution would be .333.
```

The author of our recommended text points out that **we can build simulations with an entry for each time point.** 
However, if we use this approach and we want a more fine-grained time scale, the number of events to process could potentially grow very rapidly. For instance, if the current time unit is 1 sec and we want 1 msec time units instead, our input size would grow by 1000, and depending on the frequency of events, a very large majority of those time instants will not have anything happening!


An alternative is to use a priority queue prioritized by the time of the events in the simulation. At any point in the simulation, the next event will be either:

a) a customer arrives for service (an arrival event)

b) a customer's service is complete (a departure event)


Upon arrival, 
we check for an available service channel. If one exists, the customer immediately commences service. We compute a completion time, and that time goes into the priority queue as a future event. 

If all service channels are in use, the customer goes into a FIFO queue to wait for a server to become available. We know the time the customer leaves the FIFO queue to get service because that is exactly the time when service was completed for the prior customer (the simulation just processed a departure event).


***Note: You will need a priority queue. You may implement your program using:***

***a heap you implement as described in class***

***a FIFO queue you implement with modified insert() to maintain priority***
***
### Computing Arrival and Service Time Intervals – 
These times will be modeled by a **negative exponential distribution.**
The following pseudocode contains an algorithm for computing a time interval between events with random distribution from an infinite population given the average number of events (avg) per unit time:

 

     GetNextRandomInterval(avg)

     Generate a random float f on the interval (0..1]

     Compute intervalTime as -1 * (1.0/avg) * ln(f) // natural logarithm of f

     return intervalTime

 

Note that the parameter (avg) could be either the average number of arrivals or the average number of customers that can be provided service in unit time. That is why it is generically named avg.
 ***

### Program Execution
Your simulation will be interactive. When the program runs, it will prompt the user for the following IN THIS ORDER:

n - number of arrivals to simulate (we will test with >1000 up to 5000)

lambda (l) = average arrivals in a time period.

mu (m) = average number served in a time period.

M - the number of service channels (1 to 10; do error checking)

You will keep the priority queue small, of length 200. So long as more arrivals remain, you can easily add arrivals in O(lgn) time. 

You will do so when the number of events (arrivals and departures) in the PQ gets to M+1. 

You will carry out the simulation by placing the first group of arrivals into the priority queue and then entering the event loop processing arrivals and departures. If the event is an arrival, you first check for an available server. If one is present, you can generate the departure time and add it to the priority queue, and note that the server is busy. If no servers are available, the customer goes into the FIFO queue. Eventually a departure will occur. The departure frees a server that can process the next arrival OR a customer waiting in the FIFO queue. You must tally statistics as customers' service is completed. These are the amount of time waiting for service and the amount of time actually getting service.

## An Analytical Model of typical Queue measures

Analytical models can be computed a-priori to predict the functioning of a system. There is a convenient set of formulas that will give you the results you would expect to see over the long run in a simulation. Your computer modeling will vary to some degree from the data points provided by these equations since the equations are based on large populations.


1. The percent idle time, Po; that is, the percentage of time that no one is in the system:

  ![image](https://user-images.githubusercontent.com/89366767/192570966-e81fc2c5-f0bb-4bee-9f87-9d11334e84a4.png)

2. The average number of people in the system (the number in line plus the number being served.

  ![image](https://user-images.githubusercontent.com/89366767/192571098-67683cb9-377e-44bf-8d86-d4499aa1c3f1.png)

3. The average time a customer spends in the system.  (the time the customer spent in line plus the time spent getting service):

  ![image](https://user-images.githubusercontent.com/89366767/192571183-7212d272-57ca-44ef-9c14-0b3dd506206f.png)

4. The average numbers of customers in the queue:

  ![image](https://user-images.githubusercontent.com/89366767/192571250-fa2d4033-80fb-4592-bb06-f63ad88717a0.png)

5. The average time a customer spends waiting in the queue:

  ![image](https://user-images.githubusercontent.com/89366767/192571301-5a1c3bb9-3dd8-4c1e-9f5d-b51cc641a1eb.png)

6. The utilization factor for the system, (rho); that is, the proportion of the system's resources which is used by the traffic which arrives.

  ![image](https://user-images.githubusercontent.com/89366767/192571362-c5f70717-60e0-47b3-a7c3-fd1476533c4e.png)



When your program runs, you will compute and display all six values from the Analytical Model.

 

### Simulation Measures to compute

From your simulation, you are to determine simulated values for items determined analytically by ***formulas 1, 3, 5, and 6.***
Additionally, you will report the probability of having to wait for service (the number of customers who had to wait/total customers).

 
To get the simulated value of Po, accumulate all the time after a departure of the last customer being served (leaving no one in the system) until the next arrival.

 
To simulate rho ( ρ ), compute the total time servers were available (M * total simulation time) and divide it into the total amount of service time.

 

Your output (to the console) will display 
the analytical model and simulation measures in such a way that you can compare them so that you can see how well your simulation results matched predicted values.


#### Example input and results:
***

The analytical model should produce these results for the following inputs:
```
lambda (l) = 2
mu (m) = 3
M = 2


Po = 0.5
L = 0.75
W = 0.375
Lq = 0.083
Wq = 0.0417
```

#### Output
***

All output will be to the console. You will display all the measures in the analytical model and the specified measures from the simulation.
 

### Deliverables:
***
You must include the following in your submission to the dropbox:

Your UML diagram in its own file entitled "UMLDiagram." (a Word doc or .pdf. Export from Dia if you use that program)
A user’s manual in its own file entitled "UsersManual"  (a Word doc or .pdf)
Source code
A makefile
 

Submission Requirements:  
Note: you will lose 10% if you do not follow these instructions exactly. The reason for this policy is that Canvas puts zip files inside zip files and it is a time-consuming, tedious, and error-prone policy to unzip them all one-by-one. I have a utility I wrote that nicely unzips all these into a usable folder structure. If you do not follow these instructions, your files will get all mashed up together with others, often with name collisions and it is an unusable mess.

1. Compile and run your program one last time before submitting it. Your program must run in Linux in the multiplatform lab. 

2. Place all deliverables in a single folder that is named with your last name and first name initial. For example, if your name is Katie Brodhead, the folder should be brodheadk. If you are a MacOS user, delete the _MacOS_ folder before zipping up your submission.

3. Create a "zip"  file (using WinZip or similar program) to hold your project files.

Your zip file should be named exactly like the single folder inside it but with the .zip extension. For instance:  brodheadk.zip.

So, this is how your submission should be structured (if your name were Katie Brodhead) for this project:

brodheadk.zip

    brodheadk              // the folder holding all your files

        file1.hpp          // with the actual names of your files,

        file1.cpp          // of course ...

        ...

        UserManual.docx

        UML.jpg            // please export .jpg from Dia
        lastNames.txt

4. Login to Canvas and select our course from the dashboard.

5. Go to the Assignments page and choose the assignment for which you are submitting a project.

6. Click the "Submit Assignment" button.
7. Use the "Choose File" capability to select and upload your .zip file.
