CREATE TABLE User(
    user_id int,
    name varchar(20) not null,
    address varchar(20),
    contact int,
    user_type varchar(20) not null,
    user_name varchar(20) not null,
    password varchar(20) not null,
    primary key(user_id)
);
CREATE TABLE Product(
    product_id int,
    category varchar(20) not null,
    quantity int not null,
    discount float,
    refill_price float,
    name varchar(20) not null,
    managed_by int not null,
    primary key(product_id),
    foreign key(managed_by) references User(user_id)
);
CREATE TABLE Customer(
    customer_id int,
    name varchar(20) not null,
    address varchar(20),
    contact_no int,
    managed_by int not null,
    primary key(customer_id),
    foreign key(managed_by) references User(user_id)
);
CREATE TABLE POS(
    pos_id int,
    sales_no int not null,
    quantity int not null,
    total_price float not null,
    refill_price float not null,
    managed_by int not null,
    primary key(pos_id),
    foreign key(managed_by) references User(user_id)
);
CREATE TABLE Delivery_Details(
    delivery_no int,
    quantity int not null,
    total_price float not null,
    status varchar(20) not null,
    product_id int not null,
    primary key(delivery_no),
    foreign key(product_id) references Product(product_id)
);
CREATE TABLE Payment(
    payment_id int,
    delivery_id int not null,
    order_no int not null,
    total_price float not null,
    customer_id int not null,
    managed_by int not null,
    primary key(payment_id),
    foreign key(customer_id) references Customer(customer_id),
    foreign key(managed_by) references User(user_id)
);
CREATE TABLE Delivery(
    delivery_id int,
    delivery_date date not null,
    customer_id int not null,
    plate_no varchar(20) not null,
    delivery_no int not null,
    managed_by int not null,
    primary key(delivery_id),
    foreign key(managed_by) references User(user_id),
    foreign key(customer_id) references Customer(customer_id)
);