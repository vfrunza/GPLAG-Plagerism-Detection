#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <deque>
#include <cmath>
#include <type_traits>
#include <limits>
#include <iomanip>

int SumaCifri(long long int a){
	int suma(0);
	while(a!=0){
		suma+=std::abs(a%10); a/=10;
	}
	return suma;
}

int SumaDjelilaca(long long int a){
	int suma_d(0);
	if(a==0) return suma_d;
	if(a<0){
		for(long long int (i)=-1 ; i>=a; i--){
			if(a%i == 0) suma_d+= std::abs(int(i));
		}
		return suma_d;
	}
	else {
		for(unsigned long long int (i)=1 ; i<=a; i++){
			if(a%i == 0) suma_d+= std::abs(int(i));
		}
		return suma_d;
	}
}

int BrojProstihFaktora(long long int a){
	int broj_prostih(0);
	if(a==0) return broj_prostih;
	if(a<0){
		for(long long int (i)=-2 ; i>=a; i--){
			if(a%i==0){
				int brojac(0);
				for(long long int (j)=-2 ; j>i; i--){
					if(i%j == 0)brojac++;
				}
				if(brojac==0){
					broj_prostih++;
					a/=i;
					i=-1;
				}
			}
		}
	}
	else{
		for(unsigned long long int (i)=2 ; i<=a; i++){
			if(a%i==0){
				int brojac(0);
				for(unsigned long long int (j)=2; j<i ; j++){
					if(i%j == 0) brojac++;
				}
				if(brojac==0){
					broj_prostih++;
					a/=i;
					i=1;
				}
			}
			
		}
	}
	return broj_prostih;
}



int BrojSavrsenihDjelilaca(long long int a){
	int broj_djelilaca(0);
	if(a==0) return broj_djelilaca;
	a=std::abs(a);
	for(long long int i=2 ; i<=a; i++ ){
		if(a%i==0){
			//PROVJERA ZA SAVRSENI I
			int suma(0);
			for(int j=1; j<i; j++)if(i%j==0) suma+=j;
			if(suma==i) broj_djelilaca++;
		}
	}
	return broj_djelilaca;
}

template <typename Tip1, typename Tip2, typename Funkc1 , typename Funkc2 >
auto UvrnutiPresjek(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2, Funkc1 f(Funkc2))->std::vector<std::vector<decltype(*a1+*a1)>>{
	Tip1 x1(a1);
	Tip2 y1(b1);
	std::vector<std::vector<decltype(*a1+*a1)>> Vektor_Matrica;
	while(x1!=a2){
		y1=b1;
		while(y1!=b2){
			if(f(*x1)==f(*y1)){
				std::vector<decltype(*a1+*a1)> Vektor_Red;
				Vektor_Red.push_back(*x1);
				Vektor_Red.push_back(*y1);
				Vektor_Red.push_back(f(*x1));
				Vektor_Matrica.push_back(Vektor_Red);
				
			}
			y1++;
		}
		x1++;
	}
	std::sort(Vektor_Matrica.begin(),Vektor_Matrica.end(),[](const std::vector<decltype(*a1+*a1)> a, const std::vector<decltype(*a1+*a1)> b){
		if(a[2]==b[2]){
			if(a[0]==b[0]){
				if(a[1]>b[1]) return false;
				return true;
			}
			else if(a[0]<b[0]) return true;
			else return false;
			
		}
		else if(a[2]<b[2]) return true;
		return false;
	});
	
	return Vektor_Matrica;
}

