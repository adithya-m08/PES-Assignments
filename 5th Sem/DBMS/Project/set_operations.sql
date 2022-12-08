-- using union find the names of the products whose quantity is less than 10 or category is either bottle or tank
select name
from product
where quantity < 1000
union
select name
from product
where category in ('bottle', 'tank', 'dirty water');


--using set difference find the payment details of customers who have not made any payment
select c.customer_id,
    c.name,
    c.address,
    c.contact_no
    from customer as c
except
select c.customer_id,
    c.name,
    c.address,
    c.contact_no
    from customer as c
    inner join payment as p on c.customer_id = p.customer_id;