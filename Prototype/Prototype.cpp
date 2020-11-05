// Prototype.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>

class SingletonInt
{
public:
	SingletonInt(const SingletonInt&) = delete; //On suprime le constructeur par copie ainsi on ne risque pas de créer des copies de notre singleton

	static SingletonInt& Get() //le mot clef static permet de nous assurer qu'il n'y aura qu'une seule instance de SingletonInt
	{
		static SingletonInt monSingletonInt; //Le singleton sera crée une fois, uniquement lors du premeir appelle de cette fonction grâce au mot clef static
		return monSingletonInt;
	}

	int maVariable() { return nVariable; } //Cette fonction retourn une donnée membre de la classe, elle n'est pas nécessair mais démontre que notre singleton est bien une classe 
										   //comme les autres et qu'elle peut gérer tous les aspects d'une classe normale(donnée membre, méthodes etc...)
private:
	SingletonInt() {}

	int nVariable = 2;					//Donnée membre de mon singleton 



};


int main()
{
	int nManaMx = SingletonInt::Get().maVariable(); //On appele le singleton pour utiliser une se ces fonctions.
		std::cout << nManaMx;
}