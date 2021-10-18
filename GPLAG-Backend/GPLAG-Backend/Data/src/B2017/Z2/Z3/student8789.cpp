/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>

template<typename neka>
int Nova(const std::vector<neka>& vektor,int &zabrojac) //int &kolikoseponavlja)
{
	int i(0), j(1), dodaj(0), kolikoseponavlja(0), period(0), b1(1),b2(2);
	bool kraj(true);
	for(;;)
	{
		for(int k = 0;k<b1;k++)
		{
			if()
		}
	}
	for(;;)
	{
		if(vektor.at(i)!=vektor[j]) j++;
		else if(vektor.at(i)==vektor[j]) {i++;j++; kolikoseponavlja=&vektor[j]-&vektor.at(i);}
		if(j==vektor.size())
		{
			zabrojac=i;
			dodaj=kolikoseponavlja-i;
			std::cout<<"dodaj je: "<<dodaj<<std::endl;
			break;
		}
	}
	if(dodaj==0) return vektor.size();
	/*if(dodaj < 0)
	{
		i=1;
		j=2;
		for(;;)
		{
			
		}
	}*/
	std::cout<<"zabrojac je: "<<zabrojac<<", a dodaj je: "<<dodaj;
	return dodaj;
}

template<typename neka>
int TrazenjePerioda(const std::vector<neka>& vektor, int &zabrojac, int &koliko_puta, int &kontinualnaproblem)
{
	int i(2),j(3),period{},kolikoseponavlja{},b1(0),b2(1),dodaj(0);
	bool kraj(true), test(false);
	for(;;)
	{
		for(;;)
		{
			if(!std::equal(vektor.begin(),vektor.begin()+i,vektor.begin()+j)) break;
			else
			{
				//std::cout<<"pozvana";
				period++;
				j+=1+i;
				if(j+i>=vektor.size())
				{
					//if(!std::equal(vektor.begin(), vektor.begin()+i, vektor.begin()+j-1-i)) period--;
					//else period++;
					kolikoseponavlja=&vektor.at(i)-&vektor.at(0)+1;
					kraj=0;
					break;
				}
			}
		}
		if(kraj==false) break;
		if(j>=vektor.size()-1) break;
		i++;
		j=i+1;
		period=0;
		if(j+i>=vektor.size())
			{
				for(;;)
				{
					if(vektor.at(b1)!=vektor.at(b2)) b2++;
					else if(vektor.at(b1)==vektor[b2]) {b2++;b1++; kolikoseponavlja=&vektor[b2]-&vektor.at(b1); test=true;}
					if(b2==vektor.size()){
						koliko_puta=2;
						if(b2==vektor.size())
						{
							zabrojac=b1;
							dodaj=kolikoseponavlja-b1;
						}
						else
						{
							zabrojac=b1+1;
							dodaj=kolikoseponavlja-b1-1;
						}
						return dodaj;
						test=true;
						break;
					}
				}
			}
	}
	//if(test==true) return dodaj;
	if(period==0) return -1;
	//int pomocna((&vektor.at(i)-&vektor.at(0))*period+1);
	//pomocna=vektor.size()-pomocna;
	std::cout<<"pozvana a ne treba"<<std::endl;
	dodaj=(vektor.size()%period);
	if(kolikoseponavlja*period!=vektor.size()){ dodaj=vektor.size()-kolikoseponavlja*period; zabrojac=dodaj; dodaj=kolikoseponavlja-dodaj;}
	std::cout<<"dodaj je: "<<dodaj<<", a period je: "<<period<<", a kolikoseponavlja: "<<kolikoseponavlja;
	//return pomocna;
	koliko_puta=period+1;
	kontinualnaproblem=kolikoseponavlja;
	return dodaj;
}

template<typename neka>
int Zbroji(const std::vector<neka>& vektor, int &kolikofali,int &josjedna)
{
	int i{},j{},k{},suma{};
	bool tacno(false);
	for(int i = 0; i < kolikofali+vektor.size(); i++)
	{
		if(i>=vektor.size()&&!tacno&&josjedna!=vektor.size())
		{
			j=josjedna;
			tacno=true;
		}
		if(josjedna==vektor.size()&&i==vektor.size()-1)
		{
			return suma*=2;
		}
		suma+=vektor.at(j);
		//std::cout<<"Suma je: "<<suma<<std::endl;
		j++;
	}
	return suma;
}

