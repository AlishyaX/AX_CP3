# AX Dessert Shop Project

from tabulate import tabulate
from dessert import *

class DesserShop():
    def user_prompt_candy():
        pass
    def user_prompt_cookie():
        pass
    def user_prompt_icecream():
        pass
    def user_prompt_sundae():
        pass


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

    for item in order:
        name = item.name
        cost = item.calculate_cost()
        tax = item.calculate_tax()
        #formatting
        receipt_data.append([name, f"${cost:.2f}", f"${tax:.2f}"])

    receipt_data.append(["----------", "----------", "----------"])

    # Add subtotal and tax
    subtotal = order.order_cost()
    total_tax = order.order_tax()
    order_total = subtotal + total_tax
    item_count = len(order)

    # Add summary rows
    receipt_data.append(["Order Subtotals", f"${subtotal:.2f}", f"${total_tax:.2f}"])
    receipt_data.append(["Order Total", "", f"${order_total:.2f}"])
    receipt_data.append(["Total Items in the order:", "", item_count])

    # Print the receipt
    print(tabulate(receipt_data, headers=["Name", "Cost", "Tax"], tablefmt="fsql"))
main()
