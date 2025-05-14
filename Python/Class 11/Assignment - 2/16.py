#Calculator
def calculator():
    a,b=map(int,input('Enter the numbers : ').split())
    o=input('Enter the operator [+,-,*,/,//,%] : ')
    if o=='+':
        print('\nThe sum is %s.'%(a+b))
    elif o=='-':
        print('\nTheir difference is %s.'%(a-b))
    elif o=='*':
        print('\nTheir product is %s.'%(a*b))
    elif o=='/':
        if b!=0:
            print('\nThe quotient is %s.'%(a/b))
        else:
            print('\nDivision by zero is not possible.')
    elif o=='//':
         if b!=0:
            print('\nThe integer quotient is %s.'%(a//b))
         else:
            print('\nDivision by zero is not possible.')
    elif o=='%':
        if b!=0:
            print('\nThe remainder is %s.'%(a%b))
        else:
            print('\nDivision by zero is not possible.')
    else:
        print('\nInvalid entry.')
    print('\nType calculator() to use it again.')
calculator()
