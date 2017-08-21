feux de signalisation
=====================

L'idée est de faire 3 leds pour les feux de signalisation routiere et 2 leds pour les feux de signalisation piétonne.
Le tout sera synchronisé.

## Règles

* Le rouge route durera 5 secondes
* Le orange route durera 1 seconde
* Le vert route durera le temps que l'on appuit sur le bouton
* Le vert pieton durera 5 secondes 
  * Il se déclanchera 1 seconde après le rouge route
  * Et s'arretera 1 seconde avant le vert route
* Le rouge pieton s'allumera à l'extinction du vert pieton. 

    Regle speciale. En cas d'appuit sur le bouton le feux orange de route s'allumera immediatement.

### NB : cela me semble évident mais je précise que le feux de route ne peut avoir qu'une couleur à la fois.

## Etapes

1) feu vert permanent et feu rouge à la demande
2) factorisation du code
3) boucle rouge/vert
4) gestion d'interruption avec le bouton
5) clignotement du vert pieton avant de passer au rouge pieton
6) gestion buzzer
