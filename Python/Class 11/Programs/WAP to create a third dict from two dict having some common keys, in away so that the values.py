#WAP to create a third dict from two dict having some common keys, in away so that the values
#of common keys are added as a value in the third dict
a={1:35,6:29,5:67}
b={3:90,5:15,6:1}
c={}
for i,j in a.items():
    for x,y in b.items():
        if i==x:
            c[i]=j+y
print(c)
