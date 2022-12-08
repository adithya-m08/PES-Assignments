import pandas as pd
import streamlit as st
import plotly.express as px
from database import view_all_data


def read():
    result = view_all_data()
    # st.write(result)
    df = pd.DataFrame(result, columns=['Train_no', 'Train Name', 'Train Type', 'Source', 'Destination', 'Availability'])
    with st.expander("View all Trains"):
        st.dataframe(df)
    with st.expander("Train Name"):
        task_df = df['Train Name'].value_counts().to_frame()
        task_df = task_df.reset_index()
        st.dataframe(task_df)
        p1 = px.pie(task_df, names='index', values='Train Name')
        st.plotly_chart(p1)
