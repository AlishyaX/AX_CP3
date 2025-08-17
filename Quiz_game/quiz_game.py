#Alishya Xavier, Quiz Game
import csv
import random
'''
MORE CHALLENGES:
Allow users to select from different lists of questions
User profiles (Admin users can create new lists of questions, normal users can just select from lists of questions to do)
Give different point amounts based on how quickly they answer (Use import time, time.time() then subtract the end and start time)
Add Comments
'''
print('Welcome to my quiz Game!')
print('I will ask you 10 multiple choice questions and give you wour score at the end.')
print('Let us get started!')
def load_questions(filename):
    questions = []
    letter_to_index = {'A': 1, 'B': 2, 'C': 3, 'D': 4}

    with open(filename, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)  # Skip header
        for row in reader:
            answer_letter = row[5].strip().upper()
            answer = letter_to_index.get(answer_letter)

            question = {
                'text': row[0],
                'choices': row[1:5],
                'answer': answer
            }
            questions.append(question)
    return questions

    
def ask_question(q):
    print('\n' + q['text'])
    for i, option in enumerate(q['choices'], start=1):
        print(f"{i}. {option}")
    
    while True:
        user_input = input('Which option is correct (1-4): ').strip()
        if user_input.isdigit():
            choice = int(user_input)
            if choice in [1, 2, 3, 4]:
                break
        print('That is not an option. Try again...')
    
    return choice == q['answer']


def run_quiz():
    questions = load_questions("Quiz_game/questions.csv")
    selected = random.sample(questions,10)
    score = 0
    for q in selected:
        if ask_question(q):
            print('You got the question correct!')
            score+=1
        else:
            print("That is incorrect.")
    print('\n Your final score is:', score,'/ 10!')

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
