DELIMITER $$
CREATE procedure update_age6(
IN usrid varchar(10), OUT msg varchar(30))

BEGIN

DECLARE aage int;
DECLARE ddob date;
set aage = (select age from train_user where train_user.user_id = usrid);
set ddob = (select dob from train_user where train_user.user_id = usrid);

IF aage is NULL THEN
set msg = 'Updating age as it is NULL';
update train_user set age = datediff(current_date(), ddob)/365.25 where train_user.user_id=usrid;
ELSE
set msg = 'Age is already updated';
END IF;

END;$$
DELIMITER ;