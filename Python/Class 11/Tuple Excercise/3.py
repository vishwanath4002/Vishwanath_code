#Nested tuple for 5 students , three sublects find total and average
t=()
for i in range(5):
    s=()
    print('Student',i+1)
    for j in range(1,4):
        r=eval(input('Enter the marks of subject %s :'%(i)))
        s+=r,
    t+=s,
print(t)
