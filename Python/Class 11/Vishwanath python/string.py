n=input('Enter the string : ')
for i in n:
    if i in 'aeiouAEIOU':
        continue
    else:
        print(i,end='\t')
