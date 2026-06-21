# Example Python Code to Insert a Document 

from pymongo import MongoClient 
from bson.objectid import ObjectId 

class AnimalShelter(object): 
    """ CRUD operations for Animal collection in MongoDB """ 

    def __init__(self): 
        # Initializing the MongoClient. This helps to access the MongoDB 
        # databases and collections. This is hard-wired to use the aac 
        # database, the animals collection, and the aac user. 
        # 
        # You must edit the password below for your environment. 
        # 
        # Connection Variables 
        # 
        USER = 'aacuser' 
        PASS = 'Rainbowsky' 
        HOST = 'localhost' 
        PORT = 27017 
        DB = 'aac' 
        COL = 'animals' 
        # 
        # Initialize Connection 
        # 
        self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT)) 
        self.database = self.client['%s' % (DB)] 
        self.collection = self.database['%s' % (COL)] 

    # Create a method to return the next available record number for use in the create method
            
    # Complete this create method to implement the C in CRUD. 
    """ create() returns True/False """
    def create(self, data):
        if data is not None: 
            try:
                result = self.database.animals.insert_one(data) # data should be dictionary     
                return result.inserted_id is not None  # return true if ID was created
            except Exception as e: 
                print("Error", e)  # print error 
                return False  # return false on failure
        else: 
            raise Exception("Nothing to save, because data parameter is empty") 

    # Create method to implement the R in CRUD.
    """ read() returns list/empty list """
    
    def read(self, query): 
        try: 
            cursor = self.collection.find(query)  # execute find operation with query 
            return list(cursor)  # convert cursor to a list and return
        except Exception as e:
            print("Error ", e)  # print error
            return []  # return an empty list on failure
        
    # Create Method to implement the U in CRUD.
    """ update() returns number of modified objects """
    
    def update(self, query, updated_values):
        if query is not None and updated_values is not None: # validate input types
            if not isinstance(query, dict) or not isinstance(updated_values, dict):
                raise Exception("Query and update values must be in dictionaries")
            try:
                result = self.database.animals.update_many(query, {"$set": updated_values}) # update query using update_many() 
                return result.modified_count # return number of modified objects
            except Exception as e:
                print("Error updating query ", e) # print error 
                return 0
        else: 
            raise Exception("Error, please enter something.")
                                                                   
    # Create Method to implement the D in CRUD.
    """ delete() returns number of deleted objects """
                                                                   
    def delete(self, query):
        if query is not None and isinstance(query, dict):
            try: # delete all documents that match the query
                result = self.database.animals.delete_many(query)
                return result.deleted_count # return the number of deleted documents
            except Exception as e:
                print("Error deleting ", e) # print error 
                return 0
        else: 
            raise Exception("Query must be in dictionary.")