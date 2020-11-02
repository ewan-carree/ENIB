################
#Background.py #
#E.Carree      #
#07/06/2019    #
# S2P-B IPI    #
################

import sys
import os
import random

#mes modules
import Animat

def create(filename):
	#creation du background
	bg=dict()
	#ouverture fichier
	myfile = open(filename, "r")	
	chaine=myfile.read()
	#separation des lignes
	listeLignes=chaine.splitlines()
	bg["map"]=[]
	#transformation en liste de liste
	for line in listeLignes:
		listeChar=list(line)
		bg["map"].append(listeChar)
	myfile.close()
	
	joker=dict() #creation bonus vie pour joueur
	joker["x"]=3 
	joker["y"]=random.randint(2,21) 
	joker["color"]=1
	return bg,joker

def show(bg,j) : #affichage background + bonus vie

	#couleur fond
	sys.stdout.write("\033[40m")
	#couleur white
	sys.stdout.write("\033[37m")
	
	#goto
	for y in range(0,len(bg["map"])):
		for x in range(0,len(bg["map"][y])):
			s="\033["+str(y+1)+";"+str(x+1)+"H"
			sys.stdout.write(s)
			#affiche
			sys.stdout.write(bg["map"][y][x])
			
	#on se place a la position du joker dans le terminal
	txt="\033["+str(j["y"])+";"+str(j["x"])+"H"
	sys.stdout.write(txt)
	
	#couleur fond noire
	sys.stdout.write("\033[40m")
	
	#couleur tir
	c=j["color"]
	txt="\033[3"+str(c%7+1)+"m"
	sys.stdout.write(txt)

	#affichage du tir
	sys.stdout.write("up")
	
def move(j,a,bg): # deplacement joker vie
	x1,y1=getPosition(j)
	x=x1+1
	y=y1
	if getChar(bg,x,y)==" ": #deplacement si case libre
			j['x']=x
			setColor(j,1)


	elif getChar(bg,x,y)=="*": #collision mur du joker si le joueur ne l'a pas pris
		setColor(j,6)
		x=3
		y=random.randint(2,21)
		setPosition(j,x,y)
		move(j,a,bg)

	if getPosition(j) == Animat.getPosition(a): #joueur recupere bonus vie
		a["life"]= a["life"]+ random.randint(1,5)
		x=3
		y=random.randint(2,21)
		setPosition(j,x,y)
		move(j,a,bg)
		
def setPosition(j,x,y):#redefinit la position du bonus
	j["x"]=x
	j["y"]=y

def getPosition(j):#retourne la position du bonus
	return j["x"],j["y"]
	
def setColor(j,color):#change la couleur du bonus
	j["color"]=color
	

def getChar(bg,x,y):
	#renvoie le contenu d une case donnee
	return (bg["map"][y-1][x-1])
	
def setChar(bg,x,y,c):
	#change le contenu d'une case donnee
	bg["map"][y-1][x-1]=c
