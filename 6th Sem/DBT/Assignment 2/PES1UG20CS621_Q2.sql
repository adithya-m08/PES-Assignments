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