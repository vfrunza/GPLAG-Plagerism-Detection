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
using namespace std;

vector<vector<double>> KreirajMatricu(int br_redova, int br_kolona) {
 return vector<vector<double>>(br_redova*3, vector<double>(br_kolona*3));
}
vector<vector<double>> KreirajMatricu1(int br_redova, int br_kolona) {
 return vector<vector<double>>(br_redova, vector<double>(br_kolona));
}

vector<vector<double>>hor(vector<vector<double>>mat){
	vector<vector<double>>h=KreirajMatricu1(mat.size(),mat[0].size());
	int pozicija=0;
	for(int i=0;i<mat.size();i++){
		for(int j=mat[0].size()-1;j>=0;j--){
			h[i][j]=mat[i][pozicija];
			pozicija++;
		}
		pozicija=0;
	}

	return h;
}

vector<vector<double>>ver(vector<vector<double>>mat){
	vector<vector<double>>v=KreirajMatricu1(mat.size(),mat[0].size());
	int pozicija=0;
	for(int i=mat.size()-1;i>=0;i--){
		for(int j=0;j<mat[0].size();j++){
              v[i][j]=mat[pozicija][j];
              
		}
		pozicija++;
	}
	
	return v;
}

vector<vector<double>>kom(vector<vector<double>> mat){
	vector<vector<double>>hv=KreirajMatricu1(mat.size(),mat[0].size());
	int pozicija=0;
	int pozicijaY=0;
	for(int i=mat.size()-1;i>=0;i--){
	   for(int j=mat[0].size()-1;j>=0;j--){
	   	hv[i][j]=mat[pozicija][pozicijaY];
	   	pozicijaY++;
	   }
	   pozicija++;
	   pozicijaY=0;
	}
	
	
	return hv;
	
}



vector<vector<double>> OgledaloMatrica(vector<vector<double>> mat){
	
	vector<vector<double>> final;
	for(int i=0;i<mat.size();i++){
		if(mat[0].size()!=mat[i].size())throw domain_error ("Matrica nije korektna");
	}
	
	if(mat.size()==0)return KreirajMatricu(0,0);
	
	final=KreirajMatricu(mat.size(),mat[0].size());
	
	
	vector<vector<double>>h=hor(mat);
	
	
	
	vector<vector<double>>v=ver(mat);
	
	
	
	vector<vector<double>>hv=kom(mat);
	
	
	for(int i=0; i<final.size();i++){
		for(int j=0;j<final[0].size();j++){
			
			
			if(i<mat.size()){
				
				if(j<mat[0].size()){
				
					final[i][j]=hv[i][j];
					
				}else if(j<mat[0].size()*2){
					
					final[i][j]=v[i][j-mat[0].size()];	
					
				}else if(j<mat[0].size()*3){
					
					final[i][j]=hv[i][(j-mat[0].size()*2)];
					
				}
			
				
			}else if(i<mat.size()*2){
			
				if(j<mat[0].size()){
					
					final[i][j]=h[i-mat.size()][j];
					
				}else if(j<mat[0].size()*2){
					
					final[i][j]=mat[i-mat.size()][j-mat[0].size()];
					
				}else if(j<mat[0].size()*3){
					
					final[i][j]=h[i-mat.size()][(j-mat[0].size()*2)];
					
				}
				
			}else if(i<mat.size()*3){
				
				
				
			   if(j<mat[0].size()){
				
					final[i][j]=hv[i-mat.size()*2][j];
					
				}else if(j<mat[0].size()*2){
					
					
					
					final[i][j]=v[i-mat.size()*2][(j-mat[0].size())];	
				
					
				}else if(j<mat[0].size()*3){
			        
			       
					
					final[i][j]=hv[i-mat.size()*2][j-mat[0].size()*2];
			        
			        
				}
				
				
			}
		
			
		}
	}
	
	
	return final;
}




int main (){
	try{
	vector<vector<double>> mat;
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	mat.resize(m);
	for(int i=0;i<m;i++){
		mat[i].resize(n);
	}
	cout<<"Unesite elemente matrice:"<<endl;
	
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			double a;
			cin>>a;
			mat[i][j]=a;
		}
	}
	
	vector<vector<double>>final=OgledaloMatrica(mat);
	
	cout<<"Rezultantna matrica: "<<endl;
	
	for(int i=0;i<final.size();i++){
		for(int j=0;j<final[0].size();j++){
			cout<<setw(4)<<final[i][j];
			
		}
		cout<<endl;
	}
	}catch(domain_error hi){
		cout<<hi.what()<<endl;
	}
	return 0;
}