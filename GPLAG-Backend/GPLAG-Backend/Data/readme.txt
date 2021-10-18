The archive provided consists of three parts:

SOURCE CODES:

Actual submitted homeworks by students (i.e. their source codes) are stored in folder "src". Subfolders of this folder are named after courses: A2016, A2017, B2016 and B2017. This further contain subfolders for individual assignments. On each course students were required to solve 16-22 assignments labeled "Z1/Z1", "Z1/Z2", "Z2/Z1" etc. Finally, in each folder are actual C or C++ files named after student (anonymized, so actual student names were replaced by strings in form "student1393").

TRACES:

IDE usage traces are stored in folder named "stats". Again, this folder is organized into subfolders named after courses. These folders contain files named after student (anonymized) with extension .stats and are in JSON format. Top level JSON object has paths within course folders as keys, so these paths include all folders and files within student workspace. Value is another JSON object with following keys:

- total_time: Estimated time student spent working within this folder (in seconds)

- builds: Number of times student attempted to compile the code

- builds_succeeded: Number of times program was compiled without errors

- testings: Number of times unit tests were executed

- last_test_results: String of form "X/Y" where X is number of successful test and Y is total number of tests

- events: array of JSON objects describing a "change event"

- last_revision: internal information of last SVN revision corresponding to this file, can be ignored

- entries: for folder this is a list of entries (files or subfolders) within this folder 

Event objects have the following keys:

- time: UNIX timestamp

- text: describes the type of event. Supported types are: created (file created), deleted, rename, created_folder, compiled, compiled successfully, modified (individual lines modification)

- filename: for created or rename, the filename

- old_filename: for rename, previous filename

- old_filepath: for rename, full path

- content: for created and rename, provides file content

- output: for compiled, compiled successfully, etc. compiler output

- diff: for modified, an array of line-by-line changes compared to previous version of file. This array contains objects with keys: "change" (lines that were changed), "add_lines" (lines that were added) and "remove_lines" (lines that were removed). Each of these is once again an object where keys are line numbers (relative to previous version of file), and values are new contents of corresponding line

GROUND TRUTH:

Ground truth lists students and groups of students that are considered to have involved in plagiarism due to code similarity and failure to deliver an "oral defense". There are three ground truth files. ground-truth-anon.txt contains full list of plagiarisms, ground-truth-static-anon.txt only those based on source code similarity, and ground-truth-dynamic-anon.txt only those based on failure to do an "oral defense". There is some overlap between the last two files. The format of the file is: homework assignment in the format:

- A2016/Z1/Z1

(dash, space, course name, slash, assignment name), followed by lists of anonymized names of students (such as "student3241") or groups of students who are mutually plagiarised separated by comma.
