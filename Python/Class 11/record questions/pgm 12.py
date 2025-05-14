#12
def palindrome(s):
        c=0
        j=-1
        for i in s:
                if i==s[j]:
                        j-=1
                        c+=1
        if c==len(s):
                return True
        
def iandc(sub):
    if sub in s:
        print('The first index of %s in %s is %s and the count is %s.'%(sub,s,s.index(sub),s.count(sub)))
    else:
        print('%s is not in %s'%(sub,s))

while True:        
    s=input('\nEnter the string : ')
    print('\n1.Check whether the string is a palindrome.\n2.Print the first index and count of the substring entered in the string.\n3.Exit')
    c=int(input('\nEnter your choice : '))


    if c==1:
        if palindrome(s):
            print('\n%s is a palindrome.'%(s))
        else:
            print('\n%s is not a palindrome.'%(s))
    elif c==2:
        sub=input('\nEnter the substring : ')
        iandc(sub)
    elif c==3:
        break
    else:
        print('\nInvalid entry.')
