/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::domain_error;

vector<vector<double>> OgledaloMatrica(vector<vector<double>> Matrica){
	
	
	//domain_error
	if(Matrica.size()>0){
		int duzina=Matrica[0].size();
		for(int i=1; i<Matrica.size(); i++){
			if(Matrica[i].size()!=duzina){
				throw domain_error("Matrica nije korektna");
			}
		}
	}
	//domain_error2
	
	//horizontala
	vector<vector<double>> vertikala(Matrica);
	for(int i=0; i<Matrica.size(); i++){
		vertikala[i]=Matrica[Matrica.size()-1-i];
	}
	
	//vertikala
	vector<vector<double>> horizontala(Matrica);
	for(int i=0; i<Matrica.size(); i++){
		for(int j=0; j<Matrica[i].size(); j++){
			horizontala[i][j]=Matrica[i][Matrica[i].size()-1-j];
		}
	}
	
	//simetrala
	vector<vector<double>> simetrala(horizontala);
	for(int i=0; i<Matrica.size(); i++){
		simetrala[i]=horizontala[horizontala.size()-1-i];
	}
	
	//nova matrica
	vector<vector<double>> nova_matrica(3*Matrica.size(), vector<double>(0));
	
	//prvi red
	for(int i=0; i<nova_matrica.size()/3; i++){
		for(int j=0; j<simetrala[i].size(); j++){
			nova_matrica[i].push_back(simetrala[i][j]);
		}
		for(int j=0; j<vertikala[i].size(); j++){
			nova_matrica[i].push_back(vertikala[i][j]);
		}
		for(int j=0; j<simetrala[i].size(); j++){
			nova_matrica[i].push_back(simetrala[i][j]);
		}
	}
	
	//drugi red
	
	for(int i=0; i<nova_matrica.size()/3; i++){
		for(int j=0; j<horizontala[i].size(); j++){
			nova_matrica[i+nova_matrica.size()/3].push_back(horizontala[i][j]);
		}
		for(int j=0; j<Matrica[i].size(); j++){
			nova_matrica[i+nova_matrica.size()/3].push_back(Matrica[i][j]);
		}
		for(int j=0; j<horizontala[i].size(); j++){
			nova_matrica[i+nova_matrica.size()/3].push_back(horizontala[i][j]);
		}
	}
	
	//treci red
	for(int i=0; i<nova_matrica.size()/3; i++){
		for(int j=0; j<simetrala[i].size(); j++){
			nova_matrica[i+2*nova_matrica.size()/3].push_back(simetrala[i][j]);
		}
		for(int j=0; j<vertikala[i].size(); j++){
			nova_matrica[i+2*nova_matrica.size()/3].push_back(vertikala[i][j]);
		}
		for(int j=0; j<simetrala[i].size(); j++){
			nova_matrica[i+2*nova_matrica.size()/3].push_back(simetrala[i][j]);
		}
	}
	return nova_matrica;
	
}



int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	
	if(m<0 || n<0) {
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
	cout<<"Unesite elemente matrice: ";
	vector<vector<double>> Matrica(m,vector<double>(0));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			double element;
			cin>>element;
			Matrica[i].push_back(element);
		}
	}
	
	
	vector<vector<double>> Nova_Matrica;
	try{
		Nova_Matrica=OgledaloMatrica(Matrica);
		cout<<endl<<"Rezultantna matrica:"<<endl;
		for(int i=0; i<Nova_Matrica.size(); i++){
			for(int j=0; j<Nova_Matrica[i].size(); j++){
				cout<<setw(4)<<Nova_Matrica[i][j];
			}
			cout<<endl;
		}
	}
	catch(domain_error izuzetak) {
		cout<<izuzetak.what()<<endl;
	}
	
	
	return 0;
}