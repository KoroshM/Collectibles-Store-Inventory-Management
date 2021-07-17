/** @file SearchTree.cpp
 * @author Korosh Moosavi
 * @date 2021-03-12
 * 
 * SearchTree class:
 * This header file contains all the method headers relating to creating and
 *  managing a binary search tree storing Hashable objects.
 * The node struct is implemented within the .cpp file.
 * One-line methods have been defined here in the .h file.
 *
 * Assumptions:
 * Hashable has operator== and operator< overloaded
 */
#pragma once
#include <string>
#include <iostream>
#include "Hashable.h"

using namespace std;

class SearchTree
{
private:
   /** ------------------------ ItemNode struct --------------------------
    * Implementation is in the .cpp file
    * Node storing a Hashable item
    * Left pointer points to Hashables with lower priority
    * Right pointer points to Hashables with higher priority
    *
    * Default and Hashable constructors included for ease of use
    * Destructor recursively deletes all linked descendant nodes
    * @param itemIn Hashable object to be stored in a node
    */
   struct ItemNode;

   ItemNode* root;

   /** ------------------- insert(Hashable*, ItemNode*&) ---------------------
    * Adds a new Hashable to BST
    * Recursively searches then inserts
    * @param key Hashable object being added to the BST
    * @param subRoot Node to start search at, for insertion
    * @pre    None
    * @post   Hashable key exists in the tree
    * @return Returns true if new insertion is made, false if key already exists
    */
   bool insert(Hashable* key, ItemNode*& subRoot);

   /** ------------------------ search(Hashable*) --------------------------
    * Searches BST beginning at root for node containing key
    * @param key Hashable item to search for
    * @pre    None
    * @post   None
    * @return Returns node containing key if found, nullptr if not found
    */
   SearchTree::ItemNode* search(const Hashable* key) const;

   /** ------------------------ operator<< --------------------------
    * Recursively prints to a list of each Hashable in the BST per line (inorder)
    * @param output  Ostream accepted and returned to allow chaining outputs
    * @param subRoot Node to print subtree at
    * @pre  None
    * @post Contents of tree are output
    */
   friend ostream& operator<<(ostream& output, const ItemNode* subRoot);

public:
   // ------------------------------ Constructor -----------------------------
   SearchTree() : root(nullptr) {};

   /** ------------------------ Destructor --------------------------
    * Deletes the root node of the tree, which will recursively delete
    *   all descendant nodes using its own destructor
    */
   ~SearchTree();

   /** --------------------------- isEmpty() -------------------------
    * Check if the tree is storing any data.
    * @pre  None
    * @post None
    * @return True if root is unoccupied, false if not
    */
   bool isEmpty() { return root == nullptr; };

   /** --------------------------- insert(Hashable*) -------------------------
    * Helper method for insert(Hashable*, ItemNode*&) without exposing root
    * @param key Item being added to the BST
    * @pre    root is not nullptr
    * @post   key has been added to the tree in its proper place
    * @return True if insert was successful, false if not
    */
   bool insert(Hashable* key) { return insert(key, root); };

   /** ------------------------ retrieve(Hashable*) --------------------------
    * Finds node containing key and returns that Hashable object
    * @param key Hashable item to search for
    * @pre    None
    * @post   None
    * @return Returns key if found, nullptr if not found
    */
   Hashable* retrieve(const Hashable* key) const;

   /** ------------------------ operator<< Helper --------------------------
    * Helper method for calling operator<<(ItemNode*) without exposing root
    */
   friend ostream& operator<<(ostream& output, const SearchTree& tree);
};

/** ------------------------ operator<< Helper --------------------------
 * Helper method for calling operator<<(ItemNode*) without exposing root
 */
ostream& operator<<(ostream&, const SearchTree&);
