# main.py
import time
from lang.python.functions import is_prime

def compute(function, *args):
    start = time.perf_counter()
    out = function(*args)
    end = time.perf_counter()
    sec = end - start
    return out, sec

for i in range(20):
    out, sec = compute(is_prime, i)
    print(f"{i} : {out} in {sec:.6f}s")
