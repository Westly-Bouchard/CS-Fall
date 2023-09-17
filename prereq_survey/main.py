userNum = -1;

while (int(userNum) <= 0):
    userNum = input()

userNum = int(userNum)
print("Printing all even numbers")
for i in range(0, userNum + 1):
    if i % 2 == 0:
        print(i)


sum = 0
for i in range(0, userNum):
    sum += i

print("Sum of numbers: " + str(sum))