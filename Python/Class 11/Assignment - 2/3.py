#WAP that reads three numbers and print them in ascending
a,b,c=map(int,input('Enter the three numbers : ').split())
if a<c and a<b:
    if b<c:
        print(a,b,c)
    else:
        print(a,c,b)
elif b<a and b<c:
    if a<c:
        print(b,a,c)
    else:
        print(b,c,a)
elif c<a and c<b:
    if a<b:
        print(c,a,b)
    else:
        print(c,b,a)
