for i in range(int(input())):
    sentence = input()
    print(chr(ord(sentence[0])-32)+sentence[1:]) if ord(sentence[0]) >= 97 else print(sentence)