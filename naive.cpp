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

ifstream PatternFile("./test/pattern1.txt");
ifstream TextFile("./test/text1.txt");
ofstream PatternTextFile("./out/patterntext1.output");

main(int, char **)
{
    PatternFile >> pattern;
    TextFile >> text;

    int patternCharacterCount = getPatternLetterCount(pattern);

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
                if (textIndex + patternIndex == text.length())
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

void writeToTextFile()
{
    for (int positon : positionVector)
    {
        PatternTextFile << positon << "\n"
                        << endl;
    }
    PatternTextFile.close();
}
