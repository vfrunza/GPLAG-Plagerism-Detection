/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<int>>Matrica;
typedef std::vector<int> Vector;


bool StepenDvojke(int broj){
	for(int i(0);i<=std::sqrt(broj)+1;i++){
		if(broj==std::pow(2,i)) return true;
	}
	return false;
}
int BrojRastuciPodnizova(Vector a){
	int brojel(0);
	for(int i=0;i<a.size()-1;i++){
		if(a.at(i)<=a.at(i+1) && StepenDvojke(a.at(i)) && StepenDvojke(a.at(i+1))) {
		while(i!=a.size()-1 && a.at(i)<=a.at(i+1) && StepenDvojke(a.at(i))) i++;
		brojel++;
			}
			
		}
	return brojel;
}

Matrica RastuciPodnizovi (Vector a){
	Matrica mat;
	if(a.size()==0) return mat;
	if(a.size()==1) {
		mat.resize(1);
		mat[0]=a;
		return mat;
	}
	int vel(BrojRastuciPodnizova(a));
	mat.resize(vel);
	int brojel(-1);
	int poc(0);
	int kraj(0);
	for(int i=0;i<a.size()-1;i++){
		if(a.at(i)<=a.at(i+1)){
			poc=i;
			while(i!=a.size()-1 && a.at(i)<=a.at(i+1))  i++;
			kraj=i+1;
			brojel++;
		
		
	
	for(int k=0;k<vel;k++){	
		if(k==brojel) {
			for(int j=poc;j<kraj;j++){
				mat[k].push_back(a[j]);
			}
		}
	}
	}
	}
	return mat;
}

int BrojOpadajuciPodnizova(Vector a){
	int brojel(0);
	for(int i=0;i<a.size()-1;i++){
		if(a.at(i)>=a.at(i+1)) {
		while(i!=a.size()-1 && a.at(i)>=a.at(i+1)) i++;
	
		brojel++;
			}
		}
	return brojel;
}

Matrica OpadajuciPodnizovi (Vector a){
	Matrica mat;
	if(a.size()==0) return mat;
	if(a.size()==1) {
		mat.resize(1);
		mat[0]=a;
		return mat;
	}
	int vel(BrojOpadajuciPodnizova(a));
	mat.resize(vel);
	int brojel(-1);
	int poc(0);
	int kraj(0);
	for(int i=0;i<a.size()-1;i++){
		if(a.at(i)>=a.at(i+1)){
			poc=i;
			while(i!=a.size()-1 && a.at(i)>=a.at(i+1)) i++;
			kraj=i+1;
			brojel++;
		
		
	
	for(int k=0;k<vel;k++){	
		if(k==brojel) {
			for(int j=poc;j<kraj;j++){
				mat[k].push_back(a[j]);
				}
			}
		}
	}
	}
	return mat;
}
	
	
	


int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int unos,n;
	Vector a;
	std::cin >> n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		std::cin >> unos;
		a.push_back(unos);
	}	
	Matrica	mat(RastuciPodnizovi(a));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	int maxpodniz(0);
	for(int i=0;i<mat.size();i++){
		if(mat[i].size()>maxpodniz) maxpodniz=mat[i].size();
	}

	for(int i=0;i<mat.size();i++){
		int da(1);
		for(int j=0;j<mat[i].size();j++){
			if(maxpodniz==mat[i].size())
			std::cout<<mat[i][j]<<" ";
			else da=0;
		}
		if(da)std::cout<<""<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	Matrica mat1(OpadajuciPodnizovi(a)); 
	maxpodniz=0;
	for(int i=0;i<mat1.size();i++){
		if(mat1[i].size()>maxpodniz) maxpodniz=mat1[i].size();
	}
	
	
	for(int i=0;i<mat1.size();i++){
		int da(1);
		for(int j=0;j<mat1[i].size();j++){
			if(maxpodniz==mat1[i].size())
			std::cout<<mat1[i][j]<<" ";
			else da=0;
		}
		if(da)std::cout<<""<<std::endl;
	}
	return 0;
}