/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
bool isti(std::deque<int> vektor, int broj){
	for(int i=0;i<vektor.size();i++){
		if(broj==vektor[i])return false;
	}
	return true;
}
/*int brojdjelilaca(long long int broj){
	int suma(0);
	for(int i=1;i<broj;i++){
		if(broj%i==0){
			suma+=i;
		}
	}
	return suma;
}*/
int brojdjelilaca(long long int broj){
	int s(0);
	for(long long int i=1;i<=broj-1;i++)  {    
        if(broj%i==0)s+=i;
	}
    if(s!=broj)return -1;
    return s;
   }
int SumaDjelilaca(long long int broj){
	int suma(0);
	if(broj==0)return 0;
	for(int i=1;i<=std::abs(broj);i++){
		if(std::abs(broj)%i==0)suma+=i;;
	}
	return suma;
}
bool savrsen(long long int broj){
	long long int suma(0);
	if(broj==0)return 0;
	for(int i=1;i<std::abs(broj);i++){
		if(std::abs(broj)%i==0)suma+=i;;
	}
	
	if(suma==broj)return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int broj){
	int suma(0);
	if(broj%2!=0)return 0; //nema neparnih savrsenih brojeva
	for(long long int i=1;i<=broj;i++){
		if(broj%i==0 && savrsen(i)==true){
			suma++;
			}
	}
	return suma;
}
int BrojDjelilaca(long long int broj){
	int suma(0);
	while(broj!=0){
	suma+=broj%10;
	broj/=10;
	
	}
	return suma;
}

bool DaLiJeProst(long long int broj){
	if(broj<2)return false;
	if(broj==2)return true;
	for(int i=2;i*i<=broj;i++){
		if(broj%i==0)return false;
	}
	return true;
}
int BrojProstihFaktora(long long int broj){
	int suma(0);
	if(broj<0)return 0;
	if(broj==2)return 1;
	for(int i=2;i*i<=broj;i++){
			if(DaLiJeProst((i))==true){
				if(broj%i==0){
				suma++;
				broj/=i;
				i=0;}
				
			}
		}
	return suma+1;
}
template<typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)-> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> Vektor;
	Matrica nova;
	for(auto it1=p1;it1!=p2;it1++){
		for(auto it2=p3;it2!=p4;it2++){
			if(*it1==*it2){
				Vektor neki(3);
				neki.at(0)=*it1;
				neki.at(1)=0;
				neki.at(2)=0;
			    nova.push_back(neki);
			}
		}
	}
	std::sort(nova.begin(),nova.end(), [](Vektor p1, Vektor p2){
		if(p1[2]==p2[2]){
			if(p1[0]<p2[0])return p1[0]<p2[0];
			if(p1[0]==p2[0])return p1[1]<p2[1];
			if(p1[1]>p2[1])return p1[1]>p2[1];
		}
		if(p1[2]<p2[2])return p1[2]<p2[2];
		return p1[2]<p2[2];
	});
	return nova;
}
template <typename Tip1, typename Tip2, typename TipF>
auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4,TipF f) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	typedef  std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	typedef  std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor;
	Matrica nova;
	for(auto it1=p1;it1!=p2;it1++){
		for(auto it2=p3;it2!=p4;it2++){
			if(f(*it1)==f(*it2)){
				vektor neki(3);
				neki.at(0)=*it1;
				neki.at(1)=*it2;
				neki.at(2)=f(*it1);
			    nova.push_back(neki);
			}
		}
	}
	std::sort(nova.begin(), nova.end(), [](vektor p1, vektor p2){
		if(p1[2]==p2[2]){
			if(p1[0]==p2[0])return p1[1]<p2[1];
			if(p1[0]<p2[0])return p1[0]<p2[0];
		//	if(p1[0]==p2[0])return p1[1]<p2[1];
			if(p1[1]>p2[1])return p1[1]<p2[1];
		}
	//	if(p1[2]>p2[2])return p1[0]<p2[0];
		if(p1[2]<p2[2])return p1[2]<p2[2];
		return p2[2]>p1[2];
	});
	return nova;
}
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> Vektor;
	Matrica uvrnuta;
	for(auto it1=p1;it1!=p2;it1++){
		bool isti(false);
		for(auto it2=p3;it2!=p4;it2++){
			if(*it1==*it2){
				isti=true;
				break;
			}
		}
		if(isti==false){
			Vektor v(2);
		    v.at(0)=*it1;
			v.at(1)=0;
			uvrnuta.push_back(v);
		}
	}
	for(auto it2=p3;it2!=p4;it2++){
	 	bool isti(false);
		for(auto it1=p1;it1!=p2;it1++){
			if(*it1==*it2){isti=true;break;}
		}
		if(isti==false){
			Vektor v(2);
			v.at(0)=*it2;
			v.at(1)=0;
			uvrnuta.push_back(v);
		}
	}
	std::sort(uvrnuta.begin(),uvrnuta.end(), [](Vektor p1,Vektor p2){
		if(p1[1]==p2[1]){
			if(p1[0]>p2[0])return p1[0]>p2[0];
			if(p1[0]==p2[0])return p1[1]>p2[1];
			//if(p1[1]>p2[1])return p1[1]>p2[1];
		}
		if(p1[1]>p2[1])return p1[1]>p2[1];
		return p2[1]>p1[1];
	});
	
