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
        private List<string> RawStatments;
        private List<string> Statments;
        private List<Token> Tokens;
        private string Filename;

        private string DataLocation = @"C:/Users/Victo/Source/GPLAG-Plagerism-Detection/GPLAG-PD/GPLAG-PD/Data/src/";

        private List<string> CTypes = new List<string>() { "double ", "int ", "float ", "boolean ", "char " };
        private List<string> CControls = new List<string>() { "if", "else", "else if", "return", "while", "for" };
        private List<string> CIncrements = new List<string>() { "++", "--" };
        private List<string> CAssignments = new List<string>() { "=", "+=", "-=", "*=", "/=", "%=>>=", "<<=", "&=", "^=", "|=" };
        private List<string> COperators = new List<string>() { "+", "-", "*", "/", "%" };

        public Lexer(string filename)
        {
            this.Filename = filename;
            this.RawStatments = new List<string>();
            this.Tokens = new List<Token>();

            this.Open();
            this.Tokenize();
        }

        private void Open()
        {
            string line;
            try
            {
                StreamReader sr = new StreamReader(this.DataLocation + this.Filename);
                line = sr.ReadLine();
                while (line != null)
                {
                    if (this.ValidLines(line))
                        this.Clean(line);
                    line = sr.ReadLine();
                }
                sr.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
        }

        private bool ValidLines(string line)
        {
            if (line == "" || line == "\n" || line == "\t" || line.Contains("#include"))
            {
                return false;
            }
            return true;
        }

        private void Clean(string line)
        {
            // this method will attempt to clean the source code and remove everything not nessesary for tokenization
            // In general this will include:
            // 1. REMOVE main(), comments, and directives
            // 2. REMOVE whitespace
            // 3. REMOVE unesseary strings from functions like printf, scanf, etc.
            // 4. Breakup repeated declarations ex. double a,b,c,d,e

            // REMOVE main(), comments, and directives
            if (line.Contains("main()") || line.Contains("//") || line.Contains("#include"))
            {
                Console.WriteLine("Line ignored: " + line);
            }
            else
            {
                // REMOVE whitespace
                line = line.Trim();

                // REMOVE unesseary strings from functions like printf, scanf, etc.
                string pattern = " ?\".*?\"";
                line = Regex.Replace(line, pattern, string.Empty);

                // BREAKUP repeated declarations ex. double a,b,c,d,e
                if (CTypes.Any(x => line.Contains(x)))
                {
                    foreach (string type in CTypes)
                    {
                        Regex rx = new Regex(type + @"[\w,]+", RegexOptions.Compiled | RegexOptions.IgnoreCase);
                        MatchCollection matches = rx.Matches(line);
                        if (matches.Count > 0)
                        {
                            // remove type from line
                            line = line.Substring(type.Length);
                            // split on ','
                            List<string> declatrationArray = line.Split(",").ToList();

                            // if last character is not a ";" add it
                            for (int i = 0; i < declatrationArray.Count; i++)
                            {
                                if (!declatrationArray[i].EndsWith(";"))
                                {
                                    declatrationArray[i] = declatrationArray[i] + ";";
                                }
                            }

                            // add RawStatments with type prefix
                            declatrationArray.ForEach(declatration => this.RawStatments.Add(type + " " + declatration.Trim()));
                            break;
                        }
                        
                    }
                }
                else
                {
                    Regex rx = new Regex(@";", RegexOptions.Compiled | RegexOptions.IgnoreCase);
                    MatchCollection matches = rx.Matches(line);
                    if (matches.Count > 1)
                    {
                        List<string> compoundLine = line.Split(";").ToList<string>();
                        compoundLine.ForEach(l => this.RawStatments.Add(l + ";"));
                    }
                    else
                    {
                        this.RawStatments.Add(line);
                    }
                }

                // BREAKUP compound lines
                

            }
        }

        public void Print()
        {
            this.RawStatments.ForEach(x => Console.WriteLine(x));
            this.Tokens.ForEach(token => Console.WriteLine(token.ToString()));  
        }

        private void Tokenize()
        {
            int tokenID = 1;
            foreach (string line in this.RawStatments)
            {
                // check for declaration
                if ( CTypes.Any(x => line.Contains(x)) )
                {
                    string? type = CTypes.Find(x => line.Contains(x));
                    this.Tokens.Add(new Token(tokenID++, Token.Type.Declaration, line, type));
                }
                // check for control
                else if (CControls.Any(x => line.Contains(x)))
                {
                    this.Tokens.Add(new Token(tokenID++, Token.Type.Control, line));
                }
                // check for assignment
                else if (line.Contains("="))
                {
                    this.Tokens.Add(new Token(tokenID++, Token.Type.Assignment, line));
                }
                // check for control

                // check for call-site

                // check for increment

                // check for return

                // check for expression
            }
            this.Print();
        }
    }
}
