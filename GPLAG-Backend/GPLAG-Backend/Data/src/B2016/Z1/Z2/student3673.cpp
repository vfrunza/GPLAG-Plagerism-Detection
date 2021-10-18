/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>


using namespace std;

typedef vector<vector<double>>Matrica;

Matrica OgledaloMatrica(Matrica m){
	if(m.size()==0){
		Matrica nula;
		return nula;
	}
	int br_red(m.size()),br_kol(m[0].size());
	for (int i=0;i<br_red-1;i++){
	if(m[i].size()!=m[i+1].size())throw domain_error("Matrica nije korektna");
	}
	Matrica m1(br_red,vector<double>(br_kol)),m2(br_red,vector<double>(br_kol)),m3(br_red,vector<double>(br_kol));
	for(int i=0;i<int(br_red);i++){
		for(int j=0;j<int(br_kol);j++){
			m1[i][j]=m[i][j];
			m2[i][j]=m[i][j];
		}
	}
	//pravi vertikalno ogledalo
	for(int i=0,j=int(br_red)-1;j>i;i++,j--){
	for(int k=0;k<int(br_kol);k++){
		double temp(m1[i][k]);
		m1[i][k]=m1[j][k];
		m1[j][k]=temp;
	}
	}
	//pravi horizontalno ogledalo
	for(int i=0,j=int(br_kol)-1;j>i;i++,j--){
		for(int k=0;k<int(br_red);k++){
			double temp(m2[k][i]);
			m2[k][i]=m2[k][j];
			m2[k][j]=temp;
		}
	}
	//prepisi u m3 clanove m2
	for(int i=0;i<int(br_red);i++){
		for(int j=0;j<int(br_kol);j++)
			m3[i][j]=m2[i][j];
		
	}
	//pravi hv ogledalo od m3
	for(int i=0,j=int(br_red)-1;j>i;i++,j--){
	for(int k=0;k<int(br_kol);k++){
		double temp(m3[i][k]);
		m3[i][k]=m3[j][k];
		m3[j][k]=temp;
	}
	}
	Matrica rez(3*br_red,vector<double>(3*br_kol));
	//popunjavanje matrice
	for(int i=0;i<int(br_red);i++){
		for(int j=0;j<int(br_kol);j++)rez[i][j]=m3[i][j];
	}
	for(int i=0;i<int(br_red);i++){
		for(int j=int(br_kol);j<2*int(br_kol);j++)rez[i][j]=m1[i][j-int(br_kol)];
	}
	for(int i=0;i<int(br_red);i++){
		for(int j=2*int(br_kol);j<3*int(br_kol);j++)rez[i][j]=m3[i][j-2*int(br_kol)];
	}
	for(int i=int(br_red);i<2*int(br_red);i++){
		for(int j=0;j<int(br_kol);j++)rez[i][j]=m2[i-int(br_red)][j];
	}
	for(int i=int(br_red);i<2*int(br_red);i++){
		for(int j=int(br_kol);j<2*int(br_kol);j++)rez[i][j]=m[i-int(br_red)][j-int(br_kol)];
	}
	for(int i=int(br_red);i<2*int(br_red);i++){
		for(int j=2*int(br_kol);j<3*int(br_kol);j++)rez[i][j]=m2[i-int(br_red)][j-2*int(br_kol)];
	}
	for(int i=2*int(br_red);i<3*int(br_red);i++){
		for(int j=0;j<int(br_kol);j++)rez[i][j]=m3[i-2*int(br_red)][j];
	}
	for(int i=2*int(br_red);i<3*int(br_red);i++){
		for(int j=int(br_kol);j<2*int(br_kol);j++)rez[i][j]=m1[i-2*int(br_red)][j-int(br_kol)];
	}
	for(int i=2*int(br_red);i<3*int(br_red);i++){
		for(int j=2*int(br_kol);j<3*int(br_kol);j++)rez[i][j]=m3[i-2*int(br_red)][j-2*int(br_kol)];
	}
	return rez;
}

int main ()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int a,b;
	cin>>a>>b;
	if(a<0 || b<0){cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	Matrica mat(a,vector<double>(b));
	cout<<"Unesite elemente matrice: ";
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>mat[i][j];
		}
	}
	try {
	Matrica rezultantna;
	rezultantna=OgledaloMatrica(mat);
	cout<<endl<<"Rezultantna matrica: "<<endl;
	for(int i=0;i<int(rezultantna.size());i++){
		for(int j=0;j<int(rezultantna[i].size());j++)
		cout<<setw(4)<<rezultantna[i][j];
		cout<<endl;
		
	}
		
	}
	catch(domain_error izuzetak){
		cout<<izuzetak.what();
	}
	
	return 0;
}