template<typename neka>
int**	AlocirajFragmentirano(const std::vector<neka>& vektor,int koliko_puta)
{
	bool periodicnost{};
	int kolikofali{},pomocna(vektor.size()),josjedna(0),zabrojac(0),kontinualnaproblem(0);
	//periodicnost=TestiranjePeriodicnosti(vektor);
	//if(periodicnost)
	//{
	kolikofali=Nova(vektor, zabrojac);
	//if(kolikofali!=-1)
//	{
//		josjedna=zabrojac;
		//std::cout<<"pozvana traziperiod";
//	}
	//else if(kolikofali==0)
	//}
//	else kolikofali=pomocna;
	//if(kolikofali==-1) kolikofali=pomocna;
	//else kolikofali+=vektor.size();
	//kolikofali++;
	int **p(new int*[kolikofali+vektor.size()]);
	int j(0);
	bool tacno(false);
	std::cout<<"vektor size: "<<vektor.size()<<std::endl;
	std::cout<<"Dinamicki alocirana matrica: ";
	for(int i = 0; i < kolikofali+vektor.size(); i++)
	{
		if(i>=vektor.size()&&!tacno)
		{
			j=zabrojac;
			tacno=true;
		}
		p[i]=new int[vektor[j]];
		for(int k = 0, pomocna= vektor[j]; k < vektor[j]; k++, pomocna--)
		{
			p[i][k]=pomocna;
			//std::cout<<std::setw(4);
			//std::cout<<std::left<<p[i][k-1];//"i je: "<<i<<", a j: "<<j<<", a k: "<<k;
		}
		std::cout<<i<<" ";//std::endl;
		j++;
	}
	return p;
}

template<typename neka>
int**	AlocirajKontinualno(const std::vector<neka>& vektor, int koliko_puta)
{
	int kolikofali{},pomocna(vektor.size()),josjedna(0),zabrojac(0),kontinualnaproblem(0);
	kolikofali=TrazenjePerioda(vektor,zabrojac,koliko_puta,kontinualnaproblem);
	if(kolikofali!=-1)
	{
		josjedna=zabrojac;
	}
	else kolikofali=pomocna;
	int **p(new int*[kolikofali+vektor.size()]{});
	int j(0);
	bool tacno(false);
	int ukupnoelemenata{};
	ukupnoelemenata=Zbroji(vektor, kolikofali, josjedna);
	std::cout<<ukupnoelemenata;
	//ukupnoelemenata++;
	p[0]=new int[ukupnoelemenata]{};
	int zakontinualnu{1},proba(1);
	//std::cout<<"koliko_puta: "<<koliko_puta<<std::endl;
	for(int i = 1; i < kolikofali + vektor.size(); i++)
	{
		//if(zakontinualnu==kontinualnaproblem+1) zakontinualnu=1;
		if(i==1) p[i]=p[0]+proba;
		if(i>=vektor.size()&&!tacno)
		{
			j=josjedna;
			tacno=true;
		}
		if(i!=1)
		{
			proba+=vektor.at(j);
			//std::cout<<"vektor at j je: "<<vektor.at(j)<<"a suma je: "<<proba<<std::endl;
			p[i]=p[0]+proba;
		}
		//zakontinualnu++;
		//proba+=zakontinualnu;
		j++;
	}
	j=0;
	tacno=false;
	//std::cout<<proba<<std::endl;
	//std::cout<<"koliko fali je: "<<kolikofali<<std::endl;
	std::cout<<"Dinamicki alocirana matrica: ";
	proba=0;
	for(int i = 0; i < kolikofali+vektor.size(); i++)
	{
		if(i>=vektor.size()&&!tacno)
		{
			j=josjedna;
			tacno=true;
		}
		//p[i]=new int[vektor[j]];
		for(int k = 0; k < vektor[j]; k++)
		{
			p[i][k]=k+1;
			std::cout<<std::setw(4);
			std::cout<<std::left<<p[i][k];//
			//std::cout<<"i je: "<<i<<", a j: "<<j<<", a k: "<<k<<std::endl;
		}
		proba++;
		std::cout<<std::endl;
		j++;
	}
	return p;
}

int main()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int brojelemenata{},koliko_puta{0};
	std::cin>>brojelemenata;
	std::vector<int> vektor(brojelemenata);
	std::cout<<"Unesite elemente: ";
	int pomocna{};
	for(int i = 0; i < brojelemenata; i++)
	{
		std::cin>>pomocna;
		vektor[i]=pomocna;
	}
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int alokacija{},kontinualnaproblem(0);
	std::cin>>alokacija;
	int** p;
	int zabrojac(0);
	if(alokacija==1)
	{
		p=(AlocirajFragmentirano(vektor,koliko_puta));
		pomocna=Nova(vektor, zabrojac);
		pomocna+=vektor.size();
		bool test(false);
	int k(0);
	for(int i = 0; i < pomocna; i++)
	{
		for(int j = 0; j < vektor[k]; j++)
		{
			std::cout<<p[i][j]<<" ";
		}
		k++;
		if(i>=vektor.size()-1&&!test)
		{
			k=zabrojac;
			test=true;
		}
	//	k++;
		std::cout<<i<<" "<<std::endl;
	}
		for(int i = 0; i < pomocna; i++)
		{
			delete[] p[i];
		}
		delete[] p;
	}
	else p=(AlocirajKontinualno(vektor,koliko_puta));
//	std::cout<<"Dinamicki alocirana matrica: ";
	
	return 0;
}
