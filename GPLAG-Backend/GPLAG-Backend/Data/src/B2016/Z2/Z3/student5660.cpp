
#include <vector>
#include <type_traits>
#include <deque>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
int SumaDjelilaca(long long int br){
	int sumadjel(0);
	if(br>0)
		for(long long int i=1; i<=br;i++){
			if(br%i==0)sumadjel+=i;
			if(i==br)break;
		}
	else
		for(long long int i=-1; i>=br;i--){
			if(br%i==0)sumadjel+=abs(i);
			if(i==br)break;
		}
	return sumadjel;
}
bool prost(long long int br){
	bool pr{true};
	if(br>1){
		for(long long int i=2;i<=std::sqrt(br);i++){
			if(br%i==0){pr=false; break;}
			if(std::fabs(i-std::sqrt(br))<0.000001)break;
		}
		return pr;
	}else 
		return false;
}
bool jelisavrsen(long long int br){
	long long int sumadj(0);
	for(long long int i=1; i<br;i++){
		if(br%i==0)sumadj+=i;
	}
	return sumadj==br;
}
long long int prostdjel(long long int br){
	for(long long int i=1; i<=br;i++)
		if(br%i==0 && prost(i))return i;
	return 0;
}
int BrojProstihFaktora(long long int br){
	int brprost(0);
	while(br!=1){
		long long int djel=prostdjel(br);
	//	std::cout<<djel<<" ";
		if(djel==0)return 0;
		br=br/djel;
		brprost++;
	}
	return brprost;
}
int BrojSavrsenihDjelilaca(long long int br){
	int brdj(0);
	if(br>=0)
		for(long long int i=1; i<=br; i++){
			if(br%i==0 && jelisavrsen(i))brdj++;
			if(i==br)break;
		}
	else
		for(long long int i=-1; i>=br; i--){
			if(br%i==0 && jelisavrsen(abs(i)))brdj++;
			if(i==br)break;
		}
	return brdj;
}
template <typename tip>
	auto FA(tip c)->decltype(c+c){
		return c;
	}
template<typename tip1,typename tip2,typename FunkcTip>
	auto UvrnutiPresjek(tip1 pok1, tip1 pok2, tip2 pok3, tip2 pok4,FunkcTip F)->std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type >>{
	std::vector<typename std::remove_reference<decltype(*pok1)>::type> red(3);
	std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type > > matrica(0,red);
	tip2 pok3b(pok3);
	while(pok1!=pok2){
		pok3=pok3b;
		while(pok3!=pok4){
			if(F(*pok1)==F(*pok3)){
				red[0]=*pok1;
				red[1]=*pok3;
				red[2]=F(*pok1);
				matrica.push_back(red);
			}
			pok3++;
		}
		pok1++;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*pok1)>::type> red1,std::vector<typename std::remove_reference<decltype(*pok1)>::type> red2){
		if(red1[2]==red2[2]){
			if(red1[0]==red2[0]){
				return red1[1]<red2[1];
			}
			return red1[0]<red2[0];
		}
		return red1[2]<red2[2];
	});
	return matrica;
}
template<typename tip1,typename tip2>
	auto UvrnutiPresjek(tip1 pok1, tip1 pok2, tip2 pok3, tip2 pok4)->std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type >>{
		std::vector<typename std::remove_reference<decltype(*pok1)>::type> red(3);
		std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type > > matrica(0,red);
		tip2 pok3b(pok3);
		while(pok1!=pok2){
			pok3=pok3b;
			while(pok3!=pok4){
				if(FA(*pok1)==FA(*pok3)){
					red[0]=*pok1;
					red[1]=0;
					red[2]=0;
					matrica.push_back(red);
				}
				pok3++;
			}
			pok1++;
		}
		std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*pok1)>::type> red1,std::vector<typename std::remove_reference<decltype(*pok1)>::type> red2){
			if(red1[2]==red2[2]){
				if(red1[0]==red2[0]){
					return red1[1]<red2[1];
				}
				return red1[0]<red2[0];
			}
			return red1[2]<red2[2];
		});
		return matrica;
	}
