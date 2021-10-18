#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stdexcept>
#define EPSILON 0.000001

using namespace std;
typedef vector<vector<double>> Matrica;

double planina(Matrica a){
	double suma1(0),suma2(0),vrh(0);
	int sredisnji((a.size()-1)/2);
	if(sredisnji<=0) return 0;
	int k(0);
	do{
	for(int i=sredisnji-k;i<=sredisnji+k;i++){
		for(int j=sredisnji-k;j<=sredisnji+k;j++){
			if(a.at(i).at(j)==a.at(sredisnji).at(sredisnji) && k==0){ suma1+=a.at(i).at(j); vrh=a.at(i).at(j);}
			else if(a.at(i).at(j)!=a.at(sredisnji).at(sredisnji)) suma2+=a.at(i).at(j);
		}
	}
	if(!k) k++;
	else if(k==1 && suma1>suma2){
		k++;
		suma1=suma2;
		suma2=0;
	}
	else if(suma1>suma2-suma1){
		k++;
		suma1=suma2-suma1;
		suma2=0;
	}
	else return 0;
	}while(k<=sredisnji);
	return vrh;
}
int format_kvadratne(Matrica m){
	int max_format;
	if(m.size()>=m[0].size()) max_format=m[0].size();
	else max_format=m.size();
	if(max_format%2==0) max_format--;
	return max_format;
}
Matrica NapraviMatricu(Matrica a, int i, int j, int format){
	Matrica x(format);
	int sredisnji((format-1)/2),m(0);
	for(int k=i-sredisnji;k<=i+sredisnji;k++){
		for(int l=j-sredisnji;l<=j+sredisnji;l++){
			x.at(m).push_back(a.at(k).at(l));
		}
		m++;
	}
	return x;
}
Matrica NajvecaPlaninaMatrice(Matrica a){
	int duzina(a.size()),sirina(a[0].size());
	for(int i=0;i<duzina;i++){
		if(a.at(i).size()!=sirina) throw domain_error("Matrica nije korektna");
	}
	Matrica m1,m2,prazna;
	if(duzina==0 || sirina==0) return prazna;
	int format(format_kvadratne(a));
	int sredisnji((format-1)/2);
	while (sredisnji>=1){
	m1=NapraviMatricu(a,sredisnji,sredisnji,format);
	for(int i=sredisnji;i<duzina-sredisnji;i++){
		for(int j=sredisnji;j<sirina-sredisnji;j++){
				m2 = NapraviMatricu(a,i,j,format);
				if(planina(m1) && planina(m2)){
					if(fabs(planina(m1)-planina(m2))<EPSILON){
						m2=prazna;
					}
					else if(planina(m1)<planina(m2)) m1=m2;	
					
				}
				else if(!planina(m1) && planina(m2)){
					m1=m2;
				}
				else if(!planina(m1)) m1=prazna;
		}
	}
	if(m1!=prazna) return m1;
	sredisnji--;
	format-=2;
	}
	if(!sredisnji){
		double max=a.at(0).at(0);
		for(int i=0;i<duzina;i++){
			for(int j=0;j<sirina;j++){
				if(i==0 || i==duzina-1 || j==0 || j==sirina-1)
				if(a.at(i).at(j)>=max) max=a.at(i).at(j);
			}
		}
		Matrica jedan(1,vector<double>(1,max));
		return jedan;
	}
}
int main ()
{
	cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice: "<<endl;
	Matrica matrica(m);
	double x;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>x;
			matrica.at(i).push_back(x);
		}
	}
	try{
	Matrica mat(NajvecaPlaninaMatrice(matrica));
	cout<<"Najveca planina unesene matrice je: "<<endl;
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
			cout<<setw(6)<<mat[i][j];
		}
		cout<<endl;
	}
	}
	catch(domain_error izuzetak){
		cout<<izuzetak.what();
		return 0;
	}
	return 0;
}