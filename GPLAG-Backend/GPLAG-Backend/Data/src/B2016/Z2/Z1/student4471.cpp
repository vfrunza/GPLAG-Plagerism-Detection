//atovi Ivona Ivkovic

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {
	Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};

enum class Smjerovi{
	GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};

enum class Status {
	NijeKraj,KrajPoraz,KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar	
};

enum class Komande {
	PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru	
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	//n je stranica table !
	//kreiramo tablu velicine n*n inicijaliziranu na prazno
	std::vector<std::vector<Polje>> tabla(n,std::vector<Polje>(n,Polje::Prazno));
	
	//vector mine sadrzi nepoznat broj redova od kojih svaki red je sacinjen na nacin {x,y} gdje x predstavlja horiz poz mine a y vertiklanu
	//prvo cemo provjeriti da li je ovaj vector(mine) dobro formulisan
	
	for(int i=0;i<mine.size();i++){
		if(mine[i].size() != 2){
			throw std::domain_error("Ilegalan format zadavanja mina\n");
		}
		
		
		for(int j=0;j<mine[i].size();j++){
			if(mine[i][j] >=n || mine[i][j]<0)throw std::domain_error("Ilegalne pozicije mina\n");
		}
		
		
		
	}
	
	//sada inicijaliziramo vrijednosti u nasoj tabli na vrijednost mine ako se tu nalazi mina
	int xkord;
	int ykord;
	for(int i=0;i<mine.size();i++){
	
			xkord = mine[i][0];
			ykord = mine[i][1];
			tabla[xkord][ykord] = Polje::Mina;
		
	}
	
	
	
	return tabla;
}

int PrebrojOkolneElement(const Tabla &polja,int x,int y){
	
	int brojac = 0;
	
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			
			if(i==x && j==y){
				
				if(x-1>=0 && y-1>=0 && polja[x-1][y-1] == Polje::Mina)brojac++;
				if(x-1>=0 && y>=0 && polja[x-1][y] == Polje::Mina)brojac++;
				if(x-1>=0 && y+1<polja.size() && polja[x-1][y+1] == Polje::Mina)brojac++;
				if(x>=0 && y-1>=0 && polja[x][y-1] == Polje::Mina)brojac++;
				if(x>=0 && y+1<polja.size() && polja[x][y+1] == Polje::Mina)brojac++;
				if(x+1<polja.size() && y-1>=0 && polja[x+1][y-1] == Polje::Mina)brojac++;
				if(x+1<polja.size() && y>=0 && polja[x+1][y] == Polje::Mina)brojac++;
				if(x+1<polja.size() && y+1<polja.size() && polja[x+1][y+1] == Polje::Mina)brojac++;
				
				break;
			}
				
		}
		
	}
	
	return brojac;
	
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y){
	
	//prvo cemo provjeriti da li se polje (x,y) nalazi u okviru table za igru
	//Tabla polja je nasa tabla za igru
	
	int vel_table = polja.size();
	std::string s = "Polje (";
	s += std::to_string(x) + "," +std::to_string(y) + ") ne postoji\n"; 
	if((x >=vel_table || y>=vel_table) || (x < 0 || y < 0) )throw std::domain_error(s);
	
	
	//sada trebamo vratiti matricu formata 3*3 koja predstavlja okolinu tacke x y
	std::vector<std::vector<int>> v(3,std::vector<int>(3,0));
	
	for(int i=0;i<vel_table;i++){
		for(int j=0;j<vel_table;j++){
			
			if(i==x && j==y){
				//prvi element dijagonalno
				if(x-1>=0 && y-1>=0){
					
				
					v[0][0] = PrebrojOkolneElement(polja,x-1,y-1);
				}
				//element iznad x y
				if(x-1>=0 && y>=0){
					
					v[0][1] = PrebrojOkolneElement(polja,x-1,y);
				}
				
				if(x-1>=0 && y+1<vel_table){
					
					v[0][2] = PrebrojOkolneElement(polja,x-1,y+1);
				}
				
				if(x>=0 && y-1>=0){
					
					v[1][0] = PrebrojOkolneElement(polja,x,y-1);
				}
				
				if(x>=0 && y>=0){
					
					v[1][1] = PrebrojOkolneElement(polja,x,y);
				}
				
				if(x>=0 && y+1<vel_table){
					
					v[1][2] = PrebrojOkolneElement(polja,x,y+1);
				}
				
				if(x+1<vel_table && y-1>=0){
					
					v[2][0] = PrebrojOkolneElement(polja,x+1,y-1);
				}
				
				if(x+1<vel_table && y>=0){
					
					v[2][1] = PrebrojOkolneElement(polja,x+1,y);
				}
				
				if(x+1<vel_table && y+1<vel_table){
					
					v[2][2] = PrebrojOkolneElement(polja,x+1,y+1);
				}
				
				
				return v;
			}
			
		}
	}
	

	
	return v;
	
}

