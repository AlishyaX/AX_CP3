# This holds the classes

#all dessert items inherit name 

class DessertItem:
    name: str

    def __init__(self, name = ""):
        self.name = name
    
class Candy(DessertItem):
    price_per_pound: float
    amount: float

    def __init__(self, name = "", price_per_pound = 0.0, amount = 0.0):
        self.name = name
        self.price_per_pound = price_per_pound
        self.amount = amount


class IceCream(DessertItem):
    price_per_scoop: float
    scoops: int

    def __init__(self, name = "", price_per_scoop = 0.0, scoops = 0):
        self.name = name
        self.price_per_scoop = price_per_scoop
        self.scoops = scoops


class Cookie(DessertItem):
    price_per_dozen: float
    amount_of_cookies: int

    def __init__(self, name = "", price_per_dozen = 0.0, amount_of_cookies = 0):
        self.name = name
        self.price_per_dozen = price_per_dozen
        self.amount_of_cookies = amount_of_cookies


class Sundae(IceCream):
    topping_name: str
    topping_price: float

    def __init__(self, name = "", price_per_scoop = 0.0, scoops = 0, topping_name = "", topping_price = 0.0):
        super().__init__(name, price_per_scoop, scoops)
        self.topping_name = topping_name
        self.topping_price = topping_price


class Order:
    def __init__(self):
        self.order = []
    
    def add(self, dessert_item: DessertItem):
        self.order.append(dessert_item)

    def __len__(self) -> int:
        return len(self.order)
