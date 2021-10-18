/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef std::vector<std::vector<Polje>> Tabla;

enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska);
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0);

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	std::vector<std::vector<Polje>> ploha(n, std::vector<Polje>(n, Polje::Prazno));
	for(int i=0; i<ploha.size(); i++){
		for(int j=0; j<ploha[0].size(); j++){
			for(int k=0; k<mine.size(); k++){
				if(mine[k].size()!=2)
					throw std::domain_error("Ilegalan format zadavanja mina");
					// naredna linija ili > ili >= (zadnja izmjena, ako bude padalo vise od 12at izbrisati =)
				else if(mine[k][0]<0 || mine[k][0]>=ploha[0].size() || mine[k][1]<0 || mine[k][1]>=ploha[0].size())	
					throw std::domain_error("Ilegalne pozicije mina");
				else if(i==mine[k][0] && j==mine[k][1])
					ploha[i][j]=Polje::Mina;
			}
		}
	}
	return ploha;
} //odradzeno

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> matrica(3, std::vector<int>(3));
	int brojac(0);
	for(int i=0; i<x+2; i++){
		for(int j=0; j<y+2; j++){
			if(i==x-1 && j==y-1){
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x-1 && j==y+1){
				if(j>0 && polja[i][j-1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j>0 && polja[i+1][j-1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x-1 && j==y){
				if(j>0 && polja[i][j-1]==Polje::Mina)
					brojac++;
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j>0 && polja[i+1][j-1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x && j==y-1){
				if(i>0 && polja[i-1][j]==Polje::Mina)
					brojac++;
				if(i>0 && j<polja[0].size() && polja[i-1][j+1]==Polje::Mina)
					brojac++;
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x && j==y){
				if(i>0 && j>0 && polja[i-1][j-1]==Polje::Mina)
					brojac++;
				if(i>0 && polja[i-1][j]==Polje::Mina)
					brojac++;
				if(i>0 && j<polja[0].size() && polja[i-1][j+1]==Polje::Mina)
					brojac++;
				if(j>0 && polja[i][j-1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j-1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x && j==y+1){
				if(i>0 && j>0 && polja[i-1][j-1]==Polje::Mina)
					brojac++;
				if(i>0 && polja[i-1][j]==Polje::Mina)
					brojac++;
				if(j>0 && polja[i][j-1]==Polje::Mina)
					brojac++;
				if(j>0 && i<polja.size() && polja[i+1][j-1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				if(i>0 && j<polja[0].size() && polja[i-1][j+1]==Polje::Mina)
					brojac++;
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x+1 && j==y-1){
				if(i>0 && polja[i-1][j]==Polje::Mina)
					brojac++;
				if(i>0 && j<polja[0].size() && polja[i-1][j+1]==Polje::Mina)
					brojac++;
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j>0 && polja[i+1][j-1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x+1 && j==y){
				if(i>0 && j>0 && polja[i-1][j-1]==Polje::Mina)
					brojac++;
				if(i>0 && polja[i-1][j]==Polje::Mina)
					brojac++;
				if(i>0 && j<polja[0].size() && polja[i-1][j+1]==Polje::Mina)
					brojac++;
				if(j>0 && polja[i][j-1]==Polje::Mina)
					brojac++;
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else if(i==x+1 && j==y+1){
				if(i>0 && j>0 && polja[i-1][j-1]==Polje::Mina)
					brojac++;
				if(i>0 && polja[i-1][j]==Polje::Mina)
					brojac++;
				if(j>0 && polja[i][j-1]==Polje::Mina)
					brojac++;
				if(i>0 && j<polja[0].size() && polja[i-1][j+1]==Polje::Mina)
					brojac++;
				if(j<polja[0].size() && polja[i][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && j<polja[0].size() && polja[i+1][j+1]==Polje::Mina)
					brojac++;
				if(i<polja.size() && polja[i+1][j]==Polje::Mina)
					brojac++;
				matrica[i][j]=brojac;
				brojac=0;
			}
			else{
				throw std::domain_error("Polje ("+ std::to_string(x) +","+ std::to_string(y)+") ne postoji");
			}
		}
	}
	return matrica;
} //zavrseno

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0)
		throw std::domain_error("Polje ("+ std::to_string(x) +","+ std::to_string(y)+") ne postoji");
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[0].size(); j++){
			if(i==x && j==y){
				if(polja[i][j]==Polje::Prazno)
					polja[i][j]=Polje::BlokiranoPrazno;
				else if(polja[i][j]==Polje::Posjeceno)
					polja[i][j]=Polje::BlokiranoPosjeceno;
				else if(polja[i][j]==Polje::Mina)
					polja[i][j]=Polje::BlokiranoMina;
			}
		}
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0)
		throw std::domain_error("Polje ("+ std::to_string(x) +","+ std::to_string(y)+") ne postoji");
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[0].size(); j++){
			if(i==x && j==y){
				if(polja[i][j]==Polje::BlokiranoPrazno)
					polja[i][j]=Polje::Prazno;
				else if(polja[i][j]==Polje::BlokiranoPosjeceno)
					polja[i][j]=Polje::Posjeceno;
				else if(polja[i][j]==Polje::BlokiranoMina)
					polja[i][j]=Polje::Mina;
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if(smjer==Smjerovi::GoreLijevo){
		if(x-1<0 || y-1<0)
			throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x-=1;
		y-=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	else if(smjer==Smjerovi::Gore){
		if(x-1<0)
			throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x-=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	else if(smjer==Smjerovi::GoreDesno){
		if(x-1<0 || y+1>=polja[0].size())
			throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x-=1;
		y+=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	else if(smjer==Smjerovi::Desno){
		if(y+1>=polja[0].size())
			throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		y+=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	else if(smjer==Smjerovi::DoljeDesno){
		if(x+1>=polja.size() || y+1>=polja[0].size())
			throw std::out_of_range("Izlazak van igrace table");
		else if(x+1<polja.size() && y+1<polja[0].size() && (polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina))
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x+=1;
		y+=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	else if(smjer==Smjerovi::Dolje){
		if(x+1>=polja.size())
			throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x+=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	else if(smjer==Smjerovi::DoljeLijevo){
		if(x+1>=polja.size() || y-1<0)
			throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		x+=1;
		y-=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	else if(smjer==Smjerovi::Lijevo){
		if(y-1<0)
			throw std::out_of_range("Izlazak van igrace table");
		else if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
		polja[x][y]=Polje::Posjeceno;
		y-=1;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	return Status::KrajPoraz; 
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x>=polja.size() || novi_y>=polja[0].size())
		throw std::out_of_range("Izlazak van igrace table");
	else if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
	else{
		x=novi_x;
		y=novi_y;
		if(polja[x][y]==Polje::Mina){
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					polja[i][j]=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		else if(polja[x][y]==Polje::Prazno){
			polja[x][y]=Polje::Posjeceno;
			for(int i=0; i<polja.size(); i++){
				for(int j=0; j<polja[0].size(); j++){
					if(polja[i][j]==Polje::Prazno)
						return Status::NijeKraj;
				}
			}
			return Status::KrajPobjeda;
		}
	}
	return Status::KrajPoraz;
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda)
		std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar)
		std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar)
		std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(greska==KodoviGresaka::SuvisanParametar)
		std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::cout<<"Unesite komandu: ";
	
	return true;
}

int main (){
	std::cout<<"Pokretanje bi moglo potrajati malo duze, molimo sacekajte!!!";
	return 0;
}