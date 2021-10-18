/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

/*bool DaLiJeParan(int n){
	if(n%2==0) return true;
	else return false;

}

bool Ostatak(int x){
    int n(x%3);
    if(DaLiJeParan(n)==true) return true;
    else return false;


}*/

bool trecaMogucnost(std::vector<int> V){
    std::vector<int> cif(3,0);
    bool trecaM(false);
    for(int i(0); i<V.size(); i++){
        if(V[i] == 0) cif[0]++;
        if(V[i] == 1) cif[1]++;
        if(V[i] == 2) cif[2]++;
    }
    for(int i(0); i<cif.size()-1; i++){
        if(cif[i] == 0) continue;
        for(int j(i+1); j<cif.size(); j++){
            if(cif[j] == 0) continue;        
            if(cif[i]%2 != cif[j]%2) trecaM=true;
        }
        
        
        
    }
    
    return trecaM;
    
}



bool OpakIliNe(std::vector<int> V){
    std::vector<int> cif(3,0);
    bool ParneIliNe(false);
    for(int i(0); i<V.size(); i++){
        if(V[i] == 0) cif[0]++;
        if(V[i] == 1) cif[1]++;
        if(V[i] == 2) cif[2]++;
    }
    for(int i(0); i<cif.size(); i++){
        if(cif[i] == 0) continue;
        if(cif[i] % 2 == 0) ParneIliNe=true;
        else ParneIliNe=false;
    }
    
    return ParneIliNe;
}

std::vector<int> IzdvojiGadne(std::vector<int> vek, bool a){
    std::vector<int> vekaz;
    std::vector<int> cifreT;
    bool opak;
    int broj;
    //algoritam za upisivanje u vektor trazenih brojeva
    for(int i(0); i<vek.size(); i++){
        cifreT.resize(0);
        broj=vek[i]; if(broj < 0) broj*=-1;
        while(broj!=0){
            cifreT.push_back(broj%3);
            broj/=3;
        }
        //algoritam za iskljucivanje trece mogucnosti
        if(trecaMogucnost(cifreT) == true) continue;
        
        opak=OpakIliNe(cifreT);
        
        if(opak==true && a==true){
            vekaz.push_back(vek[i]);
        }
        if(opak==false && a==false){
            vekaz.push_back(vek[i]);
        }
    }
    
    //algoritam za izbacivanje duplih
    for(int i(0); i<vekaz.size(); i++){
        for(int j(i+1); j<vekaz.size(); j++){
            
            if(vekaz[i] == vekaz[j]){
                
                for(int k(j+1); k<vekaz.size(); k++){
                    vekaz[k-1]=vekaz[k];
                }
                vekaz.resize(vekaz.size() - 1);
                j--;
            }
        }
    }
    
    
    
    return vekaz;
}

int main(){
   int n;
   std::vector<int> vek1, vek2, vek3;
   std::cout<<"Unesite brojeve (0 za prekid unosa): ";
   
   for(;;){
      std::cin>>n;
      if(n == 0) break;
      else vek1.push_back(n);
   }


   vek2=IzdvojiGadne(vek1, true);
   vek3=IzdvojiGadne(vek1, false);
   std::cout<<"Opaki: ";
   for(int i(0); i<vek2.size(); i++){
      std::cout<<vek2[i]<<" ";
   }
   std::cout<<std::endl;
   std::cout<<"Odvratni: ";
   for(int i(0); i< vek3.size(); i++){
      std::cout<<vek3[i]<<" ";
   }
   return 0;
   }


