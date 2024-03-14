s = input()
special_letter = ["!", "@", "#", "$", "%", "^", "&", "*", "?", "_", "~"]
invalid_letter = [".", "\\", "/", " ", ","]

num_excess = len(s) - 8
num_upper = 0
num_number = 0
num_symbol = 0
special1 = 0
special2 = 0
special3 = 0
if len(s) < 8: 
    print("KhongHopLe")
    exit(0)
for letter in s:
    if letter in special_letter:
        num_symbol += 1
        special1 = 1
    if letter.isupper():
        num_upper += 1
        special2 = 1
    if letter.isnumeric():
        num_number += 1
        special3 = 1
    if letter in invalid_letter:
        print("KhongHopLe")
        exit(0)

if special1 + special2 + special3 == 2:
    bonus_combo = 15
elif special1 + special2 + special3 == 3:
    bonus_combo = 25
else:
    bonus_combo = 0

if num_upper == 0 and num_number == 0 and num_symbol == 0:
    bonus_flatlower = -15
else:
    bonus_flatlower = 0

if num_number == len(s):
    bonus_flatnumber = -35
else:
    bonus_flatnumber = 0

score = 40 + 3 * num_excess + 4 * num_upper + 5 * num_number + 5 * num_symbol + bonus_combo + bonus_flatlower + bonus_flatnumber

if score < 50:
    print("Yeu")
elif score < 75:
    print("Vua")
elif score < 100:
    print("Manh")
else:
    print("RatManh")