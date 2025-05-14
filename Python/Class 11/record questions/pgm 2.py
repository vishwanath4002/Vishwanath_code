#2
ch=int(input('1.Simple interest\n2.Compound interest\nEnter your choice (1 or 2) : '))
if ch==1:
    p=float(input('Enter the principal amount : '))
    r=float(input('Enter the rate of interest in percentage : '))
    t=float(input('Enter the time in years : '))
    print('Simple interest :',(p*r*t)/100)
elif ch==2:
    p=float(input('Enter the principal amount : '))
    r=float(input('Enter the rate of interest in percentage : '))
    t=float(input('Enter the time in years : '))
    print('Compound interest :',(p*(1+r/100)**t)-p)
else:
    print('Invalid entry.')
