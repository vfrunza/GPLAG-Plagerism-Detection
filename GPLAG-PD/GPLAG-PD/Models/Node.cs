using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GPLAG_PD.Models
{
    class Node
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
            SwitchCase
        }

        private Type StatmentType;
        private string Statment;
        private string Key;
        private List<Node> Dependencies;

        public Node(Type statmentType, String statment)
        {
            this.StatmentType = statmentType;
            this.Statment = statment;

            Dependencies = new List<Node>();
        }
    }
}
