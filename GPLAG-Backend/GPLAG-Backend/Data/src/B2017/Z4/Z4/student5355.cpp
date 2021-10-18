#include <iostream>
#include <string>
#include <cmath>
#include <deque>
class Laptop
{
	//Student stu;
};

class Student
{
	Laptop lap;
	//Pomocne funkcije
	bool Chk_Index (int index);
	bool Chk_GodS  (std::string god_stud);
	void WhiteSpaceEater (std::string &nom_surnom);
public:
	//Student (int index, std::string god_stud , std::string nom_surnom, std::string addr,std::string br_tel  )

};



class Administracija
{
	Laptop lap;
	Student stu;
};


bool Student::Chk_Index (const int index)
{
	double Index_Checker= std::log (index);
	if (Index_Checker<5 && Index_Checker>=4) return true;
	return false;
}

bool Student::Chk_GodS (const std::string god_stud)
{
	if (god_stud.size()!=3) return false;
	else if (god_stud.at(0)>'3' || god_stud.at(0)<'1') return false;
	else if (god_stud.at(1)!='/') return false;
	else if (god_stud.at(2)!='B' && god_stud.at(2)!='M' && god_stud.at(2)!='D') return false;
	return true;
}

std::string Student::WhiteSpaceEater (std::string nom_surnom )
{
	std::deque<std::string> Spisak;
	nom_surnom+=" ";
	int vel(nom_surnom.size());
	for (int i(0); i<vel; i++) {
		if (nom_surnom.at(i)!=' ') {
			int poc_rijeci(i), vel_r(0);
			while (nom_surnom.at(i)!=' ' && i<vel-1)  {
				vel_r++;
				i++;
			}
			std::string pom= nom_surnom.substr (poc_rijeci, vel_r);
			Spisak.push_back (pom);
		}
	}
	std::string povratni;
	int vel_2(Spisak.size());
	for (int i(0); i<vel_2; i++) {
		std::cout<<"|"<<Spisak.at(i)<<"|"<<std::endl;
		povratni+=Spisak.at(i);
		if (i!=vel_2-1) povratni+=" ";
	}
	return povratni;
}

int main()
{
	
	return 0;
}

