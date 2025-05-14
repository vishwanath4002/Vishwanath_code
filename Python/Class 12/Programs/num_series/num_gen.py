def prime_gen(n):
    l=[]
    a=2
    while len(l)<n:
        for i in range(2,a):
            if a%i==0:
                break
        else:
            l.append(a)
        a+=1
    return l

def fib_gen(n):
    l=[]
    a,b=0,1
    for i in range(n):
        l.append(a)
        a,b=b,a+b
    return l
