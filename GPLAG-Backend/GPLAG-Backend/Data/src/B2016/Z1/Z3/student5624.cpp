/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using std:: vector;
typedef std:: vector<vector<double>> Matrica;
/*bool vektori_isti(vector<double> v1, vector<double> v2){
	if(v1.size()==v2.size()) return false;
	else{
		int br(0);
		for(int i=0; i<v1.size(); i++){
			for(int j=0; j<v2.size(); j++){
				if(v1.at(i)==v2.at(j)){
					br++;
					if(br>v2.size()) return true;
				}
			}
		}
		return false;
	}
}
Matrica Provjera(Matrica mat1){
	if(mat1.size()==1 || mat1.size()==0) return mat1;
	for(int i=0; i<mat1.size(); i++){
		for(int k=i+1; k<mat1.size(); k++){
			if(mat1[i].size()<mat1[k].size()){
				if(vektori_isti(mat1[k], mat1[i]))
				mat1.erase(mat1.begin()+i);
			}
			else{
				if(vektori_isti(mat1[i], mat1[k])) 
				mat1.erase(mat1.begin()+k);
			}
		}
	}
	return mat1;
}*/
Matrica RastuciPodnizovi(vector<double> v){
	Matrica niz(0);
	vector<double> v1;
	for(int i=0; i<v.size()-1; i++){
		if(v.at(i)<=v.at(i+1)) v1.push_back(v.at(i));
		else if(v.at(i)>v.at(i+1) && v1.size()!=0){
			v1.push_back(v[i]);
			if(v1.size()!=0) {
				niz.push_back(v1);
				v1.resize(0);
		}
	}}
	if(v1.size()!=0){
		v1.push_back(v[v.size()-1]);
		niz.push_back(v1);
	}
	//niz=Provjera(niz);
	return niz;
}
Matrica OpadajuciPodnizovi(vector <double> v){
	Matrica niz(0);
	vector<double> v1;
	for(int i=0; i<v.size()-1; i++){
		if(v.at(i)>=v.at(i+1)) v1.push_back(v.at(i));
		else if(v.at(i)<v.at(i+1) && v1.size()!=0){
			v1.push_back(v[i]);
			if(v1.size()!=0) {
				niz.push_back(v1);
				v1.resize(0);
		}
	}}
	if(v1.size()!=0){
		v1.push_back(v[v.size()-1]);
		niz.push_back(v1);
	}
	//niz=Provjera(niz);
	return niz;
}
int main ()
{	int n;
	do{
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	}while(n<=0 || n==std::numeric_limits<int>::min() || n==std::numeric_limits<int>::max());
	vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<v.size(); i++){
		std::cin>>v[i];
	}
	Matrica niz1(RastuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0; i<niz1.size(); i++){
		for(int j=0; j<niz1[i].size(); j++){
			std::cout<<niz1[i][j]<<" ";	
		}
		std::cout<<"\n";
	}
	Matrica niz2(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0; i<niz2.size(); i++){
		for(int j=niz2[i].size()-1; j>=0; j--){
			std::cout<<niz1[i][j]<<" ";	
		}
		std::cout<<"\n";
	}
	return 0;
}