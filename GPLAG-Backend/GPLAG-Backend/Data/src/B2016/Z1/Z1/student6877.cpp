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

typedef std::vector<int> Vector;

Vector IzdvojiGadne(Vector a, bool stanje){
	Vector b,c;
	
	int pomocni;
	for(int i=0;i<a.size();i++){
		bool stanje=false;
		if(i>=1){
		for(int j=0;j<i;j++){
			if(a[i]==a[j]) stanje=true;
		}
		}
		if(stanje) continue;
		else{
		pomocni=abs(a[i]);
		Vector pom(0);
		while(pomocni!=0){
			int g=pomocni%3;
			pom.push_back(g);
			pomocni/=3;
		}
		int brn(0);
		int brj(0);
		int brd(0);
		for(int i=0;i<pom.size();i++){
			if(pom[i]==0) brn++;
			else if(pom[i]==1) brj++;
			else brd++;
		}
		if(brn%2==0 && brj%2==0 && brd%2==0) b.push_back(a[i]);
		if(brn==0) brn=1;
		if(brj==0) brj=1;
		if(brd==0) brd=1;
		if(brn%2==1 && brj%2==1 && brd%2==1) c.push_back(a[i]);
		}
		
		
	}	
		
	if(stanje) return b;
	else return c;
}

int main ()
{
	Vector a;
	int unos;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    while(std::cin >> unos, unos!=0){

    if (unos!=0) a.push_back(unos);
    }
    Vector b = IzdvojiGadne(a,true);
    Vector c = IzdvojiGadne(a,false);
    std::cout<<"Opaki: ";
    for(int i=0;i<b.size();i++) std::cout <<b[i]<<" ";
    std::cout <<""<<std::endl;
    std::cout<<"Odvratni: ";
    for(int i=0;i<c.size();i++) std::cout <<c[i]<<" ";
    
	return 0;
}