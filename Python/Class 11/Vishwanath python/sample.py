t1=eval(input('Enter the first tuple : '))
t2=eval(input('Enter the second tuple : '))
t3=t1
for i in t2:
    if i not in t3:
        t3+=i,
print(t3)
