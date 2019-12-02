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
    friend void InputArray(Matrix Arr[]);
    friend void OutputArray(Matrix Arr[]);
    friend void SortArray(Matrix  Arr[]);
    void CalcArray(Matrix Arr[]);
};

void InputArray(Matrix  Arr[])
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> Arr[i].M[j];
        }
}
void OutputArray(Matrix  Arr[])
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << Arr[j].M[i] << "\t";
        }
        cout << endl;
    }
}
void SortArray(Matrix  arr[])
{
    for (int i = 0; i < n; i++)
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
                    if (arr[LeftBorder + LeftBlockIterator].M[i] < arr[MidBorder + RightBlockIterator].M[i])
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].M[i];
                        LeftBlockIterator++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].M[i];
                        RightBlockIterator++;
                    }
                }
                while (LeftBorder + LeftBlockIterator < MidBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator].M[i];
                    LeftBlockIterator++;
                }
                while (MidBorder + RightBlockIterator < RightBorder)
                {
                    SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator].M[i];
                    RightBlockIterator++;
                }

                for (int MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
                {
                    arr[LeftBorder + MergeIterator].M[i] = SortedBlock[MergeIterator];
                }
                delete SortedBlock;

            }

        }
    }
}
void Matrix::CalcArray(Matrix Arr[]) {
    double SumPidDia[n] = {0, 0, 0, 0, 0};
    for(int j = 0; j < n; j++) {
        for(int i = n; i > n-j-1; i--) {
            SumPidDia[i]+=(Arr[i].M[j]);
        }

    }
    double haunt = 1;
    for (int i = 1; i < n; i++) {
        haunt *= -1*pow(fabs(SumPidDia[i]), 1.0/4.0L);
        std::cout << "f(" << i << "): " << SumPidDia[i] << std::endl;
    }



    cout << "F(f(ij)): " << haunt << endl;


}



int main()
{
    Matrix  Array[n];
    cout << "Enter elements of matrix:\n" << endl;
    InputArray(Array);
    cout << "\nYour matrix:\n" << endl;
    OutputArray(Array);
    SortArray(Array);
    cout << "\nSorted matrix:\n" << endl;
    OutputArray(Array);
    cout << "\nCalculations:\n" << endl;
    Array->CalcArray(Array);
}

