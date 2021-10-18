#include <iostream>
#include <vector>
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
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar,
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	for(const auto &x : mine) {
		if(x.size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if(x[0]>=n or x[1]>=n) throw std::domain_error("Ilegalne pozicije mina");
	}
	Tabla polja(n, std::vector<Polje> (n, Polje::Prazno));
	for(int i(0); i<n; i++)
		for(int j(0); j<n; j++)
			for(const std::vector<int> &x : mine)
				if(i==x[0] and j==x[1]) polja[i][j]=Polje::Mina;
	/*for(auto x : polja) {
		for(auto y : x)
			std::cout << int(y) << " ";
		std::cout << std::endl;
	}*/
	return polja;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	try {
	if(x>=polja.size() or y>=polja[0].size() or x<0 or y<0) throw std::domain_error("");
	}
	catch(std::domain_error) {
		std::cout << "Polje (" << x << "," << y << ") ne postoji";
		throw;
	}
	/*for(auto x : polja) {
		for(auto y : x)
			std::cout << int(y) << " ";
		std::cout << std::endl;
	}std::cout << std::endl;*/
	int a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), k(0);
	if(polja[x][y]==Polje::Mina) {
			a++; b++; c++; d++; f++; g++; h++; k++;
		}
	if(x>=2 and y>=2)
		if(polja[x-2][y-2]==Polje::Mina) {
			a++;
		}
	if(x>=2 and y>=1)
		if(polja[x-2][y-1]==Polje::Mina) {
			a++; b++;
		}
	if(x>=2)
		if(polja[x-2][y]==Polje::Mina) {
			a++; b++; c++;
		}
	if(x>=2 and y<=polja[0].size()-2)
		if(polja[x-2][y+1]==Polje::Mina) {
			b++; c++;
		}
	if(x>=2 and y<=polja[0].size()-3)
		if(polja[x-2][y+2]==Polje::Mina) {
			c++;
		}
	if(x>=1 and y<=polja[0].size()-3)
		if(polja[x-1][y+2]==Polje::Mina) {
			c++; f++;
		}
	if(x>=1 and y<=polja[0].size()-2)
		if(polja[x-1][y+1]==Polje::Mina) {
			b++; e++; f++;
		}
	if(x>=1)
		if(polja[x-1][y]==Polje::Mina) {
			a++; c++; e++; f++; d++;
		}
	if(x>=1 and y>=1)
		if(polja[x-1][y-1]==Polje::Mina) {
			b++; e++; d++;
		}
	if(x>=1 and y>=2)
		if(polja[x-1][y-2]==Polje::Mina) {
			a++; d++;
		}
	if(y>=2)
		if(polja[x][y-2]==Polje::Mina) {
			a++; d++; g++;
		}
	if(y>=1)
		if(polja[x][y-1]==Polje::Mina) {
			a++; b++; g++; e++; h++;
		}
	if(y<=polja[0].size()-2)
		if(polja[x][y+1]==Polje::Mina) {
			b++; c++; e++; h++; k++;
		}
	if(y<=polja[0].size()-3)
		if(polja[x][y+2]==Polje::Mina) {
			c++; f++; k++;
		}
	if(x<=polja.size()-2 and y<=polja[0].size()-3)
		if(polja[x+1][y+2]==Polje::Mina) {
			f++; k++;
		}
	if(x<=polja.size()-2 and y<=polja[0].size()-2)
		if(polja[x+1][y+1]==Polje::Mina) {
			f++; e++; h++;
		}
	if(x<=polja.size()-2)
		if(polja[x+1][y]==Polje::Mina) {
			f++; e++; d++; g++; k++;
		}
	if(x<=polja.size()-2 and y>=1)
		if(polja[x+1][y-1]==Polje::Mina) {
			h++; e++; d++;
		}
	if(x<=polja.size()-2 and y>=2)
		if(polja[x+1][y-2]==Polje::Mina) {
			g++; d++;
		}
	if(x<=polja.size()-3 and y>=2)
		if(polja[x+2][y-2]==Polje::Mina) {
			g++;
		}
	if(x<=polja.size()-3 and y>=1)
		if(polja[x+2][y-1]==Polje::Mina) {
			g++; h++;
		}
	if(x<=polja.size()-3)
		if(polja[x+2][y]==Polje::Mina) {
			g++; h++; k++;
		}
	if(x<=polja.size()-3 and y<=polja[0].size()-2)
		if(polja[x+2][y+1]==Polje::Mina) {
			h++; k++;
		}
	if(x<=polja.size()-3 and y<=polja[0].size()-3)
		if(polja[x+2][y+2]==Polje::Mina) {
			k++;
		}
	
	return {{a, b, c}, {d, e, f}, {g, h, k}};
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	try {
	if(x>=polja.size() or y>=polja[0].size() or x<0 or y<0) throw std::domain_error("");
	}
	catch(std::domain_error) {
		std::cout << "Polje (" << x << "," << y << ") ne postoji";
		throw;
	}
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	try {
	if(x>=polja.size() or y>=polja[0].size() or x<0 or y<0) throw std::domain_error("");
	}
	catch(std::domain_error) {
		std::cout << "Polje (" << x << "," << y << ") ne postoji";
		throw;
	}
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int x1(x), y1(y);
	if(x>=polja.size() or  y>=polja[0].size() or x<0 or y<0) throw std::out_of_range("Izlazak van igrace table");     //
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo) {
		x-=1; y-=1;
	}
	if(smjer==Smjerovi::Gore) {
		x-=1;
	}
	if(smjer==Smjerovi::GoreDesno) {
		x-=1; y+=1;
	}
	if(smjer==Smjerovi::Desno) {
		y+=1;
	}
	if(smjer==Smjerovi::DoljeDesno) {
		x+=1; y+=1;
	}
	if(smjer==Smjerovi::Dolje) {
		x+=1;
	}
	if(smjer==Smjerovi::DoljeLijevo) {
		x+=1; y-=1;
	}
	if(smjer==Smjerovi::Lijevo) {
		y-=1;
	}
	if(x>=polja.size() or  y>=polja[0].size() or x<0 or y<0) {
		x=x1; y=y1;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x][y]==Polje::BlokiranoPrazno or polja[x][y]==Polje::BlokiranoPosjeceno or polja[x][y]==Polje::BlokiranoMina) {
		x=x1; y=y1; 
		throw std::logic_error("Blokirano polje");
	}
	if(polja[x][y]==Polje::Mina) {
		for(std::vector<Polje> &x : polja)
			for(Polje &y : x) y = Polje::Prazno;
		return Status::KrajPoraz;
	}
	//polja[x][y]=Polje::Posjeceno;
	for(int i(0); i<polja.size(); i++)                            //sva polja posjecena
		for(int j(0); j<polja[0].size(); j++) {
			if(polja[i][j]==Polje::Prazno) {
				return Status::NijeKraj;
			}
		}
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x>=polja.size() or  novi_y>=polja[0].size() or novi_x<0 or novi_y<0) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno or polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno or polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	if(polja[novi_x][novi_y]==Polje::Mina) {
		for(std::vector<Polje> &i : polja)
			for(Polje &j : i) j = Polje::Prazno;
		return Status::KrajPoraz;
	}
	x=novi_x; y=novi_y;
	for(int i(0); i<polja.size(); i++)                            //sva polja posjecena
		for(int j(0); j<polja[0].size(); j++) {
			if(x==i and y==j) continue;
			if(polja[i][j]==Polje::Prazno) {
				return Status::NijeKraj;
			}
		}
	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	char c;
		std::cin >> c;
		if(c=='P') {
			if(std::cin.peek()=='1') {
				std::cin.get();
				while(1) {
        			if(std::cin.peek()==' ') {
            			std::cin.get();
        			} else break;
    			}
    			if(std::cin.peek()=='G') {
    				std::cin.get();
    				if(std::cin.peek()=='L') {
    					std::cin.get();
    					while(1) {
        					if(std::cin.peek()==' ') {
            					std::cin.get();
        					} else break;
    					}
    					if(std::cin.peek()=='\n') {
    						komanda=Komande::PomjeriJednoMjesto;
    						smjer=Smjerovi::GoreLijevo;
    					} else {
    						greska=KodoviGresaka::NeispravanParametar;
							std::cin.ignore(10000, '\n');
                			return false;
    					}
    				} else if(std::cin.peek()=='D') {
    					std::cin.get();
    					while(1) {
        					if(std::cin.peek()==' ') {
            					std::cin.get();
        					} else break;
    					}
    					if(std::cin.peek()=='\n') {
    						komanda=Komande::PomjeriJednoMjesto;
    						smjer=Smjerovi::GoreDesno;
    					} else {
    						greska=KodoviGresaka::NeispravanParametar;
							std::cin.ignore(10000, '\n');
                			return false;
    					}
    				} else if(std::cin.peek()=='\n') {
    					komanda=Komande::PomjeriJednoMjesto;
    					smjer=Smjerovi::Gore;
    				} else if(std::cin.peek()==' ') {
    					while(1) {
        					if(std::cin.peek()==' ') {
            				std::cin.get();
        					} else break;
    					}
    					if(std::cin.peek()=='\n') {
    						komanda=Komande::PomjeriJednoMjesto;
    						smjer=Smjerovi::Gore;
    					} else {
    						greska=KodoviGresaka::NeispravanParametar;
							std::cin.ignore(10000, '\n');
                			return false;
    					}
    				} else {
    					greska=KodoviGresaka::NeispravanParametar;
						std::cin.ignore(10000, '\n');
                		return false;
    				}
    			} else if(std::cin.peek()=='D') {
    				std::cin.get();
    				if(std::cin.peek()=='o') {
    					std::cin.get();
    					if(std::cin.peek()==' ') {
    						while(1) {
	        					if(std::cin.peek()==' ') {
	            				std::cin.get();
	        					} else break;
    						}
    						if(std::cin.peek()=='\n') {
    							komanda=Komande::PomjeriJednoMjesto;
    							smjer=Smjerovi::Dolje;
    						} else {
    							greska=KodoviGresaka::NeispravanParametar;
								std::cin.ignore(10000, '\n');
	                			return false;
    						}
    					} else if(std::cin.peek()=='\n') {
    						komanda=Komande::PomjeriJednoMjesto;
    							smjer=Smjerovi::Dolje;
    					} else if(std::cin.peek()=='D') {
    						std::cin.get();
    						while(1) {
	        					if(std::cin.peek()==' ') {
	            				std::cin.get();
	        					} else break;
    						}
    						if(std::cin.peek()=='\n') {
    							komanda=Komande::PomjeriJednoMjesto;
    							smjer=Smjerovi::DoljeDesno;
    						} else {
    							greska=KodoviGresaka::NeispravanParametar;
								std::cin.ignore(10000, '\n');
	                			return false;
    						}
    					} else if(std::cin.peek()=='L') {
    						std::cin.get();
    						while(1) {
	        					if(std::cin.peek()==' ') {
	            				std::cin.get();
	        					} else break;
    						}
    						if(std::cin.peek()=='\n') {
    							komanda=Komande::PomjeriJednoMjesto;
    							smjer=Smjerovi::DoljeLijevo;
    						} else {
    							greska=KodoviGresaka::NeispravanParametar;
								std::cin.ignore(10000, '\n');
	                			return false;
    						}
    					} else {
    						greska=KodoviGresaka::NeispravanParametar;
							std::cin.ignore(10000, '\n');
	                		return false;
    					}
    				} else if(std::cin.peek()=='\n') {
    					komanda=Komande::PomjeriJednoMjesto;
    					smjer=Smjerovi::Desno;
    				} else if(std::cin.peek()==' ') {
    					while(1) {
        					if(std::cin.peek()==' ') {
            				std::cin.get();
        					} else break;
    					}
    					if(std::cin.peek()=='\n') {
    						komanda=Komande::PomjeriJednoMjesto;
    						smjer=Smjerovi::Desno;
    					} else {
    						greska=KodoviGresaka::NeispravanParametar;
							std::cin.ignore(10000, '\n');
                			return false;
    					}
    				} else {
    					greska=KodoviGresaka::NeispravanParametar;
						std::cin.ignore(10000, '\n');
                		return false;
    				}
    			} else if(std::cin.peek()=='L') {
    				std::cin.get();
    				while(1) {
        				if(std::cin.peek()==' ') {
            				std::cin.get();
        				} else break;
    				}
    				if(std::cin.peek()=='\n') {
    					komanda=Komande::PomjeriJednoMjesto;
    					smjer=Smjerovi::Lijevo;
    				} else {
    					greska=KodoviGresaka::NeispravanParametar;
						std::cin.ignore(10000, '\n');
	                	return false;
    				}
    			} else if(std::cin.peek()=='\n') {
    				std::cin.get();
    				greska=KodoviGresaka::NedostajeParametar;
	                return false;
    			} else {
    				greska=KodoviGresaka::NeispravanParametar;
					std::cin.ignore(10000, '\n');
                	return false;
    			}
			} else if(std::cin.peek()=='>') {
				std::cin.get();
				while(std::cin.peek()==' ') std::cin.get();
				if(std::cin.peek()=='\n') {
    				std::cin.get();
    				greska=KodoviGresaka::NedostajeParametar;
	                return false;
    			}
				std::cin >> x >> y;
				if(!std::cin) {
					std::cin.clear();
					greska=KodoviGresaka::NeispravanParametar;
					std::cin.ignore(10000, '\n');
                	return false;
				}
				while(std::cin.peek()==' ') std::cin.get();
				if(std::cin.peek()!='\n') {
					greska=KodoviGresaka::NeispravanParametar;
    				std::cin.ignore(10000, '\n');
                	return false;
				}
				komanda=Komande::PomjeriDalje;
			} else if(std::cin.peek()=='O') {
				std::cin.get();
				while(1) {
        			if(std::cin.peek()==' ') {
            			std::cin.get();
        			} else break;
    			}
    			if(std::cin.peek()!='\n') {
    				greska=KodoviGresaka::SuvisanParametar;
    				std::cin.ignore(10000, '\n');
                	return false;
    			}
    			komanda=Komande::PrikaziOkolinu;
			} else if(std::cin.peek()==' ') {
				while(1) {
        			if(std::cin.peek()==' ') {
            			std::cin.get();
        			} else break;
    			}
    			if(std::cin.peek()=='\n') {
    				greska=KodoviGresaka::NedostajeParametar;
					std::cin.ignore(10000, '\n');
	                return false;
    			} else {
    				greska=KodoviGresaka::PogresnaKomanda;
					std::cin.ignore(10000, '\n');
	                return false;
    			}
			} else if(std::cin.peek()=='\n') {
				greska=KodoviGresaka::NedostajeParametar;
				std::cin.ignore(10000, '\n');
                return false;
			} else {
				greska=KodoviGresaka::PogresnaKomanda;
				std::cin.ignore(10000, '\n');
                return false;
			}
		} else if(c=='B') {
			while(std::cin.peek()==' ') std::cin.get();
			if(std::cin.peek()=='\n') {
    			std::cin.get();
    			greska=KodoviGresaka::NedostajeParametar;
	            return false;
    		}
			std::cin >> x >> y;
			if(!std::cin) {
				std::cin.clear();
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000, '\n');
            	return false;
			}
			while(std::cin.peek()==' ') std::cin.get();
				if(std::cin.peek()!='\n') {
					greska=KodoviGresaka::NeispravanParametar;
    				std::cin.ignore(10000, '\n');
                	return false;
				}
			komanda=Komande::Blokiraj;
		} else if(c=='D') {
			while(std::cin.peek()==' ') std::cin.get();
			if(std::cin.peek()=='\n') {
    			std::cin.get();
    			greska=KodoviGresaka::NedostajeParametar;
	            return false;
    		}
			std::cin >> x >> y;
			if(!std::cin) {
				std::cin.clear();
				greska=KodoviGresaka::NeispravanParametar;
				std::cin.ignore(10000, '\n');
            	return false;
			}
			while(std::cin.peek()==' ') std::cin.get();
				if(std::cin.peek()!='\n') {
					greska=KodoviGresaka::NeispravanParametar;
    				std::cin.ignore(10000, '\n');
                	return false;
				}
			komanda=Komande::Deblokiraj;
		} else if(c=='Z') {
			while(1) {
        		if(std::cin.peek()==' ') {
            		std::cin.get();
        		} else break;
    		}
    		if(std::cin.peek()!='\n') {
    			greska=KodoviGresaka::SuvisanParametar;
    			std::cin.ignore(10000, '\n');
                return false;
    		}
    		komanda=Komande::ZavrsiIgru;
		} else if(c=='K') {
			while(1) {
        		if(std::cin.peek()==' ') {
            		std::cin.get();
        		} else break;
    		}
    		if(std::cin.peek()!='\n') {
    			greska=KodoviGresaka::SuvisanParametar;
    			std::cin.ignore(10000, '\n');
                return false;
    		}
    		komanda=Komande::KreirajIgru;
		} else {
			greska=KodoviGresaka::PogresnaKomanda;
			std::cin.ignore(10000, '\n');
            return false;
		}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	try {
		if(komanda==Komande::PomjeriJednoMjesto) {
			Status s(Idi(polja, x, y, p_smjer));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(s==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for(int i(0); i<polja.size(); i++)
					for(int j(0); j<polja[0].size(); j++)
						polja[i][j]=Polje::Prazno;
			} else if(s==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for(int i(0); i<polja.size(); i++)
					for(int j(0); j<polja[0].size(); j++)
						polja[i][j]=Polje::Prazno;
			}
		}
		if(komanda==Komande::PomjeriDalje) {
			Status s(Idi(polja, x, y, p_x, p_y));
			std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
			if(s==Status::KrajPoraz) {
				std::cout << "Nagazili ste na minu" << std::endl;
				for(int i(0); i<polja.size(); i++)
					for(int j(0); j<polja[0].size(); j++)
						polja[i][j]=Polje::Prazno;
			} else if(s==Status::KrajPobjeda) {
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				for(int i(0); i<polja.size(); i++)
					for(int j(0); j<polja[0].size(); j++)
						polja[i][j]=Polje::Prazno;
			}
		}
		if(komanda==Komande::Blokiraj) {
			BlokirajPolje(polja, p_x, p_y);
		}
		if(komanda==Komande::Deblokiraj) {
			DeblokirajPolje(polja, p_x, p_y);
		}
		if(komanda==Komande::PrikaziOkolinu) {
			std::vector<std::vector<int>> mat(PrikaziOkolinu(polja, x, y));
			for(int i(0); i<mat.size(); i++) {
					for(int j(0); j<mat[0].size(); j++)
						std::cout << mat[i][j] << " ";
				std::cout << std::endl;
			}
		}
		if(komanda==Komande::ZavrsiIgru) {
			for(int i(0); i<polja.size(); i++)
				for(int j(0); j<polja[0].size(); j++)
					polja[i][j]=Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		if(komanda==Komande::KreirajIgru) {
			int n, c, v;
			std::cout << "Unesite broj polja: ";
			std::cin >> n;
			std::vector<std::vector<int>> mat;
			int i(0);
			std::cin.ignore(1000, '\n');
			std::cout << "Unesite pozicije mina: ";
			while(std::cin.peek()!='.') {
				if(std::cin.peek()=='(') {
					std::cin.get();
					std::cin >> c;
					if(std::cin.peek()==',') {
						std::cin.get();
						std::cin >> v;
						if(std::cin.peek()==')') {
							std::cin.get();
							if(std::cin.peek()=='\n' or std::cin.peek()==' ') {
								while(std::cin.peek()==' ') std::cin.get();
								if(c>=n or v>=n or c<0 or v<0) {
									std::cout << "Greska, unesite ponovo!" << std::endl;
									std::cin.ignore(1000, '\n');
								} else {
									if(std::cin.peek()==' ') std::cin.get();
									mat.resize(++i);
									mat[i-1].push_back(c);
									mat[i-1].push_back(v);
									std::cin.ignore(1000, '\n');
								}
							} else {
								std::cout << "Greska, unesite ponovo!" << std::endl;
							}
						} else {
								std::cout << "Greska, unesite ponovo!" << std::endl;
								std::cin.ignore(1000, '\n');
							}
					} else {
								std::cout << "Greska, unesite ponovo!" << std::endl;
								std::cin.ignore(1000, '\n');
							}
				} else {
					std::cout << "Greska, unesite ponovo!" << std::endl;
					std::cin.ignore(1000, '\n');
							}
			}
			polja=KreirajIgru(n, mat);
			std::cin.ignore(1000, '\n');
		}
	}
	catch(std::domain_error a) {
		std::cout << a.what() << std::endl;
	}
	catch(std::out_of_range a) {
		std::cout << a.what() << std::endl;
	}
	catch(std::logic_error a) {
		std::cout << a.what() << std::endl;
	}
	catch(std::runtime_error a) {
		//std::cout << a.what() << std::endl;
		throw;
	}
}

int main ()
{	
	Komande komanda;
	Smjerovi smjer;
	int x, x1(0);
	int y, y1(0);
	Tabla polja;
	KodoviGresaka greska;
	while(1) {
		try {
			std::cout << "Unesite komandu: ";
			bool a(UnosKomande(komanda, smjer, x, y, greska));
			if(a) {
				IzvrsiKomandu(komanda, polja, x1, y1, smjer, x, y);
			} else {
				PrijaviGresku(greska);
			}
		}
		catch(std::runtime_error) {
			std::cout << "Dovidjenja!" << std::endl;
			break;
		}
	}
	return 0;
}