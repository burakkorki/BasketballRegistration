# Music Album - CS 201, Fall 2017 Homework Assignment 3
 
A basketball tournament team registration system. There are going to be multiple teams registering for the tournament. For each team you are going to store a record. Each team has a name, color, and roster. In the implementation, LINKED-LISTs are used . This assignment have two parts, whose requirements are explained below.
 
## Part A

This part is a simplified version of the entire system, which keeps just the name and color of each team without keeping its roster.

## Part B


Now extend Part A such that each team will have a roster and provide the full functionality of this basketball tournament team registration system.

For that, first, extend the Team class such that now it keeps the players (roster) of a single team. These players must be kept in another LINKED-LIST. Note that the number of players in a team is not known in advance. Here, do not forget to implement the constructor, destructor, and copy constructor of this Team class as well as do not forget to overload its assignment operator. Otherwise, you may encounter some unexpected run-time errors. This time, the interface of the Team class must be written in a file called Team.h, and its implementation must be written in a file called Team.cpp.

After extending the Team class, now work on the implementation of the following functionalities that your system should support.

          1. Add a team
          2. Remove a team
          3. Display all registered teams
          4. Add a player to the team
          5. Remove a player from the team
          6. Show detailed information about a particular team
          7. Find the team(s) whose roster contains a specified player name


## Copyright and Licence

© Burak Korkmaz, Bilkent University Computer Science

Licenced under the [MIT Licence](LICENSE).
