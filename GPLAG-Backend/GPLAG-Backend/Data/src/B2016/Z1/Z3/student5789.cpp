/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#define eps 0.0000001
typedef std::vector<std::vector<double>> matrica;

int BrojRedovaRastuceMatrice(std::vector<double> v){
	int br=0;
	for(int i=0; i<v.size(); i++){
		if(i==v.size()-1){
			if(v[i]>v[i-1]) br++;
		}
		else if(v[i]>v[i+1]){
			if(i!=0 &&  v[i]>v[i-1]) br++;
		}	
	}
	return br;
}
matrica RastuciPodnizovi(std::vector<double> v){
	matrica m;
	int br=BrojRedovaRastuceMatrice(v);
//	std::cout<<"br= "<<br<<" ";
    m.resize(br);
	int vel=0;
	std::vector<double> v1;
	for(int i=0; i<v.size()-1; i++){
		if(v[i]<v[i+1]){
			while(i<v.size()-1 &&  v[i]<v[i+1] ){
				v1.push_back(v[i]);
				i++;
			}
			v1.push_back(v[i]);
			m[vel]=v1;
			vel++;
			v1.resize(0);
		}	
	}
	/*std::cout<<"matrica: ";
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}*/

	return m;
}
int BrojRedovaOpadajuceMatrice(std::vector<double> v){
	int br=0;
	for(int i=0; i<v.size(); i++){
		if(i!=v.size()-1){
			if(v[i]>v[i+1]){
				if(i!=0 && v[i]>v[i-1]) br++;
				
			}
		}
	}
	return br;
}
matrica OpadajuciPodnizovi(std::vector<double> v){
	matrica m;
	int br=BrojRedovaOpadajuceMatrice(v);
//	std::cout<<"br= "<<br;
	m.resize(br);
	std::vector<double> v1;
	int vel=0;
	for(int i=0; i<v.size(); i++){
		if(i!=v.size()-1){
			if(v[i]>v[i+1]){
				while(i<v.size()-1 && v[i]>v[i+1]){
					v1.push_back(v[i]);
					i++;
				}
				v1.push_back(v[i]);
				m[vel]=v1;
				vel++;
				v1.resize(0);
			}
		}
		
	}
	/*std::cout<<"Matrica: \n";
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}*/
	return m;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
		std::cin>>v[i];
	}
	matrica m=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<m.size(); i++){
		for(int j=0; j<m[i].size(); j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	matrica m1=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<m1.size(); i++){
		for(int j=0; j<m1[i].size(); j++){
			std::cout<<m1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}