#Print factors of a numbers
n=int(input("Enter the number  : "))
i=1
while i<=n:
    if n%i==0:
        print(i,end=" ")
    i+=1
    if i==1 and i==n:
            print(n,"is a prime number.")
   
