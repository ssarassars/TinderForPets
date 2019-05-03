### Your Pet Adoption Matching System

## Preamble

Program Purpose: Application designed for pet adoption stores.
It can automatically match clients and pets that are available for adoption.
It does this by taking into account client attributes/ preferences and animal
attributes.



# Compilation and Launch Instructions

## Compilation
Run the compilation bash script with the following command : sudo bash cuACS_compile

## Launch
Assuming you have already done the compilation stage, you can run cuACS from the terminal using: ./cuACS

To login as a staff user, select the "Staff" option from the login screen, and enter 1 as your user ID.
When logging in as a client, clients who have already completed the personality quiz will not be able to take it again.
In order to view the personality quiz, you will have to log in as a client who has not taken it yet.
To login as a client, select the "Pet Adopter" option from the login screen, and enter any of the following IDs.

IDs for logging in as clients who HAVE NOT taken the quiz: [2, 6, 7, 8, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]
IDs for logging in as clients who HAVE taken the quiz: [1, 9, 10, 13]

Advanced users may wish to test that the matching algorithm does indeed find the optimal set of matches.
To do so, simply open the MatchingAlgorithm.cpp file and uncomment line 30.
This will run tests one through four on launch.
The details of each test are explained in the comments in MatchingAlgorithm.


# Operation


Implemented Features:
1. As a staff member, you can:
   a. add animals to the system's database
   b. view a list of animals available for
   adoption along with their basic details
   c. view a list of all registered clients
   d. add clients
   e. view a selected animal's profile
   f. edit a selected animal's profile
   g. view a list of all animal-client matches
   h. view the details of a specific animal-client match
2. Clients can:
   a. view the list of animals available for adoption
   b. view a selected animal's profile
   c. edit their matching preferences
   d. take a one-time personality quiz to establish their personality traits
