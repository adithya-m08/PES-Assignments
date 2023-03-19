create table category(
    id int primary key,
    name varchar(50),
    sub_category_id int
);
create table books(
    id int primary key,
    title varchar(50),
    author varchar(50),
    price int,
    publish_date date,
    category_id int,
    foreign key(category_id) references category(id)
);
create table borrow(
    id int primary key,
    user_id int,
    book_id int,
    due_date date,
    fee int,
    foreign key(book_id) references books(id)
);
create table user(
    id int primary key,
    address varchar(50),
    phone_no int,
    date_of_expiry date,
    borrow_id int,
    foreign key(borrow_id) references borrow(id)
);
create table returns(
    id int primary key,
    borrow_id int,
    return_date date,
    fees int,
    remarks varchar(50),
    foreign key(borrow_id) references borrow(id)
);
