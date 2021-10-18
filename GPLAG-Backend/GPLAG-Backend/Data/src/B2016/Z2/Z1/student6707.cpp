/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <vector>
#include <iostream>
#include <stdexcept>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	int provjera=0;
	for(int i=0; i<mine.size(); i++)
		{
			if(mine[i].size()!= 2) provjera=1;
		}
	
	if( provjera==1) throw std::domain_error("Ilegalan format zadavanja mina");
	provjera=0;
	for(int i=0; i<mine.size(); i++)
	{
		for(int j=0; j<mine[i].size(); j++)
		
		{
			if(mine[i][j]<0 || mine[i][j]>=n) provjera=1;	
		}
	}
	if(provjera==1) throw std::domain_error("Ilegalne pozicije mina");
	 
	Tabla a;
	a.resize(n);
	for(int i=0; i<n; i++) a[i].resize(n);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			a[i][j]=Polje::Prazno;
	
	for(int i=0; i<mine.size(); i++)
		a[mine[i][0]][mine[i][1]] =  Polje::Mina;
	
	return a;	
} 
void IspisiMatricu(Tabla matrica)
{
	for(int i=0; i<matrica.size(); i++)
	{
		for(int j=0; j<matrica[0].size(); j++)
		{
			std::cout<<" "<<int(matrica[i][j]);
		}
		std::cout<<std::endl;
	}
}

