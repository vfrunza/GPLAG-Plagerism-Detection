/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<iomanip>
#include<vector>
using std::vector;

typedef vector<vector<double>> Matrica;

Matrica IzbaciRed(Matrica M){
	int i(0), j(0);
	for(i=0;i<M.size();i++){
		if(M[i].size()<1){
			for(j=i;j<M.size()-1;i++){
				M[j]=M[j+1];
				M.resize(M.size()-1);
				i--;
			}
		}
	}
	return M;
}

Matrica OpadajuciPodnizovi(vector<double> V){
	Matrica M(0, vector<double> (0));
	int a(0);
	if(V.size()>0){
		M.resize(1);
	}
	a=V[0];
	int i(0), x(0);
	for(i=0;i<V.size();i++){
		if(V[i]<a){
			a=V[i];
			M[x].push_back(V[i]);
		}
		else{
			M.resize(M.size()-1);
			a=V[i];
			i--;
			x++;
		}
	}
	M=IzbaciRed(M);
	return M;
}

Matrica RastuciPodnizovi(vector<double> V){
	Matrica M(0, vector<double> (0));
	int a(0);
	if(V.size()>0){
		M.resize(1);
	}
	a=V[0];
	int i(0), x(0);
	for(i=0;i<V.size();i++){
		if(V[i]>a){
			a=V[i];
			M[x].push_back(V[i]);
		}
		else{
			M.resize(M.size()-1);
			a=V[i];
			i--;
			x++;
		}
	}
	M=IzbaciRed(M);
	return M;
}

int main ()
{
	int a(0), x(0);
	vector<double> V;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>a;
	std::cout<<"Unesite elemente vektora: ";
	int i(0);
	for(i=0;i<a;i++){
		std::cin>>x;
		V.push_back(x);
	}
	Matrica M(0, vector<double> (0));
	M=RastuciPodnizovi(V);
	std::cout<<"Maksimalni rastuci podnizovi: ";
	int j(0);
	for(i=0;i<M.size();i++){
		for(j=0;j<M.size();j++){
			std::cout<<std::setprecision(10)<<M[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	for(i=0;i<M.size();i++){
		for(j=0;j<M.size();j++){
			std::cout<<std::setprecision(10)<<M[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}