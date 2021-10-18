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

std::vector<int> IzdvojiGadne(std::vector<int> a, bool b){
	std::vector<int> c;
	for(int i=0;i<a.size();i++){
		int brojac0(0),brojac1(0),brojac2(0); 
		int pomoc(abs(a.at(i)));
		do{
			if(pomoc%3==0) brojac0++;
			else if(pomoc%3==1) brojac1++;
			else brojac2++;
			pomoc=pomoc/3;
		}
		while (pomoc!=0);
		if((brojac0%2==0 and brojac1%2==0 and brojac2%2==0 and b==1) or ((brojac0%2!=0 or brojac0==0) and (brojac1%2!=0 or brojac1==0) and (brojac2%2!=0 or brojac2==0) and b==0)){
			bool unesi(true);
			for(int k=0;k<c.size();k++){
				if(a.at(i)==c.at(k)) unesi=false;
			}
			if(unesi) c.push_back(a.at(i));
		}
	}
	return c;
}
int main ()
{	std::vector<int> glavni;
	int br;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>br;
	while (br!=0){
		glavni.push_back(br);
		std::cin>>br;
	}
	std::vector<int> opaki (IzdvojiGadne(glavni,1));
	std::vector<int> odvratni (IzdvojiGadne(glavni,0));
	std::cout<<"Opaki: ";
	for(const auto &x:opaki) 
		std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(const auto &x:odvratni)
		std::cout<<x<<" ";

	return 0;
	
}