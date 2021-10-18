/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;
typedef vector<vector<double>> matrica;

	int dajredove(matrica a){
		return a.size();
	}
	int dajkolone(matrica a){
		return a[0].size();
	}
	bool jeligrbava(matrica a){
		int pom=a[0].size();
		for(int i=1;i<a.size();i++){
			if(pom!=a.at(i).size())return true;
		}
		return false;
	}
	matrica unosmatrice(int redovi, int kolone){
		matrica a;
		a.resize(redovi);
		for(int i=0;i<redovi;i++)a.at(i).resize(kolone);
		for(int i=0;i<redovi;i++){
			for(int j=0;j<kolone;j++){
				cin>>a.at(i).at(j);
			}
		}
		return a;
	}
	
	matrica NajvecaPlaninaMatrice(matrica m){
		matrica nova;
		if(dajredove(m)==0 || dajkolone(m)==0)return nova;
		if(jeligrbava(m))throw domain_error("Matrica nije korektna");
		if(dajredove(m)<3){
			int max(m[0][0]);
			for(int i=0;i<dajredove(m);i++){
				for(int j=0;j<dajkolone(m);j++){
					if(m.at(i).at(j)>max)max=m.at(i).at(j);
				}
				
			}
			nova.resize(1);
			nova[0].resize(1);
			nova[0][0]=max;
			return nova;
			
		}

		
		
	}
	void ispismatrice(matrica a){
		for(int i=0;i<dajredove(a);i++){
			for(int j=0;j<dajkolone(a);j++)
			cout<<a.at(i).at(j);
			cout<<endl;
		}
	}
int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if(m<0 || n<0){cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;}
	matrica mat;
	cout<<"Unesite elemente matrice:"<<endl;
	mat=unosmatrice(m,n);
	
	if(m<3){
	cout<<"Najveca planina unesene matrice je: "<<endl<<setw(6);
	ispismatrice(NajvecaPlaninaMatrice(mat));
	}
	
	
	
	return 0;
}