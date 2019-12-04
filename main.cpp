#include <iostream>
#include <math.h>
#include <conio.h>
#define _USE_MATH_DEFINES

#define n 5
#define m 5
using namespace std;

class Matrix
{
private:
    double M[m];
public:
    friend void inputArray(Matrix Array[]);
    friend void outputArray(Matrix Array[]);
    friend void sortArray(Matrix  Array[]);
    void calcArray(Matrix Array[]);
};

void inputArray(Matrix  Array[])
{
    for (int row = 0; row < n; ++row)
        for (int column = 0; column < m; ++column)
        {
            cin >> Array[row].M[column];
        }
}
void outputArray(Matrix  Array[])
{
    for (int row = 0; row < n; ++row)
    {
        for (int column = 0; column < m; ++column)
        {
            cout << Array[column].M[row] << "\t";
        }
        cout << endl;
    }
}
void sortArray(Matrix  array[])
{
    for (int row = 0; row < n; row++)
    {
        for (int BlockSizeIterator = 1; BlockSizeIterator < n; BlockSizeIterator *= 2)
        {
            for (int BlockIterator = 0; BlockIterator < n - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
            {
                int LeftBlockIterator = 0;
                int RightBlockIterator = 0;
                int LeftBorder = BlockIterator;
                int MidBorder = BlockIterator + BlockSizeIterator;
                int RightBorder = BlockIterator + 2 * BlockSizeIterator;
                RightBorder = (RightBorder < n) ? RightBorder : n;
                int* SortedBlock = new int[RightBorder - LeftBorder];

                while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
                {
                    if (array[LeftBorder + LeftBlockIterator].M[row] < array[MidBorder + RightBlockIterator].M[row])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = array[LeftBorder + LeftBlockIterator].M[row];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = array[MidBorder + RightBlockIterator].M[row];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = array[LeftBorder + LeftBlockIterator].M[row];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = array[MidBorder + RightBlockIterator].M[row];
                    RightBlockIterator++;
                }

                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    array[LeftBorder + MergeIterator].M[row] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;

            }

        }
    }
}
void Matrix::calcArray(Matrix Array[]) {
    double sumUnderDiagonal[n] = {0, 0, 0, 0, 0};
    for(int column = 0; column < n; column++) {
        for(int row = n; row > n-column-1; row--) {
            sumUnderDiagonal[row]+=(Array[row].M[column]);
        }

    }
    double haunt = 1;
    for (int row = 1; row < n; row++) {
        haunt *= -1*pow(fabs(sumUnderDiagonal[row]), 1.0/4.0L);
        std::cout << "f(" << row << "): " << sumUnderDiagonal[row] << std::endl;
    }



    cout << "F(f(rowcolumn)): " << haunt << endl;


}



int main()
{
    Matrix  Array[n];
    cout << "Enter elements of matrix:\n" << endl;
    inputArray(Array);
    cout << "\nYour matrix:\n" << endl;
    outputArray(Array);
    sortArray(Array);
    cout << "\nSorted matrix:\n" << endl;
    outputArray(Array);
    cout << "\nCalculations:\n" << endl;
    Array->calcArray(Array);
}

