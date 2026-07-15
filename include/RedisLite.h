#ifndef REDISCLI_H
#define REDISCLI_H

#include <iostream>
#include <string>

#include "HashMap.h"
#include "DynamicArray.h"

class RedisCLI
{
private:

    HashMap<std::string,std::string> store;

    bool running;

    void displayPrompt() const;

    DynamicArray<std::string> parseCommand(const std::string& input) const;

    void executeCommand(const DynamicArray<std::string>& tokens);

    void handleSet(const DynamicArray<std::string>& tokens);

    void handleGet(const DynamicArray<std::string>& tokens);

    void handleDel(const DynamicArray<std::string>& tokens);

    void handleExists(const DynamicArray<std::string>& tokens);

    void handleCount();

    void handleClear();

    void handleKeys();

    void handleHelp();

public:

    RedisCLI();

    void run();
};

#endif