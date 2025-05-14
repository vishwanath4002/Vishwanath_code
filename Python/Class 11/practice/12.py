#Write a program that inputs two tuples a and b and prints
#True if every element in a is also an element of b, else print False.
a,b=(),()
for i in range(int(input('Enter the number of terms of the first tuple : '))):
    a+=eval(input('Enter the element : ')),
for j in range(int(input('\nEnter the number of terms in the second tuple : '))):
    b+=eval(input('Enter the element : ')),
for i in a:
    if i not in b:
        print('False.')
        break
else:
    print('True.')
