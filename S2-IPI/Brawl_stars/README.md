# brawl_stars
ENIB second semester project : create a simple game in python2.7 that can be runnable into the linux terminal

## Prerequisite
install python2.7

## Manuel d'utilisation :

Description générale : «Robot Rumble» est un jeu de survie pour un seul joueur. L'utilisateur peut se mesurer au robot dont le principe du jeu est de tuer le robot ou de survivre le plus longtemps possible. 

Règles du jeu : Le joueur doit se déplacer sur la carte tout en évitant le robot afin de ne pas prendre des dégâts car le robot essaye de le tuer. Il doit aussi éviter les murs qui lui inflige des dégâts lorsqu’il entre en contact avec.
Ce joueur possède une arme qui lui permet d’infliger des dégâts au robot. Cette arme est une arme à feu qui prend la forme que l’imagination de l’utilisateur lui donne. Pour faciliter le jeu, cette arme possède une réserve de munitions illimitée qui lui permet de tirer sans penser à comment gérer ses réserves. Cette arme tire dans une seule direction sur l’axe horizontal.
Au fur et à mesure des dégâts que le robot prend, sa jauge d'énervement augmente et ses capacités se décuplent, il gagne en vitesse ce qui rend la tâche de l’utilisateur plus difficile car le robot se déplace très vite et il est plus difficile de lui tirer dessus et le robot fait beaucoup plus de dégats. Il y aura trois paliers d’énervement allant de 100pv à 60pv, de 60pv à 10pv et de 10pv à 0pv. Le robot peut se déplacer verticalement et horizontalement aléatoirement, celui-ci peut tirer une pluie de tirs en direction du joueur. 2 tirs étant des missiles ayant une trajectoire rectiligne et une roquette ayant des déviations dans sa trajectoire. 
Les éléments qui se déplacent comme le robot et le joueur doivent rester dans la zone du jeu délimitée par des asterix. 
Un chronomètre observe les performances du joueur. Le joueur peut s’amuser à essayer de battre ce temps la partie d’après.

## Lancer le jeu 
python2.7 Main.py (dans un terminal Linux)

Le terminal doit être laissé dans un petit écran de terminal pour pouvoir jouer au jeu.

Pour quitter le jeu, l’utilisateur doit appuyer sur la toucher échap du clavier.

Jouer : z,q,s,d sur le clavier pour se déplacer (haut, bas, gauche, droite).

Eléments en plus du P2: 
Possibilité de choisir son pseudo en début de partie sur un nouvel écran de démarrage.

Le robot peut désormais se déplacer verticalement et horizontalement aléatoirement.
			
Les interactions clavier pour le joueur sont simplifiées, elles sont désormais plus simple d'utilisation.
