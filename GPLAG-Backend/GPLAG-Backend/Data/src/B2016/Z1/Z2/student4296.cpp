#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
typedef std::vector<std::vector<double>> Matrica;
Matrica OgledaloMatrica(const Matrica &M){
	Matrica K;
	if(M.size()==0)
		return K;
	bool izuzetak=false;
	for(int i=0; i<M.size()-1; i++){
		for(int j=i+1; j<M.size(); j++)
			if(M[i].size()!= M[j].size())
				izuzetak=true;
	}
	if(izuzetak) 
		throw std::domain_error("Matrica nije korektna");
	Matrica V(M.size()*3, vector<double> (M[0].size()*3,0));
	int br_redova=M.size();
	int br_kolona=M[0].size();
	for(int i=0; i<br_redova;i++)
		for(int j=0; j<br_kolona;j++){
			V[i][j]=M[br_redova-1-i][br_kolona-j-1];
			V[i][j+br_kolona]=M[br_redova-i-1][j];
			V[i][j+br_kolona*2]=M[br_redova-1-i][br_kolona-j-1];
		}
	for(int i=0; i<br_redova; i++){
		V[br_redova+i]=V[br_redova-1-i];
		V[br_redova*2+i]=V[i];
	}
	return V;
}
int main ()
{	
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	
	if(m<0 || n<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 2;
	}
	Matrica M(m, std::vector<double> (n));
	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>M[i][j];
	try{
		Matrica K;
		K=OgledaloMatrica(M);
		cout<<endl<<"Rezultantna matrica: "<<endl;
		for(auto red : K) {
    		for(double x : red) std::cout << std::setw(4) << x;
            	std::cout << std::endl;
   		}
	}
   	catch(std::domain_error izuzetak) {
      std::cout << izuzetak.what() << std::endl;
   	}
	return 0;
}