from Conversion import lengthConversion as l, distanceConversion as d
while True:
    c=int(input('1.Feet to Inches\n2.Inches to Feet\n3.Mile to Km\n4.Km to mile\n5.Exit\nEnter your choice(1,2,3,4,5) : '))
    print()
    if c==1:
        print(l.feetToInches(float(input('Enter the length in feet : '))))
    elif c==2:
        print(l.inchesToFeet(float(input('Enter the length in inches : '))))
    elif c==3:
        print(d.mileTokm(float(input('Enter the distance in miles: '))))
    elif c==4:
        print(d.kmTomile(float(input('Enter the distance in Km : '))))
    elif c==5:
        break
    else:
        print('Invalid entry. Please try again.')
    print()
