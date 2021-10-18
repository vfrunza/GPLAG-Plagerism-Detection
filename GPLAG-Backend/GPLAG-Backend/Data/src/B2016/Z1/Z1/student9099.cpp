#include<iostream>
#include<vector>
#include<cmath>
bool JelOpak(int n){
    int rem;
    std::vector<int> vektorostatka;
   n=abs(n);

for(;;) {
       if(n<=0) break; 
        rem=n%3; 
        vektorostatka.push_back(rem);
        n=n/3;
}
for(int i=0; i<vektorostatka.size(); i++)
std::cout<<vektorostatka[i];


for(int i(0); i < vektorostatka.size(); i++)
    {
        int z = 0;
        for(int j(0); j < vektorostatka.size(); j++)
        {
            if(vektorostatka[i] == vektorostatka[j])
                z++;
            
            if(z % 2 == 0)
                continue;
            else
                return false;
        }
    }
   
    
    return true;
    
}

std::vector<int> IzdvojiGadne(std::vector<int> vektor, bool check){
	std::vector<int> vektoropakih;
	std::vector<int> vektorodvratnih;
	for(int m : vektor){
      if(JelOpak(m) && check==true) vektoropakih.push_back(m);
      else if 
        (!JelOpak(m) && check==false) vektorodvratnih.push_back(m);
   }

   if (check) 
    return vektoropakih;
   else  
    return vektorodvratnih;
}

int main ()
{
 int input;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::cin>>input;
	std::vector<int> vektora;
	 while ((std::cin >> input) && input != 0)
    vektora.push_back(input);
   
   std::vector<int> vektorb(IzdvojiGadne(vektora,true));
   if(vektorb.size() == 0) std::cout<<std::endl;
   else 
    std::cout<<"Opaki: ";
    for ( int i : vektorb) 
    
    std::cout<<i<<" ";
    std::cout<<std::endl;

   
   std::vector<int> vektorc(IzdvojiGadne(vektora,false));
   if (vektorc.size() == 0) 
    std::cout<<std::endl;
   else 
   std::cout<<"Odvratni: ";
    for(int j : vektorc) 
    std::cout<<j<<" ";
    std::cout<<std::endl;
	JelOpak(56);
	return 0;
}
