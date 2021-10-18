#include<iostream>
#include<vector>
#include<cmath>


std::vector<int> IzdvojiGadne (std::vector<int> v, bool vrsta){
	
	std::vector<int> opaki={};
	std::vector<int> odvratni={};
	std::vector<int> ternarni={};
	

    for(int i=0;i<v.size();i++)
    {
      
      int broj=v[i];
      broj=abs(broj);
      int ost=broj%3;
      int rez=broj/3;
      ternarni.push_back(ost);
      
      while(rez!=0)
      {
      	ost=rez%3;
      	rez=rez/3;
      	ternarni.push_back(ost);
      }
    
      std::vector<int> br={0, 0, 0};
      
      for(int j=0;j<ternarni.size();j++)
      {
      	  for(int k=0;k<=2;k++)
      	  {
      	  	 if(ternarni[j]==k)
      	  	 {
      	  		br[k]++;
      	  	 }
      	  }
      }
      
      
      if((br[0]%2!=0 && br[1]%2!=0 && br[2]%2!=0) || (br[0]%2!=0 && br[1]%2!=0 && br[2]==0) || (br[0]==0 && br[1]%2!=0 && br[2]%2!=0) || (br[0]%2!=0 && br[1]==0 && br[2]%2!=0) || (br[0]%2!=0 && br[1]==0 && br[2]==0) || (br[0]==0 && br[1]%2!=0 && br[2]==0) || (br[0]==0 && br[1]==0 && br[2]%2!=0))
      {
      
      bool ima=false;
      for(int x(0); x<odvratni.size(); x++)
      {
        if(odvratni[x]==v[i]) {
          ima=true;
         break;
        }
      }
      
      if(!ima) 
      odvratni.push_back(v[i]);
      }
      
      else if(br[0]%2==0 && br[1]%2==0 && br[2]%2==0) {
        bool ima1=false;
         
        for(int y(0); y<opaki.size(); y++)
     {
        if(opaki[y]==v[i])
        {
        ima1=true;
        break;
       }
      }
      	if(!ima1)
      	opaki.push_back(v[i]);
      }
      
      
    	
    }

    if(vrsta==true) 
       return opaki;
    else
       return odvratni;

}

int main ()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int x;
	do{
		std::cin>>x;
		if(x==0) break;
		else v.push_back(x);
	} while(x!=0);
	
	std::vector<int> opaki=IzdvojiGadne(v,true);
	std::vector<int> gadni=IzdvojiGadne(v,false);
	std::cout<<"Opaki: ";
	 for(int c : opaki)  std::cout<<c<<" ";
	 std::cout<<std::endl;
	 std::cout<<"Odvratni: ";
     for(int c : gadni)  std::cout<<c<<" ";
        
	return 0;
}

