from cs50 import get_float


change = get_float("Change: ")

sum = 0
change *= 100
coins = [25, 10, 5, 1]

for coin in coins:
    sum += int(change / coin)
    change = change % coin

print(sum)