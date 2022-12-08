CREATE VIEW heavy_ticket_items AS
SELECT product_id,
    name,
    refill_price
FROM product
WHERE refill_price > (
        select avg(refill_price)
        from product
    );

SELECT * from heavy_ticket_items;