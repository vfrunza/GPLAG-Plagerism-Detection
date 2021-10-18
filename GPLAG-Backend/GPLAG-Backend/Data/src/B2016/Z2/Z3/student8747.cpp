/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <deque>
#include <iomanip>
#include <cmath>


int SumaCifara(long long int x){
	if(x<0) x*=-1;
	int suma=0;
	while(x!=0){
		suma+=(x%10);
		x/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int x){
	if(x<0) x*=-1;
	int suma(0);
	for(long long int i=1;i<=x;i++){
		if(x%i==0) suma+=i;
	}
	return suma;
}

bool prost(long long int x){
	for(long long int i=2;i<=sqrt(x);i++){
		if(x%i==0) return false;
	}
	return true;
}

int BrojProstihFaktora(long long int x){
	if (x<0) x*=-1;
	int brojac(0);
	int i=2;
	while(x!=1 && x!=0){
		if(prost(i)){
			while(x%i==0){
				brojac++;
				x/=i;
			}
		}
		i++;
	}
	return brojac;
}

bool savrseni(long long int x){
	int suma(0);
	for(int i=1;i<x;i++){
		if(x%i==0) suma+=i;
	}
	return x==suma;
}

int BrojSavrsenihDjelilaca(long long int x){
	if(x<0) x*=-1;
	int brojac(0);
	for(long long int i=2;i<=x;i++){
		if(x%i==0){
				if(savrseni(i)) brojac++;
		}
	}
	return brojac;
}
	template <typename tip1,typename tip2>
auto UvrnutaRazlika(tip1 p1, tip1 p2, tip2 q1,tip2 q2)-> std::vector<std::vector<typename std::remove_reference<decltype(p1[0])>::type>>{
	typename std::remove_reference<decltype(p1[0])>::type tip;
	std::vector<decltype(tip)> v1;
	while(p1!=p2){
		v1.push_back(*p1);
		p1++;
	}
	for(int i=0;i<v1.size()-1;i++){
		for(int j=i+1;j<v1.size();j++){
			if(v1[i]==v1[j]) v1.erase(v1.begin()+j);
		}
	}
	std::vector<decltype(tip)> v2;
	while(q1!=q2){
		v2.push_back(*q1);
		q1++;
	}
	for(int i=0;i<v2.size()-1;i++){
		for(int j=i+1;j<v2.size();j++){
			if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
		}
	}
	std::vector<std::vector<decltype(tip)>>mat;
	std::vector<decltype(tip)> vek(2,0);
	for(int i=0;i<v1.size();i++){
		bool nasao=true;
		for(int j=0;j<v2.size();j++){
			if(v1[i]==v2[j]){
				nasao=false;
				break;
			}
		}
		if(nasao){
			vek[0]=v1[i];
			mat.push_back(vek);
		}
	}
	for(int i=0;i<v2.size();i++){
		bool nasao=true;
		for(int j=0;j<v1.size();j++){
			if(v2[i]==v1[j]){
				nasao=false;
				break;
			}
		}
		if(nasao){
			vek[0]=v2[i];
			mat.push_back(vek);
		}
	}
	sort(mat.begin(),mat.end(),[](std::vector<decltype(tip)>x,std::vector<decltype(tip)>y){
		return x[0]>y[0];
	});
	return mat;
}
	template <typename tip1,typename tip2>
auto UvrnutiPresjek(tip1 p1, tip1 p2, tip2 q1, tip2 q2)->std::vector<std::vector<typename std::remove_reference<decltype(p1[0])>::type>>{
	typename std::remove_reference<decltype(p1[0])>::type tip;
	std::vector<decltype(tip)>v1;
	while(p1!=p2){
		v1.push_back(*p1);
		p1++;
	}
	for(int i=0;i<v1.size()-1;i++){
		for(int j=i+1;j<v1.size();j++){
			if(v1[i]==v1[j]) v1.erase(v1.begin()+j);
		}
	}
	std::vector<decltype(tip)>v2;
	while(q1!=q2){
		v2.push_back(*q1);
		q1++;
	}
	for(int i=0;i<v2.size()-1;i++){
		for(int j=i+1;j<v2.size();j++){
			if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
		}
	}
	std::vector<std::vector<decltype(tip)>> mat;
	std::vector<decltype(tip)>vek(3);
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<v2.size();j++){
			if(v1[i]==v2[j]){
				vek[0]=v1[i];
				vek[1]=0;
				vek[2]=0;
				mat.push_back(vek);
			}
		}
	}
	sort(mat.begin(), mat.end(),[](std::vector<decltype(tip)>x,std::vector<decltype(tip)>y){
		return x[0]<y[0];
	});
	return mat;
}


	template<typename tip, typename tip1, typename tip2,typename tip3>
