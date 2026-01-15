#lets try to generate a code or the whatever I learned today to find and print out prime numbers up to a specific amount

def generate_pascals_triangle(num_rows):

    triangle = []

    for i in range(num_rows):
        row = [1] * (1+i)


        for j in range(1, i):
            row[j] = triangle[i-1][j-1] + triangle[i-1][j]


testarray = [[10],[10]]
testarray =[[10], [10]]
testarray = [[10], [10]]
testarray = [[10], [10]]
testarray = [[10], [10]]



testarray[0][0] = 4

print(testarray[0][0])




        


        

