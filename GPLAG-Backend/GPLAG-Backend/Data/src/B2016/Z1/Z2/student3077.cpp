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
using std::cin;
using std::cout;

std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> m1(m);
	for(int i=0; i<m1.size()/2; i++){
		for(int j=0; j<m1[i].size(); j++){
			int k=m1.size()-1-i;
			double a=m1[i][j];
			m1[i][j]=m1[k][j];
			m1[k][j]=a;
		}
	}
	return m1;
}

std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> m1(m);
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m1[i].size()/2; j++){
			int k=m1[i].size()-1-j;
			double a=m1[i][j];
			m1[i][j]=m1[i][k];
			m1[i][k]=a;
		}
	}
		return m1;
} 

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> m1(m);
	for(int i=0; i<m1.size()-1; i++){
		int j=i+1;
		while(j<m1.size()-1){
			if(m1[i].size()!=m1[j].size())
				throw std::domain_error("Matrica nije korektna");
				j++;
		}
	}
	std::vector<std::vector<double>> rezultantna(3*m1.size(),std::vector<double>(3*m1[0].size()));
	std::vector<std::vector<double>> horizontalno=HorizontalnoOgledalo(m1);
	std::vector<std::vector<double>> vertikalno=VertikalnoOgledalo(m1);
	std::vector<std::vector<double>> kombinovano=HorizontalnoOgledalo(VertikalnoOgledalo(m1));
	for(int i=0; i<rezultantna.size(); i++){
		for(int j=0; j<rezultantna[i].size(); j++){
			int redovi=horizontalno.size();
			int kolone=horizontalno[0].size();
			int k(0),l(0), m(0),n(0),p(0),q(0),s(0),t(0);
			if((j<kolone || j>=2*kolone) &&(i>=2*redovi || i<redovi)){
				rezultantna[i][j]=kombinovano[l][k];
				k++;
				if(k==kolone-1){
					l++;
					k=0;
				} 
			}
			else if((j<kolone || j>=2*kolone) &&(i>=redovi && i<2*redovi)){
				rezultantna[i][j]=vertikalno[m][n];
				n++;
				if(n==kolone-1){
					m++;
					n=0;
				} 
			}
			else if((j<kolone || j>=2*kolone)&&(i<redovi|| i>2*redovi)){
				rezultantna[i][j]=horizontalno[p][q];
				q++;
				if(q==kolone-1) {
					p++;
					q=0;
				}
			}
			else{
				rezultantna[i][j]=m1[s][t];
				t++;
				if(t==kolone-1){
					s++;
					t=0;
				}
			}
		}
	}
	return rezultantna;
}




int main ()
{	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m;
	cin>>n;
	std::vector<std::vector<double>> matrica(m,std::vector<double>(n));
	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<matrica.size();i++){
		for(int j=0; j<matrica[i].size(); j++){
			cin>>matrica[i][j];
		}
	}
	std::vector<std::vector<double>> rezultanta=OgledaloMatrica(matrica);
	cout<<"Rezultantna matrica: ";
	for(int i=0; i<rezultanta.size(); i++){
		for(int j=0; j<rezultanta[i].size(); j++){
			cout<<rezultanta[i][j];
		}
		cout<<std::endl;
	}
	return 0;
}