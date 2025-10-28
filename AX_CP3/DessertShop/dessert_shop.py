# AX Dessert Shop Project

import tabulate

from dessert import *

data = [["Bruce Wayne", "Batman", 3852767384], ["Oliver Queen", "Green Arrow", 8586748573], ["Clark Kent", "Reporter", 654], ["Barry Allen", "CSI", 1], ["John Smith", "Unemployed", 32]]

print(tabulate(data, headers=["Name", "job", "number"]))
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
