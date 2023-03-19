--  Create a query that uses a function in the WHERE clause and analyze its execution plan
explain SELECT *
FROM returns
WHERE YEAR(return_date) > 2023;