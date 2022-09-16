#include <iostream>
#include <fstream>
#include <vector>

int solution(std::vector<int> v)
{
    int max = 1, len = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[i-1])
            len++;
        else
        {
            if (max < len)
                max = len;

            len = 1;
        }
    }

    if (max < len)
        max = len;

    return max * 10;
}

int main(void)
{
    std::ifstream infile("test.txt");
    if (infile.is_open())
        std::cout << "Nice" << '\n';
    else
        std::cout << "Not nice" << '\n';
    std::vector<int> v;
    std::string lineNumber;
    while(getline(infile, lineNumber)){
        v.push_back(stoi(lineNumber));
    }
    std::cout << v.size() << '\n';
    std::cout << solution(v) << std::endl;
    return 0;
}
