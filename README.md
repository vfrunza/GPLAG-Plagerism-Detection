# Code Plagerism Detection using GPLAG 

This project was for COSC 329 Learning Analytics. In this project I used [this](https://ieee-dataport.org/open-access/programming-homework-dataset-plagiarism-detection) dataset compiled by Vedran Ljubovic for sample assignments submitted by students. Along with code samples, this dataset also contains a file called `ground-truth-static-anon.txt` which contains a list of plagerism cases based on code similarity. An example snippet is shown below:

```
- A2016/Z1/Z1
student7386,student5378,student9538
student2821,student8295
student4934,student6617
student8598,student3331,student5573,student9498,student8796
student7888,student7704
```

Each row contains an instance of plagerism, and each student id listed participated in that plagerism. All instances listed in this file are related to code similarity, and not a student failing an oral defense when questioned by the instructor.

The goal of this project will be to use the GPLAG algorithm to come to the same or similar conclusion of plagerism as the `ground-truth-static-anon.txt` file.

## Preprocessing
The source code had to be cleaned prior to being tokenized. The following code cleaning steps have been made:

- Remove main(), comments, and directives
- Remove whitespace
- Remove unesseary strings from functions like printf, scanf, etc.
    - ex. `printf("Hello World!"); -> printf();`
- Breakup repeated declarations ex. double a,b,c,d,e
    - ex. `int a, b, c; -> int a; int bl; int c;`

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

This list contains token idexes, the type of statment, the statment itself, and the variables involved in the statment. This data is then used to create the program dependency graph.

## References
Vedran Ljubovic, May 8, 2020, "Programming Homework Dataset for Plagiarism Detection", IEEE Dataport, doi: [https://dx.doi.org/10.21227/71fw-ss32](https://dx.doi.org/10.21227/71fw-ss32).

## External Tools

### Uncrustify
I used [uncrustify](https://github.com/uncrustify/uncrustify), a C/C++ beautifying tool, as part of the preprocessing step. This tool standardized the source code by inserting `{ }` on single line `if/else` controls, added spacing around operators and variables, along with other small changes. 

The variety of source code styles by different students made preprocessing manually very difficult. This tool let me skip some of preprocessing and instead focus on processing what is required for my program such as breaking statments into single lines, tokenizing, cleaning strings, and removing unessesary lines.