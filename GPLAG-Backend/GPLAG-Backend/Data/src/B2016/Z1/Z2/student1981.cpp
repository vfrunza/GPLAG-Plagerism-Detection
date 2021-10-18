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

typedef vector<vector<double>> Matrica;

Matrica Kreiraj(double red, double kolona) {
	return Matrica(red,vector<double> (kolona));
}

Matrica OgledaloMatrica (Matrica n) {
	if(n.size()==0) {
		Matrica nula(Kreiraj(0,0));
		return nula;
	}
	
	for(int i=0; i<n.size(); i++) 
		if(n[0].size()!=n[i].size()) throw std::domain_error ("Matrica nije korektna");
	
	
	Matrica a(Kreiraj(n.size(),n[0].size())),b(Kreiraj(n.size(),n[0].size()));
	Matrica c(Kreiraj(n.size(),n[0].size())),nova(Kreiraj(n.size()*3,n[0].size()*3));

	

	
	int p(n.size()-1);
	int q(n[0].size()-1);
	for(int i=0; i<n.size(); i++) {
		q=n[0].size()-1;
		for(int j=0; j<n[0].size(); j++) {
			a[i][j]=n[p][q];
			q--; 
			
		}
		p--;
	}
	p=n.size()-1;
	for(int i=0; i<n.size(); i++) {
		for(int j=0; j<n[i].size(); j++) {
			b[i][j]=n[p][j];
			
			
		}
		p--;
	}
	
	for(int i=0; i<n.size(); i++) {
		q=n[0].size()-1;
		for(int j=0; j<n[i].size(); j++) {
			c[i][j]=n[i][q];
			q--;
			
		}
		
	}
	
	int f,g;
	f=n[0].size();
	g=n.size();
	for(int i=0; i<n.size(); i++) {
		for(int j=0; j<n[0].size(); j++) {
			nova[i][j]=a[i][j];
			nova[g+i][j]=c[i][j];
			nova[g*2+i][j]=a[i][j];
			
			nova[i][f+j]=b[i][j];
			nova[i][f*2+j]=a[i][j];
			
			nova[g+i][f+j]=n[i][j];
			
			nova[g*2+i][f*2+j]=a[i][j];
			
			nova[g*2+i][f+j]=b[i][j];
			
			nova[g+i][f*2+j]=c[i][j];
			
			
		}
	
	}
	
	
	return nova;
	
}

int main ()
{
	try{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0) { cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	
	cout<<"Unesite elemente matrice: ";
	Matrica a(Kreiraj(m,n));
	
	for(int i=0; i<a.size(); i++) 
		for(int j=0; j<a[i].size(); j++) 
			cin>>a[i][j];
	
	cout<<endl<<"Rezultantna matrica: "<<endl;
	for(int i=0; i<OgledaloMatrica(a).size(); i++) {
		for(int j=0; j<OgledaloMatrica(a)[i].size(); j++) 
			cout<<setw(4)<<OgledaloMatrica(a)[i][j];
	cout<<endl;
	}
	
	}
	catch (std::domain_error izuzetak) {
		cout<<izuzetak.what();
	}
	
	
	return 0;
}





