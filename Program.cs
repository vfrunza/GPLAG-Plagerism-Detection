using System;
using GPLAG_PD;


Console.WriteLine("GPLAG Plagerism Detection for C\n\n");

Lexer lx = new Lexer("A2016/Z1/Z1/test.c");
ProgramDependencyGraph pdg = new ProgramDependencyGraph(lx.ExportTokens());
pdg.BuildControlGraph();
pdg.PrintControlGraph();

pdg.ExportD3Data();



 