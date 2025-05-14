def add(a,b,c=10):
    return a+b+c
a,b,c=map(eval,input('Enter the numbers : ').split())
print(add(a,b))
print(add(a,b,c))
print(add(a))
