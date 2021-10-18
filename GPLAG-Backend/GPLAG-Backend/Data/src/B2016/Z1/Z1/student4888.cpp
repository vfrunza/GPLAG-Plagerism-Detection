/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

bool nalazi_se(std::vector<int>b, int r){
	if(b.size() == 0) return true;
	
	for(int i(0);i<b.size();i++){
		if (r==b[i]) return false;
	}
	return true;
}

int ternarni(int x){
	int br0(0),br1(0),br2(0); 
	if (x==0) br0++;
	while (x!=0 ){
		if (x%3==0) br0++;
		else if (x%3==1 || x%3==-1) br1++;
		else if (x%3==2 || x%3==-2) br2++;
		x=x/3;
	}
	if ((br1%2==0 || br1==0) && (br2%2==0 || br2==0) && (br0%2==0 || br0==0)) return 1;
	else if ((br1%2==1 || br1==0) && (br2%2==1 || br2==0) && (br0%2==1 || br0==0)) return 0;
	else return 2;
}

std::vector<int> IzdvojiGadne(std::vector<int>v,bool p){
	
	std::vector<int>b;
	if(v.size() == 0) return b;
	
	for(int x:v){
		if (ternarni(x)==2) continue;
		if (p==ternarni(x) && nalazi_se(b,x))b.push_back(x);
	}
	return b;
}

int main ()
{
	int  broj;
	std::vector<int>a;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	while(std::cin>>broj && broj!=0){
		a.push_back(broj);
	}
	std::vector<int>v1(IzdvojiGadne(a, true));
	std::cout << "Opaki: ";
	for(int x:v1) std::cout << x << " ";
	std::cout<< std::endl;
	std::vector<int>v2(IzdvojiGadne(a, false));
	std::cout << "Odvratni: ";	
	for(int x:v2) std::cout << x << " ";
	return 0;
}