void BlokirajPolje(Tabla &polja,int x,int y){
	
	//prvo cemo provjeriti da li se (x,y) nalazi u dozvoljenom opsegu !
	int vel_table = polja.size();
	std::string s = "Polje (";
	s += std::to_string(x) + "," +std::to_string(y) + ") ne postoji\n"; 
	if((x >=vel_table || y>=vel_table) || (x < 0 || y < 0) )throw std::domain_error(s);
	
	//std::cout<<"U funckiji blokiraj kordinate su: "<<x<<" "<<y<<std::endl;
	
	if(polja[x][y] == Polje::Prazno){
		polja[x][y] =Polje::BlokiranoPrazno;
		//std::cout<<"Blokirano polje trebalo bi ispisati 3:  "<<int(polja[x][y])<<std::endl;
	}else if(polja[x][y] == Polje::Posjeceno){
		polja[x][y] = Polje::BlokiranoPosjeceno;
	}else if(polja[x][y] == Polje::Mina){
		polja[x][y] = Polje::BlokiranoMina;
	}
	
	//ako je polje bilo vec blokirano fja nece uraditi nista!
}

void DeblokirajPolje(Tabla &polja,int x,int y){
	
	int vel_table = polja.size();
	std::string s = "Polje (";
	s += std::to_string(x) + "," +std::to_string(y) + ") ne postoji\n"; 
	if((x >=vel_table || y>=vel_table) || (x < 0 || y < 0) )throw std::domain_error(s);
	
	if(polja[x][y] == Polje::BlokiranoPrazno){
		polja[x][y] =  Polje::Prazno;
	}else if(polja[x][y] == Polje::BlokiranoPosjeceno){
		polja[x][y] =  Polje::Posjeceno;
		
	}else if(polja[x][y] == Polje::BlokiranoMina){
		polja[x][y] =  Polje::Mina;
	}
	
	//ako je polje vec deblokirano fja nece uraditi nista 
}


Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	//x,y predstavljaju trenutnu poziciju igraca
	
	int vel_table = polja.size();
	int x_pom(0),y_pom(0);
	
	if(smjer == Smjerovi::GoreLijevo){
		x_pom = -1;
		y_pom = -1;
	}else if(smjer == Smjerovi::Gore){
		x_pom = -1;
		y_pom = 0;
	}else if(smjer == Smjerovi::GoreDesno){
		x_pom = -1;
		y_pom = 1;
	}else if(smjer == Smjerovi::Desno){
		x_pom = 0;
		y_pom = 1;
	}else if(smjer == Smjerovi::DoljeDesno){
		x_pom = 1;
		y_pom = 1;
	}else if(smjer == Smjerovi::Dolje){
		x_pom = 1;
		y_pom = 0;
	}else if(smjer == Smjerovi::DoljeLijevo){
		x_pom = 1;
		y_pom = -1;
	}else if(smjer == Smjerovi::Lijevo){
		x_pom = 0;
		y_pom = -1;
	}
	
