-- multi (>2) table join of min. of 3 tables. 
SELECT *
FROM books b
    JOIN borrow bo ON b.id = bo.book_id
    JOIN returns r ON bo.id = r.borrow_id
    JOIN user u ON bo.user_id = u.id
WHERE b.id between 1 and 1000;

-- Change the join order of the tables in the queries above, at least 3 times, recording performance differences by comparing the execution plans and actual execution performance. 
-- Variety of joins need to be used like outer joins, subqueries, etc. without author table
SELECT *
FROM borrow bo
    JOIN books b ON b.id = bo.book_id
    JOIN returns r ON bo.id = r.borrow_id
    JOIN user u ON bo.user_id = u.id
WHERE b.id between 1 and 1000;
--using inner join
SELECT *
FROM borrow bo
    inner JOIN books b ON b.id = bo.book_id
    JOIN returns r ON bo.id = r.borrow_id
    JOIN user u ON bo.user_id = u.id
WHERE b.id between 1 and 1000;
--same using subquery
SELECT *
FROM borrow bo
    JOIN books b ON b.id = bo.book_id
    JOIN returns r ON bo.id = r.borrow_id
    JOIN user u ON bo.user_id = u.id
WHERE b.id IN (
        SELECT id
        FROM books
        WHERE id between 1 and 1000
    );

-- Create a query that uses a correlated subquery that retrueves a lot of values and analyze its execution plan
SELECT *
FROM books b
WHERE b.id IN (
        SELECT book_id
        FROM borrow
        WHERE user_id BETWEEN 1 AND 1000
    );

-- Create a query that uses a materialized view and analyze its execution plan.
CREATE VIEW mv_borrow AS
SELECT *
FROM borrow
WHERE user_id BETWEEN 1 AND 1000;
SELECT *
FROM books b
WHERE b.id IN (
        SELECT book_id
        FROM mv_borrow
    );

--  Create a complex query that uses a function in the WHERE clause and analyze its execution plan using returns tabl
SELECT *
FROM returns
WHERE YEAR(return_date) > 2023;

-- Create a query that uses a dynamic SQL statement and analyze its execution plan in mysql
SET @col_name = 'author';
SET @sql = CONCAT('SELECT ', @col_name, ' FROM books');
PREPARE stmt
FROM @sql;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;
EXPLAIN
SELECT @col_name
FROM books;

-- Create a COMPLEX query that involves complex data types AND JOINS ETC (e.g., arrays) and analyze its execution plan.



-- Compare the performance of different indexing strategies (e.g., B-tree, hash) on returns table and record the results.
CREATE index btree_return_date ON returns(return_date);
CREATE index hash_return_date ON returns(return_date) USING HASH;
-- using btree
SELECT *
FROM returns use index(btree_return_date)
WHERE return_date between '2021-01-01' and '2021-12-31' ;
-- using hash
SELECT *
FROM returns use index(hash_return_date)
WHERE return_date between '2021-01-01' and '2021-12-31';