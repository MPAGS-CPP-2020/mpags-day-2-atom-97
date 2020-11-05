// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// Function that processes the command line arguments
bool processCommandLine(const std::vector<std::string>& cmdArgs, bool& helpReq, bool& versionReq, bool& encrypt, size_t& key, std::string& inFile, std::string& outFile){
  
  // Function that processeses the command line arguments, checking whether version or help requested 
  // and setting i/o file names (if provided)
  // Returns true if sucesfull and false if not

  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdArgs.size()};

  //check whether encryption/decryption specfied
  bool mode=false;
  bool keyProvided=false;

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (cmdArgs[i] == "-h" || cmdArgs[i] == "--help") {
      helpReq = true;
    }
    else if (cmdArgs[i] == "--version") {
      versionReq = true;
    }
    else if (cmdArgs[i]=="--encrypt"){
      if (mode==true) {
        std::cerr << "[error] cannot both encyrpt and decrypt" <<std::endl;
        return false;
      }
      encrypt=true;
      mode=true;
    }
    else if (cmdArgs[i]=="--decrypt") {
      if (mode==true) {
        std::cerr << "[error] cannot both encyrpt and decrypt" <<std::endl;
        return false;
      }
      mode=true;
    }
    else if (cmdArgs[i]=="-key"){
      // Handle the key
      // Next element is the key unless -i is the last argument
      if (i == nCmdLineArgs-1) {
	      std::cerr << "[error] -key requires a filename argument" << std::endl;
	      // exit the function with false return to indicate failure
	      return false;
      }
      else {
	      // got a key, so convert it to the right format and advance past it
	      key = std::stoul(cmdArgs[i+1])%26;
        keyProvided=true;
	      ++i;
      }
    }
    else if (cmdArgs[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
	      std::cerr << "[error] -i requires a filename argument" << std::endl;
	      // exit the function with false return to indicate failure
	      return false;
      }
      else {
	      // Got filename, so assign value and advance past it
	      inFile = cmdArgs[i+1];
	      ++i;
      }
    }
    else if (cmdArgs[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
	      std::cerr << "[error] -o requires a filename argument" << std::endl;
	      // exit the function with false return to indicate failure
	      return false;
      }
      else {
	      // Got filename, so assign value and advance past it
	      outFile = cmdArgs[i+1];
	      ++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // return false to indicate failure
      std::cerr << "[error] unknown argument '" << cmdArgs[i] << "'\n";
      return false;
    }
  }
  if (mode==false){
    std::cerr << "[error] please specify the mode (encrypt/decrypt)" <<std::endl;
    return false;
  }
  else if(keyProvided==false){
    std::cerr << "[error] please provide the key" <<std::endl;
    return false;
  }
  // return true if all args processed correctly
  return true;
}