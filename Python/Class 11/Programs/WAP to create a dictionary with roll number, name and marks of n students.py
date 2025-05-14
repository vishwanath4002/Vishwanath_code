#WAP to create a dictionary with roll number, name and marks of n students
#in  a class and display the name of students who got marks above 75

n=int(input('Enetr the number of students : '))
d={}
for i in range(n):
    r,name,m=map(eval,input('Enter the roll number, name and marks : ').split())
    d[r]=[name,m]
for i in d.keys():
    print('%s\t\t%s\t\t%s'%(i,d[i][0],d[i][1]))
print('Student(s) who got above 75 are :')
for i in d.keys():
    if d[i][1]>=75:
        print(d[i][0])
    else:
        continue
