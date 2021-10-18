/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<cmath>


std:: vector<int> IzdvojiGadne(std::vector<int>v, bool n){
	
	std::vector<int>gadni;
	 
    for(int i=0;i<v.size();i++){
      int brojacnula=0;
      int brojacjedan=0;
      int brojacdva=0;
      int y=abs(v[i]);
      while(y!=0){
          int ostatak=y%3;
          if(ostatak==2) brojacdva++;
          else if(ostatak==1) brojacjedan++;
          	else if(ostatak==0) brojacnula++;
         y=y/3;
     }
     
     if(brojacnula%2==0 && brojacjedan%2==0 && brojacdva%2==0 && n) gadni.push_back(v[i]);
     if((brojacjedan==0 || brojacjedan%2==1) && (brojacnula==0 || brojacnula%2==1) &&(brojacdva==0|| brojacdva%2==1) && !n) gadni.push_back(v[i]);
 }
 if(gadni.size()==0 || gadni.size()==1) return gadni;
  for(int i=0;i<gadni.size()-1;i++){
        for(int j=i+1;j<gadni.size();j++){
            if(gadni[i]==gadni[j]){
                gadni.erase(gadni.begin()+j);
                j--;
            } 
        }
}

     
	 
return gadni;
	
}	
int main (){
    std::vector<int>v;
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    int broj;
    std::cin>>broj;
    while(broj!=0){
        v.push_back(broj);
        std::cin>>broj;
    }
    //for(int x: v) std::cout<<x<<" ";
    
    
    auto opaki=IzdvojiGadne(v,1);
    auto odvratni=IzdvojiGadne(v,0);
    
    std::cout<<"Opaki: ";
    for(int x:opaki) std::cout<<x<<" ";
    std::cout<<std::endl<<"Odvratni: ";
    for(int x: odvratni) std::cout<<x<<" ";
    
	return 0;
}