/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <cmath>


int SumaCifara(long long int broj) {
	int suma(0);
	while(broj!=0) {
		suma+=broj%10;
		broj/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int broj) {
	int suma(0);
	if(broj>0) {
	for(int i=1;i<=broj;i++) {
		if(broj%i==0)
		suma+=i;
	}
	}
	if(broj<0) {
		for(int i=1;i<=std::abs(broj);i++) {
			if(broj%i==0)
			suma+=i;
		}
	}
	return suma;
	
}
bool prost(long long int broj) {
	for(int i=2;i<broj;i++) {
		if(broj%i==0) {
			return false;
		}
	}
	return true;
}
int ZaSavrseneSumaDjelilaca(long long int broj) {
	int suma(0);
	for(int i=1;i<broj;i++) {
		if(broj%i==0)
		suma+=i;
	}
	return suma;
}



int BrojProstihFaktora(long long int broj) {
	int brojac(0);
	if(broj==1) {
		return 1;
	}
	int k=broj%2;
	long long int b;
	while(k==0) {
		b=broj/2;
		broj=b;
		brojac++;
		k=broj%2;
	}
	for(int j=3;j<=broj;j+=2) {
		int k=broj%j;
		while(k==0) {
			b=broj/j;
			brojac++;
			broj=b;
			k=broj%j;
		}
	}
return brojac;
}

int BrojSavrsenihDjelilaca(long long int broj) {
	int brojac(0);
	for(int i=1;i<=broj;i++) {
		//std::cout << "i: " << i << " " << ZaSavrseneSumaDjelilaca(i) << std::endl;
		if(broj%i == 0 && ZaSavrseneSumaDjelilaca(i)==i) {
			brojac++;
		}
	}
	return brojac;
}




template<typename Tip4,typename Tip5,typename Tip1,typename Tip2>
std::vector<std::vector<int>> UvrnutiPresjek(Tip1 niz1_pocetak,Tip1 niz1_iza_kraja,Tip2 niz2_pocetak,Tip2 niz2_iza_kraja,Tip4 f(Tip5 p)) {
	std::vector<std::vector<int>>matrica;
	std::vector<int> v;
	Tip2 pom_pocetak=niz2_pocetak,pom_iza_kraja=niz2_iza_kraja;
	while(niz1_pocetak!=niz1_iza_kraja) {
		while(pom_pocetak!=pom_iza_kraja) {
			
			if(f(Tip5(*niz1_pocetak))==f((Tip5)*pom_pocetak)) {
				v.push_back((*niz1_pocetak));
				v.push_back((*pom_pocetak));
				v.push_back(f(Tip5(*niz1_pocetak)));
				matrica.push_back(v);
				v.pop_back(); v.pop_back(); v.pop_back();
			}
			pom_pocetak++;

		}
		niz1_pocetak++;
		pom_pocetak=niz2_pocetak;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<int>v1,std::vector<int>v2) {
		if(v1[2]==v2[2]) {
			if(v1[0]==v2[0])
			return v1[1]<v2[1];
			return v1[0]<v2[0];
		}
		return v1[2]<v2[2];
	});
	return matrica;
}

template<typename Tip1,typename Tip2>
std::vector<std::vector<int>>UvrnutiPresjek(Tip1 niz1_pocetak,Tip1 niz1_iza_kraja,Tip2 niz2_pocetak,Tip2 niz2_iza_kraja) {
std::vector<std::vector<int>>matrica;
std::vector<int>v;
Tip2 pom_pocetak=niz2_pocetak,pom_iza_kraja=niz2_iza_kraja;
while(niz1_pocetak!=niz1_iza_kraja) {
	while(pom_pocetak!=pom_iza_kraja) {
	if(*niz1_pocetak==*pom_pocetak) {
		v.push_back(*niz1_pocetak);
		v.push_back(0);
		v.push_back(0);
		matrica.push_back(v);
		v.pop_back(); v.pop_back(); v.pop_back();
	}
	pom_pocetak++;
}
niz1_pocetak++;
pom_pocetak=niz2_pocetak;
}
std::sort(matrica.begin(),matrica.end(),[](std::vector<int>v1,std::vector<int>v2) {
	if(v1[2]==v2[2]) {
		if(v1[0]==v2[0])
			return v1[1]<v2[1];
		return v1[0]<v2[0];
	}
	return v1[2]<v2[2];
});
return matrica;
}
template<typename Tip4,typename Tip5,typename Tip1,typename Tip2>
std::vector<std::vector<int>>UvrnutaRazlika(Tip1 niz1_pocetak,Tip1 niz1_iza_kraja,Tip2 niz2_pocetak,Tip2 niz2_iza_kraja,Tip4 f(Tip5 p)) {
	std::vector<std::vector<int>>matrica;
	std::vector<int>v;
	Tip1 pom_pocetak1=niz1_pocetak,pom_iza_kraja1=niz1_iza_kraja;
	Tip2 pom_pocetak=niz2_pocetak,pom_iza_kraja=niz2_iza_kraja;
	while(pom_pocetak1!=niz1_iza_kraja) {
		int brojac(0);
		while(pom_pocetak!=pom_iza_kraja) {
			
			if(f((Tip5)*pom_pocetak1)==f((Tip5)*pom_pocetak)) {
				brojac++;
			}
			pom_pocetak++;
		}
		if(brojac==0) {
			v.push_back(*pom_pocetak1);
			v.push_back(f((Tip5)*pom_pocetak1));
			matrica.push_back(v);
			v.pop_back(); v.pop_back();
		}
		pom_pocetak1++;
		pom_pocetak=niz2_pocetak;
	}
	pom_pocetak1=niz1_pocetak;
	while(niz2_pocetak!=niz2_iza_kraja) {
		int brojac=0;
		while(pom_pocetak1!=pom_iza_kraja1) {
		
			if(f((Tip5)*niz2_pocetak)==f((Tip5)*pom_pocetak1)) {
				brojac++;
			}
			pom_pocetak1++;
		}
		if(brojac==0) {
			v.push_back(*niz2_pocetak);
			v.push_back(f((Tip5)*niz2_pocetak));
			matrica.push_back(v);
			v.pop_back(); v.pop_back();
		}
		niz2_pocetak++;
		pom_pocetak1=niz1_pocetak;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<int>v1,std::vector<int>v2) {
		if(v1[0]==v2[0])  {
		return v1[1]>v2[1];
		}
		return v1[0]>v2[0];


	});
	return matrica;
}


