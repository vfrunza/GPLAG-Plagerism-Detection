/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
Matrica IzdvojiDijagonale3D(vector<deque<deque<int>>> rubick, SmjerKretanja smjer)  {
    
    Matrica  NazNaprijed, GorDolje, DoljGore, LijevDesno, DesnLijevo, NapNazad;
    int brojac(0);
    NapNazad.resize(10);
    
    for (int i(0); i<rubick.size(); i++){
        for (int j(0); j<rubick.at(i).size(); j++){
            for (int k(0); k<rubick.at(i).at(j).size(); k++){
                if (j==k) { NapNazad.at(j).resize(brojac+1); 
                int x;
                x=rubick.at(i).at(j).at(k);
                brojac++; 
                    NapNazad.at(j).push_back(x); }  
            }
        }
    }
    
    return NapNazad; 
}
int main ()
{ Iz
	return 0;
}