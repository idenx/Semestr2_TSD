using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MatrixCompare
{
    class Matrix
    {
        double[,] matrix;
        int RowsNum, ColsNum;

        public Matrix(int RowsNum, int ColsNum)
        {
            this.RowsNum = RowsNum;
            this.ColsNum = ColsNum;
            this.matrix = new double[RowsNum, ColsNum];
        }

        public Matrix(String StrWithMatrix)
        {
            String[] Rows = StrWithMatrix.Split('\n');
            String[] Elems = Rows[0].Split(' ');
            this.matrix = new double[Rows.Length, Elems.Length];
            this.RowsNum = Rows.Length;
            this.ColsNum = Elems.Length;
            for (int i = 0; i < Rows.Length; ++i)
            {
                Elems = Rows[i].Split(' ');
                for (int j = 0; j < Elems.Length; ++j)
                {
                     Double.TryParse(Elems[j], out this.matrix[i, j]);
                }
            }
        }

        public double this[int i, int j]
        {
            set { matrix[i, j] = value; }
            get { return matrix[i, j]; }
        }

        public int Rows
        {
            get { return RowsNum; }
        }

        // Возвращает число столбцов в матрице
        public int Columns
        {
            get { return ColsNum; }
        }

        public unsafe Matrix MulToVector(Double[] Vector)
        {
            Double temp;
            int RowsCount = RowsNum;
            int ColsCount = ColsNum;
            Matrix Result = new Matrix(RowsCount, 1);
            for (int i = 0; i < RowsCount; ++i)
            {
                temp = 0;
                for (int j = 0; j < ColsCount; ++j)
                {
                    temp += this.matrix[i, j] * Vector[j];
                }
                Result[i, 0] = temp;
            }
            return Result;
        }

        public int getSizeOfThis()
        {
            return (RowsNum * ColsNum + sizeof(int) * 2);
        }

        public override  String ToString()
        {
            String Result = "";
            for (int i = 0; i < this.RowsNum; ++i)
            {
                for (int j = 0; j < this.ColsNum - 1; ++j)
                {
                    Result += Convert.ToString(matrix[i, j]) + "\t";
                }
                Result += Convert.ToString(matrix[i, this.ColsNum - 1]) + "\n";
            }
            return Result;
        }

        public void GenerateRandom(int Percentage)
        {
            const int MAX_VALUE = 8;
            const int PERCENTS = 100;
            int RandValue;
            Random rand = new Random();
            for (int i = 0; i < this.RowsNum; ++i)
            {
                for (int j = 0; j < this.ColsNum; ++j)
                {
                    RandValue = rand.Next(PERCENTS);  // [0; 100]
                    if (RandValue < Percentage)
                    {
                        matrix[i, j] = rand.Next(MAX_VALUE) + 1; // [1; MAX_VALUE + 1]
                    }
                    else
                    {
                        matrix[i, j] = 0;
                    }
                }
            }
        }

        public int getNullPercantage()
        {
            int NullElements = 0;
            for (int i = 0; i < RowsNum; ++i)
            {
                for (int j = 0; j < ColsNum; ++j)
                {
                    if (matrix[i, j] == 0)
                        ++NullElements;
                }
            }

            return 100 * NullElements / (RowsNum * ColsNum);
        }
    }
}
