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
std::vector<int> IzdvojiGadne(std::vector<int>v,bool alfa){
	std::vector<int>noviopaki,noviodvratni;
		for(int i=0;i<v.size();i++){
			std::vector<int>v1(3,0);
			int pom(v.at(i));
			do{
				int cifra;
				cifra=std::fabs(pom%3);
				v1.at(cifra)++;
				pom=pom/3;
			}while(pom!=0);
			bool opaki(true);
			for(int j=0;j<v1.size();j++){
				if(v1.at(j)==0)continue;
				if(v1.at(j)%2==1){
					opaki=false;
					break;
				}
				if(j==v1.size()) break;
			}	
			if(opaki==true){
				bool isti(false);
				for(int j=0;j<noviopaki.size();j++){
					if(v.at(i)==noviopaki.at(j)){
						isti=true;
						break;
					}
					if(j==noviopaki.size())break;
			}
			if(isti==false){
				noviopaki.push_back(v[i]);
				continue;
			}
		}
		bool odvratni(true);
		for(int j=0;j<v1.size();j++){
			if(v1.at(j)==0)continue;
			if(v1.at(j)%2==0){
				odvratni=false;
				break;
			}
			if(j==v1.size()) break;
		}
		if(odvratni==true){
			bool isti1(false);
			for(int j=0;j<noviodvratni.size();j++){
				if(v.at(i)==noviodvratni.at(j)){
					isti1=true;
					break;
				}
				if(j==noviodvratni.size())break;
			}
			if(isti1==false || v[i]==0)noviodvratni.push_back(v.at(i));
		}
		if(i==v.size())break;
	}
	if(alfa)return noviopaki;
	return noviodvratni;
}
int main ()
{	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int>a;
	for(;;){
		int b;
		std::cin>>b;
		if(std::cin){
		if(b==0) break;
		a.push_back(b);
		}
	}
	std::vector<int>op,od;
	op=IzdvojiGadne(a,true);
	std::cout<<"Opaki: ";
	for(int i=0;i<op.size();i++){
		std::cout<<op.at(i)<<" ";
		if(i==op.size()) break;
	}
		std::cout<<std::endl<<"Odvratni: ";
	od=IzdvojiGadne(a,false);	
		for(int i=0;i<od.size(); i++){
			std::cout<<od.at(i)<<" ";
			if(i==od.size()) break;
		}
	return 0;
}