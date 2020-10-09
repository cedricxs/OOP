/// import data ///

// Import Highschooler nodes 
LOAD CSV WITH HEADERS 
FROM "file:///Highschooler.csv" AS row
CREATE (n:Highschooler)
SET n = row,
n.ID = toInteger(row.ID),
n.grade = toInteger(row.grade);

// to complete...

