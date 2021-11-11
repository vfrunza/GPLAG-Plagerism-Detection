using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GPLAG_PD
{
    class Token
    {
        public enum Type
        {
            Control,
            Declaration,
            Assignment,
            Increment,
            Expression,
            Seperator
        }

        public int ID {  get; set; }
        public Type TokenType {  get; set; }
        public string Symbol {  get; set; } 
        public string VarType { get; set; }
        public string VarName { get; set; }

        public List<string> AssociatedVariables = new List<string>();

        public Token(int id, Type tokentype, string symbol)
        {
            ID = id;
            TokenType = tokentype;
            Symbol = symbol;
            VarType = "NULL";
            VarName = "";

            this.ExtractVarName();
        }

        public Token(int id, Type tokentype, string symbol, string vartype)
        {
            ID = id;
            TokenType = tokentype;
            Symbol = symbol;
            VarType = vartype;
            VarName = "";

            this.ExtractVarName();
        }

        private void ExtractVarName()
        {
            if (this.TokenType == Type.Declaration)
            {
                this.VarName = Symbol.Remove(0, VarType.Length).Trim();
            }
            else if (this.TokenType == Type.Assignment)
            {
                int eqLength = Symbol.IndexOf('=');
                this.VarName = Symbol.Remove(eqLength).Trim();
                this.ExtractAssociatedVar();
            }
            
            if (this.VarName.Contains(";")){
                this.VarName = this.VarName.Remove(this.VarName.Length - 1);
            }
        }

        private void ExtractAssociatedVar()
        {
            if (this.TokenType == Type.Assignment)
            {
                if (this.Symbol.Contains('+'))
                {
                    int eqLength = Symbol.IndexOf('=');
                    string statment = Symbol.Remove(0, eqLength + 1).Trim();
                    statment = statment.Substring(0, statment.Length - 1);

                    this.AssociatedVariables = statment.Split(new Char[] { '=', '+', '*', '/', '-' }).ToList();
                }
            }
        }

        public void addAssociatedVar(string a)
        {
            this.AssociatedVariables.Add(a);
        }

        public override string ToString() {
            return this.ID.ToString() + " | " + this.TokenType.ToString() + " | " + this.Symbol.ToString() + " | " + this.VarName.ToString() + " | " + String.Join(", ", this.AssociatedVariables);
        }
    }
}
