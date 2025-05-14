#Write a program to search for an element in a given list of numbers.
l=eval(input('Enter a list of numbers : '))
x=eval(input('Enter the number to be searched : '))
if x in l:
        print('Number found at position %s.'%(l.index(x)))
else:
        print('Number not found.')
