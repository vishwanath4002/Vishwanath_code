def fibonacci(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    return fibonacci(n-1)+fibonacci(n-2)

n=int(input('Enter the number of terms : '))
if n<0:
    print('Invalid.')
else:
    for i in range(n):
        print(fibonacci(i))

