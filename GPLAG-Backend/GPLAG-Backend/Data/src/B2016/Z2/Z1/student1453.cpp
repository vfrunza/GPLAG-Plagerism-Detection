/*B 16/17, Zadaća 2, Zadatak 1
	
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};
enum class Smjerovi{
	GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};
enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	Polje polje_tabele;
	polje_tabele=Polje::Prazno;
	Tabla igra(n,std::vector<Polje>(n,polje_tabele)); //valja li ? hmm
	polje_tabele=Polje::Mina;
	for(int k=0;k<mine.size();k++){
		if(mine[k].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		int a(mine[k][0]), b(mine[k][1]);
		if(a<0 || a>=n || b<0 || b>=n) throw std::domain_error("Ilegalne pozicije mina"); // 7/7 at C9 bez ovoga
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==a && j==b) igra[i][j]=polje_tabele;

			}
		}
	}
	return igra;
		
	
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> matrica(3,std::vector<int>(3));
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()){ 
		std::string sx(std::to_string(x));
		std::string sy(std::to_string(y));
		throw std::domain_error(std::string("Polje (")+sx+std::string(",")+sy+std::string(") ne postoji"));
		
	}
	
	int a(0),b(0);
	for(int i=x-1;i<=x+1;i++){
		if(i<0){ 
			b=0;				//treba vidit kako upisuje u matricu kad je izvan opsega i sa lijeve i desne strane 
			a++;
			continue;
		}
		for(int j=y-1;j<=y+1;j++){
			if(j<0){ 
				if(b!=2) b++;
				else {
					b=0;
					a++;
			}
				continue;
			}
			int broj_mina(0);
			if(i-1>=0){
				if(polja[i-1][j]==Polje::Mina) broj_mina++;
				if(polja[i-1][j+1]==Polje::Mina) broj_mina++;
			}
			if(j-1>=0){
				if(polja[i][j-1]==Polje::Mina) broj_mina++;
				if(polja[i+1][j-1]==Polje::Mina) broj_mina++;
			} 
			if(j-1>=0 && i-1>=0) if(polja[i-1][j-1]==Polje::Mina) broj_mina++;
			if(polja[i][j+1]==Polje::Mina) broj_mina++;
			if(polja[i+1][j]==Polje::Mina) broj_mina++;
			if(polja[i+1][j+1]==Polje::Mina) broj_mina++;
			
			matrica[a][b]=broj_mina;
			if(b!=2) b++;
			else {
				b=0;
				a++;
			}
			
		}
	}
	
	return matrica;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()){ 
		std::string sx(std::to_string(x));
		std::string sy(std::to_string(y));
		throw std::domain_error(std::string("Polje (")+sx+std::string(",")+sy+std::string(") ne postoji"));
		
	}
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()){ 
		std::string sx(std::to_string(x));
		std::string sy(std::to_string(y));
		throw std::domain_error(std::string("Polje (")+sx+std::string(",")+sy+std::string(") ne postoji"));
		
	}
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int zapamti_x(x),zapamti_y(y);
	if(smjer==Smjerovi::GoreLijevo){
		x--;
		y--;
	}
	if(smjer==Smjerovi::GoreDesno){
		x--;
		y++;
	}
	if(smjer==Smjerovi::DoljeLijevo){
		x++;
		y--;
	}
	if(smjer==Smjerovi::DoljeDesno){
		x++;
		y++;
	}
	if(smjer==Smjerovi::Desno) y++;
	if(smjer==Smjerovi::Lijevo) y--;
	if(smjer==Smjerovi::Gore) x--;
	if(smjer==Smjerovi::Dolje) x++;
	if(x<0 || y<0 || x>polja.size() || y>polja[0].size()){ 
		x=zapamti_x;
		y=zapamti_y;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno ){ 
		x=zapamti_x;												//   vidit trebaju li ove
		y=zapamti_y;												// 	dvije linije koda
		throw std::logic_error("Blokirano polje");
	}
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	polja[x][y]=Polje::Posjeceno;
	
	bool pobjeda(true);
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje::Prazno){
				pobjeda=false;
				break;
			}
		}
	}
	if(pobjeda) return Status::KrajPobjeda;
	return Status::NijeKraj;
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	int zapamti_x(x), zapamti_y(y);
	x=novi_x;
	y=novi_y;
	if(x<0 || y<0 || x>polja.size() || y>polja[0].size()){ 
		x=zapamti_x;
		y=zapamti_y;
		throw std::out_of_range("Izlazak van igrace table");
	}
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno ){ 
		x=zapamti_x;
		y=zapamti_y;
		throw std::logic_error("Blokirano polje");
	}
	if(polja[x][y]==Polje::Mina){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	
	polja[x][y]=Polje::Posjeceno;
	
	bool pobjeda(true);
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje::Prazno){
				pobjeda=false;
				break;
			}
		}
	}
	if(pobjeda) return Status::KrajPobjeda;
	
	return Status::NijeKraj;
	
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string unos;
//	std::cin.ignore(1000, '\n')
	std::getline(std::cin,unos);
	if(unos[0]!='P' && unos[0]!='K' && unos[0]!='B' && unos[0]!='D' && unos[0]!='Z' && unos[0]!='K'){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	//P>
	if(unos[0]=='P' && unos[1]=='>'){
		if(unos[2]!=' ' && (unos[2]<'0' || unos[2]>'9')){
			greska=KodoviGresaka::NedostajeParametar;							//kad se unese P> 2   da li nedostaje parametar ili druga greska
			return false;
		}
		bool upisi_x(false);
		bool upisi_y(false);
		for(int i=2;i<unos.length();i++){
			if(unos[i]==' ') continue;
			if(unos[i]>='0'&& unos[i]<='9' && upisi_x==false){
				upisi_x=true;													//treba vidit za dvocifrene dimenzije
				x=unos[i]-'0';
				continue;
			}
			if(unos[i]>='0'&& unos[i]<='9'&& upisi_y==false){
				upisi_y=true;
				y=unos[i]-'0';
				continue;
			}
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(upisi_x==false || upisi_y==false){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda=Komande::PomjeriDalje;
		return true;
	}
	//P1
	if(unos[0]=='P' && unos[1]=='1'){
		if(unos[2]!='G' && unos[2]!='D'&& unos[2]!=' '){
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		for(int i=2;i<unos.length();i++){
			if(unos[i]==' ') continue;
			if(unos.substr(i,2)=="GL"){
				smjer=Smjerovi::GoreLijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			if(unos.substr(i,2)=="GD"){
				smjer=Smjerovi::GoreDesno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			if(unos.substr(i,3)=="DoD"){
				smjer=Smjerovi::DoljeDesno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			if(unos.substr(i,3)=="DoL"){
				smjer=Smjerovi::DoljeLijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			if(unos.substr(i,2)=="Do"){
				smjer=Smjerovi::Dolje;				// kad se unese Dol da ima suvisan parametar
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			
			if(unos[i]=='G'){
				smjer=Smjerovi::Gore;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			if(unos[i]=='D'){
				smjer=Smjerovi::Desno;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			if(unos[i]=='L'){
				smjer=Smjerovi::Lijevo;
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
	}
	//B
	if(unos[0]=='B'){
		if(unos[1]!=' ' && unos[1]<'0' && unos[1]>'9'){
			greska=KodoviGresaka::NedostajeParametar;							//kad se unese P> 2   da li nedostaje parametar ili druga greska
			return false;
		}
		bool upisi_x(false);
		bool upisi_y(false);
		int i;
		for(i=1;i<unos.length();i++){
			if(unos[i]==' ') continue;
			if(unos[i]>='0'&& unos[i]<='9' && upisi_x==false){
				upisi_x=true;													//treba vidit za dvocifrene dimenzije
				x=unos[i]-'0';
				continue;
			}
			if(unos[i]>='0'&& unos[i]<='9'&& upisi_y==false){
				upisi_y=true;
				y=unos[i]-'0';
				continue;
			}
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(upisi_x==false || upisi_y==false){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda=Komande::Blokiraj;
		return true;
	}
	//D
	if(unos[0]=='D'){
		if(unos[1]!=' ' && unos[1]<'0' && unos[1]>'9'){
			greska=KodoviGresaka::NedostajeParametar;							//kad se unese P> 2   da li nedostaje parametar ili druga greska
			return false;
		}
		bool upisi_x(false);
		bool upisi_y(false);
		for(int i=1;i<unos.length();i++){
			if(unos[i]==' ') continue;
			if(unos[i]>='0'&& unos[i]<='9' && upisi_x==false){
				upisi_x=true;													//treba vidit za dvocifrene dimenzije
				x=unos[i]-'0';
				continue;
			}
			if(unos[i]>='0'&& unos[i]<='9'&& upisi_y==false){
				upisi_y=true;
				y=unos[i]-'0';
				continue;
			}
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		if(upisi_x==false || upisi_y==false){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda=Komande::Deblokiraj;
		return true;
	}
	//PO Z K
	if(unos[0]=='P' && unos[1]=='O'){
		for(int i=2;i<unos.length();i++){
			if(unos[i]==' ') continue;
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::PrikaziOkolinu;
		return true;
	}
	if(unos[0]=='Z'){
		for(int i=1;i<unos.length();i++){
			if(unos[i]==' ') continue;
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::ZavrsiIgru;
		return true;
	}
	if(unos[0]=='K'){
		for(int i=1;i<unos.length();i++){
			if(unos[i]==' ') continue;
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::KreirajIgru;
		return true;
	}
	greska=KodoviGresaka::PogresnaKomanda;
	return false;
}

void PrijaviGresku(KodoviGresaka prijavi_gresku){
	if(prijavi_gresku==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	if(prijavi_gresku==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	if(prijavi_gresku==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
	if(prijavi_gresku==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==Komande::Blokiraj){ 
		BlokirajPolje(polja,x,y);
	}
	if(komanda==Komande::Deblokiraj){ 
		DeblokirajPolje(polja,x,y);
	}
	if(komanda==Komande::PomjeriDalje){ 
		try{
			Status status(Idi(polja,p_x,p_y,x,y));
			if(status==Status::KrajPobjeda){ 
				std::cout << "Bravo, obisli ste sva sigurna polja";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			if(status==Status::KrajPoraz){ 
				std::cout << "Nagazili ste na minu";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
				
			}
			std::cout<< "Tekuca pozicija igraca je (" << x<<","<<y<<")"<<std::endl;
		}
		catch(std::logic_error e){
			std::cout << e.what() << std::endl;
		}
	}
	if(komanda==Komande::PomjeriJednoMjesto){
		try{
			Status stanje(Idi(polja,x,y,p_smjer));
			if(stanje==Status::KrajPobjeda){ 
				std::cout << "Bravo, obisli ste sva sigurna polja";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}
			if(stanje==Status::KrajPoraz){ 
				std::cout << "Nagazili ste na minu";
				for(int i=0;i<polja.size();i++){
					for(int j=0;j<polja[i].size();j++){
						polja[i][j]=Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
				
			}
			std::cout << "Tekuca pozicija igraca je (" << x<<","<<y<<")"<<std::endl;
		}
		catch(std::logic_error e){
			std::cout << e.what();
		}
	}
	if(komanda==Komande::PrikaziOkolinu){ 
		std::vector<std::vector<int>> okolina(PrikaziOkolinu(polja,x,y));
		for(int i=0;i<okolina.size();i++){
			for(int j=0;j<okolina[i].size();j++){
				std::cout << okolina[i][j]<<" ";
			}
			std::cout << std::endl;
		}
	}
	if(komanda==Komande::ZavrsiIgru){ 
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	if(komanda==Komande::KreirajIgru){
		int n;
		std::cout << "Unesite broj polja: " ;
		std::cin >> n;
		
		std::cout << "Unesite pozicije mina: " ;
		std::string s;
		std::cin.ignore(10000,'\n');
		std::vector<std::vector<int>> v;
		int mina_x(0),mina_y(0), red_mat(0);
		bool tacan_unos(false);
		while(tacan_unos==false){
			while(true){
				mina_x=0;
				mina_y=0;
				tacan_unos=true;
				std::getline(std::cin,s);
				if(s=="."){
					tacan_unos=true;
					break;
				}
				
				if(s[0]!='('){
					
					tacan_unos=false;
					break;
				}
				if(s[1]<'0' || s[1]>'9'){ 
					
					tacan_unos=false;
					break;
				}
				int i;
				int jedinice(1);
				for(i=1;i<s.length();i++){
					
					
					if(s[i]<'0'||s[i]>'9') break;
					mina_x+=(s[i]-'0')*jedinice;
					jedinice*=10;
				}
				if(s[i]!=','){
					
					tacan_unos=false;
					break;
				}
				i++;
				if(s[i]<'0' || s[i]>'9'){ 
					tacan_unos=false;
					break;
				}
				jedinice=1;
				for(;i<s.length();i++){
					if(s[i]<'0'||s[i]>'9') break;
					mina_y+=(s[i]-'0')*jedinice;
					jedinice*=10;
				}
				if(s[i]!=')'){
					tacan_unos=false;
					break;
				}
				/*if(i!=s.length()){
					tacan_unos=false;
					break;
				}*/
				
				
				if(mina_x>=0 && mina_x<n&&mina_y>=0 && mina_y<n){ 
					v.resize(red_mat+1);
					v[red_mat].push_back(mina_x);
					v[red_mat].push_back(mina_y);
				}
				else{
					tacan_unos=false;
					break;
				}
				
				red_mat++;
			}
			if(tacan_unos==false)std::cout << "Greska, unesite ponovo!" << std::endl;
			
		}
		polja=KreirajIgru(n,v);
		
	}
	
}

int main (){
	
	try{
		int x(0),y(0),p_x(0),p_y(0);
		
		KodoviGresaka greska;
		
		Tabla polja;
		
		bool unos;
		do{
			std::cout << "Unesite komandu: ";
			Komande komanda;
			Smjerovi smjer;
			unos=UnosKomande(komanda,smjer,x,y,greska);
			if(unos==false){
				PrijaviGresku(greska);
			}
			IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
			
		}while(unos);
	}
	
	catch(std::domain_error e){
		std::cout << e.what();
	}
	catch(std::runtime_error e){
		std::cout << "Dovidjenja!" << std::endl;
	}
	return 0;
}