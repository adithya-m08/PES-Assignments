from pymongo import MongoClient

# host = MongoClient("172.17.0.2")
host = MongoClient("mongodb://mongodb:27017/")

db = host["sample_pp"]
collection = db["sample_pploection"]

sample_data = {"Name:": "Adithya M", "SRN": "PES1UG20CS621"}
collection.insert_one(sample_data)
print("Inserted into the MongoDB database!")
rec_data = collection.find_one({"Name:": "Adithya M"})
print("Fetched from MongoDB: ", rec_data)
