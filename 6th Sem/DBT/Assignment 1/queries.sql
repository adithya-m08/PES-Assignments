SELECT b.title, b.author FROM books b JOIN category c ON b.category_id = c.id WHERE c.name = 'name1';

SELECT * FROM books WHERE price/5 > 100 AND price/5 < 200;
SELECT * FROM books WHERE price > 500 AND price < 1000;

SELECT * FROM user WHERE phone_no = 1111111111 AND address = 'address1';

SELECT * FROM borrow WHERE user_id = 111 AND book_id between 1 and 110;

SELECT * FROM returns WHERE borrow_id IN (SELECT id FROM borrow WHERE user_id = 111 AND book_id between 1 and 110);

-- multi (>2) table join of min. of 3 tables. 
select * from books b join category c on b.category_id = c.id join author a on b.author_id = a.id where c.name = 'name1';

-- Change the join order of the tables in the queries above, at least 3 times, recording performance differences by comparing the execution plans and actual execution performance. 
-- Variety of joins need to be used like outer joins, subqueries, etc.
select * from category c join books b on b.category_id = c.id join author a on b.author_id = a.id where c.name = 'name1';
select * from author a join books b on b.author_id = a.id join category c on b.category_id = c.id where c.name = 'name1';

-- Create a query that uses a subquery and a correlated subquery, and analyze its execution plan.
select * FROM books b where b.price > (select avg(price) from books);
select * from 

-- Create a query that uses a materialized view and analyze its execution plan.

--  Create a query that uses a function in the WHERE clause and analyze its execution plan.

-- Create a query that uses a dynamic SQL statement and analyze its execution plan.

-- Create a query that involves complex data types (e.g., arrays) and analyze its execution plan.

-- Compare the performance of different indexing strategies (e.g., B-tree, hash) on a large table and record the results.

-- Tune the database configuration settings (e.g., shared buffers, checkpoint settings) to improve query performance, and compare the results before and after the tuning.
