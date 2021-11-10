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

        public Token(int id, Type tokentype, string symbol)
        {
            ID = id;
            TokenType = tokentype;
            Symbol = symbol;
        }

        public string Print()
        {
            return this.ID.ToString() + " | " + this.TokenType.ToString() + " | " + this.Symbol.ToString();
        }
    }
}
