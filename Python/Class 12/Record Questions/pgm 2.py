def f(a):
    f=a
    for i in range(2,a):
        f*=i
    return f

def sin(x,n):
    sinx=x
    a=3
    for i in range(1,n+1):
        sinx+=(((-1)**i)*(x**a))/f(a)
        a+=2
    return sinx

def cos(x,n):
    cosx=1
    a=2
    for i in range(1,n+1):
        cosx+=(((-1)**i)*(x**a))/f(a)
        a+=2
    return cosx

while True:
    c=int(input('\n1.sinx=x - x**3/3! + x**5/5! - ...\n2.cosx=1 - x**2/2! + x**4/4! - ...\n3.Exit.\nEnter your choice (1,2,3):'))
    print()
    if c==1:
        x=float(input('Enter the value of x : '))
        n=int(input('Enter the number of terms : '))
        print('sin(%s) = %s'%(x,sin(x,n)))
    elif c==2:
        x=float(input('Enter the value of x : '))
        n=int(input('Enter the number of terms : '))
        print('cos(%s) = %s'%(x,cos(x,n)))
    elif c==3:
        break
    else:
        print('Invalid entry. Please try again.')        
