# An-Emergency-Room-Simulator
CS-273-1 Final Project (Fall, 2019)

•	You need to simulate a hospital emergency room located in the town of Simville, population 2000.

•	Every person in 273ville is equally healthy, but they do occasionally need to go to the emergency room.  
     
     o	I.e. there is equal probability that anyone in town will be admitted into the emergency room as a patient.
      
•	Your emergency room is small, but it has a big heart.  It tries to run its operation as efficiently as possible.

•	When a patient arrives at the emergency room, he/she is triaged – that is, the patient is assigned a priority number from 1 to 20, depending on the severity of the illness.  Higher priority values indicate more serious illnesses and are always treated ahead of lower priority illnesses.
     
     o	Illnesses with priority 1 to 10 occur approximately 70% of the time with equal probability
     
     o	Illnesses with priority 11 to 15 occur approximately 20% of the time with equal probability.
    
     o	Illnesses with priority 16 to 20 occur approximately 10% of the time with equal probability.
      
•	The emergency room has 2 categories of caregivers: Doctors and Nurses.
     
     o	Nurses can treat patients with priority 1 to 10, and doctors can treat patients with priority 1 to 20.
     
     o	Empirically, we also know that nurses take 1 to 10 minutes to treat a patient, and doctors take 1 to 20 minutes to treat a patient, on average. 
      
•	The hospital keeps a record of all patients that were treated in the emergency room.  Each record stores:
     
     o	the number of visits to the emergency room, and
     
     o	the severity of illness on each visit
      
•	Your simulation needs to examine a week in the life of the emergency room on a minute-by-minute basis (i.e. it needs to simulate at least 7x24x60 minutes).
•	Allow the user to input the following data values:
     
     o	The average hourly patient arrival rate (patients/ hour) at the emergency room –assume that there will not be more than 60 patients per hour.
     
     o	The number of doctors working in the emergency room.
     
     o	The number of nurses working in the emergency room. 
      
•	You simulation will need to calculate the average visit time (arrival to discharge time) for emergency room patients.
•	At the end of the simulation, you will need to display a menu with options to list the names of all residents that were treated, and retrieve the record of a resident by “name”.
•	For your final report and presentation:
      
      o	Compare and comment on the average patient visit time (for some fixed patient arrival rate) when the emergency room has 
            
            	1 doctor and 1 nurse
            
            	1 doctor and 2 nurse
            
            	2 doctors and 1 nurse
      
      o	Display a plot of the visit time for increasing patient arrival rates, for a combination of doctors and nurses of your choice
