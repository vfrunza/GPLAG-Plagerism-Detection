using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using vflibcs;

namespace GPLAG_PD
{
    class Node: IComparable<Node>
    {
        public enum Type
        {
            CallSite,
            Control,
            Declaration,
            Assignment,
            Increment,
            Return,
            Expression,
            Jump,
            Label,
            Switch
        }

        public int ID;
        private string Statment;
        public Token tk;
        public Type NodeType { get;}
        public List<Node> Children;

        public Node(Token tk, Type tp)
        {
            ID = tk.ID;
            Statment = tk.Statment;
            this.tk = tk;
            NodeType = tp;
            Children = new List<Node>();
        }

        public int GetChildrenCount()
        {
            return Children.Count;
        }

        public void Add(Node nd)
        {
            Children.Add(nd);
        }

        public string ToStringChildren()
        {
            string children = "";

            foreach (Node nd in Children)
            {
                children += " | " + nd.ID + ", " + nd.NodeType.ToString() + ", " + nd.Statment;
            }

            return children;
        }

        public override string ToString()
        {
            string children = "NODE | ID: " + ID + ", Type: " + NodeType.ToString() + ", Statment: " + Statment;
            return children;
        }

        public List<string> Export()
        {
            List<string> children = new List<string>();
            
            string parent = ID.ToString() + "|" + NodeType.ToString() + "|" + Statment;
            foreach (Node nd in Children)
            {
                children.Add(parent + "," + nd.ID + "|" + nd.NodeType.ToString() + "|" + nd.Statment + ",1.0");
                //children.Add(parent + "," + nd.ID + ",1.0");

            }
            return children;
        }

        public int CompareTo(Node? other)
        {
            if (this.NodeType == other.NodeType)
                return 0;
            else
                return 1;
        }
    }
}
