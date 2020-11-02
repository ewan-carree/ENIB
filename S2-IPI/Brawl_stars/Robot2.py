#############
#Robot2.py  #
#E.Carree   #
#07/06/2019 #
# S2P-B IPI #
#############

import sys
import random

#mes modules
import Background
import Animat


def create():	#creer le robot
	robot2 =dict()
	robot2["shape"] = [[" ","_","_","_","_","_","_"," "],
                      ["|"," ","\ "," "," ","/"," ","|"],["|","(","0","\ ","/","0",")","|"],["|"," "," "," "," "," "," ","|"],["|","[","]","[","]","[","]","|"],["|","_","_","_","_","_","_","|"]]
	robot2["x"] = 2
	robot2["y"] = 10
	robot2["width"] = len(robot2["shape"][0])
	robot2["high"] = len(robot2["shape"])
	robot2["color"] = 2
	robot2["life"]=100
	robot2["degat"]=1
	return robot2

 
def show(r2) :#afficher le robot
	#couleur fond
	sys.stdout.write("\033[40m")
	#couleur robot
	c=r2["color"]
	txt="\033[3"+str(c%7+1)+"m"
	sys.stdout.write(txt)
	
	for y in range(r2["high"]):
		for x in range(r2["width"]):
			s="\033["+str(r2["y"]+y+1)+";"+str(r2["x"]+x+1)+"H"    
			sys.stdout.write(s)
			sys.stdout.write(r2["shape"][y][x])
	
	txt="\033["+str(11)+";"+str(65)+"H"
	sys.stdout.write(txt)
	sys.stdout.write(str(r2["life"]))
	
	txt="\033["+str(12)+";"+str(70)+"H"
	sys.stdout.write(txt)
	sys.stdout.write("pos"+str(getPosition(r2)))

	
def move(r2,a,bg): #deplacement du robot
	#gestion palier de vie et evolution du robot
	if r2["life"]>60 :
		r2["degat"]=2
	elif r2["life"]>10 and r2["life"]<=60  :
		r2["degat"]=3
	elif r2["life"]<=10 :
		r2["degat"]=4
	elif r2["life"] <=0: #debuggage
		r2["life"]=0
	
	#deplacement du robot
	x,y=getPosition(r2)
	x1= random.randint(-1,1)
	y1=0
	if x1 == 0:
		y1= random.randint(-1,1)
	x=x+x1
	y=y+y1

	if y>1 and y<16 and x>2 and x<43:
		r2['x']=x
		r2['y']=y
		setColor(r2,2)	
	
	#evolution jauge enervement du robot	
	if r2["life"]>=91 and r2["life"]<=100:
		Background.setChar(bg,62,15,"#")
	elif r2["life"]>=81 and r2["life"]<=90:
		Background.setChar(bg,63,15,"#")
	elif r2["life"]>=71 and r2["life"]<=80:
		Background.setChar(bg,64,15,"#")
	elif r2["life"]>=61 and r2["life"]<=70:
		Background.setChar(bg,65,15,"#")
	elif r2["life"]>=51 and r2["life"]<=60:
		Background.setChar(bg,66,15,"#")
	elif r2["life"]>=41 and r2["life"]<=50:
		Background.setChar(bg,67,15,"#")
	elif r2["life"]>=31 and r2["life"]<=40:
		Background.setChar(bg,68,15,"#")
	elif r2["life"]>=21 and r2["life"]<=30:
		Background.setChar(bg,69,15,"#")
	elif r2["life"]>=11 and r2["life"]<=20:
		Background.setChar(bg,70,15,"#")
	elif r2["life"]>=1 and r2["life"]<=10:
		Background.setChar(bg,71,15,"#")
		
					

def setPosition(e,x,y):#redefinit la position du robot
	e["x"]=x
	e["y"]=y

def getPosition(e):#retourne la position du robot
	return e["x"],e["y"]
	
def setColor(e,color):#change la couleur du robot
	e["color"]=color


