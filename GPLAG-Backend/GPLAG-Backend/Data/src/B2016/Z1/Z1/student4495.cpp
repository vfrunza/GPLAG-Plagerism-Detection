#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> vektor, bool opaki){
	
	bool DaLiJeOpak(true),NiOpakNiGadan(false);
	std::vector<int> NoviVektor ;
	if( opaki==false && vektor.size()!=0 && vektor[0]==0)	{
		NoviVektor.push_back(vektor[0]);
		return NoviVektor;
	}
	
	for (int i=0; i<vektor.size(); i++){
		
		long long int tmp=vektor[i];
		if(tmp < 0) tmp=-tmp;
		int pretvoreni[30], indeks(0);
		//pretvaranje broja i smjestanje u niz
		while(tmp!=0){
			pretvoreni[indeks]=tmp%3;
			tmp/=3;
			indeks+=1;
		}
		//provjera da li je opak ili gadan
		DaLiJeOpak=true;
		NiOpakNiGadan=false;
		int nula(0),jedan(0),dva(0);
		for(int j=0; j<indeks; j++){
			if(pretvoreni[j]==0) nula+=1;
			else if(pretvoreni[j]==1) jedan+=1;
			else if(pretvoreni[j]==2) dva+=1;
		}
		
		if(nula != 0 && jedan != 0 && dva==0 && ((nula%2)!=(jedan%2))) NiOpakNiGadan=true;
		if(nula != 0 && dva != 0 && jedan==0 && ((nula%2)!=(dva%2))) NiOpakNiGadan=true;
		if(jedan != 0 && dva !=0 && nula==0 && ((dva%2)!=(jedan%2))) NiOpakNiGadan=true;
		if(nula!=0 && jedan !=0 && dva !=0 && (((nula%2)!=(jedan%2)) || ((dva%2) !=(jedan%2)))) NiOpakNiGadan=true;
		
		if((nula % 2) != 0 || (jedan % 2) != 0 || (dva% 2) != 0 ) DaLiJeOpak=false;
	//	std::cout<< DaLiJeOpak <<std::endl << nula <<jedan <<dva <<std::endl;
		//	std::cout << "BROJ: " << vektor[i] << " OPAK: " << DaLiJeOpak;
		//smjestanje broja u niz i provjera da li postoji isti u nizu 
		
		if(opaki && DaLiJeOpak && !(NiOpakNiGadan)){
			if(NoviVektor.size()==0)
				NoviVektor.push_back(vektor[i]);
			else {
				bool VecPostoji(false);
				for(int k=0;k<NoviVektor.size();k++){
					if(NoviVektor[k]==vektor[i]){
						VecPostoji=true;
						break;
					}
				}
				if(!(VecPostoji)) NoviVektor.push_back(vektor[i]);
			}
		}
		
		if(!(opaki) && !(DaLiJeOpak) && !(NiOpakNiGadan)){
			if(NoviVektor.size()==0)
				NoviVektor.push_back(vektor[i]);
			else {
				bool VecPostoji(false);
				for(int k=0;k<NoviVektor.size();k++){
					if(NoviVektor[k]==vektor[i]){
						VecPostoji=true;
						break;
					}
				}
				if(!(VecPostoji)) NoviVektor.push_back(vektor[i]);
			}
		}
		
		
	}
	return NoviVektor;
}




int main ()
{
	int broj;
	std::vector<int> vektor ;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin >> broj;
		if(broj == 0 ) break;
		vektor.push_back(broj);
	}
	
	
	
	
	std::vector<int> Opaki(IzdvojiGadne(vektor,true));
	if(vektor.size()==0) {
		vektor.push_back(0);
		std::vector<int> Odvratni(IzdvojiGadne(vektor,false));
	
	}
	std::vector<int> Odvratni(IzdvojiGadne(vektor,false));
	
	std::cout<< "Opaki: ";
	for(int i=0; i<Opaki.size();i++)
		std::cout << Opaki[i] << " " ;
	std::cout << std::endl;
		
	std::cout<< "Odvratni: ";
	for(int i=0; i<Odvratni.size();i++)
		std::cout << Odvratni[i] << " ";	
	
	
	
	return 0;
}