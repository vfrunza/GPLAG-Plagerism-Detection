/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<deque>
std::vector<int> IzdvojiGadne(std::vector<int> vekt,bool vrijed) {
	std::vector<int> gadost;
	for(int i=0;i<vekt.size();i++) {
		if(i==vekt.size()) break;
		int pom(vekt.at(i));
		std::deque<int> ostatak;
		while(pom!=0) {
			ostatak.push_front((pom%3));
			pom/=3;
		}
		int br0(0),br1(0),br2(0);
		for(int j=0;j<ostatak.size();j++) {
			if(j==ostatak.size()) break;
			if(ostatak.at(j)==0) br0++;
			if(ostatak.at(j)==1 || ostatak.at(j)==-1) br1++;
			if(ostatak.at(j)==2 || ostatak.at(j)==-2) br2++;
		}
		if(((br0%2==0 || br0==0) && (br1%2==0 || br1==0) && (br2%2==0 || br2==0) && vrijed && !(br0==0 && br1==0 && br2==0)) 
		|| ((br0%2!=0 || br0==0) && (br1%2!=0 || br1==0) && (br2%2!=0 || br2==0) && !(vrijed))) gadost.push_back(vekt.at(i));
	}
	for(int i=0;i<gadost.size();i++) {
        for(int j=i+1;j<gadost.size();j++) {
        	if(j==gadost.size()) break;
            if(gadost.at(i)==gadost.at(j)) {
            	gadost.erase(gadost.begin()+j);
            	j--;
            }
            if(i==gadost.size()) break;
    	}
	}
	return gadost;
}
int main ()
{	std::vector<int> a;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    int broj;
    do {
        std::cin>>broj;
        if(broj!=0) a.push_back(broj);
    } while(broj!=0);
	bool vrijednost(true);
	std::vector<int> rezultat{IzdvojiGadne(a,vrijednost)};
	std::cout<<"Opaki: ";
	for(int i: rezultat) std::cout<<i<<" ";
	vrijednost=false;
	rezultat=IzdvojiGadne(a,vrijednost);
	std::cout<<std::endl<<"Odvratni: ";
	for(int i: rezultat) std::cout<<i<<" ";
	return 0;
}
