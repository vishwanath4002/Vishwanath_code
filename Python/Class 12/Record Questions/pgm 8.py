def ispalindrome(s):
    if len(s)<2:
        return True
    elif s[0]!=s[-1]:
        return False
    return ispalindrome(s[1:-1])
while True:
    print()
    s=input('Enter the string : ')
    print(ispalindrome(s))
    c=input('Do you want to continue ?(yes/no): ')
    if c=='no':
        break
    
