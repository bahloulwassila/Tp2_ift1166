#include <iostream>
#include <iomanip>   
#include <string>
#include <fstream> 

using namespace std; // librairie standard

//Definition de la classe Personne
class Personne {
private: // Attributs privés de la classe Personne
    char sexe; 
    int numero;
    float taille, poids;

public:
	//Constructeur par defaut 
	Personne() : sexe('\0'), numero(0), taille(0.0), poids(0.0) {}
    Personne(char sexe, int numero, float taille, float poids);
	
	//Methode d'acces
	char getSexe() const { return sexe; }
    int getNumero() const { return numero; }
    float getPoids() const { return poids; }
    float getTaille() const { return taille; }
    
    //Methode pour afficher les informations d'une personne
    void afficherInformations() const {
        cout << "Sexe : " << sexe << endl;
        cout << "Numero : " << numero << endl;
        cout << "Taille : " << taille << " m" << endl;
        cout << "Poids : " << poids << " kg\n\n" << endl;
    }
    
    //Surcharge d'operateurs pour les comparaisons sur l'attribut 'numero'
    bool operator <= (const Personne & autre) const {
    	return numero <= autre.numero;
	}
	
	bool operator > (const Personne & autre) const {
		return numero > autre.numero;
	}
    
    //Methode pour diverses comparaisons sur les attributs 
    bool estPlusPetiteQue(const Personne &autre) const {
        return taille < autre.taille;
    }

    bool estFemmeEtPlusGrandeQue(const Personne &autre) const {
        return sexe == 'F' && taille > autre.taille;
    }

    bool estHommeEtPlusLourdQue(const Personne &autre) const {
        return sexe == 'M' && poids > autre.poids;
    }
};
    
//Definition du constructeur Personne   
Personne::Personne(char sexe, int numero, float taille, float poids) {
	this->sexe = sexe;
    this->numero = numero;
    this->taille = taille;
    this->poids = poids;
}

//Fonction patron pour afficher les informations d'un tableau d'objets Personnes
template <class Personne>
void afficher(Personne pers[], int nbPers, string mess)
{
	cout << "Contenu du tableau " << mess << " :\n\n";
	for (int i = 0; i < nbPers; i++)
		pers[i].afficherInformations();
	cout << endl ;
}

//Fonction modele pour echanger deux objets Personne
template <class Personne>
void permuter(Personne &a, Personne &b){
	Personne tempo = a;
	a = b;
	b = tempo;
}

//Fonction modele pour la partie partionnement de l'algo quicksort
template <class Personne>
int partitionner(Personne pers[], int debut, int fin) {
    int g= debut, d=fin;
	Personne valPivot = pers[debut];
	
	do{
		while ( g<= d && pers[g]<= valPivot)
			g++;
		while ( pers[d]> valPivot)
			d--;
		if (g<d)
			permuter(pers[g], pers[d]);
	} while (g < d);
    permuter(pers[d], pers[debut]);
    return d;
}

//Fonction modele pour l'algo de tri rapide
template <class Personne>
void triRapide(Personne pers[], int gauche, int droite)
{
    if (droite > gauche)
    {
    	int indPivot = partitionner(pers, gauche, droite);
        triRapide(pers, gauche, indPivot - 1);
        triRapide(pers, indPivot + 1, droite);
    }
}

//Fonction pour lire des donnees a partir d'un fichier et remplir un tableau de Personne
void lireRemplir(string nomALire, Personne pers[], int &nbPers){   
	const float PIED_EN_METRE = 0.3048,
        		LIVRE_EN_KG = 0.454;
    int numero, nbPieds, nbPouces, nbLivres;
    float taille, poids;
    char sexe;    
    ifstream  aLire(nomALire.c_str()); // localiser et ouvrir pour la lecture
	if (!aLire) {
        cerr << "Erreur lors de l'ouverture du fichier. \n\n" << endl;
        exit(1);
    }
				
	while (aLire >> sexe >> numero >> nbPieds >> nbPouces >> nbLivres)			       
	{
        taille = (nbPieds + nbPouces /12.0) * PIED_EN_METRE;
        poids  = nbLivres * LIVRE_EN_KG;                                
        pers[nbPers++]=Personne(sexe, numero, taille, poids);
		//nbPers++;               
	}
	aLire.close();   
}

//Fonction Afficher le nombre de personnes
void afficherNombrePersonnes(int nbPers){
	cout << "On a les informations de " << nbPers << " personnes\n\n";
}

