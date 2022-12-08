DELIMITER $$

CREATE FUNCTION check_ticket(user_id varchar(10))
RETURNS VARCHAR(50)
DETERMINISTIC
BEGIN

	DECLARE message VARCHAR(50);
	DECLARE count int;
	set count = (select count(*) from ticket as t where t.passenger_id=user_id group by t.passenger_id);
	
	if count>1 then
	set message = "purchased by more than 1 user";

	else
	set message = "purchased by 1 user";

	end if;

return message;

END; $$

DELIMITER ;