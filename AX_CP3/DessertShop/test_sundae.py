# AX testing sundae class

from dessert import Sundae

#Tests the default value
def test_default_values():
    sundae = Sundae()
    assert sundae.name == ""
    assert sundae.scoop_count == 0
    assert sundae.price_per_scoop == 0.0
    assert sundae.topping_name == ""
    assert sundae.topping_price == 0.0

#Tests the provided values
def test_provided_values():
    sundae = Sundae("Vanilla", 3, 1.50, "Hot Fudge", 0.75)
    assert sundae.name == "Vanilla"
    assert sundae.scoop_count == 3
    assert sundae.price_per_scoop == 1.50
    assert sundae.topping_name == "Hot Fudge"
    assert sundae.topping_price == 0.75

#Tests the updates values
def test_updated_values():
    sundae = Sundae("Vanilla", 3, 1.50, "Hot Fudge", 0.75)
    sundae.name = "Chocolate"
    sundae.scoop_count = 2
    sundae.price_per_scoop = 1.75
    sundae.topping_name = "Caramel"
    sundae.topping_price = 0.80
    assert sundae.name == "Chocolate"
    assert sundae.scoop_count == 2
    assert sundae.price_per_scoop == 1.75
    assert sundae.topping_name == "Caramel"
    assert sundae.topping_price == 0.80
