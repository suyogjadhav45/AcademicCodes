CREATE TABLE Stud_data1(
    sroll INT PRIMARY KEY,
    sname varchar(20),
    total_marks INT 
);

CREATE TABLE Disp(
    sroll INT,
    FOREIGN KEY (sroll) REFERENCES Stud_data1(sroll),
    sname varchar(20),
    grd varchar(20)
);

delimiter //
CREATE PROCEDURE cal(IN rollno INT)
BEGIN 
DECLARE stud_marks INT;
DECLARE stud_name varchar(20);
DECLARE stud_grd varchar(20);

Declare EXIT HANDLER FOR NOT FOUND select 'No Student Record Found' as 'Error';

SELECT sname,total_marks INTO stud_name, stud_marks FROM Stud_data1 WHERE sroll=rollno;

IF rollno<0 THEN
SIGNAL SQLSTATE 'ERROR'
SET MESSAGE_TEXT='Roll Number can not be negative';
END IF;

IF stud_marks>=990 THEN
SET stud_grd='Distinction';
ELSEIF stud_marks>=900 AND stud_marks<990 THEN
SET stud_grd='first class';
ELSEIF stud_marks<900 THEN
SET stud_grd='second class';
END IF;

INSERT INTO Disp VALUES(rollno,stud_name,stud_grd);
END;
//
delimiter ;





-- function declaration

delimiter //
CREATE FUNCTION cal_fun(stud_marks INT)
returns varchar(20)
DETERMINISTIC
BEGIN 
DECLARE stud_grd varchar(20);

IF stud_marks>=990 THEN
SET stud_grd='Distinction';
ELSEIF stud_marks>=900 AND stud_marks<990 THEN
SET stud_grd='first class';
ELSEIF stud_marks<900 THEN
SET stud_grd='second class';
END IF;

return stud_grd;
END ;
//

delimiter ;

SELECT sroll, sname, total_marks, cal_fun(total_marks) as Grade FROM Stud_data1 order by sroll;