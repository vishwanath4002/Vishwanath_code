'''Area of circle
2.Area of rectangle
3.Area of square
4.Exit'''

ch='yes' or 'y'
while ch=='yes' or ch=='y':
    n=int(input('\n1.Area of circle\n2.Area of rectangle\n3.Area of square\n4.Exit\nEnter your choice[1,2,3,4] : '))
    if n==1:
        r=float(input('Enter the radius of the circle : '))
        print('The area of the circle is ',22/7*r**2)
    elif n==2:
        l,b=map(float,input('Enter the length and breadth of the rectangle : ').split())
        print('The area of the rectangle is ',l*b)
    elif n==3:
        s=float(input('Enter the side of the square : '))
        print('The area is ',s**2)
    elif n==4:
        exit()
    ch=input('\nDo you want to continue ? : ')
