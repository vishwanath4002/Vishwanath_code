#Input a list, replicates it twice and print it in both ascending and descending
s=[]
n=int(input('Enter the limit : '))
for i in range(n):
    s.append(int(input('Enter the number : ')))
print(s)
print('Ascending order :',sorted(s*2),'\ndescending order :',sorted(s*2,reverse=True))
