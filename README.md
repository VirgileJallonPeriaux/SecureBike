# SecureBike
## Projet de terminale STI2D SIN

### La mission :
Concevoir et mettre en place, à échelle réduite, un système permettant d'automatiser et de sécuriser l'accès à un parking à vélo. Pour réaliser ce projet, notre groupe de 5 personnes dispose de 90h. La gestion du temps (division des tâches et respect des délais) est cruciale.

### Matériel :
Projet réalisé avec le langage Arduino, des cartes Arduino (circuits électroniques programmables) ainsi que des composants électroniques.

### Attribution des tâches :
Les tâches ont été attribuées en fonction des connaissances et des compétences de chaque membre du groupe. Si un membre du groupe n'arrive pas à respecter les délais imposés, il n'est évidemment pas interdit de lui venir en aide.
![Attribution des taches](https://github.com/VirgileJallonPeriaux/SecureBike/blob/master/Taches/repartitionTaches.png)

#### Le fonctionnement
- Première utilisation<br>
Lorsqu'un utilisateur souhaite accéder au garage à vélo pour la première fois, il doit se rendre au bureau de la vie scolaire.
Celle-ci lui remettra un mot de passe provisoire ainsi qu'un badge. L'utilisateur devra alors se rendre au garage à vélo dans la journée pour valider la création de son compte grâce au mot de passe provisoire et définir son mot de passe personnel.
Le mot de passe personnel fait office de "code de secours" si l'utilisateur a perdu son badge.

- Déposer un vélo<br>
Lorqu'un utilisateur souhaite garer son vélo, il doit passer son badge devant le lecteur de la borne du garage à vélo (ou taper son mot de passe). La porte s'ouvre et un écran lui indique le numéro de la place qui lui a été attribué. L'antivol de la place en question s'ouvre. Une fois son vélo positionné, l'utilisateur devra refermer l'antivol.

- Récupérer un vélo<br>
Lorsque l'utilisateur souhaite récupérer son vélo, il doit passer son badge devant le lecteur de la borne du garage à vélo (ou taper son mot de passe). La porte du garage s'ouvre et l'antivol qui maintien le vélo de l'utilisateur fait de même.

## Mes tâches :
- #### Le module de la vie scolaire
La vie scolaire doit pouvoir générer un mot de passe provioire lorsqu'un utilisateur souhaite avoir accès au garage à vélo. Celui-ci est déterminé en fonction de paramètres variables (heure, mois...) et n'est valable que jusqu'à la fin de la journée.
Le module de la vie scolaire doit pouvoir afficher sur un écran le mot de passe généré ainsi que le tag (identifiant) du badge RFID délivré au nouvel utilisateur.

- #### La borne du garage à vélo
La borne du garage à vélo doit permettre d'autoriser, ou non, un utilisateur à entrer dans le garage.
Celle-ci doit être capable de vérifier la validité des codes saisis ainsi que la validité des tags des badges.
La base de données utilisée ici est une "flat database" puisque les données sont toutes stockées dans des fichiers texte, eux même stockés sur une carte SD.


### Pour aller plus loin <br>
Une fois les phases de tests effectuées avec succès, une mise en commun des différents programmes a été effectuée. Le projet a pu être réalisé dans les temps.
Nous avons consacré les heures restantes à soumettre des idées concernant l'amélioration potentielle de notre solution. Une solution a notamment été retenue :
Faire communiquer le module de la vie scolaire avec la borne du garage à vélo. Pour ce faire, il a été envisagé d'utiliser une carte Arduino Ethernet. A l'aide d'un simple logiciel, la vie scolaire pourrait alors gérer le garage à vélo depuis ses bureaux.
Verrouiller la porte, ouvir un antivol ou même allumer la lumière serait alors envisageable.

