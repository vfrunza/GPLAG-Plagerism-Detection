//B 16/17, Zadaća 2, Zadatak 3

#include <iostream>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <type_traits>
#include <vector>
#include <string>
#include <cmath>

typedef std::vector<int> Vektor;
typedef std::vector<std::vector<int>> Matrica;

bool JelProst(long long int broj){
	if(broj<0){broj=-broj;}
	for(int i=2;i<std::sqrt(broj);i++){
		if(broj%i==0) {return false;}
	}
	return true;
}
Matrica KreirajMatricu(int br_red, int br_kol){
	return Matrica(br_red, Vektor(br_kol));
}
int SumaDjelilaca(long long int broj){
	int suma{0};
	if(broj<0){broj=-broj;}
	for(int i=1; i<=broj; i++){
		if(broj%i==0) suma+=i;
	}
	return suma;
}
int BrojProstihFaktora(long long int broj){
	int brojac{0};
	if(broj<0){broj=-broj;}
	for(int i=2;i<=broj;i++){
		if(broj%i==0){
			if(JelProst(i)){
				brojac++;
				broj/=i;
				i--;
			}
		}
	}
	return brojac;
}
int BrojSavrsenihDjelilaca(long long int broj){
	int brojac{};
	for(int i=broj;i>=1;i--){
		if(broj%i==0){
			int djelilac{i}, suma{0};
				for(int j=djelilac;j>=1;j--){
					if(djelilac%j==0){
						suma+=j;
					}
				}
			suma=suma-djelilac;
			if(suma==djelilac) brojac++;
		}
	}
	return brojac;
}
int SumaCifara(long long int broj){
	int suma{};
	if(broj<0){broj=-broj;}
	while(broj!=0){
		suma+=(broj%10);
		broj/=10;
	}
	return suma;
}

//Funckija uvrnuti presjek
template<typename tip1, typename tip2, typename funk>
auto UvrnutiPresjek(tip1 pok11, tip1 pok12, tip2 pok21, tip2 pok22, funk f) ->std::vector<std::vector<typename std::remove_reference<decltype(*pok11)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*pok11)>::type>> mat;
	int duzina1(pok12-pok11);
	int duzina2(pok22-pok21);
	tip1 poc1{pok11};
	tip2 poc2{pok21};
	
	for(int i=0;i<duzina1;i++){
		int broj1(f(*pok11));
		
		for(int j=0;j<duzina2;j++){
		int broj2(f(*pok21));
			if(broj1==broj2) {
				std::vector<typename std::remove_reference<decltype(*pok11)>::type> pomocni{};
				pomocni.push_back(*pok11);
				pomocni.push_back(*pok21);
				pomocni.push_back(broj1);
				mat.push_back(pomocni);
			}
			pok21++;
		}
		pok11++;
		pok21=poc2;
	}
	pok11=poc1;//vracamo pok11 na pocetak
		
	std::sort(mat.begin(), mat.end(), [](std::vector<typename std::remove_reference<decltype(*pok11)>::type> x, std::vector<typename std::remove_reference<decltype(*pok11)>::type> y){
		if(x[2]==y[2]){
			if(x[0]==y[0]){
				return(x[1]<y[1]);
			}
			else{
				return(x[0]<y[0]);
			}
		}else
			return(x[2]<y[2]);
	});
	
	
	return mat;
}
//Funckija uvrnuti presjek bez funkcije kao barametra
template<typename tip1, typename tip2>
auto UvrnutiPresjek(tip1 pok11, tip1 pok12, tip2 pok21, tip2 pok22) ->std::vector<std::vector<typename std::remove_reference<decltype(*pok11)>::type>> {
	typedef typename std::remove_reference<decltype(*pok11)>::type TIP;
	std::vector<std::vector<TIP>> mat;
	int duzina1(pok12-pok11);
	int duzina2(pok22-pok21);
	tip1 poc1{pok11};
	tip2 poc2{pok21};
	
	for(int i=0;i<duzina1;i++){
			int broj1{*pok11};
		for(int j=0;j<duzina2;j++){
				int broj2{*pok21};
			if(broj1==broj2) {
				std::vector<TIP> pomocni{};
				pomocni.push_back(*pok11);
				pomocni.push_back(0);
				pomocni.push_back(0);
				mat.push_back(pomocni);
			}
			pok21++;
		}
		pok11++;
		pok21=poc2;
	}
	pok11=poc1;//vracamo pok11 na pocetak
		
	std::sort(mat.begin(), mat.end(), [](std::vector<TIP> x, std::vector<TIP> y){
		if(x[2]==y[2]){
			if(x[0]==y[0]){
				return(x[1]<y[1]);
			}
			else{
				return(x[0]<y[0]);
			}
		}else
			return(x[2]<y[2]);
	});
	return mat;
}
//Funkcija Uvrnuta Razlika sa petim parametrom
template<typename tip1, typename tip2, typename funk>
auto UvrnutaRazlika(tip1 pok11, tip1 pok12, tip2 pok21, tip2 pok22, funk f) ->std::vector<std::vector<typename std::remove_reference<decltype(*pok11)>::type>> {
	typedef typename std::remove_reference<decltype(*pok11)>::type TIP;
	std::vector<std::vector<TIP>> mat;
	int duzina1(pok12-pok11);
	int duzina2(pok22-pok21);
	tip1 poc1{pok11};
	tip2 poc2{pok21};
	
	for(int i=0;i<duzina1;i++){
		bool ima_taj_broj=false;
		int broj1(f(*pok11));
		for(int j=0;j<duzina2;j++){
			int broj2(f(*pok21));
			if(broj1==broj2){ima_taj_broj=true; break;};
			pok21++;
		}	
		if(ima_taj_broj==false){
			std::vector<TIP> pomocni{};
			pomocni.push_back(*pok11);
			pomocni.push_back(broj1);
			mat.push_back(pomocni);
		}
		pok11++;
		pok21=poc2;
	}
	pok11=poc1;//vracamo pok11 na pocetak
//Gledamo drugi kontejner	
	for(int i=0;i<duzina2;i++){
		bool ima_taj_broj=false;
		int broj1(f(*pok21));
		for(int j=0;j<duzina1;j++){
			int broj2(f(*pok11));
			if(broj1==broj2){ima_taj_broj=true; break;};
			pok11++;
		}	
		if(ima_taj_broj==false){
			std::vector<TIP> pomocni{};
			pomocni.push_back(*pok21);
			pomocni.push_back(broj1);
			mat.push_back(pomocni);
		}
		pok21++;
		pok11=poc1;
	}
	pok21=poc1;//vracamo pok21 na pocetak
//sortiramo
	std::sort(mat.begin(), mat.end(), [](std::vector<TIP> x, std::vector<TIP> y){
		if(x[1]==y[1]){
				return(x[0]>y[0]);
			}
		if(x[0]==y[0]){
			return(x[1]>y[1]);
		}	
		return(x[0]>y[0]);
	});
	return mat;
}
//Funkcija Uvrnuta Razlika bez funkcije kao parametar
template<typename tip1, typename tip2>
auto UvrnutaRazlika(tip1 pok11, tip1 pok12, tip2 pok21, tip2 pok22) ->std::vector<std::vector<typename std::remove_reference<decltype(*pok11)>::type>> {
	typedef typename std::remove_reference<decltype(*pok11)>::type TIP;
	std::vector<std::vector<TIP>> mat;
	int duzina1(pok12-pok11);
	int duzina2(pok22-pok21);
	tip1 poc1{pok11};
	tip2 poc2{pok21};
	
	for(int i=0;i<duzina1;i++){
		bool ima_taj_broj=false;
		for(int j=0;j<duzina2;j++){
			if(*pok11==*pok21){ima_taj_broj=true; break;};
			pok21++;
		}	
		if(ima_taj_broj==false){
			std::vector<TIP> pomocni{};
			pomocni.push_back(*pok11);
			pomocni.push_back(0);
			mat.push_back(pomocni);
		}
		pok11++;
		pok21=poc2;
	}
	pok11=poc1;//vracamo pok11 na pocetak
//Gledamo drugi kontejner	
	for(int i=0;i<duzina2;i++){
		bool ima_taj_broj=false;
		for(int j=0;j<duzina1;j++){
			if(*pok21==*pok11){ima_taj_broj=true; break;};
			pok11++;
		}	
		if(ima_taj_broj==false){
			std::vector<TIP> pomocni{};
			pomocni.push_back(*pok21);
			pomocni.push_back(0);
			mat.push_back(pomocni);
		}
		pok21++;
		pok11=poc1;
	}
	pok21=poc1;//vracamo pok21 na pocetak
//sortiramo
	std::sort(mat.begin(), mat.end(), [](std::vector<TIP> x, std::vector<TIP> y){
		if(x[1]==y[1]){
				return(x[0]>y[0]);
			}
		if(x[0]==y[0]){
			return(x[1]>y[1]);
		}	
		return(x[1]>y[1]);
	});
	return mat;
}

