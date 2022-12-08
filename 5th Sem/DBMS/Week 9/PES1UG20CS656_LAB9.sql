DELIMITER $$ 
CREATE TRIGGER trigger1
BEFORE INSERT ON compartment
FOR EACH ROW
BEGIN
  IF (SELECT COUNT(*) FROM compartment WHERE Train_Number = NEW.Train_Number) >= 4 THEN
     SIGNAL SQLSTATE '50001' SET MESSAGE_TEXT = 'Max number of compartments reached';
  END IF;
END; $$
DELIMITER ;

INSERT INTO  compartment VALUES("F01","Class I",12,8,58450);


create table Back_Up(pnr varchar(10),train_number int, travel_date date,departure varchar(30),arrival varchar(30),departure_time time,arrival_time time, user_id varchar(20),train_type varchar(20), compartment_type varchar(10),compartment_no varchar(10),seat_no varchar(10),name varchar(30),age int(11), transaction_id int,bank varchar(20),card_no varchar(20),price int);

ALTER TABLE Ticket_Passenger ADD CONSTRAINT dt FOREIGN KEY (pnr) REFERENCES Ticket(pnr) on delete cascade;
ALTER TABLE Payment_info ADD CONSTRAINT dp FOREIGN KEY (pnr) REFERENCES Ticket(pnr) on delete cascade;

DELIMITER $$
CREATE TRIGGER del_ticket
BEFORE DELETE
ON Ticket FOR EACH ROW
BEGIN
	INSERT INTO Back_Up (SELECT * FROM (Ticket NATURAL JOIN(Ticket_Passenger NATURAL JOIN Payment_info)) WHERE pnr=old.pnr);
END; $$
DELIMITER ;

delete from Ticket where pnr="PNR005";

SELECT * FROM Back_Up;

