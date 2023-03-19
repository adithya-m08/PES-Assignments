-- Create a query that uses a materialized view and analyze its execution plan.
CREATE VIEW mv_borrow AS
SELECT *
FROM borrow
WHERE user_id BETWEEN 1 AND 1000;
explain SELECT *
FROM books b
WHERE b.id IN (
        SELECT book_id
        FROM mv_borrow
    );