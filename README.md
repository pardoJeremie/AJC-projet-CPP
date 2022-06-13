# AJC-projet-CPP

**PROJET C++ / SQLite**

*CREATION D’UNE APPLICATION DE GESTION DE CONTACTS

Au travers de ce projet, vous reverrez beaucoup de points abordés dans l’ensemble des modules. Il s'agit de créer un annuaire dans lequel seront stockés des contacts.

Le projet sera décomposé en plusieurs parties.
- PARTIE 1 : GESTION DES CONTACTS
- PARTIE 2 : BASE DE DONNEES
- PARTIE 3 : CREATION DE L'INTERFACE
 
*PARTIE 1 : GESTION DES CONTACTS*

On distingue différents types de contacts :
- Des contacts « Privés »
- Des contacts « Professionnels »

Pour l’ensemble des contacts, on distingue les caractéristiques suivantes :
- Identifiant (Numérique)
- Nom (Chaine de 30 car. en majuscule)
- Prénom (Chaine de 30 car. Première lettre en majuscule)
- Sexe (F/M)

Pour les contacts Privés, on stockera les informations suivantes :
- Adresse postale
- Date de Naissance

Pour les contacts Professionnels, on stockera les informations suivantes :
- Nom de l’entreprise (Chaine de 50 car. en majuscule)
- Adresse de l'entreprise
- Adresse Mail (Chaîne contenant un @)

Toute adresse est composée du Numéro, Rue, Complément, Code Postal et Ville. On considérera que l'ensemble des Contacts est Français.
Il est évident que vous vérifierez la véracité de chaque information.
Créer dans un premier temps une application console vous permettant de tester la hiérarchie mise en place.

*PARTIE 2 : BASE DE DONNEES*

Par ailleurs, vous disposez d'une base de données "dbContacts.db". Cette base de données recense une série de contacts.
Au sein de cette base de données, se trouve une table "CONTACTS" dans laquelle on distingue à la fois des contacts privés ou professionnels.


*PARTIE 3 : CREATION DE L'INTERFACE*

De plus, vous constituerez une application console utilisant la hiérarchie préalablement constituée dans la Partie 1 ainsi que la Base de données "dbContacts.db".

Cette application graphique offrira à l’utilisateur la possibilité de :
- Lister les contacts privés et/ou professionnels en respectant certaines contraintes au niveau de l’affichage (cf. Annexe)
- Recherche à partir de certains critères :
	- Par Nom
	- Par Ville
- Ajouter un contact quel qu'en soit le type
- Supprimer un Contact via son identifiant.

Pour l’ensemble des fonctionnalités, vous afficherez un message d’erreur en cas d’échec. Constituez une interface simple et conviviale.

*CONTRAINTES TECHNIQUES

D’un point de vue technique, on devra retrouver, au sein de votre code, les concepts suivants :
- Héritage
- Surcharge d’Opérateurs
- Composition/Agrégation
- STL
- Exception

Votre projet devra être disponible sur GitLab. Il devra comporter au moins un commit pour chaque fonctionnalité ajoutée et en état de fonctionnement. Vous pouvez effectuer évidemment des COMMIT intermédiaires.
- Les différents commit doivent bien être détaillés.
- Vous créerez au moins une branche pour chaque partie
Vous définirez également des Tags pour chaque version stable.
- Commit 1 : Ajout Fichier README.txt comportant l’énoncé - Commit N : ...

Parmi les fichiers sources, vous trouverez:
- Données dbContacts.xlsx : Fichier contenant les données présentées dans ce document
- dbContacts.db : Base de données des Contacts

A la fin du projet, vous mettrez dans la section Travaux:
- Un projet zippé
- le lien vers votre dépôt public Gitlab accessible.

*ANNEXE*

*EXEMPLE DE LISTING DES CLIENTS :

	Particulier : 00001
	M. BETY Daniel
	12, rue des Oliviers
	94000 CRETEIL
	Situation Familiale : Célibataire 
	age : 25 ans et Bon Anniversaire !
	Professionnel : 00004

Contraintes d’Affichage :
	▪ Numéro sur 5 chiffres obligatoires
	▪ Nom en Majuscules
	▪ Prénom : 1ère lettre en Majuscule, les autres minuscules
	▪ Ville en Majuscules
	
...
	Société PAUL
	Contact : Mme JOAU Jeanne 36, quai des Orfèvres
	93500 ROISSY EN FRANCE
	Mail : info@paul.fr
  
