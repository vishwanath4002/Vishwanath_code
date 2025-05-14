#Remove vowels from the string entered by the user
def vowelremove():
    a=input('Enter a string : ')
    for i in a:
        if i in 'AEIOUaeiou':
            continue
        else:
            print(i,end='')
vowelremove()
