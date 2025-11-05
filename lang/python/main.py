# main.py
import os
from lib import functions, compute, database

# Value from which the programme start to check if it is prime and stop to check
start = 100000
end = 100005

def main():

    # Initialize directory for database
    db_dir = os.path.join(os.path.dirname(__file__), 'db')
    os.makedirs(db_dir, exist_ok=True)

    # Determine if a number is prime with linear interpolation
    db_path = os.path.join(db_dir, 'every_number.db')
    database.init_db(db_path)
    for i in range(start,end):
        out, sec = compute.compute(functions.every_number, i)
        database.insert_res(out,sec)
    database.close_db()

    db_path = os.path.join(db_dir, 'square_iterator.db')
    database.init_db(db_path)
    for i in range(start,end):
        out, sec = compute.compute(functions.square_iterator, i)
        database.insert_res(out,sec)
    database.close_db()

    db_path = os.path.join(db_dir, 'square_root_ceil.db')
    database.init_db(db_path)
    for i in range(start,end):
        out, sec = compute.compute(functions.square_root_ceil, i)
        database.insert_res(out,sec)
    database.close_db()

if __name__ == "__main__":
    main()