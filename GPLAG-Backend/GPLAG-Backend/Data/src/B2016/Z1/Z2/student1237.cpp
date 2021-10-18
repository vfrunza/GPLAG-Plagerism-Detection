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
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int br_redova,int br_kolona){
	return Matrica(br_redova,std::vector<double>(br_kolona));
}
Matrica UnesiMatricu(int br_redova,int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0;i<br_redova;i++){
		for(int j=0;j<br_kolona;j++){
			std::cout<<"Element("<<i+1<<","<<j+1<<");";
			std::cin>>m[i][j];
		}
	}
	return m;
}
Matrica OgledaloMatrica(Matrica M){
	Matrica horizontalna;
	Matrica vertikalna;
	Matrica kombinovana;
	for(int i=0;i<M.size();i++){
		for(int j=0;j<M[i].size();j++){
			
			for(int k=M.size();k>0;k++){
				horizontalna.push_back(M[k]);
			}
			for(int k=M[i].size();k>0;k++){
				vertikalna.push_back(M[k]);
			}
			for(int k=horizontalna[i].size();k>0;k++){
				kombinovana.push_back(horizontalna[k]);
			}
		}
	}
	Matrica Nova;
	int red=2*kombinovana.size()+vertikalna.size();
	int kolona=2*kombinovana.size()+horizontalna.size();
	for(int i=0;i<red;i++){
		for(int j=0;j<kolona;j++){
			Nova.push_back(kombinovana[i][j]);
		}
	}
	return Nova;
}
int main ()
{
	int m,n;
	std::cout<<"Unesi broj redova: ";
	std::cin>>m;
	std::cout<<"Unesi broj kolona: ";
	std::cin>>n;
	Matrica M;
	Matrica ispis;
	M=UnesiMatricu(m,n);
	ispis=OgledaloMatrica(M);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cout<<ispis[i][j];
			std::cout<<std::endl;
		}
	}
	
	return 0;
}