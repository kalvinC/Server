#ifndef BASE64_H
#define BASE64_H

#include <string>

/**
*@param[in] string which need to be encoded.
*@return encoded string.
*/
std::string base64_encode(std::string input_str);


/**
*@param[in] string which need to be decoded.
*@return decoded string.
*/
std::string base64_decode(std::string input_str);

#endif