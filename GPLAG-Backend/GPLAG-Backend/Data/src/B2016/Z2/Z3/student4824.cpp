#include <iostream>
#include <deque>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::deque;
using std::vector;

int SumaDjelilaca(long long int broj){
	int rezultat(0);
	for(int i=1;i<broj;i++){
		if(broj%i==0) rezultat+=i;
	}
    return rezultat;
}

int BrojProstihFakora(long long int broj){
	int brojac(0);
	long long int b;
	if(broj==1) brojac=1;
	else{
		int k(broj%2);
		while(k==0){
			b=broj/2;
			broj=b;
			k=broj%2;
			brojac++;
		}
		for(int i=3;i<=broj;i+=2){
			 int p(broj/i);
			 while(p==0){
			 	b=broj/i;
			 	broj=b;
			 	p=broj/i;
			 	brojac++;
			 }
		}
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int broj){
	int brojac(0);
	for(int i=1;i<broj;i++){
		if(broj%i==0){
			int suma(0),j(1);
			for(j=1;j<i;j++){
				if(i%j==0){
					suma+=j;
				}
			}
			if(suma==j) brojac++;
		}
	}
	return brojac;
}


template <typename tip1,typename tip2>
deque<deque<int>> UvrnutiPresjek(tip1 pocetak1,tip1 iza_kraja1,tip2 pocetak2,tip2 iza_kraja2,int f(int)){
	
	int vel1(std::distance(pocetak1,iza_kraja1)),vel2(std::distance(pocetak2,iza_kraja2));
	int brojac(0);
	for(int i=0;i<vel1;i++){
		for(int j=0;j<vel2;j++){
			if(f(pocetak1[i])==f(pocetak2[j])) brojac++;
		}
	}
	deque<deque<int>> Rezultat(brojac);
	for(int i=0;i<brojac;i++){
		Rezultat[i].resize(3);
	}
	int x(0);
	for(int i=0;i<vel1;i++){
		for(int j=0;j<vel2;j++){
			if(f(pocetak1[i])==f(pocetak2[j])){
				Rezultat[x][0]=pocetak1[i];
				Rezultat[x][1]=pocetak2[j];
				Rezultat[x][3]=f(pocetak1[i]);
				x++;
			}
		}
	}
	return Rezultat;
}


int main ()
{
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int br1;
	cin>>br1;
	deque<int> dek_1(br1);
	cout<<"Unesite elemente prvog kontejnera:";
	for(int i=0;i<br1;i++){
		cin>>dek_1[i];
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int br2;
	cin>>br2;
	cout<<"Unesite elemenata drugog kontejnera: ";
	deque<int> dek_2(br2);
	for(int i=0;i<br2;i++){
		int x;
		cin>>x;
		bool isti(false);
		for(int j=0;j<i;j++){
			if(x==dek_1[j]) isti=true;
		}
		if(isti) i--;
		else dek_2[i]=x;
	}
    cout<<"Uvrnuti presjek kontejnera: "<<endl;
    deque<deque<int>> Presjek;
    Presjek=UvrnutiPresjek(dek_1.begin(),dek_1.end(),dek_2.begin(),dek_2.end(),[] (int x)->int{return x;});
	for(int i=0;i<Presjek.size();i++){
		for(int j=0;j<Presjek[i].size();j++){
			cout<<Presjek[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera: "<<endl;
	
	
	cout<<"Dovidjenja!";
	return 0;
}