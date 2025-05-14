#wap to read the roll number of n students  and their name
n=int(input('Enter the number of students : '))
d={}
for i in range(n):
   r,d[r]=map(eval,input('Enter the roll number and name of the student : ').split())
print(d)
