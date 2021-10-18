/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
using namespace std;
typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu(int broj_redova,int broj_kolona){
	return Matrica(broj_redova,vector<double>(broj_kolona));
}
int BrojRedova(Matrica m){
	return m.size();
}
int BrojKolona(Matrica m){
	if(m.size()==0) return 0;
	else 
	return m[0].size();
}
Matrica UnesiMatricu(int broj_redova,int broj_kolona){
	
	Matrica m(KreirajMatricu(broj_redova,broj_kolona));
	for(int i=0;i<broj_redova;i++)
	for(int j=0;j<broj_kolona;j++){
		cin>>m[i][j];
	}
	return m;
}
Matrica Horizontalna(Matrica m){
	auto h(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	for(int i=0;i<BrojRedova(m);i++)
	for(int j=0;j<BrojKolona(m);j++){ h[i][j]=m[i][m[i].size()-1-j];
		
	}
	return h;
}
Matrica Vertikalna(Matrica m){
	auto v(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	for(int i=0;i<BrojRedova(m);i++)
	for(int j=0;j<BrojKolona(m);j++){ v[i][j]=m[m.size()-1-i][j];
}
return v;
}

Matrica HorizontalnaVertikalna(Matrica m){
	auto h_v(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	auto pom=Horizontalna(m);

	h_v=Vertikalna(pom);
	
	return h_v;
}

Matrica Obicna(Matrica m){
	auto isti(KreirajMatricu(BrojRedova(m),BrojKolona(m)));
	for(int i=0;i<BrojRedova(m);i++)
	for(int j=0;j<BrojKolona(m);j++){ isti[i][j]=m[i][j];
}
return isti;
}

Matrica OgledaloMatrica(Matrica m){
	

	auto ogledalce(KreirajMatricu(3*BrojRedova(m),3*BrojKolona(m)));
	
	auto m_pom_1 = HorizontalnaVertikalna(m);
	auto m_pom_2 = Horizontalna(m);
	auto m_pom_3 = Vertikalna(m);
	auto m_pom_4 = Obicna(m);
	
	for(int i=0;i<m.size();i++){
		if(m[0].size()!=m[i].size()) throw domain_error("Matrica nije korektna");
	}
	
	for(int i=0;i<3*BrojRedova(m);i++)
	for(int j=0;j<3*BrojKolona(m);j++){
	if((i<BrojRedova(m) && j<BrojKolona(m)) || (i>=2*BrojRedova(m) && j<BrojKolona(m)) || (i<BrojRedova(m)&&j>BrojKolona(m)) || (i>BrojRedova(m) && j>BrojKolona(m))){
		ogledalce[i][j] = m_pom_1[i%BrojRedova(m)][j%BrojKolona(m)];
	}	
	if((i>=BrojRedova(m) && i<2*BrojRedova(m) && j<BrojKolona(m)) || (i>=BrojRedova(m) && i<2*BrojRedova(m) && j>=2*BrojKolona(m))){
		ogledalce[i][j] = m_pom_2[i%BrojRedova(m)][j%BrojKolona(m)];
	}
	if((i<BrojRedova(m)&&j>=BrojKolona(m)&&j<2*BrojKolona(m)) || (i>=2*BrojRedova(m)&&j>=BrojKolona(m)&&j<2*BrojKolona(m))){
	ogledalce[i][j]=m_pom_3[i%BrojRedova(m)][j%BrojKolona(m)];
}
if(i>=BrojRedova(m)&&i<2*BrojRedova(m)&&j>=BrojKolona(m)&&j<2*BrojKolona(m)){
ogledalce[i][j] =m_pom_4[i%BrojRedova(m)][j%BrojKolona(m)];
}

}
	return ogledalce;
}

void IspisiMatricu(Matrica m){ 
    for(int i=0; i<BrojRedova(m);i++){
    for(int j=0; j<BrojKolona(m);j++)
    cout <<setw(4)<< m[i][j] ;
    cout<<endl;
    }
}
int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne! ";
		return 0;
	}
	cout<<"Unesite elemente matrice: ";
	auto M(UnesiMatricu(m,n));
	cout<<endl;
	Horizontalna(M);
	Vertikalna(M);
	HorizontalnaVertikalna(M);
	Obicna(M);
	cout<<"Rezultantna matrica: "<<endl;
	try{
	IspisiMatricu(OgledaloMatrica(M));
	}
   catch(domain_error izuzetak) {
   cout<<izuzetak.what()<<endl;
}

	return 0;
}