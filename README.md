# Code Plagiarism Detection using GPLAG 

## Installation
To run this project you need Visual Studio 2022 and.NET 6 installed.

1. Download this repo.
2. Open the `GPLAG-PD.sln` solution file. It will open new instance of Visual Studio.
3. Right clik on the project in the solutioon explorer, click `Add` then `Project Reference`.
5. Click `Browse` in the left hand sidebar. Then click `Browse` in the bottom right.
6. Locate the file `VfLib.dll` in the root of the repo and add it as a reference.
7. In `Program.cs` I've left a sample of test cases you can run. Simply comment out/in the files you wish to run.
8. Press F5 to run the project.

## Project

This project was for COSC 329 Learning Analytics. In this project I used [this](https://ieee-dataport.org/open-access/programming-homework-dataset-plagiarism-detection) dataset compiled by Vedran Ljubovic for sample assignments submitted by students. Along with code samples, this dataset also contains a file called `ground-truth-static-anon.txt` which contains a list of Plagiarism cases based on code similarity. An example snippet is shown below:

```
- A2016/Z1/Z1
student7386,student5378,student9538
student2821,student8295
student4934,student6617
student8598,student3331,student5573,student9498,student8796
student7888,student7704
```

Each row contains an instance of plagiarism, and each student id listed participated in that plagiarism. All instances listed in this file are related to code similarity, and not a student failing an oral defense when questioned by the instructor.

The goal of this project will be to use the GPLAG algorithm to come to the same or similar conclusion of plagiarism as the `ground-truth-static-anon.txt` file.

## Preprocessing
The source code had to be cleaned prior to being tokenized. The following code cleaning steps have been made:

- Remove main(), comments, and directives
- Remove whitespace
- Remove unesseary strings from functions like printf, scanf, etc.
    - ex. `printf("Hello World!"); -> printf();`
- Breakup repeated declarations ex. double a,b,c,d,e
    - ex. `int a, b, c; -> int a; int b; int c;`

## Tokization
The program will the tokenize the source code, creating the following list:

```
23    | Declaration  | double  BO;                                        | BO
24    | Control      | if (TP1 < 0 || TP1 > 20)                           | TP1
25    | BracketOpen  | {                                                  |
26    | Control      | return(0);                                         |
27    | BracketClose | }                                                  |
...
84    | Assignment   | TBB = TP1 + TP2 + TZ + TP + TZI;                   | TBB TP1 TP2 TZ TP TZI
85    | Assignment   | MBB = MP1 + MP2 + MP + MZ + MZI;                   | MBB MP1 MP2 MP MZ MZI
```

This list contains token indexes, the type of statement, the statement itself, and the variables involved in the statement. This data is then used to create the program dependency graph.

The main method it uses is regex expressions for identifying different parts of a statements. For example, it will look for lone types like int or double. It will search for control keywords, as well as function call sites (words followed by parenthesis).


# Program Dependency Graph
For the explination, I'll be using this C program as an example:
```c
#include <stdio.h>
int main()
{
    int n;
    int remainder, original;
    int reversed = 0
    printf("Enter an integer: ");
    scanf("%d", &n);
    original = n;

    // reversed integer is stored in reversed variable
    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    // palindrome if orignal and reversed are equal
    if (original == reversed)
    {
        printf("%d is a palindrome.", original);
    }
    else
    {
        printf("%d is not a palindrome.", original);
    }

    return 0;
}
```

The program builds it's data and control graphs as ajacentcy lists. An example output of the control graph is shown below:

```
NODE | ID: 10, Type: Control, Statment:    n != 0
 | Children:
 | 12, Assignment, remainder = n % 10; | 13, Assignment, reversed = reversed * 10 + remainder; | 14, Assignment, n /= 10;
NODE | ID: 12, Type: Assignment, Statment: remainder = n % 10;
NODE | ID: 13, Type: Assignment, Statment: reversed = reversed * 10 + remainder;
```
Here we can see that node 10 is a control node, in this case `while (n != 0)`. Inside of this copntrol there are three statments:
```c
remainder = n % 10;
reversed = reversed * 10 + remainder;
n /= 10;
```

which are reflected in the output above as nodes 12-14. The same process happens for data dependencies. Following the dependency of the variable n we see:

```
NODE | ID: 3, Type: Declaration, Statment: int  n;
 | Children:
 | 8, CallSite, scanf("%d", &n); | 9, Assignment, original = n; | 10, Control,    n != 0  | 12, Assignment, remainder = n % 10; | 14, Assignment, n /= 10;
```
which are indead the nodes that utilize n as a variable in the program. Please note that this list represents chains of variable dependencies as it appears in the sopuce code. It should be interpreted as 3 has the child 8 -> 9 -> 10 -> 12 -> 14. When this data is fed into the isomorphism function, it is encoded as each node having only one child.

## External Tools

I tried to limit what external tools I used so that the project would be my work. I made two exceptions. Uncrustify to parse the input source files to beautify them and VFlib for checking isomorphism. 

### Uncrustify
I used [uncrustify](https://github.com/uncrustify/uncrustify), a C/C++ beautifying tool, as part of the preprocessing step. This tool standardized the source code by inserting `{ }` on single line `if/else` controls, added spacing around operators and variables, along with other small changes. 

The variety of source code styles by different students made preprocessing manually very difficult. This tool let me skip some of preprocessing and instead focus on processing what is required for my program such as breaking statments into single lines, tokenizing, cleaning strings, and removing unessesary lines.

### VF Graph Comparing library
I used this C# implementation of the [VF Graph Isomorphism Algorithm](https://github.com/darrellp/GraphIsomorphism) (details [here](https://www.codeproject.com/Articles/23144/A-C-Implementation-of-the-VF-Graph-Isomorphism-Alg)) by Darrell Plank. This C# library has more sophisticated subgraph isomorphism methods than anything I could've come up with and runs significantly faster than a n! comparison class I would've had to make. 

I used it to build two different graphs using my alreay existing PDG, one for each type of edge (this library only checks for node types, not edge types) and then I match those two graphs against the suspect PDG's two graphs. The result from this library returns a list of index of mapped nodes. Should a node not match, the mapping returns -1 for that node index. This can be used to create a &#947;-Isomorphic GPLAG version of the algorithm using the amount of unmatched nodes.

## References
Liu, Chao & Chen, Fen & Han, Jiawei & Yu, Philip. (2006). GPLAG: Detection of software plagiarism by program dependence graph analysis. Proceedings of the ACM SIGKDD International Conference on Knowledge Discovery and Data Mining. 2006. 872-881. 10.1145/1150402.1150522.

Vedran Ljubovic. (2020). Programming Homework Dataset for Plagiarism Detection. IEEE Dataport. https://dx.doi.org/10.21227/71fw-ss32