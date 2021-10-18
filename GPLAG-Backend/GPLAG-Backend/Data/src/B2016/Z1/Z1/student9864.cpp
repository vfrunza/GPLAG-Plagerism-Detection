#include <iostream>
#include <vector>
#include <deque>

std::vector<int> IzdvojiGadne (std::vector<int> v, bool slucaj){
	std::vector<int> rezultat;
	for(int i{};i<v.size();i++){ 
		int pomocni=v[i];
		std::deque<int> t;
	
	do{
	    int a;
	    a=pomocni%3;
	   t.push_front(a);
	   pomocni/=3;
   }while(pomocni>0);
    int brojac=0;
    for(int j=0;j<t.size();j++){
        if(t[j]==t[j+1])
        brojac ++;
}
       if(slucaj==true){
      if(brojac%2 != 0)
      rezultat.push_back(v[i]);
   }
   else{
   if(brojac%2 == 0 || brojac==0)
   rezultat.push_back(v[i]);
   }
}
   return rezultat;  
}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    std::vector <int> v;
    while(true)
    {
        int x;
        std::cin>>x;
        
        if(x==0)
        break;
        
        v.push_back(x);
    }
    auto ispis=IzdvojiGadne (v,true);
    std::cout<<"Opaki: ";
   for(int x : ispis )
   std::cout<<x<<" ";
   std::cout<<std::endl;
    ispis=IzdvojiGadne (v,false);
   std::cout<<"Odvratni: ";
   for(int x : ispis)
       std::cout<<x<<" ";
   std::cout<<std::endl;
  
	return 0;
}