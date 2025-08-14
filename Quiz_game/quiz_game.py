#Alishya Xavier, Quiz Game
import csv
'''
INSTRUCTIONS:
Create a quiz game that asks the user at least 10 questions (randomly selected from a csv that holds at least 50 questions [yes you can use AI to create your questions and answers]).

Let users answer (they should be multiple choice questions but make sure your user knows what to do to select their choice)

Tell the user if they got the question right or wrong

Give the overall score at the end

The program needs to run until the user selects to quit

MORE CHALLENGES:
Allow users to select from different lists of questions
User profiles (Admin users can create new lists of questions, normal users can just select from lists of questions to do)
Give different point amounts based on how quickly they answer (Use import time, time.time() then subtract the end and start time)

KEY REMINDERS:
CSV's use a csvreader
Think carefully about the data types you want to use!
Make clear user instructions for how they answer questions
Don't forget to plan extra debugging time! You can always add more once you have an MVP!

'''
score = 0

def quiz_main():
    print('Welcome to my Quiz Game!!!!')
    print('I will give you 10 questions that you will answer by either inputting A, B, C, or D.')
    print('At the end of this quiz I will give you your score.')
    