template<typename tip1,typename tip2>
	auto UvrnutaRazlika(tip1 pok1, tip1 pok2, tip2 pok3, tip2 pok4)->std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type > >{
	std::vector<typename std::remove_reference<decltype(*pok1)>::type> red(2);
	std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type > > matrica(0,red);
	tip2 pok3b(pok3);
	tip1 pok1b(pok1);
	while(pok1!=pok2){
		pok3=pok3b;
		bool ima(false);
		while(pok3!=pok4){
			if(FA(*pok1)==FA(*pok3))ima=true;
			pok3++;
		}
		if(!ima){
			red[0]=*pok1;
			red[1]=0;
			matrica.push_back(red);
		}
		
		pok1++;
	}
	pok3=pok3b;
	pok1=pok1b;
	while(pok3!=pok4){
		pok1=pok1b;
		bool ima(false);
		while(pok1!=pok2){
			if(FA(*pok3)==FA(*pok1))ima=true;
			pok1++;
		}
		if(!ima){
			red[0]=*pok3;
			red[1]=0;
			matrica.push_back(red);
		}
		pok3++;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*pok1)>::type> red1,std::vector<typename std::remove_reference<decltype(*pok1)>::type> red2){
		if(red1[0]==red2[0]){
			return red1[1]>red2[1];
		}
		return red1[0]>red2[0];
	});
	return matrica;
}
template<typename tip1,typename tip2,typename FunkcTip>
	auto UvrnutaRazlika(tip1 pok1, tip1 pok2, tip2 pok3, tip2 pok4,FunkcTip F)->std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type > >{
	std::vector<typename std::remove_reference<decltype(*pok1)>::type> red(2);
	std::vector<std::vector<typename std::remove_reference<decltype(*pok1)>::type > > matrica(0,red);
	tip2 pok3b(pok3);
	tip1 pok1b(pok1);
	while(pok1!=pok2){
		pok3=pok3b;
		bool ima(false);
		while(pok3!=pok4){
			if(F(*pok1)==F(*pok3))ima=true;
			pok3++;
		}
		if(!ima){
			red[0]=*pok1;
			red[1]=F(*pok1);
			matrica.push_back(red);
		}
		
		pok1++;
	}
	pok3=pok3b;
	pok1=pok1b;
	while(pok3!=pok4){
		pok1=pok1b;
		bool ima(false);
		while(pok1!=pok2){
			if(F(*pok3)==F(*pok1))ima=true;
			pok1++;
		}
		if(!ima){
			red[0]=*pok3;
			red[1]=F(*pok3);
			matrica.push_back(red);
		}
		pok3++;
	}
	std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*pok1)>::type> red1,std::vector<typename std::remove_reference<decltype(*pok1)>::type> red2){
		if(red1[0]==red2[0]){
			return red1[1]>red2[1];
		}
		return red1[0]>red2[0];
	});
	return matrica;
}
int main (){
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int brelprvog(0);
	std::cin>>brelprvog;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> prvi(0);
	int unos;
	int uneseno(0);
	while(uneseno<brelprvog){
		std::cin>>unos;
		bool nema(true);
		for(int i=0; i<prvi.size();i++)
			if(prvi[i]==unos)nema=false;
		if(nema){prvi.push_back(unos); uneseno++;}
	}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int breldrugog(0);
	std::cin>>breldrugog;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> drugi(0);
	uneseno=0;
	while(uneseno<breldrugog){
		std::cin>>unos;
		bool nema(true);
		for(int i=0; i<drugi.size();i++)
			if(drugi[i]==unos)nema=false;
		if(nema){drugi.push_back(unos); uneseno++;}
	}
	
	for(int i=0; i<breldrugog; i++)
		std::cin>>drugi[i];

	{
		std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
		auto pres=UvrnutiPresjek(prvi.begin(),prvi.end(),drugi.begin(),drugi.end(),[](int br){
			int a(0);
			while(br!=0){
				a+=abs(br%10);
				br/=10;
			}
			return a;
		});
		for(auto &x:pres){
			for(int &y:x)
				std::cout<<std::setw(6)<<y<<" ";
			std::cout<<std::endl;
		}
		
	}
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	auto pres=UvrnutaRazlika(prvi.begin(),prvi.end(),drugi.begin(),drugi.end(),BrojProstihFaktora);
	for(auto &x:pres){
		for(int &y:x)
			std::cout<<std::setw(6)<<y<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}