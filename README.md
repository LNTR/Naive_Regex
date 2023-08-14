# Naive_Regex

DSA 3 Assignment 01 - matching regular expressions using naive string matching algorithm

## Justification

Since Naive approach is the easiest to implement, I have used it for the assignment over the others. Another reason why I picked this is because we can introduce new types of regex symbols to program easily without having to modify the source code compared to other algorithms(KMP and RK algorithms requires complex procedures to handle new symbols because we have to modify their prefix function)

## Pattern Matching

This is a C++ program that reads a pattern and a text from two files, and finds the positions in the text where the pattern matches. The pattern can contain special symbols like ^, $, and . that have different meanings.

## Features

The program can handle patterns that start with ^, which means that the pattern must match at the beginning of the text.
The program can handle patterns that end with $, which means that the pattern must match at the end of the text.
The program can handle patterns that contain ., which means that it can match any character.

The program writes the matching positions to another file.

## Usage

To use this program, you need to have two files: one for the pattern and one for the text. The files should be named pattern1.txt and text1.txt respectively, and should be placed in the test folder. The pattern file should contain only one line with the pattern, and the text file should contain only one line with the text. For example:

### pattern1.txt:

```
^a.b$
```

### text1.txt:

```
abcab
```

The program will read these files and find the positions in the text where the pattern matches. The output will be written to another file named patterntext1.output, which will be placed in the out folder. The output file will contain one line for each matching position, followed by an empty line. For example:

### patterntext1.output:

```
0

3
```

This means that the pattern matches at positions 0 and 3 in the text.

## Installation

To install this program, you need to have a C++ compiler and an editor of your choice.Then, you can compile the program using the following command:

```
g++ -o pattern_matching main.cpp
```

This will create an executable file named pattern_matching in the same folder as main.cpp.

## Testing

Test cases are stored in **test** folder. The relevent text for patter**n**.txt is text**n**.txt. And their output will be generated in **out** folder, with the name **patterntextn_output.txt**

## Dependencies

This program does not have any external dependencies. It only uses standard C++ libraries such as iostream, string, vector, and fstream.
