using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using vflibcs;

namespace GPLAG_PD
{
    class GraphIsomorphism
    {
        ProgramDependencyGraph G;
        ProgramDependencyGraph G1;

        public GraphIsomorphism(ProgramDependencyGraph g, ProgramDependencyGraph g1)
        {
            this.G = g; 
            this.G1 = g1;

            Graph gControlGraph = new Graph();
            Graph gDataGraph = new Graph();

            gControlGraph = BuildC(g);
            gDataGraph = BuildD(g);


            Graph g1ControlGraph = BuildC(g1);
            Graph g1DataGraph = BuildD(g1);

            VfState graphCompControl = new VfState(gControlGraph, g1ControlGraph, false, true);
            FullMapping nodeMap = graphCompControl.Match();

            if (nodeMap != null)
            {
                // Check matching source 1 to 2
                bool Isomorphic = true;
                double unmappedNodes = 0;
                double totalNodes = nodeMap.IsomorphismVid1ToVid2.Count();
                foreach (KeyValuePair<int, int> match in nodeMap.IsomorphismVid1ToVid2)
                {
                    if (match.Value == -1)
                    {
                        //Console.WriteLine("No mapping found for control node " + match.Key.ToString() + " in Source 2");
                        Isomorphic = false;
                        unmappedNodes++;
                    }
                }


                VfState graphCompData = new VfState(gDataGraph, g1DataGraph, false, true);
                nodeMap = graphCompData.Match();
                totalNodes += nodeMap.IsomorphismVid1ToVid2.Count();

                // Check matching source 1 to 2
                foreach (KeyValuePair<int, int> match in nodeMap.IsomorphismVid1ToVid2)
                {
                    if (match.Value == -1)
                    {
                        //Console.WriteLine("No mapping found for data node " + match.Key.ToString() + " in Source 2");
                        Isomorphic = false;
                        unmappedNodes++;
                    }
                }

                Console.WriteLine("Perfectly Isomorphic: " + Isomorphic.ToString());
                Console.WriteLine("Percent similar: " + ((1.0 - (unmappedNodes / totalNodes)) * 100.0).ToString() + "%");
            }
            else
            {
                Console.WriteLine("Failed to detect matches.");
            }
        }

        private Graph BuildC(ProgramDependencyGraph g)
        {
            Graph graph = new Graph();
            Dictionary<int, int> gMap = new Dictionary<int, int>();

            // Add nodes to graph
            foreach (Node n in g.ControlGraph)
            {
                int id = graph.InsertVertex(n.NodeType);
                gMap[n.ID] = id;
            }

            // Add control edges
            foreach (Node n in g.ControlGraph)
            {
                if (n.Children.Count > 0)
                {
                    foreach (Node child in n.Children)
                    {
                        graph.AddEdge(gMap[n.ID], gMap[child.ID]);
                    }
                }
            }

            return graph;
        }

        private Graph BuildD(ProgramDependencyGraph g)
        {
            Graph graph = new Graph();
            Dictionary<int, int> gMap = new Dictionary<int, int>();


            // Add nodes to graph
            foreach (Node n in g.ControlGraph)
            {
                int id = graph.InsertVertex(n.NodeType);
                gMap[n.ID] = id;
            }

            // Add control edges
            foreach (Node n in g.DataGraph)
            {
                if (n.Children.Count > 0)
                {
                    Node prevChild = n;
                    foreach (Node child in n.Children)
                    {
                        Console.WriteLine(prevChild.ToString());
                        Console.WriteLine(child.ToString());

                        if (!gMap.ContainsKey(child.ID))
                        {
                            int id = graph.InsertVertex(child.NodeType);
                            gMap[child.ID] = id;
                        }
                        if (!gMap.ContainsKey(prevChild.ID))
                        {
                            int id = graph.InsertVertex(prevChild.NodeType);
                            gMap[prevChild.ID] = id;
                        }
                        try
                        {
                            graph.AddEdge(gMap[prevChild.ID], gMap[child.ID]);
                        }
                        catch
                        {
                            Console.WriteLine("Edge Already Added");
                        }
                        prevChild = child;
                    }
                }
            }

            return graph;
        }
    }
}
