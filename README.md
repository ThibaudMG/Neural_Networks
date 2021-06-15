# Réseaux de neuronnes en C++
> #### Objectif :
Le projet consiste à implémenter un réseau de neurones capable d’apprendre à classifier des images en fonction de leurs contenus.

> #### Solutions :
- Perceptron multicouches sans couche cachée
- Perceptron multicouche avec une couche cachée

> #### Résultats :
Les algorithmes tournent correctement et les résultats sont cohérents, néanmoins ils sont mauvais.
1. Première solution (NN1) :
	- Pour la classe Iris, un taux de classification entre 16% et 75%
	- Pour la classe Image, un taux de classification légèrement meilleur
2. Seconde solution (NN2) :
	- Pour la classe Iris, un taux de classification entre 16% et 33%
	- Pour la classe Image, un taux de classification légèrement meilleur 

> #### Utilisation :
- Requis : Neural_Networks/files/README  
$ cd .\src\  
$ make  
$ .\executable.exe argv[1](="nn1" ou "nn2") argv[2](="iris" ou "image")
