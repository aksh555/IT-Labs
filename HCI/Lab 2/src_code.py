import PySimpleGUI as sg
import time
import random
from playsound import playsound


animals = ['Tiger', 'Dolphin', 'Camel', 'Elephant', 'Snake', 'Frog', 'Horse', 'Monkey', 'Panther']
rand_animals = animals.copy()
random.shuffle(rand_animals)

def recall_freq(animals, input):
    diff = [str(animals.index(i)+1) for i, j in zip(animals, input) if i == j]
    return len(diff)/len(animals), diff

sg.theme('SandyBeach')
sg.SetOptions(element_padding=(10,2))

blocks = [[sg.Button(i)] for i in animals]

lay_home = [[sg.Text("You have 7 seconds to hear/view the list of animals given below.\nAfter this, you will be asked to recall the animals you remember from this list.\nOnce you are ready click START!", size=(800,3), font=('Helvetica', 12))], 
[sg.Text("For audio version, please help the person in clicking after the recording.\n", font=('Helvetica', 12))],[sg.Button("START Visual Version",size=(30, 2))], [sg.Button("START Audio Version",size=(30, 2))]]

lay_list = [[sg.Text(size=(50, 1), font=('Helvetica', 25), justification='center', key='time', text_color='red')]]
lay_list.extend(blocks)

lay_grid =[[sg.Text("Recall the animals shown in the previous screen by selecting the animals.\nTry to remember them in order!", size=(800,3), font=('Helvetica', 12))]]
lay_rlist = [[sg.Button(i,key=i) for i in rand_animals[:3]], [sg.Button(
              i,key=i) for i in rand_animals[3:6]], [sg.Button(i,key=i) for i in rand_animals[6:]]]
lay_grid.extend(lay_rlist)
lay_grid.append([sg.Button("SUBMIT",size=(30, 3))])
lay_op = [[sg.Text('', size=(40, 5), font=('Helvetica', 12), text_color='red', justification='left', key='out')],[sg.Button("PLAY AGAIN",size=(30, 3))]]

layout = [[sg.Column(lay_home, key='C1'), sg.Column(lay_list, visible=False, key='C2'), sg.Column(lay_grid, visible=False, key='C3'),sg.Column(lay_op, visible=False, key='C4')]]

window = sg.Window("Serial Position Effect", layout, size = (800,700), default_button_element_size=(12, 2), font = 12, auto_size_buttons=False, margins=(5,5), grab_anywhere=False)

keys_entered = []
while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event=="CLOSE":
        break
    if event == 'START Visual Version':
        current_time = 0
        start_time = int(round(time.time() * 100))
        window['C1'].update(visible=False)
        window['C2'].update(visible=True)
        while int(current_time//100)%60 <=6:
            event, values = window.read(timeout=100)
            if event == sg.WIN_CLOSED or event=="CLOSE":
                break
            current_time = int(round(time.time() * 100)) - start_time
            window['time'].update('{:02d}.{:02d}'.format((current_time // 100) % 60,current_time % 100))
        window['C2'].update(visible=False)
        window['C3'].update(visible=True)
    if event == 'START Audio Version':
        playsound('audio.mp3')
        window['C1'].update(visible=False)
        window['C3'].update(visible=True)
    if event == 'SUBMIT':
        window['C4'].update(visible=True)
        rf, pos = recall_freq(animals, keys_entered)
        window['out'].update(f'\nBased on your submission, your recall frequency is {rf:.2f}.\nRecalled Positions are: {",".join(pos)}.')
    if event[:-1] in "".join(i for i in rand_animals):
        keys_entered.append(event[:-1])
    if event =="PLAY AGAIN":
        window['C4'].update(visible=False)
        window['C3'].update(visible=False)
        window['C1'].update(visible=True)
window.close()
