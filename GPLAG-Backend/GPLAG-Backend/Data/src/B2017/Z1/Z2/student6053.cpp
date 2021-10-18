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
#include <iomanip>
#include<stdexcept>

using namespace std;

typedef vector<vector<double>> matrica;

matrica KreirajMatricu(int br_redova, int br_kolona){
	return matrica(br_redova, vector<double>(br_kolona));
}
int BrojRedova(matrica m){
	return m.size();
}
int BrojKolona(matrica m){
	return m[0].size();
}
matrica UnesiMatricu(int br_redova,int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0;i<br_redova;i++)
	for(int j=0;j<br_kolona;j++){
		cin>>m.at(i).at(j);
	}
	return m;
}
void IspisiMatricu(matrica m){
	for(int i=0;i<BrojRedova(m);i++){
		for(int j=0;j<BrojKolona(m);j++)
		cout<<setw(6)<<m.at(i).at(j);
		cout<<endl;
	}
}

matrica NajvecaPlaninaMatrice(matrica m){

		for(int i=0;i<m.size();i++){
		if(m.at(0).size()!=m.at(i).size()) throw domain_error("Matrica nije korektna");
	}
  
	if(BrojRedova(m)==1 || BrojRedova(m)==1 || BrojKolona(m)==2 || BrojKolona(m)==2){
	 auto max =	KreirajMatricu(1,1);
		max.at(0).at(0)=m[0][0];
		for(int i=0;i<BrojRedova(m);i++){
			for(int j=0;j<BrojKolona(m);j++){
				if(max.at(0).at(0)<m.at(i).at(j)) max.at(0).at(0)=m.at(i).at(j);
			}
		}
		return max;
	}
	//auto vrh = KreirajMatricu(1,1);
	//vrh[0][0]=m[0][0];
	int pocetak=0,velicina=0;
	for(int i=1;i<BrojRedova(m)-1;i++){
		for(int j=1;j<BrojKolona(m)-1;j++){
			if(m.at(i).at(j)>(m.at(i-1).at(j-1)+m.at(i-1).at(j)+m.at(i-1).at(j+1)+m.at(i).at(j-1)+m.at(i).at(j+1)+m.at(i+1).at(j-1)+m.at(i+1).at(j)+m.at(i+1).at(j+1))){
				pocetak = (i-1); velicina=3;
				
			} 
		}
	}
	auto rezultat=KreirajMatricu(velicina,velicina);
	for(int i=pocetak;i<pocetak+velicina;i++){
		for(int j=pocetak;j<pocetak+velicina;j++){
			rezultat.at(i).at(j)=m.at(i).at(j); //l++;
		}
		//k++;
	}
	
	
	
	
	return rezultat;
}


int main ()
{
	cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0){ cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	cout<<"Unesite elemente matrice: ";
	auto M(UnesiMatricu(m,n));
	cout<<endl;
	cout<<"Najveca planina unesene matrice je: "<<endl;
	try{
	IspisiMatricu(NajvecaPlaninaMatrice(M));
	}
	catch(domain_error izuzetak) {
   cout<<izuzetak.what()<<endl;
	}
	return 0;
}