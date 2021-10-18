#include <iostream>
#include <vector>
#include <stdexcept>
#include  <new>
#include <string>
#include <cmath>

enum class  Polje
{
    Prazno,Mina,Posjeceno,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};
enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};





typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru (int n,const std::vector<std::vector<int>>&mine)
{


	Polje prazno=Polje::Prazno;
	Polje mina=Polje::Mina;
	Tabla matrica (n,std::vector<Polje>(n));

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			matrica[i][j]=prazno;
		}
	}
	int broj_redova;
	int broj_kolona;
	broj_redova=mine.size();
	broj_kolona=mine[0].size();

	for (int i=0; i<broj_redova; i++) {
		broj_kolona=mine[i].size();

		if(broj_kolona!=2) {
			throw std::domain_error ("Ilegalan format zadavanja mina");
			break;
		}

	}
	for (int i=0; i<broj_redova; i++) {
		for (int j=0; j<broj_kolona; j++) {
			if (mine[i][j]>n) {
				throw std::domain_error ("Ilegalne pozicije mina");
				break;
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<broj_redova; k++) {

				if (mine[k][0]==i && mine[k][1]==j ) {
					matrica[i][j]=mina;
				}
			}

		}
	}

	return matrica;
}


std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja,int x,int y)
{
	std::vector<std::vector<int>> Broj_Mina (3,std::vector<int>(3)) ;
	int broj_redova(polja.size()+2);
	int broj_kolona(polja[0].size()+2);
	Polje prazno=Polje::Prazno;

	if (x>polja.size() || y>polja[0].size()) throw std::domain_error ("Polje () ne postoji");

	Tabla centar (broj_redova,std::vector<Polje>(broj_kolona)); // ako  mora svako polje biti u središtu podmatrice formata 3x3 - još nije sigurno !!!

	for (int i=0; i<broj_redova; i++) {
		for (int j=0; j<broj_kolona; j++) {
			if (i==0 || i+1==broj_redova) {
				for (int k=0; k<broj_kolona; k++) {
					centar[i][k]=prazno;
				}
			}

			if (j==0 || j+1==broj_redova) {
				for (int k=0; k<broj_redova; k++) {
					centar[k][j]=prazno;
				}
			}

			centar[i+1][j+1]=polja[i][j];
		}
	}

	int brojac_mina(0);
	std::vector<int> broj_mina ;

	// sad brojimo mine u okolini, pod pretpostvkom da podmatrica mora biti formata 3x3

	for (int i=1; i<broj_redova-1; i++) {
		for (int j=1; j<broj_kolona-1; j++) {
			broj_mina.resize(0);


			if (centar[i][j]!=prazno) brojac_mina--;

			for (int k=i-1; k<(i+3); k++) {
				for (int l=j-1; l<(j+3); l++) {
					if (centar[k][l]!=prazno) brojac_mina++;

				}
			}
			broj_mina.push_back(brojac_mina); // stavljamo u red


		}
		Broj_Mina.push_back(broj_mina); // stavljamo u matricu

	}



	return Broj_Mina;
}

void BlokirajPolje (Tabla &polja,int x,int y)
{
	if (x>polja.size() || y>polja[0].size()) throw std::domain_error ("Polje () ne postoji");

	if (polja[x][y]==Polje::Posjeceno)	polja[x][y]=Polje::BlokiranoPosjeceno;
	if (polja[x][y]==Polje::Prazno) 	polja[x][y]=Polje::BlokiranoPrazno;
	if (polja[x][y]==Polje::Mina)	 	polja[x][y]=Polje::BlokiranoMina;


}

