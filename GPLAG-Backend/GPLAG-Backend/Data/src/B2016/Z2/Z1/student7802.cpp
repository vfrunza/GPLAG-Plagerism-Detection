/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
 
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};


typedef std::vector<std::vector<Polje>> Tabla;



void PrijaviGresku(KodoviGresaka x){
	
	if(x==KodoviGresaka::PogresnaKomanda) cout<<"Nerazumljiva komanda!"<<endl;
	else if(x==KodoviGresaka::NedostajeParametar) cout<<"Komanda trazi parametar koji nije naveden!"<<endl;
	else if(x==KodoviGresaka::SuvisanParametar) cout<<"Zadan je suvisan parametar nakon komande!"<<endl;
	else if(x==KodoviGresaka::NeispravanParametar) cout<<"Parametar komande nije ispravan!"<<endl;
	
}

void OcistiTablu(Tabla &polja){
	for(int i(0);i<polja.size();i++)
		for(int j(0);j<polja[i].size();j++)
			polja[i][j]=Polje::Prazno;
}


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for(int i(0);i<mine.size();i++)
	if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	
	for(int i(0);i<mine.size();i++)
		for(int j(0);j<mine.at(i).size();j++)
			if(mine.at(i).at(j)>=n || mine.at(i).at(j)<0) throw std::domain_error("Ilegalne pozicije mina");
	Tabla tabla(n);
	for(int i(0);i<n;i++)
		tabla[i].resize(n);
	
	for(int i(0);i<mine.size();i++){
	for(int k(0);k<n;k++)
		for(int j(0);j<n;j++){
			std::vector<int> sklj{k,j};
			if(sklj==mine[i]) {
				tabla[k][j]=Polje::Mina;
			}
		
		}}
	for(int k(0);k<n;k++)
		for(int j(0);j<n;j++){
			if(tabla[k][j]!=Polje::Mina) {
				tabla[k][j]=Polje::Prazno;
			}
		
		}
	return tabla;
} 
int BrojMina(int x, int y,const Tabla &polja){
	int br(0);
	int brojac(0);
		for(int i(x-1);brojac<3;i++){
			int brojac1(0);
			for(int j(y-1);brojac1<3;j++){
			if(i==x && j==y){}
			else{
				if(i<0 || j<0 || i>=polja.size() || j>=polja[i].size()){}
				else if(polja[i][j]==Polje::Mina){br++;}
				else{}
			}
			brojac1++;
			}
		brojac++;
		}
	return br;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> mat(3,std::vector<int> (3));
		if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0) {
			
			int h(x);
			int m(y);
			string iks;
			string ipsilon;
			while(h!=0){
				iks.push_back(h%10 + '0');
				h=h/10;
			}
			while(m!=0){
				ipsilon.push_back(m%10 + '0');
			
				m=m/10;
			}
			
			string s;
			string a{"Polje ("};
			string b{","};
			string c{") ne postoji"};
			s=a+iks+b+ipsilon+c;
			throw std::domain_error(s);
			
		}
		int n(3);
		int m(3);
		int k(0);
		for(int i(x-1);k<n;i++){
			int l(0);
			for(int j(y-1);l<m;j++){
				mat[k][l]=BrojMina(i,j,polja);
				l++;	
			}
		k++;}
	return mat;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0) {
			int h(x);
			int m(y);
			string iks;
			string ipsilon;
			while(h!=0){
				iks.push_back(h%10 + '0');
				h=h/10;
			}
			while(m!=0){
				ipsilon.push_back(m%10 + '0');
			
				m=m/10;
			}
			string s;
			string a{"Polje ("};
			string b{","};
			string c{") ne postoji"};
			s=a+iks+b+ipsilon+c;
			throw std::domain_error(s);
		}
	if(polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPrazno){}
	else{
	if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
		else polja[x][y]=Polje::BlokiranoPrazno;
}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x>=polja.size() || y>=polja[0].size() || x<0 || y<0) {
			
			int h(x);
			int m(y);
			string iks;
			string ipsilon;
			while(h!=0){
				iks.push_back(h%10 + '0');
				h=h/10;
			}
			while(m!=0){
				ipsilon.push_back(m%10 + '0');
			
				m=m/10;
			}
			
			string s;
			string a{"Polje ("};
			string b{","};
			string c{") ne postoji"};
			s=a+iks+b+ipsilon+c;
			throw std::domain_error(s);
			
		}
	if(polja[x][y]==Polje::Mina || polja[x][y]==Polje::Prazno || polja[x][y]==Polje::Posjeceno){}
	else{
	if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
		else polja[x][y]=Polje::Prazno;
}
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
		
		polja[x][y]=Polje::Posjeceno;
		int br(0);
		for(int i(0);i<polja.size();i++){
			for(int j(0);j<polja[i].size();j++){
			if(polja[i][j]==Polje::Prazno)br++;	
			}
		}
			if(smjer==Smjerovi::Gore){
			if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
			if(polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			
			if(polja[x-1][y]==Polje::Mina){
				OcistiTablu(polja);return Status::KrajPoraz;
			}
			else if(polja[x-1][y]==Polje::Prazno){
				if(polja[x-1][y]==Polje::Prazno && br==1) return Status:: KrajPobjeda;
				else {
					
					x-=1;
					return Status::NijeKraj;
				}
			}
			
		}
		else if(smjer==Smjerovi::GoreDesno){

				if(x-1<0||y+1>=polja.size() ) throw std::out_of_range("Izlazak van igrace table");
				if(polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
				
			if(polja[x-1][y+1]==Polje::Mina){
				OcistiTablu(polja);return Status::KrajPoraz;
			}
			else if(polja[x-1][y+1]==Polje::Prazno){
				if(polja[x-1][y+1]==Polje::Prazno && br==1) return Status ::KrajPobjeda;
				else {
					
					y+=1;
					x-=1;
					return Status::NijeKraj;
				}
			}
		}
		else if(smjer==Smjerovi::GoreLijevo){
			

			if(y-1<0 || x-1<0) throw std::out_of_range("Izlazak van igrace table");
			if(polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			
			if(polja[x-1][y-1]==Polje::Mina){
				OcistiTablu(polja);return Status::KrajPoraz;
			}
			else if(polja[x-1][y-1]==Polje::Prazno){
				if(polja[x-1][y-1]==Polje::Prazno && br==1) return Status ::KrajPobjeda;
				else {
					
					y-=1;
					x-=1;
					return Status::NijeKraj;
				}
			}
		}
		else if(smjer==Smjerovi::Lijevo){
			if(y-1<0) throw std::out_of_range("Izlazak van igrace table");
			if(polja[x][y-1]==Polje::BlokiranoPosjeceno || polja[x][y-1]==Polje::BlokiranoPrazno || polja[x][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			
			if(polja[x][y-1]==Polje::Mina){
				OcistiTablu(polja); return Status::KrajPoraz;
			}
			else if(polja[x][y-1]==Polje::Prazno){
				if(polja[x][y-1]==Polje::Prazno && br==1) return Status::KrajPobjeda;
				else {
					
					y-=1;
					return Status::NijeKraj;
				}
			}
		}
		else if(smjer==Smjerovi::Desno){
			
			if(y+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
			if(polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			
			if(polja[x][y+1]==Polje::Mina){
				OcistiTablu(polja);return Status::KrajPoraz;
			}
			else if(polja[x][y+1]==Polje::Prazno){
				if(polja[x][y+1]==Polje::Prazno && br==1) return Status ::KrajPobjeda;
				else {
					
					y+=1;
					return Status::NijeKraj;
				}
			}
		}
		else if(smjer==Smjerovi::DoljeDesno){
				if(x+1>=polja[0].size() || y+1>=polja.size()) throw std::out_of_range("Izlazak van igrace table");
				if(polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
				
			
			if(polja[x+1][y+1]==Polje::Mina){
				OcistiTablu(polja);
				return Status::KrajPoraz;
			}
			else if(polja[x+1][y+1]==Polje::Prazno){
				if(polja[x+1][y+1]==Polje::Prazno && br==1) return Status:: KrajPobjeda;
				else {
					
					y+=1;
					x+=1;
					return Status::NijeKraj;
				}
			}
		}
		else if(smjer==Smjerovi::DoljeLijevo){
			if(y-1<0 || x+1>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
			if(polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			
			
			if(polja[x+1][y-1]==Polje::Mina){
				OcistiTablu(polja);return Status::KrajPoraz;
			}
			else if(polja[x+1][y-1]==Polje::Prazno){
				if(polja[x+1][y-1]==Polje::Prazno && br==1) return Status ::KrajPobjeda;
				else {
					
					y-=1;
					x+=1;
					return Status::NijeKraj;
				}
			}
		}
		else{
			if(x+1>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
			if(polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
			
			if(polja[x+1][y]==Polje::Mina){
				OcistiTablu(polja);
				return Status::KrajPoraz;
			}
			else if(polja[x+1][y]==Polje::Prazno){
				if(polja[x+1][y]==Polje::Prazno && br==1) return Status ::KrajPobjeda;
				else {
				
					x+=1;
					return Status::NijeKraj;
				}
			}
		}
	
	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){

		
		polja[x][y]=Polje::Posjeceno;
		int br(0);
		for(int i(0);i<polja.size();i++){
			for(int j(0);j<polja[i].size();j++){
			if(polja[i][j]==Polje::Prazno)br++;	
			}
		}
		
		if(novi_x<0 || novi_y<0 || novi_x>=polja.size() || novi_y>=polja[0].size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		
		if(polja[novi_x][novi_y]==Polje::Mina){
				OcistiTablu(polja);
				return Status::KrajPoraz;
			}
			else if(polja[novi_x][novi_y]==Polje::Prazno){
				if(polja[novi_x][novi_y]==Polje::Prazno && br==1) return Status ::KrajPobjeda;
				else {
				
					x=novi_x;
					y=novi_y;
					return Status::NijeKraj;
				}
			}
		
	return Status::NijeKraj;
}




int main ()
{	
	
	cout<<"Unesite broj polja: ";
	int n;
	cin>>n;
	cout<<"Unesite pozicije mina: \n";
	auto tabla(KreirajIgru(n, {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}}));
		for(int i(0);i<tabla.size();i++){
		for(int j(0);j<tabla[i].size();j++)
			if(tabla[i][j]==Polje::Mina)cout<<"1 ";
				else cout<<"0 ";
		cout<<endl;
	}


	cout<<"\nUnesite koordinate neke tacke: ";
	try{
	auto m(PrikaziOkolinu(tabla,0,0));
	for(int i(0);i<m.size();i++){
		for(int j(0);j<m[i].size();j++)
			cout<<m[i][j]<<" ";
	
	
	
	
	
		cout<<endl;
	}}catch(...){
		cout<<"ahaa";
		
	}
    return 0;
}