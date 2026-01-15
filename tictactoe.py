
row0 = ['-', '-', '-']
row1 = ['-', '-', '-']
row2 = ['-', '-', '-']

# board = [row0, row1, row2]

board1 = [['-', '-', '-'], 
          ['-', '-', '-'], 
          ['-', '-', '-']]

print(board1[0])
print(board1[1])
print(board1[2])

column = int(input("What column?\n"))
row = int(input("What Row\n"))

column -= 1
row -= 1

# so we subtract by 1 because first we are prompting a user for 1-3 not 0 because that would be confusing
# however the lists are still indexed or positioned in order from 0

board1[column][row] = "X"
print(board1[column][row])
print(board1[0])
print(board1[1])
print(board1[2])

column = int(input("Player O: What column?\n"))
row = int(input("PlayerO: What Row\n"))
column -= 1
row -= 1

current_player ="x"

while True:

    # for s in len(column[0]):

 # I need to loop this until one player wins, or all 9 board spaces are filled
        column = int(input("Player What column?\n"))
        row = int(input("Player What Row\n"))

        if board1[column][row] == "-":
            if current_player == "0":
                board1[column][row] = "0"
            elif current_player == "X":
                board1[column][row] = "X"
        
        elif board1[column][row] == "0" or "X":
            print("Spot already taken")
            continue
       
        if current_player == "x":
            current_player =="O"

        else:
            current_player == "x" 
              

        if board1[0][0] and board1[0][1] and board1 [0][2] == "X":
            print("game is finished")

#prompt for user input
#update the table
#switch players 
#prompt for user input
#loop until 3 in a row or 9 spaces filled, 
#3 in a row can be on 3 columns, 3 rows, or 2 diagonols