int main (){	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n1;
	std::cin>>n1;
	if(n1<=0){return 0;};
	
	std::deque<int> dek1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n1;i++){
		int broj;
		bool ima_taj_broj=false;
		std::cin>>broj;
		for(int j=0;j<dek1.size();j++){
			if(broj==dek1.at(j)){ ima_taj_broj=true; i--; break;}
		}
			if(ima_taj_broj==false){
				dek1.push_back(broj);}
	}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n2;
	std::cin>>n2;
	if(n2<=0) return 0;
	std::deque<int> dek2;
	std::cout<<"Unesite elemente drugog kontejnera: ";

	for(int i=0;i<n2;i++){
		int broj;
		bool ima_taj_broj=false;
		std::cin>>broj;
		for(int j=0;j<dek2.size();j++){
			if(broj==dek2.at(j)){ ima_taj_broj=true; i--; break;}
		}	
			if(ima_taj_broj==false){
				dek2.push_back(broj);
			}
	}

	Matrica rezultat{UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(), SumaCifara)};
	Matrica rezultat1{UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(), BrojProstihFaktora)};

	
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	for(int i=0;i<rezultat.size();i++){
		for(int j=0;j<rezultat[i].size();j++){
			std::cout<<std::setw(6)<<rezultat.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	for(int i=0;i<rezultat1.size();i++){
		for(int j=0;j<rezultat1[i].size();j++){
			std::cout<<std::setw(6)<<rezultat1.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	/*
	std::cout<<"Prvi glasi: ";
	for(int i=0;i<dek1.size();i++){
		std::cout<<std::setw(3)<<dek1.at(i);
	}
	std::cout<<"\nDrugi glasi: ";
	for(int i=0;i<dek2.size();i++){
		std::cout<<std::setw(3)<<dek2.at(i);
	}*/
	std::cout<<"Dovidjenja!"<<std::endl;
	return 0;
}