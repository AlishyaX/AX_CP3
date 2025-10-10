# AX Class and Objects Notes


class Person:
    """Person class with first and last names as well as age. 
    Method to get full name, increase age by 1"""
    first_name: str
    last_name: str
    age: int
    def __init__(self, _first_name = "John", last_name = "Doe", age = 0):
        """Sets all values"""
        self._first_name = _first_name #underscore makes it private
        self.last_name = last_name
        self.age = age

    def setAge(self): #setter method
        """Increase age by 1"""
        self.age +=1

    # getter method
    def full(self) -> str: #Type hinting a method 
        """Create full name"""
        return self._first_name + " " + self.last_name
    
    def __str__(self):
        return f"name: {self._first_name} {self.last_name}, age: {self.age}"



tia = Person("Tia", "Larose", 28)
alex = Person("Alex", "Larose", 37)
tia.setAge()

print(f" {tia.full()} is {tia.age} years old")
print(f" {alex.full()} is {alex.age} years old")

'''
QUESTIONS:
What is a class?
uses pascal case for class names
a class is an abstraction of an object, a zoomed out version of the thing the class represents
they include attributes (data) and methods (functions)

What is an object?
an instance of a class

How is a class a form of encapsulation? 
encapsulation is where you take everything that is connected together and putting it all together in one convienient location

How is a class an abstraction of an object?
abstraction is when you get another level further from the specific.


How do you access information in an object?
you use the dot operator with the variable name and the attribute or method name

How do you initialize a class?
you use the __init__ method

How do you set a default value 
you make the parameter equal to something in the init method

How do you use type hinting?
double checks that you aren't getting the wrong type of information

How do you set an attribute to be private?
you put an underscore before the attribute name

How do you make a class method?
you define a function inside of a class

Why do we include docstrings/
they are considered best practices inside of classes and explains what the class or method does
multiline comments

What does "self" do as a parameter for class methods?
they go into our object and takes the details of that instance of the class.
self makes it only do it for a current instance of the class

What are getter and setter methods?
setters change the values while getteres return the values

What are magic methods?
a method that has two __ before and at the end.
Built in methods that we can use to do things

Where are class objects saved? (heap or stack?)
Class objects are saved in the heap memory

'''