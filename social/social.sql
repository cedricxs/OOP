/* Delete the tables if they already exist */
drop table if exists Highschooler;
drop table if exists Friend;
drop table if exists Likes;

/* Create the schema for our tables */
create table Highschooler(ID int, name text, grade int, major text, minor text);
create table Friend(ID1 int, ID2 int);
create table Likes(ID1 int, ID2 int, since date);

/* Populate the tables with our data */
insert into Highschooler values (1510, 'Jordan', 9, 'CS', 'Maths');
insert into Highschooler values (1689, 'Gabriel', 9, 'CS', NULL);
insert into Highschooler values (1381, 'Tiffany', 9, 'Physics', 'Maths');
insert into Highschooler values (1709, 'Cassandra', 9, 'Art', NULL);
insert into Highschooler values (1101, 'Haley', 10, 'Biology', 'Chemistry');
insert into Highschooler values (1782, 'Andrew', 10, 'Music', 'Maths');
insert into Highschooler values (1468, 'Kris', 10, 'Art', 'Music');
insert into Highschooler values (1641, 'Brittany', 10, 'Biology', 'CS');
insert into Highschooler values (1247, 'Alexis', 11, 'Biology', NULL);
insert into Highschooler values (1316, 'Austin', 11, 'Art', 'CS');
insert into Highschooler values (1911, 'Gabriel', 11, 'Chemistry', 'Physics');
insert into Highschooler values (1501, 'Jessica', 11, 'Physics', NULL);
insert into Highschooler values (1304, 'Jordan', 12, 'Maths', NULL);
insert into Highschooler values (1025, 'John', 12, 'CS', 'Music');
insert into Highschooler values (1934, 'Kyle', 12, 'Art', 'Chemistry');
insert into Highschooler values (1661, 'Logan', 12, 'Physics', NULL);

insert into Friend values (1510, 1381);
insert into Friend values (1510, 1689);
insert into Friend values (1689, 1709);
insert into Friend values (1381, 1247);
insert into Friend values (1709, 1247);
insert into Friend values (1689, 1782);
insert into Friend values (1782, 1468);
insert into Friend values (1782, 1316);
insert into Friend values (1782, 1304);
insert into Friend values (1468, 1101);
insert into Friend values (1468, 1641);
insert into Friend values (1101, 1641);
insert into Friend values (1247, 1911);
insert into Friend values (1247, 1501);
insert into Friend values (1911, 1501);
insert into Friend values (1501, 1934);
insert into Friend values (1316, 1934);
insert into Friend values (1934, 1304);
insert into Friend values (1304, 1661);
insert into Friend values (1661, 1025);
insert into Friend select ID2, ID1 from Friend;

insert into Likes values(1689, 1709, '02-01-2017');
insert into Likes values(1709, 1689, '03-01-2017');
insert into Likes values(1782, 1709, '03-01-2017');
insert into Likes values(1911, 1247, '12-01-2017');
insert into Likes values(1247, 1468, '11-01-2017');
insert into Likes values(1641, 1468, '15-01-2017');
insert into Likes values(1316, 1304, '02-01-2017');
insert into Likes values(1501, 1934, '09-01-2017');
insert into Likes values(1934, 1501, '11-01-2017');
insert into Likes values(1025, 1101, '13-01-2017');