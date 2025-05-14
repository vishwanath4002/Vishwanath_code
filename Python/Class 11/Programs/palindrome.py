#Check for palindrome
'''s=input('Enter the string : ')
  i=0
  j=len(s)-1
  while i<j:
      if s[i]==s[j]:
          i+=1
          j-=1
      else:
          print('Not a palindrome.')
          break
  else:
      print('Palindrome')'''
s=input('Enter the string :')
if s==s[::-1]:
    print('It is a palindrome.')
else:
    print('Not a palindrome.')
