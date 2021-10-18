/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> IzdvojiGadne(vector<int> v, bool odluka){
    vector<int> vrati;
    
    
    
    for(int i(0); i<v.size(); i++){
        
        int element(abs(v[i]));
        vector<int> cifre;
        while(element>0){
            int ubaci=element%3;
            cifre.push_back(ubaci);
           element/=3;
        }
    
      
        
        int br0(0);
        int br1(0);
        int br2(0);
        for(int j(0); j<cifre.size(); j++){
            if(cifre[j]==0) br0++;
            if(cifre[j]==1) br1++;
            if(cifre[j]==2) br2++;
        }
        
  

        if(odluka==true && br0%2==0 && br1%2==0 && br2%2==0)
                vrati.push_back(v[i]);
        if(odluka==false && (br2==0 || br2%2==1) && (br1==0 || br1%2==1) && (br0==0 || br0%2==1))
                vrati.push_back(v[i]);
    }
    
   if(vrati.size()>0){
    for(int i(0); i<vrati.size()-1; i++){
        for(int j(i+1); j<vrati.size(); j++){
            if(vrati[i]==vrati[j]){
                vrati.erase(vrati.begin()+j);
               j--;
            }
        }
    }
   }
    
    return vrati;
}

int main(){
    
    vector<int> a; 
   
    
    cout << "Unesite brojeve (0 za prekid unosa): ";
    int i(0);
    int el;
    do{
        cin >> el;
        a.push_back(el);
        i++;
    }while(el!=0);
    a.erase(a.begin()+(a.size()-1));
    
    vector<int> opaki=IzdvojiGadne(a,true);
    vector<int> odvratni=IzdvojiGadne(a, false);
    
    cout << "Opaki: ";
    for( int j(0); j<opaki.size(); j++)
        cout << opaki[j] << " ";
    cout << endl << "Odvratni: ";
    for(int j(0); j<odvratni.size(); j++)
        cout << odvratni[j] << " ";
    
    return 0;
}