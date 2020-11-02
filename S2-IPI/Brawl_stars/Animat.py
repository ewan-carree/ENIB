#############
#Animat.py  #
#E.Carree   #
#07/06/2019 #
# S2P-B IPI #
#############

import sys
import os
import random

#mes modules
import Background
import Robot2

#le module animat gere le type abstrait de donnee animat
#un animat est un objet qui se deplace dans le terminal 

def create(): #creer un joueur
	
	#creation animat
	animat=dict()
	animat["color"]=5
	animat["x"]=55
	animat["y"]=4
	animat["life"]=100
	animat["speed"]=1
	return animat

def show(a,name) : #afficher le joueur
	
	#on se place a la position de l animat dans le terminal
	x=str(int(a["x"]))
	y=str(int(a["y"]))
	txt="\033["+y+";"+x+"H"
	sys.stdout.write(txt)
	#couleur fond noire
	sys.stdout.write("\033[40m")
	#couleur animat
	c=a["color"]
	txt="\033[3"+str(c%7+1)+"m"
	sys.stdout.write(txt)
	#affichage de l animat
	sys.stdout.write("&")
	
	txt="\033["+str(4)+";"+str(65)+"H" #affichage nom joueur dans informations
	sys.stdout.write(txt)
	sys.stdout.write(str(name))
	
	txt="\033["+str(5)+";"+str(65)+"H" #affichage vie joueur dans informations
	sys.stdout.write(txt)
	sys.stdout.write(str(a["life"]))
	
	txt="\033["+str(6)+";"+str(70)+"H" #affichage position joueur dans informations
	sys.stdout.write(txt)
	sys.stdout.write("pos"+str(getPosition(a)))


def moveH(a,r2,bg): #deplacement joueur vers le haut
	x,y= getPosition(a)
	y=y-a["speed"]
	if Background.getChar(bg,x,y)==" ":  # deplacement si case libre
		a['x']=x
		a['y']=y
		setColor(a,5)
	elif Background.getChar(bg,x,y)=="*" or Background.getChar(bg,x,y)=="|":#collision mur/obstacle
		a["life"]=a["life"]-random.randint(1,5)
		setColor(a,7)
			
	m,b= Robot2.getPosition(r2) #position robot
	positionR3=[(m+1,b+2),(m+2,b+2),(m+3,b+2),(m+4,b+2),(m+5,b+2),(m+6,b+2),(m+7,b+2),(m+8,b+2),(m+1,b+3),(m+2,b+3),(m+3,b+3),(m+4,b+3),(m+5,b+3),(m+6,b+3),(m+7,b+3),(m+8,b+3),(m+1,b+4),(m+2,b+4),(m+3,b+4),(m+4,b+4),(m+5,b+4),(m+6,b+4),(m+7,b+4),(m+8,b+4),(m+1,b+5),(m+2,b+5),(m+3,b+5),(m+4,b+5),(m+5,b+5),(m+6,b+5),(m+7,b+5),(m+8,b+5),(m+1,b+6),(m+2,b+6),(m+3,b+6),(m+4,b+6),(m+5,b+6),(m+6,b+6),(m+7,b+6),(m+8,b+6)]
	for p in positionR3 :
		if getPosition(a) == p: #collision robot
			a["life"]=a["life"]-random.randint(1,3)*r2["degat"]
			setColor(a,7)
	#debuggage
	if a["life"]>100:
		a["life"]=100
	elif a["life"] <=0:
		a["life"]=0

def moveL(a,r2,bg): #deplacement joueur vers la gauche
	x,y= getPosition(a)
	x=x-a["speed"]
	if Background.getChar(bg,x,y)==" ":# deplacement si case libre
		a['x']=x
		a['y']=y
		setColor(a,5)
	elif Background.getChar(bg,x,y)=="*" or Background.getChar(bg,x,y)=="|":#collision mur/obstacle
		a["life"]=a["life"]-random.randint(1,5)
		setColor(a,7)

	m,b= Robot2.getPosition(r2)#position robot
	positionR3=[(m+1,b+2),(m+2,b+2),(m+3,b+2),(m+4,b+2),(m+5,b+2),(m+6,b+2),(m+7,b+2),(m+8,b+2),(m+1,b+3),(m+2,b+3),(m+3,b+3),(m+4,b+3),(m+5,b+3),(m+6,b+3),(m+7,b+3),(m+8,b+3),(m+1,b+4),(m+2,b+4),(m+3,b+4),(m+4,b+4),(m+5,b+4),(m+6,b+4),(m+7,b+4),(m+8,b+4),(m+1,b+5),(m+2,b+5),(m+3,b+5),(m+4,b+5),(m+5,b+5),(m+6,b+5),(m+7,b+5),(m+8,b+5),(m+1,b+6),(m+2,b+6),(m+3,b+6),(m+4,b+6),(m+5,b+6),(m+6,b+6),(m+7,b+6),(m+8,b+6)]
	for p in positionR3 :
		if getPosition(a) == p: #collision robot
			a["life"]=a["life"]-random.randint(1,3)*r2["degat"]
			setColor(a,7)
	
	#debuggage
	if a["life"]>100:
		a["life"]=100
	elif a["life"] <=0:
		a["life"]=0

