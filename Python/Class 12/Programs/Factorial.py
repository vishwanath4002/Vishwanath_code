#factorial
def fact(n):
    f=n
    for i in range(2,n):
        f*=i
    return f

n=int(input('Enter the number : '))
print(fact(n))
