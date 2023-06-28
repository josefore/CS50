text = "alabala balabalala alalala"
substr = "la"
history = []
loc = 0
puta = 0 # variable que cambia a partir de la primer iteracion
while True:
    loc = text.find(substr, loc + puta)
    if loc == - 1:
        break

    history.append(loc)
    if puta == 0:
        puta += 1

print(history)

record = []
rec = 1
for i in range(len(history)):
    if i == len(history) - 1:
        record.append(rec)
        break
    if history[i + 1] - history[i] == len(substr):
        rec = rec + 1
    else:
        record.append(rec)
        rec = 1

print(record)

record.sort(reverse = True)
print(record)