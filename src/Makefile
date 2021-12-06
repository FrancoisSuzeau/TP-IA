# ================== Rappel ======================
# $@ partie gauche de la dépendance (ou cible)
# $< est la premiere dependance
# $^ la liste des dépendances
# @$ pour desactiver l'echo des lignes de commandes en cas d'erreur

CFLAGS=-Wall -m64
EXEC=../bin/NeuralNetwork
CC=g++

#génération de la liste des fichiers objets
# SRC contient liste des fichier sources du projet 
# on pourrait utiliser une construction automatique a l'aide du joker *.c et la commande wildcard mais il faudra gerer les dépendances vis a vis des .h
# SRC=$(wildcard *.c)
SRC=Main.cpp NeuralNetwork/Neuron/Neuron.cpp NeuralNetwork/Layer/Layer.cpp NeuralNetwork/NeuralNetwork.cpp NeuralNetwork/Calcul.cpp

OBJET=$(SRC:.cpp=.o)

all:${EXEC}

${EXEC}: ${OBJET}
	@${CC}  -o $@ $^ ${CFLAGS}

# au cas ou .h est modifié

Main.o: NeuralNetwork/NeuralNetwork.hpp
Neuron.o: NeuralNetwork/Neuron/Neuron.hpp
Layer.o: NeuralNetwork/Neuron/Layer.hpp
NeuralNetwork.o: NeuralNetwork/NeuralNetwork.hpp NeuralNetwork/Layer.hpp
Calcul.o: NeuralNetwork/Calcul.hpp NeuralNetwork/Neuron/Neuron.hpp

%.o:%.cpp
	@$(CC) -o $@ -c $< ${CFLAGS}

#La partie en commentaire représente ce que la ligne au dessus fait
#function.o: function.c
#	@${CC} -o function.o -c function.c ${CFLAGS}

#main.o:main.c headers.h
#	@${CC} -o main.o -c main.c ${CFLAGS}


# Sur unix seulement
#.PHONY: clean mrpoper

#clean:
#	@rm -rf *.o

#mrpoper: clean
#	@rm -rf $(EXEC)

# Sur windows seulement
.PHONY: clean mrpoper

clean:
	del ${OBJET}

mrpoper: clean
	del $(EXEC)