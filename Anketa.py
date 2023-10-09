def delt():
    e1.delete(0,tk.END)
    e2.delete(0,tk.END)
    e3.delete(0,tk.END)
    e4.delete(0,tk.END)
    e5.delete(0,tk.END)
    e6.delete(0,tk.END)
    e7.delete(0,tk.END)
    e8.delete(0,tk.END)

def enter():
    print(e1.get())
    print(e2.get())
    print(e3.get())
    print(e4.get())
    print(e5.get())
    print(e6.get())
    print(e7.get())
    print(e8.get())
    
    
import tkinter as tk
window=tk.Tk()
window.title('Enter domestic adress')
window.config(bg='grey')
window.resizable(False,False)

labname=tk.Label(window,text='Name:',bg='grey', anchor='e').grid(row=0,column=0,stick='we')
labsurname=tk.Label(window,text='Surname:',bg='grey', anchor='e').grid(row=1,column=0,stick='we')
labadress1=tk.Label(window,text='Adress 1:',bg='grey', anchor='e').grid(row=2,column=0,stick='we')
labadress2=tk.Label(window,text='Adress 2:',bg='grey', anchor='e').grid(row=3,column=0,stick='we')
labsity=tk.Label(window,text='Sity:',bg='grey', anchor='e').grid(row=4,column=0,stick='we')
labregion=tk.Label(window,text='Region:',bg='grey', anchor='e').grid(row=5,column=0,stick='we')
labindex=tk.Label(window,text='Index:',bg='grey', anchor='e').grid(row=6,column=0,stick='we')
labcountry=tk.Label(window,text='Country:',bg='grey', anchor='e').grid(row=7,column=0,stick='we')

e1=tk.Entry(window, bg='white')
e2=tk.Entry(window, bg='white')
e3=tk.Entry(window, bg='white')
e4=tk.Entry(window, bg='white')
e5=tk.Entry(window, bg='white')
e6=tk.Entry(window, bg='white')
e7=tk.Entry(window, bg='white')
e8=tk.Entry(window, bg='white')

e1.grid(row=0,column=1,stick='we')
e2.grid(row=1,column=1,stick='we')
e3.grid(row=2,column=1,stick='we')
e4.grid(row=3,column=1,stick='we')
e5.grid(row=4,column=1,stick='we')
e6.grid(row=5,column=1,stick='we')
e7.grid(row=6,column=1,stick='we')
e8.grid(row=7,column=1,stick='we')

button1=tk.Button(window, text='delete',width=20, command=delt).grid(row=8,column=1,padx=4,pady=4)
button2=tk.Button(window, text='enter',width=20, command=enter).grid(row=8,column=1,sticky='e',padx=4,pady=4)


window.grid_columnconfigure(0,minsize=100)
window.grid_columnconfigure(1,minsize=600)

window.mainloop()
