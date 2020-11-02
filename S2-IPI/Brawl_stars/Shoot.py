#############
#Shoot.py   #
#E.Carree   #
#07/06/2019 #
# S2P-B IPI #
#############

import sys
import random

#mes modules
import Background
import Animat
import Robot2

def create(x,y,color,decalage,etat,tir): #creation d'un tir
	shot=dict()
	shot["x"]=x
	shot["y"]=y
	shot["color"]=color
	shot["decalage"]=decalage
	shot["etat"]=etat
	shot["tir"]=tir
	return shot

def move(r2,bg,a,s,direction):	#deplacer un tir
	if s["etat"]== "missile": #missile
		x1,y= getPosition(s)
		x=x1+2*direction
		if Background.getChar(bg,x,y)==" ":#deplacement si case libre
			s["x"]=x
			setColor(s,2)
	
		if Background.getChar(bg,x,y)=="*" or Background.getChar(bg,x,y)=="|": #collision mur
			setColor(s,6)
			x,y=Robot2.getPosition(r2)
			setPosition(s,x+8,y+s["decalage"])
			move(r2,bg,a,s,direction)

		x,y = getPosition(s)
		x1,y1 = Animat.getPosition(a)
		if x==x1 and y==y1 or x-1==x1 and y==y1 :#collision joueur
			a["life"] = a["life"] - random.randint(1,3)*r2["degat"]
			Animat.setColor(a,7)

	elif s["etat"]=="roquette": #roquette
		x1,y1= getPosition(s)
		x=x1+3*direction
		y= y1+ random.randint(-1,1)
		if Background.getChar(bg,x,y)==" ":#deplacement si case libre
			s["x"]=x
			s["y"]=y
			setColor(s,2)
		
		if Background.getChar(bg,x,y)=="*" or Background.getChar(bg,x,y)=="|": #collision mur
			setColor(s,6)
			x,y=getPosition(r2)
			setPosition(s,x+8,y+s["decalage"])
			move(r2,bg,a,s,direction)
		
		x,y = getPosition(s)
		x1,y1 = Animat.getPosition(a)
		if x==x1 and y==y1 or x-1==x1 and y==y1 or x+1==x1 and y==y1 :#collision joueur
			a["life"] = a["life"] - random.randint(2,4)*r2["degat"]
			Animat.setColor(a,7)
			
	elif s["etat"] == "tir": #tir du joueur
		x1,y=getPosition(s)	
		x=x1+direction
		if Background.getChar(bg,x,y)==" " or Background.getChar(bg,x,y)=="|":#deplacement si case libre + gestion obstacle
			s["x"]=x
			setColor(s,5)

		if Background.getChar(bg,x,y)=="*":#collision mur
			x,y=getPosition(a)
			setPosition(s,x,y)
			move(r2,bg,a,s,direction)
		
		m,b= getPosition(r2) #position robot
		positionR=[(m+1,b+2),(m+2,b+2),(m+3,b+2),(m+4,b+2),(m+5,b+2),(m+6,b+2),(m+7,b+2),(m+8,b+2),(m+1,b+3),(m+2,b+3),(m+3,b+3),(m+4,b+3),(m+5,b+3),(m+6,b+3),(m+7,b+3),(m+8,b+3),(m+1,b+4),(m+2,b+4),(m+3,b+4),(m+4,b+4),(m+5,b+4),(m+6,b+4),(m+7,b+4),(m+8,b+4),(m+1,b+5),(m+2,b+5),(m+3,b+5),(m+4,b+5),(m+5,b+5),(m+6,b+5),(m+7,b+5),(m+8,b+5),(m+1,b+6),(m+2,b+6),(m+3,b+6),(m+4,b+6),(m+5,b+6),(m+6,b+6),(m+7,b+6),(m+8,b+6)]
		for p in positionR :
			if getPosition(s) == p: #collision tir joueur avec robot
				r2["life"]=r2["life"] - 1
				setColor(r2,7)

			
			
def show(s) :  #afficher un tir
	#on se place a la position du tir dans le terminal
	txt="\033["+str(s["y"])+";"+str(s["x"])+"H"
	sys.stdout.write(txt)
	
	#couleur fond noire
	sys.stdout.write("\033[40m")
	
	#couleur tir
	c=s["color"]
	txt="\033[3"+str(c%7+1)+"m"
	sys.stdout.write(txt)

	#affichage du tir
	sys.stdout.write(s["tir"])
			
def setPosition(e,x,y):#redefinit la position du tir
	e["x"]=x
	e["y"]=y

def getPosition(e):#retourne la position du tir
	return e["x"],e["y"]
	
def setColor(e,color):#change la couleur du tir
	e["color"]=color
