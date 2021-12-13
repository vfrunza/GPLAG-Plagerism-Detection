using System;
using GPLAG_PD;


Console.WriteLine("GPLAG Plagerism Detection for C\n\n");

// Manual Test Cases
//Lexer lx = new Lexer("A2016/Z1/Z1/test.c");
//Lexer lx2 = new Lexer("A2016/Z1/Z1/test2.c");

// Identical Student Submissions - Fails
Lexer lx = new Lexer("A2016/Z1/Z1/student3331.c");
Lexer lx2 = new Lexer("A2016/Z1/Z1/student5573.c");

// Identical Student Submissions
//Lexer lx = new Lexer("A2016/Z1/Z1/student7386.c");
//Lexer lx2 = new Lexer("A2016/Z1/Z1/student5378.c");

// Random
//Lexer lx = new Lexer("A2016/Z1/Z1/student5304.c");
//Lexer lx2 = new Lexer("A2016/Z1/Z1/student5140.c");

//Lexer lx2 = new Lexer("A2016/Z1/Z1/student1066.c");
ProgramDependencyGraph pdg = new ProgramDependencyGraph(lx.ExportTokens());
ProgramDependencyGraph pdg2 = new ProgramDependencyGraph(lx2.ExportTokens());


Console.WriteLine("===CONTROL GRAPH====================");
pdg.BuildControlGraph();
pdg.PrintControlGraph();

Console.WriteLine();
Console.WriteLine();

Console.WriteLine("===DATA GRAPH====================");
pdg.BuildDataGraph();
pdg.PrintDataGraph();


Console.WriteLine("===CONTROL GRAPH====================");
pdg2.BuildControlGraph();
pdg2.PrintControlGraph();

Console.WriteLine();
Console.WriteLine();

Console.WriteLine("===DATA GRAPH====================");
pdg2.BuildDataGraph();
pdg2.PrintDataGraph();

GraphIsomorphism graphComparison = new GraphIsomorphism(pdg, pdg2);

pdg.ExportD3Data();



 