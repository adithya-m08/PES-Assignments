-- Create a query that uses a correlated subquery that retrueves a lot of values and analyze its execution plan
explain SELECT *
FROM books b
WHERE b.id IN (
        SELECT book_id
        FROM borrow
        WHERE user_id BETWEEN 1 AND 1000
    );
