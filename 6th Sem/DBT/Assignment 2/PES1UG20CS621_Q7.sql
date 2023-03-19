-- Create a query that involves complex data types (e.g., arrays) and analyze its execution plan.
select *
from books join category on books.category_id = category.id
where category.sub_category_id in (1,150, 234,313,3442);