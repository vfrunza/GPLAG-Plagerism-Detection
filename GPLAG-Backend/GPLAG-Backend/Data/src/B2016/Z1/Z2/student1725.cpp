#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> M) {
    typedef std::vector<std::vector<double>> Matrica;
        
        int brojac{0};
        for(auto red:M) {
            for(auto x:red) brojac++;
        }
        
        if(brojac==0)  return M;
        
        
        Matrica h,v,hv,konacna;
        
        
        
        // HORIZONTALNA MATRICA
        
        h.resize(M.size());
        
        for(int i=0;i<M.size();i++) {
            for(int j=0;j<M[i].size();j++) 
                h[i].push_back(M[i][M[i].size()-j-1]);
               
        }
 
        // VERTIKALNA MATRICA
         
        v.resize(M.size());
         
        for(int i=0;i<M.size();i++) {
            for(int j=0;j<M[i].size();j++) 
                v[i].push_back(M[M.size()-i-1][j]);
        }
        
        //KOMBINOVANA MATRICA
        hv.resize(M.size());
        
        for(int i=0;i<M.size();i++) {
            for(int j=0;j<M[i].size();j++) 
                hv[i].push_back(h[i][j]);
        }
            
        for(int i=0;i<(hv.size()/2);i++) {
           for(int j=0;j<M[i].size();j++) {
                double temp{hv[i][j]};
                hv[i][j]=hv[hv.size()-i-1][j];
                hv[hv.size()-i-1][j]=temp;
        }
        }
    
        // KONACNA MATRICA
        konacna.resize(3*M.size());
        
        for(int i=0;i<M.size();i++) {
            for(int j=0;j<3*M[i].size();j++) {
                if(j<M[i].size()) konacna[i].push_back(hv[i][j]);
                    else if(j>=M[i].size() && j<2*M[i].size()) konacna[i].push_back(v[i][j-M[i].size()]);
                        else konacna[i].push_back(hv[i][j-2*M[0].size()]);
            }
        }
                
        for(int i=M.size();i<2*M.size();i++) {
            for(int j=0;j<3*M[0].size();j++) {
                if(j<M[0].size()) konacna[i].push_back(h[i-M.size()][j]);
                   else if(j>=M[0].size() && j<2*M[0].size()) konacna[i].push_back(M[i-M.size()][j-M[0].size()]);
                       else konacna[i].push_back(h[i-M.size()][j-2*M[0].size()]);
            }
        }
                
                
        for(int i=2*M.size();i<3*M.size();i++) {
            for(int j=0;j<3*M[0].size();j++) {        
                if(j<M[0].size()) konacna[i].push_back(hv[i-2*M.size()][j]);
                    else if(j>=M[0].size() && j<2*M[0].size()) konacna[i].push_back(v[i-2*M.size()][j-M[0].size()]);
                        else konacna[i].push_back(hv[i-2*M.size()][j-2*M[0].size()]);
            }
        }

         
        return konacna;

}

int main () {
    int n,m;
    
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    
    if(m<0 || n<0) {
        std::cout<<"Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
  
        
    typedef std::vector<std::vector<double>> Matrica; 
    Matrica M(m,std::vector<double>(n));
    
    std::cout<<"Unesite elemente matrice: "<<std::endl;;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++)
            std::cin>>M[i][j];
    }
    
    std::cout<<"Rezultantna matrica: "<<std::endl;
    
    for(auto red:OgledaloMatrica(M)) {
        for(auto x:red) std::cout<<std::setw(4)<<std::setprecision(0)<<std::fixed<<x;
            std::cout<<std::endl;
    }
   
	return 0;
}