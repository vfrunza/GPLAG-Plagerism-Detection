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
        private List<string> Statments;
        private List<Token> Tokens;
        private string Filename;

        private string DataLocation = @"C:/Users/Victo/Source/GPLAG-Plagerism-Detection/GPLAG-PD/GPLAG-PD/Data/src/";

        private List<string> CTypes = new List<string>() { "double", "int", "float", "boolean", "char" };
        private List<string> CControls = new List<string>() { "if", "else", "else if", "return", "while", "for" };
        private List<string> CIncrements = new List<string>() { "++", "--" };
        private List<string> CAssignments = new List<string>() { "=", "+=", "-=", "*=", "/=", "%=>>=", "<<=", "&=", "^=", "|=" };
        private List<string> COperators = new List<string>() { "+", "-", "*", "/", "%" };

        public Lexer(string filename)
        {
            this.Filename = filename;
            this.Statments = new List<string>();
            this.Tokens = new List<Token>();

            this.Open();
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
            if (line.Contains("main()") || line.Contains("//") || line.Contains("#include"))
            {
                Console.WriteLine("Line ignored: " + line);
            }
            else
            {
                line = line.Trim(); //trim whitespace

                string pattern = " ?\".*?\"";
                line = Regex.Replace(line, pattern, string.Empty);



                // Breakup repeated declarations ex. double a,b,c,d,e
                if (CTypes.Any(x => line.Contains(x + " ")))
                {
                    foreach (string type in CTypes)
                    {
                        Regex rx = new Regex(type + @" [\w,]+", RegexOptions.Compiled | RegexOptions.IgnoreCase);
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

                            // add statments with type prefix
                            declatrationArray.ForEach(declatration => this.Statments.Add(type + " " + declatration.Trim()));
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
                        compoundLine.ForEach(l => this.Statments.Add(l + ";"));
                    }
                    else
                    {
                        this.Statments.Add(line);
                    }
                }

            }
        }

        public void Print()
        {
            this.Statments.ForEach(x => Console.WriteLine(x));
        }

        private void Tokenize()
        {
            foreach (string line in this.Statments)
            {
                if ( line.Contains("main()") || line.Contains("//") || line.Contains("#include") ){
                    Console.WriteLine("Line ignored: " + line);
                }
                // check for declaration
                else if ( CTypes.Any(x => line.Contains(x)) )
                {

                }
                // check for assignment

                // check for control

                // check for call-site

                // check for increment

                // check for return

                // check for expression
            }
        }
    }
}
