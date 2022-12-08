select user_id, user_type, firstname, lastname from train_user u join ticket t on u.user_id = t.passenger_id where departure = 'Bengaluru' and arrival = 'Chennai' and travel_date between
'2021-10-01' and '2022-08-31';

select u.user_id, user_type, firstname, lastname 
from train_user u, ticket t
where t.Departure = 'Bengaluru' and t.Arrival = 'Chennai'
and exists (select u.User_ID, User_Type, Firstname, Lastname from train_user u, ticket t where t.Travel_Date between '2022-08-01' and '2021-10-01');

select user_id,user_type,firstname,lastname 
from train_user u join ticket t on u.user_id = t.passenger_id 
where departure = 'Bengaluru' and arrival = 'Chennai' and travel_date not between '2021-10-01' and '2021-10-31' and travel_date between '2022-08-01' and '2022-08-31';

select u1.user_id, user_Type, firstname, lastname
from ticket as t1, train_user as u1
where t1.passenger_id = u1.user_id
and t1.Departure = 'Bengaluru' and t1.Arrival = 'Chennai'
and exists (select pnr from ticket AS t2 where t1.passenger_id = t2.passenger_id 
and t2.Departure = 'Chennai' and t2.Arrival = 'Bengaluru' and (datediff(t2.Travel_Date,t1.Travel_Date) between 0 and 7));

select u1.user_id, user_Type, firstname, lastname
from ticket as t1, train_user as u1
where t1.passenger_id = u1.user_id
and t1.Departure = 'Bengaluru' and t1.Arrival = 'Chennai'
and exists (select pnr from ticket AS t2 where t1.passenger_id = t2.passenger_id 
and t2.Departure = 'Chennai' and t2.Arrival = 'Bengaluru' and (datediff(t2.Travel_Date,t1.Travel_Date) between 0 and 7));

select u1.user_id, user_type, firstname, lastname
from ticket t1, train_user u1
where t1.passenger_ID = u1.User_ID
and t1.Departure = 'Bengaluru' and t1.Arrival = 'Chennai'
and not exists(select pnr from ticket t2 where t1.passenger_ID = t2.passenger_ID 
and t2.Departure = 'Chennai' and t2.Arrival = 'Bengaluru');