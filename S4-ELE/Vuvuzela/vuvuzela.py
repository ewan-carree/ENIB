#!/usr/bin/env python
# coding: utf-8

import pygame
from pygame.locals import *
from math import pi
from math import sqrt
#bibliotheque definissant tous les opérations de calcul
import numpy as np
#librairie avec les fonctions permetttant l'affichage
import matplotlib.pyplot as plt
import scipy.signal as sig
import IPython.display as ipd 

def play(AudioName):
	#Initialisation
	pygame.init()
	fenetre = pygame.display.set_mode((300,300))
	son = pygame.mixer.Sound(AudioName)
	 
	continuer = 1 #Variable de boucle
	joue = 0 #1 si le son a été mis en pause

	while continuer:
		for event in pygame.event.get():
	         #Quitter
			if event.type == QUIT:
				continuer = 0
			
			#Lancer le son
			if event.type == KEYDOWN and event.key == K_SPACE and joue == 0:
				son.play()
				joue = 1
			#Sortir de pause
			if event.type == KEYDOWN and event.key == K_SPACE and joue == 1:
				pygame.mixer.unpause()
			#Mettre en pause
			if event.type == KEYUP and event.key == K_SPACE:
				pygame.mixer.pause()
			#Stopper
			if event.type == KEYDOWN and event.key == K_RETURN:
				son.stop()
				joue = 0


def trunc(rate,data):
	data_trunc=data[:3*rate]#son coupé à 3s car échantillon intéressant à analyser
	return data_trunc


def temporel(rate, data_trunc):
	t_trunc = np.arange(len(data_trunc))/rate #definition de l'axe temporel
	plt.plot(t_trunc,data_trunc) #analyse temporelle
	plt.xlabel("temps (s)")
	plt.ylabel("magnitude")
	plt.title("Analyse temporelle")
	plt.show()


def frequentiel(rate,data_trunc):
	f, Pxx_den = sig.periodogram(data_trunc, rate)#analyse fréquentielle
	plt.plot(f, Pxx_den)#plot permet de mettre l'échelle en linéaire
	plt.xlabel('frequency [Hz]')
	plt.ylabel('PSD [V**2/Hz]')
	plt.xlim([0,1500])#permet de zoomer sur l'image
	plt.title("Analyse fréquentielle")
	plt.show()

def transfert_function(f0, m, T0):
	den = [1/(2*pi*f0)**2,2*m/(2*pi*f0), 1] #coef du polynome dans l'ordre decroissant des puissance (de jw) JUSQUA 0
	num = [1/(2*pi*f0)**2,0,1] 
	T = sig.lti(num,den) #generation du systeme linéaire correspondant à cette fonctionde transfert
	return T

def transfert_function_twinT_passif(f0):
	num = [1/(2*pi*f0)**2,0, 1] #coef du polynome dans l'ordre decroissant des puissance (de jw) JUSQUA 0
	den = [1/(2*pi*f0)**2,4/(2*pi*f0),1] 
	T = sig.lti(num,den) #generation du systeme linéaire correspondant à cette fonctionde transfert
	return T

def transfert_function_twinT_actif(f0,Q):
	num = [1/(2*pi*f0)**2,0, 1] #coef du polynome dans l'ordre decroissant des puissance (de jw) JUSQUA 0
	den = [1/(2*pi*f0)**2,1/(2*pi*f0*Q),1] 
	T = sig.lti(num,den) #generation du systeme linéaire correspondant à cette fonctionde transfert
	return T

def bode(Transfert):
	[w,T]=Transfert.freqresp() #calcul de Tcomplexe pour toutes les pulsations
	mod=abs(T) #definition du module
	#arg=180*np.angle(T)/pi #definition de l'argument en degrés
	plt.loglog(w,mod) #trace sur echelles log log avec legende correspondante à la trace calculée 
	plt.ylabel("module sans unité")
	plt.xlabel("pulsation en rad/s")
	plt.title("diagramme de Bode")
	plt.show()

def indicielle(f0, Transfert):
	Te = 0.00001 #periode d'echantillonage des calculs
	Tau = 1/(2*pi*f0) #constante de temps du systeme
	t = np.arange(0, 10*Tau, Te) #definition des instants où seront calculés les signaux ## depart 6Tau
	[ta, rep_ind] = Transfert.step(T=t) #calcul de la réponse indicielle pour tous les points definis.Sortie sous forme d'un tableau de coordonnées 	plot(t*1000, rep_ind, color="red", label ="s(t)") #affichage de la trace avec axe en ms
	plt.plot(t*1000, rep_ind, color="red", label ="s(t)") #affichage de la trace avec axe en ms
	plt.xlabel('temps [ms]')
	plt.ylabel('sortie[V]')
	plt.title("réponse indicielle du systeme, entrée = échelon 1V à t=0")
	plt.show()

def compute_components(f=[235,705,1175,1410]):
	w0 = []
	for f0 in f:
		w0.append(2*pi*f0)
	#print(w0)
	L = 100*10**-3

	C = []
	for w in w0:
		C.append(1/(L*w**2))
	
	m = 1

	R = []
	for c in C:
		R.append((2*m)/(sqrt(c/L)))

	return L,C,R

def compute_components_actif(f=[235,705,1175,1410]):
	"""

	R1 = R2 = R 
	R3 = R/2 
	C1 = C2 = C 
	C3 = 2C

	"""
	R = 1000
	C = []
	for f0 in f:
		C.append(1/(2*pi*f0*R))

	Q = 0.3 # >0.25
	R4 = 1000
	R5 = R4*(Q*4-1)

	return R,C,R4,R5




def poles_zero(Transfert):
	poles = Transfert.poles
	zeros = Transfert.zeros
	plt.plot(np.real(poles),np.imag(poles),"x")
	plt.plot(np.real(zeros),np.imag(zeros),"o")


	
"""
from scipy.io.wavfile import read
import numpy as np
import matplotlib.pyplot as plt
from ipywidgets import interact
[rate,data]=read("./vuvuzela.wav")
@interact(t=(0.0,50.0,0.1))
def show_truncate(t_max=10):
    t = np.arange(len(data))/rate
    plt.plot(t[:t_maxrate],data[:t_maxrate])
Vous l'avez rêvé....Jupyter l'a fait !

vous choisissez la valeur de R (de manière à avoir m<1)

il faudrait être de l'ordre de la dizaine ou centaine de mH.
"""