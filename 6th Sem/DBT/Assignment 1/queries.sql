SELECT b.title,
    b.author
FROM books b
    JOIN category c ON b.category_id = c.id
WHERE c.name = 'name1';
SELECT *
FROM books
WHERE price / 5 > 100
    AND price / 5 < 200;
SELECT *
FROM books
WHERE price > 500
    AND price < 1000;
SELECT *
FROM user
WHERE phone_no = 1111111111
    AND address = 'address1';
SELECT *
FROM borrow
WHERE user_id = 111
    AND book_id between 1 and 110;
SELECT *
FROM returns
WHERE borrow_id IN (
        SELECT id
        FROM borrow
        WHERE user_id = 111
            AND book_id between 1 and 110
    );