#include <iostream>
#include <map>
#include <string>

#define LOG(x) std::cout << x << std::endl

int main2()
{
    std::string word;
    std::map<char, int> frequencyMap;

    LOG("Enter Word");
    std::getline(std::cin, word);

    for (char ch : word)
    {
        frequencyMap[ch]++;
    }

    LOG("Letter counts:");
    for (const auto& pair : frequencyMap)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