/*	std::sort(uvrnuta.begin(), uvrnuta.end(), [](Vektor p1, Vektor p2){
		if(p1[1]==p2[1]){
			if(p1[0]>p2[0])return p1[0]>p2[0];
			if(p1[0]==p2[0])return p1[1]>p2[1];
		}
		if(p1[1]>p2[1])return p1[1]>p2[1];
	});*/
return uvrnuta;
}
template <typename Tip, typename Tipp, typename Tiip>
auto UvrnutaRazlika(Tip p1, Tip p2, Tipp p3, Tipp p4,Tiip g) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	typedef std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> Matrica;
	typedef std::vector<typename std::remove_reference<decltype(*p1)>::type> Vektor;
	Matrica uvrnuta;
	for(auto it1=p1;it1!=p2;it1++){
		bool isti(false);
		for(auto it2=p3;it2!=p4;it2++){
			if(g(*it1)==g(*it2)){
				isti=true;
				break;
			}
		}
		if(isti==false){
			Vektor v(2);
		    v.at(0)=*it1;
			v.at(1)=g(*it1);
			uvrnuta.push_back(v);
		}
	}
	for(auto it2=p3;it2!=p4;it2++){
	 	bool isti(false);
		for(auto it1=p1;it1!=p2;it1++){
			if(g(*it1)==g(*it2)){isti=true;break;}
		}
		if(isti==false){
			Vektor v(2);
			v.at(0)=*it2;
			v.at(1)=(g(*it2));
			uvrnuta.push_back(v);
		}
	}
	std::sort(uvrnuta.begin(),uvrnuta.end(), [](Vektor p1,Vektor p2){
		if(p1[1]==p2[1]){
			if(p1[0]>p2[0])return p1[0]>p2[0];
			if(p1[0]==p2[0])return p1[1]<p2[1];
			;
		}
		if(p1[0]<p2[0])return p1[0]<p1[0];
		if(p1[1]<p2[1])return p1[0]>p2[0];
		return p2[1]<p1[1];
	});
	/*	std::sort(uvrnuta.begin(), uvrnuta.end(), [](Vektor p1, Vektor p2){
		if(p1[1]==p2[1]){
			if(p1[0]<p2[0])return p1[0]<p2[0];
			if(p1[0]==p2[0])return p1[1]<p2[1];
			if(p1[1]>p2[1])return p1[1]>p2[1];
		}
		if(p1[1]<p2[1])return p1[1]<p2[1];
		return p2[1]>p1[1];
	});*/
	return uvrnuta;
}
int main ()
{
	//AT7 - test funkcija sa 4 parametra čiji su elementi tipa int
//Funkcija UvrnutaRazlika sa 4 parametra radi analogno kao i funkcija 
//UvrnutiPresjek sa 4 parametra, dakle običnu razliku skupova

/*	std::deque<int> d1{1, 2, 3}, d2{2, 4, 3, 5};
    std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end())};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end())};
	for (std::vector<int>& red : v1)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<int>& red : v2)
	{
		for (int& broj : red)
			std::cout << broj << " ";
		std::cout << std::endl;
	}*/
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int broj1;
	std::cin>>broj1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> v1;
	for(int i=0;i<broj1;i++){
		int novi;
		std::cin>>novi;
		if(isti(v1,novi)==true)v1.push_back(novi);
		else i--;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int broj2;
	std::cin>>broj2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> v2;
/*	std::deque<int> d1{6, 168, 28, 12}, d2{1, 28, 51, 6};
    std::vector<std::vector<int>> a{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojSavrsenihDjelilaca)};
	std::vector<std::vector<int>> b{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojSavrsenihDjelilaca)};
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			std::cout<<a[i][j]<<" ";
		}
		std::cout<<std::endl;
	}*/
	for(int i=0;i<broj2;i++){
		int novi;
		std::cin>>novi;
		if(isti(v2,novi)==true)v2.push_back(novi);
		else i--;
	}
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	auto mat(UvrnutiPresjek(v1.begin(), v1.end(), v2.begin(), v2.end(), BrojDjelilaca));
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			std::cout<<std::setw(6)<<mat.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	auto mat1(UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora));
	for(int i=0;i<mat1.size();i++){
		for(int j=0;j<mat1[i].size();j++){
			std::cout<<std::setw(6)<<mat1.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
/*	std::cout<<BrojSavrsenihDjelilaca(168);
	std::cout << BrojSavrsenihDjelilaca(123456) << " " << BrojSavrsenihDjelilaca(56789) << " " << BrojSavrsenihDjelilaca(12121281) << " ";
std::cout << BrojSavrsenihDjelilaca(83328) << " " << BrojSavrsenihDjelilaca(1176) << " " << BrojSavrsenihDjelilaca(181287) << " ";
std::cout << BrojSavrsenihDjelilaca(45698) << " " << BrojSavrsenihDjelilaca(2048) << " " << BrojSavrsenihDjelilaca(8128);
std::cout << BrojProstihFaktora(123456) << " " << BrojProstihFaktora(56789) << " " << BrojProstihFaktora(12121281) << " ";
std::cout << BrojProstihFaktora(4512698) << " " << BrojProstihFaktora(202248) << " " << BrojProstihFaktora(181287) << " ";
std::cout << BrojProstihFaktora(45698) << " " << BrojProstihFaktora(2048) << " " << BrojProstihFaktora(8128);	*/
return 0;
}