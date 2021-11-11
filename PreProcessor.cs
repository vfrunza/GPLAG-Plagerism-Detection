using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace GPLAG_PD
{
    class PreProcessor
    {
        private string DataLocation = @"C:/Users/Victo/Source/GPLAG-Plagerism-Detection/Data/src/";
        private List<string> RawStatments;
        private List<string> L1Statments;
        private List<string> L2Statments;

        private string Filename;

        private List<string> CTypes = new List<string>() { "double ", "int ", "float ", "boolean ", "char " };

        public PreProcessor(string filename)
        {
            Filename = filename;
            RawStatments = new List<string>();
            L1Statments = new List<string>();
            L2Statments = new List<string>();

            Open();
            BreakupBySemiColon();
            BreakupByCompoundDeclaration();
            //Print();
        }

        private void Open()
        {
            string line;
            try
            {
                StreamReader sr = new StreamReader(DataLocation + Filename);
                line = sr.ReadLine();
                while (line != null)
                {
                    if (ValidLines(line))
                        Clean(line);
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
            // 4. Breakup repeated declarations ex. double a,b,c,d,e

            // REMOVE main(), comments, and directives
            if (!line.Contains("//") && !line.Contains("#include"))
            {
                // REMOVE whitespace
                line = line.Trim();

                // REMOVE unesseary strings from functions like printf, scanf, etc.
                string pattern = " ?\".*?\"";
                line = Regex.Replace(line, pattern, string.Empty);

                RawStatments.Add(line);
                
            }
        }

        private void BreakupBySemiColon()
        {
            foreach (string line in RawStatments)
            {
                if (line.Contains(";"))
                {
                    int iStart = 0;
                    int iEnd = 1;

                    foreach (char c in line)
                    {
                        if (c == ';')
                        {
                            L1Statments.Add(line.Substring(iStart, iEnd - iStart).Trim());
                            iStart = iEnd;
                        }
                        iEnd++;
                    }
                    if (iStart < iEnd - 1)
                        L1Statments.Add(line.Substring(iStart, line.Count() - iStart).Trim());
                }
                else
                {
                    L1Statments.Add(line);
                }
            
            }
        }

        private void BreakupByCompoundDeclaration()
        {
            foreach (string line in L1Statments)
            {
                if (CTypes.Any(x => line.Contains(x)))
                {
                    foreach (string type in CTypes)
                    {
                        Regex rx = new Regex(type + @"[\w,]+", RegexOptions.Compiled | RegexOptions.IgnoreCase);
                        MatchCollection matches = rx.Matches(line);
                        if (matches.Count > 0)
                        {
                            // remove type from line
                            string li = line.Substring(type.Length);
                            // split on ','
                            List<string> declatrationArray = li.Split(",").ToList();

                            // if last character is not a ";" add it
                            for (int i = 0; i < declatrationArray.Count; i++)
                            {
                                if (!declatrationArray[i].EndsWith(";"))
                                {
                                    declatrationArray[i] = declatrationArray[i] + ";";
                                }
                            }

                            // add RawStatments with type prefix
                            declatrationArray.ForEach(declatration => L2Statments.Add(type + " " + declatration.Trim()));
                            break;
                        }

                    }
                }
                else 
                {
                    L2Statments.Add(line);
                }
            }
        }


        public List<string> getSource()
        {
            return L2Statments;
        }

        public void Print()
        {
            L2Statments.ForEach(x => Console.WriteLine(x));
        }
    }
}
