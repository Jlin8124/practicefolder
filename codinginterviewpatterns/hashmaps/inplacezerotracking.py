from typing import List

def zero_striping(matrix: List[List[int]]) -> None:
    
    #what it checks okay do we have an empty list like matrix = []
    #2nd check is okay do we have [ [], [], [] ] do we have rows but are those rows empty
    if not matrix or not matrix[0]:
        return
    
    #set variables for the number of columns and rows

    n = len(matrix)
    m = len(matrix[0])

    #check if first row and colum initialls contains a zero

    first_row_has_zero = False
    for c in range(m):
        if matrix[0][c] == 0:
            first_row_has_zero = True
            break
    #check if fist column has any 0's 
    first_col_has_zero = False
    for r in range(n):
        if matrix[r][0] == 0:
            first_col_has_zero = True
            break
    #now check the sub matrix from 1 to n, which is the rows, and 1 to m which is the columns. if any of them is 0 depending on the r and c.
    # we set the beginning c and beginning r to 0
    for r in range(1, n):
        for c in range (1, m):
            if matrix[r][c] == 0:
                matrix[0][c] = 0
                matrix[r][0] = 0

    #this is the magic that sets everything to zero here
    for r in range(1, m):
        for c in range(1, m):
            if matrix[0][c] == 0 or matrix[r][0] == 0:
                matrix[r][c] = 0

    #now if the first row had zero initially now we can set all elements in first row to zero 

    if first_row_has_zero:
        for c in range(m):
            matrix[0][c] = 0

    if first_col_has_zero:
        for r in range(n):
            matrix[r][0] = 0
    
testtable = [
    [1, 0, 3, 0, 0],
    [2, 0, 3, 2, 1],
    [2, 3, 4, 2, 1],
    [3, 3, 2, 1, 5],
    [1, 2, 2, 3, 0]
]


for r in testtable:
    print(r, "\n")

zero_striping(testtable)

print("New table")
for r in testtable:
    print(r, "\n")



#time complexity so we have to iterate through the first row and column. Which is O(m) + O(n) Then we have to iterate through the rest of the elements potentially. to get O(m * n)
#space complexity is what