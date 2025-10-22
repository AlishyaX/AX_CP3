# AX testing candy class

from dessert import Candy

#Tests the default value
def test_default_values():
    candy = Candy()
    assert candy.name == ""
    assert candy.candy_weight == 0.0
    assert candy.price_per_pound == 0.0

#Tests the provided values
def test_provided_values():
    candy = Candy("Gummy Bears", 0.5, 1.25)
    assert candy.name == "Gummy Bears"
    assert candy.candy_weight == 0.5
    assert candy.price_per_pound == 1.25

#Tests the updates values
def test_updated_values():
    candy = Candy("Gummy Bears", 0.5, 1.25)
    candy.name = "lolipops"
    candy.candy_weight = 0.75
    candy.price_per_pound = 1.50
    assert candy.name == "lolipops"
    assert candy.candy_weight == 0.75
    assert candy.price_per_pound == 1.50
