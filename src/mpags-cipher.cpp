// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// transformChar function
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "RunCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool encrypt {false};
  std::string inputFile {""};
  std::string outputFile {""};
  size_t key{0};

  // Terminate the funciton if CmdArgs gave errors, indicated failure by returning 1
  if (!processCommandLine(cmdLineArgs, helpRequested, versionRequested, encrypt, key ,inputFile, outputFile)){
    return 1;
  }
  else{
    // Handle help, if requested
    if (helpRequested) {
      // Line splitting for readability
      std::cout
        << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
        << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
        << "Available options:\n\n"
          << "  -h|--help        Print this help message and exit\n\n"
        << "  --version        Print version information\n\n"
        << "  -i FILE          Read text to be processed from FILE\n"
        << "                   Stdin will be used if not supplied\n\n"
        << "  -o FILE          Write processed text to FILE\n"
        << "                   Stdout will be used if not supplied\n\n";
      // Help requires no further action, so return from main
      // with 0 used to indicate success
      return 0;
    }

    // Handle version, if requested
    // Like help, requires no further action,
    // so return from main with zero to indicate success
    if (versionRequested) {
      std::cout << "0.1.0" << std::endl;
      return 0;
    }

    // Initialise variables for processing input text
    char inputChar {'x'};
    std::string inputText {""};

    // Read in user input from stdin/file
    // Warn that input file option not yet implemented
    std::ifstream in_file{inputFile};
    if (!in_file.good()) {      //'good' was 'empty' before, why?
      in_file.close();
      std::cout << "[warning] input from file ('"
                << inputFile
                << "') not implemented yet, using stdin\n";
      // Loop over each character from user input
      // (until Return then CTRL-D (EOF) pressed)
      while(std::cin >> inputChar)
      {
        inputText+=transformChar(inputChar);
      }
    }
    else {
      while(in_file >> inputChar){
        inputText+=transformChar(inputChar);
      }
      in_file.close();
    }
    inputText=runCaesarCipher(inputText, key, encrypt);

    std::ofstream out_file{outputFile, std::ios_base::app};
    // Output the transliterated text
    // Warn that output file option not yet implemented
    if (!out_file.good()) {
      out_file.close();
      std::cout << "[warning] output to file ('"
                << outputFile
                << "') not implemented yet, using stdout"<<std::endl;
      std::cout << inputText << std::endl;
    }
    else {
      out_file << inputText;
      out_file.close();
    }

    // No requirement to return from main, but we do so for clarity
    // and for consistency with other functions
    return 0;
  }
}

