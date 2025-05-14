#4
ch='yes'
s=0
while ch=='yes':
    p=float(input('Enter the price of the item : '))
    q=float(input('Enter the quantity : '))
    s+=p*q
    ch=input('Are ther more items (yes or no) : ')
if s<=25000:
    d=s*5/100
elif s>25000 and s<=50000:
    d=s*10/100
else:
    d=s*20/100
n=s-d
print('Total amount is : %s\nDiscount amount : %s\nNet amount to be paid : %s'%(s,d,n))   
