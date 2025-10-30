# AX Dessert Shop Project

#This helps us later to make the reciept
from tabulate import tabulate
from dessert import *


class DessertShop():
    """Holds all of the info for the main to use to get what the user wants"""
    def user_prompt_candy(self):
        #Uses while loop and try and except to get users input correctly(Same with the other user_prompts)
        name = input("Enter the name of the candy: ")
        while True:
            try:
                weight = float(input("Enter the weight (lbs): "))
                if weight < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Weight must be a non-negative number.")
        while True:
            try:
                price_per_pound = float(input("Enter the price per pound: "))
                if price_per_pound < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Price must be a non-negative number.")
        #Returns the details to be used in the reciept(Same with the other user_prompts)
        return Candy(name, weight, price_per_pound)
    
    def user_prompt_cookie(self):
        name = input("Enter the name of the cookie: ")
        while True:
            try:
                quantity = int(input("Enter the number of dozens of cookies: "))
                if quantity < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Quantity must be a non-negative integer.")
        while True:
            try:
                price_per_dozen = float(input("Enter the price per dozen: "))
                if price_per_dozen < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Price must be a non-negative number.")
        return Cookie(name, quantity, price_per_dozen)
    
    def user_prompt_icecream(self):
        name = input("Enter the name of the ice cream: ")
        while True:
            try:
                scoop_count = int(input("Enter the number of scoops: "))
                if scoop_count < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Scoop count must be a non-negative integer.")
        while True:
            try:
                price_per_scoop = float(input("Enter the price per scoop: "))
                if price_per_scoop < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Price must be a non-negative number.")
        return IceCream(name, scoop_count, price_per_scoop)
    
    def user_prompt_sundae(self):
        name = input("Enter the name of the sundae: ")
        while True:
            try:
                scoop_count = int(input("Enter the number of scoops: "))
                if scoop_count < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Scoop count must be a non-negative integer.")
        while True:
            try:
                price_per_scoop = float(input("Enter the price per scoop: "))
                if price_per_scoop < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Price must be a non-negative number.")
        topping_name = input("Enter the name of the topping: ")
        while True:
            try:
                topping_price = float(input("Enter the topping price: "))
                if topping_price < 0:
                    raise ValueError
                break
            except ValueError:
                print("Invalid input. Topping price must be a non-negative number.")
        return Sundae(name, scoop_count, price_per_scoop, topping_name, topping_price)


def main():
    shop = DessertShop()
    order = Order()
    '''
    order.add(Candy('Candy Corn', 1.5, 0.25))
    order.add(Candy('Gummy Bears', 0.25, 0.35))
    order.add(Cookie('Chocolate Chip', 6, 3.99))
    order.add(IceCream('Pistachio', 2, 0.79))
    order.add(Sundae('Vanilla', 3, 0.69, 'Hot Fudge', 1.29))
    order.add(Cookie('Oatmeal Raisin', 2, 3.45))
    '''
    done: bool = False
    # build the prompt string once
    prompt = '\n'.join([ '\n',
        '1: Candy',
        '2: Cookie',
        '3: Ice Cream',
        '4: Sundae',
        '\nWhat would you like to add to the order? (1-4, Enter for done): '])
    while not done:
        choice = input(prompt)
        match choice:
            case '':
                done = True
            case '1':
                item = shop.user_prompt_candy()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '2':
                item = shop.user_prompt_cookie()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '3':
                item = shop.user_prompt_icecream()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case '4':
                item = shop.user_prompt_sundae()
                order.add(item)
                print(f'{item.name} has been added to your order.')
            case _:
                print('Invalid response: Please enter a choice from the menu (1-4) or Enter')
                print()
    #The list for the tabulate
    receipt_data = []

    #To later print out the items, cost, and tax
    for item in order:
        name = item.name
        cost = item.calculate_cost()
        tax = item.calculate_tax()
        #formatting
        receipt_data.append([name, f"${cost:.2f}", f"${tax:.2f}"])

    receipt_data.append(["----------", "----------", "----------"])

    # Add subtotal and tax for total
    subtotal = order.order_cost()
    total_tax = order.order_tax()
    order_total = subtotal + total_tax
    item_count = len(order)

    # The way that the reciept is printed
    receipt_data.append(["Order Subtotals", f"${subtotal:.2f}", f"${total_tax:.2f}"])
    receipt_data.append(["Order Total", "", f"${order_total:.2f}"])
    receipt_data.append(["Total Items in the order:", "", item_count])

    # Print the receipt
    print(tabulate(receipt_data, headers=["Name", "Cost", "Tax"], tablefmt="fsql"))
main()
