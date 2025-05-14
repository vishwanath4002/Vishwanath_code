def digit(n):
    if n==0:
        return n
    return n%10+digit(n//10)
print(digit(123))
