prices = [50, 70, 80, 90 , 100]

returns = []

for i in range(1, len(prices)):
    daily = round((prices[i] / prices[i-1]) - 1, 2) * 100 
    round(daily, 3)
    returns.append(daily)
    print(f"{returns[i-1]:.2f}%")

tupleList = ("Strawman",)

print(type(tupleList))

eng2chinese = dict()
print(eng2chinese)
eng2chinese['hello'] = 'nihao'
print(eng2chinese)
eng2chinese.update({'mama': 'mamama'})
print(type(eng2chinese))
print(eng2chinese)