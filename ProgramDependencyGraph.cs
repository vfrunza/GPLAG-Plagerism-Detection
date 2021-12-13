using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GPLAG_PD
{
    class ProgramDependencyGraph
    {
        private List<Token> Source;
        public List<Node> ControlGraph;
        public List<Node> DataGraph;

        public ProgramDependencyGraph(List<Token> source)
        {
            Source = source;
            ControlGraph = new List<Node>();
            DataGraph = new List<Node>();
        }

        public void BuildControlGraph()
        {
            Stack<Node> parents = new Stack<Node>();

            foreach (Token tk in Source)
            {
                if (tk.ID == 1 || tk.ID == 2 || tk.ID == Source.Count())
                {
                    //ignore main
                }
                else
                {
                    if (tk.TokenType == Token.Type.BracketClose && parents.Count != 0)
                    {
                        parents.Pop();
                    }
                    else if (tk.TokenType == Token.Type.BracketOpen)
                    {
                        // ignore
                    }
                    else
                    {
                        Node nd = new Node(tk, (Node.Type)tk.TokenType);
                        // if parent stack is empty, add node
                        if (parents.Count() == 0)
                        {
                            ControlGraph.Add(nd);
                        }
                        // if parent stack not empty, add node to last parent and add node
                        else if (parents.Count() != 0)
                        {
                            parents.Peek().Add(nd);
                            ControlGraph.Add(nd);
                        }
                        if (nd.NodeType == Node.Type.Control)
                        {
                            parents.Push(nd);
                        }
                        if (nd.NodeType == Node.Type.Increment)
                        {
                            nd.Add(nd);
                        }
                    }
                }
            }
        }

        public void BuildDataGraph()
        {
            foreach (Token tk in Source)
            {
                if (tk.ID == 1 || tk.ID == 2 || tk.ID == Source.Count())
                {
                    //ignore main
                }
                else
                {
                    // if node is a declaration, add it to parents
                    if (tk.TokenType == Token.Type.Declaration)
                    {
                        DataGraph.Add(new Node(tk, (Node.Type)tk.TokenType));
                    }
                    else
                    {
                        foreach (Node nd in DataGraph)
                        {
                            foreach (string vari in tk.Variables)
                            {
                                if (nd.tk.Variables.Contains(vari))
                                {
                                    nd.Add(new Node(tk, (Node.Type)tk.TokenType));
                                }
                            }
                        }
                    }
                }
            }
        }

        public void PrintControlGraph()
        {
            foreach (Node nd in ControlGraph)
            {
                Console.WriteLine(nd.ToString());
                if (nd.GetChildrenCount() != 0)
                {
                    Console.WriteLine(" | Children: ");
                    Console.WriteLine(nd.ToStringChildren());
                }
            }
        }

        public void PrintDataGraph()
        {
            foreach (Node nd in DataGraph)
            {
                Console.WriteLine(nd.ToString());
                if (nd.GetChildrenCount() != 0)
                {
                    Console.WriteLine(" | Children: ");
                    Console.WriteLine(nd.ToStringChildren());
                }
            }
        }

        public void ExportD3Data()
        {
            List<string> data = new List<string>();
            data.Add("source,target,value");

            foreach (Node nd in ControlGraph)
            {
                if (nd.GetChildrenCount() != 0)
                {
                    data.AddRange(nd.Export());
                }
            }

            var csv = new StringBuilder();

            foreach (string nd in data)
            {
                csv.AppendLine(nd);
            }

            File.WriteAllText("data-1066.csv", csv.ToString());

        }
    }
}
