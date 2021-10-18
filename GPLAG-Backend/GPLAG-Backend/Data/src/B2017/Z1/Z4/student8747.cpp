/*B 2017/2018, Zadaća 1, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <string>
#include <vector>

//testira dva slova na jednakost i velicinu, jednaki su kad su iste velicine
bool TestirajJednakost(char prvi, char drugi)
{
	if(prvi==drugi) 
	{
		if((prvi>='a'&&prvi<='z'&&drugi>='a'&&drugi<='z')||(prvi>='A'&&prvi<='Z'&&drugi>='A'&&drugi<='Z'))
			return true;
	}
	return false;
}

//Funkcija za manipulacije sa stringom
std::string PreurediString(std::string recenica, std::string rijec, int pozicija,bool polu)
{
	std::string novi;
	//U slucaju da je poziv iz polupalindrom funkcije jer se ne smije dodavat novih znakova u string
	if(!polu) novi=recenica;
	//za poseban slucaj je potreban zbog velicina koje su ili parne ili neparne po broju cifara u polupalindrom
	//za parne je to 1 a za neparne 2, da pomjeri "pokazivac" unazad na tacnu poziciju
	int brojac(0),nova(0),zapolu(0),zaposebanslucaj(2);
	//nova sluzi kao brojac za koliko cemo mjesta pomjerati "pokazivac" u oba slucaja
	if(polu) nova=rijec.size()-1;
	else nova=rijec.size()/2;
	if(rijec.size()%2==0&&!polu) zaposebanslucaj=1;
	for(;;)
	{
		//polu radi samo za palindrom
		if(polu)
		{
			if(brojac==pozicija)
			{
				if(nova!=-1) for(;;)
				{
					novi.push_back(rijec.at(nova));
					nova--;
					if(nova==-1)
					{
						brojac++; 
						//nova ide do -1 i prekida petlju, i na kraju dodaje razmak u slucaju da je "pokazivac" na poziciji koja nije kraj stringa
						if(brojac<=recenica.size()) novi.push_back(recenica.at(brojac-1));
						break;
					}
				}
			}
			else
			{
				//dodaje u novi string sva slova do kriticne tacke(one gdje je uocena jednakost rijeci iz recenice i rijeci iz vektora)
				if(brojac>=recenica.size()) break;
				novi.push_back(recenica.at(brojac));
				brojac++;
			}
		}
		//za polupalindrom varijantu, kad dodje do kriticne vrijednosti ulazi u if
		if(brojac==pozicija+zapolu&&!polu)
		{
			for(;;)
			{
				//pomjera "pokazivac" sa sredine (za poseban slucaj omogucuje da se pravilno kopira u sredinu rijeci[na koordinati gdje je brojac])
				//za poseban slucaj pravi tacan razmak od "pokazivaca"
				//ova petlja vrsi "pomjeranje"(tehnicki kopiranje) elemenata bez ikakvih vanjskih znakova i varijabli
				novi.at(brojac)=novi.at(brojac-zapolu*2-zaposebanslucaj);
				//zapolu je poseban brojac koji sluzi da izbroji koliko treba puta kopirati slovo u slovo
				//koristim ga jer nije mogao da radi nova--, isao je van opsega.
				zapolu++;
				brojac++;
				if(zapolu==nova) return novi;
			}
		}
		//za polupalindrom, vrsi pomjeranje brojaca, da ne bih pravio posebnu funkciju prepravio sam malo ovu
		if(!polu) brojac++;
	}
	return novi;
}


std::string Testiraj(std::string recenica, std::string rijec,bool polu)
{
	int pozicija(0),pomocna(0);
	std::string novi,pomocnistring(recenica);
	for(;;)
	{
		//za specijalne slucajeve gdje je znak razmaka u vektoru rijeci i u recenici
		if(pomocnistring.at(pozicija)==' ') 
			if(rijec.at(pomocna)==' ') 
			{
				pomocna++;
				pozicija++;
			}
		//test da ne ode iz opsega
		if(pozicija==pomocnistring.size()) break;
		if(TestirajJednakost(pomocnistring.at(pozicija),rijec.at(pomocna)))
		{
			pomocna++;
			//za rubne slucajeve gdje ne mogu pristupati zbog .at()
			//gleda da li je zadnja rijec u recenici ista kao zadata rijec iz vektora i da li je zaista kraj recenice
			if(pozicija==pomocnistring.size()-2&&polu&&pomocna==rijec.size()-1) 
			{
				//pozicija+2 je da pomjeri "pokazivac" na prazno mjesto i da tu ubacim rijec koja prolazi uslov
				novi=PreurediString(pomocnistring,rijec,pozicija+2,polu);
				pomocnistring=novi;
				return pomocnistring;
			}
			if(pozicija==pomocnistring.size()-2&&!polu&&pomocna==rijec.size()-1)
			{
				//pozicija-rijec.size()/2+2 je da tacno pomjeri string na "sredinu"
				novi=PreurediString(pomocnistring,rijec,pozicija-rijec.size()/2+2,polu);
				pomocnistring=novi;
				return pomocnistring;
			}
		}
		else 
		{
			//u slucaju da dva znaka nisu jednaka vraca "pokazivac" rijeci na 0
			pomocna=0;
			//u slucaju da uzastopni znak (onaj poslije neuspjelog pokusaja) isti kao prvi znak rijeci 
			if(TestirajJednakost(pomocnistring.at(pozicija),rijec.at(pomocna))) pomocna++;
		}
		//ako je rijec ispinjava uslov
		if(pomocna==rijec.size()-1)
		{
			//za palindrom
			if(polu==true)
			{
				//testira da ne ode iz opsega i da su u recenici na pozicija+2 specijalni znakovi (koji nisu slova)
				if(pozicija+2<pomocnistring.size()) if(pomocnistring.at(pozicija+2)>=32&&pomocnistring.at(pozicija+2)<=47)
				{
				novi=PreurediString(pomocnistring,rijec,pozicija+2,polu);
				pomocnistring=novi;
				pomocna=0;
				}
			}
			else
			{
				//za polupalindrom
				if(pozicija+2<pomocnistring.size()) if(pomocnistring.at(pozicija+2)>=32&&pomocnistring.at(pozicija+2)<=47)
				{
					novi=PreurediString(pomocnistring,rijec,pozicija-rijec.size()/2+2,polu);
					pomocnistring=novi;
					pomocna=0;
				}
			}
		}
		//U slucaju da se if iznad koji gleda razmake odradi i doda jednu "vise" jedinicu na brojac
		if(pomocna==rijec.size()) pomocna=0;
		novi=pomocnistring;
		if(pozicija==pomocnistring.size()-1){ /*std::cout<<"prekida"<<std::endl;*/ break;}
		//pozicija je "pokazivac" recenice
		pozicija++;
	}
	return novi;
}

