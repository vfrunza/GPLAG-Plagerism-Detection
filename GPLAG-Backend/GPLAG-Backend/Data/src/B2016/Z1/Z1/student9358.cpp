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
#include <limits>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool x){
    std::vector<int> gadni;
	for(int i=0;i<v.size();i++){
		bool postoji=false;
		int br0(0),br1(0),br2(0),cifra(0);
		int a=v[i];
		if(v[i]==0) br0++;                                
		while(v[i]!=0){                              //racunanje cifara u ternarnom zapisu i dodavanje odgovarajucem brojacu//
			cifra=std::abs(v[i]%3);                  //apsolutna vrijednost cifre, jer bi negativan broj%3 dao negativan ostatak//
			v[i]=v[i]/3;
			if(cifra==0) br0++;
			else if(cifra==1) br1++;
			else if(cifra==2) br2++;
		}
	    for(int k: gadni){                                    //provjeravanje da li se broj vec pojavio, da se ne bi ponavljao u novom vektoru//
	    	if(k==a) {
	    		postoji=true;
	    	    break;
	    	}
	    }
		if(br0%2==0 && br1%2==0 && br2%2==0 && x==true && postoji==false) gadni.push_back(a);
	    else if((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0) && x==false && postoji==false) gadni.push_back(a);
	}
	return gadni;
}

int main ()
{   int a=1;
    std::vector<int>v;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	while(a!=0){
		std::cin>>a;
		if(a==0) break;
		v.push_back(a);
	}
	std::vector<int>opaki=IzdvojiGadne(v,true);
	std::vector<int>odvratni=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	for(int i: opaki){
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i: odvratni){
		std::cout<<i<<" ";
	}
	return 0;
}