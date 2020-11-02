################
#Animation.py  #
#E.Carree      #
#07/06/2019    #
# S2P-B IPI    #
################

import sys
import tty 

#mes modules
import Animat
import Robot2
import Background



def create(filename): # creer un fond d'ecran
	#creation du fond
	animation=dict()
	#ouverture fichier
	myfile = open(filename, "r")	
	chaine=myfile.read()
	#separation des lignes
	listeLignes=chaine.splitlines()
	animation["map"]=[]
	#transformation en liste de liste
	for line in listeLignes:
		listeChar=list(line)
		animation["map"].append(listeChar)
	myfile.close()		
	return animation
	
def showStart(animation): #affichage fond d'ecran
	#couleur fond
	sys.stdout.write("\033[40m")
	#couleur
	sys.stdout.write("\033[33m")
	
	for y in range(0,len(animation[2]["map"])):
		for x in range(0,len(animation[2]["map"][y])):
			s="\033["+str(y+1)+";"+str(x+1)+"H"
			sys.stdout.write(s)
			#affiche
			sys.stdout.write(animation[2]["map"][y][x])
	sys.stdout.write("\033[17;20H")
	sys.stdout.write("Appuyer sur entrer pour continuer")
	sys.stdout.write("\033[37m")
	sys.stdout.write("\033[15;20H")
	sys.stdout.write("Quel est votre pseudo ?")
	sys.stdout.write("\033[15;45H")
	name= str(raw_input()) #recuperation interaction clavier pour nom
	# interaction clavier
	tty.setcbreak(sys.stdin.fileno())
	return name

def showEvent(animation,r2,a,finalTime) : #affichage fond d'ecran
	if a["life"]<=0: #fond d'ecran defaite
		#goto
		for y in range(0,len(animation[1]["map"])):
			for x in range(0,len(animation[1]["map"][y])):
				s="\033["+str(y+1)+";"+str(x+1)+"H"
				sys.stdout.write(s)
				#affiche
				sys.stdout.write(animation[1]["map"][y][x])
		txt="\033["+str(13)+";"+str(0)+"H"
		sys.stdout.write(txt)
		sys.stdout.write(str(" Vous n'avez tenu que "+str(finalTime)+" secondes ..."))

	if r2["life"]<=0: #fond d'ecran victoire
		#goto
		for y in range(0,len(animation[0]["map"])):
			for x in range(0,len(animation[0]["map"][y])):
				s="\033["+str(y+1)+";"+str(x+1)+"H"
				sys.stdout.write(s)
				#affiche
				sys.stdout.write(animation[0]["map"][y][x])
		txt="\033["+str(13)+";"+str(0)+"H"
		sys.stdout.write(txt)
		sys.stdout.write(str(" Seulement "+str(finalTime)+" secondes, trop fort !!!"))
		
	#couleur fond
	sys.stdout.write("\033[40m")
	#couleur
	sys.stdout.write("\033[33m")

				

	
