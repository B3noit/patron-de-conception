// Prototype.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <initializer_list>


class Robot										//La classe robot est la classe a partir de laquelle tous les prototypes sont construits
{
public:
	virtual Robot* clone() = 0;
	virtual void activation() = 0;				//Active le robot et indique son type
};

class Factory {									//la classe factory nous sert de fabrique pour les prototypes
public:
	static Robot* make_robot(int choice);		//Clone/crée un prototype
private:
	static Robot* s_prototypes[4];				//repertorie les choix possibles
};

int main() {
	std::vector<Robot*> roles;					//répertorie tous les choix de robots que l'utilisateur veut créer.
	int choice;

	while (true) {
		std::cout << "RobotJump(1) RobotPunch(2) RobotDrive(3) Go(4): "; //indique les choix GO = lancer le programme
		std::cin >> choice;//input des choix utilisateur
		if (choice == 0)
			break;
		roles.push_back(Factory::make_robot(choice)); //Ajoute le choix de l'utilisateur dans le vector roles
	}

	for (int i = 0; i < roles.size(); ++i) //Boucle pour activer tous les robots répertoriés.
		roles[i]->activation();
	for (int i = 0; i < roles.size(); ++i)//Boucle pour vider le vector roles
		delete roles[i];
}


class RobotJump : public Robot
{
public:
	Robot* clone() { return new RobotJump;}
	void activation()
	{
		std::cout << "RobotJump : jump high\n";
	}
};

class RobotPunch : public Robot
{
public:
	Robot* clone() { return new RobotPunch; }
	void activation()
	{
		std::cout << "RobotPunch : punch hard\n";
	}
};
class RobotDrive : public Robot
{
public:
	Robot* clone() { return new RobotDrive; }
	void activation()
	{
		std::cout << "RobotDrive : drift with style\n";
	}
};


Robot* Factory::s_prototypes[] = {                            //tableau repertoriant les robots/objets clonables
   0, new RobotJump, new RobotPunch, new RobotDrive
};
Robot* Factory::make_robot(int choice) {
	return s_prototypes[choice]->clone();					//méthode appelant la méthode clone de la classe de l'objet à cloner
}

