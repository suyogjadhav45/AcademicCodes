use suyadb;
show tables;
-- Creating Tables
create table borrower(rollno int primary key not null AUTO_INCREMENT, name varchar(40), doi date,name_of_book varchar(50),status varchar(10));
desc borrower;
CREATE table fine(rollno int, date_of_fine date, amt int);
desc fine;
insert into borrower (name,doi,name_of_book,status) VALUES('Atharva','2022/10/15','IOT', 'I');
update borrower set name = 'Archisha' where rollno = 4;
SELECT * from borrower;
Procedure
drop procedure calc_fine;
delimiter $
create procedure calc_fine(IN r int) begin
declare issueDate date;
declare diff int;
select doi into issueDate
from borrower
where rollno = r;
set diff = datediff(CURDATE(),issueDate);
if diff<0 then
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = 'Date is Wrong';
end if;
if diff<=30 and diff>=15 then
    insert into fine VALUES(r,CURDATE(),diff*5);
    update borrower set status = "R" where rollno = r;
elseif diff>30 then
    insert into fine VALUES(r,CURDATE(),diff*50);
    update borrower set status = "R" where rollno = r;
else
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = "%%%% NO FINE %%%%%";
end if;
end $ 
delimiter ;
TRUNCATE table fine;
call calc_fine(2);
SELECT *
from fine;