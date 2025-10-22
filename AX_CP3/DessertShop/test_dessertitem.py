# AX Testing Dessert Item Class

from dessert import DessertItem

def test_default_values():
    item = DessertItem()
    assert item.name == ""

def test_provided_values():
    item = DessertItem("Brownie")
    assert item.name == "Brownie"

def test_updated_values():
    item = DessertItem("Brownie")
    item.name = "Cheesecake"
    assert item.name == "Cheesecake"
