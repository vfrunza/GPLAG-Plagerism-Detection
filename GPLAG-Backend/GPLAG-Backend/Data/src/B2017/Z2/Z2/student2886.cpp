/*B 2017/2018, Zadaća 2, Zadatak 2 */

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <deque>

enum class SmjerKretanja {
    NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};
template <typename matrica>
matrica GoreDoljeMat (matrica mat){
    matrica nova(mat.size());
    int br1(0);
    int duzina=mat.size();
    for (int i=0; i<=(duzina/2)+1; i++){                           //pola matrica
        for (int j=i; j<duzina; j++){
             nova.at(br1).push_back(mat.at(i).at(j));
        }
    duzina--;
    br1++;
    }
    duzina=mat.size();
    for (int i=duzina/2+1; i<mat.size(); i++){                           //još pola matrica
        for (int j=duzina-i-1; j<=i; j++){
             nova.at(br1).push_back(mat.at(i).at(j));
        }
    br1++;
    }
return nova;
}

template <typename matrica>
matrica DoljeGoreMat (matrica mat){
    matrica nova (GoreDoljeMat(mat));
    reverse (nova.begin(),nova.end());
   return nova;
}

template <typename matrica>
matrica LijevoDesnoMat (matrica mat){
    matrica nova(mat.size());
    int br2(0);
   for (int j=0; j<mat.size(); j++){
       for (int i=j; i<mat.size()-j; i++){
           nova.at(br2).push_back(mat.at(i).at(j));
       }
       br2++;
   }
   br2/=2;
   br2++;
   for (int j=mat.size()/2+1; j<mat.size(); j++){
       for (int i=0; i<mat.size(); i++){
           if (i<=j && i>=mat.size()-j-1){
               nova.at(br2).push_back(mat.at(i).at(j));
           }
       }
       br2++;
   }
      return nova;
}

template <typename matrica>
matrica DesnoLijevoMat (matrica m){
    matrica nova (LijevoDesnoMat(m));
    reverse (nova.begin(),nova.end());
   return nova;
}

template <typename kontejner>
kontejner KontejnerOdRedova(kontejner dek){
    kontejner novi (dek.size());
    int br1(0);
    for (int i=0; i<dek.size(); i++){
        for (int j=0; j<dek.size(); j++){
            novi.at(br1).push_back(dek.at(j).at(i));
        }
        br1++;
    }
    return novi;
}

template <typename kont>
kont PjescaniSat (kont a, SmjerKretanja b){
    
     bool istina=1;
    int velicina=a.size();
    
    for (int i=0; i<a.size(); i++){                          //kroz dek
        for (int j=0; j<a.at(i).size(); j++){               //matrica deka 
            if (a.at(i).size()!=velicina) istina=0;
            for (int k=0; k<a.at(i).at(j).size(); k++){     
                if (a.at(i).at(j).size()!=velicina) istina=0;
            }
        }
        if (!istina) throw std::domain_error("3D matrica nema oblik kocke");
    }
    
    if (velicina%2==0) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
    
    kont najnoviji(0);
    
    kont spesl(KontejnerOdRedova(a));
    
    for (int i=0; i<velicina; i++){                         //clanovi deka
    
    if (b==SmjerKretanja::GoreDolje){
        najnoviji.push_back(GoreDoljeMat(a.at(i)));
     }
    else if (b==SmjerKretanja::DoljeGore){
        najnoviji.push_back(DoljeGoreMat(a.at(i)));
      }
    else if (b==SmjerKretanja::LijevoDesno){
        najnoviji.push_back(LijevoDesnoMat(a.at(i)));
    } 
    else if (b==SmjerKretanja::DesnoLijevo){
        najnoviji.push_back(DesnoLijevoMat(a.at(i)));
    }
    else if (b==SmjerKretanja::NaprijedNazad){
        najnoviji.push_back(GoreDoljeMat(spesl.at(i)));
    } 
    else if (b==SmjerKretanja::NazadNaprijed){
        najnoviji.push_back(DoljeGoreMat(spesl.at(i)));
    }
}
return najnoviji;
}

int main ()
{
    try{
    int n;
    std::cout << "Unesite dimenziju (x/y/z): ";
    
    while(1){
    std::cin >> n;
    if (n>0) break;
    std::cout << "Dimenzija nije ispravna, unesite opet: ";
    }
    
    std::vector<std::deque<std::deque<int>>> mojdek(n);
    
    std::cout << "Unesite elemente kontejnera: ";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            mojdek.at(i).resize(n);
            for (int k=0; k<n; k++){
                int unos;
                std::cin >> unos;
                 mojdek.at(i).at(j).push_back(unos);
            }
        }
    }
    
    int komanda;
    
    std::cout << "Unesite smjer kretanja [0 - 5]: ";
    while(1){
    std::cin >> komanda;
    if (komanda>=0 && komanda<=5) break;
    std::cout << "Smjer nije ispravan, unesite opet:";
    }
    std::cout << std::endl;
    
    std::vector<std::deque<std::deque<int>>> mojdek1(PjescaniSat(mojdek, SmjerKretanja(komanda)));
    std::cout << "Pjescani sat unesene matrice je:" << std::endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (n-mojdek1.at(i).at(j).size()>0) std::cout << std::setw((n-mojdek1.at(i).at(j).size())*2) <<" ";
            for (int k=0; k<mojdek1.at(i).at(j).size(); k++){
                if (k==mojdek1.at(i).at(j).size()-1) std::cout << " " << std::setw(3)<<mojdek1.at(i).at(j).at(k);
                else std::cout << " " << std::setw(3)<<mojdek1.at(i).at(j).at(k);
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        }
    }
    }
    catch (std::domain_error a){
        std::cout << "Izuzetak: " << a.what();
    }
    catch (std::length_error b){
        std::cout << "Izuzetak: " << b.what();
    }
    
	return 0;
}