enum class SmjerKretanja{
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template <typename 3DKont>
auto IzdvojiDijagonale3D(3DKont kont, SmjerKretanja smjer)->typename std::remove_reference<decltype(kont[0])>::type{
    
}

int main (){
    
	return 0;
}