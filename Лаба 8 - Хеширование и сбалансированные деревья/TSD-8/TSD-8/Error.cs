using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSD_8
{
    class Error : Exception
    {
        public String error;

        public Error(String Error)
        {
            this.error = Error;
        }
    }
}
