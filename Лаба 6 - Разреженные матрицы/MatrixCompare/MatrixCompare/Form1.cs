using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using PerfCounter;

namespace MatrixCompare
{
    public partial class Form1 : Form
    {
        Matrix matrix;
        SparseMatrix spMatrix;
        Double[] Vector;
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            InputDialog InputDlg = new InputDialog();
            InputDlg.Text = "Ввод разреженной матрицы";
            InputDlg.label1.Text = "Введите матрицу в поле ниже и нажмите кнопу 'Отправить'";
            InputDlg.ShowDialog();
            matrix = new Matrix(InputDlg.richTextBox1.Text);
            this.richTextBox2.Text += "\n\nСоздана разряженная матрица:\n" + matrix.ToString();
            spMatrix = new SparseMatrix(matrix);
            this.richTextBox2.Text += "\n\nРазреженное представление:\n" + spMatrix.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            InputDialog InputDlg = new InputDialog();
            InputDlg.Text = "Ввод вектора";
            InputDlg.label1.Text = "Введите вектор в поле ниже и нажмите кнопу 'Отправить'";
            InputDlg.ShowDialog();
            String[] StrVector = InputDlg.richTextBox1.Text.Split(' ', '\t');
            this.Vector = new Double[StrVector.Length];
            String vctr = "";
            for (int i = 0; i < StrVector.Length; ++i)
            {
                Double.TryParse(StrVector[i], out this.Vector[i]);
                vctr += Vector[i].ToString() + "\t";
            }
            this.richTextBox2.Text += "\n\nСоздан вектор:\n" + vctr;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.richTextBox2.Text += "\n\nВ результате умножения разреженной матрицы на вектор-столбец получен новый вектор-столбец:\n";
            this.richTextBox2.Text += "\nРазреженное представление:\n";
            this.richTextBox2.Text += spMatrix.MulToVector(Vector).ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            InputDialog InputDlg = new InputDialog();
            InputDlg.Text = "Ввод матрицы";
            InputDlg.label1.Text = "Введите матрицу в поле ниже и нажмите кнопу 'Отправить'";
            InputDlg.ShowDialog();
            matrix = new Matrix(InputDlg.richTextBox1.Text);
            this.richTextBox1.Text += "\n\nСоздана матрица:\n" + matrix.ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            InputDialog InputDlg = new InputDialog();
            InputDlg.Text = "Ввод вектора";
            InputDlg.label1.Text = "Введите вектор в поле ниже и нажмите кнопу 'Отправить'";
            InputDlg.ShowDialog();
            String[] StrVector = InputDlg.richTextBox1.Text.Split(' ', '\t');
            this.Vector = new Double[StrVector.Length];
            String vctr = "";
            for (int i = 0; i < StrVector.Length; ++i)
            {
                Double.TryParse(StrVector[i], out this.Vector[i]);
                vctr += Vector[i].ToString() + "\t";
            }
            this.richTextBox1.Text += "\n\nСоздан вектор:\n" + vctr;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.richTextBox1.Text += "\n\nВ результате умножения матрицы на вектор-столбец получен новый вектор-столбец:\n";
            this.richTextBox1.Text += matrix.MulToVector(Vector).ToString();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            const int RepeatsCount = 100;
            Counter timer = new Counter();
            int RowsNum = Convert.ToInt32(this.maskedTextBox3.Text);
            int ColsNum = Convert.ToInt32(this.maskedTextBox2.Text);
            Matrix TestMatrix = new Matrix(RowsNum, ColsNum);
            int Percentage = Convert.ToInt32(this.maskedTextBox1.Text);
            TestMatrix.GenerateRandom(Percentage);
            SparseMatrix TestSpMatrix = new SparseMatrix(TestMatrix);
            Random rand = new Random();
            Double[] TestVector = new Double[ColsNum];
            for (int i = 0; i < ColsNum; ++i)
                TestVector[i] = rand.Next();
            this.progressBar1.Value = 0;
            int Step = 5;
            int PercentPart = 2 * Step * RepeatsCount / 100;

            // Время для обычных матриц
            timer.Reset();
            timer.Start();
            for (int i = 0; i < RepeatsCount; ++i)
            {
                TestMatrix.MulToVector(TestVector);
                if (i % PercentPart == 0)
                    this.progressBar1.Value += Step;
            }
            timer.Stop();

            float Time1 = timer.TotalSeconds;
            this.richTextBox3.Text += "\nВремя умножения для обычных матриц (" + this.maskedTextBox1.Text +
                "% ненулевых элементов): " + Time1.ToString("F3") + ";\nПамять: " + TestMatrix.getSizeOfThis().ToString() +
                " байт на матрицу.";
          
            // Время для разреженных матриц
            timer.Reset();
            timer.Start();
            for (int i = 0; i < RepeatsCount; ++i)
            {
                TestSpMatrix.MulToVector(TestVector);
                if (i % PercentPart == 0)
                    this.progressBar1.Value += Step;
            }
            timer.Stop();
            float Time2 = timer.TotalSeconds;
            this.richTextBox3.Text += "\nВремя умножения для разреженных матриц (" + this.maskedTextBox1.Text +
                "% ненулевых элементов): " + Time2.ToString("F3") + ";\nПамять: " + TestSpMatrix.getSizeOfThis().ToString() +
                " байт на матрицу.";

            int PercentDelta = (int)(((Double) (Time1 / Time2) - 1) * 100);
            this.richTextBox3.Text += "\nУмножение обычных матриц медленнее на : " + PercentDelta.ToString() + "%";

            Double temp = (Double)TestMatrix.getSizeOfThis() / (Double)TestSpMatrix.getSizeOfThis();
            int MemoryPercent = (int)((temp - 1) * 100);
            this.richTextBox3.Text += "\nОбычная матрица занимает памяти больше на : " + MemoryPercent.ToString() + "%\n";

        }
    }
}