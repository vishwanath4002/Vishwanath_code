#Read n numbers and display only prime numbers
n=int(input('Enter the limit : '))
a=[]
b=[]
for i in range(n):
    a.append(int(input('Enter the element : ')))
for i in a:
    for j in range(2,(i//2)+1):
        if i%j==0:
            break
        print(i)    
