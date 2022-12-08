--find product names whose delivery status is pending with join
SELECT name,
    status
FROM product
    INNER JOIN delivery_details ON product.product_id = delivery_details.product_id
WHERE status = 'pending';


-- using right join find payment details of customers who have not made any payment
SELECT c.customer_id, c.name, c.address, c.contact_no, c.managed_by
FROM customer as c
    LEFT JOIN payment as p ON c.customer_id = p.customer_id
WHERE p.customer_id IS NULL;


-- using correlated subquery find the delivery details of the product with the highest refill_price
select *
from delivery_details
where product_id = (
        select product_id
        from product
        where refill_price = (
                select max(refill_price)
                from product
            )
    );


-- using correlated subquery find the username and password of the user who has highest number of pos
select user_name,
    password
from user
where user_id = (
        select user_id
        from pos
        where pos_id = (
                select max(pos_id)
                from pos
            )
    );

-- count the number of pending deliveries
select count(delivery_no) as count, product_id
from delivery_details
where status = 'pending';

--average refill price of products whose quantity is less than 10 and category is either bottle or tank
select avg(refill_price) as average
from product
where quantity < 1000 and category in ('bottle', 'tank');


