# Importing pakages
import streamlit as st
from create import *
from database import *

def main():
    st.title("Water Refill Management System")
    menu = ["View", "Add", "Edit", "Delete", "Run Custom Query"]
    choice = st.sidebar.selectbox("Menu", menu)

    if choice == "View":
        option = st.selectbox(
            "Select a table",
            (
                "customer",
                "delivery",
                "user",
            ),
        )
        display(option)

    if choice == "Add":
        st.subheader("Add data to table")
        option = st.selectbox("Select table to view", ("customer", "delivery", "user"))
        display(option)
        vals = st.text_input("Add to table", placeholder="Enter tuples")
        if st.button("Add"):
            add(option, vals)

    if choice == "Edit":
        st.subheader("Edit data in table")
        display("user")
        vals = st.text_input("Edit table", placeholder="Enter tuples")
        if st.button("Edit"):
            edit(vals)

    if choice == "Delete":
        st.subheader("Delete data from table")
        display("user")
        vals = st.text_input("Delete from table", placeholder="Enter user id")
        if st.button("Delete"):
            delete(vals)

    if choice == "Run Custom Query":
        st.text("Enter the query below")
        q = st.text_area("Enter query")
        if st.button("Run"):
            runquery(q)


if __name__ == "__main__":
    main()
