#Write a program to read two lists num and denum which contain numerators and denominators of
#same fractions at the respective indexes. Then display the smallest fraction along with its index.
num=[]
denum=[]
f=[]
n=int(input('Enter the number of elements : '))
print('Enter the numerators.')
for i in range(n):
    num.append(int(input('Enter numerator %s : '%(i+1))))
print()
print('Enter denominators greater than zero.')
for i in range(n):
    denum.append(int(input('Enter denominator %s : '%(i+1))))
for j in range(n):
    f.append(num[j]/denum[j])
print(f)
print('The smallest fraction is %s and its index is %s.'%(min(f),f.index(min(f))))
