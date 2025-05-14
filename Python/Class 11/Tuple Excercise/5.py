#WAP a program to display the length of the shortest string in the tuple of strings
t=()
n=int(input('Enter the number of strings : '))
for i in range(n):
    t+=input('Enter the string : '),
minimum=t[0]
for i in t:
    if len(i)<len(minimum):
        minimum=i
    else:
        continue
print('Length of the shortest string is : ',len(minimum))
