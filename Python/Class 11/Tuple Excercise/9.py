from statistics import mean
a=()
t=((1,2),(3,4.15,5.15),(7,8,12,15))
print('The mean of the individual elements are : ')
for i in t:
    a+=mean(i),
    print(i,' :',mean(i))
print('The mean of the individual means are : ',mean(a))
