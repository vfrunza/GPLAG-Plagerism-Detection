#include <iostream>
#include <vector>
#include <cstdlib>  //u coodeblocksu sam morao ukljuciti ovu bibl. jer funkcija abs nije radila
#include <limits>
std::vector<int> IzdvojiGadne(std::vector<int> v,bool x){
   std::vector<int>opaki ;
   std::vector<int>odvratni ;
   for(auto d:v){
        int nula(0);
        int jedan(0);
        int dva(0);
        int broj;
        broj=d;
        if(d==0){
            bool slucaj(true);
            for(auto k:odvratni){
                if(k==d)slucaj=false;
                else continue;
            }
            if(slucaj)odvratni.push_back(d);
            continue;
        }
        while(broj!=0){                 //broj jedinica, nula , i dvojki smještam u "int" da bi mogao provjeriti opakost/odvratnost
            if( broj%3==2 || broj%3==-2){
                    dva++;
                    broj=broj/3;
                }
                else if(broj%3==1 || broj%3==-1){
                    jedan++;
                    broj=broj/3;
                }
                else if(broj%3==0){
                    nula++;
                    broj=broj/3;
                }
             }
        if(nula%2==0 && jedan%2==0 && dva%2==0) //provjera da li je broj opak
        {                                        //usput ne dozvoljava ponavljanje brojeva
            bool slucaj(true);
            for(auto k:opaki){
                if(k==d)slucaj=false;
                else continue;
            }
            if(slucaj==true)opaki.push_back(d);
        }
        else if(nula%2!=0 && jedan%2!=0 && dva%2!=0){   //provjera da li je broj odvratan i ne dozvoljava ponavljane
            bool slucaj(true);
            for(auto k:odvratni){
                if(k==d)slucaj=false;
                else continue;
            }
            if(slucaj==true)odvratni.push_back(d);
        }
        else if(nula*jedan*dva==0){   //specijalan slucaj kada je broj odvratan
        	if((nula%2!=0 && jedan%2!=0) || (nula%2!=0 && dva%2!=0) || (jedan%2!=0 && dva%2!=0) || (jedan%2!=0 && nula+dva==0) || (dva%2!=0 && jedan+nula==0)){
                bool slucaj(true);
                for(auto k:odvratni){
                    if(k==d)slucaj=false;
                    else continue;
                }
                if(slucaj==true)odvratni.push_back(d);
            }
        	else continue;
        }
        else continue; //ovaj else je eventualno ostavljen da pokupi "GADNE"(ni odvratni ni opaki)
    }
    if(x==false)return odvratni;
    return opaki;
}
int main ()
{
   std::vector<int>a ;
   std::vector<int>b ;
   std::vector<int>c ;
   int x;

   std::cout<<"Unesite brojeve (0 za prekid unosa): ";
   while(std::cin>>x,x!=0){
        a.push_back(x);
   }
   b=IzdvojiGadne(a,true);
   c=IzdvojiGadne(a,false);
   std::cout<<"Opaki: ";
   for(auto g:b){
      std::cout<<g;
      std::cout<<" ";
   }
   std::cout<<std::endl<<"Odvratni: ";
   for(auto p:c){
      std::cout<<p;
      std::cout<<" ";
    }

	return 0;
}