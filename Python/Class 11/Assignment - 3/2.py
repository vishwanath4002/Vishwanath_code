#WAP that accepts str s1 amd s2,create a new str by appending s2 in the middle of s1
s1=input('Enter the first string : ')
s2=input('Enter the second string : ')
m=len(s1)//2
s=s1[0:m]+s2+s1[m:]
print(s)
