using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace GPLAG_PD
{
    class Lexer
    {
        public static List<string> CAll = new List<string>() { "double", "int", "float", "boolean", "char", "if", "else", "else if", "return", "while", "for", "++", "--", "=", "==", "+=", "-=", "*=", "/=", "%=>>=", "<<=", "&=", "^=", "|=", "!=", "+", "-", "*", "/", "%", "&&", "||", ">", "<", ">=", "<=", "{", "}", "(", ")" };

        private List<string> CTypes = new List<string>() { "double ", "int ", "float ", "boolean ", "char " };
        private List<string> CControls = new List<string>() { "if", "else", "else if", "return", "while", "for" };
        private List<string> CIncrements = new List<string>() { "++", "--" };
        private List<string> CAssignments = new List<string>() { "=", "+=", "-=", "*=", "/=", "%=>>=", "<<=", "&=", "^=", "|=" };
        private List<string> COperators = new List<string>() { "+", "-", "*", "/", "%", "&&", "||", ">", "<", ">=", "<=" };
        private List<string> CBrackets = new List<string>() { "{", "}", "(", ")"};

        private List<Token> Tokens = new List<Token>();
        private List<string> SourceCode = new List<string>();

        public Lexer(string filename)
        {
            PreProcessor pp = new PreProcessor(filename);
            SourceCode = pp.getSource();

            Tokenize();
            Print();
        }

        public void Print()
        {
            Tokens.ForEach(x => Console.WriteLine(x.ToString()));
        }

        private void Tokenize()
        {
            int tokenID = 1;
            foreach (string line in SourceCode)
            {
                if (line.Contains("main()"))
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.CallSite, line));
                }
                else if (line =="{")
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.BracketOpen, line));
                }
                else if ( line == "}")
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.BracketClose, line));
                }
                // check for declaration
                else if ( CTypes.Any(x => line.Contains(x)) )
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.Declaration, line));
                }
                // check for control
                else if (CControls.Any(x => line.Contains(x)))
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.Control, line));
                }
                // check for assignment
                else if (line.Contains("="))
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.Assignment, line));
                }
                // check for control

                // check for call-site

                // check for increment

                // check for return

                // check for expression
            }
        }
    }
}
