#include <iostream>
#include<vector>
   
 std::vector<int> f(std::vector<int> v) {
        for(int i=0; i<v.size(); i++) {
            for(int j=i+1; j< v.size(); j++)

            if(v[i]==v[j]) {
            
                for(int k=j;k<v.size()-1;k++)
                   v[k]=v[k+1];
                   
                   j--;
                  v.resize( v.size()-1);
            
            }
       }
       return v;
} 

std::vector<int> IzdvojiGadne(std::vector<int> v, bool A) {
     
           v=f(v);
             std::vector<int> Opaki;
             std::vector<int> Odvratni;

        for(int i=0; i<v.size(); i++) {

             int x=v[i];
             if(x<0)x*=-1;
             std::vector<int> v1;

             while(x>0) {
                v1.push_back(x%3);
                x=x/3;
             }


             
             std::vector<int> v_ponavljanja;

             for(int j=0; j<v1.size(); j++) {
                    int brojac=0;
             for(int k=0;k<v1.size(); k++) {

                if(v1[j]==v1[k]) brojac++;
             }
             v_ponavljanja.push_back(brojac);
             }


           if( A==true){
            bool pomocna=true;
            for(int l=0; l<v_ponavljanja.size(); l++)
            if(v_ponavljanja[l]%2!=0) {pomocna=false; break;}
                
                if(pomocna)Opaki.push_back(v[i]);          
           }

            if( A==false){
            bool pomocna=false;
            for(int l=0; l<v_ponavljanja.size(); l++)
            if(v_ponavljanja[l]%2==0) {pomocna=true; break;}
            if(pomocna==false) Odvratni.push_back(v[i]);
            }



        }
       /* Opaki=f(Opaki);
        Odvratni=f(Odvratni); */

        if(A==true) return Opaki;
         else return Odvratni;


}

int main()
{
  
    std::vector<int> v;
    std::cout << "Unesi brojeve (0 za prekid unosa): ";
    int element;
    do {

        std::cin >> element;
        if(element==0) break;
        v.push_back(element);
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    } while(element!=0);
    std::vector<int> v1(v);
   bool A=true;
   std::vector<int> Opaki(IzdvojiGadne(v,A));
   std::cout <<"Opaki su:";
   for(int i=0; i<Opaki.size(); i++) std::cout<<Opaki[i] << " ";

     A=false;

      std::vector<int> Odvratni(IzdvojiGadne(v1,A));
   std::cout <<"Odvratni su:";
   for(int i=0; i<Odvratni.size(); i++) std::cout<<Odvratni[i] << " ";

    return 0;
}
