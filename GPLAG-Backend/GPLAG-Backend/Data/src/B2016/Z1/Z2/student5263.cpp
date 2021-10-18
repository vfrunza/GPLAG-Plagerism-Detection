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
using std::vector;
using std::endl;
using std::setw;
using std::domain_error;
vector<vector<double>> OgledaloMatrica (vector<vector<double>> m){
	if (m.size()==0) return m;
	vector<vector<double>> hm;
	vector<vector<double>> vm;
	vector<vector<double>> mm;
	hm=m;
	vm=m;
	mm=m;
	for(int i=0;i<m.size();i++){
		if(m[0].size()!=m[i].size()) throw domain_error ("Matrica nije korektna");
	}
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size()/2;j++){
			double temp;
			temp=hm[i][j];
			hm[i][j]=hm[i][m[i].size()-1-j];
			hm[i][m[i].size()-1-j]=temp;
		}
	}
	for(int i=0;i<m.size()/2;i++){
		for(int j=0;j<m[i].size();j++){
			double temp;
			temp=vm[i][j];
			vm[i][j]=vm[m.size()-1-i][j];
			vm[m.size()-1-i][j]=temp;
		}
	}
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size()/2;j++){
			double temp;
			temp=mm[i][j];
			mm[i][j]=mm[i][m[i].size()-1-j];
			mm[i][m[i].size()-1-j]=temp;
		}
	}
	for(int i=0;i<m.size()/2;i++){
		for(int j=0;j<m[i].size();j++){
			double temp;
			temp=mm[i][j];
			mm[i][j]=mm[m.size()-1-i][j];
			mm[m.size()-1-i][j]=temp;
		}
	}
	vector<vector<double>> matrica(3*m.size(),vector<double>(3*m[0].size(),0));
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i][j]=mm[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i][j+m[0].size()]=vm[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i][j+2*m[0].size()]=mm[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i+m.size()][j]=hm[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i+m.size()][j+m[0].size()]=m[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i+m.size()][j+2*m[0].size()]=hm[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i+2*m.size()][j]=mm[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i+2*m.size()][j+m[0].size()]=vm[i][j];
		}
	}
	for (int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			matrica[i+2*m.size()][j+2*m[0].size()]=mm[i][j];
		}
	}
	return matrica;
}
int main ()
{
	try{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if (m<0 || n<0) {cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	cout<<"Unesite elemente matrice:"<<endl;
	vector<vector<double>> matrica(m, vector<double> (n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>matrica[i][j];
		}
	}
	vector<vector<double>> novamatrica=OgledaloMatrica(matrica);
	cout<<"Rezultantna matrica:"<<endl;
	for(int i=0;i<novamatrica.size();i++){
		for(int j=0;j<novamatrica[0].size();j++){
			cout<<setw(4)<<novamatrica[i][j];
		}cout<<endl;
	}
	}
	catch(...){
		cout<<"Matrica nije korektna";
	}
	return 0;
}