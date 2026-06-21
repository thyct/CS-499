# MongoDB + CSV Hybrid CRUD Module (enhanced for fallback)

from pymongo import MongoClient
import pandas as pd


class AnimalShelter:
    """
    CRUD class for animal shelter data.
    Enhanced with CSV fallback when MongoDB is unavailable.
    """

    def __init__(self):

        # MongoDB connection settings
        USER = "aacuser"
        PASS = "Rainbowsky"
        HOST = "localhost"
        PORT = 27017
        DB = "aac"
        COL = "animals"

        # CSV fallback file
        self.fallback_csv = "aac_shelter_outcomes.csv"
        self.use_db = False

        # Try MongoDB connection
        try:
            self.client = MongoClient(
                f"mongodb://{USER}:{PASS}@{HOST}:{PORT}",
                serverSelectionTimeoutMS=3000
            )
            self.database = self.client[DB]
            self.collection = self.database[COL]

            # test connection
            self.client.server_info()
            self.use_db = True

        except Exception as e:
            print("MongoDB connection failed, switching to CSV fallback:", e)
            
    # Create - Implement C in CRUD
    def create(self, data):
        if not isinstance(data, dict):
            return False

        if self.use_db:
            try:
                result = self.collection.insert_one(data)
                return result.inserted_id is not None
            except Exception as e:
                print("Create error:", e)
                return False
        return False

    # Read - Implement R in CRUD
    def read(self, query):
        try:
            import pandas as pd

            df = pd.read_csv("aac_shelter_outcomes.csv")

            # clean column names
            df.columns = df.columns.astype(str).str.strip()

            # optional filtering 
            if query and isinstance(query, dict):
                for key, value in query.items():
                    if key in df.columns:
                        if isinstance(value, dict):
                            if "$in" in value:
                                df = df[df[key].isin(value["$in"])]
                            elif "$gte" in value:
                                df = df[df[key] >= value["$gte"]]
                            elif "$lte" in value:
                                df = df[df[key] <= value["$lte"]]
                        else:
                            df = df[df[key] == value]

            return df.to_dict("records")

        except Exception as e:
            print("Read error:")

    # Update - Implement U in CRUD
    def update(self, query, values):
        if self.use_db:
            try:
                result = self.collection.update_many(query, {"$set": values})
                return result.modified_count
            except Exception as e:
                print("Update error:", e)
                return 0
        return 0
    
    # Delete - Implement U in CRUD
    def delete(self, query):
        if self.use_db:
            try:
                result = self.collection.delete_many(query)
                return result.deleted_count
            except Exception as e:
                print("Delete error:", e)
                return 0
        return 0
