#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
   std::string ObrniFraze ( std::string S ,std::vector<std::string> VS )   {
        int i,j,z,help;
        
        for ( i = 0 ; i < VS.size() ; i++ ) {
            
            for ( j = 0 ; j < VS[i].size() ; j++ )  
            if (!(VS[i][j] >= 'A' && VS[i][j] <='Z' || VS[i][j] >='a' && VS[i][j] <='z' || VS[i][j] == ' ' || VS[i][j] == '\t')) throw std::domain_error("Nekorektan izbor rijeci");
        }
        for (  i = 0 ; i < VS.size() ; i++ ) {
             for (  j = 0 ; j < S.size(); j++ ) {
                         z = j;
                         help = 0;
                while ( S[j] == VS[i][help] && help < VS[i].size())    {
                    help++;
                    j++;
                }
            
             
            if ( help == VS[i].size() )    {
                    int t = 1;
                for ( int k = z; k < z+(help/2) ; k++ ) {
                    int temp;
                    temp = S[k];
                    S[k] = S[z+help-t];
                    S[z+help-t] = temp;
                    t++;
                }
            }


            }   
           
            
        }
        
    return S;
}
    
       std::string IzmijeniUPigLatin( std::string S ,std::vector<std::string> VS )   {
        
    int i,j,z,help;
    
         for ( i = 0 ; i < VS.size() ; i++) {
             for ( j = 0 ; j < VS[i].size(); j++)   {
                 if ( VS[i][j] == ' ') throw std::domain_error("Nekorektan izbor rijeci");
             }
         }
    
         for ( i = 0 ; i < VS.size() ; i++ ) {
            
            for ( j = 0 ; j < VS[i].size() ; j++ )  
            if (!((VS[i][j] >= 'A' && VS[i][j] <='Z') || (VS[i][j] >='a' && VS[i][j] <='z') || (VS[i][j] == ' ') || (VS[i][j] == '\t'))) throw std::domain_error("Nekorektan izbor rijeci");
        }
    
        if ( VS.size() == 1 )   {
            
            for ( i = 0 ; i < S.size() ; i++ ) {
                    z = i;
                    help = 0;
                while ( S[i] != ' ' && i < S.size() ) {
                    help++;
                    i++;
                }
                    int t = 0;
                for ( int k = z; k < z+(help/2) ; k++ ) {
                    int temp;
                    temp = S[k];
                    if ( t == 0 )   {
                   S.erase(S.begin()+k);
                   S.insert(S.begin()+help+k-1,temp);    
                   S.insert(S.begin()+help+k,'a');
                   S.insert(S.begin()+help+k+1,'y');

                    }
                    t++;
                   
                }
            }
        
            return S;
        }
        for (  i = 0 ; i < VS.size() ; i++ ) {
             for (  j = 0 ; j < S.size(); j++ ) {
                         z = j;
                         help = 0;
                         int brojac = 0;
                         if ( j == 0 )  {
                while ( S[j] == VS[i][help] && help < VS[i].size())    {
                    help++;
                    j++;
                    brojac++;
                }
                    }
                            if ( j > 0  && brojac == 0)  {
                                if ( S[j-1] == ' ') {        
                while ( S[j] == VS[i][help] && help < VS[i].size())    {
                    help++;
                    j++;
                }
            }
        }
                    
                    

                   if ( help == VS[i].size() )    {
                    int t = 0;
                for ( int k = z; k < z+(help/2) ; k++ ) {
                    int temp;
                    temp = S[k];
                    if ( t == 0 )   {
                   S.erase(S.begin()+k);
                   S.insert(S.begin()+help+k-1,temp);    
                   S.insert(S.begin()+help+k,'a');
                   S.insert(S.begin()+help+k+1,'y');

                    }
                    t++;
                 }
            }

        }   
            
         
    }
            
        
            
        
            
            
        
        
        
        return S;
        
    }
    


int main ()
{
    std::cout<<"Unesite recenicu: ";
	std::string S;
	std::string Novi;
	std::string Pomocni;
	std::getline(std::cin,S);
	std::vector<std::string>VS;
	int i = 0;
	std::cout<<"Unesite fraze: ";
	for (;;)    {
	    Novi = Pomocni;
	   std::getline(std::cin,Novi);
	   VS.push_back(Novi);
       if ( VS[i].size() == 0 )  break;
       
	   i++;
	}
    std::string PIG;
     try {
         try{
    PIG = IzmijeniUPigLatin(S,VS);
     std::cout<<"Recenica nakon PigLatin transformacije: ";
    std::cout<<PIG<<std::endl;

         }
         catch(std::domain_error izuzetak)  {
             std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
         }
         
     }
   	catch (std::domain_error greska1)	{
		std::cout<<"Izuzetak: "<<greska1.what()<< std::endl;
	}
     
     try {
    std::string FRAZA;
    FRAZA = ObrniFraze(S,VS);
     std::cout<<"Recenica nakon obrtanja fraza: ";
    std::cout<<FRAZA;
 }
   	catch (std::domain_error greska2)	{
		std::cout<<"Izuzetak: "<<greska2.what()<< std::endl;
	}




	return 0;
}