/**
 * @file Game.cpp
 * @author alfonsowolski
 * @date 2025-04-04
 * @brief Implementation of the Game class
 * 
 * Implementation of the Game class
 */

#include "Game.h"
#include <string>
#include <iostream>

Game::Game(){
  DebugOutput = false;
}

Game::Game(std::string Title, std::string Publisher, std::string Genre, float HoursPlayed, float Price, short Year){
  title = Title;
  publisher = Publisher;
  genre = Genre;
  hoursPlayed = HoursPlayed;
  price = Price;
  year = Year;

  if(DebugOutput){
    std::cout << " Game added:" << std::endl
	      << "Name: " << title << std::endl
	      << "Publ: " << publisher << std::endl
	      << "Genr: " << genre << std::endl
	      << "HrPl: " << hoursPlayed << std::endl
	      << "Cost: " << price << std::endl
	      << "Year: " << year << std::endl << std:: endl;
  }
}

Game::~Game(){

}

std::string Game::getTitle(){
  return title;
}

std::string Game::getPublisher(){
  return publisher;
}

std::string Game::getGenre(){
  return genre;
}

float Game::getHoursPlayed(){
  return hoursPlayed;
}

float Game::getPrice(){
  return price;
}

short Game::getYear(){
  return year;
}