void IspisiMatricu2(std::vector<std::vector<int>> matrica)
{
	for(int i=0; i<matrica.size(); i++)
	{
		for(int j=0; j<matrica[0].size(); j++)
		{
			std::cout<<" "<<matrica[i][j];
		}
		std::cout<<std::endl;
	}
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	std::vector<std::vector<int>> matrica(3, std::vector<int>(3));
	
	int brojac=0;
	
	int a=polja.size();
	if(x<0 || y<0 || x>=a || y>=a ) throw std::domain_error("Polje (x,y) ne postoji");
	
	if(int(polja[x][y])==2) brojac++;
	 if((x-1)>=0 && (x-1)<a && int(polja[x-1][y])==2) brojac++;
	if((x-2)>=0 && (x-2)<a && int(polja[x-2][y])==2) brojac++;
	if((y-1)>=0 && (y-1)<a && int(polja[x][y-1])==2) brojac++;
	if((y-2)>=0 && (y-2)<a && int(polja[x][y-2])==2) brojac++;
	 if((y-1)>=0 && (x-2)>=0 && (x-2)<a && (y-1)<a && int(polja[x-2][y-1])==2) brojac++;
	 if((y-2)>=0 && (x-2)>=0 && (x-2)<a && (y-2)<a && int(polja[x-2][y-2])==2) brojac++;
	 if((y-2)>=0 && (x-1)>=0 && (x-1)<a && (y-2)<a && int(polja[x-1][y-2])==2) brojac++;
	
	matrica[0][0]=brojac;
	brojac=0;
	
	if(int(polja[x][y])==2) brojac++;
if((x-2)>=0 && (x-2)<a && int(polja[x-2][y])==2) brojac++;
	if((y-1)>=0 && (x-2)>=0 && (x-2)<a && (y-1)<a && int(polja[x-2][y-1])==2) brojac++;
	if((y-1)>=0 && (x-1)>=0 && (x-1)<a && (y-1)<a && int(polja[x-1][y-1])==2) brojac++;
	if((y-1)>=0 && (y-1)<a && int(polja[x][y-1])==2) brojac++;
	if((y+1)>=0 && (x-2)>=0 && (x-2)<a && (y+1)<a && int(polja[x-2][y+1])==2) brojac++;
	if((y+1)>=0 && (y+1)<a && int(polja[x][y+1])==2) brojac++;
	if((y+1)>=0 && (x-1)>=0 && (x-1)<a && (y+1)<a && int(polja[x-1][y+1])==2) brojac++;
	
	matrica[0][1]=brojac;
	brojac=0;
	
	if(int(polja[x][y])==2) brojac++;
	if((x-1)>=0 && (x-1)<a && int(polja[x-1][y])==2) brojac++;
	if((x-2)>=0 && (x-2)<a && int(polja[x-2][y])==2) brojac++;
	if((y+1)>=0 && (y+1)<a && int(polja[x][y+1])==2) brojac++;
	if((y+2)>=0 && (y+2)<a && int(polja[x][y+2])==2) brojac++;
	if((y+2)>=0 && (x-1)>=0 && (x-1)<a && (y+2)<a && int(polja[x-1][y+2])==2) brojac++;
	if((y+2)>=0 && (x-2)>=0 && (x-2)<a && (y+2)<a && int(polja[x-2][y+2])==2) brojac++;
	if((y+1)>=0 && (x-2)>=0 && (x-2)<a && (y+1)<a && int(polja[x-2][y+1])==2) brojac++;
	
	matrica[0][2]=brojac;
	brojac=0;
	if(int(polja[x][y])==2) brojac++;
	if((x-1)>=0 && (x-1)<a && int(polja[x-1][y])==2) brojac++;	
	if((x+1)>=0 && (x+1)<a && int(polja[x+1][y])==2) brojac++;
	if((y-1)>=0 && (x-1)>=0 && (x-1)<a && (y-1)<a && int(polja[x-1][y-1])==2) brojac++;
	if((y-2)>=0 && (x-1)>=0 && (x-1)<a && (y-2)<a && int(polja[x-1][y-2])==2) brojac++;
	if((y-2)>=0 && (y-2)<a && int(polja[x][y-2])==2) brojac++;
	if((y-2)>=0 && (x+1)>=0 && (x+1)<a && (y-2)<a && int(polja[x+1][y-2])==2) brojac++;
	if((y-1)>=0 && (x+1)>=0 && (x+1)<a && (y-1)<a && int(polja[x+1][y-1])==2) brojac++;
	
	matrica[1][0]=brojac;
	brojac=0;
	
	if((x+1)>=0 && (x+1)<a && int(polja[x+1][y])==2) brojac++;
	if((y+1)>=0 && (x+1)>=0 && (x+1)<a && (y+1)<a && int(polja[x+1][y+1])==2) brojac++;
	if((y-1)>=0 && (x+1)>=0 && (x+1)<a && (y-1)<a && int(polja[x+1][y-1])==2) brojac++;
	if((y-1)>=0 && (y-1)<a && int(polja[x][y-1])==2) brojac++;
	if((y+1)>=0 && (y+1)<a && int(polja[x][y+1])==2) brojac++;
	if((x-1)>=0 && (x-1)<a && int(polja[x-1][y])==2) brojac++;
	if((y-1)>=0 && (x-1)>=0 && (x-1)<a && (y-1)<a && int(polja[x-1][y-1])==2) brojac++;
	if((y+1)>=0 && (x-1)>=0 && (x-1)<a && (y+1)<a && int(polja[x-1][y+1])==2) brojac++;
	
	matrica[1][1]=brojac;
	brojac=0;
	
	if(int(polja[x][y])==2) brojac++;
	if((x+1)>=0 && (x+1)<a && int(polja[x+1][y])==2) brojac++;
	if((x-1)>=0 && (x-1)<a && int(polja[x-1][y])==2) brojac++;
	if((y+1)>=0 && (x-1)>=0 && (x-1)<a && (y+1)<a && int(polja[x-1][y+1])==2) brojac++;
	if((y+2)>=0 && (x-1)>=0 && (x-1)<a && (y+2)<a && int(polja[x-1][y+2])==2) brojac++;
	if((y+2)>=0 && (y+2)<a && int(polja[x][y+2])==2) brojac++;
	if((y+1)>=0 && (x+1)>=0 && (x+1)<a && (y+1)<a && int(polja[x+1][y+1])==2) brojac++;
	if((y+2)>=0 && (x+1)>=0 && (x+1)<a && (y+2)<a && int(polja[x+1][y+2])==2) brojac++;
	
	matrica[1][2]=brojac;
	brojac=0;
	
	if(int(polja[x][y])==2) brojac++;
	if((x+1)>=0 && (x+1)<a && int(polja[x+1][y])==2) brojac++;
	if((x+2)>=0 && (x+2)<a && int(polja[x+2][y])==2) brojac++;
	if((y-1)>=0 && (x+2)>=0 && (x+2)<a && (y-1)<a && int(polja[x+2][y-1])==2) brojac++;
	if((y-2)>=0 && (x+2)>=0 && (x+2)<a && (y-2)<a && int(polja[x+2][y-2])==2) brojac++;	
	if((y-2)>=0 && (x+1)>=0 && (x+1)<a && (y-2)<a && int(polja[x+1][y-2])==2) brojac++;	
	if((y-2)>=0 && (y-2)<a && int(polja[x][y-2])==2) brojac++;
	if((y-1)>=0 && (y-1)<a && int(polja[x][y-1])==2) brojac++;
	
	matrica[2][0]=brojac;
	brojac=0;
	
	if(int(polja[x][y])==2) brojac++;
	if((y+1)>=0 && (y+1)<a && int(polja[x][y+1])==2) brojac++;
	if((y-1)>=0 && (y-1)<a && int(polja[x][y-1])==2) brojac++;
	if((y-1)>=0 && (x+1)>=0 && (x+1)<a && (y-1)<a && int(polja[x+1][y-1])==2) brojac++;
	if((y+1)>=0 && (x+1)>=0 && (x+1)<a && (y+1)<a && int(polja[x+1][y+1])==2) brojac++;
	if((y-1)>=0 && (x+2)>=0 && (x+2)<a && (y-1)<a && int(polja[x+2][y-1])==2) brojac++;
	if((y+1)>=0 && (x+2)>=0 && (x+2)<a && (y+1)<a && int(polja[x+2][y+1])==2) brojac++;
	if((x+2)>=0 && (x+2)<a && int(polja[x+2][y])==2) brojac++;
	
	matrica[2][1]=brojac;
	brojac=0;
	
	if(int(polja[x][y])==2) brojac++;
	if((y+1)>=0 && (y+1)<a && int(polja[x][y+1])==2) brojac++;
	if((y+2)>=0 && (y+2)<a && int(polja[x][y+2])==2) brojac++;
	if((x+1)>=0 && (x+1)<a && int(polja[x+1][y])==2) brojac++;
	if((y+2)>=0 && (x+1)>=0 && (x+1)<a && (y+2)<a && int(polja[x+1][y+2])==2) brojac++;
	if((x+2)>=0 && (x+2)<a && int(polja[x+2][y])==2) brojac++;
	if((y+2)>=0 && (x+2)>=0 && (x+2)<a && (y+2)<a && int(polja[x+2][y+2])==2) brojac++;
	if((y+1)>=0 && (x+2)>=0 && (x+2)<a && (y+1)<a && int(polja[x+2][y+1])==2) brojac++;
	
	matrica[2][2]=brojac;
	brojac=0;

	return matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	
	else if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if (polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	
}

void DeblokirajPolje(Tabla &polja, int x, int y)

{
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	
	else if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if (polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}
	

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	Status vracamo;
	
	if( x==0 && y==0 && ( int(smjer)==0 || int(smjer)==7 || int(smjer)==1 || int(smjer)==2 || int(smjer)==6)) throw std::out_of_range("Izlazak van igrace table");
	else if( x==0 && y==polja.size()-1 && (int(smjer)==1 || int(smjer)==0 || int(smjer)==2 || int(smjer)==3 || int(smjer)==4)) throw std::out_of_range("Izlazak van igrace table");
	else if(y==0 && x==polja.size()-1 && (int(smjer)==0  || int(smjer)==7  || int (smjer)==6  || int(smjer)==5 || int(smjer)==4)) throw std::out_of_range("Izlatak van igrace table");
	else if(y==polja.size()-1 && x==polja.size()-1 && (int(smjer)==2  || int(smjer)==3  || int (smjer)==4  || int(smjer)==5 || int(smjer)==6)) throw std::out_of_range("Izlatak van igrace table");
	
	else if(x==polja.size()-1 && ( int(smjer)==6 || int(smjer)==5 || int(smjer)==4 ))  throw std::out_of_range("Izlatak van igrace table");
	else if(x==0 && ( int(smjer)==0 || int(smjer)==1 || int(smjer)==2 ))  throw std::out_of_range("Izlatak van igrace table");
	else if(y==0 && ( int(smjer)==6 || int(smjer)==7 || int(smjer)==0 ))  throw std::out_of_range("Izlatak van igrace table");
	else if(y==polja.size()-1 && ( int(smjer)==3 || int(smjer)==2 || int(smjer)==4 ))  throw std::out_of_range("Izlatak van igrace table");
	
	else if(int(smjer)==0 && (polja[x-1][y-1]==Polje::BlokiranoMina || polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	else if(int(smjer)==1 && (polja[x-1][y]==Polje::BlokiranoMina || polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	else if(int(smjer)==2 && (polja[x-1][y+1]==Polje::BlokiranoMina || polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	else if(int(smjer)==7 && (polja[x][y-1]==Polje::BlokiranoMina || polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	else if(int(smjer)==3 && (polja[x][y+1]==Polje::BlokiranoMina || polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	else if(int(smjer)==6 && (polja[x+1][y-1]==Polje::BlokiranoMina || polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	else if(int(smjer)==5 && (polja[x+1][y]==Polje::BlokiranoMina || polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	else if(int(smjer)==4 && (polja[x+1][y+1]==Polje::BlokiranoMina || polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno)) throw std::logic_error ("Blokirano polje");
	
	polja[x][y]=Polje::Posjeceno;
	if(int(smjer)==0) { x=x-1; y=y-1;}
	else if(int(smjer)==1) { x=x-1; }
	else if(int(smjer)==2) { x=x-1; y=y+1; }
	else if(int(smjer)==3) { y=y+1; }
	else if(int(smjer)==4) { x=x+1; y= y+1; }
	else if(int(smjer)==5) { x=x+1; }
	else if(int(smjer)==6) { x=x+1; y=y-1; }
	else if(int(smjer)==7) { y=y-1; }
	
	int prov=0;
	for(int i=0; i<polja.size(); i++)
	  {
	  	for(int j=0; j<polja[0].size(); j++)
	  	{
	  		if(i!=x && j!=y && polja[i][j]==Polje::Prazno ) prov=1;
	  	}
	  }
	  
	
	if(polja[x][y]==Polje::Mina) vracamo=Status::KrajPoraz;
	else if(prov==0 ) vracamo =Status::KrajPobjeda;
	else vracamo=Status::NijeKraj;
	
	
	if(vracamo==Status::KrajPoraz)
	{
		for(int i=0; i<polja.size(); i++)
	  {
	  	for(int j=0; j<polja[0].size(); j++)
	  	{
	  		polja[i][j]=Polje::Prazno;
	  	}
	  }
	}
	return vracamo;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	Status vracamo;
	
	if(novi_x<0 || novi_y<0 || novi_x>polja.size()-1 || novi_y>polja.size()-1) throw std::out_of_range("Izlazak van igrace table");
	
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]== Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	
	polja[x][y]= Polje::Posjeceno;

	
	int prov=0;
	for(int i=0; i<polja.size(); i++)
	  {
	  	for(int j=0; j<polja[0].size(); j++)
	  	{
	  		if(i!=x && j!=y && polja[i][j]==Polje::Prazno ) prov=1;
	  	}
	  }
	  
	 x=novi_x;
	y=novi_y;
	
	if(polja[x][y]==Polje::Mina) vracamo=Status::KrajPoraz;
	else if(prov==0 ) vracamo =Status::KrajPobjeda;
	else vracamo=Status::NijeKraj;
	
	
	if(vracamo==Status::KrajPoraz)
	{
		for(int i=0; i<polja.size(); i++)
	  {
	  	for(int j=0; j<polja[0].size(); j++)
	  	{
	  		polja[i][j]=Polje::Prazno;
	  	}
	  }
	}
	return vracamo;
	
}

void PrijaviGresku( KodoviGresaka kod)
{
	if(kod==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
	else if(kod==KodoviGresaka::NedostajeParmetar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	else if(kod==KodoviGresaka::NeispravanParametar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	else if(kod==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!";

}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);


int main ()
{
	Tabla ploca;
	int n;
	 std::cout<<"Unesite broj n: ";
	 std::cin>>n;
	 std::vector<std::vector<int>> mine={{0,1}, {1,3}, {2,0}, {2,1}, {2,3}};
	try{
	 ploca=KreirajIgru(n, mine);
	 std::cout<<"Matrica izgleda: "<<std::endl;
	 IspisiMatricu(ploca);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	
	try{
	std::vector<std::vector<int>> matrica=PrikaziOkolinu(ploca, 1,1);
	IspisiMatricu2(matrica);
	}
	catch(std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what()<<std::endl;
	}
	 
	return 0;
}