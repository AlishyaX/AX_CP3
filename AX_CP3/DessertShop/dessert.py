# This holds the classes

#all dessert items inherit name 

class DessertItem:
    name: str

    def __init__(self, name = ""):
        self.name = name
    
class Candy(DessertItem):
    candy_weight: float
    price_per_pound: float

    def __init__(self, name="", candy_weight=0.0, price_per_pound=0.0):
        super().__init__(name)
        self.candy_weight = candy_weight
        self.price_per_pound = price_per_pound



# Cookie
class Cookie(DessertItem):
    cookie_quantity: int
    price_per_dozen: float

    def __init__(self, name="", cookie_quantity=0, price_per_dozen=0.0):
        super().__init__(name)
        self.cookie_quantity = cookie_quantity
        self.price_per_dozen = price_per_dozen


# IceCream
class IceCream(DessertItem):
    scoop_count: int
    price_per_scoop: float

    def __init__(self, name="", scoop_count=0, price_per_scoop=0.0):
        super().__init__(name)
        self.scoop_count = scoop_count
        self.price_per_scoop = price_per_scoop


# Sundae (inherits from IceCream)
class Sundae(IceCream):
    topping_name: str
    topping_price: float

    def __init__(self, name="", scoop_count=0, price_per_scoop=0.0, topping_name="", topping_price=0.0):
        super().__init__(name, scoop_count, price_per_scoop)
        self.topping_name = topping_name
        self.topping_price = topping_price

class Order:
    def __init__(self):
        self.order = []
    
    def add(self, dessert_item: DessertItem):
        self.order.append(dessert_item)

    def __len__(self) -> int:
        return len(self.order)
    
    def __iter__(self):
        return iter(self.order)
