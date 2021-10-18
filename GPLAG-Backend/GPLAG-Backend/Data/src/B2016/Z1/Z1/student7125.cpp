//B 2016/2017, Zadaća 1, Zadatak 1

#include<iostream>
#include<vector>

typedef std::vector<int> vektor;

vektor IzdvojiGadne(vektor ulaz, bool opaki);

int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	vektor brojevi;

	while(true) {
		int unos;
		std::cin >> unos;
		if(unos == 0) break;

		brojevi.push_back(unos);


	}

	vektor opaki(IzdvojiGadne(brojevi, true));
	std::cout <<"Opaki:";

	for(int x : opaki)
		std::cout<<" "<< x;

	std::cout << std::endl;

	vektor odvratni(IzdvojiGadne(brojevi, false));
	std::cout<< "Odvratni:";
	for(int x : odvratni)
		std::cout <<" "<< x;

	return 0;
}

vektor IzdvojiGadne(vektor ulaz, bool izbor)
{
	vektor gadni;

	for(int x : ulaz) {
		vektor vrijednosti(3,0);			//sve tri moguće vrijednosti inicijaliziramo na 0 ponavljanja
		int temp(x);
		while(temp != 0) {
			vrijednosti[abs(temp%3)]++;		//ostatak sigurno nikada neće biti veći od 2 => abs() je sigurno koristiti
			temp /=3;
		}
		if(izbor) { 
			bool paran(true);
			for(int y : vrijednosti)
				if(y%2 != 0 && y != 0)
					paran = false;				//neka cifra se ne ponavlja paran broj puta => nije opak

			if(paran && x != 0) //ako je unos 0 onda će automatski stavljati među opake jer se petlja iznad nikada neće izvršiti pa će paran ostat true
				gadni.push_back(x);		//upisuj gadne
		}

		if (izbor == false) {
			bool neparan(true);
			//izdvoji odvratne
			for(int y : vrijednosti)	
				if(y%2 == 0 && y != 0)
					neparan = false;
					
			if(neparan)
				gadni.push_back(x);
		}


	}
	
	for(int i = 0; i < gadni.size(); i++)				//brišemo duplikate
		for(int j = gadni.size()-1; j > i; j--)
			if(gadni[i] == gadni[j])
				gadni.erase(gadni.begin()+j);


return gadni;

}