//Fonction pour afficher la personne la plus petite	
void afficherPersonnePlusPetite(Personne pers[], int nbPers){
	if (nbPers == 0) {
		cout << "Aucune personne n'a ete lue. \n\n" << endl;
    	return;
	}
	Personne plusPetite = pers[0];
	triRapide(pers,0,nbPers-1)	;
	cout << "Informations de la personne ayant la taille la plus petite : \n\n";
	plusPetite.afficherInformations();
}

//Fonction pour afficher la plus grande femme
void afficherPlusGrandeFemme(const Personne pers[], int nbPers){
    if (nbPers == 0) {
        cout << "Aucune personne n'a ete lue. \n\n" << endl;
        return;
    }
    Personne plusGrandeFemme;
    bool femmeTrouvee = false;
    for (int i = 0; i < nbPers; ++i) {
    	if (pers[i].getSexe() == 'F') {
        	if(!femmeTrouvee||pers[i].getTaille()>plusGrandeFemme.getTaille()){
        	plusGrandeFemme=pers[i];
			femmeTrouvee = true;	
			}
    	}
	}
    if (femmeTrouvee){
        cout << "Informations de la femme ayant la taille la plus grande : \n\n";
        plusGrandeFemme.afficherInformations();
    } else {
        cout << "Aucune femme n'a ete trouvee. \n\n" << endl;
    }
}

//Fonction pour utiliser pour afficher l'homme le plus lourd
void afficherHommePlusLourd(Personne pers[], int nbPers) {
    if (nbPers == 0) {
        cout << "Aucune personne n'a ete lue. \n\n" << endl;
        return;
    }
    Personne plusLourdHomme;
    bool hommeTrouve = false;
    for (int i = 0; i < nbPers; ++i) {
    	if (pers[i].getSexe() == 'M') {
    		if(!hommeTrouve || pers[i].getPoids()>plusLourdHomme.getPoids()){
    			plusLourdHomme = pers[i];
    			hommeTrouve = true;
    		}
		} 
    }
    if (hommeTrouve) {
        cout << "Informations de l'homme ayant le poids le plus lourd : \n\n";
        plusLourdHomme.afficherInformations();
	} else {
		cout << "Aucun homme n'a ete trouve. \n\n" << endl;
	}
}

//Fonction pour afficher le poids moyen des hommes
void afficherPoidsMoyenHommes(const Personne pers[], int nbPers) {
    if (nbPers==0) {
        cout << "Aucune personne n'a ete lue. \n\n" << endl;
        return;
    }
    int nbHommes = 0;
    float poidsTotalHommes = 0.0;
    for (int i = 0; i < nbPers; ++i) {
        if (pers[i].getSexe() == 'M') {
            poidsTotalHommes += pers[i].getPoids();
            nbHommes++;
        }
    }
    if (nbHommes > 0) {
        float poidsMoyenHommes = poidsTotalHommes / nbHommes;
        cout << "Le poids moyen des hommes est de : " << poidsMoyenHommes << " kg \n\n" << endl;
    } else {
        cout << "Aucun homme n'a ete trouve. \n\n" << endl;
    }
}

//Fonction pour afficher la taille moyenne des femmes
void afficherTailleMoyenneFemmes(const Personne pers[], int nbPers) {
    if (nbPers == 0) {
        cout << "Aucune personne n'a ete lue. \n\n" << endl;
        return;
    }
    int nbFemmes = 0;
    float tailleTotalFemmes = 0.0;
    for (int i = 0; i < nbPers; ++i) {
        if (pers[i].getSexe() == 'F') {
            tailleTotalFemmes += pers[i].getTaille();
            nbFemmes++;
        }
    }
    if (nbFemmes > 0) {
        float tailleMoyenneFemmes = tailleTotalFemmes / nbFemmes;
        cout << "La taille moyenne des femmes est de :" << tailleMoyenneFemmes << " m\n\n" << endl;
    } else {
        cout << "Aucune femme n'a ete trouvee. \n\n" << endl;
    }
}

//Fonction pour trier les donnees par le numero
void trierParNumero(Personne pers[], int nbPers){
	triRapide(pers, 0, nbPers-1);
	cout << "Tableau des personnes triees par numero: \n\n";
    for (int i = 0; i < nbPers; i++) {
        pers[i].afficherInformations();
    }
}

