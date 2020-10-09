### 0/ INTRO

The main purpose of the lab is to play with the social network database both with a relational DB (SQLite) and a graph DB (Neo4J) such like you are able to compare query expressions in both worlds. 

As a starter, set up a SQL database connexion (with Datagrip, SQLiteStudio, sqliteonline, etc.). Then, execute the `social.sql` script to create schema and insert tuples into the SQL database.

Second, run a Neo4J database instance and create an empty graph. 

### I/ MIGRATION

Write CYPHER statements to create and populate a Neo4j graph database with the social network data. Use provided CSV files to mass import nodes and vertices. Encode symetric relationships one-way only (and query it both ways) with CYPHER. Find a consistant way to manage NULL values.


### II/ READ-ONLY QUERIES

Write both SQL and CYPHER queries against resp. SQLite3 DB and Neo4j DB.

Dead Ref: https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_query_core/

##### Questions

0. Find the names of all students who are friends with someone named Gabriel. 
  
1. For each student A who likes a student B where the two are not friends, find if they have a friend C in common (who can introduce them!). For all such trios, return the name and grade of A, B, and C. 
  
2. Find the name and major of all students who are liked by more than one other student.
  
3. For each student in CS minor, count the number of friends of friends having grade 12. Do not count in any of the first circle friends.
  
4. Find the friendship degree (degree of separation) of each pair of students who both have the same name. For all such pair, return the name of students, their ID's and their friendship degree. Include each pair only once.

To solve the above query in SQL, you are expected to look at recursive CTE (Common Table Expression). 

5. For every pair of students who are the farest one with each other in the friendship network, give the friendship path, one way only.
  

### III/ MODIFICATION QUERIES

Dead Ref: https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-exercise-sql_social_mod/

##### Questions

6. It's time for the seniors to graduate. Remove all 12th graders from Highschooler. 

7. If two students A and B are friends, and A likes B but not vice-versa, remove the Likes tuple. 

8. For all cases where A is friends with B, and B is friends with C, add a new friendship for the pair A and C. Do not add duplicate friendships, friendships that already exist, or friendships with oneself. (This one is a bit challenging; congratulations if you get it right.)