select train_no,avg(distance) from route_info group by train_no;

select train_no,avg(distance) from route_info group by train_no order by distance desc; 

select train_no, sum(distance) from route_info group by train_no order by distance desc;

create view count_train as select train_number, count(compartment_no) as numofcompartments from compartment group by train_number;

select train_name, numofcompartments from count_train inner join train on count_train.train_number=train.train_no where numofcompartments in ((select max(n
umofcompartments) from count_train),(select min(numofcompartments) from count_train));

drop view count_train;

select user_id, count(phone_no) from (select * from user_phone where user_id in ("ADM_001", "USR_006", "USR_010")) as count_phone group by user_id;

SELECT train_type, AVG(fare_per_km) FROM fare GROUP BY train_type ORDER BY AVG(fare_per_km) DESC; 

select * from ticket_passenger where age in (select max(age) from ticket_passenger);

select count(*) from ticket_passenger where name like "%Ullal%"; 