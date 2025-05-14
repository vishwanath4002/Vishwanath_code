import pickle
x=[1,2,3]
y=[4,5,6]
f=open('sample.dat','wb+')
pickle.dump(x,f)
pickle.dump(y,f)
f.seek(0)
while True:
    try:
        print(pickle.load(f))
    except EOFError:
        break
f.close()
