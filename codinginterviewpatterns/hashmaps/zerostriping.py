from typing import List

def zero_striping_hash_sets(matrix: List[List[int]]) -> None:
    if not matrix or not matrix[0]:
        return
    m, n = len(matrix), len(matrix[0])
    zero_rows = set()
    zero_cols = set()

    for r in range(m):
        for c in range(n):
            if matrix[r][c] == 0:
                zero_rows.add(r)
                zero_cols.add(c)
    for r in range(m):
        for c in range(n):
            if r in zero_rows or c in zero_cols:
                matrix[r][c] = 0

testtable = [
    [1, 3, 4, 3, 0],
    [2, 0, 3, 2, 1],
    [2, 3, 4, 2, 1],
    [3, 3, 2, 1, 5],
    [1, 2, 2, 3, 4]
]

for r in testtable:
    print(r, "\n")

zero_striping_hash_sets(testtable)

print("New table")
for r in testtable:
    print(r, "\n")


