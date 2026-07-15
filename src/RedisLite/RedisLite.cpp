#include "../../include/RedisLite.h"

RedisCLI::RedisCLI()
{
    running = true;
}

void RedisCLI::displayPrompt() const
{
    std::cout << "redis-lite> ";
}

DynamicArray<std::string> RedisCLI::parseCommand(const std::string& input) const
{
    DynamicArray<std::string> tokens;

    std::string word;

    for(size_t i=0;i<input.length();i++)
    {
        if(input[i]==' ')
        {
            if(!word.empty())
            {
                tokens.append(word);
                word.clear();
            }
        }
        else
        {
            word+=input[i];
        }
    }

    if(!word.empty())
        tokens.append(word);

    if(tokens.size()>0)
    {
        for(char &c : tokens[0])
        {
            if(c>='a' && c<='z')
                c=c-'a'+'A';
        }
    }

    return tokens;
}

void RedisCLI::run()
{
    std::cout << "=========================================\n";
    std::cout << "       Welcome to Redis Lite\n";
    std::cout << "=========================================\n";
    std::cout << "Type HELP to see all available commands.\n";
    std::cout << "Type EXIT to quit.\n\n";

    while (running)
    {
        displayPrompt();

        std::string input;
        std::getline(std::cin, input);

        DynamicArray<std::string> tokens = parseCommand(input);

        if (tokens.size() == 0)
            continue;

        executeCommand(tokens);
    }

    std::cout << "\nGoodbye!\n";
}

void RedisCLI::executeCommand(const DynamicArray<std::string>& tokens)
{
    if(tokens[0]=="SET")
        handleSet(tokens);
    
    else if (tokens[0] == "KEYS")
    {
        handleKeys();
    }

    else if(tokens[0]=="GET")
        handleGet(tokens);

    else if(tokens[0]=="DEL")
        handleDel(tokens);

    else if(tokens[0]=="EXISTS")
        handleExists(tokens);

    else if(tokens[0]=="COUNT")
        handleCount();

    else if(tokens[0]=="CLEAR")
        handleClear();

    else if(tokens[0]=="HELP")
        handleHelp();

    else if(tokens[0]=="EXIT")
        running=false;

    else
        std::cout<<"Unknown Command\n";
}

void RedisCLI::handleSet(const DynamicArray<std::string>& tokens)
{
    if(tokens.size()!=3)
    {
        std::cout<<"Usage : SET <key> <value>\n";
        return;
    }

    store.put(tokens[1],tokens[2]);

    std::cout<<"OK\n";
}

void RedisCLI::handleGet(const DynamicArray<std::string>& tokens)
{
    if(tokens.size()!=2)
    {
        std::cout<<"Usage : GET <key>\n";
        return;
    }

    if(store.contains(tokens[1]))
        std::cout<<store.get(tokens[1])<<std::endl;
    else
        std::cout<<"(nil)\n";
}

void RedisCLI::handleDel(const DynamicArray<std::string>& tokens)
{
    if(tokens.size()!=2)
    {
        std::cout<<"Usage : DEL <key>\n";
        return;
    }

    std::cout<<store.remove(tokens[1])<<std::endl;
}

void RedisCLI::handleExists(const DynamicArray<std::string>& tokens)
{
    if(tokens.size()!=2)
    {
        std::cout<<"Usage : EXISTS <key>\n";
        return;
    }

    std::cout<<store.contains(tokens[1])<<std::endl;
}

void RedisCLI::handleCount()
{
    std::cout<<store.size()<<std::endl;
}

void RedisCLI::handleClear()
{
    store.clear();

    std::cout<<"OK\n";
}

void RedisCLI::handleKeys()
{
    if (store.empty())
    {
        std::cout << "(empty)\n";
        return;
    }

    bool first = true;

    store.forEach([&](const std::string& key, const std::string&)
    {
        if (!first)
            std::cout << " ";

        std::cout << key;
        first = false;
    });

    std::cout << '\n';
}

void RedisCLI::handleHelp()
{
    std::cout << "\nAvailable Commands:\n\n";

    std::cout << "SET <key> <value>   - Insert or update a key-value pair\n";
    std::cout << "GET <key>           - Retrieve the value of a key\n";
    std::cout << "DEL <key>           - Delete a key\n";
    std::cout << "EXISTS <key>        - Check if a key exists\n";
    std::cout << "KEYS                : Display all stored keys\n";
    std::cout << "COUNT               - Show total number of keys\n";
    std::cout << "CLEAR               - Remove all key-value pairs\n";
    std::cout << "HELP                - Show this help message\n";
    std::cout << "EXIT                - Exit Redis Lite\n\n";
}

