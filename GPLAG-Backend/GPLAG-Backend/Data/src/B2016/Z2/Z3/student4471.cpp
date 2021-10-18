#include <iostream>
#include <vector>
#include <deque>
//#include <type_traits>
#include <algorithm>
#include <iomanip>
#include <cmath>


int SumaDjelilaca(long long int x){
	
	long long int suma(0);
	for(long long int i=1;i<=abs(x);i++){
		if(x%i==0)suma+=i;
	}
	
	return suma;
}

bool jeliProst(long long int x){
	int prost(true);
	
	for(long long int i=2;i<abs(x);i++){
		if(x%2==0){
			prost = false;
			break;
		}
	}
	return prost;
}

int BrojProstihFaktora(long long int x){
	
	int brojac(0);
	
	for(long long int i=2;i<=abs(x);i++){
		
		//if(x%i==0 && jeliProst(i)==true)brojac++;
		while(x%i==0 && jeliProst(i)==true){
			brojac++;
			x/=i;
		}
	}
	
	return brojac;
}

bool jeliSavrsen(long long int x){
	
	long long int suma(0);
	for(long long int i=1;i<abs(x);i++){
		if(x%i==0)suma+=i;
	}
	if(suma==x)return true;
	return false;
}


int BrojSavrsenihDjelilaca(long long int x){
	
	long long int brojac = 0;
	for(long long int i=2;i<=abs(x);i++){          //mozda treba samo manje od x
		if(x%i==0 && jeliSavrsen(i)==true)brojac++;
	}
	
	return brojac;
}


long long int sumaCifara(long long int x){
	long long int suma = 0;
	while(x != 0){
		suma+=abs(x%10);
		x =  x/10;
	}
	return suma;
}



template <typename IterTip1,typename IterTip2,typename TipElementa1,typename TipElementa2>
auto UvrnutiPresjek(IterTip1 p1,IterTip1 p2,IterTip2 q1,IterTip2 q2, TipElementa1 fun(TipElementa2 x) )-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	
	typedef typename std::remove_reference<decltype(*p1)>::type tip;

	
	int brojac(0);

	
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		for(IterTip2 q=q1;q!=q2;q++){
			if(fun(*p) == fun(tip(*q)))brojac++;
		}
	}
	
	//kreiramo matricu sa n redova
	std::vector<std::vector<tip>>v;
	try{
		v.resize(brojac);
	}catch(...){
		throw std::bad_alloc();
	}
	
		int h = 0;
		
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		for(IterTip2 q=q1;q!=q2;q++){
			if(fun(*p) == fun(*q)){
				v[h].push_back(*p);
				v[h].push_back(tip(*q));
				v[h].push_back(tip(fun(*p)));
				h++;
			}
		}
	}
	
	
	//soritranje
	std::sort(v.begin(),v.begin()+brojac,[](std::vector<tip> v1,std::vector<tip>v2){
		
		if(v1.at(2)<v2.at(2))return true;   //prvo provjerimo treci element
		if((v1.at(2)==v2.at(2)) && v1.at(0)<v2.at(0))return true;		//onda prvi
		if( (v1.at(2)==v2.at(2)) && v1.at(0)==v2.at(0) && v1.at(1)<v2.at(1))return true;	//pa drugi...
		
		return false;
	});
	
	return v;
	
}   


template <typename IterTip1,typename IterTip2>
auto UvrnutiPresjek(IterTip1 p1,IterTip1 p2,IterTip2 q1,IterTip2 q2)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	
	typedef typename std::remove_reference<decltype(*p1)>::type tip;

	
	int brojac(0);

	
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		for(IterTip2 q=q1;q!=q2;q++){
			if(*p == tip(*q))brojac++;
		}
	}
	
	//kreiramo matricu sa n redova
	std::vector<std::vector<tip>>v;
	try{
		v.resize(brojac);
	}catch(...){
		throw std::bad_alloc();
	}
	
		int h = 0;
		
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		for(IterTip2 q=q1;q!=q2;q++){
			if(*p == tip(*q)){
				v[h].push_back(*p);
				v[h].push_back(tip(0));
				v[h].push_back(tip(0));
				h++;
			}
		}
	}
	
	
	//soritranje
	std::sort(v.begin(),v.begin()+brojac,[](std::vector<tip> v1,std::vector<tip>v2){
		
		if(v1.at(2)<v2.at(2))return true;   //prvo provjerimo treci element
		
		return false;
	});
	
	return v;
	
}


