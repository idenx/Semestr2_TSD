using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace MatrixCompare
{
    public partial class InputDialog : Form
    {
        public bool ButtonSendPressed;

        public InputDialog()
        {
            InitializeComponent();
            ButtonSendPressed = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ButtonSendPressed = true;
            this.Close();
        }

        private bool CheckInput(String text, int RowsNum, int ColsNum)
        {

            return true;
        }
    }
}
