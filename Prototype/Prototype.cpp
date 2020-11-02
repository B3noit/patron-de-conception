// Prototype.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <initializer_list>


class Robot 
{
public:
	virtual Robot* clone() = 0;
	virtual void activation() = 0;
};

class Factory {
public:
	static Robot* make_robot(int choice);
private:
	static Robot* s_prototypes[4];
};

int main() {
	std::vector<Factory> roles;
	int choice;

	while (true) {
		std::cout << "RobotJump(1) RobotPunch(2) RobotDrive(3) Go(0): ";
		std::cin >> choice;
		if (choice == 0)
			break;
		Factory::make_robot(choice);
		roles.push_back(Factory::make_robot(choice));
	}

	for (int i = 0; i < roles.size(); ++i)
		roles[i]->activation();
	for (int i = 0; i < roles.size(); ++i)
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


Robot* Factory::s_prototypes[] = {
   0, new RobotJump, new RobotPunch, new RobotDrive
};
Robot* Factory::make_robot(int choice) {
	return s_prototypes[choice]->clone();
}

