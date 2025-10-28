# AX Dessert classes
from abc import ABC, abstractmethod
#all dessert items inherit name 

#Parent class
class DessertItem(ABC):
    """ Holds all of the names of the desserts"""
    name: str

    def __init__(self, name = "", tax_percent = 7.25):
        self.name = name
        self.tax_percent = tax_percent

    @abstractmethod
    def calculate_cost() -> float:
        pass

    def calculate_tax(price, tax_rate) -> float:
        #calculates the and returns the actual tax for the item, rounded to 2 decimal places
        tax = price*(tax_rate/100)
        return round(tax, 2)


    
#Child class
class Candy(DessertItem):
    """Holds the candies weight and price per pound"""
    candy_weight: float
    price_per_pound: float

    def __init__(self, name="", candy_weight=0.0, price_per_pound=0.0):
        super().__init__(name)
        self.candy_weight = candy_weight
        self.price_per_pound = price_per_pound

    def calculate_cost(price_per_pound, candy_weight):
        return price_per_pound*candy_weight



#Child class
class Cookie(DessertItem):
    """ Holds the amount of cookies and the price per dozen"""
    dozen: int
    price_per_dozen: float

    def __init__(self, name="", dozen=0, price_per_dozen=0.0):
        super().__init__(name)
        self.dozen = dozen
        self.price_per_dozen = price_per_dozen

    def calculate_cost(price_per_dozen, dozen):
        return price_per_dozen*dozen

#Child class
class IceCream(DessertItem):
    """ Holds the amount of scoops and the price per scoop"""
    scoop_count: int
    price_per_scoop: float

    def __init__(self, name="", scoop_count=0, price_per_scoop=0.0):
        super().__init__(name)
        self.scoop_count = scoop_count
        self.price_per_scoop = price_per_scoop

    def calculate_cost(price_per_scoop, scoop_count):
        return price_per_scoop*scoop_count


#Granchild class frm Icecream
class Sundae(IceCream):
    """ Holds the name, scoop count, and price per scoop from the Icecream class and initializes topping name and price """
    topping_name: str
    topping_price: float

    def __init__(self, name="", scoop_count=0, price_per_scoop=0.0, topping_name="", topping_price=0.0):
        super().__init__(name, scoop_count, price_per_scoop)
        self.topping_name = topping_name
        self.topping_price = topping_price

    def calculate_cost(scoop_count, price_per_scoop, topping_price):
        return (scoop_count*price_per_scoop)+topping_price


class Order:
    """ Class that has a list of all of the dessert items using methods of add and __len__"""
    def __init__(self, calculate_tax):
        self.order = []
        self.calculate_tax = calculate_tax

    def add(self, dessert_item: DessertItem):
        self.order.append(dessert_item)

    def order_cost():
        #that calculates and returns the total cost for all items in the order
        a = Candy()
        b = Cookie()
        c = IceCream()
        d = Sundae()
        print("The cost for all of the items in the order: ", a+b+c+d)

    def order_tax(self):
        #calculates and returns the total tax for all items in the order
        #Working on this
        tax = self.calculate_tax.calculate_tax()

    def __len__(self) -> int:
        return len(self.order)
    
    #So that I can use the for loop to display the desserts    
    def __iter__(self):
        return iter(self.order)
