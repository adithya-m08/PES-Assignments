create view compute_price as
   	select ticket.PNR,ticket.Train_no,ticket.Departure,ticket.Arrival,route_info.distance,fare.fare_per_km
     from ticket,route_info,fare
     where (ticket.train_no=route_info.train_no and ticket.Departure = route_info.From_station_name and ticket.Arrival = route_info.To_station_name and fare.Train_type = ticket.Train_type and fare.compartment_type = ticket.compartment_type);


create view passenger_num as select PNR, count(PNR) as numbers from ticket_passenger group by PNR;

update payment_info as p INNER JOIN compute_price as cs on p.PNR = cs.PNR INNER JOIN passenger_num as pn on cs.PNR = pn.PNR set p.Price = cs.Distance * cs.fare_per_km * pn.numbers;


Select T.Train_no, T.Train_name, R.From_station_name, R.To_station_name, Distance From Train as T NATURAL JOIN route_info as R;


Select T.Train_no From Train as T, Compartment as C Where T.Train_No=C.Train_number and T.Source="Bengaluru" and T.Destination="Chennai" and C.Availability>10;


Select U.firstname, U.lastname From train_User as U, Ticket as T, Payment_Info as P Where U.User_ID=T.passenger_ID and T.PNR=P.PNR and P.Price>500;


Select U.firstname, U.lastname, U.DOB, T.PNR From train_User as U LEFT OUTER JOIN Ticket as T ON U.User_ID=T.passenger_ID;


Select U.firstname, U.lastname, U.DOB, T.PNR From train_User as U LEFT OUTER JOIN Ticket as T ON U.User_ID=T.passenger_id where T.PNR is null;



Select T.PNR, T.Train_No, T.Travel_Date, U.firstname, U.lastname From Ticket as T RIGHT OUTER JOIN train_user as U ON T.passenger_ID=U.User_ID;




Select U.User_ID, T.Train_no, T.train_Name From User_Train as U RIGHT OUTER JOIN Train AS T ON U.Train_ID=T.Train_No; 

SELECT T.Train_No, T.train_name
FROM Train as T
WHERE T.Destination!='Mangaluru' AND T.Train_No NOT IN (
SELECT R.Train_No FROM Route_Info AS R LEFT OUTER JOIN Ticket AS A ON R.Train_No=A.Train_No WHERE R.Distance<100 AND A.Departure AND A.departure_time=TIME('8:30:00') 
UNION 
SELECT R.Train_No FROM Route_Info AS R LEFT OUTER JOIN Ticket AS A ON R.Train_No=A.Train_No WHERE R.Distance<100 AND A.Departure AND A.departure_time=TIME('8:30:00') );

SELECT T.passenger_id
FROM Ticket AS T JOIN Payment_Info AS P ON T.PNR=P.PNR
WHERE P.Price>(SELECT AVG(P.Price) FROM Payment_Info AS P);