#include <iostream>
#include <vector>
#include <deque>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;


template<typename pokTip1,typename pokTip2>
auto UvrnutiPresjek(pokTip1 p1,pokTip1 k1,pokTip2 p2, pokTip2 k2)
-> vector<vector<decltype(*p1+*p1)>> {
	std::vector<std::vector<decltype(*p1+*p1)>> rezultat;
	pokTip2 poc2=p2;

	while(p1!=k1) {
		p2 = poc2;
		while(p2!=k2) {
			std::vector<decltype(*p1+*p1)> v ;

			if(*p1==*p2) {
				v.push_back(*p1);
				v.push_back(0);
				v.push_back(0);
				rezultat.push_back(v);
			}

			p2++;
		}


		p1++;

	}
		
	sort(rezultat.begin(),rezultat.end(),[](vector<decltype(*p1+*p1)>v1, vector<decltype(*p2+*p2)>v2)->bool{
		if(v1[2]<v2[2]) return true;
		else if(v1[2]==v2[2]) {
			if(v1[0]<v2[0]) {
				return true;
			} else if(v1[0]==v2[0]) {
				if(v1[1]<v2[1]) {
					return true;
				}

			}
		}

		return false;
	});

	return rezultat;
}




template<typename pokTip1,typename pokTip2,typename FunkcijskiTip>

auto UvrnutiPresjek(pokTip1 p1,pokTip1 k1,pokTip2 p2, pokTip2 k2, FunkcijskiTip f)
-> vector<vector<decltype(*p1+*p1)>> {
	std::vector<std::vector<decltype(*p1+*p1)>> rezultat;
	pokTip2 poc2=p2;

	while(p1!=k1) {
		p2 = poc2;
		while(p2!=k2) {
			std::vector<decltype(*p1+*p1)> v ;

			if(f(*p1)==f(*p2)) {
				v.push_back(*p1);
				v.push_back(*p2);
				v.push_back(f(*p1));
				rezultat.push_back(v);
			}

			p2++;
		}


		p1++;

	}


	sort(rezultat.begin(),rezultat.end(),[](vector<decltype(*p1+*p1)>v1, vector<decltype(*p2+*p2)>v2)->bool{
		if(v1[2]<v2[2]) return true;
		else if(v1[2]==v2[2]) {
			if(v1[0]<v2[0]) {
				return true;
			} else if(v1[0]==v2[0]) {
				if(v1[1]<v2[1]) {
					return true;
				}

			}
		}

		return false;
	});
	return rezultat;
}





template<typename pokTip1,typename pokTip2,typename FunkcijskiTip>

auto UvrnutaRazlika(pokTip1 p1,pokTip1 k1,pokTip2 p2, pokTip2 k2, FunkcijskiTip f)
-> vector<vector<decltype(*p1+*p1)>> {
	std::vector<std::vector<decltype(*p1+*p1)>> rezultat;
	pokTip2 poc2=p2;
	pokTip2 poc1=p1;

	while(p1!=k1) {
		p2 = poc2;
		std::vector<decltype(*p1+*p1)> v ;
		bool postoji = false;
		while(p2!=k2) {
			if(f(*p1)==f(*p2)) {
				postoji = true;
				break;
			}
			p2++;
		}
		if(!postoji) {
			v.push_back(*p1);
			v.push_back(f(*p1));
			rezultat.push_back(v);
		}
		p1++;
	}

	p1 = poc1;
	p2 = poc2;



	while(p2!=k2) {
		p1 = poc1;
		std::vector<decltype(*p1+*p1)> v ;
		bool postoji = false;
		while(p1!=k1) {
			if(f(*p2)==f(*p1)) {
				postoji = true;
				break;
			}
			p1++;
		}
		if(!postoji) {
			v.push_back(*p2);
			v.push_back(f(*p2));
			rezultat.push_back(v);
		}
		p2++;
	}






	sort(rezultat.begin(),rezultat.end(),[](vector<decltype(*p1+*p1)>v1, vector<decltype(*p2+*p2)>v2)->bool{
		if(v1[0]>v2[0]) return true;
		else if(v1[0]==v2[0]) {
			if(v1[1]>v2[1]) return true;
		}
		return false;
	});
	return rezultat;
}



