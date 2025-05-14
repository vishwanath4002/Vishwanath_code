#6
d=eval(input('Enter the items of the dictionary : '))
print('The greatest value is %s and the second greatest is %s.'%(sorted(d.values())[-1],sorted(d.values())[-2]))
