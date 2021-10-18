#include <iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<deque>
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla tabla;
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	for(int i(0); i<mine.size(); i++) {
		if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	tabla.resize(n);
	for(int i(0); i<n; i++) {
		for(int j(0); j<n; j++) tabla.at(i).push_back(Polje::Prazno);
	}
	for(int i(0); i<mine.size(); i++) {
		int h_poz(mine.at(i).at(0)), v_poz(mine.at(i).at(1));
		if(h_poz>=n || v_poz>=n) throw std::domain_error("Ilegalne pozicije mina");
		for(int j(0); j<n; j++) {
			for(int k(0); k<n; k++) {
				if(h_poz==j && k==v_poz) tabla.at(j).at(k)=Polje::Mina;
			}
		}
	}
	tabla.at(0).at(0)=Polje::Prazno;
	return tabla;
}
std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> v;
	for(int i(0); i<polja.size(); i++) {
		if(x>=polja.size() ||y>=polja.at(i).size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	v.resize(3);
	for(int i(0); i<v.size(); i++) v.at(i).resize(3);
	int pocetak_r(0),kraj_r(polja.size()-1);
	if(x>0)  pocetak_r=x-1;
	if(x<polja.size()-1) kraj_r=x+1;
	int pocetak_k(0), kraj_k(polja.at(0).size()-1);
	if(y>0) pocetak_k=y-1;
	if(y<polja.at(0).size()-1) kraj_k=y+1;
	int v_i(0);
	for(int i(pocetak_r); i<=kraj_r; i++) {
		int v_j(0);
		int poc_r(i),kr_r(i);
		if(poc_r>0) poc_r--;
		if(kr_r<polja.size()-1) kr_r++;
		for(int j(pocetak_k); j<=kraj_k; j++) {
			int poc_k(j), kr_k(j);
			if(poc_k>0) poc_k--;
			if(kr_k<polja.at(0).size()-1) kr_k++;
			for(int k(poc_r); k<=kr_r; k++) {
				for(int m(poc_k); m<=kr_k; m++) {
					if(polja.at(k).at(m)==Polje::Mina) {
						v.at(v_i).at(v_j)++;
					}
				}
			}
			if(polja.at(i).at(j)==Polje::Mina) v.at(v_i).at(v_j)--;
			v_j++;
		}
		v_i++;
	}
	return v;
}
void BlokirajPolje(Tabla &polja, int x, int y) {
	for(int i(0); i<polja.size(); i++) {
		if(x>=polja.size() || y>=polja.at(i).size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
	else if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	else if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
	for(int i(0); i<polja.size(); i++) {
		if(x>=polja.size() || y>=polja.at(i).size()) throw std::domain_error("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	}
	if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
	else if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	else if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
}
Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int pozicijax(x),pozicijay(y);
	if(smjer==Smjerovi::Gore) pozicijax--;
	else if(smjer==Smjerovi::GoreDesno) {
		pozicijax--;
		pozicijay++;
	} 
	else if(smjer==Smjerovi::GoreLijevo) {
		pozicijax--;
		pozicijay--;
	} 
	else if(smjer==Smjerovi::Dolje) pozicijax++;
	else if(smjer==Smjerovi::DoljeDesno) {
		pozicijax++;
		pozicijay++;
	} 
	else if(smjer==Smjerovi::DoljeLijevo) {
		pozicijax++;
		pozicijay--;
	}  
	else if(smjer==Smjerovi::Desno) pozicijay++;
	else pozicijay--;
	if(polja.size()<=pozicijax || polja.at(0).size()<=pozicijay) throw std::out_of_range("Izlazak van igrace table");
	else if(polja.at(pozicijax).at(pozicijay)==Polje::BlokiranoPosjeceno || polja.at(pozicijax).at(pozicijay)==Polje::BlokiranoPrazno || polja.at(pozicijax).at(pozicijay)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=pozicijax;
	y=pozicijay;
	if(polja.at(x).at(y)==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.at(i).size(); j++) polja.at(i).at(j)=Polje::Prazno;
		}
		return Status::KrajPoraz;
	} 
	else if(polja.at(x).at(y)==Polje::Prazno) {
		int brojac(0);
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.at(i).size(); j++) {
				if(polja.at(i).at(j)==Polje::Prazno) brojac++;
			}
		}
		if(brojac==1) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x>=polja.size() || novi_y>=polja.at(0).size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina) {
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.at(i).size(); j++) polja.at(i).at(j)=Polje::Prazno;
		}
		return Status::KrajPoraz;
	} 
	else if(polja.at(x).at(y)==Polje::Prazno) {
		int brojac(0);
		for(int i(0); i<polja.size(); i++) {
			for(int j(0); j<polja.at(i).size(); j++) {
				if(polja.at(i).at(j)==Polje::Prazno) brojac++;
			}
		}
		if(brojac==1) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string pomocna;
	std::getline(std::cin,pomocna);
	std::string k;
	for(int i(0); i<pomocna.size(); i++) {
		if(pomocna.at(i)==' ') {
			while(pomocna[i]==' ' && i<pomocna.size()) i++;
		}
		if(pomocna.at(i)!=' ' && i<pomocna.size()) {
			while(pomocna.at(i)!=' ' && i<pomocna.size()) {
				k.push_back(pomocna.at(i));
				i++;
				if(i==pomocna.size()) break;
			}
		}
		if(k!="P1" && k!="P>" && k!="B" && k!="D" && k!="PO" && k!="Z" && k!="K" && i==pomocna.size()) {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
		if(i==pomocna.size()) {
			if(k=="PO") {
				komanda=Komande::PrikaziOkolinu;
				return true;
			} 
			else if(k=="Z") {
				komanda=Komande::ZavrsiIgru;
				return true;
			} 
			else if(k=="K") {
				komanda=Komande::KreirajIgru;
				return true;
			} 
			else if(k=="P1" || k=="P>" || k=="B" || k=="D") {
				greska=KodoviGresaka::NedostajeParametar;
				return true;
			}
		}
		if(pomocna.at(i)==' ') {
			while(pomocna.at(i)==' ' && i<pomocna.size()) i++;
		}
		if(k=="PO" || k=="K" || k=="Z") {
			greska=KodoviGresaka::SuvisanParametar;
			return true;
		}
		if(pomocna.at(i)>='0' && pomocna.at(i)<='9') {
			int broj1(0),broj2(0);
			while(pomocna.at(i)>='0' && pomocna.at(i)<='9' && i<pomocna.size()) {
				broj1=broj1*10+(pomocna.at(i)-'0');
				i++;
				if(i==pomocna.size()) break;
			}
			if(i==pomocna.size()) {
				if( k=="PO" || k=="Z" || k=="K") {
					greska=KodoviGresaka::SuvisanParametar;
					return true;
				} 
				else if(k=="P1") {
					greska=KodoviGresaka::NeispravanParametar;
					return true;
				}
			}
			if(pomocna.at(i)==' ' ) {
				while(pomocna.at(i)==' ' && i<pomocna.size()) {
					i++;
					if(i==pomocna.size()) break;
				}
			}
			if(pomocna.at(i)>='0' && pomocna.at(i)<='9' && i<pomocna.size()) {
				while(pomocna.at(i)>='0' && pomocna.at(i)<='9' && i<pomocna.size()) {
					broj2=broj2*10+(pomocna.at(i)-'0');
					i++;
					if(i==pomocna.size()) break;
				}
				if(i!=pomocna.size()) {
					if(pomocna.at(i)==' ') {
						while(pomocna.at(i)==' '&& i<pomocna.size()) {
							i++;
							if(i==pomocna.size()) break;
						}
					}
				}
				if(i==pomocna.size()) {
					if(k=="P>") {
						komanda=Komande::PomjeriDalje;
						x=broj1;
						y=broj2;
						return true;
					} 
					else if(k=="B") {
						komanda=Komande::Blokiraj;
						x=broj1;
						y=broj2;
						return true;
					} 
					else if(k=="D") {
						komanda=Komande::Deblokiraj;
						x=broj1;
						y=broj2;
						return true;
					}
				} 
				else {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			} 
			else if(pomocna.at(i)<'0'|| pomocna.at(i)>'9') {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			} 
			else if(i==pomocna.size()) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		} 
		else if((pomocna.at(i)>='A' && pomocna.at(i)<='Z') || (pomocna.at(i)>='a' && pomocna.at(i)<='z')) {
			std::string smj;
			while(((pomocna.at(i)>='A' && pomocna.at(i)<='Z') || (pomocna.at(i)>='a'&& pomocna.at(i)<='z')) && i<pomocna.size()) {
				smj.push_back(pomocna.at(i));
				i++;
				if(i==pomocna.size()) break;
			}
			if(k=="P1") {
				if(smj=="GL") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreLijevo;
					return true;
				} 
				else if(smj=="G") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Gore;
					return true;
				} 
				else if(smj=="GD") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::GoreDesno;
					return true;
				} 
				else if(smj=="D") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Desno;
					return true;
				} 
				else if(smj=="DoD") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::DoljeDesno;
					return true;
				} 
				else if(smj=="Do") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Dolje;
					return true;
				} 
				else if(smj=="DoL") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::DoljeLijevo;
					return true;
				} 
				else if(smj=="L") {
					komanda=Komande::PomjeriJednoMjesto;
					smjer=Smjerovi::Lijevo;
					return true;
				} 
				else {
					greska=KodoviGresaka::NeispravanParametar;
					return true;
				}
			} 
			else if(k=="P>" || k=="B" || k=="D") {
				greska=KodoviGresaka::NeispravanParametar;
				return true;
			} 
			else {
				greska=KodoviGresaka::PogresnaKomanda;
				return false;
			}
		}
	}
	return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	try {
		if(komanda==Komande::PomjeriJednoMjesto) {
			Status status(Idi(polja,x,y,p_smjer));
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;;
			if(status==Status::KrajPoraz || status==Status::KrajPobjeda) {
				if(status==Status::KrajPoraz) std::cout<<"Nagazili ste minu"<<std::endl;
				else std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				for(int i(0); i<polja.size(); i++) {
					for(int j(0); j<polja.at(i).size(); j++) polja.at(i).at(j)=Polje::Prazno;
				}
				throw std::runtime_error("Igra zavrsena");
			}
		} 
		else if(komanda==Komande::PomjeriDalje) {
			p_x=x;
			p_y=y;
			Status status(Idi(polja,x,y,p_x,p_y));
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;;
			if(status==Status::KrajPoraz || status==Status::KrajPobjeda) {
				if(status==Status::KrajPoraz) std::cout<<"Nagazili ste minu"<<std::endl;
				else std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				for(int i(0); i<polja.size(); i++) {
					for(int j(0); j<polja.at(i).size(); j++) polja.at(i).at(j)=Polje::Prazno;
				}
				throw std::runtime_error("Igra zavrsena");
			}
		} 
		else if(komanda==Komande::Blokiraj) BlokirajPolje(polja,x,y);
		else if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,x,y);
		else if(komanda==Komande::PrikaziOkolinu) {
			std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja,x,y));
			for(int i(0); i<okolina.size(); i++) {
				for(int j(0); j<okolina.at(i).size(); j++) std::cout<<okolina.at(i).at(j)<<" ";
			}
		} 
		else if(komanda==Komande::ZavrsiIgru) {
			for(int i(0); i<polja.size(); i++) {
				for(int j(0); j<polja.at(i).size(); j++) polja.at(i).at(j)=Polje::Prazno;
			}
			throw std::runtime_error("Igra zavrsena");
		}
		else if(komanda==Komande::KreirajIgru) {
			int n;
			std::cout<<"Unesite broj polja: ";
			for(;;) {
				std::cin>>n;
				if(!std::cin) {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					std::cin.clear();
					std::cin.ignore(10000,'\n');
				} 
				else if(n<=0) std::cout<<"Greska, unesite ponovo!"<<std::endl;
				else break;
			}
			std::cin.ignore(1000,'\n');
			std::cout<<"Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			int i(0);
			for(;;) {
				int kraj(0);
				for(;;) {
					std::string s;
					for(;;) {
						char znak;
						znak=std::cin.get();
						if(znak!='.' && znak!='\n') s.push_back(znak);
						else break;
					}
					std::cin.ignore(1000,'\n');
					if(s.size()==0) {
						kraj=1;
						break;
					}
					int greska(0);
					auto ima_zagrada1(std::find(s.begin(),s.end(),'('));
					auto ima_zagrada2(std::find(s.begin(),s.end(),')'));
					auto ima_zarez(std::find(s.begin(),s.end(),','));
					if(ima_zagrada1!=s.end() && ima_zagrada2!=s.end() && ima_zarez!=s.end()) {
						std::deque<int>broj1,broj2;
						int h(0);
						while((s.at(h)<'0' || s.at(h)>'9') &&h<s.size()) h++;
						while(s.at(h)>='0' && s.at(h)<='9' && h<s.size()) {
							broj1.push_back(s.at(h)-'0');
							h++;
						}
						while((s.at(h)<'0' || s.at(h)>'9') &&h<s.size()) h++;
						while(s.at(h)>='0' && s.at(h)<='9' && h<s.size()) {
							broj2.push_back(s.at(h)-'0');
							h++;
						}
						int prvi(0),drugi(0);
						int ramzmaci(std::count(s.begin(),s.end(),' '));
						if(broj1.size()!=0 && broj2.size()!=0) {
							if((ramzmaci+broj1.size()+broj2.size()+3)==s.size()) {
								for(int k(0); k<broj1.size(); k++) prvi=prvi*10+broj1.at(k);
								for(int k(0); k<broj2.size(); k++) drugi=drugi*10+broj2.at(k);
							} 
							else greska=1;
						} 
						else greska=1;
						if(prvi>=n || drugi>=n) greska=1;
						if(greska==0 && prvi>=0 && drugi>=0 ) {
							std::vector<int> pomocni;
							pomocni.push_back(prvi);
							pomocni.push_back(drugi);
							mine.push_back(pomocni);
							break;
						} 
						else if(greska==1) std::cout<<"Greska, unesite ponovo!"<<std::endl;
					} 
					else std::cout<<"Greska, unesite ponovo!"<<std::endl;
				}
				if(kraj==1) {
					break;
				}
				i++;
			}
			polja=KreirajIgru(n,mine);
		}
	} 
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	} 
	catch( std::out_of_range izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	} 
	catch(std::logic_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	} 
	catch(std::runtime_error izuzetak) {
		throw;
	}
}
int main () {
	Komande komanda;
	int x,y;
	Smjerovi smjer=Smjerovi::GoreDesno;
	KodoviGresaka greska;
	Tabla polja;
	int novi_x,novi_y;
	for(;;) {
		try {
			std::cout<<"Unesite komandu: ";
			bool ispravna(UnosKomande(komanda,smjer,x,y,greska));
			if(ispravna) {
				IzvrsiKomandu(komanda,polja,x,y,smjer,novi_x,novi_y);
			}
			else PrijaviGresku(greska);
		}
		catch(std::runtime_error) {
			std::cout<<"Dovidjenja!"<<std::endl;
			return 0;
		}
	}
	return 0;
}