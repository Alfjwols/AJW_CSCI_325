/**
 * @file Node.h
 * @author alfonsowolski
 * @date 2025-04-10
 * @brief Definition of the Node class
 * 
 * A Node class that contains a string and an int
 */

#ifndef Node_H
#define Node_H

#include <fstream>

class Node{
 public:
  

/**
 * Constuctor for Node
 *
 * @param std::string Key value to set as key for node
 * @post creates new node with "key" as it's internal key, data = 0
 * 
 */
  Node(std::string Key);


/**
 * Deconstuctor for Node
 *
 * @pre 
 * @post if left and/or right point to a Node, that Node is deconstructed
 * 
 */
  ~Node();
  

/**
 * Sets the value of data to a specified number
 *
 * @param int num the number to set data to
 * @return void 
 * 
 */
  void setData(int num);



/**
 * Returns the value of data
 *
 * @pre data has a value
 * @return int the value of data
 * 
 */
  int getData();

  
/**
 * Adds an amount to the data count
 *
 * @param int num the number to add to data
 * @return void 
 * 
 */
  void add(int num);


/**
 * Increases the data count by one
 *
 * @pre data has a value
 * @return Node& 
 * @post data is increased by 1
 * 
 */
  Node& operator++();



/**
 * Sets left to point to a Node object at n
 *
 * @param Node* n the pointer to a Node object that we want inplace of left
 * @pre n points to a valid Node object
 * @return void 
 * @post left points to where n points
 * 
 */
  void setLeft(Node* n);


/**
 * Sets right to point to a Node object at n
 *
 * @param Node* n  the pointer to a Node object that we want inplace of right
 * @pre n points to a valid Node object
 * @return void 
 * @post right points to where n points
 * 
 */
  void setRight(Node* n);



/**
 * Returns the left Node
 *
 * @return Node* the Node at left or nullptr if there is no Node
 * 
 */
  Node* getLeft();


/**
 * Returns the right Node
 *
 * @return Node* the Node at right or nullptr if there is no Node
 * 
 */
  Node* getRight();


/**
 * Returns the key value of the Node
 *
 * @pre key value is set
 * @return std::string the key
 * 
 */
  std::string getKey();


/**
 * Recursive function to find proper placement for Node n
 *
 * @param Node* n the node to place
 * @return void 
 * @post n is placed in right or left or function is recursively called on right or left
 * 
 */
  void placeNode(Node* n);

  

/**
 * Recursive function for searching for a Node based on key
 *
 * @param std::string Key the Node to search for
 * @return Node* a pointer to the Node or nullptr if not found 
 * 
 */
  Node* findNode(std::string Key);


/**
 * Prints out the Node in the format: (key, data)
 *
 * @return void
 * 
 */
  void print();



/**
 * Recursive functions that prints all children Nodes (left and right) in the format: (key, data)
 *
 * @return void
 * 
 */
  void printAll();


/**
 * Recrusive function that saves all children Nodes to a file in the format: key data
 *
 * @param fstream& file reference to the file stream being saved to
 * @return void 
 * @post Node is added to the save file in the format: key data
 * 
 */
  void save(std::fstream& file);


/**
 * Returns a pointer to the parent Node
 *
 * @return Node* the parent Node
 * 
 */
  Node* getParent();


/**
 * Set the parent of the Node
 *
 * @param Node* n the node to set as parent
 * @return void 
 * @post the Parent Node is set to n
 * 
 */
  void setParent(Node* n);
  
 private:
  Node* left, right, parent;
  std::string key;
  int data;
};

#endef
