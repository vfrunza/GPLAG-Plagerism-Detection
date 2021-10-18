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

using std::cin;
using std::cout;

typedef std::vector<std::vector<double>> Matrica;
bool Grbava(Matrica m){
	bool grbava(false);
	for(int i=0;i<m.size();i++){
		if(m[0].size()!=m[i].size()){
			grbava=true;
			break;
		}
	}
	return grbava;
}
Matrica VertikalnoOgledalo(Matrica m){
	Matrica vm(m);
	for(int i=0;i<vm.size()/2;i++){
		for(int j=0;j<vm[0].size();j++){
			double temp;
			temp=vm[i][j];
			vm[i][j]=vm[vm.size()-1-i][j];
			vm[vm.size()-1-i][j]=temp;
		}
	}
	return vm;
}
Matrica HorizontalnoOgledalo(Matrica m){
	
	Matrica hm(m);
	for(int i=0;i<hm.size();i++){
		for(int j=0;j<hm[0].size()/2;j++){
			double temp;
			temp=hm[i][j];
			hm[i][j]=hm[i][hm[i].size()-1-j];
			hm[i][hm[i].size()-1-j]=temp;
		}
	}
	return hm;
}
Matrica OgledaloMatrica(Matrica m){
	if(m.size()==0)
	return Matrica(0,std::vector<double>(0));
	else if(m[0].size()==0)
	return Matrica(3*m.size(),std::vector<double>(0));
	if(Grbava(m)) throw std::domain_error("Matrica nije korektna");
	Matrica hm;
	hm=HorizontalnoOgledalo(m);
	Matrica vm;
	vm=VertikalnoOgledalo(m);
	Matrica hvm;
	hvm=HorizontalnoOgledalo(VertikalnoOgledalo(m));
	Matrica om(3*m.size(),std::vector<double>(3*m[0].size()));
	for(int i=0;i<om.size();i++){
		for(int j=0;j<om[0].size();j++){
			if(i<m.size() && j<m[0].size())
			om[i][j]=hvm[i][j];
			else if(i<m.size() && j<2*m[0].size())
			om[i][j]=vm[i][j-m[0].size()];
			else if(i<m.size() && j<3*m[0].size())
			om[i][j]=hvm[i][j-2*m[0].size()];
			else if(i<2*m.size() && j<m[0].size())
			om[i][j]=hm[i-m.size()][j];
			else if(i<3*m.size() && j<m[0].size())
			om[i][j]=hvm[i-2*m.size()][j];
			else if(i<2*m.size() && j<2*m[0].size())
			om[i][j]=m[i-m.size()][j-m[0].size()];
			else if(i<2*m.size() && j<3*m[0].size())
			om[i][j]=hm[i-m.size()][j-2*m[0].size()];
			else if(i<3*m.size() && j<2*m[0].size())
			om[i][j]=vm[i-2*m.size()][j-m[0].size()];
			else
			om[i][j]=hvm[i-2*m.size()][j-2*m[0].size()];
		}
	}
	return om;
}
int main ()
{
	int m,n;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if(m>=0 && n>=0){
	Matrica M(m,std::vector<double>(n));
	cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>M[i][j];
		}
	}
	try{
		Matrica OM=OgledaloMatrica(M);
		cout<<"Rezultantna matrica: "<<std::endl;
		for(int i=0;i<OM.size();i++){
			for(int j=0;j<OM[0].size();j++){
				cout<<std::setw(4)<<OM[i][j];
			}
			cout<<"\n";
		}
	}
	catch(std::domain_error izuzetak){
		cout<<izuzetak.what()<<std::endl;
	}
	}
	else
	cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
}