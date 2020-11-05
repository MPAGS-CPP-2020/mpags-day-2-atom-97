// Standard Library includes
#include <string>
#include <vector>
#include <algorithm>

// Define the function
std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt ){
    // Create the alphabet container and output string
    std::vector<char> alphabet={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string output{""};
    // Loop over the input text
    for (std::string::size_type i=0; i<inputText.size(); i++){
        // For each character find the corresponding position in the alphabet
        size_t index=std::find(alphabet.begin(), alphabet.end(), inputText[i])-alphabet.begin();
        // Apply the shift (+ve or –ve depending on encrypt/decrypt)
        // to the position, handling correctly potential wrap-around
        // Determine the new character and add it to the output string
        if (encrypt) {output+=alphabet[(index+key)%26];}
        else {output+=alphabet[(index-key+26)%26];}
    }
    // Finally (after the loop), return the output string
    return output;
}