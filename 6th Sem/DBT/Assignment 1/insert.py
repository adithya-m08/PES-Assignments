import mysql.connector
import random
import datetime

# Connect to the MySQL database
db = mysql.connector.connect(
  host="localhost",
  user="root",
  password="",
  database="library"
)

# Create a cursor object
cursor = db.cursor()

# Define a function to generate a random date
def random_date(start_date, end_date):
    delta = end_date - start_date
    random_days = random.randint(0, delta.days)
    return start_date + datetime.timedelta(days=random_days)

# Generate 10000 records for each table
for i in range(1, 10001):
    # Insert a record into the category table
    category_name = f"Category {i}"
    sub_category_id = random.randint(1, 10000)
    cursor.execute("INSERT INTO category (id, name, sub_category_id) VALUES (%s, %s, %s)", (i, category_name, sub_category_id))

    # Insert a record into the books table
    book_title = f"Book {i}"
    book_author = f"Author {i}"
    book_price = random.randint(1, 100)
    book_publish_date = random_date(datetime.date(2000, 1, 1), datetime.date(2022, 12, 31))
    cursor.execute("INSERT INTO books (id, title, author, price, publish_date, category_id) VALUES (%s, %s, %s, %s, %s, %s)", (i, book_title, book_author, book_price, book_publish_date, i))

    # Insert a record into the borrow table
    user_id = i
    book_id = i
    due_date = random_date(datetime.date(2023, 1, 1), datetime.date(2024, 12, 31))
    fee = random.randint(0, 100)
    cursor.execute("INSERT INTO borrow (id, user_id, book_id, due_date, fee) VALUES (%s, %s, %s, %s, %s)", (i, user_id, book_id, due_date, fee))

    # Insert a record into the user table
    user_address = f"Address {i}"
    user_phone_no = random.randint(1000000000, 9999999999)
    user_date_of_expiry = random_date(datetime.date(2024, 1, 1), datetime.date(2030, 12, 31))
    borrow_id = i
    cursor.execute("INSERT INTO user (id, address, phone_no, date_of_expiry, borrow_id) VALUES (%s, %s, %s, %s, %s)", (user_id, user_address, user_phone_no, user_date_of_expiry, borrow_id))

    # Insert a record into the returns table
    return_date = random_date(datetime.date(2023, 1, 1), datetime.date(2024, 12, 31))
    fees = random.randint(0, 100)
    remarks = f"Remarks {i}"
    cursor.execute("INSERT INTO returns (id, borrow_id, return_date, fees, remarks) VALUES (%s, %s, %s, %s, %s)", (i, borrow_id, return_date, fees, remarks))

# Commit the changes to the database
db.commit()

# Close the database connection
db.close()
