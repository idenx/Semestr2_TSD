using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using PerfCounter;

namespace Lab7
{
    public partial class Form1 : Form
    {

        private String FileName;
        private AdvancedBTree<int> BinaryTree;

        public Form1()
        {
            InitializeComponent();
            this.radioButton1.Checked = true;
        }

        private void RefreshTree()
        {
            this.textBox1.Clear();

            // Отображаем дерево
            if (BinaryTree == null)
                return;
            treeView1.BeginUpdate();
            treeView1.Nodes.Clear();
            RefreshGUI(treeView1.Nodes, BinaryTree.Nodes);
            treeView1.EndUpdate();
            this.treeView1.ExpandAll();

            // Вычисляем и выводим кол-во уровней
            int Depth = BinaryTree.Depth();
            this.textBox1.Text = "Глубина дерева: " + Depth.ToString() + "\r\n\r\n";

            // Вычисляем кол-во узлов на каждом уровне
            this.textBox1.Text += "Количество узлов на каждом уровне:\r\n";
            for (int i = 0; i < Depth; ++i)
            {
                this.textBox1.Text += "уровень №" + i.ToString() + " -> " +
                    BinaryTree.CountOfNodesOnLevel(i).ToString() + "\r\n";
            }
        }

        private int[] ReadNumbersFromFile()
        {
            string text = "";
            try
            {
                text = System.IO.File.ReadAllText(FileName);
            }
            catch (Exception)
            {
                MessageBox.Show("Файл не найден!");
                return null;
            }

            String[] StrNumbers = text.Split(' ');
            int[] Numbers = new int[StrNumbers.Length];
            try
            {
                for (int i = 0; i < Numbers.Length; ++i)
                    Numbers[i] = Convert.ToInt32(StrNumbers[i]);
            }
            catch (FormatException)
            {
                MessageBox.Show("В файле должны быть числа через пробел!");
                return null;
            }
            return Numbers;
        }

        private void ReadBTreeFromFile()
        {
            int[] Numbers = ReadNumbersFromFile();
            if (Numbers == null)
                return;
            BinaryTree = new AdvancedBTree<int>();
            for (int i = 0; i < Numbers.Length; ++i)
            {
                BinaryTree.Insert(Numbers[i]);
            }
        }

        private void RefreshGUI(TreeNodeCollection Tree, Node<int> Node)
        {
            if (Node != null)
            {
                String text = Node.ToString();
                if (AdvancedBTree<int>.isLeft(Node))
                    text += " (Левый)";
                else
                    if (AdvancedBTree<int>.isParent(Node))
                        text += " (Корень)";
                    else
                        text += " (Правый)";
                Tree.Add(text);
                RefreshGUI(Tree[Tree.Count - 1].Nodes, Node.Left);
                RefreshGUI(Tree[Tree.Count - 1].Nodes, Node.Right);
            }
        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.openFileDialog1.Filter = "Текстовые файлы (*.txt)|*.txt";
            this.openFileDialog1.FileName = "";
            if (this.openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                this.FileName = this.openFileDialog1.FileName;
                ReadBTreeFromFile();
                RefreshTree();
            }
        }

