#Write a program to create
#a tuple containing the squares of the integers 1 through 50
#the tuple (‘a’,’bb’,’ccc’,’dddd’….) ends with 26 copies of letter z.
t=()
a=()
for i in range(1,51):
    for j in range(1,27):
        if len(a)==26:
            break
        else:
            a+=chr(96+j)*j,
    t+=i**2,
print('%s\n%s'%(t,a))

