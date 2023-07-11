import pygame
import pygame.camera

pygame.camera.init()
pygame.camera.list_cameras() #Camera detected or not
cam = pygame.camera.Camera("/dev/video0",(300,100))
cam.start()
while True:
    img = cam.get_image()
    pygame.image.save(img,"filename.jpg")
