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
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> DVector;
using std::cout;
using std::cin;
using std::endl;

Matrica KreirajMatricu(int broj_redova, int broj_kolona) {
 return Matrica(broj_redova, std::vector<double>(broj_kolona));
}
void IspisiMatricu(Matrica m) {
	for(int i = 0; i < m.size(); i++) {
		for(int j = 0; j < m[0].size(); j++)
			std::cout << std::setw(4) << m[i][j];
			std::cout << std::endl;
 }
}



Matrica Obrni_Horizontalno(Matrica m){
	Matrica h(KreirajMatricu(m.size(),m[0].size()));
	for(int i(0);i<m.size();i++){
		int br(0);
		for(int j(m[0].size()-1);j>=0;j--){
			h[i][br]=m[i][j];
			br++;
			
		}
		
		
	}
	
	return h;
}
Matrica Obrni_Vertikalno(Matrica m){
	
	for(int i(0);i<m.size()-1;i++){
		DVector temp;
		for(int j(i+1);j<=m.size()-1;j++){
			
			temp=m[j];
			m[j]=m[i];
			m[i]=temp;
			
		}
	}
	
	return m;
}
Matrica Obrni_Horizontalno_Vertikalno(Matrica m){
	Matrica h(m);
	h=Obrni_Vertikalno(h);
	h=(Obrni_Horizontalno(h));
	
	
	
	return h;
}
Matrica OgledaloMatrica(Matrica a){
	if(a.size()==0) {
		a.resize(0);
		return a;}
	for(int i(0);i<a.size();i++){
		if(a[0].size()!=a[i].size()) throw std::domain_error("Matrica nije korektna");
	

			
		
		
		
	}
		Matrica h(Obrni_Horizontalno(a));
		Matrica v(Obrni_Vertikalno(a));
		Matrica hv(Obrni_Horizontalno_Vertikalno(a));
	Matrica mat(KreirajMatricu(a.size()*3,a[0].size()*3));
	
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[0].size();j++){
			
			if((i==0 && j==0)||(i==0 && j==(hv[0].size())*2) || (i==(hv.size()*2) && j==0) || (i==(hv.size()*2)&&j==(hv[0].size())*2)) {
				int br1(i);
				for(int k(0);k<hv.size();k++){
					
					int br2(j);
					for(int l(0);l<hv[0].size();l++){
						mat[br1][br2]=hv[k][l];
						br2++;
					}
					br1++;
				}
				
			}
			
			if((i==0 && j==(hv[0].size())) || (i==(hv.size()*2)&&j==(hv[0].size()))) {
				int br1(i);
				for(int k(0);k<hv.size();k++){
					
					int br2(j);
					for(int l(0);l<hv[0].size();l++){
						mat[br1][br2]=v[k][l];
						br2++;
					}
					br1++;
				}
				
			}
			if((i==hv.size() && j==(hv[0].size()))){
				int br1(i);
				for(int k(0);k<hv.size();k++){
					
					int br2(j);
					for(int l(0);l<hv[0].size();l++){
						mat[br1][br2]=a[k][l];
						br2++;
					}
					br1++;
				}
				
			}
			if((j==0 && i==(hv.size())) || (j==(hv[0].size()*2)&&i==(hv.size()))) {
				int br1(i);
				for(int k(0);k<hv.size();k++){
					
					int br2(j);
					for(int l(0);l<hv[0].size();l++){
						mat[br1][br2]=h[k][l];
						br2++;
					}
					br1++;
				}
				
			}
			
			
	}
	}
	
	return mat;
}

int main ()
{
	
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0){ cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	Matrica a(KreirajMatricu(m,n));

	cout<<"Unesite elemente matrice: ";	
		
	for(int i(0);i<m;i++)
		for(int j(0);j<n;j++){
			int br;
			cin >> br;
			a[i][j]=br;
		
			}
			
	try{
	
		Matrica h(OgledaloMatrica(a));
		cout<<"\nRezultantna matrica: "<<endl;
		IspisiMatricu(h);
		
		
		
	}catch(std::domain_error izuzetak){	
			cout<<izuzetak.what()<<endl;
	}
			
	
	return 0;
}
