# AX Student Class Project

class Student:
    """Student class with student id, name, and grade"""
    student_id: str
    name: str
    grade: int

    def __init__(self, student_id = "000", name = "John Doe", grade = 100):
        """Sets all values"""
        self.student_id = student_id
        self.name = name
        self.grade = grade

    def display_grade(self) -> int: #Type hinting
        """Getter method to display the student's grade"""
        return self.grade
    
    def change_grade(self, new_grade) -> int: #Type hinting
        """Setter method to change the student's grade"""
        self.grade = new_grade

    def __str__(self):
        "The way that the intitial student info is printed"
        return f"Student ID: {self.student_id}, Name: {self.name}, Grade: {self.grade}"


def main():
    #Create 5 student objects
    students = [
        Student("001", "Alice Smith", 95),
        Student("002", "Bob Johnson", 88),
        Student("003", "Charlie Brown", 92),
        Student("004", "Diana Prince", 85),
        Student() #Default student
    ]

    #This prints the initial student information
    print("Initial student information:")
    #for each object in list of students print each student
    for student in students:
        print(student)

    #Changes the grades of at least 3 students
    students[0].change_grade(98)  # Alice Smith
    students[2].change_grade(94)  # Charlie Brown
    students[4].change_grade(85)  # John Doe

    #This prints the Updated grades
    print("\nUpdated grades:")
    print(f"{students[0].name}'s new grade: {students[0].display_grade()}")
    print(f"{students[2].name}'s new grade: {students[2].display_grade()}")
    print(f"{students[4].name}'s new grade: {students[4].display_grade()}")

main()