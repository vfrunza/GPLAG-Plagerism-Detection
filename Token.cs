using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace GPLAG_PD
{
    class Token
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
            Switch,
            BracketOpen,
            BracketClose
        }

        public int ID {  get; set; }
        public Type TokenType {  get; set; }
        public string Statment {  get; set; } 
        public List<string> Variables { get; set; } 


        public Token(int id, Type tokentype, string statment)
        {
            ID = id;
            TokenType = tokentype;
            Statment = statment;
            Variables = new List<string>();

            FindVariables();
        }

        private void FindVariables()
        {
            // remove touching () and ;
            string str = Statment.Replace(";", " ");
            str = str.Replace(",", " ");
            str = str.Replace("&", " ");
            str = str.Replace(")", " ");
            str = str.Replace("(", " ");

            // remove numbers
            string pattern = @" *\d+ *";
            str = Regex.Replace(str, pattern, " ");

            // remove text
            pattern = " ?\".*?\"";
            str = Regex.Replace(str, pattern, string.Empty);

            // remove increment
            pattern = @"\+{2}";
            str = Regex.Replace(str, pattern, string.Empty);
            pattern = @"\-{2}";
            str = Regex.Replace(str, pattern, string.Empty);

            //remove common callsites
            if (str.Contains("printf") || str.Contains("scanf"))
            {
                str = str.Replace("printf", " ");
                str = str.Replace("scanf", " ");
            }

            // save to list
            List<string> stm = str.Split(" ").ToList();
            Variables = stm.Except(Lexer.CAll).ToList();

            Variables.RemoveAll(x => x == " ");
            Variables.RemoveAll(x => x == "");

        }

        public override string ToString() {
            string str = String.Format("{0,-5} | {1,-12} | {2,-120} | {3,-30}", ID.ToString(), TokenType.ToString(), Statment.ToString(), string.Join(" ", Variables.ToArray()));
            return str;
        }
    }
}
