#Write a program to display unique vowels present in the given word using stack,
def PUSH(x):
    stack.append(x)
def TRAVERSAL(x):
    for i in stack[::-1]:
        print(i)

x=input('Enter the word : ')
v='aeiou'
stack=[]
for i in x:
    if i.lower() in v and i not in stack:
        PUSH(i)
TRAVERSAL(stack)
