# lib/database.py
import sqlite3

# global variables
_db_connection = None
_db_cursor = None

# Create database
def init_db(path):
    global _db_connection, _db_cursor
    _db_connection = sqlite3.connect(path)
    _db_cursor = _db_connection.cursor()
    _db_cursor.execute('''
        CREATE TABLE IF NOT EXISTS is_prime (
            VALUE   INTEGER     NOT NULL    UNIQUE,
            TIME    REAL        NOT NULL
        )
    ''')
    _db_connection.commit()

# Close database
def close_db():
    global _db_connection
    if _db_connection:
        _db_connection.close()
        _db_connection = None

# Insert new value if it is not already in
def insert_res(value, avg_time):
    _db_cursor.execute("INSERT OR IGNORE INTO is_prime (VALUE, TIME) VALUES (?, ?)", (value, avg_time))
    _db_connection.commit()