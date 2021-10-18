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
#include <string>
#include <iomanip>
#include <stdexcept>
#define eps 0.0000001
using namespace std;
typedef vector<vector<double>>MAT;
bool Jednaki(MAT mat){
	double m(mat.at(0).at(0));
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat.at(i).size();j++){
			if(mat.at(i).at(j)-m>eps) return false;
		}
	}
	return true;
}
bool DaLiJePlanina(MAT mat,int m,int n,int velicina){
	double SUMA(mat.at(m).at(n));
	for(int k=1;k<=velicina/2;k++){
		double suma(0);
		for(int i=m-k;i<=m+k;i++){
			for(int j=n-k;j<=n+k;j++){
				if(j!=n-k && j!=n+k) continue;
				suma+=mat.at(i).at(j);
			}
		}
		if(suma>SUMA) return false;
		suma=SUMA;
	}
	return true;
}
MAT NajvecaPlaninaMatrice(MAT mat){

	for(int x=1;x<mat.size();x++){
		if(mat.at(0).size()!=mat.at(x).size()) throw domain_error("Matrica nije korektna");
	}
	//Matrice formata 0x0 mx0 0xm
	if(mat.size()==0) return mat;
		if(Jednaki(mat) && mat.size()>1 && mat.at(0).size()>1){ MAT nulta(1,vector<double>(1,0)); return nulta ;}
	if(mat.size()!=0){
		bool ima=true;
		for(int x=0;x<mat.size();x++){
			if(mat.at(x).size()!=0){ ima=false; break;}
		}
		if(ima==true){
		MAT planina(1,vector<double>());
		return planina;
		}
	}
	// Korektna matrica
	int k,maxi(0),maxj(0);
	if(mat.size()>=mat.at(0).size()) k=mat.at(0).size();
	else k=mat.size();
	if(k%2 == 0)k--;
	for(k=k;k>2;k-=2){
		for(int i=0;i<mat.size();i++){
			if(i+k/2>=mat.size() || i-k/2<0) continue;
			for(int j=0;j<mat.at(0).size();j++){
				if(j+k/2>=mat.at(0).size() || j-k/2<0) continue;
				if(DaLiJePlanina(mat,i,j,k)){
					if(!maxi){
						maxi=i;
						maxj=j;
					}
					else{
						if(mat.at(i).at(j)>mat.at(maxi).at(maxj)){
							maxi=i;
							maxj=j;
						}
						else if(mat.at(i).at(j)-mat.at(maxi).at(maxj)<=eps){
							if(i<maxi){
								maxi=i;
								maxj=j;
							}
							else if(i==maxi){
								if(j<maxj){
									maxi=i;
									maxj=j;
								}
							}
						}
					}
				}
			}
		}
		if(maxi) break;
	}
	if(!maxi){
	
		double max(mat.at(0).at(0));
		for(int x=0;x<mat.size();x++){
			for(int y=0;y<mat.at(x).size();y++){
				if(mat.at(x).at(y)>=max) max=mat.at(x).at(y);
			}
		}
			MAT planina(1,vector<double>());
			planina.at(0).push_back(max);
			return planina;
	
	}
	int x(0);
	MAT planina(k,vector<double>());
	for(int i=maxi-k/2;i<=maxi+k/2;i++){
		for(int j=maxj-k/2;j<=maxj+k/2;j++){
			planina.at(x).push_back(mat.at(i).at(j));
		}
		x++;
	}
	return planina;
}
int main ()
{
    cout<<"Unesite dimenzije matrice (m i n): ";
    int m,n;
    cin>>m>>n;
    if(m<0 || n<0){ cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
    MAT mat(m,vector<double>(n));
    cout<<"Unesite elemente matrice: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>mat.at(i).at(j);
    }
   try{  MAT planina(NajvecaPlaninaMatrice(mat));
     cout<<"Najveca planina unesene matrice je:"<<endl;
     for(int i=0;i<planina.size();i++){
        for(int j=0;j<planina.at(0).size();j++){

            cout<<setw(6)<<planina.at(i).at(j);
        }
        cout<<endl;
     }
   }
   catch(domain_error izuzetak){
   	cout<<izuzetak.what()<<endl;
   }


    return 0;
}