//	std::cout<<"VELICINA TABLE JE "<<vel_table<<"A X Y: "<<	x<<" "<<y<<"A x_p y_p :"<<x_pom<<" "<<y_pom<<std::endl;
	
	if((x + x_pom>=vel_table || x + x_pom<0) || (y + y_pom>=vel_table || y + y_pom<0) )throw std::out_of_range("Izlazak van igrace table");
	//sada provjeravamo da li je polje blokirano gdje se hocemo pomjeriti 
	if(int(polja[x+x_pom][y+y_pom]) >=3)throw std::logic_error("Blokirano polje");
	
	
	x = x+x_pom;
	y = y+y_pom;
	
	//ako smo zgazili na minu cistimo tablu te vracamo stats::KrajPoraz
	if(polja[x][y] == Polje::Mina){
		for(int i=0;i<vel_table;i++){
			for(int j=0;j<vel_table;j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		
		return Status::KrajPoraz;
	}
	
	//ako se nista od gornjeg nije desilo pomjeramo igraca u zeljenom smjeruu te oznacavamo polje na kojem smo bili sa Posjeceno
	polja[x-x_pom][y-y_pom] = Polje::Posjeceno;
	
	//u slucaju da je igrac posjetio zadnje polje koje koje nema mina vracamo status::KrajPobjeda
	
	int brojac_mina = 0;
	for(int i=0;i<vel_table;i++){
			for(int j=0;j<vel_table;j++){
				if(polja[i][j] == Polje::Mina)brojac_mina++;
			}
		}
	
	if(brojac_mina==0)return Status::KrajPobjeda;
	return Status::NijeKraj;
}



Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y){
	
	int vel_table = polja.size();
	//da li je ipsravna nova lokacija ?
	if(novi_x<0 || novi_x>=vel_table || novi_y<0 || novi_y>=vel_table)throw std::out_of_range("Izlazak van igrace table");
	//sada provjeramo da li je polje blokirano gdje se hocemo provjeriti !
	if(int(polja[novi_x][novi_y])>=3)throw std::logic_error("Blokirano polje");                   //ovdje bilo u uglastim novi_x novi_y
	
	
	
	
	x = novi_x;
	y = novi_y;
	
	//ako smo zgazili na minu
	if(polja[x][y] == Polje::Mina){
		for(int i=0;i<vel_table;i++){
			for(int j=0;j<vel_table;j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	
	//ako se nista nije desilo od ovog gore pomjeramo igraca na zeljenu poziciju i oznacamo proslo polje kao posjeceno
	polja[x-novi_x][y-novi_y] = Polje::Posjeceno;
	
	//OVDJE ZA KRAJ IGRE NIJE DOBRO ODRADJENO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11
	
	int brojac_mina = 0;
	for(int i=0;i<vel_table;i++){
		for(int j=0;j<vel_table;j++){
			if(polja[i][j] == Polje::Mina)brojac_mina++;
		}
	}
	
	if(brojac_mina==0)return Status::KrajPobjeda;
	return Status::NijeKraj;
	
}




void PrijaviGresku(KodoviGresaka greska){
	
	if(greska == KodoviGresaka::PogresnaKomanda)std::cout<<"Nerazumljiva komanda!\n";
	else if(greska == KodoviGresaka::NedostajeParametar)std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	else  if(greska == KodoviGresaka::NeispravanParametar)std::cout<<"Parametar komande nije ispravan!\n";
	else if(greska == KodoviGresaka::SuvisanParametar)std::cout<<"Zadan je suvisan parametar nakon komande!\n";
}



bool jeliBroj(char c){
	if(c>= '0' && c<='9')return true;
	return false;
}



bool jeliIspravanString(std::string s){
	
	int i=0;
	int brojac1 = 0;
	int brojac2 = 0;
	int brojac3 = 0;
	int brojac4 = 0;
	
	while(i != s.length() && s[i]==' '){
		i++;
		if(s[i] == s.length())break;
	}
	if(i == s.length() || s[i] != '(')return false;
	i = 0;
	while(i != s.length()){
		
		if(s[i] == '('){
			brojac1++;
		}else if(s[i] == ')'){
			brojac2++;
		}else if(s[i] == ','){
			brojac3++;
		}else if(jeliBroj(s[i])){
			brojac4++;
			while(jeliBroj(s[i]))i++;
			i--;
		}
		
		i++;
	}
	
	i=0;
	while(i != s.length()){
		if(s[i] == ')'){
			i++;
			while(i != s.length()){
				if(s[i] != ' ')return false;
				i++;
				if(i == s.length())break;
			}
		}
		
		i++;
		if(i>=s.length())break;
	}
	if(brojac1 != 1 || brojac2 != 1 || brojac3!= 1 || brojac4 != 2 )return false;
	return true;
}

std::vector<std::vector<int>>UnosMina(int n){
	
	std::string s;
	std::vector<std::vector<int>>mine;
	
	std::cout<<"Unesite pozicije mina: ";
	int duzina = 0;
	std::cin.ignore(10,'\n');
	
	while(1){
		//std::cin>>s;
		std::getline(std::cin,s);                                           //PREPRAVLJENO OVDJE NA GETLINE !
		if(s == ".")break;
		
		if(jeliIspravanString(s) == false){
			std::cout<<"Greska, unesite ponovo!\n";
		}else if(jeliIspravanString(s)==true){
			int broj1=-1,broj2=-1;
			
			int i=0;
			int predznak = 1;
			while(i != s.length() && s[i] != ','){
				if(jeliBroj(s[i])){
					if(i-1 >=0 && s[i-1] == '-')predznak = -1;
					int j=i;
					while(jeliBroj(s[i]))i++;
					
					broj1 = std::stoi(s.substr(j,i-1));
					broj1*=predznak;
					break;
				}
				i++;
			}
			
			predznak = 1;
			while(i != s.length()){
				if(jeliBroj(s[i])){
					if(i-1 >=0 && s[i-1] == '-')predznak = -1;
					int j=i;
					while(jeliBroj(s[i]))i++;
					
					broj2 = std::stoi(s.substr(j,i-1)); //begativne brojeve provjeriti 
					broj2*=predznak;
				}
				i++;
			}
			
			if((broj1>=0 && broj1<n) && (broj2>=0 && broj2<n) ){
			duzina++;
			mine.resize(duzina);
			mine[duzina-1].push_back(broj1);
			mine[duzina-1].push_back(broj2);
			}else std::cout<<"Greska, unesite ponovo!\n";
		}
		s.clear();
	}
	
	//std::cin.ignore(2,'.');
	/*std::cout<<std::endl;
	for(auto &red:mine){
		for(auto &i:red){
			std::cout<<i<<" ";
		}
		std::cout<<std::endl;
	}*/
	
	return mine;
}





std::string izbrisi_razmake(std::string s){
	
	int duzina = s.length();
	
	for(int i=0;i<duzina;i++){
	
		if(s[i] == ' '){
			if( i != 0 && jeliBroj(s[i-1])==true && i+1!=duzina && jeliBroj(s[i+1])==true ){
				continue;
			}else {
			s.erase(s.begin()+i);
			i--;
			duzina--;	
			}
			
		}
	}
	
	return s;
} 

bool razmak_izmedju_kom_par(std::string s){
	
	int j=0;
	while(j!= s.length() && s[j]==' ')j++;

		while(j != s.length() && s[j]!= ' ')j++;
		if(j != s.length())return true;
		return false;

}


bool UnosKomande(Komande &komanda,Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska){
	
	std::vector<std::string> dozvoljeni_komande {"P1GL","P1G","P1GD","P1D","P1DoD","P1Do","P1DoL","P1L"};
	
	
	//sada unosimo sa tastature
	
	std::string s;
	std::getline(std::cin,s);
	
	
	bool imali_razmaka = razmak_izmedju_kom_par(s);
	s = izbrisi_razmake(s);
	int vel = s.length();
	
	//ako je neko unio samo enter !
	if(vel==0){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	
	if(s[0] != 'P' && s[0] != 'B' && s[0] != 'D' && s[0] != 'Z' && s[0] != 'K'){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	//prvo za slova PO,Z,K
	
	if(s == "PO"){
		komanda = Komande::PrikaziOkolinu;
		return true;
	}else if(s == "Z"){
		komanda = Komande::ZavrsiIgru;
		return true;
	}else if(s == "K"){
		komanda = Komande::KreirajIgru;
		return true;
	}else if(s=="B"){
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}else if(s=="D"){
		greska = KodoviGresaka::NedostajeParametar;
		return false;
	}else if(vel==1){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}else if(s[0] == 'Z' || s[0] == 'K'){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}else if(s[0]=='P' && s[1] == 'O'){
		greska = KodoviGresaka::SuvisanParametar;
		return false;
	}else if(s[0] == 'D' || s[0] == 'B'){
		if(imali_razmaka == false){
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		
		if(jeliBroj(s[1]) == false && imali_razmaka==false){
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		int j=1;
		while(j!= s.length()){
			if(s[j] != ' ' && jeliBroj(s[j])==false){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			j++;
		}
		
		//jos test da li imaju dva broja
		int brojac = 0;
		j=1;
		
		while(j != s.length()){
			if(jeliBroj(s[j])){
				brojac++;
				while(jeliBroj(s[j]) && j!= s.length()){j++;if(j==s.length())break;}
				if(j==s.length())break;
			}
			j++;
		}
		
		if(brojac<2){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		//ako smo prosli testove ove znaci da je komanda ispravna pa je unosimo
		if(s[0] == 'D'){
		komanda = Komande::Deblokiraj;
		}else komanda = Komande::Blokiraj;
		
		x = s[1] -48; //pretvaramo iz asci u brojeve
		y = s[s.length()-1] - 48;
		return true;
	
		
	}else if(s[0] == 'P' && s[1]=='>'){
		
		
		
		if(s.length()<=3){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		if(imali_razmaka == false){
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		
		int j=2;
		while(j!= s.length()){
			if(s[j] != ' ' && jeliBroj(s[j])==false){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			j++;
		}
		
		//jos test da li imaju dva broja
		int brojac = 0;
		j=2;
		
		while(j != s.length()){
			if(jeliBroj(s[j])){
				brojac++;
				while(jeliBroj(s[j]) && j!= s.length()){j++;if(j==s.length())break;}
				if(j==s.length())break;
			}
			j++;
		}
		
		if(brojac<2){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		//ako smo prosli testove ove znaci da je komanda ispravna pa je unosimo
		
		komanda = Komande::PomjeriDalje;
		
		x = s[2] -48; //pretvaramo iz asci u brojeve
		y = s[s.length()-1] - 48;
//		std::cout<<x<<"     "<<y<<std::endl;
		return true;

	}else {
		//ovo je slucaj SA P1                       ///DA LI TREBA UPISATI U komande i komandu pomjeriJednoMjesto
		if(s[0] == 'P' && s[1] != '1'){
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		
		if(s.length()<3){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(imali_razmaka == false){
			greska = KodoviGresaka::PogresnaKomanda;
			return false;
		}
		
		if(imali_razmaka == true && s[2] != 'G' && s[2] != 'D' && s[2] != 'L'){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		int indeks = -1;
		for(int i=0;i<8;i++){
			if(s==dozvoljeni_komande[i]){
				indeks = i;
			//	std::cout<<"Najden indeks: "<<i<<std::endl;
				break;
			}
		}
		
		
	//	std::cout<<"|"<<s<<"|"<<std::endl;																												//mala provjera ispisa ovdje !!
		if(indeks==8 || indeks == -1){
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		//P1GL","P1G","P1GD","P1D","P1DoD","P1Do","P1DoL","P1L"
		
		switch(indeks){
			case 0: {smjer = Smjerovi::GoreLijevo; komanda = Komande::PomjeriJednoMjesto;return true;}
			case 1: {smjer = Smjerovi::Gore;komanda = Komande::PomjeriJednoMjesto;return true;}
			case 2: {smjer = Smjerovi::GoreDesno;komanda = Komande::PomjeriJednoMjesto;return true;}
			case 3: {smjer = Smjerovi::Desno;komanda = Komande::PomjeriJednoMjesto;return true;}
			case 4: {smjer = Smjerovi::DoljeDesno;komanda = Komande::PomjeriJednoMjesto; return true;}
			case 5: {smjer = Smjerovi::Dolje;komanda = Komande::PomjeriJednoMjesto; return true;}
			case 6: {smjer = Smjerovi::DoljeLijevo;komanda = Komande::PomjeriJednoMjesto; return true;}
			case 7: {smjer = Smjerovi::Lijevo;komanda = Komande::PomjeriJednoMjesto; return true;}
		}
		//return true;
	}

	return false;
}


void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
	if(komanda == Komande::PomjeriJednoMjesto){
		
		try{
			Status rezultat = Idi(polja,x,y,p_smjer);
			if(rezultat == Status::KrajPoraz){
				std::cout<<"Nagazili ste na minu\n";
				
				//sada izvrasvamo zavrsi igru !
				for(auto &red : polja){
					for(auto &i: red){
						i = Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}else if(rezultat == Status::KrajPobjeda){
				std::cout<<"Bravo, obisli ste sva sigurna polja\n";
				
				//sada izvrasvamo zavrsi igru !
				for(auto &red : polja){
					for(auto &i: red){
						i = Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
				
			}else{
				std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			}
		
		}catch(std::out_of_range temp){
			std::cout<<temp.what()<<std::endl;
		}catch(std::logic_error temp){
			std::cout<<temp.what()<<std::endl;
		}catch(std::runtime_error temp){
			throw;
		}
		
	}else if(komanda == Komande::PomjeriDalje){
		
		try{
			Status rezultat = Idi(polja,x,y,x,y);                                  //ovdje druga dva parametra p_x i p_y
			if(rezultat == Status::KrajPoraz){
				std::cout<<"Nagazili ste na minu\n";
				
				//sada izvrasvamo zavrsi igru !
				for(auto &red : polja){
					for(auto &i: red){
						i = Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");
			}else if(rezultat == Status::KrajPobjeda){
				std::cout<<"Bravo, obisli ste sva sigurna polja\n";
				
				//sada izvrasvamo zavrsi igru !
				for(auto &red : polja){
					for(auto &i: red){
						i = Polje::Prazno;
					}
				}
				throw std::runtime_error("Igra zavrsena");                               //DA LI TREBA ISPISATI OVDJE dovidjena !!
				
			}else{
				std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			}
		
		}catch(std::out_of_range temp){
			std::cout<<temp.what()<<std::endl;
		}catch(std::logic_error temp){
			std::cout<<temp.what()<<std::endl;
		}catch(std::runtime_error temp){
			throw;
		}
	
		
	}else if(komanda == Komande::Blokiraj){
		
		try{
			BlokirajPolje(polja,x,y);
		}catch(std::domain_error temp){
			std::cout<<temp.what();
		}
		
	}else if(komanda==Komande::Deblokiraj){
		try{
			DeblokirajPolje(polja,x,y);
		}catch(std::domain_error temp){
			std::cout<<temp.what();
		}
	}else if(komanda == Komande::PrikaziOkolinu){
		
		try{
			std::vector<std::vector<int>> v = PrikaziOkolinu(polja,x,y);
			
			for(auto &red : v){
				for(auto &i: red){
					std::cout<<i<<" ";
				}
				std::cout<<std::endl;
			}
		}catch(std::domain_error temp){
			std::cout<<temp.what()<<std::endl;
		}
	}else if(komanda == Komande::ZavrsiIgru){
		//sada izvrasvamo zavrsi igru !
				for(auto &red : polja){
					for(auto &i: red){
						i = Polje::Prazno;
					}
				}
			//	std::cout<<"Dovidjenja!";
				throw std::runtime_error("Igra zavrsena");
	}else if(komanda == Komande::KreirajIgru){
		
		std::cout<<"Unesite broj polja: ";
		int n;
		std::cin>>n;
		std::vector<std::vector<int>> mine = UnosMina(n);
		polja = KreirajIgru(n,mine);
		
		/*
		for(auto &red : polja){
					for(auto &i: red){
						std::cout<<int(i)<<" ";
					}
					std::cout<<std::endl;
				}
		
			std::cout<<std::endl;
			for(auto &red : mine){
					for(auto &i: red){
						std::cout<<i<<" ";
					}
					std::cout<<std::endl;
				}
			*/
	}
	
	
}




int main ()
{
	

	
	Komande komanda;
	Smjerovi smjer ;
	int x(0),y(0),p_x(0),p_y(0);
	KodoviGresaka greska;
	Tabla polja;
	
	while(true){
	
		std::cout<<"Unesite komandu: ";
		
		if(std::cin.peek()== '\n'){
			std::cin.ignore(1,'\n');
			
		}
		bool rez = UnosKomande(komanda,smjer, x, y,greska);
		if(rez == true){
			try{
				IzvrsiKomandu(komanda,polja,x,y,smjer,p_x,p_y);
			}catch(std::domain_error temp){
				std::cout<<temp.what()<<std::endl;
				std::cout<<"Dovidjenja!";
				return 0;
			}catch(std::runtime_error temp){
			//	std::cout<<temp.what()<<std::endl;
				std::cout<<"Dovidjenja!\n";
				return 0;
			}catch(std::logic_error temp){
				std::cout<<temp.what()<<std::endl;
			}
		}else {
			PrijaviGresku(greska);
		}
		
		
	}
	return 0;
}


/*
void ispisiTablu(std::vector<std::vector<Polje>> polja){
   for(int i = 0; i < polja.size(); i++) {
          for(int j = 0; j < polja[i].size(); j++) std::cout << int(polja[i][j]) << " ";
          std::cout << std::endl;
        }
}

int main(){
	
//AT14 (zamger) - funkcija idi sa 4 parametra 
    int x = 0, y = 0;
    std::vector<std::vector<int>> mine = {{0,2}, {1,0}, {1,2}, {2,1}, {2,2}};
    std::vector<std::vector<Polje>> tabla = KreirajIgru(3, mine);
    Idi(tabla, x, y, Smjerovi::Desno);
    Idi(tabla, x, y, Smjerovi::Dolje);
    ispisiTablu(tabla);
    if(x == 1 && y == 1) std::cout << "OK" << std::endl;
      else  std::cout << "NOK" << std::endl;

	
	
}
*/































































































