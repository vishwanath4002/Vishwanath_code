def Score_add(Game):
    n=input('Enter the name : ')
    s=int(input('Enter the score : '))
    Game.append([n,s])
    for i in Game[::-1]:
        print()
        print(i[0],':',i[1])

def Score_del(Game):
    if len(Game)>0:
        return Game.pop()
    else:
        print('Underflow')
        
    
