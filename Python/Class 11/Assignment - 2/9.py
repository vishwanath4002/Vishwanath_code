'''WAP to input some numbers repeatedly and print their sum.The program
ends when the user inputs no more to enter or when the number entered
is less than zero'''

s=0
while True:
    n=input('Enter the number : ')
    if n=='no more to enter' or int(n)<0 :
        break
    s+=int(n)
    print('Sum : %d' %s)

