/**
 * @file Game.h
 * @author alfonsowolski
 * @date 2025-04-04
 * @brief Definition of the Game object
 * 
 * Definition of the Game object
 */

#ifndef GAME_H
#define GAME_H

#include <string>

class Game{
 public:


/**
 * constuctor for the Game class
 *
 */
  Game();


/**
 * Constructor for a Game Object that includes population it with data
 *
 * @param std::string Title The game title
 * @param std::string Publisher the publisher of the game
 * @param std::string Genre the genre of the game
 * @param float HoursPlayed the hours loged on the game
 * @param float Price the cost of the game
 * @param short Year the release year of the game
 * @post a 'Game' object with Title, Publisher, Genre, HoursPlayed, Price, and Year filled out
 * 
 */
  Game(std::string Title, std::string Publisher, std::string Genre, float HoursPlayed, float Price, short Year);

/**
 * deconstructor for the Game class
 *
 */
  ~Game();


/**
 * Returns the Title of the game
 *
 * @return std::string the game's Title
 * 
 */
  std::string getTitle();
  

/**
 * Returns the Publisher of the game
 *
 * @return std::string The game's Publisher 
 * 
 */
  std::string getPublisher();
  

/**
 * Returns game's Genre 
 *
 * @return std::string the game's Genre
 * 
 */
  std::string getGenre();
  

/**
 * Returns hours played on game
 *
 * @return float the hours played on game
 * 
 */
  float getHoursPlayed();
  

/**
 * Returns the cost of the Game
 *
 * @return float the cost of the game
 * 
 */
  float getPrice();
  

/**
 * Returns the Year the game was released
 *
 * @return short the Year the game was released
 * 
 */
  short getYear();
  
 private:
  std::string title;
  std::string publisher;
  std::string genre;
  float hoursPlayed;
  float price;
  short year;
};

#endif
