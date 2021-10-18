#include<iostream>
#include<vector>  
#include<stdexcept>
enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla; 
TablaKreirajIgru(int n, const std::vector<std::vector<int>> &mine){ 
	std::vector<std::vector<int>> povratna;
	for(int i(0); i<mine.size(); i++){
		for(int j(0); j<mine[i].size(); j++){
			if(mine[i].size()>2) throw std::domain_error("Ilegalan format zadavanja mina";)
			if(i>=n) throw std::domain_error("Ilegalan format zadavanja mina");
		} 
	}  
	povratna.resize(n);
	for(int i(0); i<n; i++) povratna[i].resize(n);  
	for(int i(0); i<n; i++){
		for(int j(0); j<n; j++) povratna[i][j]=0;
	}
	for(int i(0); i<mine.size(); i++){
		povratna[a[i][0]][a[i][1]]=1;
		}
	return povratna; 
} 
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	for(int i(0); i<polja.size(); i++) if(x>=polja.size() || y>=polja[i].size()) throw std::domain_error("Polje (" << x << "," << y << ") ne postoji");
	std::vector<std::vector<int>> povratna(3, std::vector<int>(3,0)); 
	for(int i(0); i<polja.size(); i++){
		for(int j(0); j<polja[i].size(); j++){
			if(x!=0 && x!=polja.size()-1 && y!=0 && y!=polja[i].size()-1){
				if(i==x-1 && j=y-1){
					
				}
			}
		}
	}
	
}