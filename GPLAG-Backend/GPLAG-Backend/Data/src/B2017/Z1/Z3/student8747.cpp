/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>

enum Smjer{Rastuci,Opadajuci};

//Testira stepene dvojke tako sto uzima broj i poredi ga sa 2^n
bool TestStepeniDvojke(double broj)
{
	double pomocna(0), brojac(2);
	if(broj<0) return false;
	if(broj==1||broj==2) return true;
	for(;;)
	{
		pomocna=pow(2,brojac);
		if(pomocna==broj) return true;
		if(pomocna>broj) return false;
		brojac++;
	}
	return false;
}

//Popunjava vektor za zadati pocetak i kraj
std::vector<int> PopuniVektor(std::vector<int> vektor, int pocetak, int kraj)
{
	std::vector<int> novi;
	for(int i = pocetak; i < kraj;i++)
		novi.push_back(vektor.at(i));
	return novi;
}

//Poredi n i n+1 element matrice u zavisnosti od enum unosa,
//za enum rastuci gleda da je prvi manji od drugog
//a za enum opadajuci gleda da je drugi manji od prvog
bool Uporedi(int a, int b, bool test)
{
	//if(!TestStepeniDvojke(a)||!TestStepeniDvojke(b)) return false;
	//std::cout<<"pozvan! a je: "<<a<<" b je: "<<b<<std::endl;
	if(!test&&a<b){ /*std::cout<<"pozvan prvi!"<<std::endl;*/ return true;}
	if(test&&b<a){ /*std::cout<<"pozvan drugi!"<<std::endl;*/ return true;}
	return false;
}

std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> vektor, Smjer neki)
{
	std::deque<std::vector<int>> novi;
	std::vector<int> elementi;
	int pocetak(0),kraj(0),brojac(0);
	bool smjer(false),test(false);
	if(neki==Opadajuci) smjer=true;
	for(auto i : vektor)
	{
		//testira da li je broj iz vektora stepen dvojke
		if(TestStepeniDvojke(i))
		{
			if(brojac>0&&Uporedi(vektor.at(brojac-1),i,smjer)) 
			{
				//ako prodje i ako je prvi put da prolazi onda stavlja test na true
				//da podesi pocetak za dalje testiranje
				if(test==false) {pocetak=brojac-1; test=true; /*std::cout<<"pocetak je: "<<vektor.at(pocetak)<<std::endl;*/}
			}
			else
			{
				//ako element nije stepen dvojke postavlja kraj na vrijednost brojaca
				kraj=brojac;
				//za slucaj kad je kraj-pocetak==1 izbacuje jedan element a ne par elemenata
				//i testira da li se pozivala ikako funkcija koja ce postavljati pocetak
				if(abs(pocetak-kraj)>1&&test==true)
				{
					//dodatno testiranje zbog kriticnih slucajeva kad pocetna if "preskoci" element koji
					//nije stepen dvojke a sljedeci prodje
					for(int k = pocetak; k<kraj; k++)
					//ako nadje element koji nije stepen dvojke u opsegu pocetak kraj onda postavlja kraj na
					//vrijednost k
					if(!TestStepeniDvojke(vektor.at(k))){ kraj=k; break;}
					{
						elementi=PopuniVektor(vektor,pocetak,kraj);
						novi.push_back(elementi);
						elementi.clear();
					}
				}
				//postavlja pocetak na vrijednost brojac zbog ponavljanja podnizova
				//i test na false da moze ponovo uspostaviti brojac u slucaju da uspije if od ovog else
				pocetak=brojac;
				test=false;
			}
		}
		//U slucaju da prodje da se ne pozove else u slucaju iznad (kad je zadnji element zadovoljio uslov a nije pokrenut else)
		//vrsi dodatna testiranja
		if(test==true&&brojac==vektor.size()-1)
		{
			kraj=brojac;
			//testira za parove koji su veci od 2 da li je na kraju element koji je stepen dvojke
			//i ako jeste poveca kraj za jedan zbog toga sto for petlja ne ide do kraja
			if(kraj-pocetak>=1&&TestStepeniDvojke(vektor.at(kraj))) kraj++;
			elementi=PopuniVektor(vektor,pocetak,kraj);
			novi.push_back(elementi);
			elementi.clear();
		}
		brojac++;
	}
	//if(vektor.size()==1) if(TestStepeniDvojke(vektor.at(0))) {elementi.push_back(vektor.at(0)); novi.push_back(elementi);}
	return novi;
}

int main ()
{
	Smjer smjer;
	std::vector<int> vektor;
	std::deque<std::vector<int>> dek;
	double testunosa(0);
	double brojvektora(0),brojac(0);
	std::cout<<"Unesite broj elemenata vektora: ";
	//rigorozno testira za validan unos, postoji odstupanje u slucaju
	//da je unos vrijednosti broj koji je priblizno jednak cijelom broju
	//to jeste 2.00000000001 je priblizno jednak 2
	for(;;)
	{
		std::cin>>brojvektora;
		if((int(brojvektora)/brojvektora==1&&brojvektora>0)){break;}
		else
		{
			std::cout<<"Unos nije validnog formata, pokusajte ponovo!";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
	}
	std::cout<<"Unesite elemente vektora: ";
	for(;;)
	{
		std::cin>>testunosa;
		if(int(testunosa)/testunosa==1)
		{
			vektor.push_back(testunosa); 
			brojac++;
			if(brojac==brojvektora) break;
		}
		else
		{
			std::cout<<"Unos nije validnog formata, pokusajte ponovo!";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	for(;;)
	{
		std::cin>>testunosa;
		if(testunosa==1){smjer=Rastuci; break;}
		else if(testunosa==2){smjer=Opadajuci; break;}
		else{
			std::cout<<"Unos nije validnog formata, pokusajte ponovo!";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
		}
	}
	dek=MaksimalniPodnizoviStepenaDvojke(vektor, smjer);
	if(dek.size()==0) {std::cout<<"Nema podnizova koji odgovaraju uslovima"; return 0;}
	else if(smjer==Rastuci)
	std::cout<<"Maksimalni rastuci podnizovi: ";
	else if(smjer==Opadajuci) std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	for(auto i : dek)
	{
		for(auto j : i)
		{
			std::cout<< j<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}