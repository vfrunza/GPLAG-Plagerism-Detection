#include <iostream>
#include <vector>
#include <cstdlib> // Zbog funckije abs.
#include <utility> // Zbog move semantike.
typedef std::vector<int> vektor;
// Tenar je funkcija koja prima cijelobrojnu vrijednost, a vraca vektor koliko se koja cifra pojavljuje puta u ternarnom brojnom sistemu.
vektor Tenar(int v){
	vektor k(3);
	do
	{
		k.at(abs(v%3))++;
		v/=3;
	}while(v!=0);
	return k;
}
// Funkcija sluzi za izbacivanje dupliakta.
vektor Izbaci(vektor v){ 
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			if(v.at(i)==v.at(j))
			{
				v.erase(v.begin()+j);
				j--;
			}
		}
	}
	return v;
}
vektor IzdvojiGadne(vektor v, bool p){
	v=std::move(Izbaci(v));
	vektor t,q; //"t" je vektor kojeg saljemo nazad u funkciju, a "q" je vektor koji nam govori koliko se puta cifre 0, 1 i 2 pojavljuju u broju.
	int pr,npr; //pr i npr su varijable koje nam govore da koliko se cifara pojavljuje paran ili neparan broj puta.
	for(auto i:v)
	{
		q=std::move(Tenar(i));
		pr=0;
		npr=0;
		for(int j=0;j<3;j++)
		{
			if(q.at(j)==0)
				continue;
			if(q.at(j)%2==0)
				pr++;
			else
				npr++;
		}
		if(p==true) // Ukoliko nam trazi opake...
		{
			if(pr!=0&&npr==0)
				t.push_back(i);
		}
		else // Ukoliko nam trazi odvratne...
		{
			if(npr!=0&&pr==0)
				t.push_back(i);
		}
	}
	return t;
}


int main ()
{
	// Kraci main program za unos i ispis elemenata.
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	vektor v;
	for(;;){
		std::cin>>n;
		if(n==0)
			break;
		v.push_back(n);
	}
	vektor c,b;
	c=std::move(IzdvojiGadne(v,true)); //Koristimo funkciju move zbog brzeg i boljeg rada.
	b=std::move(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(int i:c)
		std::cout<<i<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int i:b)
		std::cout<<i<<" ";
	return 0;
}