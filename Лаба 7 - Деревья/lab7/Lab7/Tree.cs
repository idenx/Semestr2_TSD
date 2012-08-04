using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Lab7
{
    class Node<T>
    {
        private Node<T> left, right;
        private Node<T> parent;
        private T key;

        public Node()
        {
            this.left = null;
            this.right = null;
            this.parent = null;
        }

        public Node(T key)
        {
            this.key = key;
            this.left = null;
            this.right = null;
            this.parent = null;
        }

        public Node<T> Left
        {
            get
            {
                return this.left;
            }
            set
            {
                this.left = value;
            }
        }

        public Node<T> Parent
        {
            get
            {
                return this.parent;
            }
            set
            {
                this.parent = value;
            }
        }

        public Node<T> Right
        {
            get
            {
                return this.right;
            }
            set
            {
                this.right = value;
            }
        }

        public T Key
        {
            get
            {
                return this.key;
            }

            set
            {
                this.key = value;
            }
        }

        public override String ToString()
        {
            return this.key.ToString();
        }
    }

    class BTree<T> where T : IComparable
    {
        protected Node<T> Root;

        public BTree()
        {
            Root = null;
        }

        public Node<T> Nodes
        {
            get
            {
                return Root;
            }
        }

        public void Insert(T key)
        {
            Node<T> toInsert = new Node<T>(key);
            if (Root == null)
            {
                Root = toInsert;
                return;
            }

            Node<T> temp = Root, parent = null;


            while (temp != null)
            {
                parent = temp;
                if (key.CompareTo(temp.Key) <= 0)
                {
                    temp = temp.Left;
                }
                else
                {
                    temp = temp.Right;
                }
            }
            toInsert.Parent = parent;

            if (key.CompareTo(parent.Key) <= 0)
            {
                parent.Left = toInsert;
            }
            else
            {
                parent.Right = toInsert;
            }
        }
    }

    class AdvancedBTree<T> : BTree<T> where T : IComparable
    {
        public AdvancedBTree() : base()
        {

        }

        public int Depth()
        {
            return CalcDepth(Root);
        }

        public int CountOfNodesOnLevel(int LevelNumber)
        {
            return CalcNodesCount(Root, 0, LevelNumber);
        }

        static private int CalcNodesCount(Node<T> Node, int CurDepth, int TargetDepth)
        {
            if (Node == null)
                return 0;

            if (CurDepth == TargetDepth)
                return 1;

            return CalcNodesCount(Node.Left, CurDepth + 1, TargetDepth) + 
                CalcNodesCount(Node.Right, CurDepth + 1, TargetDepth);
        }

        static private int CalcDepth(Node<T> Node)
        {
            if (Node == null)
                return 0;

            int LeftHeight = CalcDepth(Node.Left);
            int RightHeight = CalcDepth(Node.Right);

            if (LeftHeight > RightHeight)
                return LeftHeight + 1;
            else
                return RightHeight + 1;
        }

        static public bool isLeft(Node<T> Node)
        {
            if (Node.Parent == null)
                return false;
            return (Node.Parent.Left == Node);
        }

        static public bool isParent(Node<T> Node)
        {
            return (Node.Parent == null);
        }

        static public int NodeLevel(Node<T> Node)
        {
            int Level = 0;
            while (Node != null)
            {
                Node = Node.Parent;
                ++Level;
            }
            return Level - 1;
        }

        public void Remove(Node<T> Node)
        {
            Node<T> x, y;
            if (Node.Left == null || Node.Right == null)
                y = Node;
            else
                y = NextAfter(Node);

            if (y.Left != null)
                x = y.Left;
            else
                x = y.Right;

            if (x != null)
                x.Parent = y.Parent;

            if (y.Parent == null)
                this.Root = x;
            else
                if (isLeft(y))
                    y.Parent.Left = x;
                else
                    y.Parent.Right = x;
            if (y != Node)
                Node.Key = y.Key; 
        }

        public Node<T> Search(T Key)
        {
            return SearchHelper(this.Root, Key);
        }

        public List<T> GetSortedList()
        {
            List<T> list = new List<T>();
            SortHelper(ref list, Root);
            return list;
        }

        private void SortHelper(ref List<T> list, Node<T> StartNode)
        {
            if (StartNode != null)
            {
                SortHelper(ref list, StartNode.Left);
                list.Add(StartNode.Key);
                SortHelper(ref list, StartNode.Right);                
            }
        }

        public Node<T> SearchHelper(Node<T> StartNode, T Key)
        {
            if (StartNode == null || StartNode.Key.CompareTo(Key) == 0)
                return StartNode;
            if (Key.CompareTo(StartNode.Key) <= 0)
                return SearchHelper(StartNode.Left, Key);
            else
                return SearchHelper(StartNode.Right, Key);
        }

        public Node<T> Minimum(Node<T> Current)
        {
            while (Current.Left != null)
                Current = Current.Left;
            return Current;
        }

        public Node<T> NextAfter(Node<T> Current)
        {
            if (Current.Right != null)
                return Minimum(Current.Right);
            Node<T> temp = Current.Parent;

            while (temp != null && Current == temp.Right)
            {
                Current = temp;
                temp = temp.Parent;
            }
            return temp;
        }
    }
}