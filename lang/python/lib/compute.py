import time

def compute(function, *args):
    start = time.perf_counter()
    for i in range(10):
        out = function(*args)
    end = time.perf_counter()
    sec = (end - start)/10
    return out, sec