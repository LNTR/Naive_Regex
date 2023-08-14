#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string pattern;

string text;

vector<int> positionVector;

int getPatternLetterCount(string pattern);
void writeToTextFile();
string readTextFromFile(ifstream &File);
ifstream PatternFile("./test/pattern6.txt");
ifstream TextFile("./test/text6.txt");
ofstream PatternTextFile("./out/patterntext6_output.txt");

main(int, char **)
{
    pattern = readTextFromFile(PatternFile);
    text = readTextFromFile(TextFile);
    int patternCharacterCount = getPatternLetterCount(pattern);

    if (patternCharacterCount <= text.length())
    {
        for (int textIndex = 0; textIndex < text.length() - patternCharacterCount + 1; textIndex++)
        {
            int patternIndex = 0;
            int symbolCount = 0;

            while (patternIndex < pattern.length())
            {

                if (pattern[patternIndex] == '^')
                {
                    if (textIndex == 0)
                    {
                        patternIndex++;
                        symbolCount++;
                    }
                    else
                    {
                        break;
                    }
                }

                else if (pattern[patternIndex] == '$')
                {
                    if (textIndex + patternIndex - symbolCount == text.length())
                    {
                        patternIndex++;
                        symbolCount++;
                    }
                    else
                    {
                        break;
                    }
                }
                else if ((pattern[patternIndex] == text[textIndex + patternIndex - symbolCount]) || ((pattern[patternIndex] == '.')))
                {
                    patternIndex++;
                }
                else
                {
                    break;
                }
            }

            if (patternIndex == pattern.length())
            {
                positionVector.push_back(textIndex);
            }
        }
    }
    writeToTextFile();
}

int getPatternLetterCount(string pattern)
{
    int count = 0;
    for (auto character : pattern)
    {
        if (!((character == '$') || (character == '^')))
        {
            count++;
        }
    }
    return count;
}

string readTextFromFile(ifstream &File)
{
    string text;
    while (getline(File, text))
        ;
    return text;
}

void writeToTextFile()
{
    if (positionVector.size() == 0)
    {
        PatternTextFile << "Not Found";
    }
    for (int positon : positionVector)
    {
        PatternTextFile << positon << "\n"
                        << endl;
    }
    PatternTextFile.close();
}
