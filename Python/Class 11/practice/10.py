#Write a program to display the length of the shortest string in the tuple of strings.
t=()
for i in range(int(input('Enter the number of strings : '))):
    t+=input('Enter the string : '),
a=[]
for j in t:
    if len(j)==len(min(t)):
        a.append(j)
print('Shortest strings are : ')
for i in a:
    print(i,end=',')

