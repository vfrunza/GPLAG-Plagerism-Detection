#include<iostream>
#include<vector>
#include<algorithm>
#include<type_traits>
#include<deque>
#include<iomanip>
#include<cmath>
int SumaCifara(long long int a)
{
	if(a<0) a*=-1;
	int sum=int();
	while(a!=0) {
		sum=sum+a%10;
		a/=10;
	}
	return sum;
}
int SumaDjelilaca(long long int a)
{
	if(a<0) a*=-1;
	int suma=0;
	for(int i=1; i<=a; i++) {
		if(a%i==0)suma=suma+i;
	}
	return suma;
}
bool DaLiJeProst(long long int a){
	if(a==1 || a<0 || a==0) return 0; 
	if(a==2) return 1; 
	for(long long int i=2; i<a; i++){
		if(a%i==0) return 0;
	}
	return 1; 
}
int BrojProstihFaktora(long long int a)
{
	if(a<0) a*=-1;
	int broj=0;
	for(long long int i=1; i<=a; i++){
		if(a%i==0 && DaLiJeProst(i)) {broj++; a=a/i; i--;}
	}

	return broj;
}
int BrojSavrsenihDjelilaca(long long int a)
{
	if(a<0) a*=-1;
	std::vector<long long int> v;
	std::vector<long long int> v1;
	for(int i=1; i<=a; i++) {
		if(a%i==0) {
			v.push_back(i);
		}
	}

	for(int i=0; i<v.size(); i++) {
		int suma=0;
		for(int j=1; j<v[i]; j++) {
			if(v[i]%j==0) suma=suma+j;
		}
		if(suma==v[i]) v1.push_back(v[i]);
	}

	int br=v1.size();
	return br;
}
template <typename NekiTip1, typename NekiTip2, typename NekiTip3, typename NekiTip4>
auto UvrnutiPresjek(NekiTip1 pocetak, NekiTip1 kraj, NekiTip2 pocetak1, NekiTip2 kraj1, NekiTip3 f(NekiTip4)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	std::vector<std::vector <typename std::remove_reference<decltype(*pocetak)>::type>> Matrica;
	std::vector<typename std::remove_reference<decltype(*pocetak)>::type> v;
	for(int i=0; i<(kraj-pocetak); i++) {
		for(int j=0; j<(kraj1-pocetak1); j++) {
			v.resize(0);
			if(f(pocetak[i])==f(pocetak1[j])) {
				v.push_back(pocetak[i]);
				v.push_back(pocetak1[j]);
				v.push_back(f(pocetak[i]));
				Matrica.push_back(v);
			}
		}
	}
	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak)>::type> a, std::vector<typename std::remove_reference<decltype(*pocetak)>::type> b) {
		if (a[2]<b[2]) return true;
		else if(a[2]==b[2] && a[0]<b[0]) return true;
		else if(a[2]==b[2] && a[0]==b[0] && a[1]<b[1]) return true;
		else return  false;
	});
	return Matrica;
}

