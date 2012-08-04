using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ComponentModel;
using GraphSharp.Controls;



namespace GraphSharpDemo
{
    public class PocGraphLayout : GraphLayout<PocVertex, PocEdge, MyGraph> { }


    public class MainWindowViewModel : INotifyPropertyChanged
    {
        #region Data

        private string layoutAlgorithmType;
        private MyGraph graph;
        private List<String> layoutAlgorithmTypes = new List<string>();

        #endregion
        
        #region Ctor
        public MainWindowViewModel()
        {
            Graph = new MyGraph(true);

            List<PocVertex> existingVertices = new List<PocVertex>();
            existingVertices.Add(new PocVertex("Москва")); //0
            existingVertices.Add(new PocVertex("Казань")); //1
            existingVertices.Add(new PocVertex("Лондон")); //2
            existingVertices.Add(new PocVertex("Нью-Йорк")); //3
            existingVertices.Add(new PocVertex("Санкт-Петербург")); //4
            existingVertices.Add(new PocVertex("Киев")); //5
            existingVertices.Add(new PocVertex("Париж")); //6

            foreach (PocVertex vertex in existingVertices)
                Graph.AddVertex(vertex, true);


            //add some edges to the graph
            Graph.AddEdge(existingVertices[0], existingVertices[1], 100, 2000);
            Graph.AddEdge(existingVertices[0], existingVertices[2], 200, 5000);
            Graph.AddEdge(existingVertices[0], existingVertices[3], 400, 1500);
            Graph.AddEdge(existingVertices[0], existingVertices[5], 1000, 400);

            Graph.AddEdge(existingVertices[1], existingVertices[4], 800, 10000);

            Graph.AddEdge(existingVertices[4], existingVertices[5], 700, 500);

            Graph.AddEdge(existingVertices[3], existingVertices[2], 1000, 8000);
            Graph.AddEdge(existingVertices[3], existingVertices[5], 1800, 12000);

            Graph.AddEdge(existingVertices[3], existingVertices[6], 100, 200);

            Graph.AddEdge(existingVertices[6], existingVertices[4], 150, 200);


            //Add Layout Algorithm Types
            layoutAlgorithmTypes.Add("BoundedFR");
            layoutAlgorithmTypes.Add("Circular");
            layoutAlgorithmTypes.Add("CompoundFDP");
            layoutAlgorithmTypes.Add("EfficientSugiyama");
            layoutAlgorithmTypes.Add("FR");
            layoutAlgorithmTypes.Add("ISOM");
            layoutAlgorithmTypes.Add("KK");
            layoutAlgorithmTypes.Add("LinLog");
            layoutAlgorithmTypes.Add("Tree");

            //Pick a default Layout Algorithm Type
            LayoutAlgorithmType = "FR";
        }
        #endregion


        public void ReLayoutGraph()
        {
            graph = new MyGraph(true);

            List<PocVertex> existingVertices = new List<PocVertex>();
            existingVertices.Add(new PocVertex("Нью-Йорк"));
            existingVertices.Add(new PocVertex("Москва"));

            foreach (PocVertex vertex in existingVertices)
                Graph.AddVertex(vertex, true);

            NotifyPropertyChanged("Graph");
        }

        #region Public Properties

        public List<String> LayoutAlgorithmTypes
        {
            get { return layoutAlgorithmTypes; }
        }


        public string LayoutAlgorithmType
        {
            get { return layoutAlgorithmType; }
            set
            {
                layoutAlgorithmType = value;
                NotifyPropertyChanged("LayoutAlgorithmType");
            }
        }



        public MyGraph Graph
        {
            get { return graph; }
            set
            {
                graph = value;
                NotifyPropertyChanged("Graph");
            }
        }
        #endregion

        #region INotifyPropertyChanged Implementation

        public event PropertyChangedEventHandler PropertyChanged;

        private void NotifyPropertyChanged(String info)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(info));
            }
        }

        #endregion
    }
}
