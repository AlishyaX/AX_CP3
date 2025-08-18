#Alishya Xavier, Quiz Game
import csv
import random
import time
'''
MORE CHALLENGES:
3. Allow users to select from different lists of questions
2. User profiles (Admin users can create new lists of questions, normal users can just select from lists of questions to do)
1. Give different point amounts based on how quickly they answer (Use import time, time.time() then subtract the end and start time)
'''
#Intro
print('Welcome to my quiz Game!')
print('I will ask you 10 multiple choice questions and give you your score at the end.')
print('Let us get started!')

#Loads Questions
def load_questions(filename):
    questions = []
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
    
    start_time = time.time()
    
    while True:
        #Gathers the input from the user
        user_input = input('Which option is correct (1-4): ').strip()
        if user_input in ['1', '2', '3', '4']:
                break
        else:
            print('That is not an option. Try again...')
    
    end_time = time.time()
    duration = end_time - start_time
    
    #Returns the users answer and how long they took to answer the question
    correct_answ = int(user_input) == q['answer']
    return correct_answ, duration

#Runs the quiz
def run_quiz():
    questions = load_questions("Quiz_game/questions.csv")
    #randomly picks questions
    selected = random.sample(questions,10)
    #starting score
    score = 0
    #tells the user when they get the question right or wrong
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
while True:
    run_quiz()
    while True:
        play_again = input('Do you want to play again? y/n\n').lower()
        if play_again == 'n':
            print('Thank you for playing!')
            exit()
        elif play_again == 'y':
            break
        else:
            print('That is not an option')
            continue
