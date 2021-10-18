// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename NekiTip>
auto IzdvojiDijagonale3D (NekiTip kont, SmjerKretanja x) -> typename std::remove_reference<decltype (*kont.begin())>::type {
    typename std::remove_reference<decltype (*kont.begin())>::type mat;
    
}

int main ()
{
	return 0;
}