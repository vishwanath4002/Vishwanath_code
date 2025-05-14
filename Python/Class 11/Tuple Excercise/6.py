t=((2,5),(4,2),(9,8),(12,10))
print(t)
count=0
for i in t:
    if i[0]%2==0 and i[1]%2==0:
        count+=1
    else:
        continue
print('The number of groups in which which elements are even are : ',count)
