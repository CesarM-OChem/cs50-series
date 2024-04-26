text = input("Text: ")

letters = 0
words = 0
sentences = 0
for c in text:
    if c.isalpha():
        letters += 1
    elif c == '.' or c == '!' or c == '?':
        sentences += 1
    elif c == ' ':
        words += 1

words += 1

l = letters / words * 100
s = sentences / words * 100

index = 0.0588 * l - 0.296 * s - 15.8
index = round(index)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade", index)