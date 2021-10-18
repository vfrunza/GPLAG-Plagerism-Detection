/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/


enum SmjerKretanja {
	NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
}


template <typename NekiTip>// 3 funkcije za gd,ld,nn,za transponovanje,jos 3d fju dodati

NekiTip Pjescani2D(NekiTip kont,SmjerKretanja n)  {
	
	int m=kont.size()
	NekiTip l;
	for(int i{0};i<m;i++) {
		for(int j{0};j<m;j++) {
			
			if((i>=j && i+j<=m-1) || (i<=j && i+j>=m-1)) l.at(i).push_back(kont.at(i).at(j));//prelasci u redove!!!!!!!
			
		}
	}
}
template <typename NekiTip>

NekiTip PjescaniSat(NekiTip kont,SmjerKretanja s) {
	
	
	
}




int main ()
{
	return 0;
}