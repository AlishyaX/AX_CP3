# AX Parent and Child Classes Notes


class Animal():
    def __init__(self, age, color):
        self.age = age
        self.color = color

    def move(self):
        pass

    def  __str__(self):
        return f"Age: {self.age}\nColor: {self.color}"
    
    def __eq__(self, other):
        return (self.age == other.age and self.color == other.color)
    
class Dog(Animal):
    def __init__(self, age, color, owner, breed, name):
        super().__init__(age, color)
        self.owner = owner
        self.breed = breed
        self.name = name

    def move(self):
        print(f"{self.name} Runs")

    def __str__(self):
        return f"Age: {self.age}\nColor: {self.color}\nOwner: {self.owner}\nBreed: {self.breed}\nName: {self.name}"
    
    def __eq__(self, other):
        return (self.age == other.age and self.color == other.color and self.owner == other.owner and self.breed == other.breed and self.name == other.name)
bobby = Dog(5, "brown", "Jill", "Bulldog", "Bobby")
birdy = Dog(1, "Black", "Nikkie", "Lab", "Birdy")
alex = Animal(16, "white")
nick = Animal(16, "white")

print(bobby.move())
print(alex)

print(alex == nick)
print(bobby == birdy)
'''

QUESTIONS:
What is a parent/abstract class?
a box with the name of the class at the top, attributes in the middle, and methods at the bottom, and 
the child classes point to it with a clear arrow.
+ is public and - is private.


How do you create a child class?
it is a box with the name of the class at the top, attributes in the middle, and methods at the bottom.
and a clear arrow pointing to the parent class.

How does a child class inherit from the parent class?
a child class inherits from the parent class by using the super() function in its __init__ method.

What are class diagrams?
they allow us to visualize what we put in our classes.

How are class diagrams used to show a parent/child relationship?
they can be used to show a parent/child relationship by having the child class point to the parent class with a clear arrow.

How do you overload operators in a class?
you overload operators in a class by defining special methods like __eq__ for equality, __str__ for string representation, etc.

What are test cases?
check to make sure that as we build our program we don't break the classes we have already written.

Why do we use test cases?
they help us check our code to make sure it does a certain condition.

How do we create test cases?
we create tests in seperate files in the same folder.
you either do test_filename.py or filename_test.py.
we use test_filename.py.
then you use the assert key word to check if the output is what you expect.
then you click on the testing button and configure the tests on that folder.


'''