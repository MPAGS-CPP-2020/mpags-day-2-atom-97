// Standard Library includes
#include <string>

// For std::isalpha and std::isupper
#include <cctype>

// Function that transforms a single input char into output
std::string transformChar(const char in_char){
    // Uppercase if an alphabetic character
    if (std::isalpha(in_char)) {
      std::string s(1,std::toupper(in_char));
      return s;
    }

    // Transliterate digits to English words
    switch (in_char) {
      case '0':
	      return "ZERO";
      case '1':
	      return "ONE";
      case '2':
	      return "TWO";
      case '3':
	      return "THREE";
      case '4':
	      return "FOUR";
      case '5':
	      return "FIVE";
      case '6':
	      return "SIX";
      case '7':
	      return "SEVEN";
      case '8':
	      return "EIGHT";
      case '9':
	      return "NINE";
    }

    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.
    return "";
}