template<typename Tip1,typename Tip2>
std::vector<std::vector<int>>UvrnutaRazlika(Tip1 niz1_pocetak,Tip1 niz1_iza_kraja,Tip2 niz2_pocetak,Tip2 niz2_iza_kraja) {
	std::vector<std::vector<int>>matrica;
	std::vector<int>v;
	Tip1 pom_pocetak1=niz1_pocetak,pom_iza_kraja1=niz1_iza_kraja;
	Tip2 pom_pocetak=niz2_pocetak,pom_iza_kraja=niz2_iza_kraja;
	while(pom_pocetak1!=niz1_iza_kraja) {
		int brojac(0);
		while(pom_pocetak!=pom_iza_kraja) {
			
			if(*pom_pocetak1==*pom_pocetak) {
				brojac++;
			}
			pom_pocetak++;
		}
		if(brojac==0) {
			v.push_back(*pom_pocetak1);
			v.push_back(0);
			matrica.push_back(v);
			v.pop_back(); v.pop_back();
		}
		pom_pocetak1++;
		pom_pocetak=niz2_pocetak;
	}
	pom_pocetak1=niz1_pocetak;
	while(niz2_pocetak!=niz2_iza_kraja) {
		int brojac=0;
		while(pom_pocetak1!=pom_iza_kraja1) {
		
			if(*niz2_pocetak==*pom_pocetak1) {
				brojac++;
			}
			pom_pocetak1++;
		}
		if(brojac==0) {
			v.push_back(*niz2_pocetak);
			v.push_back(0);
			matrica.push_back(v);
			v.pop_back(); v.pop_back();
		}
		niz2_pocetak++;
		pom_pocetak1=niz1_pocetak;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<int>v1,std::vector<int>v2) {
		if(v1[0]==v2[0])  {
		return v1[1]>v2[1];
		}
		return v1[0]>v2[0];


	});
	return matrica;
}




template<typename Tip>
void IspisiMatricu(std::vector<std::vector<Tip>>m) {
	for(int i=0;i<m.size();i++) {
		for(int j=0;j<m[i].size();j++) {
			std::cout<<std::setw(6)<<m[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
int main ()
{
	//std::cout<<BrojProstihFaktora(63);
	//return 0;
	//std::cout<<SumaDjelilaca(-5);
	//return 0;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int broj1;
	std::cin>>broj1;
	std::deque<int>dek1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int broj;
	int brojac(0);
	std::cin>>broj;
	dek1.push_back(broj);
	do {
		std::cin>>broj;
		for(int i=0;i<dek1.size();i++) {
			if(dek1[i]==broj)
			brojac++;
		}
		if(brojac==0) {
			dek1.push_back(broj);
		}
		brojac=0;
	}
	while(dek1.size()!=broj1);
	brojac=0;
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int broj2;
	std::cin>>broj2;
	std::deque<int>dek2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::cin>>broj;
	dek2.push_back(broj);
	brojac=0;
	do {
		std::cin>>broj;
		for(int i=0;i<dek2.size();i++) {
			if(dek2[i]==broj)
			brojac++;
		}
		if(brojac==0) {
			dek2.push_back(broj);
		}
		brojac=0;
	}
	while(dek2.size()!=broj2);
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	std::vector<std::vector<int>>m=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara);
	IspisiMatricu(m);
	std::vector<std::vector<int>>m1=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end());
	//IspisiMatricu(m1);
	//std::cout<<std::endl;
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	std::vector<std::vector<int>>m2=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
	IspisiMatricu(m2);
	std::cout<<"Dovidjenja!";
	
/*std::deque<int> d1{-2, -1, 0, 43, -5, 10, 11}, d2{2, -1, 0, 5, -10, 23};
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaDjelilaca)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaDjelilaca)};
	
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}*/

	return 0;
}