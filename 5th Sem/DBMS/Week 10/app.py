# Importing pakages
import streamlit as st
import mysql.connector

from create import create
from database import create_table
from delete import delete
from read import read
from update import update

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    port=3306
)
c = mydb.cursor()



def main():
    st.title("Train App")
    menu = ["Add", "View", "Edit", "Remove"]
    choice = st.sidebar.selectbox("Menu", menu)

    create_table()
    if choice == "Add":
        st.subheader("Enter Train Details:")
        create()

    elif choice == "View":
        st.subheader("View created train details")
        read()

    elif choice == "Edit":
        st.subheader("Update created trains")
        update()

    elif choice == "Remove":
        st.subheader("Delete created trains")
        delete()

    else:
        st.subheader("About trains")


if __name__ == '__main__':
    main()
