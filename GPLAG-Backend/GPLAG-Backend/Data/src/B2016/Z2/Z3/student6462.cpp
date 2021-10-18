/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

bool Savrsen(long long int broj){
	int suma(0);
	long long int kopija(broj);
	while(kopija!=0){
		suma+=kopija%10;
		kopija/=10;
	}
	if(broj==suma) return true;
	return false;
}

int SumaDjelilaca(long long int broj){
	int suma(0);
	for(int i=1; i<broj; i++){
		if(broj%i==0) suma+=i;
	}
	if(broj>1) return suma;
	return 1;
}

int BrojProstihFaktora(long long int broj){
	int brojac(0);
	for(int i=1; i<broj; i++){
		if(broj%i==0) brojac++;
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int broj){
	int brojac(0);
	for(int i=1; i<broj; i++){
		if(broj%i==0){
			if(Savrsen(i)==true) brojac++;
		}
	}
	return brojac;
}

int SumaCifara(long long int broj){
	long long int kopija=broj;
	int suma(0);
	while(kopija!=0){
		suma+=kopija%10;
		kopija/=10;
	}
	return suma;
}

template <typename IterTip1, typename IterTip2, typename NekiTip1, typename NekiTip2>
auto UvrnutiPresjek (IterTip1 poc1, IterTip1 kraj1, IterTip2 poc2, IterTip2 kraj2, NekiTip1 fun(NekiTip2 broj)) 
-> std::vector<std::vector<NekiTip1>> {
	std::vector<std::vector<NekiTip1>> mat;
	int br(0);
	while(poc1!=kraj1){
		IterTip2 kopija=poc2;
		while(kopija!=kraj2){
			if(fun(*poc1)==fun(*kopija)){
			mat.resize(br+1);
			mat[br].resize(3);
			mat[br][0]=*poc1;
			mat[br][1]=*kopija;
			mat[br][2]=fun(*poc1);
			br++;
		   }
		kopija++;
		}
		
		poc1++;
	}
	std::sort(mat.begin(), mat.end(), [] (std::vector<NekiTip1> x, std::vector<NekiTip1> y){
		 if(x[2]<y[2]) return true;
		 if(x[2]>y[2]) return false;
		 if(x[2]==y[2]){
		 	if(x[1]<y[1]) return true;
		 	if(x[1>y[1]]) return false;
		 	if(x[1]==y[1]){
		 		if(x[0]<y[0]) return true;
		 		if(x[0]>y[0]) return false;
		 		
		 	}
		 }
		 return false;
		});
	return mat;
}

int main ()
{
	std::deque<int> d1, d2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int broj, n;
	int niz[20]{-1};
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n; i++){
		std::cin>>broj;
		d1.push_back(broj);
	
	}

	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
//	std::cin.ignore(10000, '\n');
	int n1;
	std::cin>>n1;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n1; i++){
		std::cin>>broj;
		d2.push_back(broj);
	}
//	std::cin.ignore(10000, '\n');
	std::vector<std::vector<int>> mat=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<3; j++){
			std::cout<<mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Doviđenja!"<<std::endl;
	return 0;
}






