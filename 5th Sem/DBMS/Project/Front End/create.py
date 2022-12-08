import streamlit as st
import pandas as pd
from database import *


def display(table_name):
    result = view_table(table_name)
    if table_name == "customer":
        df = pd.DataFrame(
            result,
            columns=["customer_id", "name", "address", "contact_no", "managed_by"],
        )
    if table_name == "delivery":
        df = pd.DataFrame(
            result,
            columns=[
                "delivery_id",
                "delivery_date",
                "customer_id",
                "plate_no",
                "delivery_no",
                "managed_by",
            ],
        )
    if table_name == "user":
        df = pd.DataFrame(
            result,
            columns=[
                "user_id",
                "name",
                "address",
                "contact",
                "user_type",
                "user_name",
                "password",
            ],
        )

    st.dataframe(df)
