using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GPLAG_PD.Models
{
    class Edge
    {
        public enum Type
        {
            Control,
            Data
        }

        private Type DependencyType;
        private Node Next;

        public Edge(Type dependencyType, Node next)
        {
            this.DependencyType = dependencyType;
            this.Next = next;
        }
    }
}
