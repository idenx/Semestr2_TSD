using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PerfCounter
{

    public class Counter
    {

        [System.Runtime.InteropServices.DllImport("KERNEL32")]
        private static extern bool QueryPerformanceCounter(ref
			long lpPerformanceCount);

        [System.Runtime.InteropServices.DllImport("KERNEL32")]
        private static extern bool
            QueryPerformanceFrequency(ref long lpFrequency);

        long totalCount = 0;
        long startCount = 0;
        long stopCount = 0;
        long freq = 0;

        public void Start()
        {
            startCount = 0;
            QueryPerformanceCounter(ref startCount);
        }

        public void Stop()
        {
            stopCount = 0;
            QueryPerformanceCounter(ref stopCount);
            totalCount += stopCount - startCount;
        }

        public void Reset()
        {
            totalCount = 0;
        }

        public float TotalSeconds
        {
            get
            {
                freq = 0;
                QueryPerformanceFrequency(ref freq);
                return ((float)totalCount / (float)freq);
            }
        }

        public double MFlops(double total_flops)
        {
            return (total_flops / (1e6 * TotalSeconds));
        }

        public override string ToString()
        {
            return String.Format("{0:F3} seconds", TotalSeconds);
        }
    }
}
