using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using PerfCounter;

namespace TSD_8
{
    public partial class Form1 : Form
    {
        private AdvancedBTree<int> BinaryTree;
        private AdvancedBTree<int> BalancedBinaryTree;
        private OAHashTable OATable;
        private CAHashTable CATable;
        const int RepeatsCount = 1000000;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.radioButton2.Checked = true;
            this.radioButton3.Checked = true;
            this.radioButton6.Checked = true;

            // Бинарные деревья
            BinaryTree = ReadBTreeFromFile();
            BalancedBinaryTree = ReadBTreeFromFile();
            BalancedBinaryTree.Balance();
            RefreshTree(BalancedBinaryTree);
            List<int> Values = BalancedBinaryTree.GetSortedList();
            HashSet<int> Set = new HashSet<int>(Values);
            this.textBox1.Text = Set.Count.ToString();

            // Хеш-таблицы
            FillOAHashTable(ref OATable);
            this.richTextBox1.Text = OATable.ToString();
        }

        private AdvancedBTree<int> ReadBTreeFromFile()
        {
            int[] Numbers = ReadNumbersFromFile();
            if (Numbers == null)
                return null;
            AdvancedBTree<int> BinaryTree = new AdvancedBTree<int>();
            for (int i = 0; i < Numbers.Length; ++i)
            {
                BinaryTree.Insert(Numbers[i]);
            }
            return BinaryTree;
        }

