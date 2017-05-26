using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace practicMP7Single
{
    public partial class FormDepended : Form
    {
        private FormDepended()
        {
            InitializeComponent();
        }

        private static FormDepended f;

        public static FormDepended getf()
        {
           if (f == null || f.IsDisposed) f = new FormDepended();
           return f;
        }
        public static FormDepended fw = getf();

        public void ShowForm()
        {
            Show();
            Activate();
        }
    }
}
