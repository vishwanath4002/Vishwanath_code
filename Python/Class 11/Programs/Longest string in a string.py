#Read a string snd display the longest substring
'''s=input('Enter the string : ').split()
longest=s[0]
for i in range(len(s)):
    if len(s[i])>len(longest):
        longest=s[i]
        continue
print(longest)'''
s=input('Enter the string : ').split()
m=0
for i in s:
    if len(i)>m:
        m=len(i)
        l=i
print(l)

