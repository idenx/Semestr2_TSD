using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSD_8
{

    class Info
    {
        private int data;

        public int Data
        {
            get
            {
                return this.data;
            }

            set
            {
                this.data = value;
            }
        }

        public Info(int Key)
        {
            this.data = Key;
        }

        public Info()
        {

        }
    }

    class OAHashTable
    {
        protected Info[] Table;
        protected int Size;
        public OAHashTable()
        {

        }

        public OAHashTable(int Size)
        {
            this.Size = Size;
            Table = new Info[Size];
        }

        private int DoubleHash(Info Key, int Offset)
        {
            return (HashFunction1(Key) + Offset * HashFunction2(Key)) % Size;
        }

        private int HashFunction1(Info Key)
        {
            int a = 3, b = 7;
            int p = 211;
            return ((a * Key.Data + b) % p) % Size;
        }

        private int HashFunction2(Info Key)
        {
            int a = 5, b = 11;
            int p = 199;
            return 1 + ((a * Key.Data + b) % p) % (Size - 1);
        }

        public int Search(Info Key)
        {
            int Index, Offset = 0;
            do
            {
                Index = DoubleHash(Key, Offset);
                if (Table[Index] == null)
                    return -1;
                if (Table[Index].Data == Key.Data)
                    return Index;
                else
                    ++Offset;
            } while (Table[Index] != null && Offset != Size);
            return -1;
        }

        public void Insert(Info Key)
        {
            int Index, Offset = 0;
            do
            {
                Index = DoubleHash(Key, Offset);
                if (Table[Index] == null)
                {
                    Table[Index] = Key;
                    return;
                }
                else
                    ++Offset;
            } while (Offset != Size);
            Error err = new Error("Переполнение хеш-таблицы!");
            throw err;
        }

        public int getMemory()
        {
            return this.Size * sizeof(int);
        }

        public override String ToString()
        {
            StringBuilder Result = new StringBuilder();
            Result.Append(" # Key\r\n");
            String tmp;
            for (int i = 0; i < Size; ++i)
            {
                if (Table[i] != null)
                    tmp = Table[i].Data.ToString();
                else
                    tmp = "null";
                Result.Append(i.ToString() + "   " + tmp + "\r\n");
            }

            return Result.ToString();
        }
    }

    class CAHashTable
    {
        int Size;
        List<int>[] Table;

        public CAHashTable()
        {

        }

        public CAHashTable(int Size)
        {
            this.Size = Size;
            this.Table = new List<int>[Size];
        }

        public int Search(int Key)
        {
            int Index = 0;
            Index = HashFunction(Key);
            if (Table[Index] == null)
                return -1;
            foreach (int value in Table[Index])
                if (value == Key)
                    return Index;
            return -1;
        }

        public void Insert(int Key)
        {
            int Index = 0;
            Index = HashFunction(Key);
            if (Table[Index] == null)
            {
                List<int> list = new List<int>();
                list.Add(Key);
                Table[Index] = list;
            }
            else
                Table[Index].Add(Key);
        }

        private int HashFunction(int Key)
        {
            int a = 37, b = 101;
            int p = 211;
            return ((a * Key + b) % p) % Size;
        }

        public override String ToString()
        {
            StringBuilder Result = new StringBuilder();
            Result.Append(" # Key\r\n");
            String tmp;
            for (int i = 0; i < Size; ++i)
            {
                if (Table[i] != null)
                {
                    tmp = "";
                    for (int j = 0; j < Table[i].Count - 1; ++j)
                        tmp += Table[i][j] + " -> ";
                    tmp += Table[i][Table[i].Count - 1];
                }
                else
                    tmp = "null";
                Result.Append(i.ToString() + "   " + tmp + "\r\n");
            }

            return Result.ToString();
        }

        public int getMemory()
        {
            int size = 0;
            for (int i = 0; i < this.Size; ++i)
            {
                if (Table[i] != null)
                    size += Table[i].Count * (4 + sizeof(int));
                size += 4;
            }
            return size;
        }
    }
}
