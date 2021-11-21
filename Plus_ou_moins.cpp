#include<iostream>
#include<array>
#include<ctime>
#include<cstdlib>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::this_thread;

const int facile = 11;
const int moyen = 101;
const int difficile = 1001;

void montrer_la_regle(char c) {
	if (c == 'i') {
		cout << "-------------------------------------------------------------------------------------------------------" << endl;
		cout << "Le jeu du + ou - se deroule ainsi : " << endl;
		cout << "Moi (l'ordinateur) va choisir un chiffre au hasard entre 0 et 10/100/1000 (cela depend de la difficulte) " << endl;
		cout << "Ton but a toi est de deviner le nombre que j'ai choisi " << endl;
		cout << "Comment ? " << endl;
		cout << "Tu vas taper sur l'ordinateur un nombre pour essayer de deviner le mien, si ton nombre :" << endl;
		cout << "-est superieur au mien alors je te dirai ""-""" << endl;
		cout << "-est inferieur au mien alors je te dirai ""+""" << endl;
		cout << "-est egal a mon nombre alors tu as gagne !" << endl;
		cout << "Si tu t'es trompe alors tu peux tenter de retrouver mon nombre en tapant une nouvelle fois " << endl;
		cout << "un nombre sur le clavier a l'aide de l'indice et ceux jusqu'a ce que tu ai trouve mon nombre " << endl;
		cout << "-------------------------------------------------------------------------------------------------------" << endl << endl;

	}
	else if (c != 'i') {
		return;
	}
}
int choix_difficulte(char c,int& d) {

	switch (c) {
	case 'f':
		d = facile;
		return d;
		break;
	case 'm':
		d = moyen;
		return d;
		break;
	case 'd':
		d = difficile;
		return d;
		break;
	}
}
void plus_ou_moins(int a,int b) {
	while (a != b) {
		cout << "rentrer un nombre" << endl;
		cin >> a;
		while (a < b) {
			cout << "c'est ""+""" << endl;
			cout << "rentrer un nombre" << endl;
			cin >> a;
		}
		while (a > b) {
			cout << "c'est ""-""" << endl;
			cout << "rentrer un nombre" << endl;
			cin >> a;
		}
	}
	if (a == b) 
		cout << "felicitation vous avez trouve !" << endl;
}
int main() {
	int nb = -1, difficulte = -1, aleatoire = 0;
	char regle;
	char choix;
	srand(time(nullptr));
	cout << "Bienvenue" << endl;
	sleep_for(2s);
	cout << "On va jouer au jeu du + ou -" << endl;
	sleep_for(3s);
	cout << "Si, tu ne connais pas les regles de ce jeu appuie sur i, sinon appuie sur s" << endl << endl;
	cin >> regle;
	sleep_for(2s);
	montrer_la_regle(regle);
	cout << "Choisir la difficulte : " << endl;
	cout << "taper ""f"" pour facile" << endl;
	cout << "taper ""m"" pour moyen" << endl;
	cout << "taper ""d"" pour difficile" << endl;
	cin >> choix;
	choix_difficulte(choix,difficulte);
	aleatoire = rand() % difficulte;
	cout << "Commencons a jouer"  << endl;
	cout << "C'est bon j'ai choisi mon nombre , vas-y devine le !" << endl;
	plus_ou_moins(nb,aleatoire);
	return 0;
}
