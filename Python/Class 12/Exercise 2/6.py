def sumsquare(n):
    if n==0:
        return n
    return n*n+sumsquare(n-1)
