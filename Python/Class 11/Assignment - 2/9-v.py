s=0
while True:
    n=input('Enter the number : ')
    if n=='no more to enter' or int(n)<0:
        break
    s+=int(n)
    print('The sum is : %s' %s)
