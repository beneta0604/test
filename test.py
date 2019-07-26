

amount = []
symbols = []
mustbeSafedSymbols = ['3', '7', 'K', 'k']
lol
#сахраняет нужные введённые символы
symbol = input("введите любой символ")
while symbol != '0':
    if symbol == '0':
        break
    elif symbol == mustbeSafedSymbols[0] or symbol == mustbeSafedSymbols[1] or symbol == mustbeSafedSymbols[2] or symbol == mustbeSafedSymbols[3]:
        symbols.append(symbol)
    symbol = input("введите любой символ")

#подсчитывает символы
for index in mustbeSafedSymbols:
    amount.append(symbols.count(index))
amount[2]=amount[2]+amount[3]
amount.pop(3)

#ресует гистограмму
for index in range(len(amount)):
    counter=0
    if mustbeSafedSymbols[index]=='K':
        print("K,   k", end='')
    else:
        print(mustbeSafedSymbols[index],"  ",amount[index], end='')
    if amount[index]>9:
        print("   ",end='')
    else:
        print("    ",end='')
    while counter!=amount[index]:
        print('*', end='')
        counter+=1
    print('\n')
