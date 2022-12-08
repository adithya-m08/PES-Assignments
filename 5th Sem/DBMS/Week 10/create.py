import streamlit as st
from database import add_data


def create():
    col1, col2 = st.columns(2)
    with col1:
        train_no = st.text_input("Train no:")
        train_name = st.text_input("Name:")
        train_type = st.text_input("Train Type:")
    with col2:
        train_src = st.selectbox("Src", ["Bangalore", "Chennai", "Mangaluru"])
        train_dst = st.selectbox("Dst", ["Bangalore", "Chennai", "Mangaluru"])
        availability = st.selectbox("Availability", ["Yes", "No"])
    if st.button("Add Train"):
        add_data(train_no, train_name, train_type, train_src, train_dst, availability)
        st.success("Successfully added Train: {}".format(train_name))
