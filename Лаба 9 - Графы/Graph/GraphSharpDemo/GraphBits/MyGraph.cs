using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using QuickGraph;

namespace GraphSharpDemo
{
    public class MyGraph : BidirectionalGraph<PocVertex, PocEdge>
    {

        public int[,] Lengths;
        public int[,] Taxes;
        private int VertexCount;
        private const int MaxSize = 64;

        private int Count
        {
            get
            {
                return VertexCount++;
            }
        }

        public MyGraph(bool flag) : base(flag)
        {
            Lengths = new int[MaxSize, MaxSize];
            Taxes = new int[MaxSize, MaxSize];
            VertexCount = 0;
        }

        public MyGraph()
            : base()
        {

        }

        public void AddEdge(PocVertex from, PocVertex to, int Length, int Tax)
        {
            string edgeString = string.Format("Длина пути: {0}\nПошлина: {1}", Length, Tax);
            PocEdge newEdge = new PocEdge(edgeString, from, to);
            this.AddEdge(newEdge);
            Lengths[from.ID, to.ID] = Length;
            Taxes[from.ID, to.ID] = Tax;

            edgeString = string.Format("Длина пути: {0}\nПошлина: {1}", Length, Tax);
            newEdge = new PocEdge(edgeString, to, from);
            this.AddEdge(newEdge);
            Lengths[to.ID, from.ID] = Length;
            Taxes[to.ID, from.ID] = Tax;
        }

        public void AddEdge(String from, String to, int Length, int Tax)
        {
            PocVertex From = GetByString(from), To = GetByString(to);
            if (From != null && To != null)
                this.AddEdge(From, To, Length, Tax);
        }

        public PocEdge GetEdge(PocVertex Start, PocVertex End)
        {
            foreach (PocEdge edge in this.Edges)
            {
                if (edge.Start == Start && edge.End == End)
                    return edge;
            }
            return null;
        }

        public PocVertex GetByString(String City)
        {
            foreach (PocVertex vertex in this.Vertices)
                if (vertex.City == City)
                    return vertex;
            return null;
        }

        public void AddVertex(PocVertex Vertex, bool tmp)
        {
            Vertex.ID = Count;
            this.AddVertex(Vertex);
        }

        public void SearchWay(PocGraphLayout layout, PocVertex StartVertex, PocVertex EndVertex)
        {
            if (StartVertex == null || EndVertex == null)
                return;

            // Алгоритм Дейкстра
            // ЗНАЧЕНИЕ МИНИМИЗАЦИИ = ДЛИНА + ПОШЛИНА
            
            // Здесь в итоге будут храниться длины минимальных значений до каждой вершины
            int[] Values = new int[this.Vertices.Count()];
            const int BigNum = 1000000;

            // Здесь храним все минимальные пути
            List<PocVertex>[] Paths = new List<PocVertex>[this.Vertices.Count()];

            PocVertex[] vertices = new PocVertex[this.Vertices.Count()];
            int i = 0;
            foreach (PocVertex vertex in this.Vertices)
            {
                vertices[i] = vertex;
                if (vertex != StartVertex)
                    Values[i] = BigNum;
                else
                    Values[i] = 0;
                i++;
            }

            HashSet<PocVertex> S = new HashSet<PocVertex>();

            bool Exists = true;

            // Сам алгоритм
            while (!S.SetEquals(this.Vertices) && Exists)
            {
                int MinValue = BigNum, MinIndex = -1;
                for (int j = 0; j < this.Vertices.Count(); ++j)
                {
                    if (Values[j] < MinValue && !S.Contains(vertices[j]))
                    {
                        MinIndex = j;
                        MinValue = Values[j];
                    }
                }
                S.Add(vertices[MinIndex]);

                for (int j = 0; j < this.Vertices.Count(); ++j)
                {
                    if (Lengths[MinIndex, j] != 0 && !S.Contains(vertices[j]))
                    {
                        if (Values[MinIndex] + Lengths[MinIndex, j] + Taxes[MinIndex, j] < Values[j])
                        {
                            Values[j] = Values[MinIndex] + Lengths[MinIndex, j] + Taxes[MinIndex, j];
                            
                            if (Paths[j] == null)
                                Paths[j] = new List<PocVertex>();

                            if (Paths[MinIndex] != null)
                            {
                                Paths[j].Clear();
                                for (int k = 0; k < Paths[MinIndex].Count; ++k)
                                {
                                    Paths[j].Add(Paths[MinIndex][k]);
                                }
                            }
                            Paths[j].Add(vertices[MinIndex]);
                        }
                    }
                }
                Exists = false;
                for (int j = 0; j < this.Vertices.Count(); ++j)
                {
                    if (Values[j] != BigNum && !S.Contains(vertices[j]))
                    {
                        Exists = true;
                        break;
                    }
                }
            }

            
            // Подсветка найденного пути
            int ResultIndex = -1;
            for (int j = 0; j < this.Vertices.Count(); ++j)
            {
                if (vertices[j] == EndVertex)
                {
                    ResultIndex = j;
                    break;
                }
            }

            Paths[ResultIndex].Add(EndVertex);
            for (int j = 0; j < Paths[ResultIndex].Count - 1; ++j)
            {
                layout.HighlightEdge(GetEdge(Paths[ResultIndex][j], Paths[ResultIndex][j + 1]), null);
                layout.HighlightEdge(GetEdge(Paths[ResultIndex][j + 1], Paths[ResultIndex][j]), null);
            }

        }


    }
}
