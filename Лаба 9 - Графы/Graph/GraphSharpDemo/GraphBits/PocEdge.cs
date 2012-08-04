using QuickGraph;
using System.Diagnostics;
using System.ComponentModel;
using System;

namespace GraphSharpDemo
{
    /// <summary>
    /// A simple identifiable edge.
    /// </summary>
    [DebuggerDisplay("{Source.Tag} -> {Target.Tag}")]
    public class PocEdge : Edge<PocVertex>, INotifyPropertyChanged
    {
        private string tag;

        public PocVertex Start
        {
            get
            {
                return this.Source;
            }
        }

        public PocVertex End
        {
            get
            {
                return this.Target;
            }
        }

        public string Tag
        {
            get { return tag; }
            set
            {
                tag = value;
                NotifyPropertyChanged("Tag");
            }
        }

        public PocEdge(string Tag, PocVertex source, PocVertex target)
            : base(source, target)
        {
            tag = Tag;
        }


        #region INotifyPropertyChanged Implementation

        public event PropertyChangedEventHandler PropertyChanged;

        private void NotifyPropertyChanged(string info)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(info));
            }
        }

        #endregion
    }
}