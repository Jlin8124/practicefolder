#imported List from typing library to create Lists
from typing import List

#created the list of rows 0-8 to represent the sudoku table to verify values later
row_sets = [set() for _ in range(9)]
#created the list of columns 0-8 to represent the sudoku table to verify values later
column_sets = [set() for _ in range(9)]
#created the subgrid sets or shrinking down the 9x9 sudoku table into 9 equal 3 by 3 components
# 0 1 2 // 3 = 0, 3 4 5 // 3 = 1, and 6 7 8 // 3 = 2
subgrid_sets = [[set() for _ in range(3)] for _ in range(3)]
subgrid_sets = [[set() for _ in range(3)] for _ in range(3)]
subgrid_sets = [[set() for _ in range(3)] for _ in range(3)]

# created a test board to verify values later
board = [

    "538923012",
    "532332912",
    "192938124",
    "982392014",
    "928392104",
    "129839214",
    "928310104",
    "918239803",
    "928390103"
]

#created a function named verify_sudokuboard for clarity and set the return to be a true, that it is indeed a sudoku board
def verify_sudokuboard(board: List[List[int]]) -> bool:
    

    #generated a loop for all the rows so we can check for duplicates
    for r in range(9):
        #generated a loop for all the columns so we can check for duplicates
        for c in range(9):
            #setup a variable inside that is equal to board[r][c]
            num = board[r][c]

            #checking if if the num is 0 or blank we just continue to the next value
            if num == 0:
                continue
            #this ties into later where we append the value of num, and then we check using hashing if its in the row_sets[r] we created
            if num in row_sets[r]:
                return False
            #this ties into later where we appened the value of num, and then we use hashing to check if its in column_sets[c] we created
            if num in column_sets[c]:
                return False
            #also ties into later where we append the value of num, to row, column and subgrid sequentially if we see no duplicates
            if num in subgrid_sets[r // 3][c // 3]:
                return False
            #appending num to all 3 sets
            row_sets[r].add(num)
            column_sets[r].add(num)
            subgrid_sets[r // 3][c // 3].add(num)


#printing the board
print(board)

#converting the strings into integers
board = [[int(char) for char in row] for row in board]
print(board[0])

#calling the function to verify
verify_sudokuboard(board)

#Time Complexity: For the sudoku board its O(1), for a board of NxN elements its O(n^2)
#Space Complexity: Same as the above