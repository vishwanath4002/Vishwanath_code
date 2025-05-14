secret_number=9
for i in range(3):
    a=int(input('Guess: '))
    if a==secret_number:
        print('You won.')
        break
