/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector> 
#include <stdexcept>
#include <string>
#include <complex>


enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;
int stanuti(0), TempX(0), TempY(0);

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla tabela(n, std::vector<Polje>(n,Polje::Prazno));
	for(unsigned int i(0); i<mine.size(); i++){
		if(int(mine[i].size()) != 2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0] > int(tabela.size()) || mine[i][1] > int(tabela[0].size())) throw std::domain_error("Ilegalne pozicije mina");
		tabela[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	return tabela;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polje, int x, int y){
	if(x<0 || y<0 || x>=int(polje.size()) || y>=int(polje[0].size())) throw std::domain_error("Polje (" + std::to_string(x) + ","+ std::to_string(y) + ") ne postoji");
	std::vector<std::vector<int>> Okolina(3, std::vector<int>(3,0));
	int X(x-1), a(0), k(0);
	
	while(k<3){
	int b(0), Y(y-1);
		if(X>=0 && X<=int(polje.size())-1){
			for(int j(0);j<3; j++, Y++){
				int broj(0), kor_x(X-1), i(0);
				
				if(Y>=0 && Y<=int(polje[0].size())-1){
					while(i<3){
						int kor_y(Y-1);
						if((kor_x<0 || kor_x>int(polje.size())-1) && (kor_y<0 || kor_y>int(polje.size())-1)) {i++; kor_x++; continue;}
						if(kor_x>=0 && kor_x<=int(polje.size()) -1){
							if(kor_y>=0)
								if(polje[kor_x][kor_y] == Polje::Mina) broj++;
							if(kor_y+1>=0 && kor_y+1<=int(polje[i].size()-1) && kor_y!=Y && kor_x!=X)                                                
								if(polje[kor_x][kor_y+1] == Polje::Mina) broj++;
							if(kor_y+2<=int(polje[i].size())-1)
								if(polje[kor_x][kor_y+2] == Polje::Mina) broj++;
						}
					kor_x++;
					i++;
					}
				}
			Okolina[a][b++] = broj;
			}
		}
			X++;
			k++;
			a++;
	}
	return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	
	if(x<0 || x>int(polja.size())-1 || y<0 || y>int(polja[0].size())-1) throw std::domain_error("Polje (" + std::to_string(x) +","+ std::to_string(y) +") ne postoji");
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla&polja, int x, int y){
	if(x<0 || x>int(polja.size())-1 || y<0 || y>int(polja[0].size())-1) throw std::domain_error("Polje (" + std::to_string(x)+ "," + std::to_string(y) + ") ne postoji");
	if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	if(polja[x][y] == Polje::BlokiranoPrazno)polja[x][y] = Polje::Prazno;
	if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}
