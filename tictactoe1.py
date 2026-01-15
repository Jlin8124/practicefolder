board1 = [['-', '-', '-'], 
          ['-', '-', '-'], 
          ['-', '-', '-']]

row = 0
col = 0
playerTurn = "X"


for i in range(1,10):
    validMove = False
    while validMove == False:
        row = 0
        col = 0
        while (col < 1 or col > 3):
            col = int(input("What column? "))
            
        while (row < 1 or row > 3):    
            row = int(input("What row? "))
        col -= 1    
        row -= 1

        if board1[row][col] == "-":
            board1[row][col] = playerTurn
            validMove = True
        else:
            print("Invalid spot")
            

    print(board1[0])
    print(board1[1])
    print(board1[2])




if playerTurn == "X":
    playerTurn == "O"

else:
    playerTurn =="X"











