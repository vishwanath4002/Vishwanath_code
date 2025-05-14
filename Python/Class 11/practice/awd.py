d1 = {'a':10,'b':20,'c':10}
d2 = {'a':10,'b':20,'c':30}
v1=list(d1.values())
v2=list(d2.values())
print(d1)
for i in v1:
    if v1.count(i)>1:
        print('%s keys have same values.'%(v1.count(i)))
        break
else:
    print('No key has same value.')
print(d2)
for i in v2:
    if v2.count(i)>1:
        print('%s have same values.'%(v2.count(i)))
        break
else:
    print('No key have same values.')
