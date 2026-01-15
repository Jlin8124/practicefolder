

multiples = []

for outer in range(1,5):
    multiples.append([])

    for inner in range(1,6):
        print("Outer: ", outer, ", Inner: ", inner, "Outer x inner: ", inner * outer)
        multiples[outer - 1].append(outer * inner)

print(multiples)

for outerList in multiples:
    for innerValue in outerList:
        print(innerValue, " ", end =" ")
    print()


