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
typedef std::vector<std::vector<double>> Matrica;
using std::cin;
using std::cout;
using std::endl;

Matrica HorizontalnoVertikalna(Matrica m){
	Matrica a;
	a.resize(m.size());
	int kolone=m[0].size(), redovi=m.size();
	for (int i=0; i<redovi; i++) a[i].resize(kolone);
	for (int i=0; i<redovi; i++){
		for (int j=0; j<kolone; j++){
			a[i][j]=m[redovi-1-i][kolone-j-1];
		}
	}
	return a;
}
Matrica Vertikalna(Matrica m){
	Matrica a;
	int kolone=m[0].size(), redovi=m.size();
	a.resize(redovi);
	for (int i=0; i<redovi; i++) a[i].resize(kolone);
	for(int i=0; i<redovi;i++){
		for (int j=0; j<kolone;j++){
			a[i][j]=m[redovi-1-i][j];
		}
	}
	return a;
}
Matrica Horizontalna(Matrica m){
	Matrica a;
	int kolone=m[0].size(), redovi=m.size();
	a.resize(redovi);
	for (int i=0; i<redovi; i++) a[i].resize(kolone);
	for(int i=0; i<redovi;i++){
		for (int j=0; j<kolone;j++){
			a[i][j]=m[i][kolone-1-j];
		}
	}
	return a;
}
Matrica OgledaloMatrica(Matrica m){
	Matrica ogledalo;
	if (m.size()>0 && m[0].size()>0){
	int a=m.size(), b=m[0].size();
	int c=3*a;
	ogledalo.resize(c);
	for (int i=0; i<c; i++) ogledalo[i].resize(3*b);
	Matrica hv(HorizontalnoVertikalna(m));
	Matrica h(Horizontalna(m));
	Matrica v(Vertikalna(m));
	for (int i=0; i<a; i++){
		for (int j=0; j<3*b; j++){
			if (j<b) ogledalo[i][j]=hv[i][j];
			else if (j>=b && j<2*b) ogledalo[i][j]=v[i][j-b];
			else if (j>=2*b) ogledalo[i][j]=hv[i][j-2*b];
			
		}
	}
	for (int i=a; i<2*a; i++){
		for (int j=0; j<3*b; j++){
			if(j<b) ogledalo[i][j]=h[i-a][j];
			else if(j>=b && j<2*b) ogledalo[i][j]=m[i-a][j-b];
			else if (j>=2*b) ogledalo[i][j]=h[i-a][j-2*b];
		}
	}
	for (int i=2*a; i<3*a; i++){
		for (int j=0; j<3*b; j++){
			if (j<b) ogledalo[i][j]=hv[i-2*a][j];
			else if (j>=b && j<2*b) ogledalo[i][j]=v[i-2*a][j-b];
			else if (j>=2*b) ogledalo[i][j]=hv[i-2*a][j-2*b];
		}
	}
	}
	return ogledalo;
}

int main ()
{
	try{
	int a,b;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>a>>b;
	if (a<0 || b<0){
		throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	}
	cout<<"Unesite elemente matrice: ";
	Matrica m;
	m.resize(a);
	for (int i=0; i<a; i++){ 
		m[i].resize(b);
	}
	for(int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			cin>>m[i][j];
		}
	}
	cout<<endl;
	for (int i=0; i<a; i++){
	if (m[i].size()!=b) throw std::domain_error("Matrica nije korektna");
	}
	Matrica ogledalo=OgledaloMatrica(m);
	
	cout<<"Rezultantna matrica: "<<endl;
	for (int i=0; i<ogledalo.size(); i++){
		for (int j=0; j<ogledalo[0].size(); j++){
			cout<<std::setw(4)<<ogledalo[i][j];
		}
		cout<<endl;
	}
	}
	catch (std::domain_error x){
		std::cout<<x.what();
	}
	return 0;
}