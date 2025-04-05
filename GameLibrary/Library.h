/**
 * @file Library.h
 * @author alfonsowolski
 * @date 2025-04-04
 * @brief Definition of the Library class
 * 
 * Definition of the Library class
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "Game.h"
#include <list>
#include <string>

class Library{
public:


/**
 * the constuctor for the Library class
 * 
 */
  Library();


/**
 * the deconstructor for the Library class
 * 
 */
  ~Library();
  
/**
 * Inserts 'Game' object g into GamesList alphabetically
 *
 * @param Game g the game to be inserted
 * @pre g is initialized
 * @return void 
 * @post g has been inserted into GamesList alphabetically
 * 
 */
  void insert_sorted(Game g);


/**
 * Prints a list of all games that have the specified genre
 *
 * @param std::string genre the genre we are looking for
 * @return void 
 * 
 */
  void find_Genre(std::string genre);


/**
 * Prints the game with the specified name from our list
 *
 * @param std::string name the title of the game we are looking for
 * @return void 
 * 
 */
  void find_Game(std::string name);


/**
 * Removes the specified game from our list
 *
 * @param std::string Title The name of the game to remove
 * @param short Year the specific year the game was made
 * @return void 
 * 
 */
  void delete_Title(std::string Title, short Year);
  
private:
  std::list<Game> GamesList;
  int ListSize;
};

#endif
