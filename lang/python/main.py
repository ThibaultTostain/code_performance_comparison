# main.py
from lib import functions, compute

for i in range(100000,100005):
    print("")
    out, sec = compute.compute(functions.square_root_ceil, i)
    print(f"{i} : {out} in {sec:.6f}s")
