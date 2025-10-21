# AX Dessert Shop Project

from dessert import *

def main():
    #make an instance of your order
    my_order = Order()
    #add to your order "Gummy bears" ..., "Candy Corn" ..., "Chocolate Chip" ..., "Mint Chocolate Chip" ..., "Cookies and Cream" ..., "Vanilla", ..., 
    #print out the name of each item and how many items are in the order
    my_order.add(Candy("Gummy Bears", 0.34, 1.25))
    my_order.add(Candy("Candy Corn", 2.45, 0.36))
    my_order.add(Cookie("Chocolate Chip", 6, 2.17))
    my_order.add(IceCream("Mint Chocolate Chip", 2, 1.66))
    my_order.add(IceCream("Cookies and Cream", 1, 1.52))
    my_order.add(Sundae("Vanilla", 2, 1.00, "Hot Fudge", 0.33))

    for items in my_order:
        print(f"Dessert Item: {items.name}")

# create a pytest 
# Test the DessertItem, Candy, Cookie, IceCream, and Sundae classes

#Test each one on a seperate file to see if:
# 1. A blank creation of the class will have your default values
# 2. A value can be correctly set for each of the classes
# 3. A values in a created class can be updated