std::vector<std::vector<tip>> UvrnutaRazlika(tip1 p1, tip1 p2, tip2 q1, tip2 q2, tip f(tip3)){
	std::vector<tip>v1;
	while(p1!=p2){
		v1.push_back(*p1);
		p1++;
	}
	for(int i=0;i<v1.size()-1;i++){
		for(int j=i+1;j<v1.size();j++){
			if(v1[i]==v1[j]) v1.erase(v1.begin()+j); 
		}
	}
	std::vector<tip>v2;
	while(q1!=q2){
		v2.push_back(*q1);
		q1++;
	}
	for(int i=0;i<v2.size()-1;i++){
		for(int j=i+1;j<v2.size();j++){
			if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
		}
	}
	std::vector<std::vector<tip>> mat;
	std::vector<tip> vek(2);
	for(int i=0;i<v1.size();i++){
		bool nasao=true;
		for(int j=0;j<v2.size();j++){
			if(f(v1[i])==f(v2[j])) {
				nasao=false;
				break;
			}
		}
		if(nasao){
			vek[0]=v1[i];
			vek[1]=f(v1[i]);
			mat.push_back(vek);
		}
	}
	for(int i=0;i<v2.size();i++){
		bool nasao=true;
		for(int j=0;j<v1.size();j++){
			if(f(v2[i])==f(v1[j])){
			nasao=false;
			break;
			}
		}
		if(nasao){
			vek[0]=v2[i];
			vek[1]=f(v2[i]);
			mat.push_back(vek);
		}
	}
	sort(mat.begin(), mat.end(),[](std::vector<tip> x,std::vector<tip>y){
		if(x[0]==y[0]) return x[1]>y[1];
		else return x[0]>y[0];
	});
	return mat;
}

	template <typename tip,typename tip1,typename tip2,typename tip3>
std::vector<std::vector<tip>> UvrnutiPresjek(tip1 p1,tip1 p2,tip2 q1, tip2 q2, tip f(tip3)){
	std::vector<tip>v1;
	while(p1!=p2){
		v1.push_back(*p1);
		p1++;
	}
	std::vector<tip>v2;
	while(q1!=q2){
		v2.push_back(*q1);
		q1++;
	}
	for(int i=0;i<v1.size()-1;i++){
		for(int j=i+1;j<v1.size();j++){
			if(v1[i]==v1[j]) v1.erase(v1.begin()+j);
		}
	}
	for(int i=0;i<v2.size()-1;i++){
		for(int j=i+1;j<v2.size();j++){
			if(v2[i]==v2[j]) v2.erase(v2.begin()+j);
		}
	}
	std::vector<std::vector<tip>>mat;
	std::vector<tip>vek(3);
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<v2.size();j++){
			if(f(v1[i])==f(v2[j])){
				vek[0]=v1[i];
				vek[1]=v2[j];	
				vek[2]=f(v1[i]);
				mat.push_back(vek);
			}
		}
	}
	sort(mat.begin(), mat.end(),[](std::vector<tip>x,std::vector<tip>y){
		if(x[2]==y[2] && x[0]==y[0]) return x[1]<y[1];
		else if(x[2]==y[2]) return x[0]<y[0];
		else return x[2]<y[2];
	});
	return mat;
}

int main(){
	int n;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin >> n;
	if(!std::cin ){
		std::cin.clear();
		return 0;
	}
	std::deque<int>d1;
		std::cout << "Unesite elemente prvog kontejnera: ";
		for(int i=0;i<n;i++){
			int x;
			bool logi=true;
			std::cin >> x;
			if(d1.size()>0){
				for(int j=0;j<d1.size();j++){
					if(x==d1[j]){
						logi=false;
						break;
					}
				}
			}
			if(logi) d1.push_back(x);
			else i--;
		}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin >> n;
	if(!std::cin){
		std::cin.clear();
		return 0;
	}
	std::deque<int> d2;
		std::cout << "Unesite elemente drugog kontejnera: ";
		for(int i=0;i<n;i++){
			int x;
			bool logi=true;
			std::cin >> x;
			if(d2.size()>0){
				for(int j=0;j<d2.size();j++){
					if(x==d2[j]) {
						logi=false;
						break;
					}
				}
			}
			if(logi) d2.push_back(x);
			else i--;
		}
	std::cout << "Uvrnuti presjek kontejnera:"<< std::endl;
	if(d1.size()>0 && d2.size()>0){
		std::vector<std::vector<int>> mat=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
		for(int i=0;i<mat.size();i++){
			for(int j=0;j<mat[i].size();j++){
				std::cout << std::setw(6) << mat[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	if(d1.size()>0 && d2.size()>0){
		std::vector<std::vector<int>> matr=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
		for(int i=0;i<matr.size();i++){
			for(int j=0;j<matr[i].size();j++){
				std::cout << std::setw(6) << matr[i][j]<< " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << "Dovidjenja!" << std::endl;
	return 0;
}