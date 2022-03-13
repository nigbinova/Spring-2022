import random

#This program creates a list, prints a random index from the list, and prints all the index values that weren't randomly picked.
print("")

list1 = [2,4,6,8,10]
x = (random.choice(list1))
index = list1.index(x)
print ("The random index from the list is:", index)

print ("")
for i in range(len(list1)):
  if (index != i):
        print(list1[i])
        
print ("")
print (x)
