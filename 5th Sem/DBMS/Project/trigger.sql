--decrement quantity after delivery status is changed to delivered
DELIMITER $$
CREATE or replace procedure decrement_quantity(IN p integer, IN q integer) BEGIN
UPDATE product
SET quantity = quantity - q
WHERE product_id = p;
END;$$ 
DELIMITER ;

DROP TRIGGER update_quantity;
DELIMITER $$ 
CREATE TRIGGER IF NOT EXISTS update_quantity BEFORE
UPDATE ON delivery_details 
FOR EACH ROW BEGIN IF NEW.status = 'delivered' 
THEN 
CALL decrement_quantity(NEW.product_id, NEW.quantity);
END IF;
END $$ 
DELIMITER ;