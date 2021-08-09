import PySimpleGUI as sg
import random

animals = ['Tiger', 'Dolphin', 'Camel', 'Elephant',
           'Snake', 'Frog', 'Horse', 'Monkey', 'Panther']

random.shuffle(animals)

def recall_freq(animals, input):
    diff = [str(animals.index(i)+1) for i, j in zip(animals, input) if i == j]
    return len(diff)/len(animals), diff

sg.ChangeLookAndFeel('LightPurple')
sg.SetOptions(element_padding=(5, 5))

rows = [[sg.Text('You have 7 seconds to view the list of animals given below. After this, you will be asked to recall the animals you remember from this list.', size=(40, 3), font=('Helvetica', 14),
                   text_color='black')]]
blocks = [[sg.Button(i)] for i in animals]
rows.extend(blocks)               
win = sg.Window('Animal List', rows, default_button_element_size=(50,2), auto_size_buttons=False,
          grab_anywhere=False)
win.read(timeout=8000)
win.close()

rand_animals = animals.copy()
random.shuffle(rand_animals)

sg.ChangeLookAndFeel('LightTeal')
sg.SetOptions(element_padding=(5,5))

layout = [[sg.Text('Recall the animals shown in the previous screen by clicking the buttons. Try to remember them in order.', size=(40, 2), font=('Helvetica', 14),
                   text_color='black')],
          [sg.Button(i) for i in rand_animals[:3]], [sg.Button(
              i) for i in rand_animals[3:6]], [sg.Button(i) for i in rand_animals[6:]],
          [sg.Button('Submit', size=(40, 2))],
          [sg.Text('', size=(40, 2), font=('Helvetica', 12),
                   text_color='red', key='out')],
          ]

window = sg.Window('SP Blocks', layout,
                   default_button_element_size=(15, 6),
                   auto_size_buttons=False,
                   grab_anywhere=False)

keys_entered = []
while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED:
        break
    elif event in "".join(i for i in rand_animals):
        keys_entered.append(event)
    elif event == 'Submit':
        rf, pos = recall_freq(animals, keys_entered)
        window['out'].update(
            f'Based on your submission, your recall frequency is {rf:.2f}.\nRecalled Positions are: {",".join(pos)}.')

window.close()