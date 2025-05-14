#Given a tuple pairs=((2,5),(4,2),(9,8),(12,10)), count the number of pairs (a,b) such that both a and b are even.
t=((2,5),(4,2),(9,8),(12,10))
c=0
for x,y in t:
    if x%2==0 and y%2==0:
        c+=1
print('The number of pairs such that both are even is :',c)
