/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include<iostream>
#include<cmath>
#include<deque>
#include<vector>
#include<algorithm>

#include<iomanip>

double CijeliDioKvadratnogKorijena (double broj)
{
	return int (std::sqrt(broj));
}
int SumaCifara(long long int a){
	int suma(0);
	if(a/10==0) return a;
	
	while(a!=0){
		int cifra(a%10);
		
		suma+=cifra;
		a=a/10;
		
	}
	return suma;
	
}

int SumaDjelilaca(long long int a){
	
	if(a<0) a=std::abs(a);
	int suma(0);
	for(int i=1;i<=a;i++){
		if(a%i==0) suma+=i;
		
	}
	return suma;
}

int BrojProstihFaktora (long long int a){
	int brojac(0);
	for(int i=2;i<=a;i++){
		if(a%i==0){
			brojac++;
			a=a/i;
			i--;
			
		}
		
	}
	return brojac;
}

bool SavrsenBroj(long long int a){
long long int suma(0);


	for(long long int i=1;i<a;i++){
		
		if(a%i==0){
			suma+=i;
		}
		if(suma>a) break;
	
	
	}
	

	if(suma==a) {
		return true;
	}
	else{ return false;}
	
	
}



int BrojSavrsenihDjelilaca(long long int a){
	int brojac(0);

	for(long long int i=1;i<=a;i++){
		if(SavrsenBroj(i)){
			if(a%i==0) brojac++;
		}
		
	}
	
	return brojac;
}




template<typename pok1,typename pok2>
auto UvrnutiPresjek(pok1 pocetak1,pok1 iza_kraja1,pok2 pocetak2,pok2 iza_kraja2)->std::vector<std::vector<decltype(*pocetak1+0)>>{
	std::vector<std::vector<decltype(*pocetak1+0)>> a(0),a1(1,std::vector<decltype(*pocetak1+0)>(1));
	
	a1[0][0]=0;
	
	pok2 pocetak22(pocetak2);
	
	int i(0);
	while(pocetak1!=iza_kraja1){
		pocetak22=pocetak2;
		while(pocetak22!=iza_kraja2){
			if(*pocetak1==*pocetak22){
				i++;
				a.resize(i);
				a[i-1].push_back(*pocetak1);
				a[i-1].push_back(0);
				a[i-1].push_back(0);
				
			}
			pocetak22++;
		}
		pocetak1++;
	}
//	auto pocetak11(a.begin());
	
//	std::vector<std::vector<decltype(*pocetak1+0)>>::iterator it(a.begin());
	std::sort(std::begin(a),std::end(a),[](std::vector<decltype(a1[0][0]+0)> x,std::vector<decltype(a1[0][0]+0)> y){
		if(x[2]!=y[2]) return x[2]<y[2];
		else{
			if(x[0]!=y[0]) return x[0]<y[0];
			else{
				return x[1]<=y[1];
			}
		}
	});
	
	return a;
}

template<typename pok1,typename pok2,typename tip1,typename tip2>
auto UvrnutiPresjek(pok1 pocetak1,pok1 iza_kraja1,pok2 pocetak2,pok2 iza_kraja2,tip1 f(tip2))->std::vector<std::vector<decltype(*pocetak1+0)>>{
	
	std::vector<std::vector<decltype(*pocetak1+0)>> a(0),a1(1,std::vector<decltype(*pocetak1+0)>(1));
	a1[0][0]=0;
	
	
	int i(0);
	pok2 pocetak22(pocetak2);
	
	
	
	while(pocetak1!=iza_kraja1){
		
		pocetak22=pocetak2;
		
		while(pocetak22!=iza_kraja2){
			if(f(*pocetak1)==f(*pocetak22))
			{
			//	std::cout<<*pocetak1<<"-"<<*pocetak2<<"**  ";
				i++;
				
				a.resize(i);
				a[i-1].push_back(*pocetak1);
				a[i-1].push_back(*pocetak22);
				a[i-1].push_back(f(*pocetak1));
			
		}
		
	//	std::cout<<*pocetak22<<"-  ";
		pocetak22++;
	}
//	std::cout<<*pocetak1<<"++";
	pocetak1++;
	
}
//auto pocetak11(a.begin());
//std::vector<std::vector<decltype(*pocetak1+0)>>::iterator it(a.begin());

std::sort(std::begin(a),std::end(a),[](std::vector<decltype(a1[0][0]+0)> x,std::vector<decltype(a1[0][0]+0)> y){
		if(x[2]!=y[2]) return x[2]<y[2];
		else{
			if(x[0]!=y[0]) return x[0]<y[0];
			else{
				return x[1]<=y[1];
			}
		}
	});
return a;
}





