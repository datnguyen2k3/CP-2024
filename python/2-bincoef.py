from functools import lru_cache

@lru_cache(maxsize=None)
def comb(n, k):
    if k == 0 or k == n:
        return 1
    if k == 1:
        return n
    
    return comb(n - 1, k - 1) + comb(n - 1, k)