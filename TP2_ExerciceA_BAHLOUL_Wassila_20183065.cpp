#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//fonction pour afficher le numero de telephone et le nom de la personne
void afficherTelephone(const string& nom, const string& numero) {
	string code = numero.substr(0, 3);
	string part1 = numero.substr(3, 3);
	string part2 = numero.substr(6, 4);

	cout << "Le telephone de " << nom << " : (" << code << ") " << part1 << "-" << part2 << endl;
}

//Fonction pour compter les repetition dans un numero
void compterRepetition(const string& nom, const string& numero, char chiffre) {
	int occurrences = count(numero.begin(), numero.end(), chiffre);

	cout << "Il y a " << occurrences << "  fois le caractere chiffre " << chiffre << " dans le numero de telephone de " << nom << endl;
}

//Fonction booleene pour trouver les chiffres du numero de telephone de L'UdeM qui sont present dans celui de Jean
bool tousChiffresUdemPresentsDansJean(const string& telUdM, const string& telJean) {
	int index = 0;
	
	while (index < telUdM.size()) {
		char caractereCourant = telUdM[index];
		
		if(isdigit(caractereCourant) && telJean.find(caractereCourant) == string::npos) {
				return false;
			}
		index++;
	}
	return true;
}

//Fonction pour afficher les resultats de la fonction precedente
void afficherResultatVerification(const string& telUdM, const string& telJean) {
	if (tousChiffresUdemPresentsDansJean(telUdM, telJean)) {
		cout << "Tous les chiffres du numero de l'UdeM figurent dans celui de Jean." << endl;
	} else {
		cout << "Certains chiffres du numero de l'UdeM ne figurent pas dans celui de Jean." << endl;
	}
}

//Fonction pour afficher les chiffres qui sont absents dans le numero de l'UdeM qui sont presents dans celui de Jean
void afficherChiffresNonPresent(const string& telUdM, const string& telJean) {
	cout << "Caracteres chiffres de Jean absents dans Udem: ";

	for(int i = 0; i < telJean.size(); ++i) {
		char chiffreJean = telJean[i];
		if (isdigit(chiffreJean) && telUdM.find(chiffreJean) == string::npos) {
			cout << chiffreJean << " ";
		}
	}

	cout << endl;
}

//Fonction pour afficher les chiffres impairs d'un numero
void afficherChiffresImpairs(const string& numero){
	cout << "Caracteres chiffres impairs de Jean: ";
	bool dejaPresent[10]={false};
	int index = 0;
	while (index < numero.size()){
		char chiffre = numero[index];
		if (isdigit(chiffre)) {
			int chiffreInt = chiffre - '0';
			if (chiffreInt %2 != 0 && !dejaPresent[chiffreInt]){
				cout << chiffreInt << " ";
				dejaPresent[chiffreInt]=true;
			}
		}
		index++;
	}
	cout << endl;
}

//Fonction pour afficher les chiffres pairs d'un numero
void afficherChiffresPairs(const string& numero){
	cout << "Caracteres chiffres pairs de l'UdeM: ";
	int index = 0;
	
	while (index < numero.size()){
		char chiffre = numero[index];
		
		if(isdigit(chiffre)){
			int chiffreInt = chiffre - '0';
			if (chiffreInt %2 == 0){
				cout << chiffreInt << " ";
			}
		}
		index++;
	}
	cout << endl;
}

//Fonction pour trouver le plus grand chiffre d'un numero
void trouverPlusGrandChiffre(const string& numero){
	string::const_iterator i = max_element(numero.begin(), numero.end());
	if (i != numero.end() && isdigit(*i)){
		cout << "Le plus grand caractere chiffre du numero de telephone: "<< *i << endl;
	} else {
		cout << "Aucun caractere chiffre trouve." << endl;
	}
}

//Fonction pour trouver le plus petit chiffre d'une numero
void trouverPlusPetitChiffre(const string& numero){
	string::const_iterator i = min_element(numero.begin(), numero.end());
	if (i != numero.end() && isdigit(*i)){
		cout << "Le plus petit caractere chiffre du numero de telephone: "<< *i << endl;
	} else {
		cout << "Aucun caractere chiffre trouve." << endl;
	}
}

//Fonction main
int main() {
	string telUdM = "5143436111";
	string telJean = "4501234567";

	afficherTelephone("l'Universite de Montreal", telUdM);
	afficherTelephone("Jean", telJean);

	compterRepetition("UdeM", telUdM, '4');
	compterRepetition("UdeM", telUdM, '1');
	compterRepetition("Jean", telJean, '7');

	afficherResultatVerification(telUdM, telJean);
	afficherChiffresNonPresent(telUdM, telJean);
	afficherChiffresImpairs(telJean);
	afficherChiffresPairs(telUdM);
	
	trouverPlusGrandChiffre(telUdM);
    trouverPlusPetitChiffre(telJean);

	return 0;
}

/*Execution:
Le telephone de l'Universite de Montreal : (514) 343-6111
Le telephone de Jean : (450) 123-4567
Il y a 2  fois le caractere chiffre 4 dans le numero de telephone de UdeM
Il y a 4  fois le caractere chiffre 1 dans le numero de telephone de UdeM
Il y a 1  fois le caractere chiffre 7 dans le numero de telephone de Jean
Tous les chiffres du numero de l'UdeM figurent dans celui de Jean.
Caracteres chiffres de Jean absents dans Udem: 0 2 7
Caracteres chiffres impairs de Jean: 5 1 3 7
Caracteres chiffres pairs de l'UdeM: 4 4 6
Le plus grand caractere chiffre du numero de telephone: 6
Le plus petit caractere chiffre du numero de telephone: 0

--------------------------------
Process exited after 0.6563 seconds with return value 0
Appuyez sur une touche pour continuer...
*/
