// B 16/17, Zadaća 2, Zadatak 2
//	Autotestovi by Enil Pajic (epajic1@etf.unsa.ba | @eon : etf.ba)
//	NAPOMENA: i javni ATo-vi su dio postavke!	

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <iomanip>
#include <string>

enum class SmjerKretanja{NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename Kontejner>

auto  IzdvojiDijagonale3D(Kontejner kont, SmjerKretanja smjer) -> typename std::remove_reference<decltype(kont.at(0))>::type
{
    int v_kont(0), v_mat(0), v_red(0);
    
    if (kont.size() != 0) 
    {
        v_kont = kont.size();
        if (kont.at(0).size() != 0)
        {
            v_mat = kont.at(0).size();
            if (kont.at(0).at(0).size() != 0) 
                v_red = kont.at(0).at(0).size();
        }
    }
    
    typedef typename std::remove_reference<decltype(kont.at(0))>::type TipPovratnog;
    TipPovratnog povratni;
    
    if (v_kont == 0 || v_mat == 0 || v_red == 0)
        return povratni;
    
    for (int i = 0; i < v_kont; i++)
    {
        for (int j = 0; j < kont.at(i).size(); j++)
        {
            if (kont.at(i).at(j).size() != v_red)
                throw std::domain_error("Redovi nemaju isti broj elemenata");
        }
    }
    
    for (int i = 0; i < v_kont; i++)
        if (kont.at(i).size() != v_mat)
            throw std::domain_error("Plohe nemaju isti broj redova");
    
    typedef typename std::remove_reference<decltype(kont.at(0).at(0))>::type TipReda;
    int naprijed, horizontalno, vertikalno, zadnja(v_kont - 1);
    int d_n, d_v, d_h;
    int granica_n(0), granica_v(0), granica_h(0);
    int br_redova(0);
    int *x, *y, *z; //Pokazivaci potrebni jer hor vert i napr ne znace uvijek isto
    
    if (smjer == SmjerKretanja::NaprijedNazad)
    {
        x = &naprijed; y = &vertikalno; z = &horizontalno;
        naprijed = 0; vertikalno = 0; horizontalno = 0; 
        granica_n = v_kont; granica_v = v_mat; granica_h = v_red;
        d_n = 1; d_v = 1; d_h = 1; 
    }
    if (smjer == SmjerKretanja::NazadNaprijed)
    {
        x = &naprijed; y = &vertikalno; z = &horizontalno;
        naprijed = zadnja; vertikalno = 0; horizontalno = v_red - 1;
        granica_n = -1; granica_v = v_mat;  granica_h = -1;
        d_n = -1; d_v = 1; d_h = -1; 
    }
    
    if (smjer == SmjerKretanja::GoreDolje)
    {
        y = &naprijed; z = &vertikalno; x = &horizontalno;
        naprijed = 0; vertikalno = 0; horizontalno = v_kont - 1;
        granica_n = v_mat; granica_v = v_red;  granica_h = -1;
        d_n = 1; d_v = 1; d_h = -1; 
    }
    if (smjer == SmjerKretanja::DoljeGore)
    {
        y = &naprijed; z = &vertikalno; x = &horizontalno;
        naprijed = v_mat - 1; vertikalno = v_red - 1; horizontalno = v_kont - 1; 
        granica_n = -1; granica_v = -1; granica_h = -1;
        d_n = -1; d_v = -1; d_h = -1; 
    }
    
    if (smjer == SmjerKretanja::LijevoDesno)
    {
        z = &naprijed; y = &vertikalno; x = &horizontalno;
        naprijed = 0; vertikalno = 0; horizontalno = v_kont - 1; 
        granica_n = v_red; granica_v = v_mat; granica_h = -1;
        d_n = 1; d_v = 1; d_h = -1; 
    }
    if (smjer == SmjerKretanja::DesnoLijevo)
    {
        z = &naprijed; y = &vertikalno; x = &horizontalno;
        naprijed = v_red - 1; vertikalno = 0; horizontalno = 0; 
        granica_n = -1; granica_v = v_mat; granica_h = v_kont;
        d_n = -1; d_v = 1; d_h = 1; 
    }
    
    //Poceci
    int hpoc(horizontalno);
    int vpoc(vertikalno);
    
    while (naprijed != granica_n)
    {
        povratni.push_back(TipReda(0));
        while (horizontalno != granica_h && vertikalno != granica_v)
        {
            povratni.at(br_redova).push_back(kont.at(*x).at(*y).at(*z));
            
            horizontalno += d_h;
            vertikalno += d_v;
        }
        //Vrati hor i vert na pocetak
        horizontalno = hpoc;
        vertikalno = vpoc;
        br_redova++;
        naprijed += d_n;
    }
    
    return povratni;
}

int main ()
{
    int x, y, z;
    
    std::cout << "Unesite dimenzije (x y z): ";
    std::cin >> x >> y >> z;
    if (x < 0 || y < 0 || z < 0)
    {
        std::cout << "Neispravne dimenzije kontejnera!\n";
        return 0;
    }
    
    std::cout << "Unesite elemente kontejnera: \n";
    std::vector<std::deque<std::deque<int>>> kontejner(x, std::deque<std::deque<int>>(y, std::deque<int>(z)));
    
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                std::cin >> kontejner.at(i).at(j).at(k);
    
    int br_smjera;
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    std::cin >> br_smjera;
    if (br_smjera < 0 || br_smjera > 5)
    {
        std::cout << "Smjer kretanja nije ispravan!\n";
        return 0;
    }
    try
    {
        std::deque<std::deque<int>> dijagonale(IzdvojiDijagonale3D(kontejner, SmjerKretanja(br_smjera)));
        
        std::vector<std::string> smjerovi{"NaprijedNazad", "NazadNaprijed", "GoreDolje", "DoljeGore", "LijevoDesno", "DesnoLijevo"};
        std::cout << smjerovi[br_smjera] << ": \n";
        for (auto red:dijagonale)
        {
            for (auto x:red)
                std::cout << std::setw(4) << x;
            std::cout << "\n";
        }
    }
    catch (std::domain_error e)
    {
        std::cout << e.what();
    }
    
	return 0;
}