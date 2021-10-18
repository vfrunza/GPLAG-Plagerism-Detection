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

using namespace std;
typedef vector<vector<double>> Matrica;

Matrica KreirajMatricu(int a, int b) {
   return Matrica (a,vector<double>(b));
}

Matrica Kombinovano(Matrica m){
    Matrica s(KreirajMatricu(m.size(),m[0].size()));
	for(int i(0);i<m.size();i++){
		for(int j(0);j<m[i].size();j++){
		    s[i][j]=m[m.size()-1-i][m[i].size()-1-j];
		}
	}
	return s;
}

Matrica Horizontalno(Matrica m){
    Matrica s(KreirajMatricu(m.size(),m[0].size()));
    int k(0);
    int l(0);
	for(int i(m.size()-1);i>=0;i--){
		for(int j(0);j<m[i].size();j++){
		    s[i][j]=m[k][l];
		    l++;
		}
		k++;
	}
	return s;
}

Matrica Vertikalno(Matrica m){
    Matrica s(KreirajMatricu(m.size(),m[0].size()));
    int k(0);
    int l(0);
	for(int i(0);i<m.size();i++){
		for(int j(m[i].size());j>=0;j--){
		    s[i][j]=m[k][l];
		    l++;
		}
		k++;
	}
	return s;
}

Matrica OgledaloMatrica(Matrica m){
	Matrica finalna(KreirajMatricu(m.size()*3,m[0].size()*3));
	Matrica v(Vertikalno(m));
	Matrica h(Horizontalno(m));
	Matrica hv(Kombinovano(m));
	for(int i(0);i<finalna.size();i++){
		for(int j(0);j<finalna[i].size();j++){
		if((i<m.size() and j<m[0].size()) or (i<m.size() and j<m[0].size()*3))
	    finalna[i][j]=hv[i][j];
		else if((i<m.size()*2 and j<m[i].size()) or(i<m.size()*2 and j<m[i].size()*3))
		finalna[i][j]=h[i][j];
		else if((i<m.size()*3 and j<m[i].size()) or(i<m.size()*3 and j<m[i].size()*3))
		finalna[i][j]=hv[i][j];
		else if((i<m.size() and j>m[0].size() and j<m[0].size()*2) or(i<m.size() and j>m[0].size()*2 and j<m[0].size()*3))
		finalna[i][j]=v[i][j];
		else if((i<m.size()*2 and j>m[0].size() and j<m[0].size()*2) or(i<m.size()*2 and j>m[i].size()*2 and j<m[0].size()*3))
		finalna[i][j]=m[i][j];
		else if((i<m.size()*3 and j>m[0].size() and j<m[0].size()*2) or(i<m.size()*3 and j>m[i].size()*2 and j<m[0].size()*3))
		finalna[i][j]=v[i][j];
		}
	}
	return finalna;
}

int main ()
{
	int m,n;
    cout<<"Unesite broj redova i kolona matrice: ";
    cin>>m>>n;
    cout<<"Unesite matricu: ";
    
    Matrica mat(KreirajMatricu(m,n));
    for(int i(0);i<m;i++){
        for(int j(0);j<n;j++){
            cin>>mat[i][j];
            
        }
    }
    Matrica s=OgledaloMatrica(mat);
      for(int i(0);i<s.size();i++){
        for(int j(0);j<s[i].size();j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}