//Fonction pour la recherche dichotomique
int rechercheDichotomique(Personne pers[], int nbPers, int numeroRecherche)  {
    int debut = 0;
    int fin = nbPers - 1;
    while (debut <= fin) {
        int milieu = (debut +fin) / 2;
        if (pers[milieu].getNumero() == numeroRecherche){
        	cout << "Informations de la personne ayant le numero " << numeroRecherche << " : \n\n";
			pers[milieu].afficherInformations();
			return milieu;
		}
    	else if(pers[milieu].getNumero()<numeroRecherche)
    		debut = milieu + 1;
		else
			fin = milieu -1;
	}
	cout << "Personne ayant le numero " << numeroRecherche << " non trouvee. \n\n";
	return - 1;
}  

//Fonction main utilisation des fonctions qui ont ete declarees
int main() {
	
	const int MAX_PERS = 30;
	Personne pers[MAX_PERS];
	int nbPers;
	
 	lireRemplir("imph24.txt", pers, nbPers);
 	afficherNombrePersonnes(nbPers);
 	
 	afficherPersonnePlusPetite(pers, nbPers);
 	
	afficherPlusGrandeFemme(pers, nbPers); 
	afficherHommePlusLourd(pers, nbPers);
	
	afficherPoidsMoyenHommes(pers, nbPers);
    afficherTailleMoyenneFemmes(pers, nbPers);
    
    trierParNumero(pers, nbPers);
    
    rechercheDichotomique(pers, nbPers, 2235);
    rechercheDichotomique(pers, nbPers, 2176);
    rechercheDichotomique(pers, nbPers, 9876);
	
 	return 0;

}

/*Execution:
On a les informations de 20 personnes

Informations de la personne ayant la taille la plus petite :

Sexe : F
Numero : 2187
Taille : 1.6764 m
Poids : 81.72 kg


Informations de la femme ayant la taille la plus grande :

Sexe : F
Numero : 2176
Taille : 1.8796 m
Poids : 84.898 kg


Informations de l'homme ayant le poids le plus lourd :

Sexe : M
Numero : 2879
Taille : 1.8796 m
Poids : 86.714 kg


Le poids moyen des hommes est de : 75.1989 kg


La taille moyenne des femmes est de :1.72156 m


Tableau des personnes triees par numero:

Sexe : F
Numero : 1357
Taille : 1.6764 m
Poids : 70.37 kg


Sexe : F
Numero : 2108
Taille : 1.8034 m
Poids : 74.91 kg


Sexe : F
Numero : 2176
Taille : 1.8796 m
Poids : 84.898 kg


Sexe : F
Numero : 2187
Taille : 1.6764 m
Poids : 81.72 kg


Sexe : M
Numero : 2233
Taille : 1.8542 m
Poids : 85.352 kg


Sexe : M
Numero : 2235
Taille : 1.8796 m
Poids : 85.806 kg


Sexe : M
Numero : 2879
Taille : 1.8796 m
Poids : 86.714 kg


Sexe : F
Numero : 3498
Taille : 1.4986 m
Poids : 61.29 kg


Sexe : F
Numero : 4100
Taille : 1.651 m
Poids : 54.026 kg


Sexe : M
Numero : 4148
Taille : 1.8034 m
Poids : 83.99 kg


Sexe : M
Numero : 4169
Taille : 1.6764 m
Poids : 55.842 kg


Sexe : F
Numero : 4177
Taille : 1.7526 m
Poids : 62.652 kg


Sexe : F
Numero : 4198
Taille : 1.7526 m
Poids : 56.75 kg


Sexe : M
Numero : 4354
Taille : 1.6764 m
Poids : 76.726 kg


Sexe : M
Numero : 4433
Taille : 1.4732 m
Poids : 57.658 kg


Sexe : M
Numero : 4869
Taille : 1.6002 m
Poids : 73.548 kg


Sexe : M
Numero : 5423
Taille : 1.7526 m
Poids : 66.738 kg


Sexe : M
Numero : 5444
Taille : 1.778 m
Poids : 68.554 kg


Sexe : F
Numero : 5477
Taille : 1.8034 m
Poids : 66.738 kg


Sexe : M
Numero : 5678
Taille : 2.0066 m
Poids : 86.26 kg


Informations de la personne ayant le numero 2235 :

Sexe : M
Numero : 2235
Taille : 1.8796 m
Poids : 85.806 kg


Informations de la personne ayant le numero 2176 :

Sexe : F
Numero : 2176
Taille : 1.8796 m
Poids : 84.898 kg


Personne ayant le numero 9876 non trouvee.


--------------------------------
Process exited after 0.3974 seconds with return value 0
Appuyez sur une touche pour continuer...
*/



