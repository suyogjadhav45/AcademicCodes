use suyadb;

create table Stud_data(
    name VARCHAR(255) NOT NULL,
    roll INT NOT NULL PRIMARY KEY,
    marks INT NOT NULL
);

CREATE Table Result(
    name VARCHAR(255),
    roll INT NOT NULL,
    grade VARCHAR(255) ,
    FOREIGN KEY (roll) REFERENCES Stud_data(roll)
);

delimiter //

CREATE PROCEDURE grade_proc(IN rollID INT)
BEGIN
DECLARE Stud_marks INT;
Declare stud_name varchar(255);
DECLARE grade VARCHAR(255);
SELECT marks,name INTO Stud_marks, stud_name FROM Stud_data WHERE roll=rollID;

IF(Stud_marks>=990 AND Stud_marks<=1500) THEN 
SET grade="Distinction";
ELSEIF(Stud_marks<=989 AND Stud_marks>=900) THEN
SET grade="First Class";
ELSEIF(Stud_marks<=899 AND Stud_marks>=825) THEN
SET grade="Second Class";
END IF;

INSERT INTO Result VALUES(stud_name,rollID,grade);
END

//

delimiter ;
call grade_proc(1);




create table stud(
    roll int primary key,
    name varchar(255),
    marks int
);


 delimiter $$
 CREATE PROCEDURE cal_grade(IN s_roll INT)
 BEGIN
 declare sname varchar(255);
 declare sclass varchar(255);
 declare smarks int;
 select name,marks into sname,smarks from stud where roll=s_roll;
 
  if marks>=900 then
  set sclass="good";
  elseif marks<900 then
  set sclass="bad";
  end if;
  insert into res values(s_roll,sname,sclass);
  end $$