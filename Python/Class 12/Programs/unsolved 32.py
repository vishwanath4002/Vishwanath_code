#Write a program to display all teh records in a file along with line/record number.
with open('sample.txt','r') as f:
    x=1
    for i in f.readlines():
        print(x,'.',i,end='')
        x+=1
