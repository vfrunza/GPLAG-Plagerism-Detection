#include <iostream>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>


int SumaDjelilaca (long long int x) {
	int suma(0);
	for(int i=1; i<=std::abs(x); i++) {
		if(x%i==0) suma+=i;
	}
	return suma;
}

int SumaCifara(long long int x) {
	int suma(0);
	for(;;) {
		int cifra;
		cifra=std::abs(x%10);
		suma+=cifra;
		x/=10;
		if(x==0) break;
	}
	return suma;
}

int BrojProstihFaktora (long long int x) {
	int brojac(0);
	
	for(int i=2; i<=x; i++) {
		while(x%i==0) {
			brojac++;
			x/=i;
		}
	}
	
	return brojac;
}


int BrojSavrsenihDjelilaca(long long int x) {
	int brojac(0);
	
	for(int i=1; i<=std::abs(x); i++) {
		if(x%i==0) {
			if(SumaDjelilaca(i)-i==i)
				brojac++;
		}
	}
	return brojac;
}


template <typename ITtip1, typename ITtip2, typename fpar, typename fpov>
auto UvrnutiPresjek(ITtip1 poc1, ITtip1 kraj1, ITtip2 poc2, ITtip2 kraj2, fpov funk(fpar) ) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {

//Matrica ciji su elementi isti tip kao i elementi bloka	
std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> mat;

int i(1);
	while(poc1!=kraj1) {
		ITtip2 pom2(poc2);
		while(pom2!=kraj2) {
			if(funk(*poc1)==funk(*pom2)) {
				mat.resize(i);
				mat[i-1].push_back(*poc1);
				mat[i-1].push_back(*pom2);
				mat[i-1].push_back(funk(*poc1));
				i++;
			}
			pom2++;
		}
		poc1++;
	}
	

std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*poc2)>::type> red1, std::vector<typename std::remove_reference<decltype(*poc2)>::type> red2) {
	if(red1[2]<red2[2]) return true;
	else if(red1[2]>red2[2]) return false;
	else if(red1[0]<red2[0]) return true;
	else if(red1[0]>red2[0]) return false;
	else if(red1[1]<red2[1]) return true;
	else if(red1[1]>red2[1]) return false;
	return true;
	});
	
	return mat;

	
}

template <typename ITtip1, typename ITtip2>

auto UvrnutiPresjek(ITtip1 poc1, ITtip1 kraj1, ITtip2 poc2, ITtip2 kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> mat;
	
	int i(1);
	while(poc1!=kraj1) {
		ITtip2 pom2(poc2);
		while(pom2!=kraj2) {
			if(*poc1==*pom2) {
				mat.resize(i);
				mat[i-1].resize(3);
				mat[i-1][0]=*poc1;
				i++;
			}
			pom2++;
		}
		poc1++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*poc2)>::type> red1, std::vector<typename std::remove_reference<decltype(*poc2)>::type> red2) {
	if(red1[0]<red2[0]) return true;
	
	return false;
	});
	
	return mat;
	
}

template <typename ITtip1, typename ITtip2, typename fpar, typename fpov>
auto UvrnutaRazlika(ITtip1 poc1, ITtip1 kraj1, ITtip2 poc2, ITtip2 kraj2, fpov funk(fpar) ) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {

//Matrica ciji su elementi isti tip kao i elementi bloka	
std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> mat;

int i(1);
ITtip1 pom1(poc1);
while(poc1!=kraj1) {
	ITtip2 pom2(poc2);
	bool ima_par(false);
	while(pom2!=kraj2) {
		if(funk(*poc1)==funk(*pom2)) {
			ima_par=true;
			break;
		}
		pom2++;
	}
	if(!ima_par) {
		mat.resize(i);
		mat[i-1].push_back(*poc1);
		mat[i-1].push_back(funk(*poc1));
		i++;
		
	}
	poc1++;
}
poc1=pom1;
while(poc2!=kraj2) {
	pom1=poc1;
	bool ima_par(false);
	while(pom1!=kraj1) {
		if(funk(*poc2)==funk(*pom1)) {
			ima_par=true;
			break;
		}
		pom1++;
	}
	if(!ima_par) {
		mat.resize(i);
		mat[i-1].push_back(*poc2);
		mat[i-1].push_back(funk(*poc2));
		i++;
		
	}
	poc2++;
}

std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*poc2)>::type> red1, std::vector<typename std::remove_reference<decltype(*poc2)>::type> red2) {
	if(red1[0]>red2[0]) return true;
	else if(red1[0]<red2[0]) return false;
	else if(red1[1]>red2[1]) return true;
	else if(red1[1]<red2[1]) return false;
	return true;
	});
	
	return mat;

}

template <typename ITtip1, typename ITtip2>

auto UvrnutaRazlika(ITtip1 poc1, ITtip1 kraj1, ITtip2 poc2, ITtip2 kraj2) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> mat;
	
	int i(1);
ITtip1 pom1(poc1);
while(poc1!=kraj1) {
	ITtip2 pom2(poc2);
	bool ima_par(false);
	while(pom2!=kraj2) {
		if(*poc1==*pom2) {
			ima_par=true;
			break;
		}
		pom2++;
	}
	if(!ima_par) {
		mat.resize(i);
		mat[i-1].resize(2);
		mat[i-1][0]=*poc1;
		i++;
		
	}
	poc1++;
}
poc1=pom1;
while(poc2!=kraj2) {
	pom1=poc1;
	bool ima_par(false);
	while(pom1!=kraj1) {
		if(*poc2==*pom1) {
			ima_par=true;
			break;
		}
		pom1++;
	}
	if(!ima_par) {
		mat.resize(i);
		mat[i-1].resize(2);
		mat[i-1][0]=*poc2;
		i++;
		
	}
	poc2++;
}
std::sort(mat.begin(), mat.end(), [] (std::vector<typename std::remove_reference<decltype(*poc2)>::type> red1, std::vector<typename std::remove_reference<decltype(*poc2)>::type> red2) {
	if(red1[0]>red2[0]) return true;
	return false;
	});
	
	return mat;
	
}

int main ()
{

	std::deque<int> dek1, dek2;
	
	int n1,n2;
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n1; i++) {
		int clan;
		std::cin>>clan;
		int j;
		for(j=0; j<i; j++) {
			if (clan==dek1[j]) { i--; break; }
		}
		if(j==i) dek1.push_back(clan);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n2; i++) {
		int clan;
		std::cin>>clan;
		int j;
		for(j=0; j<i; j++) {
			if (clan==dek2[j]) { i--; break; }
		}
		if(j==i) dek2.push_back(clan);
	}
	
	std::vector<std::vector<int>> mat1,mat2;
	
	mat1=UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara );
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<mat1.size(); i++) {
		for(int j=0; j<mat1[0].size(); j++) {
			std::cout<<std::setw(6)<<mat1[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	mat2=UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora );
	
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0; i<mat2.size(); i++) {
		for(int j=0; j<mat2[0].size(); j++) {
			std::cout<<std::setw(6)<<mat2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	
	return 0;
}