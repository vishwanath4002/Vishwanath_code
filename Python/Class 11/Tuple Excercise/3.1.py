from statistics import mean
def calc():
    for i in range(5):
        print('\nTotal marks of student %s = %s'%(i+1,sum(t[i])))
        print('Average marks of student %s = %s'%(i+1,mean(t[i])))
t=()
for i in range(5):
    s=()
    print('\nStudent',(i+1))
    for j in range(1,4):
        r=eval(input('Enter the marks of subject %s :'%(j)))
        s+=r,
    t+=s,
print(t)
calc()
