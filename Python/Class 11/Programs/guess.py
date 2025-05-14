#WAP to guess a number between 1 and 10 user chosen by the user in 10 tries.
from random import randint
print('Try to guess the number between 1 and 10 I have chosen. You have only ten chances .')
for i in range(10):
    b=int(input('Enter your guess :  '))
    a=randint(1,10)
    if b==a:
        print('\        /  _______                     \                          /    ___\n  \    /    |          |   |           |       \                       /     |__|   |\     |\n    \/      |          |   |           |         \        /\        /        __    |  \   |\n     |       |          |   |           |           \    /    \    /         |   |   |    \ |\n     |       |______|   |______|             \/        \/           |__|   |     \|\n\nWell guessed in the attempt %s'%(i+1))
        break
    elif b!=a:
        print('Nice try.\nTry again.')
    if i+1==10:
        print('You have run out of chances.\nTry again later')
        break
