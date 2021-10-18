#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<double>> Matrica;
typedef vector<double> Vektor;
void IspisiMatricu (Matrica matrica)
{
    for(unsigned int i=0; i<matrica.size(); i++) {
        for(unsigned int j=0; j<(matrica.at(i)).size(); j++ ) {
            cout << (matrica.at(i)).at(j) << " ";
        }
        cout << endl;
    }
}

// mozda dodati bool funkciju koja mi provjerava da li je maksimalan nakon sto ga nadem

Matrica RastuciPodnzovi (Vektor pocetni)
{
    Matrica rastuci;
    Vektor pomocni;
    
   for(unsigned int i=0; i<pocetni.size(); i++)
   {
       
       if(i==pocetni.size()-1)
       {
           if(pocetni.at(pocetni.size()-1)>pocetni.at(pocetni.size()-2))
           pomocni.push_back(pocetni.at(pocetni.size()-1));
           break;
       }

       if(pocetni.at(i+1)>pocetni.at(i) and i!=pocetni.size()-1)
       {
           pomocni.push_back(pocetni.at(i));
           pomocni.push_back(pocetni.at(i+1));
           i++;
           continue;
       }
       
       else
       {
           
       }
       
   }
    
   
    
    
    return rastuci;
}

Matrica OpadajuciPodnizovi (Vektor pocetni)  
{
    Matrica opadajuci;
    return opadajuci;
}

int main()
{
    int brel(0);
    double element(0);
    Vektor pocetni;
    cout << "Unesite broj elementa: " << endl;
    cin >> brel;
    cout << "Unesite elemente: " << endl;
    while(brel>0) {
        cin >> element;
        pocetni.push_back(element);
        brel--;
    }
    cout << "Rastući: " << endl;
    IspisiMatricu(RastuciPodnzovi(pocetni));
    
   // cout << endl << "Opadajući: " << endl;
   // IspisiMatricu(OpadajuciPodnizovi(pocetni));
    cout << endl;
    return 0;
}