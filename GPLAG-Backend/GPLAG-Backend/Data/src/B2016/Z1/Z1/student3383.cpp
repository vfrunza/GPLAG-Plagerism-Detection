/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> brojevi, bool x){
	std::vector<int> vrati;
	std::vector<int> proberi;
	int broj;
	for(int i:brojevi){
		if(i<0) broj=i*(-1);
		else broj=i;
		std::vector<int> ternar;
		while(broj != 0){
			ternar.push_back(broj%3);
			broj=broj/3;
		}
		std::vector<int> cifre(3, 0);
	    for(int j(ternar.size()-1); j>=0; j--) cifre.at(ternar.at(j))++;
	    
	    if(x && cifre[0]%2==0 && cifre[1]%2==0 && cifre[2]%2==0) proberi.push_back(i);
	    else if(!x && (cifre[0]==0 || cifre[0]%2!=0) && (cifre[1]==0 ||cifre[1]%2!=0) && (cifre[2]==0 || cifre[2]%2!=0)) proberi.push_back(i);
	}
	for(int i{0}; i<proberi.size(); i++){
		if(i==0) vrati.push_back(proberi.at(i));
		else{
			bool dupli{false};
			for(int j{0}; j<vrati.size(); j++){
				if(proberi.at(i)==vrati.at(j)){
					dupli=true;
					break;
				}
			}
			if(!dupli) vrati.push_back(proberi.at(i));
		}
	}
	return vrati;
}

int main ()
{
	std::vector<int> Brojevi;
	int x;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin >> x;
		if(x!=0) Brojevi.push_back(x);
	}while(x!=0);
	
	std::vector<int> opaki(IzdvojiGadne(Brojevi,true));
	std::cout << "Opaki:";
	for(int i:opaki)std::cout << " " << i;
	
	std::vector<int> odvratni(IzdvojiGadne(Brojevi,false));
	std::cout << std::endl << "Odvratni:";
	for(int i:odvratni)std::cout << " " << i;
	return 0;
}