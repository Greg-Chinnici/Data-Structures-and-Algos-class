#file IO shit can be done later, this is just for the concept
def Translate(txt):
    done = ""
    for word in txt:
        for letter in word:
            if letter.lower() in ["a","e","i",'o',"u"]:
                done += letter
            elif (letter.isalpha()):
                done += letter + "o" + letter
            else:
                done += letter
    return done
inText = "stubborn"
outText = Translate(inText)
print(outText)

print(outText == "sostotubobboborornon")
'''


'''
totalTxt = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
letter = "a"
sentences = []
s = ""
for letter in totalTxt:
    if letter == ".":
        sentences.append(s)
    else:
        s+= letter
for sentence in sentences:
    print(Translate(sentence))

