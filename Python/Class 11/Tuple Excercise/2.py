#WAP to create a nested tuple to store roll number, name and marks of n students
t=()
n=int(input('Enter the number of students : '))
for i in range(n):
    s=()
    s+=int(input('Enter the roll number : ')),
    s+=input('Enter the name : '),
    s+=float(input('Enter the marks : ')),
    t+=s,
print(t)
