-- multi (>2) table join of min. of 3 tables. 
explain SELECT *
FROM books b
    JOIN borrow bo ON b.id = bo.book_id
    JOIN returns r ON bo.id = r.borrow_id
    JOIN user u ON bo.user_id = u.id
WHERE b.id between 1 and 1000;

explain select *
from user u
    join borrow bo on u.id = bo.user_id
    join returns r on bo.id = r.borrow_id
where u.id between 1 and 1000;

explain select *
from category c
    join books b on c.id = b.category_id
    join borrow bo on b.id = bo.book_id
    join returns r on bo.id = r.borrow_id
where c.id between 1 and 1000;