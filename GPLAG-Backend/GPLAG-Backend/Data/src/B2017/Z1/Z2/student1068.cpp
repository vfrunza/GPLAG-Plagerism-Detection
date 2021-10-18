#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define EMPTY_MATRIX {}

// Less typing.
typedef std::vector<std::vector<double>> matrix;

bool isEmpty(matrix m)
{
    if (m.size() == 0)
        return true;
        
    for (int y(0); y < m.size(); y++)
        if (m.at(y).size() != 0)
            return false;
    
    return true;
}

bool isRagged(matrix m)
{
    int n_columns(m.at(0).size());
    for (int y(1); y < m.size(); y++)
        if (m.at(y).size() != n_columns)
            return true;
    
    return false;
}

bool canCreateSquareWithRadiusR(matrix source, int x, int y, int r)
{
    return (((x + r < source.at(0).size()) && (x - r >= 0)) && ((y + r < source.size()) && (y - r >= 0)));
}

bool firstPeakIsHigherThanSecondOne(matrix m1, matrix m2)
{
    return (m1.at(m1.size() / 2).at(m1.size() / 2) > m2.at(m2.size() / 2).at(m2.size() / 2));
}

bool equalPeaks(matrix m1, matrix m2)
{
    return (m1.at(m1.size() / 2).at(m1.size() / 2) == m2.at(m2.size() / 2).at(m2.size() / 2));
}

matrix getMountain(matrix source, int x, int y)
{
    int radius(1);
    long double peak(source.at(y).at(x));
    
    while (canCreateSquareWithRadiusR(source, x, y, radius))
    {
        long double sum(0);
        
        for (int i(x - radius); i <= x + radius; i++)
        {
            sum += source.at(y - radius).at(i);
            sum += source.at(y + radius).at(i);
        }
        
        for (int i(y - radius + 1); i <= y + radius - 1; i++)
        {
            sum += source.at(i).at(x - radius);
            sum += source.at(i).at(x + radius);
        }
        
        if (sum < peak)
        {
            peak = sum;
            radius++;
        }
        else
            break;
    }
    radius--;
    
    if (radius == 0)
        return matrix {{source.at(y).at(x)}};
    
    matrix mountain;
    for (int i(y - radius); i <= y + radius; i++)
    {
        std::vector<double> row;
        for (int j(x - radius); j <= x + radius; j++)
            row.push_back(source.at(i).at(j));
            
        mountain.push_back(row);
    }
    
    return mountain;
}

matrix NajvecaPlaninaMatrice(matrix source)
{
    if (isEmpty(source))
        return matrix EMPTY_MATRIX;
    
    if (isRagged(source))
        throw std::domain_error("Matrica nije korektna\n");
    
    int n_rows(source.size()), n_columns(source.at(0).size());
    int peak_x, peak_y;
    
    matrix current_largest_mountain;
    for (int y(0); y < n_rows; y++)
    {
        for (int x(0); x < n_columns; x++)
        {
            matrix new_mountain(getMountain(source, x, y));
            if (new_mountain.size() > current_largest_mountain.size())
            {
                current_largest_mountain = std::move(new_mountain);
                peak_x = x;
                peak_y = y;
            }
            else if (new_mountain.size() == current_largest_mountain.size())
                if (firstPeakIsHigherThanSecondOne(new_mountain, current_largest_mountain))
                {
                    current_largest_mountain = std::move(new_mountain);
                    peak_x = x;
                    peak_y = y;
                }
                else if (equalPeaks(new_mountain, current_largest_mountain))
                    if (x < peak_x)
                    {
                        current_largest_mountain = std::move(new_mountain);
                        peak_x = x;
                        peak_y = y;
                    }
                    else if (x == peak_x)
                        if (y < peak_y)
                        {
                            current_largest_mountain = std::move(new_mountain);
                            peak_x = x;
                            peak_y = y;
                        }
        }
    }
    
    return current_largest_mountain;
}

int main (void)
{
    int columns, rows;
    std::cout << "Unesite dimenzije matrice (m i n): ";
    
    std::cin >> rows >> columns;
    if (rows < 0 || columns < 0)
    {
        std::cout << "Dimenzije matrice moraju biti nenegativne!\n";
        return -1;
    }
    
    double input;
    matrix input_matrix(rows, std::vector<double>());
    std::cout << "Unesite elemente matrice: \n"; 
    for (int y(0); y < rows; y++)
        for (int x(0); x < columns; x++)
        {
            std::cin >> input;
            input_matrix.at(y).push_back(input);
        }
    
    matrix largestMountain(NajvecaPlaninaMatrice(input_matrix));
    std::cout << "\nNajveca planina unesene matrice je:" << std::endl;
    for (int y(0); y < largestMountain.size(); y++)
    {
        for (int x(0); x < largestMountain.at(0).size(); x++)
                std::cout << std::setw(6) << largestMountain.at(y).at(x);
        
        std::cout << std::endl;     
    }
    
	return 0;
}