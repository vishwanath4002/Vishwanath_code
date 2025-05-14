#Read n values and store them inside a list and display the even numbers
x=[]
n=int(input('Enter the limit : '))
for i in range(n):
    a=int(input('Enter the %sth number : '%(i+1)))
    if a%2==0:
        x.append(a)
print('The even numbers are',x)
