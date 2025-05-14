#WAP to print the factors of a number enteresd by user
n=int(input('Enter the number : '))
for i in range(1,n+1):
    if n%i==0:
        print(i,end=',')
print(' are the factors of',n)
