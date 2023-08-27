#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<pair<regex, string>> rules = {
    {regex("Hi|Hello|Hey there|Hola", regex_constants::icase), "Hello! Good Afternoon!! How can I assist you?"},
    {regex("fine", regex_constants::icase), "Great to hear that, How can I help you?"},
    {regex(".*sorry.* ", regex_constants::icase), "Its ok, never mind"},
    {regex(".*age.*", regex_constants::icase), "I'm a computer program so i dont have a specific age!!"},
    {regex(".*your.*name", regex_constants::icase), "My name is Chatbot."},
    {regex(".*sports.*|sports|sport", regex_constants::icase), "I love Sports !! I like playing Cricket"},
    {regex(".*actor.*", regex_constants::icase), "Hrithik Roshan is my Favourite Actor !"},
    {regex(".*created.* | .*creator.*", regex_constants::icase), "Suyog Jadhav created me!!"},
    {regex("how.*are.*you", regex_constants::icase), "I'm doing well, How about you?"},
    {regex("location|city|.*location.*|.*city.*", regex_constants::icase), "Pune, Maharashtra"},
    {regex(".*weather.*", regex_constants::icase), "Its too hot here in pune!!"},

    {regex("exit", regex_constants::icase), "Goodbye!"},
};

string generateResponse(string &userInput)
{
    for (const auto &rule : rules)
    {
        if (regex_search(userInput, rule.first))
        {
            return rule.second;
        }
    }
    return "I'm sorry, I don't understand.";
}

int main()
{
    string userInput;
    std::cout << "Chatbot: Hello! How can I assist you?" << std::endl;
    while (true)
    {
        std::cout << "User: ";
        getline(cin, userInput);
        string response = generateResponse(userInput);
        cout << "Chatbot: " << response << std::endl;
        if (regex_search(userInput, regex("exit", regex_constants::icase)))
        {
            break;
        }
    }
}
