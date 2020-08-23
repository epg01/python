# This program counts words in a general way.

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
        break
    else:
        Word_Counter.setdefault(Name, 0)
        Word_Counter[Name] += 1;
if (len(Word_Counter)):
    for Word, amount in Word_Counter.items():
        print('Word ' + Word + '     ' + 'Number of occurences = ' + str(amount))
else:
    print('No items were entered')
