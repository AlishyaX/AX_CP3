# This holds the classes

#all dessert items inherit name 

#Parent class
class DessertItem:
    """ Holds all of the names of the desserts"""
    name: str

    def __init__(self, name = ""):
        self.name = name
    
#Child class
class Candy(DessertItem):
    """Holds the candies weight and price per pound"""
    candy_weight: float
    price_per_pound: float

    def __init__(self, name="", candy_weight=0.0, price_per_pound=0.0):
        super().__init__(name)
        self.candy_weight = candy_weight
        self.price_per_pound = price_per_pound



#Child class
class Cookie(DessertItem):
    """ Holds the amount of cookies and the price per dozen"""
    cookie_quantity: int
    price_per_dozen: float

    def __init__(self, name="", cookie_quantity=0, price_per_dozen=0.0):
        super().__init__(name)
        self.cookie_quantity = cookie_quantity
        self.price_per_dozen = price_per_dozen


#Child class
class IceCream(DessertItem):
    """ Holds the amount of scoops and the price per scoop"""
    scoop_count: int
    price_per_scoop: float

    def __init__(self, name="", scoop_count=0, price_per_scoop=0.0):
        super().__init__(name)
        self.scoop_count = scoop_count
        self.price_per_scoop = price_per_scoop


#Granchild class frm Icecream
class Sundae(IceCream):
    """ Holds the name, scoop count, and price per scoop from the Icecream class and initializes topping name and price """
    topping_name: str
    topping_price: float

    def __init__(self, name="", scoop_count=0, price_per_scoop=0.0, topping_name="", topping_price=0.0):
        super().__init__(name, scoop_count, price_per_scoop)
        self.topping_name = topping_name
        self.topping_price = topping_price


class Order:
    """ Class that has a list of all of the dessert items using methods of add and __len__"""
    def __init__(self):
        self.order = []
    
    def add(self, dessert_item: DessertItem):
        self.order.append(dessert_item)

    def __len__(self) -> int:
        return len(self.order)
    
    #So that I can use the for loop to display the desserts    
    def __iter__(self):
        return iter(self.order)
