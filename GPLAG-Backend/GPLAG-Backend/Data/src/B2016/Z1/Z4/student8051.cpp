#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

bool ws(char s){		//	Ova funkcija mi sluzi da mi ukaze na to da li je odabrani znak slovo ili ne. Ukoliko je slovo, salje 0. U suprotnom 1.
   if((s>='a'&&s<='z')||(s>='A'&&s<='Z'))
      return 0;
   else 
      return 1;
}
std::string ObrniFraze(std::string s, std::vector<std::string> v){
	char pom;	// Pomocni char. Sluzi kasnije za razmjenu znakova.
	for(int i=0;i<v.size();i++)
	{
		int k(v.at(i).length());	// K oznacava duzinu stringa.
		for(int j=0;j<s.length()-k+1;j++)	//  Petlja ide do s.length()-k+1 zato jer kad bude trazio zeljenu rijec, naci ce je dotle. U suprotnom je nema tu nikako.
		{
			if(v.at(i).at(0)==s.at(j))	//  Gleda da li se prvi znak stringa u vektoru poklapa sa stringom u recenici.
			{
				std::string p(s.substr(j,k));	//	Uzimamo string sa mjesta odakle se poklakapaju znakovi i gledamo da li su to iste rijeci, odnosno fraze.
				if(p==v.at(i))					//	Ukoliko jesu, onda je "obrcemo", u suprotnom nastavljamo pretragu.
				{
					for(int r=j;r<j+k/2;r++)	//	Ovdje rijec obrcemo, idemo do pola rijeci i krajnji znakovi se mijenjaju sa prednjim.
					{
						pom=s.at(r);
						s.at(r)=s.at(j+k-r+j-1);
						s.at(j+k-r-1+j)=pom;
					}
					j+=k-1;						// Stavljamo pokazivac na iduce mjesto.
				}
			}
		}
	}
	return s;
}
std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{
	for(int i=0;i<v.size();i++)		//	Ovdje provjeravamo da li u vektor stringova postoji ikakav znak koji nije u slovu engleske abecede.
	{								//	Ukoliko jest bacamo izuzetak, u suprotnom nastavljamo sa radom.
		for(int j=0;j<v.at(i).length();j++)
		{
			if(ws(v.at(i).at(j)))
				throw std::domain_error("Nekorektan izbor rijeci");
		}
	}
	if(v.empty())		//	U slucaju  da je vektor prazan, primjenjujemo PigLatin na svaku rijec u stringu.
	{
		for(int i=0;i<s.length();i++)
		{
			if((i==0&&ws(s.at(i))==0)||(ws(s.at(i))==0&&ws(s.at(i-1))==1))	//	Prvi uslov je da ukoliko se rijec nalazi na pocetku stringa. Ovi ostali su za rijeci koje nisu na prvom mjestu (logicno).
			{																//	Naravno, dakle prvo provjeravamo da li se na toj poziciji nalazi slovo ili ne. Ukoliko se nalazi slovo na toj poziciji,
				int j=i;													//	a prethodni znak nije slovo, onda primjenjujemo PigLatin.
				while(ws(s.at(j))==0)		//	Idemo do kraja rijeci.
				{
					if(j==s.length()-1)
						break;
					j++;
				}
				if(ws(s.at(j)))				//	Ukoliko prelazimo rijec (a hocemo, osim ako je zadnja i nalazi se na kraju stringa) onda vracamo j za jedan ulijevo.
					j--;
				char c=s.at(i);				//	Slovo koje cemo brisati ulazi u char c.
				s.erase(s.begin()+i);		//	Brisemo prvo slovo rijeci.
				std::string q;				
				q.push_back(c);				//	U string q ubacujemo to prvo slovo, pa dodajemo na to "ay".
				q+="ay";
				s.insert(j,q);				//	Zatim taj string q ubacujemo na kraj rijeci.
				i=j+2;						//  Micemo "i" na kraj nase nove rijeci.
			}
		}
	}
	else{
	for(int i=0;i<v.size();i++)
	{
		int k(v.at(i).length());
		for(int j=0;j<s.length();j++)
		{
			if(v.at(i).at(0)==s.at(j))
			{
				std::string p(s.substr(j,k));
				if(v.at(i)==p&&(j+k==s.length()||ws(s.at(j+k)))&&(j==0||ws(s.at(j-1))))		//	Ukoliko je rijec koju trazimo nalazi u stringu i ukoliko se na kraju rijeci nalazi neki znak koji nije iz engleske abecede, primijenjujemo PigLatin.
				{
					s.erase(s.begin()+j);		//	Brisemo prvo slovo iz rijeci.
					std::string q;
					q.push_back(v.at(i).at(0));		//	Prvo slovo rijeci sstavljamo u string q. Zatim dodajemo u string q "ay".
					q+="ay";
					j+=k-1;					//	j stavljamo na kraj prve rijeci.
					s.insert(j,q);			//	Stavljamo rijec q na kraj te trazene rijeci koju smo htjeli izmijeniti...
				}
			}
		}
	}
	}
	return s;
}

int main ()
{									//	Kratki main program za unos i ispis zadatka.
	std::cout<<"Unesite recenicu: ";
	std::string s;
	std::getline(std::cin,s);
	std::string p;
	std::vector<std::string> v;
	std::cout<<"Unesite fraze: ";
	char c;
	do{
		std::getline(std::cin,p);
		c=std::cin.peek();				//	Koristim peek da vidim sta mi se nalazi u ulaznom toku.
		if(c=='\n')						//	Ukoliko je tamo samo novi red, onda mi se prekida petlja.
			break;
		v.push_back(p);					//	U vektor v guramo string koji unosimo sa ulaznog toka.
		p.clear();						//	I brisemo p string(za svaki slucaj).
	}while(c!='\n');
	if(p.length()>0)					//	Ovo ovdje mi sluzi da onaj zadnji string iz ulaznog toka ubacim u vektor. Ako saljem prazan string, ovo se nece izvrsiti.
		v.push_back(p);
	try{						//	Obicni try-catch u slucaju ako se u vektoru nalazi ista sto nije u engleskoj abecedi.
		std::cout<<"Recenica nakon PigLatin transformacije: "<<IzmijeniUPigLatin(s,v)<<std::endl;
	}
	catch(std::domain_error izuzetak){	//	U slucaju izuzetka izbacuje poruku na ekran.
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}
	std::cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(s,v);	//	I na kraju poziva se funkcija ObrniFraze.
	 
    
	return 0;
}