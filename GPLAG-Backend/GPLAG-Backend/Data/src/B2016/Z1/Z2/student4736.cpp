#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>


using namespace std;


typedef vector<double> Vektor;
typedef vector<vector<double>> Matrica;





bool daLiJeGrbava(Matrica M){
	
	for(int i=0;i<M.size();i++){
		if(M[0].size()!=M[i].size()) return true;
	}
	
	return false;
}


Matrica horizontalnoOgledalo(Matrica M){
	if(daLiJeGrbava(M)) throw domain_error("Matrica nije korektna");
	Matrica H(M.size(),vector<double>(M[0].size()));
	
	for(int i=0; i<M.size();i++){
		
		for(int j=0; j<M[i].size();j++){
			
			H[i][M[i].size()-j-1] = M[i][j];
		}
	}
	
	return H;
}


Matrica vertikalnoOgledalo(vector<vector<double>>M){
	if(daLiJeGrbava(M)) throw domain_error("Matrica nije korektna");
	Matrica H(M.size(),vector<double>(M[0].size()));
	
	for(int i=0; i<M.size();i++){
		
		for(int j=0; j<M[i].size();j++){
			
			H[M.size()-i-1][j] = M[i][j];
		}
	}
	
	return H;
}



Matrica kombinovanoOgledalo(vector<vector<double>>M){
	if(daLiJeGrbava(M)) throw domain_error("Matrica nije korektna");
	Matrica H(M.size(),vector<double>(M[0].size()));
	
	for(int i=0; i<M.size();i++){
		
		for(int j=0; j<M[i].size();j++){
			
			H[M.size()-i-1][M[i].size()-j-1] = M[i][j];
		}
	}
	
	return H;
}


Matrica sastaviHorizontalno(Matrica M1, Matrica M2){
	if(M1.size()!=M2.size()) throw range_error("Matrice nisu saglasne za horizontalno sastavljanje. Moraju imati isti broj redova!");
	Matrica M3(M1.size());
	
	for(int i=0;i<M3.size();i++){
		
		for(int j=0;j<M1[i].size();j++){
			M3[i].push_back(M1[i][j]);
		}
	
		
		for(int j=0;j<M2[i].size();j++){
			M3[i].push_back(M2[i][j]);
		}
	}
	
	return M3;
}


Matrica sastaviVertikalno(Matrica M1, Matrica M2){
	Matrica M3;
	
	for(int i =0;i<M1.size();i++){
		M3.push_back(M1[i]);
	}
	
	for(int i =0;i<M2.size();i++){
		M3.push_back(M2[i]);
	}
	return M3;
}

Matrica OgledaloMatrica(Matrica M){
	
	if(daLiJeGrbava(M)) throw domain_error("Matrica nije korektna");
	if(M.size()==0) return vector<vector<double>>();//rjesenje za potencijalno krahiranje za 0x0 matricu
	
	Matrica OM; 
	
	
	Matrica h = horizontalnoOgledalo(M);
	Matrica v = vertikalnoOgledalo(M);
	Matrica hv = kombinovanoOgledalo(M);
	
	
	Matrica prviTreciRed = sastaviHorizontalno(hv,v);
 	prviTreciRed = sastaviHorizontalno(prviTreciRed,hv);
 	
 	
 	Matrica drugiRed  = sastaviHorizontalno(h,M);
 	drugiRed  = sastaviHorizontalno(drugiRed,h);
 	
 	
 	OM = sastaviVertikalno(prviTreciRed,drugiRed);
 	OM = sastaviVertikalno(OM,prviTreciRed);
	
	return OM;
}




void ispisiMatricu(Matrica M){
	
	for(int i=0;i<M.size();i++){
		
		for(int j=0;j<M[i].size();j++){
		
				cout<<setw(4)<<M[i][j];
			
		}
		cout<<endl;
	}
}

int main ()
{
	
	try{
		int m,n;
		cout<<"Unesite dimenzije matrice (m n): ";
		cin>>m>>n;
		
		
		if(m<0 || n<0){ 
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		Matrica M(m,Vektor(n));
		
		cout<<"Unesite elemente matrice:"<<endl;
		for(int i=0;i<M.size();i++){
			
			for(int j=0;j<M[i].size();j++){
				cin>>M[i][j];
			}
		}
		
		
	Matrica OM = OgledaloMatrica(M);
	
	cout<<"Rezultantna matrica:"<<endl;
	ispisiMatricu(OM);
	}
	catch(domain_error e){
		cout<<e.what()<<endl;
	}
	
	return 0;
}