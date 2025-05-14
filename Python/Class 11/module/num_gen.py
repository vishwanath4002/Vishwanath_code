def prime(n):
    print('The prime number upto %s are : ',)
    for i in range(2,n+1):
        for j in range(2,i):
            if i%j==0:
                break
            else:
                print(i,end=',')
def fibonacci(n):
    a=0
    b=1
    for i in range(n):
        print(a)
        c=a+b
        a,b=b,c

