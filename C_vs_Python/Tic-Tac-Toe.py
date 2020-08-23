# Progran Tic-Tac-Toe

The_Board = {'Top-L': ' ', 'Top-M': ' ', 'Top-R': ' ',
             'Mid-L': ' ', 'Mid-M': ' ', 'Mid-R': ' ',
             'Low-L': ' ', 'Low-M': ' ', 'Low-R': ' '}
def Print_Board(board):
    print(board['Top-L'] + '|' + board['Top-M'] + '|' + board['Top-R'])
    print('-+-+-')
    print(board['Mid-L'] + '|' + board['Mid-M'] + '|' + board['Mid-R'])
    print('-+-+-')
    print(board['Low-L'] + '|' + board['Low-M'] + '|' + board['Low-R'])

Turn = 'X'
for i in range(9):
    Print_Board(The_Board)
    print('Turn to ' + Turn + '. Move on which space?')
    Move      = input()
    The_Board[Move] = Turn
    if Turn == 'X':
        Turn = 'O'
    else:
        Turn = 'X'
Print_Board(The_Board)
