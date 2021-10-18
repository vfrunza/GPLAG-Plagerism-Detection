/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };


typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	for(int i=0 ; i<mine.size() ; i++)
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	
	for(int i=0; i<mine.size() ; i++){
		for(int j=0 ; j<mine[i].size() ; j++){
			if(mine[i][j]>=n || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	std::vector<std::vector<Polje>> t(n, std::vector<Polje>(n));
	for(int i=0 ; i<t.size() ; i++){
		for(int j=0 ; j<t[i].size() ; j++){
			t[i][j] = Polje(0);
		}
	}
		std::vector<int> temp;
		for(int i=0 ; i<mine.size() ; i++){
			temp = mine[i];
				for(int j=0 ; j<t.size() ; j++){
					for(int k=0 ; k<t[i].size() ; k++){
						if(j == temp[0] && k == temp[1]) t[j][k] = Polje(2);
					}
				}
		}
			return t;
}

int IzbrojiMine (int x, int y, const Tabla &polja){
	int br(0);
	for(int i=-1 ; i<2 ; i++){
		for(int j=-1; j<2 ; j++){
	if(x+i<0 || y+j<0 || x+i>=polja.size() | y+j>=polja.size()) continue;
	if(i==0 && j==0) continue;
	if(polja[x+i][y+j] == Polje(2)) br++;
}		
	}
	return br;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0) throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	
	std::vector<std::vector<int>> nova(3, std::vector<int>(3));
	for(int i=-1 ; i<2 ; i++){
		for(int j=-1; j<2 ; j++){
			if(x+i<0 || y+j<0 || x+i>=polja.size() | y+j>=polja.size()) continue;
			nova[i+1][j+1] = IzbrojiMine(x + i, y + j, polja);
			
	}
}
	return nova;
}

void BlokirajPolje (Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja.size()) throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
				if(polja[x][y]==Polje(0)) polja[i][j]=Polje(3);
				else if(polja[x][y] == Polje(2)) polja[x][y] = Polje(5);
				else if(polja[x][y] == Polje(1)) polja[x][y] = Polje(4);
			}
}

void DeblokirajPolje (Tabla &polja, int i, int j){
	if(x>=polja.size() || y>=polja.size()) throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
				if(polja[i][j] == Polje(3)) polja[i][j] = Polje(0);
				else if(polja[i][j] == Polje(4)) polja[i][j] = Polje(1);
				else if(polja[i][j] == Polje(5)) polja[i][j] = Polje(2);
}

