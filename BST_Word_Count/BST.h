/**
 * @file BST.h
 * @author alfonsowolski
 * @date 2025-04-10
 * @brief Definition of the BST object
 * 
 * Definition of the BST object
 */


#ifndef BST_H
#define BST_H



class BST{
 public:

/**
 * Constuctor for the BST object
 *
 * @post BST Object is created
 * 
 */
  BST();
  

/**
 * Deconstructor for BST
 * 
 * @post Node at start is deconstucted (and by Node's deconstuctor every child Node aswell)
 * 
 */
  ~BST();


/**
 * Set count of Node with specified key to 'count'
 *
 * @param std::string key the Node we want to change the count for
 * @param int count the desired value we want to set the Node's cout to 
 * @pre the key pairs to a node
 * @return void 
 * @post the Node with the specified key has its data value changed to 'count'
 * 
 */
  void set(std::string key, int count);


/**
 * returns the count of the specified Node
 *
 * @param std::string key the Node we want to find the value of
 * @pre the key pairs to a Node in our list
 * @return int the data value of the Node
 * 
 */
  int find(std::string key);


/**
 * Prints every node in alphabetical order by key. prints as: (key, data)
 *
 * @return void
 * 
 */
  void print();


/**
 * Prints the leftmost Node in tree
 *
 * @return void  
 * 
 */
  void min();


/**
 * Prints the rightmost Node in tree
 *
 * @return void 
 * 
 */
  void max();


/**
 * Saves tree into a file 
 *
 * @param std::string path the file to save to
 * @return void 
 * 
 */
  void save_file(std::string path);


/**
 * Deletes the Node with the specified key
 *
 * @param std::string key the Node to remove from the tree
 * @return void 
 * 
 */
  void delete(std::string key);
  
  
 private:
  Node* start
};


#endef
