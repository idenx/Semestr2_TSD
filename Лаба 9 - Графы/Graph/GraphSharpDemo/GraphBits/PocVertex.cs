using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace GraphSharpDemo
{
    /// <summary>
    /// A simple identifiable vertex.
    /// </summary>
    [DebuggerDisplay("{City}-{IsMale}")]
    public class PocVertex
    {
        public string City { get; private set; }
        public bool IsMale { get; private set; }
        public int ID { get; set; }

        public PocVertex(string City)
        {
            this.City = City;
            IsMale = false;
        }

        public override string ToString()
        {
            return string.Format("{0}-{1}", City, IsMale);
        }
    }
}
