#2
d={}
n=int(input('Enter the number of students : '))
for i in range(n):
    r=int(input('Enter the roll number : '))
    n=input('Enter the name : ')
    m=eval(input('Enter the marks : '))
    d[r]=[n,m]
print(d)
print('The students who got more than 75 are : ')
for i in d:
    if d[i][1]>75:
        print(d[i][0],end=',')
