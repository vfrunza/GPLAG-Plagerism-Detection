#include <iostream>
#include <vector>
#include <iomanip> //Zbog ispisa. 
#include <utility> //Zbog funkcije move.
typedef std::vector<double> vektor; //Radi ljepseg koda koristio sam ove typedef deklaracije da ne bi izgledalo tako "rogobatno" (da bi kod izgledao ljepse).
typedef std::vector<std::vector<double>> matrica;

matrica RastuciPodnizovi(std::vector<double> c){
	matrica k;//Formira se prazna matrica u kojoj se smjestaju maksimalno opadajuci nizovi.
	for(int i=0;i<c.size();i++)
	{
		int j(i);//Princip ide da se prvo odredi pocetak tog podniza i njegov kraj. To radimo preko 2 brojaca, "j" i "i", gdje je j kraj, a i pocetak. 
		while(j<c.size())
		{
			if(j==c.size()-1&&i!=j) //Za zadnjeg clana. 
			{
				k.resize(k.size()+1); //Formiramo novi red u matrici i u njoj smjestamo elemente vektora c.
				for(int t=i;t<=j;t++)
					k.at(k.size()-1).push_back(c.at(t));
				i=j;
				break;
			}
			else if(j==c.size()-1&&i==j) //Ukoliko su dosli do zadnjeg elementa, a nije u podnizu, onda prekidamo (zbog uslova ispod).
				break;
			if(c.at(j)<=c.at(j+1)) //Ukoliko sljedeci clan zadovoljava kriterij maksimalnog podniza, povecava se brojac j. 
				j++;
			else if(i!=j) //A ukoliko ne zadovoljava, ovaj dosadasnji podniz smjestamo u matricu k.
			{
				k.resize(k.size()+1);
				for(int t=i;t<=j;t++)
					k.at(k.size()-1).push_back(c.at(t));
				i=j;	//Stavljamo pocetak na kraj podniza i prekidamo ovu while petlju. 
				break;
			}
			else
				break; //Ako je "i" jednak "j" a sljedeci clan ne zadovoljava kriterij maximalnog podniza, prekidamo petlju.
		}
	}
	return k;
}
/*Da ne bih pisao opet jedno te isto, posto je ovo identicno poput gornje funkcije (umjesto < stavlja se >) analogno komentari se vezu za 
funkciju OpadajuciPodnizovi...*/
matrica OpadajuciPodnizovi(vektor c){
	matrica k;
	for(int i=0;i<c.size();i++)
	{
		int j(i); 
		while(j<c.size())
		{
			if(j==c.size()-1&&i!=j)
			{
				k.resize(k.size()+1);
				for(int t=i;t<=j;t++)
					k.at(k.size()-1).push_back(c.at(t));
				i=j;
				break;
			}
			else if(j==c.size()-1&&i==j)
				break;
			if(c.at(j)>=c.at(j+1))
				j++;
			else if(i!=j) 
			{
				k.resize(k.size()+1);
				for(int t=i;t<=j;t++)
					k.at(k.size()-1).push_back(c.at(t));
				i=j;
				break;
			}
			else
				break;
		}
	}
	return k;
}

int main ()
{
	//Kraci main za unos i ispis elemenata.
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	vektor v;
	double k;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		std::cin>>k;
		v.push_back(k);
	}
	matrica p;
	p=std::move(RastuciPodnizovi(v)); //Move semantiku koristim da ne bi bilo nekih PREogromnih matrica... Jer je ljepse, brze i bolje :)
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	//Ispis maksimalno rastucih podnizova preko rangovske petlje.
	for(auto i:p)
	{
		for(auto j:i)
			std::cout<<j<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	p=std::move(OpadajuciPodnizovi(v));
	//Ispis maksimalno opadajucih podnizova preko rangovske petlje.
	for(auto i:p)
	{
		for(auto j:i)
			std::cout<<j<<" ";
		std::cout<<std::endl;
	}
	return 0;
}