template <typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek(NekiTip1 pocetak, NekiTip1 kraj, NekiTip2 pocetak1, NekiTip2 kraj1) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	std::vector<std::vector <typename std::remove_reference<decltype(*pocetak)>::type>> Matrica;
	std::vector<typename std::remove_reference<decltype(*pocetak)>::type> v;
	for(int i=0; i<(kraj-pocetak); i++) {
		for(int j=0; j<(kraj1-pocetak1); j++) {
			v.resize(0);
			if((pocetak[i])==(pocetak1[j])) {
				v.push_back(pocetak[i]);
				v.push_back(0);
				v.push_back(0);
				Matrica.push_back(v);
			}
		}
	}
	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak)>::type> a, std::vector<typename std::remove_reference<decltype(*pocetak)>::type> b) {
		if (a[2]<b[2]) return true;
		else if(a[2]==b[2] && a[0]<b[0]) return true;
		else if(a[2]==b[2] && a[0]==b[0] && a[1]<b[1]) return true;
		else return  false;
	});
	return Matrica;
}
template <typename NekiTip1, typename NekiTip2, typename NekiTip3, typename NekiTip4>
auto UvrnutaRazlika(NekiTip1 pocetak, NekiTip1 kraj, NekiTip2 pocetak1, NekiTip2 kraj1, NekiTip3 f(NekiTip4)) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	std::vector<std::vector <typename std::remove_reference<decltype(*pocetak)>::type>> Matrica;
	std::vector<typename std::remove_reference<decltype(*pocetak)>::type> v;
	for(int i=0; i<(kraj-pocetak); i++) {
		int b=0;
		for(int j=0; j<(kraj1-pocetak1); j++) {
			v.resize(0);
			if(f(pocetak[i])==f(pocetak1[j])) b=1;
		}
		if(b==0) {
			v.push_back(pocetak[i]);
			v.push_back(f(pocetak[i]));
			Matrica.push_back(v);
		}
	}
	for(int i=0; i<(kraj1-pocetak1); i++) {
		int b=0;
		for(int j=0; j<(kraj-pocetak); j++) {
			v.resize(0);
			if(f(pocetak1[i])==f(pocetak[j])) b=1;
		}
		if(b==0) {
			v.push_back(pocetak1[i]);
			v.push_back(f(pocetak1[i]));
			Matrica.push_back(v);
		}
	}
	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak)>::type> a, std::vector<typename std::remove_reference<decltype(*pocetak)>::type> b) {
		if (a[0]>b[0]) return true;
		else if(a[0]==b[0] && a[1]>b[1]) return true;
		else return  false;
	});
	return Matrica;
}
template <typename NekiTip1, typename NekiTip2>
auto UvrnutaRazlika(NekiTip1 pocetak, NekiTip1 kraj, NekiTip2 pocetak1, NekiTip2 kraj1) -> std::vector<std::vector<typename std::remove_reference<decltype(*pocetak)>::type>> {
	std::vector<std::vector <typename std::remove_reference<decltype(*pocetak)>::type>> Matrica;
	std::vector<typename std::remove_reference<decltype(*pocetak)>::type> v;
	for(int i=0; i<(kraj-pocetak); i++) {
		int b=0;
		for(int j=0; j<(kraj1-pocetak1); j++) {
			v.resize(0);
			if(pocetak[i]==pocetak1[j]) b=1;
		}
		if(b==0) {
			v.push_back(pocetak[i]);
			v.push_back(0);
			Matrica.push_back(v);
		}
	}
	for(int i=0; i<(kraj1-pocetak1); i++) {
		int b=0;
		for(int j=0; j<(kraj-pocetak); j++) {
			v.resize(0);
			if(pocetak1[i]==pocetak[j]) b=1;
		}
		if(b==0) {
			v.push_back(pocetak1[i]);
			v.push_back(0);
			Matrica.push_back(v);
		}
	}
	std::sort(Matrica.begin(), Matrica.end(), [](std::vector<typename std::remove_reference<decltype(*pocetak)>::type> a, std::vector<typename std::remove_reference<decltype(*pocetak)>::type> b) {
		if (a[0]>b[0]) return true;
	
	});
	return Matrica;
}


int main()
{

std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::deque<int> dek(n);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<dek.size(); i++) {
		std::cin>>dek[i];
		for(int j=0; j<i; j++) {
			if(dek[i]==dek[j]) {
				dek.resize(dek.size()+1);
				break;
			}
		}
	}
	for(int i=0; i<dek.size(); i++) {
		for(int j=i+1; j<dek.size(); j++) {
			if(dek[i]==dek[j] && i!=j) {
				dek.erase(dek.begin()+j);
				j--;
			}
		}
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n1;
	std::cin>>n1;
	std::deque<int> dek1(n1);
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<dek1.size(); i++) {
		std::cin>>dek1[i];
		for(int j=0; j<i; j++) {
			if(dek1[i]==dek1[j]) {
				dek1.resize(dek1.size()+1);
				break;
			}
		}
	}
	for(int i=0; i<dek1.size(); i++) {
		for(int j=i+1; j<dek1.size(); j++) {
			if(dek1[i]==dek1[j] && i!=j) {
				dek1.erase(dek1.begin()+j);
				j--;
			}
		}
	}
	auto Matrica=UvrnutiPresjek(dek.begin(), dek.end(), dek1.begin(), dek1.end(), SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	for(int i=0; i<Matrica.size(); i++) {
		for(int j=0; j<Matrica[i].size(); j++) {
			std::cout<<std::setw(6)<<Matrica[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	auto Matrica1=UvrnutaRazlika(dek.begin(), dek.end(), dek1.begin(), dek1.end(), BrojProstihFaktora);
	for(int i=0; i<Matrica1.size(); i++) {
		for(int j=0; j<Matrica1[i].size(); j++) {
			std::cout<<std::setw(6)<<Matrica1[i][j]<<" ";
		}
		std::cout<<"\n";
	}

	std::cout<<"Dovidjenja!";

	return 0;
}