/**
 * @file HelperFunctions.h
 * @author alfonsowolski
 * @date 2025-04-11
 * @brief definition of the HelperFunctions namespace
 * 
 * definition of the Helper Functions namespace
 */

#pragma once
#include <string>

namespace HelperFunctions{

  std::string toLower(std::string str);

  bool ComesBefore(std::string str1, std::string str2);

  std::string filterChars(std::string str, std::string allowedChars);
  
}
