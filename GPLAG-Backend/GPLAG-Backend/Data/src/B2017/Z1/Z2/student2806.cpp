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
#include <stdexcept>
using namespace std; //papak sam
typedef vector<vector<double>> Matrica;

bool JeLiPlanina(Matrica m, int pocx, int pocy, int krajx, int krajy){
	int srednjix((pocx+krajx)/2);
	int srednjiy((pocy+krajy)/2);
	double S(0);//pomocni element za sumiranje
	int n(1); 
	double a(m.at(srednjix).at(srednjiy));//a je vrijednost sred. elementa
	
	
	while(n<=srednjix-pocx) {
		S=0;
		for(int i=srednjix-n; i<=srednjix+n; i++){
			for(int j=srednjiy-n; j<=srednjiy+n; j++){
				if(i==srednjix-n || i==srednjix+n || j==srednjix-n || j==srednjiy+n) 
				S=S+m.at(i).at(j);//sabira sve elemente u krugu oko srednjeg ukljucujuci i njega
			}
		}
		if(S>a) return false;
		a=S;//sad a=S da bi mogla poredit opet
		n++;
	}
	return true;
}

Matrica NajvecaPlaninaMatrice(Matrica m){
	Matrica planina;
	int pocx(0), pocy(0), krajx(0), krajy(0), duzina(3), pom(0);//pom cuva vr najv do tada nadjene planine
	bool da(false);//u pocetku nema planine
	
	Matrica prazna;
	if(m.size()==0 || m[0].size()==0) {
		return prazna;
	}
	for(int i(0); i<m.size(); i++){
		if(m.at(i).size()!=m.at(0).size()) throw domain_error("Matrica nije korektna");
	}
	while(duzina<=m.size() && duzina<=m.at(0).size()){
	for(int i(0); i<m.size()-duzina+1; i++){//ide po i sve do treceg odzada, povecavat ce se duzina 3,5,7...
		for(int j(0); j<m.at(0).size()-duzina+1; j++){//krece se po j
			da=JeLiPlanina(m, i, j, i+duzina-1, j+duzina-1);
			if(duzina>pom){//sacuva sve koordinate samo za najvecu do tad planinu 
			if(da){
				pocx=i;
				pocy=j;
				krajx=i+duzina-1;
				krajy=j+duzina-1;//kad nadjemo planinu cuvamo kordinate krajeva matrice planine
				pom=duzina;
			}
			}
			da=false;
			
		}
	}
		duzina+=2;
	}
	vector<double> pom1; 
	for(int i=pocx; i<=krajx; i++){
		for(int j=pocy; j<=krajy; j++){
			pom1.push_back(m.at(i).at(j));
		}
		planina.push_back(pom1);
		pom1.resize(0);
	} 
  if(planina.size()==1) {
  	double pom2(planina.at(0).at(0));
  	for(int i(0); i<m.size(); i++){
  		for(int j(0); j<m.at(0).size(); j++){
  			if(m.at(i).at(j)>pom2) {
  				
  				planina.at(0).at(0)=m.at(i).at(j);
  			}
  		}
  	}
  }
	return planina;
}

int main ()
{
	int m, n;
	
	cout<<"Unesite dimenzije matrice (m i n): ";
	cin>>m>>n;
	if(m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";	
		return 0;
	}
	
	Matrica mat(m);
	for(int i(0); i<m; i++) {
		mat.at(i).resize(n);
	}
	if(n>0 && m>0){
	cout<<"Unesite elemente matrice:";
	for(int i(0); i<m; i++){
		for(int j(0); j<n; j++){
			cin>>mat.at(i).at(j);
		}
	}
	
	
	Matrica test2(NajvecaPlaninaMatrice(mat));
	cout<<endl<<"Najveca planina unesene matrice je:"<<endl;
	for(int i(0); i<test2.size(); i++){
		for(int j(0); j<test2.at(0).size(); j++){
			cout<<setw(6)<<test2.at(i).at(j);
		}
		cout<<endl;
	}
}
	return 0;
}