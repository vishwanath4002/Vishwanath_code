def naturalNumbers(n):
    for i in range(n):
        print(i+1,end=' ')

def fibonacciSeries(n):
    c=0
    a,b=0,1
    while c<n:
        print(a,end=' ')
        a,b=b,a+b
        c+=1

def square(n):
    for i in range(n):
        print((i+1)**2,end=' ')

def primeNumbers(n):
    for i in range(1,n+1):
        for j in range(2,i//2):
            if i%j==0:
                break
        else:
            print(i,end=' ')
