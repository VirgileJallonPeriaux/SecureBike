# SecureBike
## Projet de terminale STI2D SIN

### Objectif : concevoir et mettre en place, à échelle réduite, un système permettant d'automatiser et de sécuriser l'accès à un parking à vélo

Réalisé avec le langage Arduino, des cartes Arduino (circuits électroniques programmables) ainsi que des composants électroniques.

#### Le fonctionnement
Lorsqu'un utilisateur souhaite accéder au garagé à vélo pour la première fois, il doit se rendre au bureau de la vie scolaire.
Celle-ci lui remettra un mot de passe ainsi qu'un badge. L'utilisateur devra alors se rendre au garage à vélo dans la journée pour valider la création de son compte et définir son mot de passe personnel.
Le mot de passe fait office de "code de secours" si l'utilisateur a perdu son badge.


## Mes tâches :
#### Le module de la vie scolaire
La vie scolaire doit pouvoir générer un mot de passe. Celui-ci est déterminé en fonction de paramètres variables (heure, mois...) et n'est valable que jusqu'à la fin de la journée.
Le module doit pouvoir afficher sur un écran le mot de passe généré.
* Carte Arduino
* RTC (Real Time Clock)
* Module Grove
* Lecteur LCD

#### La borne du garage à vélo
De manière générale, ma tâche ici consiste à autoriser, ou non, un utilisateur à entrer dans le garage à vélo.
Je suis chargé de vérifier la validité des codes saisis ainsi que la validité des tags des badges.
La base de données utilisée ici est une "flat database" puisque les données sont toutes stockées dans des fichiers texte, eux même stockés sur une carte SD.
* Carte Arduino
* RTC (Real Time Clock)
* Module Grove
* Lecteur LCD
* Lecteur NFC/RFID Grove
* Module SD
* Tags RFID
