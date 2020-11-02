#############
#Main.py    #
#E.Carree   #
#07/06/2019 #
# S2P-B IPI #
#############

#differentes couleurs disponibles
#1 vert
#2 jaune
#3 bleu
#4 rose
#5 cyan
#6 blanc
#7 rouge
#... en boucle

import sys
import os
import time
import select
import termios
import random

#mes modules
import Background 
import Animat
import Robot2
import Shoot
import Animation

#interaction clavier
old_settings = termios.tcgetattr(sys.stdin)

#donnee du jeu
animat=None
background = None 
timeStep=None
robot2= None
shot = None
joker = None
animation = None
name = None
finalTime = None
temps= int(time.time())


def init():
	global animat, background, timeStep, robot2,shot,joker,animation
	
	# creation des elements du jeu
	animat = Animat.create()
	background,joker= Background.create("Background.txt")
	robot2=Robot2.create()
	shot=[]
	tirjoueur= Shoot.create(x=55,y=4,color=5,decalage=0,etat="tir",tir="--")
	shot.append(tirjoueur)
	roquetterobot=Shoot.create(x=10,y=14,color=2,decalage=4,etat="roquette",tir="-->")
	shot.append(roquetterobot)
	missilerobot=Shoot.create(x=10,y=12,color=2,decalage=2,etat="missile",tir="--")
	shot.append(missilerobot)
	missile2robot=Shoot.create(x=10,y=16,color=2,decalage=6,etat="missile",tir="--")
	shot.append(missile2robot)
	animation=[]
	win =Animation.create(filename="win.txt")
	animation.append(win)
	lose =Animation.create(filename="lose.txt")
	animation.append(lose)
	start = Animation.create(filename="start.txt")
	animation.append(start)

	
	#effacer la console
	sys.stdout.write("\033[1;1H")
	sys.stdout.write("\033[2J")
	

def move():
	#deplacement des elements du jeu
	global animat,robot2,shot,background,joker
	Robot2.move(robot2,animat,background)
	Shoot.move(robot2,background,animat,shot[0],-1)
	Shoot.move(robot2,background,animat,shot[1],1)
	Shoot.move(robot2,background,animat,shot[2],1)
	Shoot.move(robot2,background,animat,shot[3],1)
	Background.move(joker,animat,background)


def show():
	#affichage des differents elements du jeu
	global background, animat,robot2,joker,shot,name
	Background.show(background,joker)
	chrono()
	Shoot.show(shot[1])
	Shoot.show(shot[2])
	Shoot.show(shot[3])
	Robot2.show(robot2)
	Shoot.show(shot[0])
	Animat.show(animat,name)

	#restoration couleur 
	sys.stdout.write("\033[37m")
	sys.stdout.write("\033[40m")

	#deplacement curseur
	sys.stdout.write("\033[1;1H\n")

def interact():
	#gestion des evenement clavier
	global animat, background,timeStep,robot2,shot
	
	#si une touche est appuyee
	if isData():
		c = sys.stdin.read(1)
		if c == '\x1b':         # x1b is ESC
			quitGame()
		elif c== "z":#deplacement haut
			Animat.moveH(animat,robot2,background)
		elif c== "q":#deplacement gauche
			Animat.moveL(animat,robot2,background)
		elif c== "s":#deplacement bas
			Animat.moveD(animat,robot2,background)
		elif c== "d":#deplacement droite
			Animat.moveR(animat,robot2,background)
		elif c=='6' or c=='0':#touche triche pour joueur
			cheat()
	
def isData():
	#recuperation evenement clavier
	return select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], [])

def chrono (): #creation chronometre 
	global temps
	tempsactuel= int(time.time())
	c = tempsactuel-temps
	#on se place a la position du tir dans le terminal
	txt="\033["+str(23)+";"+str(65)+"H"
	sys.stdout.write(txt)
	sys.stdout.write(str(c)+" secondes")
	return c
	
def cheat(): #fonction de triche pour le joueur
	global animat,robot2
	c = sys.stdin.read(1)
	if c=="6":
		animat["life"]=100
	if c=="0":
		robot2["life"]=0

def run(): #boucle de simulation
	global timeStep, robot2,animat,finalTime
	while animat["life"]!=0 and robot2["life"]!=0:
		if robot2["life"]>90 :
			timeStep=0.3
		elif robot2["life"]>80 :
			timeStep=0.25
		elif robot2["life"]>70 :
			timeStep=0.2
		elif robot2["life"]>60 :
			timeStep=0.19
		elif robot2["life"]>50 :
			timeStep=0.18
		elif robot2["life"]>40 :
			timeStep=0.17
		elif robot2["life"]>30 :
			timeStep=0.16
		elif robot2["life"]>20 :
			timeStep=0.15
		elif robot2["life"]>10 :
			timeStep=0.13
		elif robot2["life"]>1 :
			timeStep=0.1

		interact()		
		move()
		show()
		time.sleep(timeStep)
		finalTime = chrono()
		
		
def start(): #premier ecran du jeu 
	global animation,name
	name=Animation.showStart(animation)
	
def end():#dernier ecran de jeu
	global animation,robot2,animat,finalTime
	Animation.showEvent(animation,robot2,animat,finalTime)
	

def quitGame():	#echap clavier
	#restoration parametres terminal
	global old_settings
	
	#couleur white
	sys.stdout.write("\033[37m")
	sys.stdout.write("\033[40m")
	
	termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)
	sys.exit()

######################################
#initialisation
init()
#debut
start()
#play:
run()
#fin
end()
#quit:
quitGame()