def moveD(a,r2,bg): #deplacement joueur vers le bas
	x,y= getPosition(a)
	y=y+a["speed"]
	if Background.getChar(bg,x,y)==" ":# deplacement si case libre
		a['x']=x
		a['y']=y
		setColor(a,5)
	elif Background.getChar(bg,x,y)=="*" or Background.getChar(bg,x,y)=="|": #collision mur/obstacle
		a["life"]=a["life"]-random.randint(1,5)
		setColor(a,7)
			
	m,b= Robot2.getPosition(r2)#position robot
	positionR3=[(m+1,b+2),(m+2,b+2),(m+3,b+2),(m+4,b+2),(m+5,b+2),(m+6,b+2),(m+7,b+2),(m+8,b+2),(m+1,b+3),(m+2,b+3),(m+3,b+3),(m+4,b+3),(m+5,b+3),(m+6,b+3),(m+7,b+3),(m+8,b+3),(m+1,b+4),(m+2,b+4),(m+3,b+4),(m+4,b+4),(m+5,b+4),(m+6,b+4),(m+7,b+4),(m+8,b+4),(m+1,b+5),(m+2,b+5),(m+3,b+5),(m+4,b+5),(m+5,b+5),(m+6,b+5),(m+7,b+5),(m+8,b+5),(m+1,b+6),(m+2,b+6),(m+3,b+6),(m+4,b+6),(m+5,b+6),(m+6,b+6),(m+7,b+6),(m+8,b+6)]
	for p in positionR3 :
		if getPosition(a) == p: #collision robot
			a["life"]=a["life"]-random.randint(1,3)*r2["degat"]
			setColor(a,7)

	#debuggage		
	if a["life"]>100:
		a["life"]=100
	elif a["life"] <=0:
		a["life"]=0

def moveR(a,r2,bg): #deplacement joueur vers la droite
	x,y= getPosition(a)
	x=x+a["speed"]
	if Background.getChar(bg,x,y)==" ":# deplacement si case libre
		a['x']=x
		a['y']=y
		setColor(a,5)
	elif Background.getChar(bg,x,y)=="*" or Background.getChar(bg,x,y)=="|":#collision mur/obstacle
		a["life"]=a["life"]-random.randint(1,5)
		setColor(a,7)
	
	m,b= Robot2.getPosition(r2)#position robot
	positionR3=[(m+1,b+2),(m+2,b+2),(m+3,b+2),(m+4,b+2),(m+5,b+2),(m+6,b+2),(m+7,b+2),(m+8,b+2),(m+1,b+3),(m+2,b+3),(m+3,b+3),(m+4,b+3),(m+5,b+3),(m+6,b+3),(m+7,b+3),(m+8,b+3),(m+1,b+4),(m+2,b+4),(m+3,b+4),(m+4,b+4),(m+5,b+4),(m+6,b+4),(m+7,b+4),(m+8,b+4),(m+1,b+5),(m+2,b+5),(m+3,b+5),(m+4,b+5),(m+5,b+5),(m+6,b+5),(m+7,b+5),(m+8,b+5),(m+1,b+6),(m+2,b+6),(m+3,b+6),(m+4,b+6),(m+5,b+6),(m+6,b+6),(m+7,b+6),(m+8,b+6)]
	for p in positionR3 : #collision robot
		if getPosition(a) == p:
			a["life"]=a["life"]-random.randint(1,3)*r2["degat"]
			setColor(a,7)
			
	#debuggage
	if a["life"]>100:
		a["life"]=100
	elif a["life"] <=0:
		a["life"]=0


def setPosition(e,x,y): #redefinit la position du joueur
	e["x"]=x
	e["y"]=y

def getPosition(e): #retourne la position du joueur
	return e["x"],e["y"]
	
def setColor(e,color):#change la couleur du joueur
	e["color"]=color
