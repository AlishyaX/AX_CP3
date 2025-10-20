#Alishya Xavier, Quiz Game
import csv
import random
import time

#Info for admin
admin_username = "admin"
admin_password = "adminpass"

# User Profiles
def login():
    print('---------------------LOGIN----------------------')
    print('Type (exit) to leave')
    username = input("Username: ")
    if username == 'exit':
        print('Thank you for playing!')
        exit()
    password = input("Password: ")

    if username == admin_username and password == admin_password:
        print("You logged in as admin!")
        return "admin"
    else:
        print(f"Welcome {username}!")
        return "user"
    
#Lets the User create quiz questions
def create_quiz(filename):
    #Lets the user append questions to csv
    with open(filename, 'a', newline='') as file:
        writer = csv.writer(file)

        while True:
            q = input("Enter Question: ")
            a = input("Choice A: ")
            b = input("Choice B: ")
            c = input("Choice C: ")
            d = input("Choice D: ")
            ans = input("Correct Answer(A/B/C/D): ").upper()
            if ans not in ['A', 'B', 'C', 'D']:
                print('Thats not an option try again!')
                continue
            
            #Writes the question into the csv
            writer.writerow([q, a, b, c, d, ans])
            print('You added the question!')

            #Lets the admin add more questions
            if input("Do you want to add another question? y/n\n").lower() != 'y':
                break

#Loads Questions
def load_questions(filename):
    questions = []
    #Translates what the user types into multiple choice
    letter_to_index = {'A': 1, 'B': 2, 'C': 3, 'D': 4}

    #Opens the CSV
    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)  # Skip header
        for row in reader:
            #finds the answer row
            answer_letter = row[5].strip().upper()
            #gets the the answer from the dictionary
            answer = letter_to_index.get(answer_letter)

            #Identifys which rows are which part of the question
            question = {
                'text': row[0],
                'choices': row[1:5],
                'answer': answer
            }
            questions.append(question)
    return questions

#Asks the question to the user
def ask_question(q):
    #asks the question
    print('\n' + q['text'])
    #This prints the row of choices in a column
    for i, option in enumerate(q['choices'], start=1):
        print(f"{i}. {option}")
    
    #Calculates the time from when the question starts
    start_time = time.time()
    
    while True:
        #Gathers the input from the user
        user_input = input('Which option is correct (1-4): ').strip()
        if user_input in ['1', '2', '3', '4']:
                break
        else:
            print('That is not an option. Try again...')
    
    #Calculates the time until question is answered
    end_time = time.time()
    #Total amount of time per question
    duration = end_time - start_time
    
    #Returns the users answer and how long they took to answer the question
    correct_answ = int(user_input) == q['answer']
    return correct_answ, duration

#Runs the quiz
def run_quiz(filename):
    questions = load_questions(filename)
    #randomly picks questions
    selected = random.sample(questions,10)
    #starting score
    score = 0
    #tells the user when they get the question right or wrong and gives points depending on time
    for q in selected:
        correct_answ, duration = ask_question(q)
        if correct_answ:
            if duration < 5:
                score +=3
            elif duration < 10:
                score+=2
            else:
                score+=1
            print('You got the question correct!')
        else:
            print("That is incorrect.")
    print('\n Your final score is:', score)

#Runs the code and keeps going unless they want to end
def start():
    while True:
        filename = "Quiz_game/questions.csv"
        role = login()
        #Admin can make questions
        if role == "admin":
            print('Here you can make more question for the users to play!')
            create_quiz(filename)
            print('Logging out..\n')
        #User can just play the quiz
        elif role == "user":
            print('\n\n\n\nWelcome to my quiz Game!')
            print('I will ask you 10 multiple choice questions and give you your score at the end.')
            print('Let us get started!')
            run_quiz(filename)
            play_again = input('Do you want to play again? y/n\n').lower()
            if play_again == 'n':
                print('Thank you for playing!')
                continue
            elif play_again == 'y':
                run_quiz(filename)

#Runs the Program        
start()
                
