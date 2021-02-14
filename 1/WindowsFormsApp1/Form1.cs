using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            using (var sr = new StreamReader(@"C:\Users\T520\Desktop\TestRepos\TestRepos\WindowsFormsApp1\file.txt"))
            {
                var str = sr.ReadToEnd();
                textBox1.Text = str.ToString();
            }
        }
    }
}
