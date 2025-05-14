#Write a program that interactively 
#a)creates a nested tuple to store the marks in three subjects for 5 students.
#b)Add a function that computes total marks and average marks obtained by each student.
from statistics import mean
def marks():
    for i in range(5):
        print('\nStudent %s\nSum : %s\nAverage : %s'%(i+1,sum(t[i]),mean(t[i]))
t=()
for i in range(5):
    m=()
    print('Student',i+1)
    for j in range(3):
        m+=eval(input('Enter the marks of subject %s : '%(j+1))),
    t+=m,
marks()