template<typename pok1,typename pok2>
auto UvrnutaRazlika(pok1 pocetak1,pok1 iza_kraja1,pok2 pocetak2,pok2 iza_kraja2)->std::vector<std::vector<decltype(*pocetak1+0)>>{
	std::vector<std::vector<decltype(*pocetak1+0)>> a1(UvrnutiPresjek(pocetak1,iza_kraja1,pocetak2,iza_kraja2));
	int i(0);
	
	
	std::vector<std::vector<decltype(*pocetak1+0)>>m(0),m1(1,std::vector<decltype(*pocetak1+0)>(1));
	
	m1[0][0]=0;
	
	while(pocetak1!=iza_kraja1){
		bool pr(false);
		for(int i=0;i<a1.size();i++){
			if(*pocetak1==a1[i][0]){
				pr=true;
				break;
			}
			
		}
		if(pr)
		pocetak1++;
		else{
			i++;
			m.resize(i);
			m[i-1].push_back(*pocetak1);
			m[i-1].push_back(0);
			pocetak1++;
		}
		
	}
	while(pocetak2!=iza_kraja2){
		bool pr(false);
		for(int i=0;i<a1.size();i++){
			if(*pocetak2==a1[i][0]){
				pr=true;
				break;
			}
		}
		if(pr)
		pocetak2++;
		else{
			i++;
			m.resize(i);
			m[i-1].push_back(*pocetak2);
			m[i-1].push_back(0);
			pocetak2++;
		}
	}
//	auto pocetak11(m.begin());
	std::sort(std::begin(m),std::end(m),[](std::vector<decltype(m1[0][0]+0)> x,std::vector<decltype(m1[0][0]+0)> y){
		if(x[0]!=y[0]) return x[0]>y[0];
			else{
				return x[1]>=y[1];
			}
		
	});
	
	return m;
	
}

template<typename pok1,typename pok2, typename tip1,typename tip2>
auto UvrnutaRazlika(pok1 pocetak1, pok1 iza_kraja1, pok2 pocetak2,pok2 iza_kraja2,tip1 f(tip2))->std::vector<std::vector<decltype((*pocetak1)+0)>>{
	
	std::vector<std::vector<decltype(*pocetak1+0)>> a1(UvrnutiPresjek(pocetak1,iza_kraja1,pocetak2,iza_kraja2,f));
//	bool pr(false);
int i(0);


std::vector<std::vector<decltype(*pocetak1+0)>> m(0),m1(1,std::vector<decltype(*pocetak1+0)>(1));


m1[0][0]=0;


	while(pocetak1!=iza_kraja1){
		bool pr(false);
		for(int i=0;i<a1.size();i++){
			
			if(*pocetak1==a1[i][0]){
				pr=true;
				break;
			}
			
		}
		if(pr)
		pocetak1++;
		
		else{
			i++;
			m.resize(i);
			m[i-1].push_back(*pocetak1);
			m[i-1].push_back(f(*pocetak1));
			pocetak1++;
			
		}
		
	}
	while(pocetak2!=iza_kraja2){
		bool pr2(false);
		for(int i=0;i<a1.size();i++){
			if(*pocetak2==a1[i][1]){
				pr2=true;
				break;
			}
		}
		if(pr2) pocetak2++;
		else{
			i++;
			m.resize(i);
			m[i-1].push_back(*pocetak2);
			m[i-1].push_back(f(*pocetak2));
			pocetak2++;
		}
	}
//	auto pocetak11(m.begin());
	
//std::vector<std::vector<decltype(*pocetak1+0)>>::iterator it(m.begin());
	
	std::sort(std::begin(m),std::end(m),[](std::vector<decltype(m1[0][0]+0)> x,std::vector<decltype(m1[0][0]+0)> y){
		if(x[0]!=y[0]) return x[0]>y[0];
		
			else{
				return x[1]>=y[1];
			}
		
	});
	return m;

	
}

int main ()
{

	std::deque<int> d1;
	int n1;
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	
	int a;
	bool pr1(false);
	for(int i=0;i<=n1;i++){
		std::cin>>a;
		for(int j=0;j<d1.size();j++){
			
			if(d1[j]==a) {
				pr1=true;
				break;
			}
		}
		if(pr1){
			pr1=false;
			continue;
		}
		
		d1.push_back(a);
	}
	
	std::deque<int> d2;
	int n2;
	bool pr2(false);
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	
	
	
	
	for(int i=0;i<=n2;i++){
		std::cin>>a;
		for(int j=0;j<d2.size();j++){
			if(d2[j]==a){
				pr2=true;
				break;
			}
		}
		if(pr2){
			pr2=false;
			continue;
		}
		d2.push_back(a);
	}
	std::cout<<"Uvrnuti presjek kontejnera:";
	std::vector<std::vector<int>> rj;
	rj=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaCifara);
	std::cout<<std::endl;
	for(int i=0;i<rj.size();i++){
		for(int j=0;j<3;j++){
			std::cout<<std::setw(6)<<rj[i][j]<<" ";
			
			
		}
		std::cout<<std::endl;
	}
	
	std::cout<<"Uvrnuta razlika kontejnera:";

	std::vector<std::vector<int>> rj2(UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora));
	std::cout<<std::endl;
	for(int i=0;i<rj2.size();i++){
		for(int j=0;j<2;j++){
			std::cout<<std::setw(6)<<rj2[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	




	
	return 0;
}