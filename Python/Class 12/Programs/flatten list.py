l=[1,2,3,[4,5,6,[7,8]],[9,10,11]]
s=str(l)
x=[]
y=''
for i in s:
    if i==',':
        x.append(int(y))
        y=''
        continue
    if i.isdigit():
        y+=i
print(x)
