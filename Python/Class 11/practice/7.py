#Write a program to create a nested tuple to store roll number, name and marks of n students.
t=()
for i in range(int(input('Enter the number of students : '))):
    print('\nStudent',i+1)
    s=()
    s+=int(input('Enter the roll number : ')),
    s+=input('Enter the name : '),
    s+=eval(input('Enter the marks : ')),
    t+=s,
print(t)
