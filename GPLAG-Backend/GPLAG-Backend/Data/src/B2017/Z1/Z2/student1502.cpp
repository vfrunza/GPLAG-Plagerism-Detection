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
#include <stdexcept>
#include <iomanip>

using namespace std;

vector<vector<double>>KreirajMatricu(int br_redova, int br_kolona){
	return vector<vector<double>>(br_redova, vector<double>(br_kolona));
}

int Okolina(int i1, int j1, int &format, vector<vector<double>>mat){
	
	
	int suma=mat.at(i1).at(j1); int suma1=0;
	
	for(int temp=0; temp<10; temp++){
		
		if(i1-temp<0 or j1-temp<0 or i1+temp>=mat.size() or j1+temp>=mat.at(0).size()){
			format=temp-1;
			break;
		}
		
		
		for(int i=i1-temp;i<=i1+temp;i++){
			for(int j=j1-temp;j<=j1+temp;j++){
				if(i==i1 and j==j1)continue;
				suma1+=mat.at(i).at(j);
			}
		}
	if(suma1<suma){
		suma=suma1;          						//MOZDA PROBLEM PROVJERITI
	}
	}
	return suma;
}

	
vector<vector<double>> NajvecaPlaninaMatrice(vector<vector<double>>mat){
		
	
	
	vector<vector<double>> final;
	int format1=0;
	int format2=0;
	int im=0,jm=0;
	for(int i=0;i<mat.size();i++){
		if(mat.at(0).size()!=mat.at(i).size())throw domain_error ("Matrica nije korektna");
	}
	
	if(mat.size()==0)return KreirajMatricu(0,0);
	
	if(mat.size()<=2 or mat.at(0).size()<=2){
		final=KreirajMatricu(1,1);
		int mm=mat.at(0).at(0);
		for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[0].size();j++){
		if(mm<mat.at(i).at(j))mm=mat.at(i).at(j);
			
		}
		}
		final.at(0).at(0)=mm;
		return final;
	}
	
	for(int i=1;i<mat.size()-1;i++){
		for(int j=1;j<mat[0].size()-1;j++){
			int okol=Okolina(i,j,format1,mat);
			if(mat.at(i).at(j)>okol){
				if(format1>format2){
					format2=format1;
					im=i; jm=j;
				}else if(format1==format2 and mat.at(i).at(j)>mat.at(im).at(jm)){
					format2=format1;
					im=i; jm=j;
				}
				
				
				//OSTALI SLUCAJEVI TEST
				
			}
			
			
			
			
		}
	}


	final.resize(format2*2+1);
	for(int i=0;i<final.size();i++){
		final.at(i).resize(format2*2+1);
	}
	int k1=0;
	for(int i=im-format2;i<=im+format2;i++){
		int k2=0;
		for(int j=jm-format2;j<=jm+format2;j++){
			final.at(k1).at(k2)=mat.at(i).at(j);			//KOORDINATE UPITNE
			k2++;
		}
		k1++;
	}

return final;
}
	

int main (){
	cout<<"Unesite dimenzije matrice (m i n): ";
try{
	int m,n;
	cin>>m>>n;
	if(m<0 or n<0) throw domain_error("Dimenzije matrice moraju biti nenegativne!");
	vector<vector<double>> mat=KreirajMatricu(m,n);
	cout<<"Unesite elemente matrice:"<<endl;
	double a;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a;
			mat.at(i).at(j)=a;
		}
	}

	vector<vector<double>> final=NajvecaPlaninaMatrice(mat);
	cout<<"Najveca planina unesene matrice je:"<<endl;
	for(vector<double> x:final){
		for(double y: x){
			cout<<setw(6)<<y;
		}
		cout<<endl;
	}
	}catch(domain_error hello_there){
		cout<<hello_there.what();
	}
	

	return 0;
}