#include "base64.h"


static const std::string Base64_Const = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";  


std::string base64_encode(std::string input_str)
{
	int len = input_str.length();
	unsigned char base64_str_t[4];  
    unsigned char base_char_t[3];  
  
    std::string tmp_str;  

  
    int i = 0;  
    for (int j = 0; j < len; j++)  
    {  
        base_char_t[i++] = input_str[j];  
  
        if (i == 3)  
        {  
            base64_str_t[0] = ((base_char_t[0] & 0xfc) >> 2);  
            base64_str_t[1] = ((base_char_t[0] & 0x03) << 4) | ((base_char_t[1] & 0xf0) >> 4);  
            base64_str_t[2] = ((base_char_t[1] & 0x0f) << 2) | ((base_char_t[2] & 0xc0) >> 6);  
            base64_str_t[3] = ((base_char_t[2] & 0x3f));  
  
            i = 0;  
  
            for (int k = 0; k < 4; k++)  
            {  
                tmp_str += Base64_Const[base64_str_t[k]];  
            }  
        }  
    }  
  
    if (i > 0)  
    {  
        for (int m = i; m < 3; m++)  
        {  
            base_char_t[m] = 0;  
        }  
  
        base64_str_t[0] = ((base_char_t[0] & 0xfc) >> 2);  
        base64_str_t[1] = ((base_char_t[0] & 0x03) << 4) | ((base_char_t[1] & 0xf0) >> 4);  
        base64_str_t[2] = ((base_char_t[1] & 0x0f) << 2) | ((base_char_t[2] & 0xc0) >> 6);  
        base64_str_t[3] = ((base_char_t[2] & 0x3f));  
  
        if (i == 1)  
        {  
            tmp_str += Base64_Const[base64_str_t[0]];  
            tmp_str += Base64_Const[base64_str_t[1]];  
            tmp_str += "=";  
            tmp_str += "=";  
        }  
        else if (i == 2)  
        {  
            tmp_str += Base64_Const[base64_str_t[0]];  
            tmp_str += Base64_Const[base64_str_t[1]];  
            tmp_str += Base64_Const[base64_str_t[2]];  
            tmp_str += "=";  
        }  
    }  
  
    return tmp_str;  
      
}

std::string base64_decode(std::string input_str)
{
	unsigned char base64_str_t[4];  
    unsigned char base_char_t[3];  
  
    std::string tmp_str;  
    int len = input_str.find("=");  
  
    if (len < 0)  
    {  
        len = input_str.length();  
    }  
  
    int i = 0;  
  
    for (int j = 0; j < len; j++)  
    {  
        base64_str_t[i++] = Base64_Const.find(input_str[j]);  
          
        if (i == 4)  
        {  
            base_char_t[0] = ((base64_str_t[0] & 0x3f) << 2) | ((base64_str_t[1] & 0x30) >> 4);  
            base_char_t[1] = ((base64_str_t[1] & 0x0f) << 4) | ((base64_str_t[2] & 0x3c) >> 2);  
            base_char_t[2] = ((base64_str_t[2] & 0x03) << 6) | (base64_str_t[3] & 0x3f);  
  
            i = 0;  
  
            for (int k = 0; k < 3; k++)  
            {  
                tmp_str += base_char_t[k];  
            }  
        }  
    }  
  
    if (i > 0)  
    {  
        for (int m = i; m < 4; m++)  
        {  
            base64_str_t[m] = 0;  
        }  
  
        base_char_t[0] = ((base64_str_t[0] & 0x3f) << 2) | ((base64_str_t[1] & 0x30) >> 4);  
        base_char_t[1] = ((base64_str_t[1] & 0x0f) << 4) | ((base64_str_t[2] & 0x3c) >> 2);  
        base_char_t[2] = ((base64_str_t[2] & 0x03) << 6) | (base64_str_t[3] & 0x3f);  
  
        for (int k = 0; k < 3; k++)  
        {  
            tmp_str += base_char_t[k];  
        }  
    }  
    return tmp_str;  
}