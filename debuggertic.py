board1 = [['X', 'O', 'X'], 
          ['-', '-', '-'], 
          ['-', '-', '-']]

#how do i get the length of how many columns there are or rows 

print(board1[0])
print(board1[1])
print(board1[2])

if board1[0][0] and board1[0][1] and board1 [0][2] == "-":
        print("game is finished")

countX = 0
countO = 0
#mistake was putting these variables in local, so when the the iteration finished, the variables reset back to 0
# because i put it in the loop or in the iteration but outside globally the count keeps adding up

for s in range(1, (len(board1[0]) + 1)):
    
    print (s)

    if board1[0][s-1] == "O":
        countO += 1
        print("This is countO:", countO)
    elif board1[0][s-1] == "X":
        countX += 1
        print("This is countx:",countX)

    if board1[s-1][0] == "X" and board1[s-1][1] == "X" and board1[s-1][2] == "X":
        print("game is over")
    
if countO == 3:
    print("game is over! O has won")  

elif countX == 3:
    print("game is over X has won!")
            

