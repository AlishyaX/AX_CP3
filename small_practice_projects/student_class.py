# AX Student Class Project

'''
INSTRUCTIONS:
Write a program that uses a class to abstract a student. 
Students need to have a student id, name, and grade. 
The student class should have an __init__ method to initialize the values.
 Have the id default to 000, name to John Doe and grade to 100. 
 Make a getter function that will display the student's grade. 
 Make a setter function that will change the student's grade. 
 Create at least 5 student objects. 
 Print each object (note that means you will need a __str__ method), 
 change the grades of at least 3 students and then use the getter method to display the new grades. 

OUTPUT EXAMPLE: 



'''

class Student:
    """Student class with student id, name, and grade"""
    student_id: str
    name: str
    grade: float

    def __init__(self, student_id = "000", name = "John Doe", grade = 100.0):
        """Sets all values"""
        self.student_id = student_id
        self.name = name
        self.grade = grade

    def display_grade(self) -> float:
        """Getter method to display the student's grade"""
        return self.grade
    
    def change
