#WAP to input names of n employees and salary details(basic pay, rent allowance, etc.)
#Display the total salary

n=int(input('Enter the number of employeses : '))
d={}
for i in range(n):
    s=input('Enter the name : ')
    m=eval(input('Enter the basic pay : '))
    h=eval(input('Enter the allowance (house rent) : '))
    c=eval(input('Enter the conveyance allowance : '))
    d[s]=[m,h,c]
print(d)
for i in d.keys():
    print(i,'%d : salary :',sum(d[i]))
