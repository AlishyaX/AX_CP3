# AX testing icecream class

from dessert import IceCream

#Tests the default value
def test_ice_cream_default_values():
    ice_cream = IceCream()
    assert ice_cream.name == ""
    assert ice_cream.price_per_scoop == 0.0
    assert ice_cream.scoop_count == 0

#Tests the provided values
def test_ice_cream_provided_values():
    ice_cream = IceCream("Pistachio", 2, .79)
    assert ice_cream.name == "Pistachio"
    assert ice_cream.scoop_count == 2
    assert ice_cream.price_per_scoop == .79

#Tests the updates values
def test_ice_cream_updated_values():
    ice_cream = IceCream("Pistachio", 2, .79)
    ice_cream.name = "Strawberry"
    ice_cream.price_per_scoop = 2.00
    ice_cream.scoop_count = 3
    assert ice_cream.name == "Strawberry"
    assert ice_cream.price_per_scoop == 2.00
    assert ice_cream.scoop_count == 3