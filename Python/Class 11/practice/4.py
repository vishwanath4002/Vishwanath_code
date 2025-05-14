#Write a program to input two lists and display the maximum element from
#the elements of both the lists combined, along with its index in its list.
l1=eval(input('Enter the first list : '))
l2=eval(input('Enter the second list : '))
m=max(l1+l2)
print('The maximum element is : ',m)
if m in l1:
    if m in l2:
        print('Index of %s in the first list is %s.\nIndex of %s in the second list is %s.'%(m,l1.index(m),m,l2.index(m)))
    else:
        print('Index of %s in the first list is %s.'%(m,l1.index(m)))
elif m in l2:
    print('Index of %s in the second list is %s.'%(m,l2.index(m)))
