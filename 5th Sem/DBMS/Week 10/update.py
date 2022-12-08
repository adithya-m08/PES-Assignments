import datetime

import pandas as pd
import streamlit as st
from database import view_all_data, view_only_train_names, get_train, edit_train_data


def update():
    result = view_all_data()
    # st.write(result)
    df = pd.DataFrame(result, columns=['Train_no', 'Train Name', 'Train Type', 'Source', 'Destination', 'Availability'])
    with st.expander("Current data"):
        st.dataframe(df)
    list_of_trains = [i[0] for i in view_only_train_names()]
    selected_train = st.selectbox("Train to Update", list_of_trains)
    selected_result = get_train(selected_train)
    # st.write(selected_result)
    if selected_result:
        train_no = selected_result[0][0]
        train_name = selected_result[0][1]
        train_type = selected_result[0][2]
        train_src = selected_result[0][3]
        train_dst = selected_result[0][4]
        availability = selected_result[0][5]

        # Layout of Create

    col1, col2 = st.columns(2)
    with col1:
        new_train_no = st.text_input("Train no:")
        new_train_name = st.text_input("Name:")
        new_train_type = st.text_input("Train Type:")
    with col2:
        new_train_src = st.selectbox("Src", ["Bangalore", "Chennai", "Mangaluru"])
        new_train_dst = st.selectbox("Dst", ["Bangalore", "Chennai", "Mangaluru"])
        new_availability = st.selectbox("Availability", ["Yes", "No"])
        if st.button("Update Dealer"):
            edit_train_data(new_train_no, new_train_name, new_train_type, new_train_src, new_train_dst, new_availability, train_no, train_name, train_type, train_src, train_dst, availability)
            st.success("Successfully updated:: {} to ::{}".format(train_name, new_train_name))

    result2 = view_all_data()
    df2 = pd.DataFrame(result2, columns=['Train_no', 'Train Name', 'Train Type', 'Source', 'Destination', 'Availability'])
    with st.expander("Updated data"):
        st.dataframe(df2)
