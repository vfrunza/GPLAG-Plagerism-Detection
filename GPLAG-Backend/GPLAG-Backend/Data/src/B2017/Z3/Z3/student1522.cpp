/B2017/2018: Zadaća 3, Zadatak 3
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <vector>
#include <iterator>

//Definiramo genericku strukturu Matrica
template<typename NekiTip>
struct Matrica{
    int broj_redova, broj_kolona;
    NekiTip** elementi = nullptr;
};

//Funkcija za dealokaciju memorije
template<typename NekiTip>
void UnistiMatricu(NekiTip mat){
    if(!mat.elementi) return;
    for(int i(0); i < mat.broj_redova; i++) delete[] mat.elementi[i];
    delete[] mat.elementi;
    mat.elementi = nullptr;
}

//Funkcija za stvaranje novih matrica
template<typename NekiTip>
Matrica<NekiTip> StvoriMatricu(int br_redova){
    Matrica<NekiTip> mat;
    mat.broj_redova = br_redova;
    mat.broj_kolona = br_redova;
    mat.elementi = new NekiTip*[br_redova];
    //sve ih inicijalizujemo na nullptr
    for(int i(0); i < br_redova; i++) mat.elementi[i] = nullptr;
    //sada alociramo matricu
    try{
        for(int i(0); i < br_redova; i++) mat.elementi[i] = new NekiTip[br_redova]; 
    }catch(...){
        UnistiMatricu(mat);
        throw;
    }
    return mat;
}

//Funkcija za unos matrice
template<typename NekiTip>
void UnesiMatricu(Matrica<NekiTip> &mat){
    for(int i(0); i < mat.broj_redova; i++){
        for(int j(0); j< mat.broj_redova; j++){
            std::cout << "A(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi[i][j];
            //std::cout << std::endl;
        }
    }
}

//Funkcija za ispis matrice
template<typename NekiTip>
void IspisiMatricu(const Matrica<NekiTip> &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = false){
    for(int i(0); i < mat.broj_redova; i++){
        for(int j(0); j < mat.broj_redova; j++){
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << mat.elementi[i][j];
        }
        std::cout << std::endl;
    }
    if(treba_brisati) UnistiMatricu(mat);
}

//Funkcija za racunanje produkta dvije matrice
template<typename NekiTip>
Matrica<NekiTip> ProduktMatrica(const Matrica<NekiTip> &m1, const Matrica<NekiTip> &m2){
    if(m1.broj_redova != m2.broj_redova) throw std::domain_error("Matrice nisu saglasne za mnozenje");
    //stvaramo matricu koju cemo vratiti kao rezultat funkcije
    auto m3(StvoriMatricu<NekiTip>(m1.broj_redova));
    for(int i(0); i < m1.broj_redova; i++){
        for(int j(0); j < m1.broj_redova; j++){
            NekiTip suma;
            for(int k(0); k < m1.broj_redova; k++) suma = m1.elementi[i][k] * m2.elementi[k][j];
            m3.elementi[i][j] = suma;
        }
    }
    return m3;
}

template<typename NekiTip>
Matrica<NekiTip> ZbirMatrica(const Matrica<NekiTip> &mat1, const Matrica<NekiTip> &mat2){
    auto m3(StvoriMatricu<NekiTip>(mat1.broj_redova));
    for(int i(0); i < mat1.broj_redova; i++){
        for(int j(0); j < mat1.broj_redova; j++){
            m3.elementi[i][j] = mat1.elementi[i][j] + mat2.elementi[i][j];
        }
    }
    return m3;
}

template<typename NekiTip>
Matrica<NekiTip> PomnoziMatricuSkalarom(const Matrica<NekiTip> &mat, int faktor){
    auto m2(StvoriMatricu<NekiTip>(mat.broj_redova));
    for(int i(0); i < mat.broj_redova; i++){
        for(int j(0); j < mat.broj_redova; j++) m2.elementi[i][j] = mat.elementi[i][j] * faktor;
    }
    return m2;
}

template<typename NekiTip>
Matrica<NekiTip> StepenujMatricu(const Matrica<NekiTip> &mat, int n){
    auto m2(StvoriMatricu<NekiTip>(mat.broj_redova));
    m2 = ProduktMatrica(mat, mat);
    for(int i(0); i < n-2; i++){
        m2 = ProduktMatrica(mat, mat);
    }
    return m2;
}

template<typename NekiTip>
Matrica<NekiTip> KreirajJedinicnu(int broj_redova){
    auto m2(StvoriMatricu<NekiTip>(broj_redova));
    for(int i(0); i < broj_redova; i++){
        for(int j(0); j < broj_redova; j++) {
            if(i == j) m2.elementi[i][j] = 1;
            else m2.elementi[i][j] = 0;
        }
    }
    return m2;
}

//Funkcija koja racuna matricni polinom
template<typename NekiTip>
Matrica<NekiTip> MatricniPolinom(const Matrica<NekiTip> &mat, int n, std::vector<double>::iterator it){
    if(n < 0) throw std::domain_error("Neispravan stepen polinoma");
    if(mat.broj_kolona != mat.broj_redova) throw std::domain_error("Matrica mora biti kvadratna");
    auto mat2(StvoriMatricu<NekiTip>(mat.broj_redova));
    //Sada trebamo racunati matricni polinom
    //Matrice podrzavaju osobinu komutativnosti
    //Tako da ce jedinicna matrica biti naknadno dodana
    //Cuvam prvo mjesto u vektoru
    auto poc(it);
    it++;
    for(int i(1);;){
        auto pomnozena(StvoriMatricu<NekiTip>(mat.broj_redova));
        auto stepenovana(StvoriMatricu<NekiTip>(mat.broj_redova));
        pomnozena = PomnoziMatricuSkalarom(mat, *it);
        stepenovana = StepenujMatricu(pomnozena, i);
        if(i == 1) mat2 = stepenovana;
        //else if(*it == 0);
        else mat2 = ZbirMatrica(mat2, stepenovana);
        i++;
        if(i == n +1) break;
        it++;
    }
    auto jed(StvoriMatricu<NekiTip>(mat.broj_redova));
    jed = KreirajJedinicnu<NekiTip>(mat.broj_redova);
    jed = PomnoziMatricuSkalarom(jed, *poc);
    mat2 = ZbirMatrica(jed, mat2);
    //mat2 += v[0] * KreirajJedinicnu<double>(mat.broj_redova);
    return mat2;
}

int main ()
{
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int dimenzija(0);
    std::cin >> dimenzija;
    std::cout << "Unesite elemente matrice A: " << std::endl;
    Matrica<double> mat;
    try{
        mat = StvoriMatricu<double>(dimenzija);
    }catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!";
        return 0;
    }
    UnesiMatricu(mat);
    std::cout << "Unesite red polinoma: ";
    int red_polinoma(0);
    std::cin >> red_polinoma;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> koeficijenti;
    for(int i(0); i < red_polinoma+1; i++){
        int temp(0);
        std::cin >> temp;
        koeficijenti.push_back(temp);
    }
    Matrica<double> mat2;
    try{
        mat2 = StvoriMatricu<double>(dimenzija);
    }catch(std::bad_alloc){
        std::cout << "Nema dovoljno memorije!";
        return 0;
    }
    try{
    mat2 = MatricniPolinom(mat, red_polinoma, koeficijenti.begin());
    }catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
        return 0;
    }
    IspisiMatricu(mat2, 10, 6, true);
	return 0;
}
