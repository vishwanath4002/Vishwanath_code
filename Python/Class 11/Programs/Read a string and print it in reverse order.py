#Read a string and print it in reverse order
s=input('Enter a string : ')
for i in range(1,len(s)+1):
    print(s[-i],end='')
