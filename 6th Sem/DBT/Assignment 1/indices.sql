create index category_name_index on category(name);
CREATE INDEX books_title_index ON books(title);
CREATE INDEX books_author_index ON books(author);
CREATE INDEX books_price_index ON books(price);
CREATE index borrow_user_id_index on borrow(user_id);
CREATE index user_address_index on user(address);
CREATE index user_phone_no_index on user(phone_no); 