template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2)->std::vector<std::vector<decltype(*a1+*a1)>>{
	Tip1 x1(a1);
	Tip2 y1(b1);
	std::vector<std::vector<decltype(*a1+*a1)>> Vektor_Matrica;
	while(x1!=a2){
		y1=b1;
		while(y1!=b2){
			if(*x1 == *y1){
				std::vector<decltype(*a1+*a1)> Vektor_Red;
				Vektor_Red.push_back(*x1);
				Vektor_Red.push_back(0);
				Vektor_Red.push_back(0);
				Vektor_Matrica.push_back(Vektor_Red);
			}
			y1++;
		}
		x1++;
	}
	std::sort(Vektor_Matrica.begin(),Vektor_Matrica.end(),[](const std::vector<decltype(*a1+*a1)> a, const std::vector<decltype(*a1+*a1)> b){
		if(a[0]>b[0]) return false; return true;
	});
	return Vektor_Matrica;
}
template  <typename Tip1, typename Tip2, typename Funkc1 , typename Funkc2 >
auto UvrnutaRazlika(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2, Funkc1 f (Funkc2)) -> std::vector<std::vector<decltype(*a1+*a1)>>{
	std::vector<std::vector< decltype(*a1+*a1)>> Vektor_Matrica;
	Tip1 x(a1);
	Tip2 y(b1);
	while(x!=a2){
		y=b1;
		int brojac(0);
		while(y!=b2){
			if(f(*x)==f(*y))brojac++;
			y++;
		}
		if(brojac==0){
			std::vector<decltype(*a1+*a1)> Vektor_Red;
			Vektor_Red.push_back(*x);
			Vektor_Red.push_back(f(*x));
			Vektor_Matrica.push_back(Vektor_Red);
		}
		x++;
	}
	x=a1;
	y=b1;
	while(y!=b2){
		x=a1;
		int brojac=0;
		while(x!=a2){
			if(f(*x)==f(*y))brojac++;
			x++;
		}
		if(brojac==0){
			std::vector<decltype(*a1+*a1)> Vektor_Red;
			Vektor_Red.push_back(*y);
			Vektor_Red.push_back(f(*y));
			Vektor_Matrica.push_back(Vektor_Red);
		}
		y++;
	}
	std::sort(Vektor_Matrica.begin(), Vektor_Matrica.end(),[](const std::vector<decltype(*a1+*a1)> a, const std::vector<decltype(*a1+*a1)> b){
		if(a[0]==b[0]){
			if(a[1]<b[1]) return false;
			return true;
		}
		else if(a[0]>b[0]) return true;
		return false;
	} );
	return Vektor_Matrica;
}


template  <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 a1, Tip1 a2, Tip2 b1, Tip2 b2)-> std::vector<std::vector<decltype(*a1+*a1)>>{
	Tip1 x(a1);
	Tip2 y(b1);
	int brojac(0);
	std::vector<std::vector< decltype(*a1+*a1)>> Vektor_Matrica;
	while(x!=a2){
		y=b1; 
		brojac=0; 
		while(y!=b2){
			if (*x == *y){
				brojac++; 
				}
				y++;
			
		}
		if(brojac==0){
			std::vector<decltype(*a1+*a1)> Vektor_Red;
			Vektor_Red.push_back(*x);
			Vektor_Red.push_back(0);
			Vektor_Matrica.push_back(Vektor_Red);
		} x++;}
	x=a1; 
	y=b1;
	while(y!=b2){
		x=a1; 
		brojac=0; 
		while(x!=a2){
			if(*y == *x) {
				brojac++;
			}
			x++;
		} 
		if(brojac==0){
			std::vector<decltype(*a1+*a1)> Vektor_Red;
			Vektor_Red.push_back(*y);
			Vektor_Red.push_back(0);
			Vektor_Matrica.push_back(Vektor_Red);
		}y++;}
	
	std::sort(Vektor_Matrica.begin(),Vektor_Matrica.end(),[](const std::vector<decltype(*a1+*a1)> a, const std::vector<decltype(*a1+*a1)> b){
		if(a[0]<b[0]) return false; return true;
	});
	
	return Vektor_Matrica;
}

int main (){
	std::deque<int> x1, x2;
	int x;
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	std::cin>>x;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for(int i=0; i<x; i++){
		bool Prolaz(true);
		int y;
		std::cin>>y;
		for(int j=0; j<i; j++)
			if(x1[j]==y)
			{
				i--;
				Prolaz=false;
				break;
			}
		if(Prolaz)	x1.push_back(y);
	}
	
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	std::cin>>x;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0; i<x; i++){
		bool Prolaz(true);
		int y;
		std::cin>>y;
		for(int j=0; j<i; j++)
			if(x2[j]==y)
			{
				i--;
				Prolaz=false;
				break;
			}
		if(Prolaz)	x2.push_back(y);
	}
	std::vector<std::vector<int>> matrica;
	matrica=UvrnutiPresjek(x1.begin(),x1.end(), x2.begin(),x2.end(),SumaCifri);
	std::vector<std::vector<int>> matrica1;
	matrica1=UvrnutaRazlika(x1.begin(),x1.end(), x2.begin(),x2.end(),BrojProstihFaktora);
	std::cout << "Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<matrica.size(); i++){
		for(int j=0; j<matrica[i].size(); j++){
			std::cout<<std::setw(6)<< matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
		for(int i=0; i<matrica1.size(); i++){
		for(int j=0; j<matrica1[i].size(); j++){
			std::cout<<std::setw(6)<< matrica1[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Dovidjenja!";
	return 0;
}