template<typename pokTip1,typename pokTip2>
auto UvrnutaRazlika(pokTip1 p1,pokTip1 k1,pokTip2 p2, pokTip2 k2)
-> vector<vector<decltype(*p1+*p1)>> {
	std::vector<std::vector<decltype(*p1+*p1)>> rezultat;
	pokTip1 poc1=p1;
	pokTip2 poc2=p2;

	while(p1!=k1) {
		
		
		std::vector<decltype(*p1+*p1)> v ;
		bool duplikat=false;
		while(p2!=k2) {
			if(*p1==*p2) {
				duplikat=true;
				break;
			}
			p2++;
		}
		if(!duplikat){
			v.push_back(*p1);
			v.push_back(0);
			rezultat.push_back(v);
		}

		p1++;
		p2 = poc2;
	}

	while(p2!=k2) {
		p1 = poc1;
		
		std::vector<decltype(*p1+*p1)> v ;
		bool duplikat=false;
		while(p1!=k1) {
			if(*p1==*p2) {
				duplikat=true;
				break;
			}
			p1++;
		}
		if(!duplikat){
			v.push_back(*p2);
			v.push_back(0);
			rezultat.push_back(v);
		}

		p2++;

	}
	sort(rezultat.begin(),rezultat.end(),[](vector<decltype(*p1+*p1)>v1, vector<decltype(*p2+*p2)>v2)->bool{
		if(v1[0]>v2[0]) return true;
		else if(v1[0]==v2[0]) {
			if(v1[1]>v2[1]) return true;
		}
		return false;
	});
	return rezultat;
}




long long int SumaDjelilaca(int broj)
{
	long long int suma=0;

	for (int i = 1; i <= broj; i++) {
		if(broj%i==0){
			suma+=i;
		}
	}
	return suma;
}

bool prost(int broj){
	for (int i = 2; i <= broj/2; i++) {
		if(broj%i==0)return false;
	}
	return true;
}

long long int BrojProstihFaktora(int broj)
{
	int brojac=0;
	int kopija=broj;
	for (int i = 2; i <= broj; i++) {
		if(prost(i)&&broj%i==0){
			while(kopija%i==0){
				brojac++;
				kopija=kopija/i;
			}
			if(kopija==1)break;
		}
	}
	return brojac;
}



bool savrsenBroj(int broj){
	
	return (SumaDjelilaca(broj)-broj) == broj;
}

long long int BrojSavrsenihDjelilaca(int broj){
	int brojac=0;
	
	for (int i = 1; i <= broj; i++) {
		if(savrsenBroj(i)&&broj%i==0){
			brojac++;
		}
	}
	
	return brojac;
}

int main ()
{
	deque<int>d1,d2;
	int brojEl1,brojEl2;
	
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>brojEl1;
	cout<<"Unesite elemente prvog kontejnera: ";
	string s;
	for (int i = 0; i <brojEl1 ; i++) {
		int broj;
		cin>>broj;
		bool duplikat = false;
		for (int i = 0; i < d1.size(); i++) {
			if(broj==d1[i]){
				duplikat=true;
				break;
			}
		}
		if(!duplikat)
			d1.push_back(broj);
		else
			i--;
	}
	//getline(cin,s,'\n');

	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>brojEl2;
	cout<<"Unesite elemente drugog kontejnera: ";
	
	for (int i = 0; i <brojEl2 ; i++) {
		int broj;
		cin>>broj;
		bool duplikat = false;
		for (int i = 0; i < d2.size(); i++) {
			if(broj==d2[i]){
				duplikat=true;
				break;
			}
		}
		if(!duplikat)
			d2.push_back(broj);
		else
			i--;
	}

	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	
	
	std::vector<std::vector<int>> P = UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),[](int broj){
		int suma=0;
		while(broj!=0){
			suma+=broj%10;
			broj/=10;
		}
		return suma;
	});
	
	
	for (int i = 0; i < P.size(); i++) {
		cout<<setw(6)<<P[i][0]<<" "<<setw(6)<<P[i][1]<<" "<<setw(6)<<P[i][2]<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;

	std::vector<std::vector<int>> R = UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	for (int i = 0; i < R.size(); i++) {
		cout<<setw(6)<<R[i][0]<<" "<<setw(6)<<R[i][1]<<" "<<endl;
	}
	cout<<"Dovidjenja!";
	return 0;
}