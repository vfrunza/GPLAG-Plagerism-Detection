#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <type_traits>
#include <cmath>
#include <iomanip>

int hahaha (long long int x) {
	return x;
}

int hehehe (long long int x) {
	return x;
}

int SumaDjelilaca (long long int x) {
	int suma=0;
	for(long long int i=1;i<=x;i++) {
		if(x%i==0) suma+=i;
	}
	return suma;
}

bool JelSavrsen (long long int x) {
	int b=SumaDjelilaca(x);
	if(x==b/2) return true;
	return false ;
}

bool JelProst (long long int x) {
	if(x==1 or x<0) return false;
	for(long long int i=2;i<=std::sqrt(x);i++) {
		if(x%i==0) return false;
	}
	return true;
}

int BrojSavrsenihDjelilaca (long long int x) {
	int br=0;
	for(long long int i=1;i<=x;i++) {
		if(x%i==0 and JelSavrsen(i)==true) br++;
	}
	return br;
}

int BrojProstihFaktora (long long int x) {
	int br=0;
	for(long long int i=1;i<=x;i++) {
		if(x%i==0 and JelProst(i)==true) {
			br++;
			x/=i--;
			if(x==1) break;
		}
	}
	return br;
}

template <typename tip, typename pok >

bool bio (tip x, pok p,pok q) {
	while(p!=q) {
		if(*p==x) return true;
		p++;
	}
	return false ;
}

int Sumacifara(long long int x) {
	int suma=0;
	while(x!=0) {
		suma+=x%10;
		x/=10;
	}
	return std::fabs(suma);
}

template <typename pok1, typename pok2 ,typename tip1, typename tip2 >

auto UvrnutiPresjek(pok1 prvi1, pok1 prvi2, pok2 drugi1, pok2 drugi2, tip1 f(tip2)=hehehe) -> std::vector<std::vector< typename std::remove_reference<decltype(*prvi1)>::type>> {
 	int vel1=prvi2-prvi1;
 	int vel2=drugi2-drugi1;
 	int br=0;
 	std::vector<tip1> v1,v2,v3;
 	for(int i=0;i<vel1;i++) {
 		for(int j=0;j<vel2;j++) {
 			if(f(*prvi1)==f(*drugi1)) {
 				br++;
 				v1.push_back(*prvi1);
 				v2.push_back(*drugi1);
 				v3.push_back(f(*prvi1));
 			}
 			drugi1++;
 			if(drugi1==drugi2) drugi1-=vel2;
 		}
 		prvi1++;
 	}
 	std::vector<std::vector<tip1>> Matrica(br,std::vector<tip1>(3));
 	for(int i=0;i<br;i++) {
 		for(int j=0;j<3;j++) {
 			Matrica[i][0]=v1[i];
 			Matrica[i][1]=v2[i];
 			Matrica[i][2]=v3[i];
 		}
 	}
 	std::sort(Matrica.begin(),Matrica.end(),[] (std::vector<tip1> a,std::vector<tip1> b) -> bool {
 		if(a[2]>b[2]) return false;
 		else if(a[2]==b[2]) {
 			if(a[0]>b[0]) return false;
 			else if(a[0]==b[0]) {
 				if(a[1]>b[1]) return false;
 				return true ;
 			}
 			else return true ;
 		}
 		return true ;
 	});
 	return Matrica;
 }

template <typename pok1, typename pok2, typename tip1, typename tip2 > 

auto UvrnutaRazlika (pok1 poc1, pok1 kraj1, pok2 poc2, pok2 kraj2, tip1 f(tip2)=hahaha) -> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> {
	int vel1=kraj1-poc1;
	int vel2=kraj2-poc2;
	int znak=1,br=0;
	std::vector<tip1> v1;
	while(poc1!=kraj1) {
		while(poc2!=kraj2) {
			if(f(*poc1)==f(*poc2)) znak=0;
			else if (f(*poc1)!=f(*poc2) and poc2==kraj2-1 and znak==1) {
				v1.push_back(*poc1);
				br++;
			}
			poc2++;
		}
		poc2-=vel2;
		znak=1;
		poc1++;
	}
	znak=1;
	poc1=kraj1-vel1;
	poc2=kraj2-vel2;
	while(poc2!=kraj2) {
		while(poc1!=kraj1) {
			if(f(*poc1)==f(*poc2)) znak=0;
			else if(f(*poc1)!=f(*poc2) and poc1==kraj1-1 and znak==1) {
				v1.push_back(*poc2);
				br++;
			}
			poc1++;
		}
		znak=1;
		poc1-=vel1;
		poc2++;
	}
	std::vector<std::vector<tip1>> Matrica (br,std::vector<tip1>(2));
	for(int i=0;i<Matrica.size();i++) {
			Matrica[i][0]=v1[i];
			Matrica[i][1]=f(v1[i]);
	}
	std::sort(Matrica.begin(),Matrica.end(),[] (std::vector<tip1> v1, std::vector<tip1> v2) -> bool {
		if(v1[0]<v2[0]) return false;
		else if (v1[0]==v2[0]) {
			if(v1[1]<v2[1]) return false;
			return true;
		}
		return true;
	}) ;
	return Matrica;
}

int main () {
	std::deque<int> d1,d2 ;
	std::cout << "Unesite broj elemenata prvog kontejnera: " ;
	int a;
	std::cin >> a;
	std::cout <<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<a;i++) {
		int x;
		std::cin >> x;
		if(bio(x,d1.begin(),d1.end())==true) {
			i--;
			continue;
		}
		d1.push_back(x);
	}

	std::cout << "Unesite broj elemenata drugog kontejnera: " ;
	int b;
	std::cin >> b ;
	std::cout <<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<b;i++) {
		int x;
		std::cin >> x ;
		if(bio(x,d2.begin(),d2.end())==true) {
			i--;
			continue;
		}
		d2.push_back(x);
	}
	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	std::vector<std::vector<int>> v = UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(),Sumacifara);
	 for(int i=0;i<v.size();i++) {
		for(int j=0;j<v[i].size();j++) {
			std::cout << std::setw(6) << v[i][j] << " " ;
		}
		std::cout << std::endl ;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	std::vector<std::vector<int>> v1=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(),BrojProstihFaktora);
	for(int i=0;i<v1.size();i++) {
		for(int j=0;j<v1[i].size();j++) {
			std::cout << std::setw(6) << v1[i][j] << " " ;
		}
		std::cout << std::endl;
	}
	std::cout << "Dovidjenja!" ; 
	return 0;
}