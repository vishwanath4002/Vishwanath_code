#9
try:
    d2={}
    d1=eval(input('Enter the dictionary : '))
    for i,j in d1.items():
        d2[j]=i
    print(d2)
except:
    print('Mapping not allowed with mutable values.')
else:
    print('No errors.')
