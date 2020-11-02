// Prototype.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>

class Robot {										//La classe dont hérite les robots fabriqués
public:
	virtual ~Robot() {}
	virtual std::string Operation() const = 0;
};


class RobotJump : public Robot {				//La classe des robotjump
public:
	std::string Operation() const override {
		return "{RobotJump a ete lance}";
	}
};
class RobotPunch : public Robot {				//La classe des robotpunch
public:
	std::string Operation() const override {
		return "{RobotPunch a ete lance}";
	}
};


class Creator {		//La classe creator dont les sous-classe de créateurs de robots héritent
public:
	virtual ~Creator() {};
	virtual Robot* FactoryMethod() const = 0;

	std::string SomeOperation() const {
		//appelle la méthode factory qui elle crée réellement le robot
		Robot* robot = this->FactoryMethod();
		//on appelle une méthode du robot crée pour prouver que cela fonctionne.
		std::string result = "Le Creator vient de confirmer que " + robot->Operation();
		delete robot;
		return result;
	}
};

class CreatorRobotJump : public Creator {		//les sous classes de créateurs surcharge la méthode factory						
public:											//pour crée les robots qui leurs sont attribués
	Robot* FactoryMethod() const override {
		return new RobotJump();
	}
};
class CreatorRobotPunch : public Creator {
public:
	Robot* FactoryMethod() const override {
		return new RobotPunch();
	}
};


void GenieDuMal(const Creator& creator) {// fonction a l'origine de la demande de la création d'un robot

	std::cout << "Genie du mal :\"Je veux lancer un robot ! Peu importe lequel depechez-vous!\"\n"
		<< creator.SomeOperation() << std::endl;
}

int main() {
	std::cout << "Lancment d'un RobotJump\n";
	Creator* creator = new CreatorRobotJump();//test robot jump
	GenieDuMal(*creator);
	std::cout << std::endl;
	std::cout << "Lancment d'un RobotPunch\n";
	Creator* creator2 = new CreatorRobotPunch();//test robot punch
	GenieDuMal(*creator2);

	delete creator;
	delete creator2;
	return 0;
}
