def Value(x,y=3,z=5):
    global s
    s=s+y+z
    y=y-z
    z=s+1
    print( x,"@",y,"@",z)
    return z
x=10
y=20
s=100
r1=Value(x,y)
print( s,"$",r1)
r2=Value(x)
print( s,"$",r2)