        private void InsertNumberToFile(int Number, String FileName)
        {
            String text = System.IO.File.ReadAllText(FileName);
            text += " " + Number.ToString();
            System.IO.File.WriteAllText(FileName, text);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int Number = 0;
            try
            {
                Number = Convert.ToInt32(this.maskedTextBox1.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Число не введено!");
                return;
            }

            if (this.radioButton1.Checked)
            {
                try
                {
                    InsertNumberToFile(Number, FileName);
                    ReadBTreeFromFile();
                    RefreshTree();
                }
                catch (Exception)
                {
                    MessageBox.Show("Файл не найден!");
                    return;
                }
            }
            else
            {
                maskedTextBox1.Clear();
                if (BinaryTree == null)
                {
                    MessageBox.Show("Бинарное дерево еще не создано! Откройте файл для его создания");
                    return;
                }
                BinaryTree.Insert(Number);
                RefreshTree();
            }

        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.textBox1.Clear();
            this.treeView1.Nodes.Clear();
            this.maskedTextBox1.Clear();
        }

        // Сравнение времени добавления
        private void button4_Click(object sender, EventArgs e)
        {
            const int RepeatLimit = 1000;
            const int Limit2 = 10;
            const String TestFileName = "Comparing.txt";
            String Test = "";
            System.IO.StreamWriter file = new System.IO.StreamWriter(TestFileName);
            const int Number = 4;
            BTree<int> Tree = new BTree<int>();

            Counter counter = new Counter();

            // Настройки для ПрогрессБара
            const int PercentStep = 5;
            const int OnePart = RepeatLimit / (2 * PercentStep);

            // Время добавления в файл
            counter.Start();
            for (int i = 0; i < RepeatLimit; ++i)
            {
                for (int j = 0; j < Limit2; ++j)
                {
                    Test += " " + Number.ToString();
                    file.Write(Test);
                }

                if (i % OnePart == 0)
                    progressBar1.Value += PercentStep;
            }
            counter.Stop();
            double FileAddTime = counter.TotalSeconds;

            // Время добавления в бинарное дерево
            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatLimit; ++i)
            {
                for (int j = 0; j < Limit2; ++j)
                    Tree.Insert(Number);
                if (i % OnePart == 0)
                    progressBar1.Value += PercentStep;
            }
            counter.Stop();
            double TreeAddTime = counter.TotalSeconds;

            // Выод времени
            String Result = "Время добавления числа при " + RepeatLimit.ToString() + " повторах:\r\n  В файл -> " +
                FileAddTime.ToString("F2") + " секунд\r\n  В бинарное дерево -> " + TreeAddTime.ToString("F2") + " секунд";
            MessageBox.Show(Result);
            this.progressBar1.Value = 0;
            file.Close();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (BinaryTree == null)
            {
                MessageBox.Show("Дерево еще не создано");
                return;
            }
            int Number = 0;
            try
            {
                Number = Convert.ToInt32(this.maskedTextBox2.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Число не введено!");
                return;
            }
            Node<int> Node = BinaryTree.Search(Number);
            if (Node == null)
                MessageBox.Show("Ничего не найдено");
            else
                MessageBox.Show("Введенное число найдено на " + 
                    AdvancedBTree<int>.NodeLevel(Node).ToString() + " уровне");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (BinaryTree == null)
            {
                MessageBox.Show("Дерево еще не создано");
                return;
            }
            int Number = 0;
            try
            {
                Number = Convert.ToInt32(this.maskedTextBox2.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Число не введено!");
                return;
            }
            Node<int> Node = BinaryTree.Search(Number);
            if (Node == null)
                MessageBox.Show("Ничего не найдено");
            else
            {
                BinaryTree.Remove(Node);
                RefreshTree();
                MessageBox.Show("Введенное число найдено на " +
                    AdvancedBTree<int>.NodeLevel(Node).ToString() + " уровне и удалено");
            }
        }

        // Сравнение сортировок и поиска
        private void button1_Click(object sender, EventArgs e)
        {
            AdvancedBTree<int> TestTree = new AdvancedBTree<int>();
            Random rand = new Random();
            Counter counter = new Counter();
            const int MaxNum = 100;
            const int RepeatsLimit = 10000;

            // Для дерева высотой 10
            while (TestTree.Depth() != 10)
                TestTree.Insert(rand.Next(MaxNum));

            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.Search(rand.Next(MaxNum));
            counter.Stop();
            double Search10Time = counter.TotalSeconds;

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.GetSortedList();
            counter.Stop();
            double Sort10Time = counter.TotalSeconds;
            this.progressBar1.Value += 20;

            // Для дерева высотой 20
            TestTree = new AdvancedBTree<int>();
            while (TestTree.Depth() != 20)
                TestTree.Insert(rand.Next(MaxNum));
            
            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.Search(rand.Next(MaxNum));
            counter.Stop();
            double Search20Time = counter.TotalSeconds;

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.GetSortedList();
            counter.Stop();
            double Sort20Time = counter.TotalSeconds;
            this.progressBar1.Value += 20;

            // Для дерева высотой 50
            TestTree = new AdvancedBTree<int>();
            while (TestTree.Depth() != 50)
                TestTree.Insert(rand.Next(MaxNum));

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.Search(rand.Next(MaxNum));
            counter.Stop();
            double Search50Time = counter.TotalSeconds;

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.GetSortedList();
            counter.Stop();
            double Sort50Time = counter.TotalSeconds;
            this.progressBar1.Value += 20;

            // Сравнение сортировки и добавления при разных степенях ветвления
            const int TestDepth = 100;

            // Для сильного ветвления
            TestTree = new AdvancedBTree<int>();
            while (TestTree.Depth() != TestDepth)
                TestTree.Insert(rand.Next(MaxNum));

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.Search(rand.Next(MaxNum));
            counter.Stop();
            double SearchGoodTime = counter.TotalSeconds;

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.GetSortedList();
            counter.Stop();
            double SortGoodTime = counter.TotalSeconds;
            this.progressBar1.Value += 20;

            // Для слабого ветвления
            TestTree = new AdvancedBTree<int>();
            int j = 0;
            while (TestTree.Depth() != TestDepth)
                TestTree.Insert(j++);

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.Search(rand.Next(MaxNum));
            counter.Stop();
            double SearchBadTime = counter.TotalSeconds;

            counter.Reset();
            counter.Start();
            for (int i = 0; i < RepeatsLimit; ++i)
                TestTree.GetSortedList();
            counter.Stop();
            double SortBadTime = counter.TotalSeconds;
            this.progressBar1.Value += 20;

            // Вывод результата
            String Result = "Сравнение в зависимости от глубины дерева:\r\n" +
                "  Глубина 10:\r\n" +
                "    Время поиска = " + Search10Time.ToString("F2") + "\r\n" +
                "    Время сортировки = " + Sort10Time.ToString("F2") + "\r\n" +
                "  Глубина 20:\r\n" +
                "    Время поиска = " + Search20Time.ToString("F2") + "\r\n" +
                "    Время сортировки = " + Sort20Time.ToString("F2") + "\r\n" +
                "  Глубина 50:\r\n" +
                "    Время поиска = " + Search50Time.ToString("F2") + "\r\n" +
                "    Время сортировки = " + Sort50Time.ToString("F2") + ".\r\n" +
                "Сравнение в зависимости от степени ветвления дерева:\r\n" +
                "  Плохая степень ветвления:\r\n" +
                "    Время поиска = " + SearchBadTime.ToString("F2") + "\r\n" +
                "    Время сортировки = " + SortBadTime.ToString("F2") + "\r\n" +
                "  Отличная степень ветвления:\r\n" +
                "    Время поиска = " + SearchGoodTime.ToString("F2") + "\r\n" +
                "    Время сортировки = " + SortGoodTime.ToString("F2") + "\r\n";
            MessageBox.Show(Result);
            this.progressBar1.Value = 0;
        }
    }
}