void OdblokirajPolje (Tabla &polja,int x,int y)
{
	if (x>polja.size() || y>polja[0].size()) throw std::domain_error ("Polje () ne postoji");

	if (polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	if (polja[x][y]==Polje::BlokiranoPrazno)    polja[x][y]=Polje::Prazno;
	if (polja[x][y]==Polje::BlokiranoMina)      polja[x][y]=Polje::Mina;

}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int broj_redova (polja.size());
	int broj_kolona (polja[0].size());
	int novo_x;
	int novo_y;

	if (x<0 || y<0) throw std::out_of_range ("Izlazak van  igrace table");
	if (x+1>broj_redova) throw std::out_of_range ("Izlazak van igrace table");
	if (y+1>broj_kolona) throw std::out_of_range ("Izlazak van igrace table");


	if (smjer==Smjerovi::GoreLijevo) {
		novo_x=x-1;
		novo_y=y-1;
		polja[x][y]=Polje::Posjeceno;
	}

	if (smjer==Smjerovi::GoreDesno) {
		novo_x=x-1;
		novo_y=y+1;
		polja[x][y]=Polje::Posjeceno;
	}
	if (smjer==Smjerovi::DoljeLijevo) {
		novo_x=x+1;
		novo_y=y-1;
		polja[x][y]=Polje::Posjeceno;
	}

	if (smjer==Smjerovi::DoljeDesno) {
		novo_x=x+1;
		novo_y=y+1;
		polja[x][y]=Polje::Posjeceno;
	}

	if (smjer==Smjerovi::Lijevo) {
		novo_x=x;
		novo_y=y-1;
		polja[x][y]=Polje::Posjeceno;
	}
	if (smjer==Smjerovi::Desno) {
		novo_x=x;
		novo_y=y+1;
		polja[x][y]=Polje::Posjeceno;
	}

	if (polja[novo_x][novo_y]==Polje::BlokiranoPosjeceno ||polja[novo_x][novo_y]==Polje::BlokiranoPrazno || polja[novo_x][novo_y]==Polje::BlokiranoMina ) throw std::logic_error ("Blokirano polje");
	if (polja[novo_x][novo_y]==Polje::Mina) {
		for (int i=0; i<broj_redova; i++) {
			for (int j=0; j<broj_kolona; j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	int gore_x,dolje_x,lijevo_x,desno_x;
	int gore_y,dolje_y,lijevo_y,desno_y;

	gore_x=novo_x-1;
	gore_y=novo_y;
	dolje_x=novo_x+1;
	dolje_y=novo_y;
	lijevo_x=novo_x;
	lijevo_y=novo_y-1;
	desno_x=novo_x;
	desno_y=novo_y+1;

	if (polja[gore_x][gore_y]==Polje::BlokiranoPosjeceno && polja[dolje_x][dolje_y]==Polje::BlokiranoPosjeceno && polja[lijevo_x][lijevo_y]==Polje::BlokiranoPosjeceno && polja[desno_x][desno_y]==Polje::BlokiranoPosjeceno) {
		return Status::KrajPobjeda;
	}


	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	int broj_redova (polja.size());
	int broj_kolona (polja[0].size());


	if (x<0 || y<0) throw std::out_of_range ("Izlazak van  igrace table");
	if (x+1>broj_redova) throw std::out_of_range ("Izlazak van igrace table");
	if (y+1>broj_kolona) throw std::out_of_range ("Izlazak van igrace table");



	polja[x][y]=Polje::Posjeceno;

	if (polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina ) throw std::logic_error ("Blokirano polje");
	if (polja[novi_x][novi_y]==Polje::Mina) {
		for (int i=0; i<broj_redova; i++) {
			for (int j=0; j<broj_kolona; j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	int gore_x,dolje_x,lijevo_x,desno_x;
	int gore_y,dolje_y,lijevo_y,desno_y;

	gore_x=novi_x-1;
	gore_y=novi_y;
	dolje_x=novi_x+1;
	dolje_y=novi_y;
	lijevo_x=novi_x;
	lijevo_y=novi_y-1;
	desno_x=novi_x;
	desno_y=novi_y+1;

	if (polja[gore_x][gore_y]==Polje::BlokiranoPosjeceno && polja[dolje_x][dolje_y]==Polje::BlokiranoPosjeceno && polja[lijevo_x][lijevo_y]==Polje::BlokiranoPosjeceno && polja[desno_x][desno_y]==Polje::BlokiranoPosjeceno) {
		return Status::KrajPobjeda;
	}


	return Status::NijeKraj;

}

void PrijaviGresku (KodoviGresaka greska)
{
	if (greska==KodoviGresaka::NeispravanParametar) {
		std::cout << "Parametar komande nije ispravan!";
	}

	if (greska==KodoviGresaka::PogresnaKomanda) {
		std::cout << "Nerazumljiva komanda!";
	}
	if (greska==KodoviGresaka::NedostajeParametar) {
		std::cout << "Komanda trazi parametar koji nije naveden!";
	}
	if (greska==KodoviGresaka::SuvisanParametar) {
		std::cout << "Zadan je suvisan parametar nakon komande!";
	}

}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska)  // ne radi za unos komandi sa parametrima 
{
	std::vector<std::string> komande {{"P1"},{"P>"},{"D"},{"PO"},{"Z"},{"K"},{"B"}};
	std::vector<std::string> pomjeri {{"GD"},{"GL"},{"G"},{"D"},{"L"},{"DoD"},{"Do"},{"DoL"}};

	std::string kom;
	std::string dir;
	std::string pomocna;
	
	bool ispravan(true);
	
	for (;;) {
		std::getline(std::cin,kom);
		if (std::cin.peek()=='\n') break;
	} //komanda je unesena

	for (int i=0; i<kom.length(); i++) {
		if ((kom[i]<'A' || kom[i]>'z')&& kom[i]!='>' && kom[i]!='1') {
			ispravan=false;
			break;
		}
	}
	if (ispravan) {
		int q(0);
		int w(-1);
		// ubaciti u pomocnu bez razmaka ispred
		for (std::string::iterator it=kom.begin(); it!=kom.end(); it++) {
			w++;
			if (*it!=' ') {
				pomocna[q]=kom[w];
				q++;
			}
		}
// u pomocnoj se nalazi "P1DoD" "D34"

//ubaciti 34 u dir
		if (pomocna[0]==komande[0][0]) { // ako pocinje sa P u dir ubacujemo od 2
			for (int i=0; i<pomocna.length(); i++) {
				dir[i]=pomocna[i+2];
			}
		}

		if (pomocna[0]==komande[2][0] || pomocna[0]==komande[4][0] || pomocna[0]==komande[5][0] || pomocna[0]==komande[6][0]) {
			for (int i=0; i<pomocna.length(); i++) {
				dir[i]=pomocna[i+1];
			}
		}

		if (pomocna[0]==komande[0][0]) {
			if (pomocna[1]==komande[0][1])  komanda=Komande::PomjeriJednoMjesto;
			if (pomocna[1]==komande[1][1])  komanda=Komande::PomjeriDalje;
			if (pomocna[1]==komande[3][1])  komanda=Komande::PrikaziOkolinu;
		}

		if (pomocna[0]==komande[2][0]) komanda=Komande::Deblokiraj;
		if (pomocna[0]==komande[4][0]) komanda=Komande::ZavrsiIgru;
		if (pomocna[0]==komande[5][0]) komanda=Komande::KreirajIgru;
		if (pomocna[0]==komande[6][0]) komanda=Komande::Blokiraj;

		if (pomocna[0]==komande[0][0] && pomocna[1]==komande[0][1] || pomocna[0]==komande[1][0] && pomocna[1]==komande[1][1] || pomocna[0]==komande[2][0] || pomocna[0]==komande[6][0]) {
			if (pomocna[0]==komande[0][0] && pomocna[1]==komande[0][1] || pomocna[0]==komande[1][0] && pomocna[1]==komande[1][1]) {

				if (pomocna.length()<4) greska=KodoviGresaka::NedostajeParametar;
				if (pomocna.length()>4) greska=KodoviGresaka::SuvisanParametar;
			}

			if (pomocna[0]==komande[2][0] || pomocna[0]==komande[6][0]) {
				if (pomocna.length()<3) greska=KodoviGresaka::NedostajeParametar;
				if (pomocna.length()>3) greska=KodoviGresaka::SuvisanParametar;
			}

		}


// ako je P1
		if (dir[0]==pomjeri[6][0]) smjer=Smjerovi::Dolje;
		if (dir[0]==pomjeri[2][0]) smjer=Smjerovi::Gore;
		if (dir[0]==pomjeri[3][0]) smjer=Smjerovi::Desno;
		if (dir[0]==pomjeri[4][0]) smjer=Smjerovi::Lijevo;
		if (dir[0]==pomjeri[0][0] && dir[1]==pomjeri[0][1]) smjer=Smjerovi::GoreDesno;
		if (dir[0]==pomjeri[1][0] && dir[1]==pomjeri[1][1]) smjer=Smjerovi::GoreLijevo;
		if (dir[0]==pomjeri[5][0] && dir[1]==pomjeri[5][1] && dir[2]==pomjeri[5][2]) smjer=Smjerovi::DoljeDesno;
		if (dir[0]==pomjeri[7][0] && dir[1]==pomjeri[7][1] && dir[2]==pomjeri[7][2]) smjer=Smjerovi::DoljeLijevo;


		if (pomocna[0]==komande[1][0] && pomocna[1]==komande[1][1] || pomocna[0]==komande[2][0] || pomocna[0]==komande[6][0]) {
			x=dir[0];
			y=dir[1];
		}

	}

	else {
		greska=KodoviGresaka::PogresnaKomanda;
	}


	if (ispravan==true && greska!=KodoviGresaka::NedostajeParametar && greska!=KodoviGresaka::SuvisanParametar) return true;
	else
		return false;
}

void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
	int n;
	std::string unos;

	if (komanda==Komande::KreirajIgru) {
		std::cout << "Unesite broj polja";
		std::cin >> n;
		std::vector<std::vector<int>>mine(n,std::vector<int>(n));
		for (;;) {
			std::getline(std::cin,unos);
			if (std::cin.peek()=='.') break;

		}   // unosimo string do tačke
		int a(-1);
		int k(0);
		int r(0); // za stepene
		x=0;
		y=0;

		// petljom provjeriti da li je ispravan
		if (unos[0]=='(') {
			for (int i=1; i<unos.length(); i++) {
				a++;
				k++;
				if (unos[i]==',') break;
			}  // brojimo cifre za x

			for (int j=k; j>0; j--) {
				r++;
				x=x+pow(unos[j],r);     // dobili smo x
			}

			a=-1;
			r=0;

			k++; // zbog zareza

			for(int j=k; j<unos.length(); j++) {
				a++;
				if (unos[j]==')') break; // y ima a cifara
			}


			for (int j=(k+a); j>k; j--) {
				r++;
				y=y+pow(unos[j],r);
			}

		}
		polja=KreirajIgru(n,mine);
	}

	if (komanda==Komande::PomjeriJednoMjesto) {
		auto stat (Idi(polja,x,y,p_smjer));
		if (stat==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja";
		}

		if (stat==Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu";
			for (int i=0; i<polja.size(); i++) {
				for (int j=0; j<polja[0].size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
		}
		if (komanda==Komande::ZavrsiIgru) {
			for (int i=0; i<polja.size(); i++) {
				for (int j=0; j<polja[0].size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}

	}
	std::vector<std::vector<int>> Okolina(n,std::vector<int>(n)) ; // n ce biti deklarirano pri komandi kreiraj igru
	if (komanda==Komande::PrikaziOkolinu) {
		Okolina=PrikaziOkolinu(polja,x,y);
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				std::cout << Okolina[i][j] << " ";
			}
			std::cout << std::endl;
		}

		if (komanda==Komande::Blokiraj) {
			try {
				BlokirajPolje(polja,x,y);
			} catch (std::domain_error izuzetak) {
				std::cout << izuzetak.what() << std::endl;
			}
		}
	}

	if (komanda==Komande::Deblokiraj) {
		try {
			OdblokirajPolje(polja,x,y);
		} catch(std::domain_error izuzetak) {
			std::cout << izuzetak.what()<< std::endl;
		}
	}

	if (komanda==Komande::PomjeriDalje) Idi(polja,x,y,p_x,p_y);

}

int main ()
{
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	int x,y;
int p_x;
int p_y;
Tabla polja;
Smjerovi p_smjer;
std::cout << "Unesite komandu: ";
	for (;;)
	{
		try{
	UnosKomande(komanda,smjer,x,y,greska);
	
	if (UnosKomande) 
	{
		
		IzvrsiKomandu(komanda,  polja,  x,  y, p_smjer = Smjerovi::Gore, p_x=0 , p_y=0);
	}
	else (PrijaviGresku(greska));
		}
		
		catch(std::runtime_error kraj)
		{
			std::cout << kraj.what() << std::endl;
			std::cout << "Dovidjenja!";
			break;
		}
	
     }
	return 0;
}