Status Idi(Tabla &polja, int &i, int &j, Smjerovi smjer){

				if(smjer == GoreLijevo ) {
					if(i-1<polja.size() && i-1>=0 && j-1<polja.size() && j-1>=0) {
						if(polja[i-1][j-1]==Polje(3) || polja[i-1][j-1] == Polje(4) || polja[i-1][j-1]==Polje(5)) 
						throw std::logic_error("Blokirano polje");
						else{ i=i - 1; j = j-1; polja[i][j] = Polje(1);}
					} 
					else throw std::out_of_range("Izlazak van igrace table");
				}
				else if(smjer == Gore) { 
					if(i-1<polja.size() && i-1>=0 && j<polja.size() && j>=0) {
						if(polja[i-1][j]==Polje(3) || polja[i-1][j] =Polje(4) || polja[i-1][j]==Polje(5))	
						throw std::logic_error("Blokirano polje");
					    else{ x = i - 1; y = j; polja[i][j] = Polje(1);}
					}
					else throw std::out_of_range("Izlazak van igrace table");
				}
				else if(smjer == GoreDesno) {
					if(i-1<polja.size() && i-1>=0 && j+1<polja.size() && j+1>=0) {
						if(polja[i-1][j+1]==Polje(3) || polja[i-1][j+1] == Polje(4) || polja[i-1][j+1]==Polje(5))	
						throw std::logic_error("Blokirano polje");
						else {x = i-1; y = j+1; polja[i][j] = Polje(1);}
						
					}
					else throw std::out_of_range("Izlazak van igrace table");
				}
				else if(smjer = Desno) { 
					if(i<polja.size() && i>=0 && j+1<polja.size() && j+1>=0) {
						if(polja[i][j+1]==Polje(3)|| polja[i][j+1] == Polje(4) || polja[i][j+1]==Polje(5))
						throw std::logic_error("Blokirano polje");
						else{ x = i; y = j + 1; polja[i][j] = Polje(1);}
						
					}
					else throw std::out_of_range("Izlazak van igrace table");
						
				}
				else if( smjer == DoljeDesno) { 
					if(i+1<polja.size() && i+1>=0 && j+1<polja.size() && j+1>=0){
						if(polja[i+1][j+1]==Polje(3) || polja[i+1][j+1] 1== Polje(4) || polja[i+1][j+1]==Polje(5))
						throw std::logic_error("Blokirano polje");
						else {x = i + 1 ; y = j +1; polja[i][j] = Polje(1);}
						
					}
					else throw std::out_of_range("Izlazak van igrace table");
					
				}
				else if(smjer == Dolje) { 
					if(i+1<polja.size() && i+1>=0 && j<polja.size() && j>=0){ 
						if(polja[i+1][j]==Polje(3) || polja[i+1][j] == Polje(4) || polja[i+1][j]==Polje(5))
						throw std::logic_error("Blokirano polje");
						else{ x = i + 1; y = j; polja[i][j] = Polje(1);}
						
					}
					else throw std::out_of_range("Izlazak van igrace table");
					
				}
				else if(smjer == DoljeLijevo) { 
					if(i+1<polja.size() && i+1>=0 && j-1<polja.size() && j-1>=0){ 
						if(polja[i+1][j-1]==Polje(3) || polja[i+1][j-1] == Polje(4) || polja[i+1][j-1]==Polje(5))
						throw std::logic_error("Blokirano polje");
						else{ x = i + 1; y = j - 1; polja[i][j] = Polje(1);}
						
					}
					else throw std::out_of_range("Izlazak van igrace table");
					
				}
				else if(smjer == Lijevo) { 
					if(i<polja.size() && i>=0 && j-1<polja.size() && j-1>=0){
						if(polja[i][j-1]==Polje(3) || polja[i][j-1] == Polje(4) || polja[i][j-1]==Polje(5))
						throw std::logic_error("Blokirano polje");
						else {x = i ; y = j - 1; polja[i][j] = Polje(1);} 
						
					}
					else throw std::out_of_range("Izlazak van igrace table");

	
}
		if(polja[i][j] == Polje(2)){
			for(int i=0 ; i<polja.size() ; i++){
				for(int j=0 ; j<polja[i].size() ; j++){
					polja[i][j] = Polje(0);
				}
			}
				return Status(1);
		}
			int br(0);
			for(int i=0 ; i<polja.size() ; i++){
				for(int j=0 ; j<polja[i].size() ; j++)
					if(polja[i][j]!=Polje(0)) br++;
			}
				if(br == polja.size()*polja.size()) return KrajPobjeda;
				return NijeKraj;
}
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x>=polja.size() || novi_y>=polja.size() || novi_x<0 || novi_y<0 ) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje(3) || polja[novi_x][novi_y] == Polje(4) || polja[novi_x][novi_y]==Polje(5))
	throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje(1);
	x = novi_x;
	y = novi_y;
	
	if(polja[novi_x][novi_y] == Polje(2)){
			for(int i=0 ; i<polja.size() ; i++){
				for(int j=0 ; j<polja[i].size() ; j++){
					polja[i][j] = Polje(0);
				}
			}
				return KrajPoraz;
		}
			int br(0);
			for(int i=0 ; i<polja.size() ; i++){
				for(int j=0 ; j<polja[i].size() ; j++)
					if(polja[i][j]!=Polje(0)) br++;
			}
				if(br == polja.size()*polja.size()) return KrajPobjeda;
				return NijeKraj;
	}
	
bool JesuLiIsti(std::string kom, std::string s){
	for(int i=0 ; i<kom.size() ; i++){
		while(kom[i] == ' ') i++;
		while(kom[i] == s[k++]) br++;
	}
	if(br == s.length()) return true;
	return false;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string kom;
	int a, b;
	std::cin>>kom;
	if(JesuLiIsti(kom, 'K')){ komanda = Komande(6); return true; }
	if(JesuLiIsti(kom, 'Z')) { komanda = Komande(5); return true; }
	if(JesuLiIsti(kom, 'PO')) { komanda = Komande(4); return true; }
	if(JesuLiIsti(kom, 'B')){
		std::cin>>a;
		std::cin>>b;
		komanda = Komande(2);
		x = a;
		y = b;
		return true ;
	}
}
	
int main ()
{
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}