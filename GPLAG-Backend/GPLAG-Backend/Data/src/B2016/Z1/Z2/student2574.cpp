#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;

typedef typename std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica (Matrica main_matrica) {
	if (main_matrica.size()==0)
		return main_matrica;
	for (int i=0; i<main_matrica.size(); i++) {
		if (i==main_matrica.size()-1 && i>1) {
			if (main_matrica.at(i).size()!=main_matrica.at(i-1).size()) {
				throw std::domain_error ("Matrica nije korektna");
				break;
			}
		}
		else if ( i>1 && main_matrica.at(i).size()!=main_matrica.at(i+1).size())
			throw std::domain_error ("Matrica nije korektna");
	}
	Matrica Vertikalno (main_matrica);
	//VERTIKALNO OGLEDALO//
	for (int i=0; i<int(Vertikalno.size()/2);i++) {
		std::vector<double> temp;
		temp.resize(Vertikalno[i].size());
		temp=Vertikalno[i];
		Vertikalno[i]=Vertikalno[Vertikalno.size()-1-i];
		Vertikalno[Vertikalno.size()-1-i]=temp;
	}
	//HORIZONTALNO OGLEDALO//
	Matrica Horizontalno (main_matrica);
	for (int i=0; i<Horizontalno.size(); i++) {
		int index(Horizontalno[i].size()-1);
		for (int j=0; j<int(Horizontalno[i].size()/2); j++) {
			double temp(Horizontalno[i][j]);
			Horizontalno[i][j]=Horizontalno[i][index];
			Horizontalno[i][index]=temp;
			index--;
		}
	}
	//KOMBINOVANO OGLEDALO//
	Matrica Kombinovano (main_matrica); 
		for (int i=0; i<int (Kombinovano.size()/2); i++) {
			std::vector<double> temp;
			temp.resize(Kombinovano[i].size());
			temp=Kombinovano[i];
			Kombinovano[i]=Kombinovano[Kombinovano.size()-1-i];
			Kombinovano[Kombinovano.size()-1-i]=temp;
		}
		for (int i=0; i<Kombinovano.size(); i++) {
			int index (Kombinovano[i].size()-1);
			for (int j=0; j<int(Kombinovano[i].size()/2); j++) {
				double temp(Kombinovano[i][j]);
				Kombinovano[i][j]=Kombinovano[i][index];
				Kombinovano[i][index]=temp;
				index--;
			}
		}
		//Čuvaj iz mejna origidžinal//
	Matrica OBICNA (main_matrica);
	Matrica GOTOVA (3*main_matrica.size(),std::vector<double>(3*main_matrica[0].size()));
	for (int i=0; i<Kombinovano.size(); i++) {
		for (int j=0; j<Kombinovano.at(i).size(); j++) GOTOVA.at(i).at(j)=Kombinovano.at(i).at(j); 
	}
	for (int i=0; i<Vertikalno.size(); i++) {
		for (int j=0; j<Vertikalno.at(i).size(); j++) GOTOVA.at(i).at(j+Kombinovano.at(i).size())=Vertikalno.at(i).at(j);
	}
	for (int i=0; i<Kombinovano.size(); i++) {
		for (int j=0; j<Kombinovano.at(i).size(); j++) GOTOVA.at(i).at(j+Kombinovano.at(i).size()+Vertikalno.at(i).size())=Kombinovano.at(i).at(j);
	}
	for (int i=0; i<Horizontalno.size(); i++) {
		for (int j=0; j<Horizontalno.at(i).size(); j++) GOTOVA.at(i+Kombinovano.size()).at(j)=Horizontalno.at(i).at(j);
	}
	for (int i=0; i<OBICNA.size(); i++) {
		for (int j=0; j<OBICNA.at(i).size(); j++) GOTOVA.at(i+Kombinovano.size()).at(j+Horizontalno.at(i).size())=OBICNA.at(i).at(j);
	}
	for (int i=0; i<Horizontalno.size(); i++) {
		for (int j=0; j<Horizontalno.at(i).size(); j++) GOTOVA.at(i+Kombinovano.size()).at(j+Horizontalno.at(i).size()+OBICNA.at(i).size())=Horizontalno.at(i).at(j);
	}
	for (int i=0; i<Kombinovano.size(); i++) {
		for (int j=0; j<Kombinovano.at(i).size(); j++) GOTOVA.at(i+Kombinovano.size()+Horizontalno.size()).at(j)=Kombinovano.at(i).at(j);
	}
	for (int i=0; i<Vertikalno.size(); i++) {
		for (int j=0; j<Vertikalno.at(i).size(); j++) GOTOVA.at(i+Kombinovano.size()+Horizontalno.size()).at(j+Kombinovano.at(i).size())=Vertikalno.at(i).at(j);
	}
	for (int i=0; i<Kombinovano.size(); i++) {
		for (int j=0; j<Kombinovano.at(i).size(); j++) GOTOVA.at(i+Kombinovano.size()+Horizontalno.size()).at(j+Kombinovano.at(i).size()+Vertikalno.at(i).size())=Kombinovano.at(i).at(j);
	}
	return GOTOVA;
}
 
int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m(0),n(0);
	for (;;) {
		cin>>m;
		if (!cin) {
			cin.clear();
			cin.ignore(10000,'\n');
		}
		else break;
	}
	for (;;) {
		cin>>n;
		if (!cin) {
			cin.clear();
			cin.ignore(10000,'\n');
		}
		else break;
	}
	if (n<0 || m<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	Matrica main_matrica(m,std::vector<double>(n));
	cout<<"Unesite elemente matrice: ";
	for (int i=0; i<m; i++) 
		for (int j=0; j<n; j++) 
			cin>>main_matrica.at(i).at(j);
	cout<<std::endl;
	cout<<"Rezultantna matrica: \n";
	Matrica iz_funkcije;
	try {
		iz_funkcije=(OgledaloMatrica(main_matrica));
	}
	catch (std::domain_error izuzetak) {
 		cout << izuzetak.what() << std::endl;
	}
	for (auto red : iz_funkcije) {
		for (auto x : red) 
			cout<<std::setw(4)<<x;
		cout<<std::endl;
	}
	return 0;
}