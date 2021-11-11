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
        private string DataLocation = @"C:/Users/Victo/Source/GPLAG-Plagerism-Detection/GPLAG-PD/GPLAG-PD/Data/src/";
        private List<string> RawStatments;
        private List<string> L1Statments;
        private string Filename;

        public PreProcessor(string filename)
        {
            this.Filename = filename;
            this.RawStatments = new List<string>();
            this.L1Statments = new List<string>();

            this.Open();
            this.BreakupBySemiColon();
            this.Print();
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
            // 4. Breakup repeated declarations ex. double a,b,c,d,e

            // REMOVE main(), comments, and directives
            if (!line.Contains("//") && !line.Contains("#include"))
            {
                // REMOVE whitespace
                line = line.Trim();

                // REMOVE unesseary strings from functions like printf, scanf, etc.
                string pattern = " ?\".*?\"";
                line = Regex.Replace(line, pattern, string.Empty);

                this.RawStatments.Add(line);
                
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
                            this.L1Statments.Add(line.Substring(iStart, iEnd - iStart).Trim());
                            iStart = iEnd;
                        }
                        iEnd++;
                    }
                    if (iStart < iEnd - 1)
                        this.L1Statments.Add(line.Substring(iStart, line.Count() - iStart).Trim());
                }
                else
                {
                    this.L1Statments.Add(line);
                }
            
            }
        }


        public List<string> getSource()
        {
            return L1Statments;
        }

        public void Print()
        {
            this.L1Statments.ForEach(x => Console.WriteLine(x));
        }
    }
}
