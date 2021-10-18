#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <limits>
int f(long long int p) {
	int suma(0);
	while(p!=0) {
		suma+=p%10;
		p/=10;
	}
	return suma;
}
int SumaDjelilaca(long long int p)  {
	int suma(0);
	for(int i=2;i<=p/2;i++) {
		if(p%i==0) {
			suma+=i;
		}
	}
	return suma;
}
int BrojProstihFaktora(long long int d) {
	int broj(0);
   for(int j=2;j<d;j++) {
   	if(d%j==0) {
   		broj++;
   		d/=j;
   		j--;
   	}
   }
   return broj;
}

int BrojSavrsenihDjelilaca(long long int s) {
	int broj(0),suma(0),djelilac(0);
	for(int i=2;i<s;i++) {
		if(s%i==0) {
			djelilac=s/i;
			suma=0;
			for(int j=1;j<djelilac;j++) {
				if(djelilac%j==0) {
					suma+=j;
				}
			}
			if(suma==djelilac) 
			broj++;
		}
	}
	return broj;
}
typedef std::vector<std::vector<int>> Matrica;
template <typename tip1, typename tip2,typename tip3,typename tip4>
Matrica UvrnutiPresjek(tip1 pocetak,tip1 iza_kraja,tip2 start,tip2 end,tip3 fun(tip4 x)=[](tip1 pocetak,tip1 iza_kraja,tip2 start,tip2 end)->Matrica {
	Matrica rjesenje;
	while(pocetak!=iza_kraja) {
		rjesenje.resize(rjesenje.size()+1);
		while(start!=end) {
			if(*pocetak==*start) {
			rjesenje.push_back(*pocetak);
			}
			start++;
			}
			pocetak++;
		}
		return rjesenje;
})  {
	Matrica konacna;
	int i(0);
	while(pocetak!=iza_kraja && start!=end) {
		if(fun(*pocetak)==fun(*start)) {
			konacna.resize(konacna.size()+1);
			konacna[i].push_back(*pocetak);
			konacna[i].push_back(*start);
			konacna[i].push_back(fun(*pocetak));
			i++;
		}
		pocetak++;
		start++;
	}
std::sort(konacna[0],konacna[konacna.size()-1],[](std::vector<tip3> x,std::vector<tip3> y)->bool  {
	if(x[2]>y[2])
	return x[2]>y[2];
	if(x[2]==y[2]) 
	return x[0]>y[0];
	if(x[2]==y[2] && x[0]==y[0])
	return x[1]>y[1];
});
	return konacna;
}
template <typename tip1, typename tip2, typename tip3,typename tip4>
Matrica UvrnutaRazlika(tip1 pocetak,tip1 iza_kraja,tip2 start,tip2 end,tip3 fun(tip4 x)=[](tip1 pocetak,tip1 iza_kraja,tip2 start,tip2 end)->Matrica {
	Matrica rjesenje;
	while(pocetak!=iza_kraja) {
		rjesenje.resize(rjesenje.size()+1);
		while(start!=end) {
		     if(*pocetak!=*start) 
		   start++;
		   else break;
			}
			if(start==end) 
				rjesenje.push_back(*pocetak);
			pocetak++;
		}
		return rjesenje;
}) {
	Matrica Razlika;
	int j(0);
	while(pocetak!=iza_kraja) {
		Razlika.resize(Razlika.size()+1);
		while(start!=end) {
			if(fun(*pocetak)!=fun(*start))
			start++;
			else 
			break;
		}
		if(start==end) 
		Razlika[j].push_back(*pocetak);
		Razlika[j].push_back(fun(*pocetak));
		j++;
		pocetak++;
	}
	std::sort(Razlika[0],Razlika[Razlika.size()],[](std::vector<tip3> x,std::vector<tip3> y)->long long int {
	if(x[0]>y[0])
	return x[0];
	if(x[0]==y[0]) 
    return x[1]>y[1];
});
return Razlika;
}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>>n;
	std::deque<long long int> d(n);
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n;i++) {
		int k;
		std::cin>>k;
		d.push_back(k);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int g;
	std::cin>>g;
	std::deque<long long int> s(g);
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int j=0;j<g;j++) {
		int a;
		std::cin>>a;
		s.push_back(a);
	}
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	auto Rezultat(UvrnutiPresjek<std::deque<long long int>::iterator,std::deque<long long int>::iterator,int,long long int>(d.begin(),d.end(),s.begin(),s.end(),f));
	for(int t=0;t<Rezultat.size();t++) {
		for(int u=0;u<Rezultat[0].size();u++) {
			std::cout<<Rezultat[t][u]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	auto Razlika(UvrnutaRazlika<std::deque<long long int>::iterator,std::deque<long long int>::iterator,int,long long int>(d.begin(),d.end(),s.begin(),s.end(),f));
	for(int r=0;r<Razlika.size();r++) {
		for(int c=0;c<Razlika[0].size();c++) {
			std::cout<<Razlika[r][c]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}