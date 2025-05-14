def odd(l):
    for i in range(len(l)):
        if l[i]%2!=0:
            l[i]*=2
    return l
l=eval(input('Enter the list : '))
odd(l)
print(l)
