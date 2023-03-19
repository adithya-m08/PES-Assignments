-- Create a query that uses a dynamic SQL statement and analyze its execution plan 
SET @col_name = 'author';
SET @sql = CONCAT('SELECT ', @col_name, ' FROM books');
PREPARE stmt
FROM @sql;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;
EXPLAIN
SELECT @col_name
FROM books;