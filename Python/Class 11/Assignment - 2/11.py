#WAP that searches for prime numbers from 15 through 25
for i in range(15,26):
    for j in range(2,i):
        if i%j==0:
            break
    else:
        print(i,end=' ')
print(' are the prime numbers between 15 and 25')
