using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using GraphSharp.Controls;
using GraphSharpDemo.AddDialogs;
using GraphSharpDemo.SearchDialog;

namespace GraphSharpDemo
{

    

    public partial class MainWindow : Window
    {
        private MainWindowViewModel vm;
        public MainWindow()
        {
            vm = new MainWindowViewModel();
            this.DataContext = vm;
            InitializeComponent();
        }

       

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            vm.ReLayoutGraph();
        }

        private void buttonAddCity_Click(object sender, RoutedEventArgs e)
        {
            AddCity AddCityDlg = new AddCity();
            AddCityDlg.ShowDialog();
            vm.Graph.AddVertex(new PocVertex(AddCityDlg.textBox1.Text), true);
        }

        private void buttonAddPathClick(object sender, RoutedEventArgs e)
        {
            AddPath AddPathDlg = new AddPath();
            AddPathDlg.ShowDialog();
            vm.Graph.AddEdge(AddPathDlg.textBoxFrom.Text, AddPathDlg.textBoxTo.Text,
                Convert.ToInt32(AddPathDlg.textBoxLength.Text), Convert.ToInt32(AddPathDlg.textBoxTax.Text));
        }

        private void button3_Click(object sender, RoutedEventArgs e)
        {
            SearchWay SearchWayDlg = new SearchWay();
            SearchWayDlg.ShowDialog();
            vm.Graph.SearchWay(graphLayout, vm.Graph.GetByString(SearchWayDlg.textBoxFrom.Text),
                vm.Graph.GetByString(SearchWayDlg.textBoxTo.Text));
        }
    }
}
