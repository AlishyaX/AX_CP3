#AX Abstraction Notes

from abc import ABC, abstractmethod

class Animal(ABC):
    def __init__(self, name):
        self.name = name
    
    def __str__(self):
        return f"This animal's name is {self.name}"

    @abstractmethod
    def move(self):
        pass

class Quadruped(Animal):
    def __init__(self, name):
        super().__init__(name)

    def move(self):
        print(f"{self.name} can walk or run")

class Aquatic(Animal):
    def __init__(self, name):
        super().__init__(name)

    def move(self):
        print(f"{self.name} can swim")  

class SeaLion(Aquatic, Quadruped):
    def __init__(self, name):
        super().__init__(name)

    def eats(self):
        print(f"{self.name} eats penguins and krill")

sealion = SeaLion("Greg")
print(sealion)
sealion.move()
sealion.eats()
print(Aquatic.mro())

"""
QUESTIONS:
Why can't you create an object from an abstract class?
Because they are too abstract to represent a real object

How do abstract classes and abstract methods work together?
abstract class must have at least one method

What does abc stand for?
Abstract Base Class

What are decorators? 
they are @ symbols that modify functions or methods
specifically used to give further info to the program about what follows

What is an abstract method?
Inside and abstract class
they are specifcally written to be overwritten by their child classes 
makes it so that any child class must have that method

What is a concrete method?
methods that we normally write in classes that can be used as is or overwritten

What is an abstract class?
a placeholder class that can't be made objects from
exists specifically to be a parent class for other classes
it must have at least one abstract method

How do you make an abstract method?
Example above with @abstractmethod decorator and then defining the method with pass

How can you create a class that inherits from multiple parent classes?
you just use a comma to separate the parent classes in the class definition

Why does the inheritance order matter?
it prioritizes the first parent class when there are methods with the same method so it doesn't reset
the order is important to know which things are going to happen

What does the mro() method do when you call it on a class?
method resolution order
it tells you what version of the method takes precedence

What is Method resolution order?
which classes we inherit from first
"""