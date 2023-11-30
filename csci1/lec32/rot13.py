def rot13_char(c):
    chars =           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    encrypted_chars = "NOPQRSTUVWXYZABCDEFGHIJKLM"

    # find the index of c in chars
    i = 0
    indexOfChar = -1
    while i < len(chars):
        if chars[i] == c:
            indexOfChar = i
        i = i + 1

    # go to that same index in encrypted_chars
    return encrypted_chars[indexOfChar]

def rot13_string(text):
    encrypted_string = ""

    # go through every char in text and encrypt it
    for c in text:
        encrypted_char = rot13_char(c)
        encrypted_string = encrypted_string + encrypted_char

    return encrypted_string

text = input("Enter a string to encrypt (all caps): ")
print(rot13_string(text))
