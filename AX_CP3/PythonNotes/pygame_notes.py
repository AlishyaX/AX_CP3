#  AX Pygame Notes

'''
QUESTIONS:
How do you set up pygame?
- pip install pygame-ce

What is the purpose of the "While running" loop?

How do you create a screen in pygame?
-shown below

How are objects placed on the screen in pygame?

What events can I listen for in pygame? What do those events do?

How can I detect collision with pygame?

How do you add sounds in pygame?
 
'''

import pygame

pygame.init()
#Creates a screen
screen = pygame.display.set_mode((1200, 720))
pygame.display.set_caption("Pygame Tutorial")
pos_x = 100
pos_y = 200

ufo = pygame.image.load('pythonNotes\ufo-flying.png')
ufo_rect = ufo.get_rect(topleft = (512, 512))
while True:
    #Backround color
    screen.fill((128,0,128))

    pygame.draw.rect(screen, (250, 0, 0), (pos_x, pos_y, 100, 100))
    pygame.draw.circle(screen, (0,0,0), (500,500), 50)

    screen.blit(ufo, ufo_rect)
    #As long as the game is running follow these instructions
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
        
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT]:
            pos_x -= 5
        elif keys[pygame.K_RIGHT]:
            pos_x += 5
        elif keys[pygame.K_UP]:
            pos_y += 5
        elif keys[pygame.K_DOWN]:
            pos_y -= 5

    pygame.display.flip()