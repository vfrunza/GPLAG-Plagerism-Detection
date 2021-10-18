#include<iostream>
#include<vector>
#include<stdexcept>
#include<cmath>
#include<string>
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru, KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

void PrijaviGresku(KodoviGresaka input){
	if(input==KodoviGresaka(0))std::cout<<"Nerazumljiva komanda! ";
	else if(input==KodoviGresaka(1))std::cout<<"Komanda trazi parametar koji nije naveden! ";
    else if(input==KodoviGresaka(2))std::cout<<"Parametar komande nije ispravan! ";
    else if(input==KodoviGresaka(3))std::cout<<"Zadan je suvisan parametar nakon komande!";

}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2)
		throw std::domain_error("Ilegalne pozicije mina");
	}
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<mine[i].size();j++){
			if(mine[i][j]<0||mine[i][j]>=n){
				throw std::domain_error("Ilegalne pozicije mina");
			}
		}
	}
	Tabla m(n,std::vector<Polje>(n,Polje(0)));
	for(int i=0;i<mine.size();i++){
		m[mine[i][0]][mine[i][1]]=Polje(2);
	}
	return m;
} 


Matrica PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::string warning("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(x>=polja.size()||x<0||y>=polja[0].size()||y<0)
	throw std::domain_error(warning);
	Tabla pomocna(polja.size()+6,std::vector<Polje>(polja[0].size()+6,Polje(3)));
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[0].size();j++){
			pomocna[i+3][j+3]=polja[i][j];
		}
	}
	Matrica mine(3,std::vector<int>(3));
	int brojmina(0),brojac1(0),brojac2(0);
	for(int i=x+3-1;i<x+5;i++){
		for(int j=y+3-1;j<y+5;j++){
			brojmina=0;
			for(int k=0;k<pomocna.size();k++){
				for(int s=0;s<pomocna[k].size();s++){
					if(((abs(k-i)==1&&abs(s-j)==1)||(abs(k-i)==0&&abs(s-j)==1)||(abs(k-i)==1&&abs(s-j)==0))&&pomocna[k][s]==Polje(2)&&pomocna[k][s]!=Polje(3)){
						brojmina++;
					}
				}
			}
			mine[brojac1][brojac2]=brojmina;
			brojac2++;
		}
		brojac1++;
		brojac2=0;
	}
		return mine;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	std::string warning("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(x<0||x>=polja.size()||y<0||y>=polja[0].size())
	throw std::domain_error(warning);
	if(polja[x][y]==Polje(3)||polja[x][y]==Polje(4)||polja[x][y]==Polje(5))
	exit(0);
	else{
	if(polja[x][y]==Polje(0))
	polja[x][y]=Polje(3);
	if(polja[x][y]==Polje(1))
	polja[x][y]=Polje(4);
	if(polja[x][y]==Polje(2))
	polja[x][y]=Polje(5);}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	std::string warning("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(x<0||x>=polja.size()||y<0||y>=polja[0].size())
	throw std::domain_error(warning);
	if(polja[x][y]==Polje(0)||polja[x][y]==Polje(1)||polja[x][y]==Polje(2))
	exit(0);
	else{
	if(polja[x][y]==Polje(3))
	polja[x][y]=Polje(0);
	if(polja[x][y]==Polje(4))
	polja[x][y]=Polje(1);
	if(polja[x][y]==Polje(5))
	polja[x][y]=Polje(2);}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if(smjer==Smjerovi(0)&&x-1>=0&&y-1>=0&&(polja[x-1][y-1]!=Polje(3)&&polja[x-1][y-1]!=Polje(4)&&polja[x-1][y-1]!=Polje(5))){
		polja[x][y]=Polje(1);
		x=x-1;y=y-1;
	}
	else if(smjer==Smjerovi(0)&&(x-1<0||y-1<0))
	throw std::out_of_range("Izlazak van igrace table");
	
	else if(smjer==Smjerovi(1)&&x-1>=0&&(polja[x-1][y]!=Polje(3)&&polja[x-1][y]!=Polje(4)&&polja[x-1][y]!=Polje(5))){
		polja[x][y]=Polje(1);
		x=x-1;
	}
	else if(smjer==Smjerovi(1)&&x-1<0)
	throw std::out_of_range("Izlazak van igrace table");
	
	else if(smjer==Smjerovi(2)&&x-1>=0&&y+1<polja[0].size()&&(polja[x-1][y+1]!=Polje(3)&&polja[x-1][y+1]!=Polje(4)&&polja[x-1][y+1]!=Polje(5))){
		polja[x][y]=Polje(1);
		x=x-1;y=y+1;
	}
	else if(smjer==Smjerovi(2)&&(x-1<0||y+1>=polja[0].size()))
	throw std::out_of_range("Izlazak van igrace table");
	
	else if(smjer==Smjerovi(3)&&y+1<polja[0].size()&&(polja[x][y+1]!=Polje(3)&&polja[x][y+1]!=Polje(4)&&polja[x][y+1]!=Polje(5))){
		polja[x][y]=Polje(1);
		y=y+1;
	}
	else if(smjer==Smjerovi(3)&&y+1>=polja[0].size())
	throw std::out_of_range("Izlazak van igrace table");
	
	else if(smjer==Smjerovi(4)&&x+1<polja.size()&&y+1<polja[0].size()&&(polja[x+1][y+1]!=Polje(3)&&polja[x+1][y+1]!=Polje(4)&&polja[x+1][y+1]!=Polje(5))){
		polja[x][y]=Polje(1);
		y=y+1;x=x+1;
	}
	else if(smjer==Smjerovi(4)&&(x-1>=polja.size()||y+1>=polja[0].size()))
	throw std::out_of_range("Izlazak van igrace table");
	
	else if(smjer==Smjerovi(5)&&x+1<polja.size()&&(polja[x+1][y]!=Polje(3)&&polja[x+1][y]!=Polje(4)&&polja[x+1][y]!=Polje(5))){
		polja[x][y]=Polje(1);
		x=x+1;
	}
	else if(smjer==Smjerovi(5)&&x-1>=polja.size())
	throw std::out_of_range("Izlazak van igrace table");
	
	else if(smjer==Smjerovi(6)&&x+1<polja.size()&&y-1>=0&&(polja[x+1][y-1]!=Polje(3)&&polja[x+1][y-1]!=Polje(4)&&polja[x+1][y-1]!=Polje(5))){
		polja[x][y]=Polje(1);
		x=x+1;y=y-1;
	}
	else if(smjer==Smjerovi(6)&&(x-1>=polja.size()||y-1<0))
	throw std::out_of_range("Izlazak van igrace table");
	
	else if(smjer==Smjerovi(7)&&(y-1>=0)&&(polja[x][y-1]!=Polje(3)&&polja[x][y-1]!=Polje(4)&&polja[x][y-1]!=Polje(5))){
		polja[x][y]=Polje(1);
		y=y-1;
	}
	else if(smjer==Smjerovi(7)&&(x-1>=polja.size()||y-1<0))
	throw std::out_of_range("Izlazak van igrace table");
	
	else 
	throw std::logic_error("Blokirano polje");
	int logicka=1;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[0].size();j++){
			if(polja[i][j]==Polje(0)){
			logicka=0;
			break;}
		}
		if(!logicka)break;
	}
	if(polja[x][y]==Polje(2))
	return Status(1);
	else if(logicka)return Status(2);
	else
	return Status(0);
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0||novi_x>=polja.size()||novi_y<0||novi_y>=polja[0].size())
	throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje(3)||polja[novi_x][novi_y]==Polje(4)||polja[novi_x][novi_y]==Polje(5))
	throw std::logic_error("Blokirano polje");
	int a(x);
	int b(y);
	polja[x][y]=Polje(1);
        if(novi_x-a<0){
		for(int i=0;i<abs(novi_x-a);i++)
		x--;
	}
        else{
		for(int i=0;i<abs(novi_x-a);i++)
		x++;}
	
		if(novi_y-b<0){
		for(int i=0;i<abs(novi_y-b);i++)
		y++;
	}
        else{
		for(int i=0;i<abs(novi_y-b);i++)
		y++;
	}

