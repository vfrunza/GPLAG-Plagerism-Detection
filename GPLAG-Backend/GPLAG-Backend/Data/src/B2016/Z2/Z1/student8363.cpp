/*B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::string;
bool debug = true;
enum class Polje {
    Prazno,Posjeceno,Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
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
    PomjeriJednoMjesto ,PomjeriDalje , Blokiraj    , Deblokiraj,
    PrikaziOkolinu     ,ZavrsiIgru   , KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> mvInt;

void throwErrIf(Tabla polja,int x,int y) {
	string greska = "Polje ("+to_string(x)+","+to_string(y)+") ne postoji";
	if(polja.size()==0)throw std::domain_error(greska);
	if(x>=polja.size() || y>=polja.size() || x<0 || y<0)throw std::domain_error(greska);
}
Tabla KreirajIgru(int n,mvInt &mine) {
	Tabla tabla(n);
	for (int i = 0; i < n; i++) {
		tabla.at(i).resize(n);
		for (auto &e : tabla.at(i)) {
			e=Polje::Prazno;
		}
	}
	for (auto i : mine) {
		if(i.size()!=2)throw std::domain_error("Ilegalan format zadavanja mina");
		if(i.at(0)>=n || i.at(1)>=n || i.at(0)<0 || i.at(1)<0)throw std::domain_error("Ilegalne pozicije mina");
	}
	for (auto i : mine) {
		tabla.at(i.at(0)).at(i.at(1))=Polje::Mina;
	}
	return tabla;
}
int prebroj_mine(const Tabla &polja,int &&x,int &&y) {
	int broj_mina = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if(i+x<0 || i+x>=polja.size() || (!i && !j))continue;
			if(j+y<0 || j+y>=polja.at(0).size())continue;
			//cout<<"Pristupam tacki "<<i+x<<" "<<j+y<<" mina: "<<(polja.at(i+x).at(j+y)==Polje::Mina)<<endl;
			broj_mina+=(polja.at(i+x).at(j+y)==Polje::Mina);
		}
	}
	return broj_mina;
}
mvInt PrikaziOkolinu(const Tabla &polja,int x,int y) {
	throwErrIf(polja,x,y);
	mvInt izlaz;
	izlaz.resize(3);
	for (int i = 0; i < 3; i++) {
		izlaz.at(i).resize(3);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			//moguce da van table moraju biti sve 0
			izlaz.at(i).at(j)=prebroj_mine(polja,i-1+x,j-1+y);
		}
	}
	return izlaz;
}
void BlokirajPolje(Tabla &polja,int x, int y) {
	
	throwErrIf(polja,x,y);
	Polje &poz= polja.at(x).at(y);
	if(poz == Polje::Posjeceno)poz=Polje::BlokiranoPosjeceno;
	if(poz == Polje::Prazno)poz=Polje::BlokiranoPrazno;
	if(poz == Polje::Mina)poz=Polje::BlokiranoMina;
}
void DeblokirajPolje(Tabla &polja,int x,int y) {
	throwErrIf(polja,x,y);
	Polje &poz= polja.at(x).at(y);
	if(poz == Polje::BlokiranoPosjeceno)poz=Polje::Posjeceno;
	if(poz == Polje::BlokiranoPrazno)poz=Polje::Prazno;
	if(poz == Polje::BlokiranoMina)poz=Polje::Mina;

}
template <typename T>
int prebroj_u_matrici(Tabla polja,T a) {
	int c=0;
	for (auto i : polja) {
		for (auto e : i) {
			if(e==a)c++;
		}
	}
	return c;
}
Status Idi(Tabla &polja,int &x, int &y,int novi_x,int novi_y) {
	//rijesimo errore
	{
		/*for (int i = 0; i < polja.size(); i++) {
			for (int j = 0; j < polja.at(0).size(); j++) {
				if(polja.at(i).at(j)!=Polje::Prazno &&
				polja.at(i).at(j)!=Polje::Mina)cout<<
				"Na polju "<<i<<" "<<j<<" status je "<<static_cast<int>(polja.at(i).at(j))<<endl;
			}
		}*/
		if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja.at(0).size())
			throw std::out_of_range("Izlazak van igrace table\n");
		if(polja.at(novi_x).at(novi_y) == Polje::BlokiranoPosjeceno ||
		        polja.at(novi_x).at(novi_y) == Polje::BlokiranoPrazno ||
		        polja.at(novi_x).at(novi_y) == Polje::BlokiranoMina){
				throw std::logic_error("Blokirano polje\n");
		        }
	}
	int tmpx=x,tmpy=y;
	x=novi_x;
	y=novi_y;
	if(polja.at(x).at(y)==Polje::Mina)return Status::KrajPoraz;
	polja.at(tmpx).at(tmpy)=Polje::Posjeceno;
	bool pobjeda = true;
	for (auto i : polja) {
		for (auto e : i) {
			if(e==Polje::Prazno || e==Polje::BlokiranoPrazno) {
				pobjeda=false;
				break;
			}
		}
		if(pobjeda==false)break;
	}
	if(pobjeda) {
		return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
Status Idi(Tabla &polja,int &x, int &y, Smjerovi smjer) {
	int nx=0,ny=0;
	if(smjer==Smjerovi::Gore)					
	nx=-1;
	else if(smjer==Smjerovi::Lijevo)
	ny=-1;
	else if(smjer==Smjerovi::Desno)	
	ny=1;
	else if(smjer==Smjerovi::Dolje)	
	nx=1;
	else if(smjer==Smjerovi::GoreLijevo)		{
		nx=-1;
		ny=-1;
	} else if(smjer==Smjerovi::GoreDesno)			{
		nx=-1;
		ny=1;
	} else if(smjer==Smjerovi::DoljeDesno)		{
		nx=1;
		ny=1;
	} else if(smjer==Smjerovi::DoljeLijevo)		{
		nx=1;
		ny=-1;
	}
	return Idi(polja,x,y,nx+x,ny+y);

}
void PrijaviGresku(KodoviGresaka kod) {
	if(kod == KodoviGresaka::PogresnaKomanda)			cout<<"Nerazumljiva komanda!\n";
	else if(kod == KodoviGresaka::NedostajeParametar)	cout<<"Komanda trazi parametar koji nije naveden!\n";
	else if(kod == KodoviGresaka::SuvisanParametar)		cout<<"Zadan je suvisan parametar nakon komande!\n";
	else if(kod == KodoviGresaka::NeispravanParametar)	cout<<"Parametar komande nije ispravan!\n";
}
bool prazan_String(string s) {
	for (int i = 0; i < s.size(); i++)
		if(i!=' ')return false;
	return true;
}
void stripWspace(string &s) {
	int v = std::remove(s.begin(),s.end(),' ') - s.begin();
	s.resize(v);
}
int toInt(string s,int &poz,char terminating_char=' ') {
	if(poz>=s.size())throw std::domain_error("Poz izvan opsega s");
	int a=0;
	bool barem_jedan_broj = false;
	while (s[poz]!=terminating_char && poz<s.size()) {
		if(s[poz]>='0' && s[poz]<='9')barem_jedan_broj=true;
		a*=10;
		a+=s[poz]-'0';
		a++;
		poz++;
	}
	if(!barem_jedan_broj)throw std::domain_error("Nije bilo niti jednog broja u stringu");
	return a;
}
bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y, KodoviGresaka &greska) {
	string k;
	std::getline(cin,k,'\n');
	if(k.size()==0)return false;
	char ck[2];
	for (int i = 0; i < k.size(); i++) {
		if(k[i]!=' ') {
			ck[0]=k[i];
			if(i+1<k.size())
				ck[1]=k[i+1];
			break;
		}
	}
	//P1 P>
	if(ck[0]=='Z' || ck[0]=='K') {
		char tmp = ck[0];
		bool dobra=true;
		int c=0;
		for (int i = 0; i < k.size(); i++) {
			if(k[i]==tmp) {
				c++;
				if(c>1) {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
			if(k[i]!=tmp && k[i]!=' ') {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
		}
		if(ck[0]=='Z')
			komanda=Komande::ZavrsiIgru;
		else komanda=Komande::KreirajIgru;
		return true;
	} else if(ck[0]=='P' && ck[1]=='O') {
		for (int i = 0; i < k.size(); i++) {
			if(k[i]!=' ') {
				if(k[i]!='P' && k[i]!='O' && k[i]!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
			}
		}
		komanda=Komande::PrikaziOkolinu;
		return true;
	} else if(ck[0]=='B' || ck[0]=='D') {
		char tmp = ck[0];
		int c=0;
		for (int i = 0; i < k.size(); i++) {
			if(k[i]!=' ') {
				if(k[i]==tmp)c++;
				if(c>1) {
					greska=KodoviGresaka::PogresnaKomanda;
					return false;
				}
				if(k[i]!=tmp && k[i]!=' ' && (k[i]<'0' || k[i]>'9')) {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}
		}
		int poz=0;
		for (int i = 0 ; i < k.size(); i++) {
			if(k[i]!=' ' && k[i]!=tmp) {
				poz=i;
				break;
			}
		}
		int tx=0,ty=0;
		try {
			tx=toInt(k,poz);
			while (k[poz]==' ')poz++;
			ty=toInt(k,poz);
		} catch(...) {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(poz!=k.size())
			while (poz<k.size()) {
				if(k[poz]!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				poz++;
			}
		x=--tx;
		y=--ty;
		if(ck[0]=='D')komanda=Komande::Deblokiraj;
		else komanda=Komande::Blokiraj;
		
		return true;
	} else if(ck[0]=='P' && (ck[1]=='1' || ck[1]=='>')) {
		char tmp = ck[0], tmp1=ck[1];
		for (int i = 0; i < k.size()-1; i++) {
			if(k[i]==tmp && k[i+1]==tmp1) {
				if(i+2<k.size()) {
					if(k[i+2]!=' ') {
						greska=KodoviGresaka::PogresnaKomanda;
						return false;
					}
				}
			}
		}
		int poz=0;
		for (int i = 0; i < k.size(); i++) {
			if(k[i]!=' ') {
				if(k[i]=='P' && k[i+1]=='1') {
					string np1[]= {"DoD","DoL","GL","GD","Do","G","D","L"};
					Smjerovi tmpsm[]= {
						Smjerovi::DoljeDesno,
						Smjerovi::DoljeLijevo,
						Smjerovi::GoreLijevo,
						Smjerovi::GoreDesno,
						Smjerovi::Dolje,
						Smjerovi::Gore,
						Smjerovi::Desno,
						Smjerovi::Lijevo
					};
					i+=2;
					while (k[i]==' ' && i<k.size())i++;
					if(i<k.size()) {
						for (int j = 0; j < 8; j++) {
							bool jes = std::equal(k.begin()+i,k.begin()+np1[j].size()+i,np1[j].begin());
							if(jes) {
								i+=np1[j].size();
								i++;
								while (i<k.size()) {
									if(k[i]!=' ') {
										//cout<<k[i]<<endl;
										greska=KodoviGresaka::SuvisanParametar;
										return false;
									}
									i++;
								}
								smjer=tmpsm[j];
								komanda=Komande::PomjeriJednoMjesto;
								return true;
							}
						}
						greska=KodoviGresaka::NeispravanParametar;
						return false;
					} else {
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}

				}
				if(k[i]=='P' && k[i+1]=='>') {
					i+=2;
					if(i<k.size()) {
						for(int j=i; j<k.size(); j++) {
							if(k[j]!=' ' && (k[j]<'0' || k[j]>'9')) {
								greska=KodoviGresaka::NeispravanParametar;
								return false;
							}
						}
					}
				}
			}
		}
		for (int i = 0 ; i < k.size(); i++) {
			if(k[i]!=' ' && k[i]!=tmp) {
				if(k[i]==tmp1 && k[i-1]==tmp)continue;
				poz=i;
				break;
			}
		}
		int tx=x,ty=y;
		try {
			tx=toInt(k,poz);
			while (k[poz]==' ')poz++;
			ty = toInt(k,poz);
		} catch(...) {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(poz!=k.size())
			while (poz<k.size()) {
				if(k[poz]!=' ') {
					greska=KodoviGresaka::SuvisanParametar;
					return false;
				}
				poz++;
			}
		if(ck[1]=='>' ){
			komanda=Komande::PomjeriDalje;
			tx--;
			ty--;
			x=tx;
			y=ty;
		}
		else komanda=Komande::PomjeriJednoMjesto;
		return true;
	} else {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}

}
void IzvrsiKomandu(Komande komanda,Tabla &polja,int &x, int &y,Smjerovi p_smjer=Smjerovi::Gore ,int p_x = 0 ,int p_y = 0) {
	bool ispisi_poz=false;
	Status a=Status::NijeKraj;
	try {
		if(komanda==Komande::Blokiraj)BlokirajPolje(polja,p_x,p_y);
		else if(komanda==Komande::Deblokiraj)DeblokirajPolje(polja,p_x,p_y);
		else if(komanda==Komande::PomjeriDalje){ 
		a = Idi(polja,x,y,p_x,p_y);
		cout<<"Tekuca pozicija igraca je ("+to_string(x)+','+to_string(y)+")\n";
		}
		else if(komanda==Komande::PomjeriJednoMjesto){a = Idi(polja,x,y,p_smjer);
		cout<<"Tekuca pozicija igraca je ("+to_string(x)+','+to_string(y)+")\n";
		}
		else if(komanda==Komande::PrikaziOkolinu) {
			mvInt okolina = PrikaziOkolinu(polja,x,y);
			int i;
			for (i = 0; i < okolina.size(); i++) {
				for (int j = 0;j < okolina.at(0).size(); j++) {
					cout<<okolina.at(i).at(j)<<" ";
				}
				cout<<endl;
			}
			
		} else if(komanda==Komande::ZavrsiIgru) {
			for (int i = 0; i < polja.size(); i++) {
				for (int j = 0; j < polja.at(0).size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena.");
		} 
		else if(komanda==Komande::KreirajIgru) {
			cout<<"Unesite broj polja: ";
			int n;
			cin>>n;
			while (!cin) {
				cout<<"Greska unesite ponovo\n";
				cin.clear();
				cin.ignore(10000,'\n');
				cin>>n;
			}
			mvInt mine;
			cout<<"Unesite pozicije mina: ";
			string s;
			while (true) {
				if(cin.peek()=='\n')cin.ignore(1);
				std::getline(cin,s,'\n');
				if(s==".")break;
				else {
					int a,b,poz=0;
					try {
					while (s[poz]!='('){
						if(poz==s.size())throw std::domain_error("Pogresan unos");
						poz++;}
					poz++;
					
						a=toInt(s,poz,',');
						poz++;
						b=toInt(s,poz,')');
						poz++;
						while(poz<s.size()) {
							if(s[poz]!=' ' && s[poz]!='\n')poz++;
							throw std::domain_error("Neispavan unos");
						}
						std::vector<int> tmp;
						if(a>0)a--;
						if(b>0)b--;
						if(a<0 || a>=n || b<0 || b>=n)throw std::domain_error("Polje je van table");
						tmp.push_back(a);
						tmp.push_back(b);
						mine.push_back(tmp);
					} catch(...) {
						cout<<"Greska, unesite ponovo!\n";
					}
				}
			}
			polja = KreirajIgru(n,mine);
		} 
		else if(komanda==Komande::PrikaziOkolinu)PrikaziOkolinu(polja,x,y);

	} catch(std::domain_error e) {
		cout<<e.what()<<endl;
	} catch(std::out_of_range e) {
		cout<<e.what()<<endl;
	} catch(std::runtime_error e) {
		throw;
	} catch(std::logic_error e) {
		cout<<e.what();
	} catch(...) {
		cout<<"Uhvacen neobradjeni tip greske \n";
		throw;
	}
	if(a==Status::NijeKraj)ispisi_poz=true;
	else if(a==Status::KrajPoraz) {
		cout<<"Nagazili ste na minu"<<endl;
		IzvrsiKomandu(Komande::ZavrsiIgru,polja,x,y);
	} else {
		cout<<"Bravo obisli ste sva sigurna polja"<<endl;
		IzvrsiKomandu(Komande::ZavrsiIgru,polja,x,y);
	}
	//std::cout << std::endl;
}
int main () {
	Tabla a;
	//parametri iz unosa
	int x, y;
	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	//pozicija igraca
	int tx=0,ty=0;
	try {
		while (1) {
			cout<<"Unesite komandu: ";
			if(!UnosKomande(komanda,smjer,x,y,greska))
				PrijaviGresku(greska);
			else {
				IzvrsiKomandu(komanda,a,tx,ty,smjer,x,y);
			}

		}
	} catch(std::runtime_error e) {
		cout<<"Dovidjenja!"<<endl;
	}
	return 0;
}