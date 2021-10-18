#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using std::cin;
using std::cout;
using std::vector;

vector<vector<double>> OgledaloMatrica(vector<vector<double>> M){

	    vector<vector<double>> Rezultat;
	    //Proširujemo rezultantnu matricu
	    
	    Rezultat.resize(3*M.size());
	    for(int i=0;i<3*M.size();i++)
	        Rezultat[i].resize(3*M[0].size());
	    
	    //Ispitujemo dali je poslata grbava matrica i bacamo izuzetak
	    
	    for(int i=0;i<M.size();i++){
	    	if(M[i].size() != M[0].size())
	    	throw std::domain_error("Matrica nije korektna");
	       }
	    //U x i y smjestamo velicine br redova i br kolona radi notacije
	    int x=0,y=0;
	    if(M.size()!=0 && M[0].size()!=0){
	    x=M.size();
	    y=M[0].size();
	    }
	    //Manipulisemo matricom M da bi kreirali nove 3 matrice hM, vM i hvM 
	    vector<vector<double>> hM(M.size(),vector<double> (y)),hvM(M.size(),vector<double> (y)),vM(x,vector<double> (y));
	    for(int i=0;i<M.size();i++){
	    	for(int j=0;j<y;j++){
	    		hM[i][j]=M[i][M[i].size()-j-1];
	    		vM[i][j]=M[M.size()-i-1][j];
	    		hvM[i][j]=M[M.size()-i-1][M[i].size()-j-1];
	    	}
	    }
	    
	    //Upisujemo kreirane matrice na zeljena mjesta u rezultantnoj matrici
	    for(int i=0;i<Rezultat.size();i++){
	    	for(int j=0;j<Rezultat[i].size();j++){
	            if(i<x && j<y)                    
	            Rezultat[i][j]=hvM[i][j];
	            
	            else if(i<x && j<2*y && j>=y)     
	            Rezultat[i][j]=vM[i][j-y];
	            
	            else if(i<x && j>=2*y)            
	            Rezultat[i][j]=hvM[i][j-2*y];
	            
	            else if(j<y && i>=x && i<2*x)    
	            Rezultat[i][j]=hM[i-x][j];
	            
	            else if(j<y && i>=2*x)
	            Rezultat[i][j]=hvM[i-2*x][j];     
	            
	            else if(j>=2*y && i>=2*x)
	            Rezultat[i][j]=hvM[i-2*x][j-2*y];
	            
	            else if(i>=2*x && j>=y && j<2*y)
	            Rezultat[i][j]=vM[i-2*x][j-y];
	            
	            else if(i>=x && i<2*x && j>=2*y)
	            Rezultat[i][j]=hM[i-x][j-2*y];
	            
	            else if(i>=x && i<2*x && j>=y && j<2*y)
	            Rezultat[i][j]=M[i-x][j-y];
	    	}
	    }
	    return Rezultat;
}
int main ()
{
		int m,n;
		cout<<"Unesite dimenzije matrice (m n): ";
		cin>>m>>n;
		if(n<0 || m<0){
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		cout<<"Unesite elemente matrice: "<<std::endl;
		vector<vector<double>> Ulazna_matrica(m,vector<double> (n));
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>Ulazna_matrica[i][j];
			}
		}
		try{
		vector<vector<double>> Rezultantna_matrica(3*m,vector<double> (3*n));
		Rezultantna_matrica=OgledaloMatrica(Ulazna_matrica);
		cout<<"Rezultantna matrica:"<<std::endl;
		for(int i=0;i<Rezultantna_matrica.size();i++){
			for(int j=0;j<Rezultantna_matrica[i].size();j++){
		        cout<<std::setw(4)<<Rezultantna_matrica[i][j];
			}
			cout<<std::endl;
        }
    }
	catch(std::domain_error greska){
		cout<<greska.what();
	}
	return 0;
}