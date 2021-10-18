/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<math.h>
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica
Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova,std::vector<double>(br_kolona));
}
Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			std::cout<<"Element ("<<i+1<<","<<j+1<<"): ";
			std::cin>>m[i][j];
		}
	}
	return m;
}
Matrica OgledaloMatrica(Matrica M){
	
	int brojac(0);
	std::vector<int> hist;
	for(int i=0; i<M.size();i++){
		for(int j=0; j<M[i].size();j++){
			brojac++;
		}
		hist(i).push_back(brojac);
	}
	for(int i=0; i<hist.size(); i++) 
	for(int j=i+1; j<hist.size(); j++)
	if(hist.at(i)!=hist.at(j)) throw std::domain_error("Matrica nije korektna");
	
	Matrica hM;
	hM.resize(M.size())
	for(int i=0; i<M.size(); i++) hm[i].resize(M[i].size());
	
	for(int i=0; i<M.size; i++){
	for(int j=0; j<M[i].size(); j++){
		hM[i][j]=M[i][j];
	}	
	}
	for(int i=0; i<hM.size(); j++){
		int k=hM[i].size()-1;
		for(int j=0; j<hM[i].size/2; j++){
			double temp=hM[i][j];
			hM[i][j]=hM[i][k];
			hM[i][k]=temp;
			k--;
		}
	}
	
	Matrica vM=M;
	
	for(int j=0; j<vM[0].size(); j++){
		int k=vM.size();
		for(int i=0; i<vM.size()/2; i++){
			double temp=vM[i][j];
			vM[i][j]=vM[k][j];
			vM[k][j]=temp;
			k--;
		}
	}
	
	Matrica hvM=hM;
	
	for(int j=0; j<hvM[0].size(); j++){
		int k=hvM.size();
		for(int i=0; i<hvM.size()/2; i++){
			double temp = hvM[i][j];
			hvM[i][j] = hvM[k][j];
			hvM[k][j] = temp;
			k--;
			
		}
	}
	
	Matrica Ogledalo;
	Ogledalo.resize(3*M.size());
	for(int i = 0; i < M.size() ; i++) Ogledalo[i].resize(3*M[i].size());
	
	for(int i=0; i<Ogledalo.size(); i++){
		for(int j=0; j<Ogledalo[i].size(); j++){
			
			if(i<Ogledalo.size()/3 && j<Ogledalo[i].size()/3){
				Ogledalo[i][j]=hvM[i][j];
			}
			else if(i>=Ogledalo.size()/3 && i<((Ogledalo.size()/3)+M.size()) && j<Ogledalo[i].size()/3)
			Ogledalo[i][j]=hM[i-M.size()][j];
			
			else if(i>=((Ogledalo.size()/3)+M.size()) && j<Ogledalo.size()/3)
			Ogledalo[i][j]=hvM[i-2*M.size()][j];
			
			else if(i<Ogledalo.size()/3 && j>=Ogledalo[i].size()/3 && j<((Ogledalo[i].size()/3)+M[i].size()))
			Ogledalo[i][j]=vM[i][j-M[i].size()];
			
			else if(i<Ogledalo.size()/3 && j>=((Ogledalo[i].size()/3)+M[i].size()))
			Ogledalo[i][j]=hvM[i][j-2*M[i].size()];
			
			else if(i>=Ogledalo.size()/3 && i<((Ogledalo.size()/3)+M.size()) && j>=Ogledalo[i].size()/3 && j<((Ogledalo[i].size()/3)+M[i].size()))
			Ogledalo[i][j]=M[i-M.size()][j-M[i].size()];
			
			else if(i>=(Ogledalo.size()/3)+M.size() && j<(Ogledalo.size()/3)+M[i].size())
			Ogledalo[i][j]=vM[i-2*M.size()][j-M[i].size()];
			
			else if(i>=Ogledalo.size()/3 && i<(Ogledalo.size()/3)+M.size() && j>=(Ogledalo.size()/3)+M[i].size)
			Ogledalo[i][j]=hM[i-M.size()][j-2*M[i].size()];
			
			else
			Ogledalo[i][j]=hvM[i-2*M.size()][j-2*M[i].size];
		}
		
		return Ogledalo;
	}
	}

int main ()
{
	int m, n;
	std::cout<<"Unesite dva cijela broja: ";
	std::cin>>m>>n;
	Matrica M;
	M.resize(m);
	for(int i=0; i<m; i++) M[i].resize(n);
	cout<<"Unesite elemente matrice dimenzija "<<m<<"x"<<n<<": ";
	M=UnesiMatricu(m,n);
	try{
		Matrica Ogledalo(OgledaloMatrica(M));
		
		for(int i=0;i<Ogledalo.size(); i++){
			for(int j=0; j<Ogledalo)
		}
		
	}
	
	return 0;
}