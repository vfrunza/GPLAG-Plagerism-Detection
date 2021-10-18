/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

	int stepenuj (int baza, int exp){
		if(exp == 0) return 1;
		int rez=1;
		for(int i=0;i<exp;i++){
			rez*=baza;
		}
		return rez;
	}
	std::vector<int> DajTercarni(int broj){
		broj=fabs(broj);
		std::vector<int>v;
		for(; ;){
			if(broj<=0)break;
			v.push_back(broj%3);
			broj/=3;
		}
		return v;
		
	}
	//parno ponavljanje
	bool Opak(int broj){
		auto v = DajTercarni(broj);

	int br0=0,br1=0,br2=0;
	for(auto br : v){
		if(br==0)br0++;
		else if(br==1)br1++;
		else if(br==2)br2++;
	}
	if(br0%2==0 && br1%2==0 && br2%2==0) return true;
	else return false;
	}
	//neparno ponavljanje
	bool Odvratan (int broj){
		auto v = DajTercarni(broj);
	int br0=0,br1=0,br2=0;
	for(auto br : v){
		if(br==0)br0++;
		else if (br==1)br1++;
		else if(br==2)br2++;
	}
	if((br0%2==1 || br0==0) && (br1%2==1 || br1==0) && (br2%2==1 || br2==0)) return true;
	else return false;
	}
	std::vector<int> BezDuplikata(std::vector<int> v){
		for(int i=0;i<v.size()-1;i++){
			for(int j=i+1;j<v.size();j++){
				if(v[i]==v[j]){
					for(int k=j;k<v.size()-1;k++) v[k]=v[k+1];
					v.resize(v.size()-1);
				}
			} 
		} 
		return v;
	}
	std::vector<int> IzdvojiGadne(std::vector<int> v, bool temp){
		std::vector<int> rez;
		if(v.size()==0)return v;     
		// Opaki     
		if(temp){
			for(auto x : v){
				if(Opak(x)) rez.push_back(x);
			}
		}
		else{
			for(auto x : v){
				if(Odvratan(x))rez.push_back(x);
			}
		}
		v=BezDuplikata(rez);
		v=BezDuplikata(v);
		return v;
	}
	
int main()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>v;
	int temp;
	for(; ;){
		std::cin>>temp;
		if(temp==0)break;
		v.push_back(temp);
	}
	std::vector<int> rez;
	rez=IzdvojiGadne(v,1);
	std::cout<<"Opaki: ";
	for(auto x: rez)std::cout<<x<<" ";
	rez=IzdvojiGadne(v,0);
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(auto x: rez) std::cout<<x<<" ";
	return 0;
}

