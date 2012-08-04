using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MatrixCompare;

namespace MatrixCompare
{
    class SparseMatrix
    {
        Double[] Elements;
        int[] ColumnIndexes;
        List<int> RowsBegin;

        public SparseMatrix(Matrix matrix)
        {
            int NumOfNotNullElements = 0;
            for (int i = 0; i < matrix.Rows; ++i)
            {
                for (int j = 0; j < matrix.Columns; ++j)
                {
                    if (matrix[i, j] != 0)
                        ++NumOfNotNullElements;
                }
            }

            Elements = new double[NumOfNotNullElements];
            ColumnIndexes = new int[NumOfNotNullElements];
            RowsBegin = new List<int>();
            int k = 0;
            for (int i = 0, temp; i < matrix.Rows; ++i)
            {
                temp = k;
                for (int j = 0; j < matrix.Columns; ++j)
                {
                    if (matrix[i, j] != 0)
                    {
                        Elements[k] = matrix[i, j];
                        ColumnIndexes[k] = j;
                        ++k;
                    }
                }

                if (temp == k)
                    temp = -1;
                RowsBegin.Add(temp);
            }
        }


        public String ToString() 
        {
            String Result = "";

            Result += "Вектор ненулевых элементов:\n";
            for (int i = 0; i < Elements.Length; ++i)
                Result += Convert.ToString(Elements[i]) + "\t";

            Result += "\nВектор номеров столбцов ненулевых элементов:\n";
            for (int i = 0; i < ColumnIndexes.Length; ++i)
                Result += Convert.ToString(ColumnIndexes[i]) + "\t";

            Result += "\nСписок индексов - начала строк с ненулевыми элементами:\n";

            List<int>.Enumerator enumerator = RowsBegin.GetEnumerator();
            for (int i = 0; i < RowsBegin.Count; ++i)
            {
                enumerator.MoveNext();
                Result += Convert.ToString(enumerator.Current) + "\t";
            }
            return Result;
        }

        private SparseMatrix(Double[] Elements, int[] ColumnIndexes, List<int> RowsBegin)
        {
            this.Elements = Elements;
            this.ColumnIndexes = ColumnIndexes;
            this.RowsBegin = RowsBegin;
        }

        public int getSizeOfThis()
        {
            return (Elements.Length + ColumnIndexes.Length + RowsBegin.Count);
        }

        public SparseMatrix MulToVector(Double[] Vector)
        {
            Double[] ResultVector = new Double[RowsBegin.Count];
            int NumOfNotNullElements = 0;

            int RowEnd, RowBegin;
            Double temp;
            List<int>.Enumerator enumerator = RowsBegin.GetEnumerator();
            for (int i = 0; i < RowsBegin.Count; ++i)
            {
                enumerator.MoveNext();
                RowBegin = enumerator.Current;
                if (RowBegin == -1)
                {
                    ResultVector[i] = 0;
                    continue;
                }
                RowEnd = getRowEndIndex(i);
                temp = 0;
                for (int j = RowBegin; j < RowEnd; ++j)
                {
                    temp += Elements[j] * Vector[ColumnIndexes[j]];
                }
                ResultVector[i] = temp;
                if (temp != 0)
                    ++NumOfNotNullElements;
            }


            Double[] ResultElements = new Double[NumOfNotNullElements];
            int[] ResultColumnIndexes = new int[NumOfNotNullElements];
            List<int> ResultRowsBegin = new List<int>();
            for (int i = 0, j = 0; j < NumOfNotNullElements; ++i)
            {
                if (ResultVector[i] != 0)
                {
                    ResultElements[j] = ResultVector[i];
                    ResultColumnIndexes[j] = 0;
                    ResultRowsBegin.Add(j);
                    j++;
                }
                else
                {
                    ResultRowsBegin.Add(-1);
                }
            }

            SparseMatrix ResultMatrix = new SparseMatrix(ResultElements, ResultColumnIndexes, ResultRowsBegin);
            return ResultMatrix;
        }

        private int getRowEndIndex(int Row)
        {
            if (Row == RowsBegin.Count - 1)
            {
                return Elements.Length;
            }
            List<int>.Enumerator enumerator = RowsBegin.GetEnumerator();
            for (int i = 0; i <= Row; ++i)
                enumerator.MoveNext();
            while (enumerator.MoveNext())
            {
                if (enumerator.Current != -1)
                    return enumerator.Current;
            }
            return -1;
        }
    }
}