std::string NapraviPoluPalindrom(std::string recenica, std::vector<std::string> vektor)
{
	//kad je vektor rijeci prazan vraca recenicu
	if(vektor.size()==0) return recenica;
	std::string novi,pomocni;
	//kad je recenica prazna vraca prazan string
	if(recenica.size()==0) return novi;
	pomocni=recenica;
	//pomjera se kroz vektor i salje rijeci u funkciju
	for(auto i : vektor)
	{
		novi=Testiraj(pomocni,i,false);
		//u slucaju da vrati vektor koji je dobio znakove onda ga ponovo salje u funkciju na dalju obradu
		if (novi.size()!=0) pomocni=novi;
	}
	return novi;

}

std::string NapraviPalindrom(std::string recenica, std::vector<std::string> vektor)
{
	if(vektor.size()==0) return recenica;
	std::string novi,pomocni;
	if(recenica.size()==0) return novi;
	pomocni=recenica;
	for(auto i : vektor)
	{
		novi=Testiraj(pomocni,i,true);
		if (novi.size()!=0) pomocni=novi;
	}
	return novi;
}

int main ()
{
	std::string recenica,nova,pomocna;
	std::vector<std::string> vektor;
	std::cout<<"Unesite recenicu: ";
	std::getline (std::cin, recenica);
	std::cout<<"Unesite fraze: ";
	for(;;)
	{
		std::getline (std::cin, pomocna);
		if(pomocna.size()==0) break;
		vektor.push_back(pomocna);
		pomocna.clear();
	}
	nova=NapraviPalindrom(recenica, vektor);
	std::cout<<"Recenica nakon Palindrom transformacije: ";
	for(auto i : nova)
		std::cout << i;
	nova.clear();
	nova=NapraviPoluPalindrom(recenica,vektor);
	std::cout<<std::endl<<"Recenica nakon PoluPalindrom transformacije: ";
	for(auto i : nova)
		std::cout << i;
		
	return 0;
}