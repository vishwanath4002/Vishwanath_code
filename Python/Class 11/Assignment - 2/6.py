#WAP to print multiplication table of anumber entered by user
def multiply():
    n=int(input('Enter the number : '))
    for i in range(1,11):
        print('%s X %s = %s'%(n,i,n*i))
multiply()
