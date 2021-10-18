#include <iostream>
#include <deque>
#include <vector>
#include <limits>
#include <cmath>

bool jeliOpak(int x){
	
	bool opak(true);
	std::deque<int>v;
	//da ne bi bilo hardkodiranje ovo cemo tretirati u pretvaranju u ternanri broj
	//if(x==0)return false;
	int broj;
	//ovdje zbog min inta ovo nije dozvoljeno raditi !!
    //if(x<0)x=-x;
	while(x != 0){
		broj = x%3;
		v.push_front((fabs)(broj));
		x/=3;
	}
	if(v.empty())return false;

	int brojaci[3]{0};
	//for(int y: v)brojaci[y]++;
	for(int i=0;i<v.size();i++){
		brojaci[v[i]]++;
	}
	
	for(int i=0;i<3;i++){
		if(brojaci[i]!=0 && brojaci[i]%2!=0)opak = false;
	}
	
		//ako je true -->OPAK
		return opak;
}

bool jeliOdvratan(int x){
	
	bool odvratan(true);
	std::deque<int>v;
	
	int broj;
	//funckija jeliOdvratan po defaultu vracan da je 0 odvratan broj!
//	if(x==0)return true;
	while(x != 0){
		broj = x%3;
		v.push_front(fabs(broj));
		x/=3;
	}
	
	
	
	int brojaci[3]{0};
	for(int y: v)brojaci[y]++;
	
	for(int i=0;i<3;i++){
		if(brojaci[i]!=0 && brojaci[i]%2==0)odvratan = false;
	}
	
		//ako je true -->odvratan
		return odvratan;
}

std::vector<int>IzdvojiGadne(std::vector<int>v,bool t){
	
	std::vector<int> v1; //opaki
	std::vector<int> v2;//odvratni
	
	for(int x: v){
		if(jeliOpak(x)){
			v1.push_back(x);
			
		}else if(jeliOdvratan(x))v2.push_back(x);
	}
	
	//sada iz ovih dekova izbacujemo elemente koji se ponavljaju
	
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<i;j++){
			if(v1[j]==v1[i]){
				v1.erase(v1.begin()+i);
				i--;
			}
		}
	}
	
	//sada iz drugog deka izbacujemo el koji se pon
	
	for(int i=0;i<v2.size();i++){
		for(int j=0;j<i;j++){
			if(v2[j]==v2[i]){
				v2.erase(v2.begin()+i);
				i--;
			}
		}
	}
	
	if(t){
		return v1;
	}else return v2;
}


int main ()
{
	
	
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	std::vector<int> v;
	int x;
	
	while(1){
		std::cin>>x;
		if(x==0 || !std::cin)break;
		else v.push_back(x);
	}
	
	
	

	std::vector<int> opaki(IzdvojiGadne(v,true));
	std::vector<int> odvratni(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(int x: opaki)std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int x: odvratni)std::cout<<x<<" ";
	std::cout<<std::endl;
	
	return 0;
}




/*
PROGRAM SA DEKOM URADJEN 
std::deque<int>IzdvojiGadne(std::deque<int>v,bool t){
	
	std::deque<int> v1; //opaki
	std::deque<int> v2;//odvratni
	
	for(int x: v){
		if(jeliOpak(x)){
			v1.push_back(x);
			
		}else if(jeliOdvratan(x))v2.push_back(x);
	}
	
	//sada iz ovih dekova izbacujemo elemnte koji se ponavljaju
	
	for(int i=0;i<v1.size();i++){
		for(int j=0;j<i;j++){
			if(v1[j]==v1[i]){
				v1.erase(v1.begin()+i);
				i--;
			}
		}
	}
	
	//sada iz drugog deka izbacujemo el koji se pon
	
	for(int i=0;i<v2.size();i++){
		for(int j=0;j<i;j++){
			if(v2[j]==v2[i]){
				v2.erase(v2.begin()+i);
				i--;
			}
		}
	}
	
	if(t){
		return v1;
	}else return v2;
}


int main ()
{
	
	
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	std::deque<int> v;
	int x;
	while(1){
		std::cin>>x;
		if(x==0)break;
		else v.push_back(x);
	}
	
	std::deque<int> opaki(IzdvojiGadne(v,true));
	std::deque<int> odvratni(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(int x: opaki)std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int x: odvratni)std::cout<<x<<" ";
	std::cout<<std::endl;
	
	return 0;
}*/