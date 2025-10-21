# AX Dessert Shop Project

from dessert import *

def main():
    #make an instance of your order
    my_order = Order()
    
    #print out the name of each item and how many items are in the order
    my_order.add(Candy("Candy Corn", 1.5, .25))
    my_order.add(Candy("Gummy Bears", .25, .35))
    my_order.add(Cookie("Chocolate Chip", 6, 3.99))
    my_order.add(IceCream("Pistachio", 2, .79))
    my_order.add(Sundae("Vanilla", 3, .69, "Hot Fudge", 1.29))
    my_order.add(Cookie("Oatmeal Raisin", 2, 3.45))
    
    #displays the outputs
    for items in my_order:
        print(f"{items.name}")

    print(f"Total number of items in order: {len(my_order)}")

main()
