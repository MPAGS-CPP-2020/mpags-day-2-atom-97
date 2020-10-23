#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// Declare the funciton
bool processCommandLine(const std::vector<std::string>& cmdArgs, bool& helpReq, bool& versionReq, std::string& inFile, std::string& outFile);

#endif //MPAGSCIPHER_PROCESSCOMMANDLINE_HPP