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
std::vector<int> IzdvojiGadne(std::vector<int > v, bool istina){
	int a=5,b=5,br=0,u;
	std::vector<int> opaki;
	std::vector<int> odvratni;
	std::vector<int> pomocni;
	for(int d: v){
		u=d;
		d=abs(d);
		    while(d>0){
	        pomocni.push_back(d%3);
	        d/=3;
	    }
	    for(int e: pomocni){
	    	for(int f: pomocni){
	    		if(f==e) br++;
	    	}
	    	if(br%2==0) a=1;
	    	else b=2;
	    	br=0;
	    }
	     if(a==1 && b==5){
	   	for(int m: opaki){
	   		if(u==m) goto L1;
	   	}
	   	opaki.push_back(u);
	   }
	   if(a==5 && b==2){
	   	for(int q: odvratni){
	   		if(u==q) goto L1;
	   	}
	   	odvratni.push_back(u);
	   }
	   L1:
	   a=5; b=5;
	   pomocni.resize(0);
	}
	if(istina) return opaki;
	else return odvratni;
}

int main ()
{
	int z;
    std::vector<int> v;
    std::vector<int> v1;
    std::vector<int> v2;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    std::cin>>z;
    v.push_back(z);
    z=69;
    while(z!=0){
    	std::cin>>z;
    	if(z==0) break;
    	v.push_back(z);
    }
    bool a=true;
    v1=IzdvojiGadne(v,a);
    std::cout<<"Opaki: ";
    for(int m: v1) std::cout<<m<<" ";
    a=false;
    v2=IzdvojiGadne(v,a);
    std::cout<<std::endl<<"Odvratni: ";
    for(int n: v2) std::cout<<n<<" ";
	return 0;
}