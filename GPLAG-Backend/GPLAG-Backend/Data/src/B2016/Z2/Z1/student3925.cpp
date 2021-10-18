/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>



enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla t(n,std::vector<Polje>(n,Polje::Prazno));
	for(int i(0);i<mine.size();i++){
		if(mine[i].size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
	}
	for(int i(0);i<mine.size();i++){
		if(mine[i][0]<0 || mine[i][0]>=n || mine[i][1]<0 || mine[i][1]>=n) throw std::domain_error("Ilegalne pozicije mina");
	}
	for(int i(0);i<mine.size();i++) {
		int a=mine[i][0];
		int b=mine[i][1];
		t[a][b]=Polje::Mina;
	}
	return t;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> m;
	if(x<0 || x>=polja.size() || y<0 || y>= polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	
	for(int i(x-1);i<=x+1;i++){
		std::vector<int> v;
		for(int j(y-1);j<=y+1;j++){
			int suma(0);
			for(int k(i-1);k<=i+1;k++){
				for(int l(j-1);l<=j+1;l++){
					if(k!=i || l!=j){
						if(k>=0 && l>=0 && k<polja.size() && l<polja.size()){
							if(polja[k][l]==Polje::Mina || polja[k][l]==Polje::BlokiranoMina) suma++;
						}
					}
				}
			}
			v.push_back(suma);
		}
		m.push_back(v);
	}
	return m;
}


void BlokirajPolje (Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
}
void DeblokirajPolje (Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw std::domain_error ("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int a,b;
	if(smjer==Smjerovi::GoreLijevo) {
		a=-1;
		b=-1;
	}
	else if(smjer==Smjerovi::Gore){
		a=-1;
		b=0;
	}
	else if(smjer==Smjerovi::GoreDesno){
		a=-1;
		b=1;
	}
	else if(smjer==Smjerovi::Desno){
		a=0;
		b=1;
	}
	else if(smjer==Smjerovi::DoljeDesno){
		a=1;
		b=1;
	}
	else if(smjer==Smjerovi::Dolje){
		a=1;
		b=0;
	}
	else if(smjer==Smjerovi::DoljeLijevo){
		a=1;
		b=-1;
	}
	else if(smjer==Smjerovi::Lijevo){
		a=0;
		b=-1;
	}
	else{
		a=0;
		b=0;
	}
	if(x+a<0 || x+a>=polja.size() || y+b<0 || y+b>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	else if(polja[x+a][y+b]==Polje::BlokiranoPosjeceno || polja[x+a][y+b]==Polje::BlokiranoPrazno || polja[x+a][y+b]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	else {
		polja[x][y]=Polje::Posjeceno;
		x+=a;
		y+=b;
	}
	if(polja[x][y]==Polje::Mina){
		for(int i(0);i<polja.size();i++){
			for(int j(0);j<polja.size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else {
		for(int i(0);i<polja.size();i++){
			for(int j(0);j<polja.size();j++){
			
				if(i!=x || j!=y){
				if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno) return Status::NijeKraj;
				}
			}
		}
		
		return Status::KrajPobjeda;
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina)
	throw std::logic_error ("Blokirano polje");
	else {
		polja[x][y]=Polje::Posjeceno;
		x=novi_x;
		y=novi_y;
		if(polja[x][y]==Polje::Mina){
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.size();j++) polja[i][j]=Polje::Prazno;
			}
			return Status::KrajPoraz;
		}
		
		else {
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.size();j++) {
					if(x!=i || y!=j){
					if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno) return Status::NijeKraj;
				}
				}
			}
			return Status::KrajPobjeda;
			
		}
	}
}
void PrijaviGresku(KodoviGresaka kod){
	if(kod==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	else if(kod==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	else if(kod==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	else if(kod==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}
bool isNum (char c){
	return c>='0' && c<='9';
}
bool pokupi_broj(const std::string &s, int &indeks, int &a){
	if(indeks>=s.length()) return false;
	if(!isNum(s[indeks])) return false;
	a=0;
	while(indeks<s.length() && isNum(s[indeks])){
		a=a*10+(s[indeks]-'0');
		++indeks;
	}
	return true;
}
void skipSpaces(const std::string &s, int &indeks){
	while(indeks<s.length() && s[indeks]==' ') indeks++;
}

bool pokupi_tacku(const std::string &s, int indeks, int &a, int &b,int n){
	if(indeks>=s.length()) return false;
	skipSpaces(s,indeks);
	if(indeks>=s.length()) return false;
	if(s[indeks]!='(') return false;
	indeks++;
	if(!(pokupi_broj(s,indeks,a))) return false;
	skipSpaces(s,indeks);
	if(s.length()<=indeks) return false;
	if(s[indeks]!=',') return false;
	indeks++;
	skipSpaces(s,indeks);
	if(!pokupi_broj(s,indeks,b)) return false;
	skipSpaces(s,indeks);
	if(s.length()<=indeks) return false;
	if(s[indeks]!=')') return false;
	indeks++;
	skipSpaces(s,indeks);
	if(indeks<s.length()) return false;
	if(a<0 || b<0 || a>=n || b>=n) return false;
	return true;
}

bool UnosKomande( Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string s;
	std::getline(std::cin, s);
	int i(0);
	while(i<s.length() && s[i]==' ') i++; /*Pokupim sve razmake ako ih ima*/
	if(i==s.length()) { /*znaci da su samo razmaci bili*/
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	else if(s[i]=='K' || s[i]=='Z'){/*Nade K ili Z*/
		int p=i;
		i++;
		while(i<s.length() && s[i]==' ') i++;
		if(i==s.length()){	/*Ako je i=s.length znaci da su samo razmaci bili nakon slova K ili Z*/
			if(s[p]=='K') komanda=Komande::KreirajIgru;
			else if(s[p]=='Z') komanda=Komande::ZavrsiIgru;
			return true;
		}
		else{
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
	}
	else if(s[i]=='P'){ /*Nade P*/
		i++; // i uvecan za naredno slovo
		if(i==s.length()){ //znaci da je samo P bilo i to je pogresna komanda
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
			}
		else if(s[i]!='1' && s[i]!='>' && s[i]!='O'){
			greska=KodoviGresaka::PogresnaKomanda; // osim PO P> i P1 sve je pogresna komanda
			return false;
			}
		else {
			int p=i; //p je gdje se nalazi znak nakon P (O, > ili 1)
			i++;
			while(i<s.length() && s[i]==' ') i++; //guta razmake nakon P?
			if(i==s.length()){ //ako je i doslo do kraja znaci da smo imali samo P?
				if(s[p]=='O'){ //ako je ? O onda je dobro treba prikazati okolinu
						komanda=Komande::PrikaziOkolinu;
						return true;
						}
					else{//u ostalim slucajevima (to je 1 i>) needostaje parametar
						greska=KodoviGresaka::NedostajeParametar;
						return false;
						}
					}
			else if(s[p]=='O'){
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else if(s[p]=='1'){ //ako smo na ovom ifu znaci da ima nesto nakon P? i da sigurno nismo na kraju stringa
					if(s[i]!='G' && s[i]!='D' && s[i]!='L'){
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else if(s[i]=='L'){ // rijeseno za L
						i++;
						while(i<s.length() && s[i]==' ') i++;
						if(i!=s.length()){
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else {
							komanda=Komande::PomjeriJednoMjesto;
							smjer=Smjerovi::Lijevo;
							return true;
						}
					}
					else if(s[i]=='D' || s[i]=='G'){ // ako je G ili D
						int q=i;
						i++;// q mi je indeks od G ili D
						while(i<s.length() && s[i]==' ') i++; //dok su razmaci pici
						if(i==s.length()){ //ako je bilo samo D ili G pa razmaci
							komanda=Komande::PomjeriJednoMjesto; 
							if(s[q]=='D') smjer=Smjerovi::Desno;
							else smjer=Smjerovi::Gore;
							return true;
						}
						else if(s[q+1]!='L' && s[q+1]!='D' && s[q+1]!='o'){ // ako nisu bili razmaci samo ispred i ako ide D ili G pa nesto sto ne treba
							greska=KodoviGresaka::NeispravanParametar; //DA LI JE TACNA GRESKA
							return false;
						}
						else if(s[q]=='G' && s[q+1]=='L'){ // Ako ide P1 razmaci GL
							i=q+1; //i je na L
							i++; //i je iza l
							while(i<s.length() && s[i]==' ') i++; //kupi razmake
							if(i==s.length()){ // samo razmaci bili ili nista nakon L
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::GoreLijevo;
								return true;
							}
							else{ //ima nesto iza i ne valja
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
						else if(s[q]=='G' && s[q+1]=='D'){
							i=q+1;
							i++;
							while(i<s.length() && s[i]==' ') i++;
							if(i==s.length()){
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::GoreDesno;
								return true;
							}
							else {
								greska=KodoviGresaka::SuvisanParametar;
								return false;
							}
						}
						else if(s[q]=='D' && s[q+1]=='o'){ // ako imam P1 Do
							i=q+1;
							int k=i;// k i i pokazuje na o
							i++; // i je jedno mjesto dalje
				
							while(i<s.length() && s[i]==' ') i++; //preskacem razmake
							if(i==s.length()){ //ako je i=s.length onda je Do bila komanda
								komanda=Komande::PomjeriJednoMjesto;
								smjer=Smjerovi::Dolje;
								return true;
							}
							else{
								int w=k+1;
								if(w!=i){ //ako se i pomjerio znaci da je bilo razmaka ali i nije do kraja znaci jos nesto
									greska=KodoviGresaka::NeispravanParametar;
									return false;
								}
								else{
									i=w;
									if(s[w]!='D' && s[w]!='L'){
										greska=KodoviGresaka::NeispravanParametar;
										return false;
									}
									i++;
									while(i<s.length() && s[i]==' ') i++;
									if(i==s.length()){
										komanda=Komande::PomjeriJednoMjesto;
										if(s[w]=='D') smjer=Smjerovi::DoljeDesno;
										else smjer=Smjerovi::DoljeLijevo;
										return true;
									}
									else{
										greska=KodoviGresaka::NeispravanParametar;
										return false;
									}
									
								}
								
							}
						}
						
					}
					
			
			
					}
					
			else if(s[p]=='>'){// ima nesto nakon P? i nismo na kraju stringa
					if(s[i]<'0' || s[i]>'9'){
						greska=KodoviGresaka::NeispravanParametar;
						return false;
						}
					else{
						int parametar(0);//u parametar stavlja x
						bool poc(false);
						while(i<s.length() && s[i]>='0' && s[i]<='9'){
							if(poc==false){
								parametar+=s[i]-48;
								poc=true;
								}
							else parametar=parametar*10+(s[i]-48);
							i++;
							} // ovdje znaci da je pokupio P> i neki broj
						if(i==s.length()){ // znaci da nema y da pokupi
							greska=KodoviGresaka::NedostajeParametar; 
							return false;
							}
						else {
							while(i<s.length() && s[i]==' ') i++;
							if(i==s.length()){
								greska=KodoviGresaka::NedostajeParametar;
								return false;
							}
							if(s[i]<'0' || s[i]>'9'){
								greska=KodoviGresaka::NeispravanParametar;
								return false;
								}
							else{
								int parametary(0);
								bool poc2(false);
								while(i<s.length() && s[i]>='0' && s[i]<='9'){
									if(poc2==false){
										parametary+=s[i]-48;
										poc2=true;
										}
									else parametary=parametary*10+(s[i]-48);
									i++;
									}
							while(i<s.length() && s[i]==' ') i++;
							if(i!=s.length()){
								greska=KodoviGresaka::NeispravanParametar;
								return false;
								}
							else{
								komanda=Komande::PomjeriDalje;
								x=parametar;
								y=parametary;
								return true;
								}
							}
						}
					}
				
				} //kraj ako je ocitano P>
			
		}
		}
	else if(s[i]=='B' || s[i]=='D')	{ // ako imam B ili D
		int p=i; //p ce mi biti indeks B ili D da na kraju provjerim
		i++;
		if(i==s.length()){ //znaci da sam imala samo B ili D pa nedostaje parametar
			greska=KodoviGresaka::NedostajeParametar;
			return false;
			}
		else{ //provjeravamo sta ima dalje
			while(i<s.length() && s[i]==' ') i++; 
			if(i==s.length()){ //ako je dosao dotle znaci da smo imali samo razmake nakon B ili D
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else if(s[i]<'0' || s[i]>'9'){ //znaci da nakon B ili D imam nesto sto nije broj
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			else{ //znaci da smo broj nasli nakon B ili D
				int parametar(0);
				bool poc(false);
				while(i<s.length() && s[i]>='0' && s[i]<='9'){ //dokle god su cifre
					if(poc==false){
						parametar+=s[i]-48;
						poc=true;
					}
					else parametar=parametar*10+(s[i]-48);
					i++;
				}//u parametar pokupili broj nakon B ILI D i to je x parametar
				if(i==s.length()){ //samo je x bio nema y
					greska=KodoviGresaka::NedostajeParametar;
					return false;
				}
				else{
					while(i<s.length() && s[i]==' ') i++; //kupi razmake
					if(i==s.length()) { //pokupili smo x i razmake i nema vise nista, fali y
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
					if(s[i]<'0' || s[i]>'9'){ //naisao na nesto sto nije cifra
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					}
					else{ //kupi parametar
						int parametary(0);
						bool poc2(false);
						while(i<s.length() && s[i]>='0' && s[i]<='9'){
							if(poc2==false){
								parametary+=s[i]-48;
								poc2=true;
							}
							else parametary=parametary*10+(s[i]-48);
							i++;
						} // i je odma iza zadnje cifre, paramentary je y
						while(i<s.length() && s[i]==' ') i++; //kupi razmake
						if(i!=s.length()){ //ako ima jos ista nakon y neispravni su parametri
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
						else{ // ima komandu i parametre, smjestit x i y aa na osnov s[p] tj da li je B ili D odrediti komandu
							if(s[p]=='B'){ 
								komanda=Komande::Blokiraj; // B je blokiraj
							}
							else komanda=Komande::Deblokiraj; // ako nije B  onda je D
							x=parametar;
							y=parametary;
							return true;
						}
					}
				}
			}
		}
	}

		greska=KodoviGresaka::PogresnaKomanda;
		return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==Komande::PomjeriJednoMjesto){
		try{
			Status sad=Idi(polja,x,y,p_smjer);
			if(sad==Status::NijeKraj) std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")" << std::endl;
			else if(sad==Status::KrajPoraz){
				std::cout << "Nagazili ste na minu" << std::endl;
				throw std::runtime_error("Igra zavrsena");
			}
			else if(sad==Status::KrajPobjeda){
				std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
				throw std::runtime_error("Igra zavrsena");
			}
		}
		catch(std::out_of_range izuzetak) {std::cout << izuzetak.what() << std::endl;}
		catch (std::logic_error izuzetak1){ std::cout << izuzetak1.what() << std::endl;}
	}
	else if(komanda==Komande::PomjeriDalje){
		
		try{
		Status sad=Idi(polja, x, y, p_x,p_y);
		if(sad==Status::NijeKraj) std::cout << "Tekuca pozicija igraca je ("<<x<<","<<y<<")" << std::endl;
		else if(sad==Status::KrajPoraz){
			std::cout << "Nagazili ste na minu" << std::endl;
			throw std::runtime_error("Igra zavrsena");
		}
		else if(sad==Status::KrajPobjeda){
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			throw std::runtime_error("Igra zavrsena");
		}
		}
		catch(std::out_of_range izuzetak) {std::cout << izuzetak.what() << std::endl;}
		catch(std::logic_error izuzetak1) {std::cout << izuzetak1.what() << std::endl;}
	}
	else if(komanda==Komande::Blokiraj) {
		try{
			BlokirajPolje(polja,p_x,p_y);
		}
		catch(std::domain_error izuzetak) {std::cout << izuzetak.what() << std::endl;}
	}
	else if(komanda==Komande::Deblokiraj){
		try{
			DeblokirajPolje(polja, p_x, p_y);
		}
		catch(std::domain_error iz){ std::cout << iz.what() << std::endl;}
	}
	else if(komanda==Komande::PrikaziOkolinu){
		try{
			for(auto i:PrikaziOkolinu(polja,x,y)){
				for(auto j: i) std::cout << j << " ";
				std::cout << std::endl;
			}
		}
		catch(std::domain_error jah) {std::cout << jah.what() << std::endl;}
	}
	else if(komanda==Komande::ZavrsiIgru){
		for(auto &i:polja){
			for(auto &j:i) j=Polje::Prazno;
		}
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda==Komande::KreirajIgru){
		std::cout << "Unesite broj polja: ";
		int a;
		std::cin>>a;
		std::cin.ignore(10000,'\n');
		std::vector<std::vector<int>> mi ;
		std::cout << "Unesite pozicije mina: ";
		std::string s;
		std::getline(std::cin,s);
		int b(0),c(0),indeks(0);
		while(s!="."){
			if(pokupi_tacku(s,indeks,b,c,a)) mi.push_back(std::vector<int>{b,c});
			else std::cout << "Greska, unesite ponovo!" << std::endl;
			std::getline(std::cin,s);
		}
		polja=KreirajIgru(a,mi);
		
	}
}
int main ()
{
	int x0(0),y0(0), x(0),y(0);
	Tabla polja(0,std::vector<Polje>(0));
	Komande komanda;
	KodoviGresaka greska;
	Smjerovi smjer;
	try{
	while(1){
		std::cout << "Unesite komandu: ";
		if(UnosKomande(komanda, smjer, x,y,greska)){
			IzvrsiKomandu(komanda, polja, x0, y0,smjer,x,y);
		}
		else PrijaviGresku(greska);
	}
	}
	catch(...) {std::cout << "Dovidjenja!";}
	return 0;
}