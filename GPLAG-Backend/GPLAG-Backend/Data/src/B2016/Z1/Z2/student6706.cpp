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
typedef vector<vector<double>> mat;
mat OgledaloMatrica(mat c){
	for(int i=0;i<c.size();i++)
    if(c[0].size()!=c[i].size()) throw domain_error("Matrica nije korektna");
	
	
	if(c.size()==0) return c;
	//horizontalna
	mat h(c.size(),vector<double>(c[0].size()));
	for(int i=0; i<c.size();i++){
		for(int j=0; j<c[i].size();j++){
			h[i][j]=c[i][j];
		}
	}
	double pomocna;
	for(int i=0; i<h.size(); i++){
		int j=0;
		while(j<h[i].size()/2){
			pomocna=h[i][j];
			h[i][j]=h[i][h[i].size()-j-1];
			h[i][h[i].size()-j-1]=pomocna;
			j++;
		}
	}
	//vertikalna
	mat v(c.size(),vector<double>(c[0].size()));
	for(int i=0; i<c.size();i++){
		for(int j=0; j<c[i].size();j++){
			v[i][j]=c[i][j];
		}
	}
	for(int i=0; i<v.size()/2;i++){
		for(int j=0; j<v[i].size();j++){
			pomocna=v[i][j];
			v[i][j]=v[v.size()-i-1][j];
			v[v.size()-i-1][j]=pomocna;
		}
	}
	//horizontalna i vertikalna
	mat hv(c.size(),vector<double>(c[0].size()));
	for(int i=0; i<hv.size();i++){
	for(int j=0; j<hv[i].size(); j++){
		hv[i][j]=h[i][j];
        }
	}
	for(int i=0; i<hv.size()/2;i++){
		for(int j=0; j<hv[i].size();j++){
			pomocna=hv[i][j];
			hv[i][j]=hv[hv.size()-i-1][j];
			hv[hv.size()-i-1][j]=pomocna;
		}
	}
	//ogledalo matrica
	mat ogledalo(3*c.size(),vector<double>(3*c[0].size()));
	int m=c.size(), n=c[0].size();
	//hv
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			ogledalo[i][j]=hv[i][j];
		}
	}
	//v
	for(int i=0; i<m; i++){
		int k=0;
		for(int j=n; j<2*n; j++){
			ogledalo[i][j]=v[i][k];
			k++;
		}
	}
	//hv
	for(int i=0; i<m; i++){
		int k=0;
		for(int j=2*n; j<3*n; j++){
			ogledalo[i][j]=hv[i][k];
			k++;
		}
	}
	//h
	int b=0;
	for(int i=m; i<2*m; i++){
		int k=0;
		for(int j=0; j<n; j++){
			ogledalo[i][j]=h[b][k];
			k++;
		}
		b++;
	}
	//prvobitna matrica
	 b=0;
	for(int i=m; i<2*m; i++){
		int k=0;
		for(int j=n; j<2*n; j++){
			ogledalo[i][j]=c[b][k];
			k++;
		}
		b++;
	}
	//h
	 b=0;
	for(int i=m; i<2*m; i++){
		int k=0;
		for(int j=2*n; j<3*n; j++){
			ogledalo[i][j]=h[b][k];
			k++;
		}
		b++;
	}
	//hv
	b=0;
	for(int i=2*m; i<3*m; i++){
		int k=0;
		for(int j=0; j<n; j++){
			ogledalo[i][j]=hv[b][k];
			k++;
		}
		b++;
	}
	//v
	b=0;
	for(int i=2*m; i<3*m; i++){
		int k=0;
		for(int j=n; j<2*n; j++){
			ogledalo[i][j]=v[b][k];
			k++;
		}
		b++;
	}
	//hv
	b=0;
	for(int i=2*m; i<3*m; i++){
		int k=0;
		for(int j=2*n; j<3*n; j++){
			ogledalo[i][j]=hv[b][k];
			k++;
		}
		b++;
	}
	return ogledalo;
	
}

int main (){
	try{
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	mat c(m,vector<double>(n));
	cout<<"Unesite elemente matrice: "<<endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>c[i][j];
		}
	}
	mat nova=OgledaloMatrica(c);
	cout<<"Rezultantna matrica: "<<endl;
	for(int i=0; i<nova.size();i++){
		for(int j=0; j<nova[i].size();j++)
		cout<<setw(4)<<nova[i][j];
		cout<<endl;
		}
	}
	catch(domain_error izuzetak){
	cout<<"Izuzetak: "<<izuzetak.what()<<endl;
}
	return 0;
}