#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

//Definition de la classe employe
class Employe {
//Attributs prives 
private :
	string NAS;      // format "123 456 789", ex : "250 343 567"   
    float  salHebdo; // exemple 1075.25 
	
//Attributs publics	    
public :
//Constructeur initialise le NAS et le salaire hebdomadaire
  	Employe(const string& n, float s){
  		this -> NAS = n;
  		this -> salHebdo = s;
	}

//Constructeur surcharge initialise le NAS, les heures de travail, et le salaire horaire	  
	Employe(const string& n, float heuresTravaillees, float salaireHoraire){
		this->NAS=n;
		this->salHebdo=heuresTravaillees*salaireHoraire;
	}
	
	float getSalHebdo() const {
		return salHebdo;
	}
	
	void setSalHebdo(float nouveauSalaire){
		salHebdo = nouveauSalaire;
	}
//Fonction qui afficher les informations de l'employe
	void afficher(const string& message){
		cout << message << " :" << endl;
		cout << "    NAS : " << NAS << endl;
		cout << "    Salaire hebdomadaire : " << salHebdo << "$ par semaine" << endl;
	}
} ; 

//Fonction main
int main() {
	Employe emp1("321 498 726", 987.50);
	Employe emp2("135 444 321", 45.00, 20.00);
	
	emp1.afficher("Informations du premier employe");
	emp2.afficher("\nInformations du deuxieme employe");

	emp1.setSalHebdo(emp2.getSalHebdo()+125.75);
	emp1.afficher("\nInformations du premier employe apres modifications");
	
	return 0;
}
/*Execution:
Informations du premier employe :
    NAS : 321 498 726
    Salaire hebdomadaire : 987.5$ par semaine

Informations du deuxieme employe :
    NAS : 135 444 321
    Salaire hebdomadaire : 900$ par semaine

Informations du premier employe apres modifications :
    NAS : 321 498 726
    Salaire hebdomadaire : 1025.75$ par semaine

--------------------------------
Process exited after 0.6679 seconds with return value 0
Appuyez sur une touche pour continuer...
*/
