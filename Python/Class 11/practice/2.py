#Write a program that input a list , replicates it twice and then print the sorted list in ascending and descending order.
l=eval(input('Enter a list : '))
print('Ascending order : %s \nDescending order : %s'%(sorted(l*2),sorted(l*2,reverse=True)))
