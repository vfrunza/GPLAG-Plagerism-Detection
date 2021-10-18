#include <iostream>
#include<vector>
#include<stdexcept>

using namespace std;

enum class Polje {
 Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};
typedef std::vector<std::vector<Polje>> Tabla;




Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	for (int i = 0; i < mine.size(); i++) {
		if(mine[i].size()!=2) throw domain_error("Ilegalan format zadavanja mina");
		if(mine[i][0]<0|| mine[i][0]>=n || mine[i][1]<0|| mine[i][1]>=n)
		throw domain_error("Ilegalne pozicije mina");
	}
	
	Tabla t(n,vector<Polje>(n,Polje::Prazno));
	
	for (int i = 0; i < mine.size(); i++) {
		t[mine[i][0] ][mine[i][1]] = Polje::Mina;
	}
	
	return t;
}
template<typename T>
bool ispravniIndeksi(const std::vector<std::vector<T> >& M,int x, int y){
	return x>=0&&x<M.size()&&y>=0&&y<M[0].size(); 
}

int sumirajSusjede(const Tabla& polja,int x,int y ){
	int suma=0;
	for (int i = -1; i <=1 ; i++) {
		for (int j = -1; j <= 1; j++) {
			if(i==0&&j==0)continue;
			int xt=x+i,yt=y+j;
			if(ispravniIndeksi(polja,xt,yt) && polja[xt][yt]==Polje::Mina){
				suma++;
			}
		}
	}
	
	return suma;
}



string int2string(int x){
  string tekstualniBroj;
  if(x==0) return "0";
  while(x!=0){
    int cifra = x%10;
    
    tekstualniBroj.push_back('0'+cifra);
    x/=10;
  }
  
  return tekstualniBroj;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(!ispravniIndeksi(polja,x,y)){
		throw domain_error("Polje ( "+int2string(x)+","+int2string(y)+" ) ne postoji");
	}
	vector<vector<int> > rezultat(3);
	
	for (int i = -1; i <=1 ; i++) {
		for (int j = -1; j <= 1; j++) {
			int xt=x+i,yt=y+j;
			if(ispravniIndeksi(polja,xt,yt)){
				int suma = sumirajSusjede(polja,xt,yt);
				rezultat[i+1].push_back(suma);
			}
			else{
				rezultat[i+1].push_back(0);	
			}
		}
	}
	return rezultat;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	
	
	
}
void DeblokirajPolje(Tabla &polja, int x, int y);
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer);
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y);
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);

void ispisi(const Tabla& polja){
	for (int i = 0; i < polja.size(); i++) {
		for (int j = 0; j < polja[i].size(); j++) {
			if(polja[i][j]==Polje::Prazno)
				cout<<"0 ";
			else if(polja[i][j]==Polje::Mina){
				cout<<"1 ";
			}
		}
		cout<<endl;
	}
}



int main ()
{
	try{
		vector<vector<int>>mine={{1,2},{4,4},{3,4}};
		Tabla tabla = KreirajIgru(5,mine);
		
		ispisi(tabla);
		cout<<"OK"<<endl;
		std::vector<std::vector<int>> M = PrikaziOkolinu(tabla,4,4);
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M[i].size(); j++) {
				cout<<M[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	catch(domain_error e){
		cout<<e.what()<<endl;
	}
	
	
	return 0;
}