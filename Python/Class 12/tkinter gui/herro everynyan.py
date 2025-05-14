from tkinter import *
def clicked():
    res="Welcome to "+txt.get()
    Label(text=res).grid(column=1, row=1)
window=Tk()
txt=Entry(window, width=10)
txt.grid(column=1,row=0)
bt=Button(window, text="Enter", font=("Arial"), command=clicked)
bt.grid(column=2,row=0)
window.geometry('640x384')
window.mainloop()
