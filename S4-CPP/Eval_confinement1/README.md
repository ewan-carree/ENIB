# cpp_test_S4
test concerning class in c++


## Prerequisite
No prerequisite.

## Use
make ./prog to compile

./prog to run it

make clean if you want to delete the files created by the make program


## For futher
fix mistakes, develop code

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Organisation : 100 %
Données et invariant : 40 %
Encapsulation : 100 %
Construction avec valeurs : 70 %
Construction par défaut : 50 %
Membre(s) de consultation : 20 %
Membre(s) de modification : 10 %
Non-membres de confort : 30 %
Tests : 100 %
Style : 0 %
Bonus : 0 %
Compilation et exécution : 100 %
--> Examen : 10.34 / 20

~~~~ remarques correction ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
L'attribut count_ ne sert à rien, vector possède déjà la fonction size() qui renseigne sa dimension.
Compliquer le code inutilement n'est pas de la programmation correcte.
L'invariant n'est pas très bien expliqué, autant dire que le vector ne peut pas contenir des chaînes vides, mais alors le constructeur par défaut ne respecte pas l'invariant vu qu'il crée un vecteur avec une chaîne vide, un bébé sans nom...
Le constructeur avec initialisation exige qu'il faut au moins un nom dans le vector. Pourquoi ? Où cette contrainte est expliquée ?
La fonction pour changer le nom ne change que celui du dernier alor que changer un nom déjà donné est un algorithme très simple, en outre la fonction n'assure pas l'invariant (le nouveau nom peut être une chaîne vide).
Ni dans la fonction birth() ni dans la fonction changeName() la std::move() est utilisée.
La fonction decease() peut causer un "segmentation fault"
La fonction pour consulter le tableau renvoie la copie du tableau ! Il aurait au moins fallu le renvoyer pas référence constante.
Si la recopie (par costruction ou affectation) ne fait rien d'autre que ce que la recopie automatiquement générée par le compilateur, alors il est inutile de la réimplémenter !!
La fonction globale pour recupérer un nom n'est pas une bonne idée, elle cause la copie du tableau entier juste pour en récupérer un nom. En outre elle ne s'assure pas que l'on ne sort pas du tableau.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
