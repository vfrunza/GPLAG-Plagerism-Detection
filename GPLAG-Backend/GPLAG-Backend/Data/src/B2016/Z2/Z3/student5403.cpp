/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <type_traits>
#include <iomanip>
#include <deque>

template <typename tip>

int SumaCifara(tip broj)
{
	int suma(0);
	while(broj!=0){
		tip ostatak=broj%10;
		suma+=ostatak;
		broj/=10;
	}

	
	return suma;
}

int BrojProstihFaktora(int broj){
   
        int brojac=0;
        int i=1;
            while(i<=broj){
            if(broj%i==0){
                int j=1;
                int k=0;
                    while(j<=i){
                        if(i%j==0){
                            k++;
                        }
                        j++;
                    }
                    if(k==2){
                     brojac++;
                    }
                }
           i++;
            }
        
        
        return brojac;
    }
    

template <typename tip1,typename tip2,typename tip>

std::vector<std::vector<int>> UvrnutaRazlika(tip1 p1, tip1 p2, tip2 p3, tip2 p4, tip fun(tip broj)){
    
std::vector<std::vector<int>> matrix;

  int red(0);
  tip1 pom1,pom2;
  tip2 pom3,pom4;
  pom1=p1;
  pom2=p2;
  pom4=p4;
  
  while(pom1!=pom2){
      bool p=true;
      pom3=p3;
      std::vector<int>pomocni_vektor(0);
      while(pom3!=p4){
          if(BrojProstihFaktora(*pom1)==BrojProstihFaktora(*pom3)){
              p=false;
              break;
          }
          pom3++;
      }
      
      if(p==true){
          pomocni_vektor.push_back(*pom1);
          pomocni_vektor.push_back(BrojProstihFaktora(*pom1));
          matrix.push_back(pomocni_vektor);
      }
      
      pom1++;
  }


while(pom3!=pom4){
    pom1=p1;
      std::vector<int>pomocni_vektor(0);
    bool p=true;
    while(pom1!=pom2){
        if(BrojProstihFaktora(*pom3)==BrojProstihFaktora(*pom1)){
            p=false;
            break;
        }
        pom1++;
    }
    if(p==true){
        pomocni_vektor.push_back(*pom3);
        pomocni_vektor.push_back(BrojProstihFaktora(*pom3));
        matrix.push_back(pomocni_vektor);
    }
    pom3++;
}

    std::sort(matrix.begin(),matrix.end());
    
    return matrix;
    
}

template <typename tip1,typename tip2,typename tip>

std::vector<std::vector<int>> UvrnutiPresjek(tip1 p1, tip1 p2, tip2 p3, tip2 p4, tip fun(tip broj)) {
 
  std::vector<std::vector<int>> matrix;

  int red(0);
  tip1 pom1,pom2;
  tip2 pom3,pom4;
  pom1=p1;
  pom2=p2;
  pom4=p4;
  int i(0);
  
  std::vector<int>pomocni_vektor(0);	
  		
  while(pom1<pom2){
  	 pom3=p3;
  	while(pom3<pom4){
        std::vector<int>pomocni_vektor(0);	

  		if(fun(*pom1)==fun(*pom3)){
  		    
         pomocni_vektor.push_back(*pom1);
		 pomocni_vektor.push_back(*pom3);
  		 pomocni_vektor.push_back(fun(*pom1));
	     matrix.push_back(pomocni_vektor);
        
  			i++;
  			red++;
  		
  		}
  		pom3++;
  	}
  	pom1++;
  }


 
  std::sort(matrix.begin(),matrix.end());
 

  return matrix;
}


int main ()
{
	
	int prvi,drugi;
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>prvi;
	std::vector<int> kontejner1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
    
    int x;
    int vel=0;
	for(int i=0;i<prvi;i++){
       bool p=false;
	   std::cin>>x;
	   for(int j=0;j<vel;j++){
  			if(x==kontejner1[j]){
  			   p=true;
  			   i--;
  				break;
  			}	   	
	   }
        if(p==false){
        vel++;	
       
          kontejner1.push_back(x);
          
          }
		}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>drugi;
	std::vector<int> kontejner2;
	std::cout<<"Unesite elemente drugog kontejnera: ";

	vel=0;
	for(int i=0;i<drugi;i++){
	   bool p=false;
	    std::cin>>x;
	   for(int j=0;j<vel;j++){
  			if(x==kontejner2[j]){
  				p=true;
  			    i--;
  			    break;
  			}	   	
	   }
        if(p==false){
          vel++;
          kontejner2.push_back(x);
	}
	}

	auto uvrnuto=UvrnutiPresjek(std::begin(kontejner1), std::end(kontejner1),std::begin(kontejner2),std::end(kontejner2),SumaCifara<int>);
	std::cout<<std::endl;
	std::cout<<"Uvrnuti presjek glasi: ";
	std::cout<<std::endl;
    for(int i=0;i<uvrnuto.size();i++){
    	for(int j=0;j<3;j++){
    		std::cout<<std::left<<std::setw(6)<<uvrnuto[i][j];
    	}
    	std::cout<<std::endl;
    }
    std::cout<<"Uvrnuta razlika glasi: ";
    std::cout<<std::endl;
    auto razlika=UvrnutaRazlika(std::begin(kontejner1), std::end(kontejner1),std::begin(kontejner2),std::end(kontejner2),SumaCifara<int>);
    
    std::cout<<std::endl;
    for(int i=0;i<razlika.size();i++){
        for(int j=0;j<2;j++){
            std::cout<<std::left<<std::setw(6)<<razlika[i][j];
        }
        std::cout<<std::endl;
    }
	
	return 0;
}