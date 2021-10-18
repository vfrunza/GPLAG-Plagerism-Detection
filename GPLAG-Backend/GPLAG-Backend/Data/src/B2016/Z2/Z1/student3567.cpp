#include<iostream>
#include<vector>
using namespace std;


enum class Polje{ Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina };
typedef vector<vector<Polje>> Tabla;
Tabla KreirajIgru(int n,const vector<vector<int>> &mine){
    for(int i(0);i<mine.size();i++){
        for(int j(0);j<mine[i].size();j++){
            if(mine[i].size()!=2) throw domain_error("Ilegalan format zadavanja mina");
            if(i>n || j>n) throw domain_error("Ilegalne pozicije mina");
            if(i<n && j<n && mine[i][j]==1){
                Tabla[i].push_back(Mina);
            }
        }
    }
}
vector<vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y){
    vector<vector<int>> matrica;
    int br(0);
    for(int i(x);i<Tabla.size();i++){
        for(int j(y);j<Tabla[i].size();j++){
        	if(i==0 && j==0){
            if (Tabla[i][j]==1) {
                
            }
            
        }
        if(Tabla[i-1][i+1])
    }
}
int main ()
{
    int n;
    cout<<"Unesite broj polja: ";
    cin>>n;
    
	return 0;
}