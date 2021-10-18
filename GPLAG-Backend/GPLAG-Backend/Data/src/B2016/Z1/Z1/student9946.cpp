#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> IzdvojiGadne (std::vector<int> punoBrojeva,bool a )
{

	std::vector<int> gadniBrojevi;

	for(int i=0; i<punoBrojeva.size(); i++) {
		int brojNula=0;
		int brojJedinica=0;
		int brojDvica=0;
		int broj=fabs(punoBrojeva[i]);
		while (broj!=0) {
			int a=broj%3;
			broj/=3;
			if(a==0) brojNula++;
			else if(a==1) brojJedinica++;
			else brojDvica++;
		}

		if (((brojNula%2==0 && brojNula!=0) || brojNula==0) && ((brojJedinica%2==0 &&brojJedinica!=0) || brojJedinica==0) && ((brojDvica%2==0 && brojDvica!=0 )|| brojDvica==0) && a==true) { //opaki brojevi
			bool postoji=false;
			for(int j=0; j<gadniBrojevi.size(); j++) {
				if(gadniBrojevi[j]==punoBrojeva[i])
					postoji=true;
			}
			if(postoji==false)
				gadniBrojevi.push_back(punoBrojeva[i]);

		} else if (((brojNula%2==1 && brojNula!=0) || brojNula==0) 	&& ((brojJedinica%2==1 && brojJedinica!=0) || brojJedinica==0) && ((brojDvica%2==1 && brojDvica!=0) || brojDvica==0) && a==false) { //odvratni brojevi
			bool postoji=false;
			for(int j=0; j<gadniBrojevi.size(); j++) {
				if(gadniBrojevi[j]==punoBrojeva[i])
					postoji=true;
			}
			if(postoji==false)
				gadniBrojevi.push_back(punoBrojeva[i]);
		}

	}
	return gadniBrojevi;

}
int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	int input;
	std::vector<int> necu;
	while (std::cin >> input && input!=0) {
		necu.push_back(input);
	}
	std::vector<int> opakiBrojevi=IzdvojiGadne(necu,true);
	std::vector<int> odvratniBrojevi=IzdvojiGadne(necu,false);
	std::cout << "Opaki: ";
	for (int i=0; i<opakiBrojevi.size(); i++) {
		std::cout << std::to_string(opakiBrojevi[i])<<" ";
	}
	std::cout << std::endl << "Odvratni: ";
	for (int i=0; i<odvratniBrojevi.size(); i++) {
		std::cout << std::to_string(odvratniBrojevi[i]) <<" ";
	}

	return 0;
}