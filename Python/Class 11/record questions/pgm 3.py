#3
ch=int(input('1.Area of rectangle\n2.Area of square\n3.Area of triangle\nEnter your choice : '))
if ch==1:
    l=eval(input('Enter the length of the rectangle : '))
    b=eval(input('Enter the breadth of the rectangle : '))
    print('Area :',l*b)
elif ch==2:
    s=eval(input('Enter the side of the square : '))
    print('Area :',s**2)
elif ch==3:
    b=eval(input('Enter the base of the triangle : '))
    h=eval(input('Enter the height of the triangle : '))
    print('Area :',0.5*b*h)
else:
    print('Invalid entry.')
