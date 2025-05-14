#5
d1=eval(input('Enter the items of the first dictionary : '))
d2=eval(input('Enter the items of the second dictionary : '))
d3=d1.copy()
d3.update(d2)
for i,x in d1.items():
    for j,y in d2.items():
        if i==j:
            d3[i]=x+y
print(d3)
