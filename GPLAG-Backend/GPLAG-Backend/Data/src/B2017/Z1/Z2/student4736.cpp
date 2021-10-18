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
using namespace std;



bool imaPlaninu(vector<vector<double>> M, int okvir, int ip, int jp)
{
	vector<double>sume;
	for(int k=0; k<=okvir/2; k++) {
		double suma=0;

		for(int i=ip+k; i<ip+okvir-k; i++) {
			for(int j=jp+k; j<jp+okvir-k; j++) {
				if(i==ip+k || j==ip+k || i==ip+okvir-1-k || j==jp+okvir-1-k) {
					suma+=M.at(i).at(j);
				} 
			}
		}
		sume.push_back(suma);
	}

	for (int i = 0; i < sume.size()-1; i++) {
		if(sume.at(i) >= sume.at(i+1)) {
			return false;
		}
	}

	return true;
}

vector<vector<double>> NajvecaPlaninaMatrice(vector<vector<double>> M)
{
	vector<vector<double>> P;
	int ipmax=0, jpmax=0,maxokvir=0;


	for (int i = 0; i < M.size(); i++) {
		if(M[i].size()!=M[0].size()) {
			throw domain_error("Matrica nije korektna");
		}
	}

	if(M.size()==0 || M[0].size()==0) return P;
	
	int okvir;
	

	//stimamo da okvir bude najveci moguci i neparan
	if(M.size()<=M[0].size()) {
		okvir = M.size();
		if(okvir%2==0)okvir--;
	} else {
		okvir = M[0].size();
		if(okvir%2==0)okvir--;
	}

	while(okvir>=1) {

		for (int i = 0; i <= M.size()-okvir; i++) {
			for (int j = 0; j <= M[i].size()-okvir; j++) {
				if(imaPlaninu(M,okvir,i,j)){
					if(okvir>maxokvir){
						ipmax = i;
						jpmax = j;
						maxokvir=okvir;
					}
					else if(okvir==maxokvir){
						if(M.at(i+okvir/2).at(j+okvir/2) >  M.at(ipmax+maxokvir/2).at(jpmax+maxokvir/2) ){
							ipmax = i;
							jpmax = j;
							maxokvir=okvir;
						}
					}
				}
			}
		}
		
		if(maxokvir!=0){
			for (int i = ipmax; i < ipmax+maxokvir; i++) {
				vector<double>r;
					for (int j = jpmax; j < jpmax+maxokvir; j++) {
						r.push_back(M.at(i).at(j));
					}
				P.push_back(r);
			}
			
			
			break;
		}
		okvir-=2;
	}

	return P;
}

int main ()
{
	try {

		int m,n;
		cout<<"Unesite dimenzije matrice (m i n): ";
		cin>>m>>n;
		if(m<0||n<0){
			cout<<"Dimenzije matrice moraju biti nenegativne!"<<endl;
			return 0;
		}
		cout<<"Unesite elemente matrice:"<<endl;
		vector<vector<double>> A(m,vector<double>(n));

		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[i].size(); j++) {
				cin>>A.at(i).at(j);
			}
		}

		vector<vector<double>> NP = NajvecaPlaninaMatrice(A);
		cout<<"Najveca planina unesene matrice je:"<<endl;

		for(vector<double> v:NP) {
			for(double e:v) {
				cout.width(6);
				cout<<e;
			}
			cout<<endl;
		}
		NajvecaPlaninaMatrice(A);
	} catch(domain_error e) {
		cout<<e.what()<<endl;
	}
	return 0;
}