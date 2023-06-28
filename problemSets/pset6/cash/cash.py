from cs50 import get_float


i = 0.0
while i < 0.01:
    i = get_float("Change owed: ")

j = int(round(i * 100))
d = int(j / 25)
c = int(j % 25)
b = int(c % 10)
a = int(b % 5)
f = int(d + (c / 10) + (b / 5) + a)
print(f)