        private int[] ReadNumbersFromFile()
        {
            const String FileName = "Test.txt";
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


        private void RefreshTree(AdvancedBTree<int> Tree)
        {
            // Отображаем дерево
            if (Tree == null)
                return;
            treeView1.BeginUpdate();
            treeView1.Nodes.Clear();
            RefreshGUI(treeView1.Nodes, Tree.Nodes);
            treeView1.EndUpdate();
            this.treeView1.ExpandAll();
        }

        private void FillOAHashTable(ref OAHashTable HT)
        {
            if (BalancedBinaryTree == null)
                return;
            Info Key = new Info();
            List<int> Values = BalancedBinaryTree.GetSortedList();
            HashSet<int> Set = new HashSet<int>(Values);
            int Size = 0;
            try
            {
                Size = Convert.ToInt32(this.textBox1.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Число не введено!");
                return;
            }

            HT = new OAHashTable(Size);
            try
            {
                foreach (int value in Set)
                {
                    Key = new Info(value);
                    HT.Insert(Key);
                }
            }
            catch (Error err)
            {
                MessageBox.Show(err.error);
            }
        }

        private void FillCAHashTable(ref CAHashTable HT)
        {
            if (BalancedBinaryTree == null)
                return;
            List<int> Values = BalancedBinaryTree.GetSortedList();
            HashSet<int> Set = new HashSet<int>(Values);
            int Size = 0;
            try
            {
                Size = Convert.ToInt32(this.textBox1.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Число не введено!");
                return;
            }

            HT = new CAHashTable(Size);
            foreach (int value in Set)
                HT.Insert(value);
        }

        private void button1_Click(object sender, EventArgs e)
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

            if (this.radioButton5.Checked)
            {
                if (radioButton1.Checked)
                {
                    TreeSearch(BinaryTree, Number);
                    return;
                }
                if (radioButton2.Checked)
                {
                    TreeSearch(BalancedBinaryTree, Number);
                    return;
                }
            }
            if (this.radioButton6.Checked)
            {
                if (radioButton3.Checked)
                {
                    OAHashTableSearch(Number);
                }
                else
                {
                    CAHashTableSearch(Number);
                }
            }
        }

        private void TreeSearch(AdvancedBTree<int> Tree, int Key)
        {
            Counter counter = new Counter();
            counter.Start();
            Node<int> Node = null;
            for (int i = 0; i < RepeatsCount; ++i)
                Node = Tree.Search(Key);
            counter.Stop();
            String Result;
            if (Node == null)
                Result = "Ничего не найдено";
            else
                Result = "Введенное число найдено на " +
                    AdvancedBTree<int>.NodeLevel(Node).ToString() + " уровне.";

            MessageBox.Show(Result + "\nВремя поиска при " + RepeatsCount.ToString() +
                     " повторах = " + counter.TotalSeconds.ToString("F2"));
        }

        private void OAHashTableSearch(int Key)
        {
            Info InfoKey = new Info(Key);
            int Result = -1;
            Counter counter = new Counter();
            counter.Start();
            for (int i = 0; i < RepeatsCount; ++i)
                Result = OATable.Search(InfoKey);
            counter.Stop();

            String StrResult;

            if (Result == -1)
                StrResult = "Ничего не найдено!";
            else
                StrResult = "Индекс элемента в массива = " + Result.ToString();

            MessageBox.Show(StrResult + "\nВремя поиска при " + RepeatsCount.ToString() +
                     " повторах = " + counter.TotalSeconds.ToString("F2"));
        }

        private void CAHashTableSearch(int Key)
        {
            int Result = -1;
            Counter counter = new Counter();
            counter.Start();
            for (int i = 0; i < RepeatsCount; ++i)
                Result = CATable.Search(Key);
            counter.Stop();

            String StrResult;

            if (Result == -1)
                StrResult = "Ничего не найдено!";
            else
                StrResult = "Индекс элемента в массива = " + Result.ToString();

            MessageBox.Show(StrResult + "\nВремя поиска при " + RepeatsCount.ToString() +
                     " повторах = " + counter.TotalSeconds.ToString("F2"));
        }


        private void button2_Click(object sender, EventArgs e)
        {
            FillOAHashTable(ref OATable);
            this.richTextBox1.Text = OATable.ToString();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (this.radioButton2.Checked)
                RefreshTree(BalancedBinaryTree);
            else
                RefreshTree(BinaryTree);
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            if (this.radioButton3.Checked)
            {
                FillOAHashTable(ref OATable);
                if (OATable != null)
                    this.richTextBox1.Text = OATable.ToString();
            }
            else
            {
                FillCAHashTable(ref CATable);
                if (CATable != null)
                    this.richTextBox1.Text = CATable.ToString();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            StringBuilder Result = new StringBuilder();
            const int TestRepeatsCount = 1000000;
            Counter counter = new Counter();
            int Key = 3;
            this.progressBar1.Value = 0;

            counter.Start();
            for (int i = 0; i < TestRepeatsCount; ++i)
                BinaryTree.Search(Key);
            counter.Stop();
            this.progressBar1.Value += 25;
            Double BTreeTime = counter.TotalSeconds;

            counter.Reset();
            counter.Start();
            for (int i = 0; i < TestRepeatsCount; ++i)
                BalancedBinaryTree.Search(Key);
            counter.Stop();
            this.progressBar1.Value += 25;
            Double BalancedBTreeTime = counter.TotalSeconds;

            Info InfoKey = new Info(Key);
            counter.Reset();
            FillOAHashTable(ref OATable);
            counter.Start();
            for (int i = 0; i < TestRepeatsCount; ++i)
                OATable.Search(InfoKey);
            counter.Stop();
            this.progressBar1.Value += 25;
            Double OATableTime = counter.TotalSeconds;


            counter.Reset();
            FillCAHashTable(ref CATable);
            counter.Start();
            for (int i = 0; i < TestRepeatsCount; ++i)
                CATable.Search(Key);
            counter.Stop();
            this.progressBar1.Value += 25;
            Double CATableTime = counter.TotalSeconds;

            Result.Append("Количество повторений = " + TestRepeatsCount.ToString() +
                ".\nБинарное дерево\n\t-Время поиска = " + BTreeTime.ToString("F2") +
                "\n\t-Занимаемая память = " + BinaryTree.getMemory() +
                " байт\nСбалансированное бинарное дерево\n\t-Время поиска = " + BalancedBTreeTime.ToString("F2") +
                "\n\t-Занимаемая память = " + BalancedBinaryTree.getMemory() +
                " байт\nХеш-таблица с открытой адресацией\n\t-Время поиска = " + OATableTime.ToString("F2") +
                "\n\t-Занимаемая память = " + OATable.getMemory() +
                " байт\nХеш-таблица с закрытой адресацией\n\t-Время поиска = " + CATableTime.ToString("F2") +
                "\n\t-Занимаемая память = " + CATable.getMemory() + " байт.");
            MessageBox.Show(Result.ToString());
            this.progressBar1.Value = 0;
        }

        private void GenerateCompareFile()
        {
            Random rnd = new Random();
            StringBuilder Result = new StringBuilder();
            int TestFileSize = 121;
            for (int i = 0; i < TestFileSize; ++i)
                Result.Append(rnd.Next(197).ToString() + " ");
            Result.Append(rnd.Next(197));

            System.IO.File.WriteAllText("CompareFile.txt", Result.ToString());
        }
    }
}
