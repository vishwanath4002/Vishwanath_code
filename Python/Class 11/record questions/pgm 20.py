#20
def name(n):
    s=''
    for i in n:
        s+=(a[i])+' '
    return s

a={'0':'Zero', '1':'One', '2':'Two', '3':'Three', '4':'Four', '5':'Five', '6':'Six', '7':'Seven', '8':'Eight', '9':'Nine', '.':'Point'}

while True:

    d={}

    print()

    print('1.To count the frequency of the elements in a list using a dictionary.\n2.To input a number and display the corresponding number names.\n3.Exit')
    c=int(input('Enter your choice (1/2/3) : '))

    print()

    if c==1:
        l=eval(input('Enter the list : '))
        print()
        for i in l:
            d[i]=l.count(i)
        print(d)

    elif c==2:

        n=input('Enter the number to display the number name of : ')
        print()
        print(name(n))

    elif c==3:

        break

    else:

        print('Invalid entry. Please try again.')
