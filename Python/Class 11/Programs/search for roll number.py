#WAP to store n student details in a dictionary and display information on the basis of admission number
n=int(input('Enter the limit : '))
d={}

for i in range(n):
    r=int(input('Enter the roll number : '))
    d[r]=input('Enter the name : ')
print(d)
x=int(input('Enter the roll number to be found : '))
print(d.get(x,'Not found.'))