template <typename IterTip1,typename IterTip2,typename TipElementa1,typename TipElementa2>
auto UvrnutaRazlika(IterTip1 p1,IterTip1 p2,IterTip2 q1,IterTip2 q2, TipElementa1 fun(TipElementa2 x) )-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	
	typedef typename std::remove_reference<decltype(*p1)>::type tip;
	
	int brojac = 0;
	int flag = 1;
	
	//prvo prodjemo kroz prvi niz i trazimo elemenete koji nemaju para u drugom nizu 
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		flag = 1;
		for(IterTip2 q=q1;q!=q2;q++){
			if(fun(*p) == fun(*q)){flag = 0;break;}
		}
		if(flag)brojac++;
	}
	
	//sada isto za drugi niz 
	for(IterTip2 q=q1 ;q!=q2; q++ ){
		flag = 1;
		for(IterTip1 p=p1;p!=p2;p++){
			if(fun(*p) == fun(*q)){flag = 0;break;}
		}
		if(flag)brojac++;
	}
	
	
	//kreiramo matricu sa n redova
	std::vector<std::vector<tip>>v(brojac);
	
	
	
	
	int h = 0;
		//kroz prvi niz 
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		flag  = 1;
		for(IterTip2 q=q1;q!=q2;q++){
			if(fun(*p) == fun(tip(*q))){flag = 0;break;}
			
		}
		
		if(flag){
			v[h].push_back(*p);
			v[h].push_back(fun(*p));
			h++;
		}
	}
	
	for(IterTip2 q=q1 ;q!=q2; q++ ){
		flag  = 1;
		for(IterTip1 p=p1;p!=p2;p++){
			if(fun(*p) == fun(*q)){flag = 0;break;}
			
		}
		
		if(flag){
			v[h].push_back(*q);
			v[h].push_back(fun(*q));
			h++;
		}
	}
	
	//soritranje
	
	std::sort(v.begin(),v.begin()+brojac,[](std::vector<tip> v1,std::vector<tip>v2){
		
		if(v1.at(0)>v2.at(0))return true;   //prvo provjerimo prvi element
		if((v1.at(0)==v2.at(0)) && v1.at(1)>v2.at(1))return true;
		return false;
	}); 
	
	return v;
	

}	
  

//fja razlika sa 4 parametra

template <typename IterTip1,typename IterTip2>
auto UvrnutaRazlika(IterTip1 p1,IterTip1 p2,IterTip2 q1,IterTip2 q2)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	
	typedef typename std::remove_reference<decltype(*p1)>::type tip;
	
	int brojac = 0;
	int flag = 1;
	
	//prvo prodjemo kroz prvi niz i trazimo elemenete koji nemaju para u drugom nizu 
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		flag = 1;
		for(IterTip2 q=q1;q!=q2;q++){
			if(*p == *q){flag = 0;break;}
		}
		if(flag)brojac++;
	}
	
	//sada isto za drugi niz 
	for(IterTip2 q=q1 ;q!=q2; q++ ){
		flag = 1;
		for(IterTip1 p=p1;p!=p2;p++){
			if(*p == *q){flag = 0;break;}
		}
		if(flag)brojac++;
	}
	
	
	//kreiramo matricu sa n redova
	std::vector<std::vector<tip>>v(brojac);
	
	
	
	
	int h = 0;
		//kroz prvi niz 
	for(IterTip1 p=p1 ;p!=p2; p++ ){
		flag  = 1;
		for(IterTip2 q=q1;q!=q2;q++){
			if(*p == *q){flag = 0;break;}
			
		}
		
		if(flag){
			v[h].push_back(*p);
			v[h].push_back(tip());
			h++;
		}
	}
	
	for(IterTip2 q=q1 ;q!=q2; q++ ){
		flag  = 1;
		for(IterTip1 p=p1;p!=p2;p++){
			if(*p == *q){flag = 0;break;}
			
		}
		
		if(flag){
			v[h].push_back(*q);
			v[h].push_back(tip());
			h++;
		}
	}
	
	//soritranje
	
	std::sort(v.begin(),v.begin()+brojac,[](std::vector<tip> v1,std::vector<tip>v2){
		
		if(v1.at(0)>v2.at(0))return true;   //prvo provjerimo prvi element
		if((v1.at(0)==v2.at(0)) && v1.at(1)>v2.at(1))return true;
		return false;
	}); 
	
	return v;
	

}	
  



int main ()
{
	
	int n1,n2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	
	std::deque<int> v1;
	int temp;
	
	for(int i=0;i<n1;i++){
		std::cin>>temp;
		
		while(1){
			if(std::find(v1.begin(),v1.end(),temp)!= v1.end()){
				std::cin>>temp;
			}else {
				v1.push_back(temp);
				break;
			}
		}
	
	}
	
	
//	std::cin.ignore(1000,'\n');
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::deque<int> v2;
	std::cout<<"Unesite elemente drugog kontejnera: ";

for(int i=0;i<n2;i++){
		std::cin>>temp;
		
		while(1){
			if(std::find(v2.begin(),v2.end(),temp)!= v2.end()){
				std::cin>>temp;
			}else {
				v2.push_back(temp);
				break;
			}
		}
	
	}

	

	auto v = UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),sumaCifara);

	auto g = UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora);
	
	
	
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(std::vector<int> &red: v){
		for(int &x: red)std::cout<<std::setw(6)<<x<<" ";
		std::cout<<std::endl;
	}
	
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(std::vector<int> &red: g){
		for(int &x: red)std::cout<<std::setw(6)<<x<<" ";
		std::cout<<std::endl;
	}
	
	std::cout<<"Dovidjenja!"<<std::endl;
	return 0;
}

