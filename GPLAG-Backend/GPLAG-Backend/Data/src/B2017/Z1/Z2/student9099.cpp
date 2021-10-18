#include <cstdio>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;

double  Suma(Matrica MM, int xx, int yy, int rr, bool& oop )
{
	int ddy=MM.size();

	int ddx=MM.at(0).size();
	
	
	long double ssuma=0;
   
    oop =    (xx - rr >=0) && (ddx - xx - rr - 1 >=0) 
   	      && (yy - rr >=0) && (ddy - yy - rr - 1 >=0);
   	
   	
   	if(!oop) {
   		return -100;
   	}
	else {
		for(int xi=xx-rr;xi<=xx+rr;xi++){
			ssuma = ssuma + MM.at(yy-rr).at(xi) + MM.at(yy+rr).at(xi); 
		}	
		for(int yi=yy-rr+1;yi<=yy+rr-1;yi++){
			ssuma = ssuma + MM.at(yi).at(xx-rr) + MM.at(yi).at(xx+rr); 
		}	
	}
	
    return ssuma;	
}

Matrica NajvecaPlaninaMatrice(Matrica M)
{

	
  for(int i=0;i<M.size();i++){
	if((M.at(i).size())!=M.at(0).size()){
		throw std::domain_error("Matrica nije korektna");
	}
  }
	
  Matrica IM;
	
  if (M.size() > 0) {
	
	int dy=M.size();
	
	int dx=M.at(0).size();
	
	int mx;
	int my;
	long double mxy;
	bool mxyIsDefined = false;
	int mr=-1;
	long double s;
	long double ps;
	bool op;
	int r;
	
	for(int y=0;y<dy;y++){
		for(int x=0;x<dx;x++){
			
			r=0;
			s=M.at(y).at(x);
			
			do{
			   r++;
			   ps=s;
			   s=Suma(M,x,y,r,op);
			} while (op && (ps>=s));
			
			r--;
			if(r>=0){
				if (  
				       (r>mr)
				    || ((r==mr)&&mxyIsDefined&&(M.at(y).at(x)>mxy))
				    || ((r==mr)&&mxyIsDefined&&(M.at(y).at(x)==mxy)&&(y<my))
				    || ((r==mr)&&mxyIsDefined&&(M.at(y).at(x)==mxy)&&(y==my)&&(x<mx))
				  ){
					mr=r;
					mx=x;
					my=y;
					mxy=M.at(y).at(x);
					mxyIsDefined = true;
				}
			}
		}
	}
	
	if(mr>=0){
        std::vector<double> red; 
		for(int y=my-mr; y<=my+mr; y++){
			for(int x=mx-mr; x<=mx+mr; x++){
				red.push_back(M.at(y).at(x));
			}
			IM.push_back(red);
			red.clear();
		}

	}
  }
  return IM;	
}
	
	
	

int main ()
{
	try{

	Matrica Mat;
	int m;
	int n;
	
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m;
	std::cin>>n;
	
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		std::cout<<std::endl;
	}
	else
	{
	    if (m==0 && n==0) {
		}
		else
		{
			std::cout<<"Unesite elemente matrice:";
	
			for(int i=0;i<m;i++){
				Mat.push_back(std::vector<double>());
				for(int j=0;j<n;j++){
					double element;
					std::cin>>element;
					Mat.at(i).push_back(element);
				}
			}
	
		}
		Matrica MF(NajvecaPlaninaMatrice(Mat));
		std::cout<<"\nNajveca planina unesene matrice je:"<<std::endl;
	
		for(int i=0;i<MF.size();i++){
			for(int j=0;j<MF.at(i).size();j++){
				std::cout<<std::setw(6)<<MF.at(i).at(j);
			}
			std::cout<<std::endl;
		}
	}
	
} catch(std::domain_error except){
	std::cout<<except.what()<<std::endl;
}
	
	
	return 0;
}