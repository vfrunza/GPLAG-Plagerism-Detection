/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::vector;
using std::string;


int PotencijalniKrivci(char** &x, vector<string> v){
	x = nullptr;
	try{
	x = new char*[v.size()];
	}
	catch(...){
		delete[] x;
		throw std::bad_alloc();
	}
	for(int i=0;i<v.size();i++)
		x[i] = nullptr;
	try{
	for(int i=0;i<v.size();i++){
		x[i] = new char[v[i].size() + 1];
		std::strcpy(x[i], v[i].c_str());
	}
	}catch(...){
		for(int i=0;i<v.size();i++)
			delete[] x[i];
		delete[] x;
		throw std::bad_alloc();
	}
	return v.size();
}

int OdbaciOptuzbu(char** &x, int vel, string ime){
	bool lo=false;
	for(int i=0;i<vel;i++){
		if(x[i]!=nullptr && strcmp(x[i], ime.c_str()) == 0 && lo == false){
			delete[] x[i];
			x[i] = nullptr;
			lo = true;
		}
	}
	int br(0);
	if(lo) for(int i=0;i<vel;i++)
			 if(x[i]==nullptr)
				 br++;
	if(!lo)throw std::domain_error("Osoba sa imenom " +ime+ " nije bila optuzena");
	if(br>10){
		int index(0);
		char **p(new char*[vel-br]);
		for(int i=0;i<vel;i++){
				if(x[i] != nullptr){
					p[index] = new char[std::strlen(x[i])];
					std::strcpy(p[index], x[i]);
					index++;
			}
		}
		//brisem staro;
		for(int i=0;i<vel;i++)
			delete[] x[i];
		delete[] x;
		
		x = p;
		return vel-br;
	}
	
	
	return vel;
}

int DodajOptuzbu(char** &x, int vel, string ime){
//	try{
	char *y(new char[ime.length()+1]);
	std::strcpy(y, ime.c_str());
//	}catch(...){
//		throw std::bad_alloc;
//		return vel;
//	}
	for(int i=0;i<vel;i++)
		if(x[i] == nullptr){
		//	delete[] x[i];
			x[i] = y;
		//	delete[] y;
			return vel;
		}
//	try{
	char **p = new char*[vel+1];
//	}catch(...){delete[] p; throw std::bad_alloc;}
	for(int i=0;i<vel;i++){
		p[i] = new char[std::strlen(x[i])];
		strcpy(p[i], x[i]);
	}
	p[vel] = y;
	x = p;
	return vel+1;
}

void IzlistajOptuzbu(char** x, int vel){
	for(int i=0;i<vel;i++){
		if(x[i]!=nullptr){
			for(int j=0;j<strlen(x[i]);j++)
				 cout << x[i][j];
		cout << "\n";
		}
	}
}

int main ()
{
	int brel;
	cout << "Koliko potencijalnih krivaca zelite unijeti? ";
	cin >> brel;
	cout << "\nUnesite potencijalne krivce: ";
	vector<string> v;
	
	for(int i=0;i<brel+1;i++){
		string s;
		std::getline(cin, s);
		v.push_back(s);
	}
	char **x;
	int vel;
	vel = PotencijalniKrivci(x, v);
	int opcija(-1);
	while(opcija!=0){
	cout << "\nOdaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	cin >> opcija;
	if(opcija == 1){
		cout << "\nUnesite ime novog optuzenog: ";
		string ime;
		cin.clear();
		cin.ignore(1000, '\n');
		std::getline(cin, ime);
		vel = DodajOptuzbu(x, vel, ime);
	}
	else if(opcija == 2){
		cout << "\nUnesite ime koje zelite izbaciti: ";
		string ime;
		cin.clear();
		cin.ignore(1000, '\n');
		std::getline(cin, ime);
		try{
		vel = OdbaciOptuzbu(x, vel, ime);
		}catch(std::domain_error cigla){cout << cigla.what();}
	}	
	else if(opcija == 3){
		IzlistajOptuzbu(x, vel);
	}
	else if(opcija == 0){
		for(int i=0;i<vel;i++)
			delete[] x[i];
		delete[] x;
	}
	}
	
	return 0;
}