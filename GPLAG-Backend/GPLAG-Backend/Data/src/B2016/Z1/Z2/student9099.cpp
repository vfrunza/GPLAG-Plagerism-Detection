#include<iostream>
#include<vector>
const int r = 2, k = 3;

std::vector<std::vector<double>> OgledaloMatrica(double mat[][k]){
    double h[r][k], v[r][k], hv[r][k], OM[3*r][3*k];
    int r2=0, k2=0;
    for (int i = 0; i < r; i++)
    {
        for (int j=k-1;j>=0;j--)
        {
            h[i][j]=mat[i][k2];
            k2++;
        }
        k2=0;
    } 
    for(int i=r-1;i>=0;i--)
    {
        for(int j=0;j<k;j++)
        {
            v[i][j]=mat[r2][j];
		}
        r2++;
    } 


    for(int i=0;i<r;i++)
    {
        for(int j=k-1;j>=0;j--)
        {
            hv[i][j]=v[i][k2];
            k2++;
        }
        k2=0;
    } 

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<k;j++)
            {
                OM[i][j] = hv[i][j];
                OM[i + r][j] = h[i][j];
                OM[i + r + r][j] = hv[i][j];
                OM[i][j+k] = v[i][j];
                OM[i][j+k+k] = hv[i][j];
                OM[i + r][j+k] = mat[i][j];
                OM[i + r][j + k + k] = h[i][j];
                OM[i + r + r][j + k] = v[i][j];
                OM[i + r + r][j + k + k] = hv[i][j];
            }
        } 

return OM;
     
}

int main() {
    std::vector<std::vector<double>> mat(OgledaloMatrica (r ,k) 
     for (int i = 0; i < 3*r; i++)
        {
            for (int j = 0; j < 3*k; j++)
            {
                std::cout << OM[i][j] << " ";
            }
            std::cout << std::endl;
        }

        return 0;

    return 0;
}