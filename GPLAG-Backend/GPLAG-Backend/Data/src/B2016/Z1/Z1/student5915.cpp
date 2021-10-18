#include <iostream>
#include <vector>
#include <cmath>

std::vector <int> IzdvojiGadne(std::vector <int> a, bool b){
    std::vector<int> opaki, odvratni;
    for(int x: a){
        std::vector <int> ternar(3);
        if(x >= -2 && x <= 2 && x != 0){
        odvratni.push_back(x);
        continue;
        }
        int gadni (x);
         do{
            ternar[abs(x) % 3]++ ;
           x/= 3;
        } while(x!= 0);
        if(ternar[0] % 2 == 0 && ternar[1] % 2 == 0 && ternar[2] % 2 == 0)
            opaki.push_back(gadni);
        if ((ternar[0] % 2 != 0 && ternar[1] % 2 != 0 && ternar[2] % 2 != 0) || (ternar[0] == 0 && ternar[1] == 0 && ternar[2] % 2 != 0) || (ternar[0] == 0 && ternar[2] == 0 && ternar[1] % 2 != 0) || (ternar[0] == 0 && ternar[1] % 2 != 0 && ternar[2] % 2 != 0) || (ternar[1]== 0 && ternar[0] % 2 != 0 && ternar[2] % 2 != 0) || (ternar[2] == 0 && ternar[0] % 2 != 0 && ternar[1] % 2 !=0)) 
            odvratni.push_back(gadni);
    }
    for(int i = 0; i < opaki.size(); i++)
     for(int j = i; j < opaki.size(); j++)
        if(opaki[i] == opaki[j] && i != j)
        { opaki.erase(opaki.begin() + j);
            j--;
        }
    for(int i = 0; i < odvratni.size(); i++)
      for(int j = i; j < odvratni.size(); j++)
        if(odvratni[i] == odvratni[j] && i != j){
         odvratni.erase(odvratni.begin() + j);
         j--;
        }
if(b) return opaki;
    else return odvratni;
}

int main ()
{
    std::vector <int> a;
    int broj;
    std::cout << "Unesite brojeve (0 za prekid unosa): ";
    while (std::cin >> broj)
        a.push_back(broj);

    std::cout << "Opaki: ";
    for(int x: IzdvojiGadne(a, true))
      std::cout << x << " ";
    std::cout << "\nOdvratni: ";
    for(int x: IzdvojiGadne(a, false))
    std::cout << x << " ";
	return 0;
}