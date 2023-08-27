use suyadb;

-- Create table
create table Borrower(
    roll INT NOT NULL,
    name VARCHAR(20) NOT NULL,
    dateoi DATE NOT NULL,
    status CHAR(1) NOT NULL
);

CREATE TABLE Fine(
    roll INT NOT NULL,
    dateof DATE NOT NULL,
   amount INT NOT NULL
);