int Prebroji(Tabla &polja){
	int brojac(0);
	for(auto x: polja){
		for(auto y: x){
			if(y == Polje::Prazno) brojac++;
		}
	}
	return brojac;
}
void PrijaviGresku(KodoviGresaka kod){
	if(kod == KodoviGresaka::PogresnaKomanda) std::cout <<"Nerazumljiva komanda!\n";
	else if(kod == KodoviGresaka::NedostajeParametar) std::cout <<"Komanda trazi parametar koji nije naveden!\n";
	else if(kod == KodoviGresaka::NeispravanParametar) std::cout <<"Parametar komande nije ispravan!\n";
	else if(kod == KodoviGresaka::SuvisanParametar) std::cout <<"Zadan je suvisan parametar nakon komande!\n";
}
bool IzdvojiKoordinate(std::string &s, int &i, KodoviGresaka &greska){
	i++;
	while(s[i] == ' ')i++;
	if(i>=int(s.length())-2){greska = KodoviGresaka::NedostajeParametar; return false;}
	int kor_x(0), kor_y(0);
	if(!(s[i]>='0' && s[i]<='9')){
		greska = KodoviGresaka::NeispravanParametar;
		return false;
		}
	while(i<int(s.length()) && s[i]>='0'&&s[i]<='9'){
	kor_x+=s[i] - '0';
	kor_x*=10;
	i++;
	}
	kor_x/=10;
	if(i>=int(s.length())-1){greska = KodoviGresaka::NedostajeParametar; return false;}
	if(s[i]==' '){
		while(s[i] == ' ')i++;
		if(i>=int(s.length())){greska = KodoviGresaka::NedostajeParametar; return false;}
	}	
	else{greska = KodoviGresaka::NedostajeParametar;return false;}
	if(!(s[i]>='0' && s[i]<='9')){greska = KodoviGresaka::NeispravanParametar; return false;}
				while(i<int(s.length()) && s[i]>='0' && s[i]<='9'){
					kor_y+=s[i] - '0';
					kor_y*=10;
					i++;
				}
				kor_y/=10;
				if(!(i==int(s.length()) || (i<int(s.length())&&s[i]==' '))){
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				} 
				TempX=kor_x;
				TempY=kor_y;
				return true;
			
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int kor_x(x), kor_y(y);
	int BrojPraznih(Prebroji(polja));
	if(smjer == Smjerovi::Gore || smjer ==Smjerovi::GoreDesno || smjer == Smjerovi::GoreLijevo) kor_x-=1;
	if(smjer == Smjerovi::GoreDesno || smjer == Smjerovi::Desno || smjer == Smjerovi::DoljeDesno) kor_y+=1;
	if(smjer == Smjerovi::Dolje || smjer ==Smjerovi::DoljeDesno || smjer == Smjerovi::DoljeLijevo) kor_x+=1;
	if(smjer == Smjerovi::Lijevo || smjer == Smjerovi::DoljeLijevo || smjer ==Smjerovi::GoreLijevo) kor_y-=1; 
	
	if(kor_x<0 || kor_x>=int(polja.size()) || kor_y<0 || kor_y>=int(polja[0].size())) throw std::out_of_range("Izlazak van igrace table\n");
	else if(polja[kor_x][kor_y] == Polje::BlokiranoPosjeceno || polja[kor_x][kor_y] == Polje::BlokiranoPrazno || polja[kor_x][kor_y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	else{
		polja[x][y] = Polje::Posjeceno;
		x=kor_x;
		y=kor_y;
		stanuti++;
	}
	if(polja[kor_x][kor_y] == Polje::Mina){
		polja = std::vector<std::vector<Polje>>(polja.size(), std::vector<Polje>(polja[0].size(), Polje::Prazno));
		return Status::KrajPoraz;	
	} 
	if(BrojPraznih == stanuti) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	int BrojPraznih(Prebroji(polja));
	if(novi_x>=int(polja.size())||novi_x<0 ||novi_y<0 || novi_y>=int(polja.size())) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x=novi_x;
	y = novi_y;
	stanuti++;
	if(polja[x][y]==Polje::Mina){
		polja = std::vector<std::vector<Polje>>(polja.size(), std::vector<Polje>(polja[0].size(), Polje::Prazno));
		return Status::KrajPoraz;
	}
	if(BrojPraznih == stanuti) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string s;
	std::getline(std::cin, s);
	for(int i(0); i<int(s.length());){
		while(i<int(s.length()) && s[i] == ' ') i++;
		if(i == int(s.length())){greska = KodoviGresaka::PogresnaKomanda; return false;}
		if(s[i] == 'P'){
			i++;
			if(s[i] == '1'){
				i++;
				while(i<int(s.length())-1 && s[i] == ' ') i++;
				if(i==int(s.length())){greska = KodoviGresaka::NedostajeParametar; return false;}
				if(s[i] == 'G'){
					if(i==int(s.length())-1 || (i<=int(s.length())-2 && s[i+1] == ' ')){
						smjer = Smjerovi::Gore;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					if(i<=int(s.length())-2 && s[i+1] == 'L'){
						i++;
						if(i==int(s.length())-1 || (i<=int(s.length())-2 && s[i+1] == ' ')){
							smjer = Smjerovi::GoreLijevo;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						greska = KodoviGresaka::NeispravanParametar;
						return false;
						
					}
					if(i<=int(s.length())-2 && s[i+1] == 'D'){
						i++;
						if(i==int(s.length())-1 || (i<=int(s.length())-2 && s[i+1] == ' ')){
							smjer = Smjerovi::GoreDesno;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						greska = KodoviGresaka::NeispravanParametar;
						return false;;
					}
					
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					
				}
				if(s[i] == 'D'){
					if(i == int(s.length())-1 || (i<=int(s.length())-2 && s[i+1] == ' ')){
						smjer = Smjerovi::Desno;
						komanda = Komande::PomjeriJednoMjesto;
						return true;
					}
					 if(i>=int(s.length())-2 && !(s[i+1] == 'o' || s[i+1]!=' ')){
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					if(i<=int(s.length())-2 && s[i+1] == 'o'){
						if(i==int(s.length())-2 || (i<=int(s.length()) - 3 && s[i+2] == ' ')){
							smjer = Smjerovi::Dolje;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
							
						}	
						if((i == int(s.length()) -3 && s[i+2] == 'D') || (i<=int(s.length())-4 && s[i+2] == 'D' && s[i+3] == ' ')){
							smjer = Smjerovi::DoljeDesno;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						if((i == int(s.length()) -3 && s[i+2] == 'L') || (i<=int(s.length())-4 && s[i+2] == 'L' && s[i+3] == ' ')){
							smjer = Smjerovi::DoljeLijevo;
							komanda = Komande::PomjeriJednoMjesto;
							return true;
						}
						greska = KodoviGresaka::NeispravanParametar;
						return false;
					}
					greska = KodoviGresaka::NeispravanParametar;
					return false;
				}
				if(s[i] == 'L' && (i==int(s.length())-1 || (i<=int(s.length()) && s[i+1] == ' '))){
					smjer = Smjerovi::Lijevo;
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
				greska = KodoviGresaka::NeispravanParametar;
				return false;;
			}
			if(s[i] == '>'){
				
				bool flag{IzdvojiKoordinate(s, i, greska)};
				if(flag){
					komanda = Komande::PomjeriDalje;
					x=TempX; 
					y=TempY;
					return true;
				}
				
			    return false;
			}
			if(s[i] == 'O'){
				if(i==int(s.length())-1 ||(i<=int(s.length())-2 && s[i+1] == ' ')){
					komanda = Komande::PrikaziOkolinu;
					return true;
				}
			}
			greska = KodoviGresaka::PogresnaKomanda;
			return false;;
		}
		if(s[i] == 'B'){
			
			bool flag{IzdvojiKoordinate(s,i,greska)};
			if(flag){
				komanda = Komande::Blokiraj;
				x=TempX;
				y=TempY;
				return true;
			}
			return false;
		}
		if(s[i] == 'D'){
			bool flag{IzdvojiKoordinate(s,i,greska)};
			if(flag){
				komanda = Komande::Deblokiraj;
				x=TempX;
				y=TempY;
				return true;
			}
			return false;
		}
		if((i==int(s.length())-1 && s[i] == 'Z')||(i<=int(s.length())-2 && s[i+1] == ' ')){
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		if((i==int(s.length())-1 && s[i] == 'K')||(i<=int(s.length())-2 && s[i+1] == ' ')){
			komanda = Komande::KreirajIgru;
			return true;
		}
		
		greska = KodoviGresaka::PogresnaKomanda; 
		return false;
	}
	greska = KodoviGresaka::PogresnaKomanda;
	return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	try{
	if(komanda == Komande::PomjeriJednoMjesto)	{
		Status S = Idi(polja,x,y,p_smjer);
		std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
		if(S==Status::KrajPobjeda) std::cout << "Bravo, obisli ste sva sigurna polja\n";
		else if(S==Status::KrajPoraz){ std::cout << "Nagazili ste na minu\n";komanda = Komande::ZavrsiIgru;}
	}
	if(komanda == Komande::ZavrsiIgru){
		Tabla  temp(polja.size(), std::vector<Polje>(polja[0].size(), Polje::Prazno));
		polja = temp;
		throw std::runtime_error("Igra zavrsena\n");
	}
	if(komanda == Komande::PomjeriDalje){
		Idi(polja,x,y,TempX,TempY);
		std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
	} 
	if(komanda == Komande::Blokiraj)BlokirajPolje(polja, TempX, TempY);
	if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja,TempX,TempY);
	if(komanda == Komande::PrikaziOkolinu){ 
		std::vector<std::vector<int>> Okolina{PrikaziOkolinu(polja, x,y)};
		for(auto x : Okolina){
			for(auto y : x) std::cout << y<<" ";
			std::cout  << std::endl;
		}
		
	}
	if(komanda == Komande::KreirajIgru){
		int n;
		while(1){
		std::cout << "Unesite broj polja: ";
		
		if(std::cin>>n) { 
				std::cin.ignore(1000, '\n');
				break;
		}
		else{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		}
		std::cout << "Unesite pozicije mina: ";
		std::vector<std::vector<int>> mine;
		for(int i(0);;){
			std::string miwa(5,'*');
			std::getline(std::cin, miwa);
			if(miwa[0] =='.') break;
			if(miwa[0] == '(' && miwa[1]>='0' && miwa[1]<='9' && miwa[2]==',' && miwa[3]>='0' && miwa[3]<='9' && miwa[4]==')'){
				int mina_x(miwa[1] - '0'), mina_y(miwa[3] - '0');
				if(mina_x>=n || mina_x<0 ||mina_y>=n ||mina_y<0){
					std::cout <<"Greska, unesite ponovo!"<<std::endl;
					continue;
				}
				mine.resize(i+1);
				mine[i].push_back(mina_x);
				mine[i].push_back(mina_y);
				i++;
				continue;
			}
			
			std::cout << "Greska, unesite ponovo!" << std::endl;
			continue;	
		}
		polja = KreirajIgru(n,mine);
	}
	}
	catch(std::out_of_range e){
		std::cout << e.what() << std::endl;
	}
	catch(std::domain_error e){
		std::cout << e.what() << std::endl;
	}
	catch(std::logic_error e){
		std::cout << e.what() << std::endl;
	}
	catch(std::runtime_error e){
		
	}
}

int main (){
	Komande komanda(Komande::KreirajIgru);
	int x(0), y(0);
	Smjerovi smjer;
	KodoviGresaka greska;
	Tabla polja;
	while(1){
		std::cout << "Unesite komandu: ";
		if(UnosKomande(komanda, smjer, x, y, greska)){ IzvrsiKomandu(komanda, polja, x, y, smjer);}
		else PrijaviGresku(greska);
		if(komanda == Komande::ZavrsiIgru){std::cout << "Dovidjenja!" << std::endl; break;}
		
		
	}
	return 0;
}