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

## Code Cleaning
The source code had to be cleaned prior to being tokenized. The following code cleaning steps have been made:

- Remove main(), comments, and directives
- Remove whitespace
- Remove unesseary strings from functions like printf, scanf, etc.
    - ex. `printf("Hello World!"); -> printf();`
- Breakup repeated declarations ex. double a,b,c,d,e
    - ex. `int a, b, c; -> int a; int bl; int c;`

scanf(, &c); if(c<0 || c>10) { printf (); return 0; }