#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>

int SumaCifri(long long int n) {
    int suma = 0;
    while(n != 0) {
        suma += n % 10;
        n/=10;
    }
    return suma;
}

template<typename Tip, typename Var>
Tip SumaDjelilaca(Var broj) {
    int suma = 0;
    for(int i = 1; i <= broj; i++) 
        if(broj % i == 0) suma += i;
    
    return suma;
}

int BrojProstihFaktora(long long int broj) {
    if(broj < 0) broj *= -1;
    int faktori = 0;
    
    for(int i = 2; i <= broj; ) {
        if(broj % i == 0) {
            faktori++;
            broj /= i;
        }
        else i++;
    }
    return faktori;
}  

bool SavrsenBroj(long long int n) {
    int suma = 0;
    for(int i = 1; i < n; i++) {
        if(n % i == 0) suma += i;
    }
    if(suma == n) return true;
    return false;
}

int BrojSavrsenihDjelilaca(long long int n) {
    int broj = 0;
    for(int i = 1; i < n; i++) {
        if(n % i == 0)
            if(SavrsenBroj(i)) broj++;
    }
    
    return broj;
}

template<typename Tip, typename It1, typename It2>
std::vector<std::vector<Tip>> Unija(It1 pocetak1, It1 kraj1, It2 pocetak2, It2 kraj2) {
    std::vector<std::vector<Tip>> matrica;
    
    It2 pomocni;
    while(pocetak1 != kraj1) {
        pomocni = pocetak2;
        while(pomocni != kraj2) {
            if(*pomocni == *pocetak1) matrica.push_back({*pocetak1,0,0});
            pomocni++;
        }
        pocetak1++;
    }
    return matrica;
}

template<typename Tip, typename Fja, typename Var, typename It1, typename It2>
auto UvrnutiPresjek(It1 pocetak1, It1 kraj1, It2 pocetak2, It2 kraj2, Fja kriterij(Var) = NULL) -> std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>{
    typedef typename std::remove_reference<std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>>::type TipMat;
    
    It2 pomocni = pocetak2;
    
    TipMat matrica;
    
    if(kriterij != NULL) {
        while(pocetak1 != kraj1) {
            pomocni = pocetak2;
            while(pomocni != kraj2) {
                if(kriterij(*pocetak1) == kriterij(*pomocni)) 
                    matrica.push_back({*pocetak1, *pomocni, kriterij(*pocetak1)});
                pomocni++;
            }
            pocetak1++;
        }
    } 
    else matrica = Unija<int>(pocetak1, kraj1, pocetak2, kraj2);
    std::sort(matrica.begin(), matrica.end(), [](const std::vector<Tip> &a, const std::vector<Tip> &b) -> bool 
        {if(a[2] == b[2]) {if(a[0] == b[0]) return a[1] < b[1]; else return a[0] < b[0];}  return a[2] < b[2];});
    
    return matrica;
}

template<typename Tip, typename Fja, typename Var, typename It1, typename It2>
auto UvrnutaRazlika(It1 pocetak1, It1 kraj1, It2 pocetak2, It2 kraj2, Fja kriterij(Var)) -> std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>{
    typedef typename std::remove_reference<std::vector<std::vector<decltype(*pocetak1+*pocetak1)>>>::type TipMat;
    
    TipMat matrica;
    
    bool ImaIsti = false;
    It2 pomocni1 = pocetak1;
    It1 pomocni2;
    while(pomocni1 != kraj1) {
        pomocni2 = pocetak2;
        while(pomocni2 != kraj2) {
            if(kriterij(*pomocni1) == kriterij(*pomocni2)) ImaIsti = true;
            pomocni2++;
        }
        if(!ImaIsti) matrica.push_back({*pomocni1, kriterij(*pomocni1)});
        ImaIsti = false;
        pomocni1++;
    }
    
    pomocni1 = pocetak1;
    pomocni2 = pocetak2;
    ImaIsti = false;
    
    while(pomocni2 != kraj2) {
        pomocni1 = pocetak1;
        while(pomocni1 != kraj1) {
            if(kriterij(*pomocni1) == kriterij(*pomocni2)) ImaIsti = true;
            pomocni1++;
        }
        if(!ImaIsti) matrica.push_back({*pomocni2,kriterij(*pomocni2)});
        ImaIsti = false;
        pomocni2++;
    }
    
    std::sort(matrica.begin(), matrica.end(), [](const std::vector<Tip> &a, const std::vector<Tip> &b) -> bool 
        {if(a[0] == b[0]) return a[1] > b[1]; return a[0] > b[0];});
    
    return matrica;
    
}

template<typename Tip>
void IspisiMatricu(std::vector<std::vector<Tip>> matrica) {
    for(int i = 0; i < matrica.size(); i++) {
        for(int j = 0; j < matrica[i].size(); j++)
            std::cout << std::setw(6) << matrica[i][j] << " ";
        std::cout << std::endl;
    }
}

template<typename Tip>
void UnesiDek(std::deque<Tip> &dek) {
    Tip broj;
    bool ImaVec = false;
    for(int i = 0; i < dek.size(); i++) {
        std::cin >> broj;
        for(int j = 0; j < dek.size(); j++) 
            if(dek[j] == broj) ImaVec = true;
        if(!ImaVec) dek[i] = broj;
        else i--;
        ImaVec = false;
    }
}

int main ()
{
    int n, m;
    std::cout << "Unesite broj elemenata prvog kontejnera: ";
    std::cin >> n;
    std::deque<int> prvi(n);
    std::cout << "Unesite elemente prvog kontejnera: ";
    UnesiDek(prvi);
    
    std::cout << "Unesite broj elemenata drugog kontejnera: ";
    std::cin >> m;
	std::deque<int> drugi(m);
    std::cout << "Unesite elemente drugog kontejnera: ";
	UnesiDek(drugi);
   	
	std::vector<std::vector<int>> mat;
	mat = UvrnutiPresjek<int, int, long long int>(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), SumaCifri);

	std::cout << "Uvrnuti presjek kontejnera:" << std::endl;
	IspisiMatricu(mat);
    
	std::vector<std::vector<int>> razlika;
	razlika = UvrnutaRazlika<int,int,long long int>(prvi.begin(), prvi.end(), drugi.begin(), drugi.end(), BrojProstihFaktora());
	std::cout << "Uvrnuta razlika kontejnera:" << std::endl;
	IspisiMatricu(razlika);
	std::cout << "Dovidjenja!";
	return 0;
}