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


/**
 * Reads file at location "path" and enters data from the file into the game library
 *
 * @param string path the path to the file to read
 * @pre file at path exists and data is stored in correct format
 * @return void 
 * @post Game Library is filled from data from the file at "path"
 * 
 */
  void Load_Library(std::string path);


/**
 * Saves data in Game Library to the file at "path"
 *
 * @param string path the path to the file to write the data in Game Library to
 * @pre path of file is an existing folderpath to a file
 * @return void 
 * @post file is created or writen to with the data from Game Library in the correct format
 * 
 */
  void Save_Library(std::string path);
  
private:
  std::list<Game> GamesList;
  int ListSize;
};

#endif
