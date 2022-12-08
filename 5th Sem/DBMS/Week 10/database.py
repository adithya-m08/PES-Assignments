# pip install mysql-connector-python
import mysql.connector

mydb = mysql.connector.connect(
    host="localhost", user="root", port=3306, database="trains"
)
c = mydb.cursor()


def create_table():
    c.execute(
        "CREATE TABLE IF NOT EXISTS TRAIN(train_no TEXT, train_name TEXT, train_type TEXT, train_src TEXT, train_dst TEXT, availability TEXT)"
    )


def add_data(train_no, train_name, train_type, train_src, train_dst, availability):
    c.execute(
        "INSERT INTO TRAIN(train_no, train_name, train_type, train_src, train_dst, availability) VALUES (%s,%s,%s,"
        "%s,%s,%s)",
        (train_no, train_name, train_type, train_src, train_dst, availability),
    )
    mydb.commit()


def view_all_data():
    c.execute("SELECT * FROM TRAIN")
    data = c.fetchall()
    return data


def view_only_train_names():
    c.execute("SELECT train_name FROM TRAIN")
    data = c.fetchall()
    return data


def get_train(train_name):
    c.execute('SELECT * FROM TRAIN WHERE train_name="{}"'.format(train_name))
    data = c.fetchall()
    return data


def edit_train_data(
    new_train_no,
    new_train_name,
    new_train_type,
    new_train_src,
    new_train_dst,
    new_availability,
    train_no,
    train_name,
    train_type,
    train_src,
    train_dst,
    availability,
):
    c.execute(
        "UPDATE TRAIN SET train_no=%s, train_name=%s, train_type=%s, train_src=%s, train_dst=%s, availability=%s WHERE "
        "train_no=%s and train_name=%s and train_type=%s and train_src=%s and train_dst=%s and availability=%s",
        (
            new_train_no,
            new_train_name,
            new_train_type,
            new_train_src,
            new_train_dst,
            new_availability,
            train_no,
            train_name,
            train_type,
            train_src,
            train_dst,
            availability,
        ),
    )
    mydb.commit()
    data = c.fetchall()
    return data


def delete_data(train_name):
    c.execute('DELETE FROM TRAIN WHERE train_name="{}"'.format(train_name))
    mydb.commit()
