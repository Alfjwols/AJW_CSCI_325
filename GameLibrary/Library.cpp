/**
 * @file Library.cpp
 * @author alfonsowolski
 * @date 2025-04-04
 * @brief Implimentation of the Library class
 * 
 * Implementation of the Library class
 */

#include "Game.h"
#include "Library.h"

#include <list>
#include <iostream>
#include <iomanip>

bool isBefore(std::string str1, std::string str2);

Library::Library(){
  ListSize = 0;
}

void Library::insert_sorted(Game g){
  std::list<Game>::iterator it;
  // cycles through list to figure out where to place
  for(it = GamesList.begin(); it != GamesList.end(); it++){
    if (isBefore(g.getTitle(), it->getTitle() )){ // checks if g's title comes before the title of the game at position 'it' in the list
      GamesList.insert(it, g); // inserts the game
      return; // we are done
    }
    // check next word
  }
  // must go at end
  GamesList.push_back(g);
}

void Library::find_Genre(std::string Genre){    
  std::list<Game>::iterator it;
  // cycle through Gameslist using iterator "it"
  for( it = GamesList.begin(); it != GamesList.end(); it++){
    if( it->getGenre() == Genre ){ // check if it has the correct genre
      std::cout << it->getTitle() << std::endl;
    }
  }
}

void Library::find_Game(std::string Title){
  std::list<Game>::iterator it;
  // cycle through Gameslist using iterator "it"
  for( it = GamesList.begin(); it != GamesList.end(); it++){
    if( it->getTitle().find(Title) != std::string::npos){ // check if game contains title
      // print info about game
      std::cout << "Title: " << it->getTitle() << std::endl
	   << "Publisher: " << it->getPublisher() << std::endl
	   << "Genre: " << it->getGenre() << std::endl
	   << "Hours Played: " << it->getHoursPlayed() << std::endl
	   << "Price: " << it->getPrice() << std::endl
	   << "Year: " << it->getYear() << std::endl;
    }
  }
  
}

void Library::delete_Title(std::string Title, short Year){
  std::list<Game>::iterator it;
  // cycle through Gameslist uning iterator "it"
  for( it = GamesList.begin(); it != GamesList.end(); it++){
    if( it->getTitle() == Title && it->getYear() == Year ){ // check if the Title and Year match
      GamesList.erase(it); // remove the item from the list
      return; // we are done
    }
  }
}





/**
 * Checks if str1 comes before str2 alphabetically
 *
 * @param string str1 the first string
 * @param string str2 the string to compare to
 * @return bool 
 * 
 */
bool isBefore(std::string str1, std::string str2){
  int strLen = str1.length(); // default to length of str1

  if( strLen < str2.length()){ // switch to len of str2 if it is larger
    strLen = str2.length();
  }

  // compare charachter by charachter
  for(int i = 0; i < strLen; i++){
    if( str1[i] < str2[i] ){ // is smaller so it goes before
      return true;
    } else if( str1[i] > str2[i] ){ // is larger so goes after
      return false; 
    }
  }

  return false; // must be equal so lets just say after since it isnt before
}

