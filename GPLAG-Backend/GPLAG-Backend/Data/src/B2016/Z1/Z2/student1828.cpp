/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
typedef std::vector<std::vector<double>> Matrica;

Matrica OgledaloMatrica (Matrica XxX){
	if (XxX.size()==0){
		return XxX;
	}
	for (int i=0;i<XxX.size();i++){
	     if (XxX[0].size()!=XxX[i].size()){
	    	throw std::domain_error("Matrica nije korektna");
	    }
		
		
	}
	Matrica Horizontalno(XxX.size(),std::vector<double>(0));
	Matrica Vertikalno;
	Matrica HorVertikalno(XxX.size(),std::vector<double>(0));
	for (int i=0;i<XxX.size();i++){             //horizontalna matricha
	    for (int j=0;j<XxX[i].size();j++){
	    	Horizontalno[i].push_back(XxX[i] [XxX[i].size()-1-j]);
		                }
                     	}
	   for (int i=XxX.size()-1;i>=0;i--){     //vertikalna matricha
	    Vertikalno.push_back(XxX[i]);
	   	                }
	   	for (int i=0;i<Vertikalno.size();i++){      //Horvertikalna matricha samo okrene vertikalnu kao horizontalnu
	   		for (int j=0;j<Vertikalno[i].size();j++){
	   			HorVertikalno[i].push_back(Vertikalno[i] [XxX[i].size()-1-j] );
	   		            }
	   	                }
	   	Matrica Nedobognikom(XxX.size()*3,std::vector<double>(XxX[0].size()*3));
	          for (int i=0;i<Nedobognikom.size();i++){
	          	for (int j=0;j<Nedobognikom[i].size();j++){

                            if (i<HorVertikalno.size() && j<HorVertikalno[i].size()) {
                            Nedobognikom[i][j]=HorVertikalno[i][j];	}
                           else  if ((i<XxX.size())  && (j>=XxX[i].size()) && (j<XxX[i].size()*2)){
	          		     	Nedobognikom[i][j]=Vertikalno[i][j-Vertikalno[i].size()];
	          		    }  else  if ( i<XxX.size()  && j>=XxX[i].size()*2 ){
	          		     	Nedobognikom[i][j]=HorVertikalno[i][j-XxX[i].size()*2];
	          		    }  else  if ( i>=XxX.size() && i<XxX.size()*2 && j<XxX[0].size()) {
	          		 	     Nedobognikom[i][j]=Horizontalno[i-XxX.size()][j];
	          		   } else if (i>=XxX.size()*2 && i<XxX.size()*3 && j>=0 && j<HorVertikalno[0].size()) {
	          		       Nedobognikom[i][j]=HorVertikalno[i-XxX.size()*2][j];
	          		   } else if (i>=XxX.size() && i<XxX.size()*2 && j>=XxX[0].size() && j<XxX[0].size()*2){
	          		   Nedobognikom[i][j]=XxX[i-XxX.size()][j-XxX[0].size()];}
	          		   else if (i>=XxX.size() && i<XxX.size()*2 && j>=XxX[0].size()  && j<XxX[0].size()*3){
	          		   	Nedobognikom[i][j]=Horizontalno[i-XxX.size()][j-XxX[0].size()*2];
	          		   } else if (i>=XxX.size()*2 && i<XxX.size()*3 && j>=XxX[0].size() && j<XxX[0].size()*2){
	          		   	Nedobognikom[i][j]=Vertikalno[i-XxX.size()*2][j-XxX[0].size()];
	          		   } else if (i>=XxX.size()*2 && i<XxX.size()*3 && j>=XxX[0].size()*2 && j<XxX[0].size()*3){
	          		   	Nedobognikom[i][j]=HorVertikalno[i-XxX.size()*2][j-XxX[0].size()*2];
	          		   }
	          		   else Nedobognikom [i][j]=0;

	          	        }
	                    }

	return Nedobognikom;

}

int main ()
{

	int Redovi,Kolone;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>Redovi >>Kolone;
	if (Redovi<0 || Kolone<0){std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0; }
	Matrica Matricazapoziv(Redovi,std::vector<double>(Kolone));
	std::cout<<"Unesite elemente matrice: ";
        for (int i=0;i<Redovi;i++){
        	for (int j=0;j<Kolone;j++){
        		std::cin>>Matricazapoziv[i][j];
        	}
        }
        std::cout<<std::endl;
        std::cout<<"Rezultantna matrica: ";
        std::cout<<std::endl;
        Matrica KrajMatrica(Redovi,std::vector<double>(Kolone));
        try {                       
        KrajMatrica=OgledaloMatrica(Matricazapoziv);
        for (int i=0;i<Redovi*3;i++){
        	for (int j=0;j<Kolone*3;j++){
        		std::cout<<std::setw(4)<<KrajMatrica[i][j];
        	}
        	std::cout<<std::endl;
        }}
        catch(const char Greska []){
        	std::cout<<Greska;
        }
	return 0;
}