/**
 * @file HelperFunctions.cpp
 * @author alfonsowolski
 * @date 2025-04-11
 * @brief A file of helpful functions
 * 
 * a file of helpful functions including: ComesBefore toLower
 */

#include "HelperFunctions.h"
#include <string>

namespace HelperFunctions{
  
  std::string toLower(std::string str);
  
  bool ComesBefore(std::string str1, std::string str2){
    int strLen = str1.length();
    
    if(strLen > (int)str2.length()){ // if str2 is smaller then change strLen
      strLen = str2.length();
    }
    str1 = toLower(str1);
    
    str2 = toLower(str2);
    
    for(int i = 0; i < strLen; i++){                 
      
      if(str1[i] < str2[i]){
	
	return true;
	
      }
      else if(str1[i] > str2[i]){
	
	return false;
	
      }
    }
    
    return false;
  }
  
  std::string toLower(std::string str){
    for(int i = 0; i < (int)str.length(); i++){
      if(str[i] >= 'A' && str[i] <= 'Z'){
	str[i] = str[i] + ('a' - 'A');
      }
    }
    return str;
  }

  std::string filterChars(std::string str, std::string allowedChars){
    std::string newStr = "";
    for(int i = 0; i < (int)str.length(); i++){
      for(int j = 0; j < (int)allowedChars.length(); j++){
	if( str[i] == allowedChars[j] ){
	  newStr += str[i];
	  break;
	}
      }
    }
    
    return newStr;
  }
  
} // end of HelperFunctions
