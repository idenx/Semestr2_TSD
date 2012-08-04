using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TSD_8
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

            public void Clear()
            {
                Root = null;
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
    }
