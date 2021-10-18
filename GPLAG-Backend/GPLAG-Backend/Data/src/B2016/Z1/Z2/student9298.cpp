/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica(Matrica kopija){
	try{
		Matrica finalna;
		if(kopija.size()==0) throw kopija;
		// ispitivanje grbave matrice
		for(int i=0; i< kopija.size(); i++){
			if(kopija[0].size() != kopija[i].size() ) throw std::domain_error("Matrica nije korektna");
		}
		//horizontalna matrica
		Matrica horizontalna;
		horizontalna.resize(kopija.size()); //pravljenje dimenzija matrice
		for(int i=0; i<horizontalna.size();i++) horizontalna[i].resize(kopija[0].size());
		//stavljanje elemenata u matricu(horizontalna)
		for(int i=0; i<horizontalna.size() ; i++){
			for(int j=0 ; j<horizontalna[i].size() ; j++){
				horizontalna[i][j]=kopija[i][kopija[0].size() - 1 - j];
			} 
		}
		// vertikalna matrica
		Matrica vertikalna;
		vertikalna.resize(kopija.size());
		for(int i=0; i<vertikalna.size() ; i++) vertikalna[i].resize(kopija[0].size());
		// stavljanje elemenata
		for(int i=0 ; i<vertikalna.size() ; i++){
			for(int j=0 ; j<vertikalna[i].size() ; j++){
				vertikalna[i][j] = kopija[kopija.size() - 1 - i][j] ;
			}
		}
		// matrica kombinovana
		Matrica kombinovana;
		kombinovana.resize(kopija.size());
		for(int i=0; i<kombinovana.size() ; i++) kombinovana[i].resize(kopija[0].size());
		for(int i=0; i<kombinovana.size() ; i++){
			for(int j=0; j<kombinovana[i].size() ; j++){
				kombinovana[i][j] = kopija [kopija.size() - 1 - i][kopija[0].size() - 1 - j];
			}
		}
		// Za laksi rad for petljom , redove i kolone na broj
		int a_1,a_2,a_3,b_1,b_2,b_3;
		a_1 = kopija.size();
		a_2 = (2* a_1);
		a_3 = (3* a_1);
		b_1 = kopija[0].size();
		b_2 = (2* b_1);
		b_3 = (3* b_1);
		// GLAVNA MATRICA 3 for(for) petlje
		finalna.resize(a_3);
		for(int i=0; i< finalna.size() ; i++) finalna[i].resize(b_3);
		
		for(int i=0; i<a_1 ; i++){
			for(int j=0 ; j<b_3 ; j++){
				if(j<b_1){
					finalna[i][j]=kombinovana[i][j];
				}
				else if(j<b_2){
					finalna[i][j]=vertikalna[i][j - b_1];
				}
				else{
					finalna[i][j]=kombinovana[i][j - b_2];
				}
			}
		}
		// Drugi red
		for(int i=a_1; i<a_2 ; i++){
			for(int j=0 ; j<b_3 ; j++){
				if(j<b_1){
					finalna[i][j]=horizontalna[i - a_1][j];
				}
				else if(j<b_2){
					finalna[i][j]=kopija[i - a_1][j - b_1];
				}
				else{
					finalna[i][j]=horizontalna[i - a_1][j - b_2];
				}
			}
		}
		
		// Treci Red
		for(int i=a_2; i<a_3 ; i++){
			for(int j=0 ; j<b_3 ; j++){
				if(j<b_1){
					finalna[i][j]=kombinovana[i - a_2][j];
				}
				else if(j<b_2){
					finalna[i][j]=vertikalna[i - a_2][j - b_1];
				}
				else{
					finalna[i][j]=kombinovana[i - a_2][j - b_2];
				}
			}
		}
		
		//KRAJ
		return finalna;
	}
	catch(Matrica a){
		Matrica finalna;
		return finalna;
	}
}
int main ()
{
	try{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m >> n;
	if(m<0 || n<0) throw m;
	Matrica nova(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<nova.size() ; i++)
	{
		for(int j=0; j<nova[i].size() ; j++)
		{
			double a;
			std::cin>>a;
			nova[i][j]=a;
			
		}
	}
	Matrica prava;
	prava=OgledaloMatrica(nova);
	std::cout<< std::endl <<"Rezultantna matrica: " << std::endl;
	for(int i=0;i<prava.size() ; i++)
	{
		for(int j=0; j<prava[i].size() ; j++)
		{
			std::cout<<std::setw(4) <<  prava[i][j];
			
		}
		std::cout<<std::endl;
	}
	
	return 0;
	}
	catch(int n){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
}