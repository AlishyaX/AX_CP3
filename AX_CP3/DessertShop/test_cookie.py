# AX Testing Cookie Class

from dessert import Cookie

#Tests the default value
def test_cookie_default_values():
    cookie = Cookie()
    assert cookie.name == ""
    assert cookie.price_per_dozen == 0.0
    assert cookie.cookie_quantity == 0

#Tests the provided values
def test_cookie_provided_values():
    cookie = Cookie("Chocolate Chip", 6, 3.99)
    assert cookie.name == "Chocolate Chip"
    assert cookie.price_per_dozen == 3.99
    assert cookie.cookie_quantity == 6

#Tests the updates values
def test_cookie_updated_values():
    cookie = Cookie("Chocolate Chip", 3.99, 6)
    cookie.name = "Sugar"
    cookie.price_per_dozen = 4.25
    cookie.cookie_quantity = 12
    assert cookie.name == "Sugar"
    assert cookie.price_per_dozen == 4.25
    assert cookie.cookie_quantity == 12
