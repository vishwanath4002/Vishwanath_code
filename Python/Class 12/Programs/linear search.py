def linearsearch(l,e):
        for i in range(len(l)):
            if l[i]==e:
                return i
        return -1

a=eval(input(('Enter the list : ')))
b=eval(input('Enter the element to be searched : '))
print('Index :',linearsearch(a,b))
