import os


# print("This script will delete all saved games\n")
# agree = str()
# while(not(agree.lower() == "y" or agree.lower == "n")):
#     agree = input("Are u sure?:\n")


# if (agree.lower == "y"):
os.system('find . -name "*.txt" -type f -delete')
print("Cached was cleaned")
