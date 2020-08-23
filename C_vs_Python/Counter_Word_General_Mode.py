# This program counts words in a general way.

import pprint

def Print_Welcome():
    print('The progams was initialized')
    print('This program counts the ocurrences of each word')
    print('Start writting')
    print('Enter enter to exit')

Word_Counter  = {} # A directory was created to counter the occurrences of each word.

Print_Welcome()

while True:
    Name = input()
    if Name == '':
        if (len(Word_Counter)):
            print(pprint.pformat(Word_Counter))
        else:
            print('No items were entered')
        break
    else:
        Word_Counter.setdefault(Name, 0)
        Word_Counter[Name] += 1;
print('Finished program')