int logicka=1;
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[0].size();j++){
			if(polja[i][j]==Polje(0)){
			logicka=0;
			break;}
		}
		if(!logicka)break;
	}
	if(polja[x][y]==Polje(2))
	return Status(1);
	else if(logicka)return Status(2);
	else
	return Status(0);


}


int main ()
{
/*	Matrica m;
	m=PrikaziOkolinu(KreirajIgru(5, {{0,1}, {0,4},{1,3},{1,4},{2,0},{2,1},{2,3}}),1,1);
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[0].size();j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<"\n";
	}
std::vector<std::vector<int>> mine = {{0,2}, {1,3}, {1,5}, {4,2}, {5,1}, {5,5}} ;
std::vector<std::vector<Polje>> tabla = KreirajIgru(6, mine);
 int x = 2, y = 0;
 Idi(tabla, x, y, 4, 5);
 std::cout << x << " " << y << std::endl;
 Idi(tabla, x, y, 5, 5);
 std::cout << x << " " << y << std::endl;*/
    //AT13 (zamger) - funkcija idi sa 4 parametra izuzeci 
    int x = 0, y = 0;
    std::vector<std::vector<int>> mine = {{0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};
    std::vector<std::vector<Polje>> tabla = KreirajIgru(3, mine);
   try{
     Idi(tabla, x, y, Smjerovi::Lijevo);
   }
   catch(std::out_of_range e){
     std::cout << e.what() << std::endl;
   }
   BlokirajPolje(tabla, 0, 1);
   try{
     Idi(tabla, x, y, Smjerovi::Desno);
   }
   catch(std::logic_error e){
     std::cout << e.what() << std::endl;
   }
	return 0;
}