/*B 2017/2018, Zadaća 2, Zadatak 1
	
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
#include <stdexcept>
#include <string>

enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla podloga_igrice (n);
	for(int i=0; i<n; i++)
	{
		podloga_igrice.at(i)=std::vector<Polje>(n, Polje::Prazno);
	}
	
	
	for(int i=0; i<mine.size(); i++)           //ako jedan od vektora matrice "mine", sadrzi vise ili manje od dva elementa
	{
		if(mine.at(i).size()!=2)
		throw std::domain_error("Ilegalan format zadavanja mina");
	}
	
	for(int i=0; i<mine.size(); i++)     //ako je zadata pozicija mine na tablici koja ne postoji
	{
		for(int j=0; j<mine.at(0).size(); j++)
		{
			if(mine.at(i).at(j)>=n || mine.at(i).at(j)<0)
			throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	
	if(n<=0)
	throw std::domain_error("Ilegalna velicina");
	
	
	for(int i=0; i<mine.size(); i++)
	{
		for(int j=0; j<mine.at(0).size(); j++)
		{
			if((j+1)!=mine.at(i).size() )
			podloga_igrice.at( mine.at(i).at(j) ).at( mine.at(i).at(j+1) )=Polje::Mina; //??
		}
	}
	return podloga_igrice;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &podloga_igrice, int x, int y)
{
	std::vector<std::vector<int>> okolina(3, std::vector<int>(3, 0));
	int brojac(0);
	
	if(x<0 || x>=podloga_igrice.size() || y<0 || y>=podloga_igrice.at(0).size())
	throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	int brx=x-1;
	int bry=y-1;
	
	for(int i=0; i<okolina.size(); i++)
	{
		for(int j=0; j<okolina.at(0).size(); j++)
		{
				if( (brx-1)>=0 && (bry-1)>=0 && podloga_igrice.at(brx-1).at(bry-1)==Polje::Mina)
				brojac++;
				if( (brx-1)>=0 && (bry)>=0 && podloga_igrice.at(brx-1).at(bry)==Polje::Mina)
				brojac++;
				if( (brx-1)>=0 && (bry+1)>=0 && (bry+1)<podloga_igrice.at(0).size() && podloga_igrice.at(brx-1).at(bry+1)==Polje::Mina)
				brojac++;
				if( (brx)>=0 && (bry-1)>=0 && podloga_igrice.at(brx).at(bry-1)==Polje::Mina)
				brojac++;
				if( (brx)>=0 && (bry+1)>=0 && (bry+1)<podloga_igrice.at(0).size() && podloga_igrice.at(brx).at(bry+1)==Polje::Mina)
				brojac++;
				if( (brx+1)>=0 && (bry-1)>=0 && (brx+1)<podloga_igrice.size() && podloga_igrice.at(brx+1).at(bry-1)==Polje::Mina)
				brojac++;
				if( (brx+1)>=0 && (bry)>=0 && (brx+1)<podloga_igrice.at(0).size() && podloga_igrice.at(brx+1).at(bry)==Polje::Mina)
				brojac++;
				if( (brx+1)>=0 && (y+1)>=0 && (brx+1)<podloga_igrice.size() && (bry+1)<podloga_igrice.at(0).size() && podloga_igrice.at(brx+1).at(bry+1)==Polje::Mina)
				brojac++;
				
			okolina.at(i).at(j)=brojac;
			brojac=0;
			bry++;
			
			if(bry>(y+1))
			{
				brx++;
				bry=(y-1);
			}
			if(brx>(x+1))
				return okolina;
			
		}
	}
	return okolina;
}


void BlokirajPolje(Tabla &podloga_igrice, int x, int y)
{
	if( x<0 || x>=podloga_igrice.size() || y<0 || y>=podloga_igrice.at(0).size())
	throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if(podloga_igrice.at(x).at(y)==Polje::Prazno)
	podloga_igrice.at(x).at(y)=Polje::BlokiranoPrazno;
	else if(podloga_igrice.at(x).at(y)==Polje::Posjeceno)
	podloga_igrice.at(x).at(y)=Polje::BlokiranoPosjeceno;
	else if(podloga_igrice.at(x).at(y)==Polje::Mina)
	podloga_igrice.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &podloga_igrice, int x, int y)
{
	if( x<0 || x>=podloga_igrice.size() || y<0 || y>=podloga_igrice.at(0).size())
	throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	if(podloga_igrice.at(x).at(y)==Polje::BlokiranoPrazno)
	podloga_igrice.at(x).at(y)=Polje::Prazno;
	else if(podloga_igrice.at(x).at(y)==Polje::BlokiranoPosjeceno)
	podloga_igrice.at(x).at(y)=Polje::Posjeceno;
	else if(podloga_igrice.at(x).at(y)==Polje::BlokiranoMina)
	podloga_igrice.at(x).at(y)=Polje::Mina;
}

enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status{
	NijeKraj, KrajPoraz, KrajPobjedna
};

Status Idi(Tabla &podloga_igrice, int &red, int &kolona, Smjerovi smijer) //"red" i "kolona" predstavljaju trenutnu poziciju igraca
{
	Status nastavak;
	
	podloga_igrice.at(red).at(kolona)=Polje::Posjeceno;
	
	if(smijer==Smjerovi::Gore)
	{
		if((red-1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red-1).at(kolona)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red-1).at(kolona)==Polje::BlokiranoPrazno || podloga_igrice.at(red-1).at(kolona)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		red=(red-1);
	}
	else if(smijer==Smjerovi::Dolje)
	{
		if((red+1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red+1).at(kolona)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red+1).at(kolona)==Polje::BlokiranoPrazno || podloga_igrice.at(red+1).at(kolona)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		red=(red+1);
	}
	else if(smijer==Smjerovi::Desno)
	{
		if((kolona+1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red).at(kolona+1)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red).at(kolona+1)==Polje::BlokiranoPrazno || podloga_igrice.at(red).at(kolona+1)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		kolona=(kolona+1);
	}
	else if(smijer==Smjerovi::Lijevo)
	{
		if((kolona-1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red).at(kolona-1)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red).at(kolona-1)==Polje::BlokiranoPrazno || podloga_igrice.at(red).at(kolona-1)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		kolona=(kolona-1);
	}
	else if(smijer==Smjerovi::GoreLijevo)
	{
		if((red-1)<0 || (kolona-1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red-1).at(kolona-1)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red-1).at(kolona-1)==Polje::BlokiranoPrazno || podloga_igrice.at(red-1).at(kolona-1)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		{
			red=(red-1);
			kolona=(kolona-1);
		}
	}
	else if(smijer==Smjerovi::GoreDesno)
	{
		if((red-1)<0 || (kolona+1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red-1).at(kolona+1)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red-1).at(kolona+1)==Polje::BlokiranoPrazno || podloga_igrice.at(red-1).at(kolona+1)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		{
			red=(red-1);
			kolona=(kolona+1);
		}
	}
	else if(smijer==Smjerovi::DoljeDesno)
	{
		if((red+1)<0 || (kolona+1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red+1).at(kolona+1)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red+1).at(kolona+1)==Polje::BlokiranoPrazno || podloga_igrice.at(red+1).at(kolona+1)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		{
			red=(red+1);
			kolona=(kolona+1);
		}
	}
	else if(smijer==Smjerovi::DoljeLijevo)
	{
		if((red+1)<0 || (kolona-1)<0)
		throw std::out_of_range("Izlazak van igrace table");
		else if(podloga_igrice.at(red+1).at(kolona-1)==Polje::BlokiranoPosjeceno || podloga_igrice.at(red+1).at(kolona-1)==Polje::BlokiranoPrazno || podloga_igrice.at(red+1).at(kolona-1)==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		else
		{
			red=(red+1);
			kolona=(kolona-1);
		}
	}
	
	if(podloga_igrice.at(red).at(kolona)==Polje::Mina)
	{
		nastavak=Status::KrajPoraz;
		for(int i=0; i<podloga_igrice.size(); i++)
			for(int j=0; j<podloga_igrice.size(); j++)
				podloga_igrice.at(i).at(j)=Polje::Prazno;
	}
	else if(podloga_igrice.at(red).at(kolona)==Polje::Prazno)
	{
		bool sve_prazno(true);
		for(int i=0; i<podloga_igrice.size(); i++)
		{
			for(int j=0; j<podloga_igrice.size(); j++)
			{
				if(podloga_igrice.at(i).at(j)!=Polje::Prazno)
				sve_prazno=false;
			}
		}
		
		if(sve_prazno)
			nastavak=Status::KrajPobjedna;
		else
			nastavak=Status::NijeKraj;
			
		podloga_igrice.at(red).at(kolona)=Polje::Posjeceno;
	}
	else if(podloga_igrice.at(red).at(kolona)==Polje::BlokiranoPrazno || podloga_igrice.at(red).at(kolona)==Polje::BlokiranoMina || podloga_igrice.at(red).at(kolona)==Polje::BlokiranoPosjeceno)
	std::cout<<"Blokirano polje"; 
	

	return nastavak;
}

Status Idi(Tabla &podloga_igrice, int &red, int &kolona, int novi_red, int nova_kolona) 
{
	Status nastavak;
	podloga_igrice.at(red).at(kolona)=Polje::Posjeceno;
	
	if(novi_red<0 || novi_red>=podloga_igrice.size() || nova_kolona<0 || nova_kolona>=podloga_igrice.at(0).size() )
	throw std::out_of_range("Izlazak van igrace table");
	else if(podloga_igrice.at(novi_red).at(nova_kolona)==Polje::BlokiranoPosjeceno || podloga_igrice.at(novi_red).at(nova_kolona)==Polje::BlokiranoPrazno || podloga_igrice.at(novi_red).at(nova_kolona)==Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
	else
	{
		red=novi_red;
		kolona=nova_kolona;
	}
	
	if(podloga_igrice.at(red).at(kolona)==Polje::Mina)
	{
		nastavak=Status::KrajPoraz;
		for(int i=0; i<podloga_igrice.size(); i++)
			for(int j=0; j<podloga_igrice.size(); j++)
				podloga_igrice.at(i).at(j)=Polje::Prazno;
	}
	else if(podloga_igrice.at(red).at(kolona)==Polje::Prazno)
	{
		bool sve_prazno(true);
		for(int i=0; i<podloga_igrice.size(); i++)
		{
			for(int j=0; j<podloga_igrice.size(); j++)
			{
				if(podloga_igrice.at(i).at(j)!=Polje::Prazno)
				{ 
					sve_prazno=false;
					break;
				}
			}
			if(!sve_prazno)
			break;
		}
		
		if(sve_prazno)
			nastavak=Status::KrajPobjedna;
		else
			nastavak=Status::NijeKraj;
			
		podloga_igrice.at(red).at(kolona)=Polje::Posjeceno;
	}
	
	return nastavak;
}
////////////////
enum class KodoviGresaka{ PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};

void PrijaviGresku(KodoviGresaka greska)
{
	if(greska==KodoviGresaka::PogresnaKomanda)
	std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar)
	std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar)
	std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(greska==KodoviGresaka::SuvisanParametar)
	std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

bool UnosKomande(Komande &komanda, Smjerovi &smijer, int &x, int &y, KodoviGresaka &greska)
{
	bool tacno(false);
	std::string kod;
	std::vector<std::string> naredbe;
	
	std::getline(std::cin, kod);
	
	std::string::iterator p;
	p=kod.begin();
	
	int i(1);
	
	do{
		while(p!=kod.end() && *p==' ')
		p++;
		
		if(i==1)
		{
			while(p!=kod.end() && *p!=' ')
			{
				naredbe.resize(i);
				naredbe.at(i-1).push_back(*p);
				p++;
				tacno=true;
			}
		}
		if(tacno)
		i++;
		
		while(p!=kod.end() && *p!=' ')
		{
			naredbe.resize(2);
			naredbe.at(1).push_back(*p);
			p++;
		}
		
		if(naredbe.size()==2 && *p==' ')
		naredbe.at(1).push_back(*p);
		
		tacno=false;
		
	}while(p!=kod.end());
	
	if(naredbe.size()==0)
	{
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(naredbe.at(0)!="P1" && naredbe.at(0)!="P>" && naredbe.at(0)!="B" && naredbe.at(0)!="D" && naredbe.at(0)!="PO" && naredbe.at(0)!="Z" && naredbe.at(0)!="K")
	{
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	if(naredbe.size()<2 && naredbe.at(0)=="P1")          
	{
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	}
	/*if(naredbe.size()>2 && naredbe.at(0)=="P1" && (naredbe.at(1)=="GL" || naredbe.at(1)=="G" || naredbe.at(1)=="D" || naredbe.at(1)=="DoD" || naredbe.at(1)=="DoL" || naredbe.at(1)=="L" || naredbe.at(1)=="GD" || naredbe.at(1)=="Do") )          
	{
		greska=KodoviGresaka::SuvisanParametar;
		return false;
	}*/
	if( naredbe.size()==2 && naredbe.at(0)=="P1" && naredbe.at(1)!="GL" && naredbe.at(1)!="G" && naredbe.at(1)!="D" && naredbe.at(1)!="DoD" && naredbe.at(1)!="DoL" && naredbe.at(1)!="L" && naredbe.at(1)!="GD" && naredbe.at(1)!="Do")          
	{
		greska=KodoviGresaka::NeispravanParametar;
		return false;
	}
	if(naredbe.size()==2 && naredbe.at(0)=="P1" && (naredbe.at(1)=="GL" || naredbe.at(1)=="G" || naredbe.at(1)=="D" || naredbe.at(1)=="DoD" || naredbe.at(1)=="DoL" || naredbe.at(1)=="L" || naredbe.at(1)=="GD" || naredbe.at(1)=="Do") )          
	{
		komanda=Komande::PomjeriJednoMjesto;
		
		if(naredbe.at(0)=="P1" && naredbe.at(1)=="GL")
		smijer=Smjerovi::GoreLijevo;
		else if(naredbe.at(0)=="P1" && naredbe.at(1)=="G")
		smijer=Smjerovi::Gore;
		else if(naredbe.at(0)=="P1" && naredbe.at(1)=="D")
		smijer=Smjerovi::Desno;
		else if(naredbe.at(0)=="P1" && naredbe.at(1)=="DoD")
		smijer=Smjerovi::DoljeDesno;
		else if(naredbe.at(0)=="P1" && naredbe.at(1)=="DoL")
		smijer=Smjerovi::DoljeLijevo;
		else if(naredbe.at(0)=="P1" && naredbe.at(1)=="L")
		smijer=Smjerovi::Lijevo;
		else if(naredbe.at(0)=="P1" && naredbe.at(1)=="GD")
		smijer=Smjerovi::GoreDesno;
		else if(naredbe.at(0)=="P1" && naredbe.at(1)=="Do")
		smijer=Smjerovi::Dolje;
		
		return true;
	}
	
	
	if(naredbe.size()>2 && (naredbe.at(0)=="PO" || naredbe.at(0)=="Z" || naredbe.at(0)=="K") )
	{
		greska=KodoviGresaka::SuvisanParametar;
		return false;
	}
	if( naredbe.size()==1 && naredbe.at(0)!="PO" && naredbe.at(0)!="Z" &&  naredbe.at(0)!="K" )
	{
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	if( naredbe.size()==1 && naredbe.at(0)=="PO" )
	{
		komanda=Komande::PrikaziOkolinu;
		return true;
	}
	if( naredbe.size()==1 && naredbe.at(0)=="Z" )
	{
		komanda=Komande::ZavrsiIgru; 
		return true;
	}
	if( naredbe.size()==1 && naredbe.at(0)=="K" )
	{
		komanda=Komande::KreirajIgru; 
		return true;
	}
	
	int broj1(0), broj2(0);
	bool da(false);
	
	auto p1=naredbe.at(1).begin();
	
	if(naredbe.size()==2 )
		{
			if( (*p1-'0')>=0 && (*p1-'0')<=9 )
			{
				while((*p1-'0')>=0 && (*p1-'0')<=9)
				{
					broj1=(broj1*10)+(int(*p1)-'0');
					p1++;
					
					if(p1==naredbe.at(1).end())
					{
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
				}
				
			while(p1!=naredbe.at(1).end() && *p1==' ')
			p1++;
			
			if(p1==naredbe.at(1).end())
			{
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			
		}
		else
		{
		    greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		if( (*(p1)-'0')>=0 && (*(p1)-'0')<=9 )
		{
			while((*p1-'0')>=0 && (*p1-'0')<=9)
			{
				broj2=(broj2*10)+(int(*p1)-'0');
				
				p1++;
				
				if(p1==naredbe.at(1).end())
			    break;
			}
			
			if(p1!=naredbe.at(1).end() && *p1==' ')
			p1++;
			
			if(p1==naredbe.at(1).end() )
			{
				x=broj1;
				y=broj2;
				da=true;
			}
			else
			{
				greska=KodoviGresaka::SuvisanParametar;
				return false;	
			}
			
		}
		else
		{
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		
	}
	
	if( naredbe.size()==1 && (naredbe.at(0)=="P>" || naredbe.at(0)=="B" || naredbe.at(0)=="D")  )          
	{
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	}
	/*if( naredbe.size()>3 && (naredbe.at(0)=="P>" || naredbe.at(0)=="B" || naredbe.at(0)=="D") && ne_broj1 && ne_broj2 )          
	{
		greska=KodoviGresaka::SuvisanParametar;
		return false;
	}*/
	
	if(naredbe.size()==2 && (naredbe.at(0)=="P>" || naredbe.at(0)=="B" || naredbe.at(0)=="D") && !da)
	{
		greska=KodoviGresaka::NedostajeParametar;
		return false;
	}
	
	if( naredbe.size()==2 && naredbe.at(0)=="P>" && da )          
	{
		komanda=Komande::PomjeriDalje;

		return true;
	}
	if( naredbe.size()==2 && naredbe.at(0)=="D" && da )          
	{
		komanda=Komande::Deblokiraj;
		return true;
	}
	if( naredbe.size()==2 && naredbe.at(0)=="B" && da )          
	{
		komanda=Komande::Blokiraj;
		return true;
	}
}

void IzvrsiKomandu (Komande komanda, Tabla &podloga_igrice, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0)
{
	
	if(komanda==Komande::PomjeriJednoMjesto)
	{
		Status ne_kraj;
		ne_kraj=Idi(podloga_igrice, x, y, p_smjer);
		if(ne_kraj==Status::KrajPobjedna)
		std::cout<<"Bravo, obisli ste sva sigurna polja";
		else if(ne_kraj==Status::KrajPoraz)
		std::cout<<"Nagazili ste na minu";
		
		if(ne_kraj==Status::KrajPobjedna || ne_kraj==Status::KrajPoraz)
		{
			for(int i=0; i<podloga_igrice.size(); i++)
				for(int j=0; j<podloga_igrice.at(0).size(); j++)
					podloga_igrice.at(i).at(j)=Polje::Prazno;
			
			throw std::runtime_error("Igra Zavrsena");
		}
	}
	
	if(komanda==Komande::PomjeriDalje)
	{
		Status ne_kraj;
		ne_kraj=Idi(podloga_igrice, x, y, p_x, p_y);
		
		if(ne_kraj==Status::KrajPobjedna)
		std::cout<<"Bravo, obisli ste sva sigurna polja";
		else if(ne_kraj==Status::KrajPoraz)
		std::cout<<"Nagazili ste na minu";
		
		if(ne_kraj==Status::KrajPobjedna || ne_kraj==Status::KrajPoraz)
		{
			for(int i=0; i<podloga_igrice.size(); i++)
				for(int j=0; j<podloga_igrice.at(0).size(); j++)
					podloga_igrice.at(i).at(j)=Polje::Prazno;
			
			throw std::runtime_error("Igra Zavrsena");
		}
	}
	
	if(komanda==Komande::PomjeriJednoMjesto || komanda==Komande::PomjeriDalje)
	std::cout<<"Tekuca pozicija igraca je ("+std::to_string(x)+","+std::to_string(y)+")"<<std::endl;
	
	if(komanda==Komande::Blokiraj)
	{
		try
		{
			BlokirajPolje(podloga_igrice, p_x, p_y);
		}
		catch(std::domain_error poruka)
		{
			std::cout<<poruka.what()<<std::endl;
		}
	}
	
	if(komanda==Komande::Deblokiraj)
	{
		try
		{
			DeblokirajPolje(podloga_igrice, p_x, p_y);
		}
		catch(std::domain_error poruka)
		{
				std::cout<<poruka.what()<<std::endl;
		}
	}
	
	if(komanda==Komande::PrikaziOkolinu)
	{
		std::vector<std::vector<int>> okolina;
		okolina=PrikaziOkolinu( podloga_igrice, x, y);
		
		for(int i=0; i<okolina.size(); i++)
		{
			for(int j=0; j<okolina.at(i).size(); j++)
			{
				std::cout<<okolina.at(i).at(j)<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	if(komanda==Komande::ZavrsiIgru)
	{
		for(int i=0; i<podloga_igrice.size(); i++)
			for(int j=0; j<podloga_igrice.at(0).size(); j++)
				podloga_igrice.at(i).at(j)=Polje::Prazno;
		
		throw std::runtime_error("Igra Zavrsena");
	}
	
	if(komanda==Komande::KreirajIgru)
	{
		int broj_polja;
		std::cout<<"Unesite broj polja: ";
		while(!(std::cin>>broj_polja) || std::cin.peek()!='\n' || broj_polja<=0)
		{
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Unesite broj polja: ";
		}
	
		std::cout<<"Unesite pozicije mina: ";
		
		std::cin.ignore(1000, '\n');
		
		std::string koordinate;
		std::vector<std::vector<int>> poz_mine;
		
		
	
	bool da(false), preskoci(false);
	int i(0);

	do{
	    int broj1(0), broj2(0);
	    preskoci=false;
	    
		std::getline(std::cin, koordinate);
		
		if(koordinate.size()==1 && koordinate.at(0)=='.')
		break;
		
		if(koordinate.size()==0)
		{
		    std::cout<<"Greska, unesite ponovo!"<<std::endl;
			preskoci=true;
			continue;
		}
		
		auto p1=koordinate.begin();
		
		while(p1!=koordinate.end() && *p1==' ')
		p1++;
		
		if(p1==koordinate.end())
		{ 
			std::cout<<"Greska, unesite ponovo!"<<std::endl;
			preskoci=true;
			continue;
		}
		
		if(preskoci)
		continue; 
		
		if(*p1=='(')
		{
			p1++;
			
			while(p1!=koordinate.end() && *p1==' ')
			p1++;
				
		    if(p1==koordinate.end())
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				preskoci=true;
				continue;
			}
		
			if( (*p1-'0')>=0 && (*p1-'0')<=9 )
			{
				while((*p1-'0')>=0 && (*p1-'0')<=9)
				{
					broj1=(broj1*10)+(int(*p1)-'0');
					p1++;
					
					if(p1==koordinate.end())
					{
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						preskoci=true;
						break;
					}
				}
				
				if(preskoci)
				continue;
				
				while(p1!=koordinate.end() && *p1==' ')
				p1++;
				
				if(p1==koordinate.end())
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					preskoci=true;
					continue;
				}
				
				if(*p1!=',')
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					preskoci=true;
					continue;
				}
			}
			else
			{
			    std::cout<<"Greska, unesite ponovo!"<<std::endl;
			    preskoci=true;
				continue;
			}
			
			
			if( *p1==',' )
			{
				p1++;
				
				while(p1!=koordinate.end() && *p1==' ')
				p1++;
				
				if(p1==koordinate.end())
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					preskoci=true;
					continue;
				}
				
				while((*p1-'0')>=0 && (*p1-'0')<=9)
				{
					broj2=(broj2*10)+(int(*p1)-'0');
					
					p1++;
					
					if(p1==koordinate.end())
					{
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						preskoci=true;
						continue;
					}
					
				}
				
				if(preskoci)
				continue;
				
				while(p1!=koordinate.end() && *p1==' ')
				p1++;
				
				if(p1==koordinate.end())
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					continue;
				}
				
				if(*p1!=')')
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					continue;
				}
				
				if(*p1==')')
				{
				    p1++;
					while(p1!=koordinate.end() && *p1==' ')
					p1++;
					
					if(p1==koordinate.end() && broj1<broj_polja && broj2<broj_polja)
					{
						i++;
						poz_mine.resize(i);
						poz_mine.at(i-1).push_back(broj1);
						poz_mine.at(i-1).push_back(broj2);
						da=true;
					}
					else
					{
					    std::cout<<"Greska, unesite ponovo!"<<std::endl;
					    continue; 
					}
				}
				else
				{
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					continue;
				}
				
			}
			else
			{
				std::cout<<"Greska, unesite ponovo!"<<std::endl;
				continue;
			}
		}
		else
		{
		    std::cout<<"Greska, unesite ponovo!"<<std::endl;
			continue;
		}
		
		}while(true);
	
		podloga_igrice=KreirajIgru(broj_polja, poz_mine);
	}
}

int main ()
{
 int x_nula(0), y_nula(0), x(0), y(0);
	Tabla podloga_igrice (0, std::vector<Polje> (0));
	Komande komanda;
	KodoviGresaka greska;
	Smjerovi smjer;
	
	try{
		while(1)
		{
			
			std::cout<<"Unesite komandu: ";
			if( UnosKomande(komanda, smjer, x, y, greska))
			{
				try{
				IzvrsiKomandu(komanda, podloga_igrice, x_nula, y_nula, smjer, x, y);
				}
				catch(std::domain_error poruka1)
				{
					std::cout<<poruka1.what()<<std::endl;
				}
				catch(std::logic_error poruka2)
				{
					std::cout<<poruka2.what()<<std::endl;
				}
				catch(std::out_of_range poruka3)
				{
					std::cout<<poruka3.what()<<std::endl;
				}
				
			}
			else PrijaviGresku(greska);
		
		}
	}catch(...)
	{
		std::cout<<"Dovidjenja!";
	}

	return 0;
}