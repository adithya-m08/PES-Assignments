import streamlit as st
import pandas as pd
import mysql.connector
from create import *

mydb = mysql.connector.connect(**st.secrets["mysql"])
c = mydb.cursor()


def view_table(table_name):
    c.execute("SELECT * FROM " + table_name)
    data = c.fetchall()
    return data


def add(o, v):
    q = "INSERT INTO {}  VALUES {}".format(o, v)
    c.execute(q)
    mydb.commit()
    st.success("Added successfully")


def edit(v):
    res = v.split(",")
    q = (
        "UPDATE user set name ="
        + res[1]
        + ", address ="
        + res[2]
        + ", contact ="
        + res[3]
        + ", user_type ="
        + res[4]
        + ", user_name ="
        + res[5]
        + ", password ="
        + res[6]
        + " where user_id = "
        + res[0]
    )
    c.execute(q)
    mydb.commit()
    st.success("Row successfully updated")


def runquery(a):
    c.execute(a)
    res = c.fetchall()
    df = pd.DataFrame(res)
    st.dataframe(df)
    st.success("Query executed successfully")


def delete(i):
    q = "DELETE FROM user where user_id = " + i
    c.execute(q)
    mydb.commit()
    st.success("User removed")
