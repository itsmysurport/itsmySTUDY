import random

dictA = {}

while True:
    word = input('Input Word : ')
    if word=='0':
        break
    means = input("What's means?")
    dictA[word] = means

while True:
    dictB = dictA
    while len(dictB):
        choice = random.choice(list(dictB.keys()))
        answer = input('What means %s? : ' % choice)
        if dictB.get(choice) == answer:
            print('TRUE!')
            del dictB[choice]
        else:
            print('False!')
