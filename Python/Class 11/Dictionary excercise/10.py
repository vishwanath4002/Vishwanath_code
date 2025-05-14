#10
d2={}
d1=eval(input('Enter the dictionary with lists as the values : '))
for i,j in d1.items():
    d2[i]=sum(j)
print(d2)
