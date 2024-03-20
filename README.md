# Tp2_ift1166
Numéro A (7 points) : classe string
La classe string fera partie des matières prévues pour l’examen intra. Elle comptera pour entre 30 et 40 points sur 100.

Soient les déclarations suivantes :
          string telUdM =  "5143436111",
               telJean  = "4501234567";

Écrire le code en C++ permettant de :

a)	Extraire avec des sous-chaînes appropriées puis afficher à l’écran :  
              Le telephone de l’Universite de Montreal :  (514) 343-6111
      Le telephone de Jean :  (450) 123-4567

b)	Compter et afficher à l’écran :  

Il y a 2 fois le caractère chiffre '4' dans le numéro de téléphone de UdeM
Il y a 4 fois le caractère chiffre '1' dans le numéro de téléphone de UdeM
Il y a 1 fois le caractère chiffre '7' dans le numéro de téléphone de Jean

c)	Prouver, par une fonction de type bool, que tous les caractères chiffres du numéro de téléphone de l’UdeM figurent dans celui de Jean.

d)	Afficher les caractères chiffres du numéro de téléphone de Jean qui ne figurent pas dans le numéro de téléphone de l’UdeM :  0  2  7

e)	Afficher les caractères, chiffres impairs, du numéro de téléphone de Jean : 1 3 5 7

f)	Afficher les caractères, chiffres pairs, du numéro de téléphone de l’UdeM : 4 6

g)	Déterminer puis afficher :

-	Le plus grand caractère chiffre du numéro de téléphone de l’UdeM :   6
-	Le plus petit caractère chiffre du numéro de téléphone de Jean : 0

Critères de correction pour le numéro A : 
-	Bon fonctionnement + qualité de chaque question : 1 point par question = 7 points

 
Numéro B (8 points) : Introduction à la POO en C++

On dispose de la classe incomplète Employe suivante : 

class Employe {  
  private :
            string NAS;      // format "123 456 789", ex : "250 343 567"   
            float  salHebdo; // exemple 1075.25 
  public : 
       . . .  Constructeurs à écrire . . . 
       . . .  Autres fonctions membres à écrire . . . 
} ; // fin de la classe Employe 

Écrire deux constructeurs appropriés utilisant le pointeur this pour construire ces deux employés : 

Employe emp1("321 498 726", 987.50),                          
        emp2("135 444 321", 45.00, 20.00); 
Le premier reçoit deux paramètres, le NAS (NAS) et le salaire hebdomadaire (salHebdo), alors que le second reçoit trois paramètres, le NAS, le nombre d’heures travaillés et le salaire horaire (il faut calculer le salaire hebdomadaire et le mettre dans salHebdo). 
Écrire la fonction membre afficher dont sa définition est reportée afin que : 
             emp2.afficher("Informations du deuxieme employe"); 
Affiche sur l’écran (tel quel) : 

  Informations du deuxieme employe :  
      NAS : 135 444 321 
      Salaire hebdomadaire : 900.00$ par semaine 
 
Écrire les méthodes d’accès et de modification sur le salaire hebdomadaire. Utiliser ces méthodes afin de changer le salaire de emp1 en utilisant celui de emp2 auquel on ajoute 125.75$. On affiche les informations de emp1 après cette modification.

Critères de correction pour le numéro B : 

-	Classe Employe                      : 5 points
-	Fonction principale                   : 3 points




Numéro C (20 points) : Classe et tableau d’objets

Vous disposez du fichier texte imp_h24.txt sur StudiUM.
Le programme Tab_Pers.cpp permet de lire ce fichier, remplit le tableau pers des objets de la classe Personne et de transmettre par référence le nombre exact de personnes lues.
On explique ce programme et le rend disponible sur StudiUM.

Adaptez ce programme en C++ permettant aussi de :

1.	Afficher le nombre de personnes lues en utilisant des fonctions appropriées.

2.	Déterminer et afficher les informations de la personne ayant la taille la plus petite.
              
   3. Déterminer et afficher les informations des personnes ci-dessous :
            a) La femme ayant la taille la plus grande ;
            b) L’homme ayant le poids le plus lourd.

   4. Calculer et afficher :
            a) Le poids moyen des hommes ;
            b) La taille moyenne des femmes.

5.	Trier (avec le tri rapide) les personnes selon leurs numéros et afficher le contenu du tableau pers après le tri.                     

   6.   Rechercher et afficher les résultats de la recherche dichotomique des personnes ayant les numéros suivants : 2235, 2176, 9876.

Critères de correction du numéro C : 
   
        - Bon fonctionnement + qualité du code                   6 tâches x 2,5 points   :      15 points
        - La classe Personne avec des fonctions membres                                    :           5 points
