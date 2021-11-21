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
        private List<string> CControls = new List<string>() { "if", "else", "else if", "while", "for" };
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

        public List<Token> ExportTokens()
        {
            return Tokens;
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

                // check for control
                else if (CControls.Any(x => line.Contains(x)))
                {
                    if (line.Contains("for"))
                    {
                        string st = line;
                        st = st.Replace("for", " ");
                        st = st.Replace(")", " ");
                        st = st.Replace("(", " ");
                        st.Trim();

                        List<string> for_control = st.Split(";").ToList();

                        // if a iteration var is declared
                        if (CTypes.Any(x => for_control[0].Contains(x))){
                            for_control[0] = for_control[0].Trim();
                            Tokens.Add(new Token(tokenID++, Token.Type.Declaration, for_control[0].Substring(0, for_control[0].IndexOf("=")).Trim()));
                            Tokens.Add(new Token(tokenID++, Token.Type.Assignment, for_control[0].Substring(for_control[0].IndexOf(" ")).Trim()));
                            Tokens.Add(new Token(tokenID++, Token.Type.Control, for_control[1].Trim()));
                            Tokens.Add(new Token(tokenID++, Token.Type.Increment, for_control[2].Trim()));
                        }
                    }
                    else if (line.Contains("while"))
                    {
                        string st = line;
                        st = st.Replace("while", " ");
                        st = st.Replace(")", " ");
                        st = st.Replace("(", " ");
                        st.Trim();

                        Tokens.Add(new Token(tokenID++, Token.Type.Control, st));
                    }
                    else
                    {
                        Tokens.Add(new Token(tokenID++, Token.Type.Control, line));
                    }
                }

                // check for declaration
                else if (CTypes.Any(x => line.Contains(x)))
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.Declaration, line));
                }

                // check for assignment
                else if (line.Contains("="))
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.Assignment, line));
                }
                // check for call-site
                else if (line.Contains("scanf"))
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.CallSite, line));
                }

                // check for return
                else if (line.Contains("return"))
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.Return, line));
                }

                // check for expression
                else
                {
                    Tokens.Add(new Token(tokenID++, Token.Type.Expression, line));
                }
            }
        }
    }
}
