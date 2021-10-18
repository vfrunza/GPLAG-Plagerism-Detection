#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iomanip>
typedef std::vector<std::vector<int>> Matrica;
int BrojSavrsenihDjelilaca(long long int broj){
	int a{0};
	long long int suma{0};
	long long int niz[100];
	for(long long int i=1; i<=broj; i++){
		if(broj%i==0){
			for(long long int j=1; j<i; j++){
				if(i%j==0) suma=suma+j;
			}
			if(suma==i){niz[a]=i; a++;}
			suma=0;
		}
	}
	return a;
}
int BrojProstihFaktora(long long int broj1){
	int brojpf{0};
	long long int broj{broj1};
	    if(broj==0 || broj==1) return 0;
	    if(broj<0) broj=broj*(-1);
		for(int j=2; j<=broj; j++){
			if(broj%j==0){
				broj=broj/j; 
				j--; 
				brojpf++;
				if(broj==1) return brojpf;
			}
		}
	return brojpf;
}
int SumaDjelilaca(long long int broj){
	int suma{0};
	if(broj==0) return 0;
	if(broj<0) broj=broj*(-1);
	for(int i=1; i<=broj; i++){
		if(broj%i==0) suma=suma+i;
	}
	return suma;
}
int f(long long int x){
 int ostatak{0}, suma{0};
    if(x==0) return suma;
	while(x>0){
		ostatak=x%10;
		x=(x-ostatak)/10;
		suma=suma+ostatak;
	}
	return suma;
}
template <typename NekiTip1, typename NekiTip2, typename NekiTip3>
Matrica UvrnutaRazlika(NekiTip1 p1, NekiTip1 p2, NekiTip2 p3, NekiTip2 p4, int BrojProstihFaktora(NekiTip3)){
	Matrica a;
	NekiTip2 pomoc{p3};
	NekiTip1 pomoc1{p1};
	int broj1{0}, broj2{0}, brojac{0}, ind{0};
	int niz1[100], niz2[100];
	while(p1!=p2){
		broj1=BrojProstihFaktora(*p1);
		while(p3!=p4){
			broj2=BrojProstihFaktora(*p3);
			if(broj1==broj2){
			 ind=1;
			}
		 p3++;	
		}
	 if(ind==0){
	 	niz1[brojac]=*p1;
	 	niz2[brojac]=broj1;
	 	brojac++;
	 }
	 ind=0;
	 p1++;
	 p3=pomoc;
	}
	ind=0;
	p1=pomoc1;
	while(p3!=p4){
	    broj2=BrojProstihFaktora(*p3);
	    while(p1!=p2){
	    	broj1=BrojProstihFaktora(*p1);
	    	if(broj2==broj1){
	    		ind=1;
	    	}
	    	p1++;
	    }
	    if(ind==0){
	    	niz1[brojac]=*p3;
	    	niz2[brojac]=broj2;
	    	brojac++;
	    }
	    ind=0;
	    p3++;
	    p1=pomoc1;
	}
	a.resize(brojac);
	for(int i=0; i<brojac; i++) a[i].resize(2);
	for(int i=0; i<brojac; i++){
		a[i][0]=(int)niz1[i];
		a[i][1]=(int)niz2[i];
	}
	std::sort(a.begin(), a.end(), [](std::vector<int>v1, std::vector<int>v2)->bool{if(v1[0]==v2[0]) return v1[1]>v2[1]; else return v1[0]>v2[0];});
	return a;
}
template <typename NekiTip1, typename NekiTip2, typename NekiTip3>
  Matrica UvrnutiPresjek(NekiTip1 p1, NekiTip1 p2, NekiTip2 p3, NekiTip2 p4, int f(NekiTip3)) {
	Matrica a;
	NekiTip2 pomoc{p3};
	int suma1{0}, suma2{0}, brojac{0};
	int niz1[100];
	int niz2[100];
	int niz3[100];
	while(p1!=p2){
		suma1=f(*p1);
		while(p3!=p4){
			suma2=f(*p3);
			if(suma1==suma2){
				niz1[brojac]=*p1;
				niz2[brojac]=*p3;
				niz3[brojac]=suma1;
				brojac++;
			}
			p3++;
		}
		p1++;
		p3=pomoc;
	}
 a.resize(brojac);
 for(int i=0; i<brojac; i++) a[i].resize(3);
 for(int i=0; i<brojac; i++){
 	a[i][0]=(int)niz1[i];
 	a[i][1]=(int)niz2[i];
 	a[i][2]=niz3[i];
 }
std::sort(a.begin(), a.end(), [](std::vector<int>v1, std::vector<int> v2)->bool{if(v1[2]==v2[2] && v1[0]==v2[0]) return v1[1]<v2[1]; else if(v1[2]==v2[2] && v1[0]!=v2[0]) return v1[0]<v2[0]; else return v1[2]<v2[2];});
 return a;
}
template <typename NekiTip1, typename NekiTip2>
Matrica UvrnutiPresjek(NekiTip1 p1, NekiTip1 p2, NekiTip2 p3, NekiTip2 p4){
	Matrica a;
	NekiTip2 pomoc{p3};
	int ind{0}, niz1[100], brojac{0};
	while(p1!=p2){
		while(p3!=p4){
			if(*p1==*p3) ind=1;
			p3++;
		}
		if(ind==1) {niz1[brojac]=*p1; brojac++;}
		ind=0;
		p1++;
		p3=pomoc;
	}
	a.resize(brojac);
	for(int i=0; i<brojac; i++) a[i].resize(3);
	for(int i=0; i<brojac; i++){
		a[i][0]=(int)niz1[i];
		a[i][1]=0;
		a[i][2]=0;
	}
	std::sort(a.begin(), a.end(), [](std::vector<int>v1, std::vector<int>v2)->bool{return v1[0]<v2[0];});
	return a;
}
template <typename NekiTip1, typename NekiTip2>
Matrica UvrnutaRazlika(NekiTip1 p1, NekiTip1 p2, NekiTip2 p3, NekiTip2 p4){
	Matrica a;
	NekiTip1 pomoc{p1};
	NekiTip2 pomoc1{p3};
	int ind{0}, niz1[100], brojac{0};
	while(p3!=p4){
		while(p1!=p2){
			if(*p1==*p3) ind=1;
			p1++;
		}
		if(ind==0) {niz1[brojac]=*p3; brojac++;}
		ind=0;
		p3++;
		p1=pomoc;
	}
	p1=pomoc;
	ind=0;
	while(p1!=p2){
		while(p3!=p4){
			if(*p1==*p3) ind=1;
			p3++;
		}
		if(ind==0) {niz1[brojac]=*p1; brojac++;}
		ind=0;
		p1++;
		p3=pomoc1;
	}
	a.resize(brojac);
	for(int i=0; i<brojac; i++) a[i].resize(2);
	for(int i=0; i<brojac; i++){
		a[i][0]=niz1[i];
		a[i][1]=0;
	}
	std::sort(a.begin(),a.end(),[](std::vector<int>v1, std::vector<int>v2)->bool{return v1[0]>v2[0];});
	return a;
}
int main (){
	int broj1, broj2, i{0};
	std::deque<int>d1;
	std::deque<int>d2;
	std::cout <<"Unesite broj elemenata prvog kontejnera: ";
	std::cin >>broj1;
	int x, ind{0};
	std::cout <<"Unesite elemente prvog kontejnera: ";
	while(i!=broj1){
		if(i==broj1) break;
		std::cin >>x;
		for(int k=0; k<d1.size(); k++){
			if(x==d1[k]) ind=1;
		}
		if(ind==0) {d1.push_back(x); i++;}
		ind=0;
	}
	ind=0;
	i=0;
	std::cout <<"Unesite broj elemenata drugog kontejnera: ";
	std::cin >>broj2;
	std::cout <<"Unesite elemente drugog kontejnera: ";
	while(i!=broj2){
		if(i==broj2) break;
		std::cin >>x;
		for(int k=0; k<d2.size(); k++){
			if(x==d2[k]) ind=1;
		}
		if(ind==0) {d2.push_back(x); i++;}
		ind=0;
	}
    Matrica a;
    a.resize(d1.size()*d2.size());
    for(int i=0; i<d1.size()*d2.size(); i++) a[i].resize(3);
	a=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), f);
//    a=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end());
 //   a=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),SumaDjelilaca);
	std::cout <<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<a.size(); i++) {
	 for(int j=0; j<a[0].size(); j++){
	 	std::cout<<std::setw(6)<<std::right<<a[i][j]<<" ";
	 }	
	 std::cout<<std::endl;
	}
	std::cout <<"Uvrnuta razlika kontejnera:"<<std::endl;
	Matrica b;
	b.resize(d1.size()*d2.size());
	for(int i=0; i<d1.size()*d2.size(); i++) b[i].resize(2);
	b=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(), BrojProstihFaktora);
//	b=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end());
 //   b=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(), SumaDjelilaca);
	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[0].size(); j++){
			std::cout<<std::setw(6)<<std::right<<b[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout <<"Dovidjenja!"<<std::endl;
	return 0;
}