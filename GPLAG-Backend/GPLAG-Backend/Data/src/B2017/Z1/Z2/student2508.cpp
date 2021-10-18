#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdexcept>


using std::cout;
using std::cin;
using std::vector;
using std::endl;

constexpr double EPSILON = 0.00000000001;

double dajVrh(vector<vector<double>> planinaMatrica, int duzina,int i, int j){

	return planinaMatrica.at((i+duzina)/2).at((j+duzina)/2);
}

bool JeLiPlanina(vector<vector<double>> matrica,int i, int j, int duzina){
	int poz1((i+duzina)/2),poz2((j+duzina)/2); //poz vrha
	int k(1);
	double max(dajVrh(matrica,duzina,i,j));
	
	//k je brojac za koncentricne kvadrate
	while(k<=duzina/2){
		double zbir(0);
		for(int m(poz1-k); m<=poz1+k; m++){	//redovi
		
			//Svi redovi osim prvog i zadnjeg - Sabiramo samo elemente na ivici
			if(m!=poz1-k and m!=poz1+k){
				zbir+=matrica.at(m).at(poz2-k) + matrica.at(m).at(poz2+k);
				continue;
			}
			//Prvi i zadnji red
			for(int n(poz2-k); n<=poz2+k; n++){				zbir+=matrica.at(m).at(n);
			}
		}
		if(zbir>=max)
			return false;
		else
			max=zbir; //Sad poredimo slj koncentricnik vadrat sa trenutnim pa njega stavljamo na "max"
		k++;
	}

	
	return true;
}


vector<vector<double>> NajvecaPlaninaMatrice(vector<vector<double>> matrica){
	vector<vector<double>> najvecaPlanina;
	
	//Provjeravamo je li poslana prazna matrica, ako jeste vracamo kao rezultat opet praznu matricu
	if(matrica.size()==0) return najvecaPlanina;
	

	//Uzimamo broj kolona prvog reda i poredimo sa svim drugim redovima da provjerimo dal i je matrica grbava
	int brojKolona = matrica.at(0).size();
	
	for(int i=1; i<matrica.size(); i++){
		if(matrica.at(i).size()!=brojKolona) throw std::domain_error("Matrica nije korektna");
	}

	//Najveci neparni (uzimamo najmanji od najveceg neparnog redova i najveceg neparnog kolona) 
	
	int najveciNeparni = matrica.size();
	if(matrica.at(0).size()<najveciNeparni)
		najveciNeparni=matrica.at(0).size();
		
	if(najveciNeparni%2==0) najveciNeparni--;
	
	//Pocetne pozicije planine
	int poz1(-1),poz2(-1);
	double max;
	
	while(poz1==-1 and najveciNeparni>=1){			//probavamo sa najvecim mogucim dimenzijama, pa ako nema uopste planina, idemo nize
		for(int i=0; i<=matrica.size()-najveciNeparni; i++){
			for(int j=0; j<=matrica.at(i).size()-najveciNeparni; j++){
				if(JeLiPlanina(matrica,i,j,najveciNeparni)){
					if(poz1==-1 || dajVrh(matrica,najveciNeparni,i,j)>max){	//Ako nijedna planina jos nije pronadjena ili ako je vrh trenutne veci od do sad najvece, onda postavi tu kao najvecu planinu
						poz1=i;
						poz2=j;
						max=dajVrh(matrica,najveciNeparni,i,j);
					}
	
				}
			}
		}
		if(poz1==-1)
			najveciNeparni-=2;
	}
	
	//Sada kada imamo koordinate i velicinu najvece planine, samo je umetnemo u rezultat i vratimo
	if(poz1!=-1){
		najvecaPlanina.resize(najveciNeparni);
		for(int i=poz1; i<poz1+najveciNeparni; i++){
			for(int j=poz2; j<poz2+najveciNeparni; j++){
				najvecaPlanina.at(i-poz1).push_back(matrica.at(i).at(j));
			}
		}
	}

	
	return najvecaPlanina;
	
}


int main ()
{
	cout<<"Unesite dimenzije matrice (m i n): ";
	int m(0),n(0);
	cin>>m>>n;
	if(m<=0 or n<=0){
		cout<<"Dimenzije matrice moraju biti nenegativne! ";
		return 0;
	}
		
	cout<<"Unesite elemente matrice: ";
	vector<vector<double>> matrica(m,vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cin>>matrica.at(i).at(j);
	}
	cout<<endl<<"Najveca planina unesene matrice je: "<<endl;
	
	vector<vector<double>> rez(NajvecaPlaninaMatrice(matrica));
	for(int i=0; i<rez.size(); i++){
		for(int j=0; j<rez.at(0).size(); j++){
			cout<<std::setw(6)<<rez.at(i).at(j);
		}
		cout<<endl;
	}

	return 0;
}