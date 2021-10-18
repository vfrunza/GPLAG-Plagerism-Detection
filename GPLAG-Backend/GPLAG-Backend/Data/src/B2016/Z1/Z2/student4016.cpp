/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include <iomanip>
using namespace std;
typedef vector<vector<int>> Matrica;

Matrica OgledaloMatrica (Matrica M){
	if(M.size()==0) return M;
	for (int k=0; k<M.size(); k++){
			if(M[k].size()!=M[0].size())
			throw domain_error("Matrica nije korektna");
		} 
	Matrica h(M.size(), vector<int> (M[0].size()));
	for (int i=0; i<M.size(); i++){
		for (int j=0; j<M[0].size(); j++){
			h[i][j]=M[i][M[i].size()-1-j];
		}

	}
		Matrica v(M.size(), vector<int>( M[0].size()));
		for(int i=0; i<M.size();  i++){
			for (int j=0; j<M[i].size(); j++){
				v[i][j]=M[M.size()-1-i][j];
		}
	
	}
		Matrica hv(M.size(), vector<int>( M[0].size()));
		for (int i=0; i<h.size(); i++){
			for (int j=0; j<h[0].size(); j++){
				hv[i][j]=h[M.size()-1-i][j];
			}
		}
		cout<<endl;
		Matrica pomocni(3*M.size(), vector<int> (3*M[0].size()));
		
		int visina=pomocni.size();
		int sirina=pomocni[0].size();
		int bred, bkol;
		for (int i=0; i<3*M.size(); i++){
			for (int j=0; j<3*M[0].size(); j++){
				
				if (i>=M.size()) bred=i%M.size();
				else if(i<M.size())  bred=i;
				if (j>=M[0].size() )  bkol=j%M[0].size();
				else if (j<M[0].size())  bkol=j;
				//hv
				if((i<visina/3 && j<sirina/3) || (i<visina && i>=2*visina/3 && j<sirina && j>=2*sirina/3) || (i<visina && i>=2*visina/3 && j<sirina/3) || (i<visina/3  && j<sirina && j>=2*sirina/3))
				  {pomocni[i][j]=hv[bred][bkol];}
				//h
				else if(i>=visina/3 && i<2*visina/3 && (j<sirina/3 || j>=2*sirina/3) )
				{pomocni [i][j]=h[bred][bkol];}
				//v
				else if(j>=sirina/3 && j<2*sirina/3 && (i<visina/3 || i>=2*visina/3))
				{pomocni[i][j]=v[bred][bkol]; }
	        	else {pomocni[i][j]=M[bred][bkol];}
				
			}
		}
		
		return pomocni;
}


int main (){
	int m, n;
	cout <<"Unesite dimenzije matrice (m n): ";
	cin >>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice:\n";
	Matrica M(m, vector<int>(n));
	for (int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>M[i][j];
		}
	}
	Matrica ma=OgledaloMatrica(M);
	cout <<"Rezultantna matrica:\n";
	for(int i=0; i<ma.size(); i++){
		for( int j=0; j<ma[0].size(); j++){
			cout<< setw(4)<<ma[i][j];
		}
		cout<<endl;
	}
	return 0;
}