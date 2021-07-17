/** @file SearchTree.cpp
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * SearchTree class:
 * This cpp file contains all the methods and functions relating to creating and
 *  managing a binary search tree storing Hashable objects.
 * The node struct is implemented within this file.
 * 
 * Assumptions:
 * Hashable has operator== and operator< overloaded
 */
#include "SearchTree.h"

 /** ------------------------ ItemNode struct --------------------------
 * Node storing a Hashable item
 * Left pointer points to Hashables with lower priority
 * Right pointer points to Hashables with higher priority
 *
 * Default and Hashable constructors included for ease of use
 * Destructor recursively deletes all linked descendant nodes
 * @param itemIn Hashable object to be stored in a node
 */
struct SearchTree::ItemNode
{
   Hashable* item;

   ItemNode* left;
   ItemNode* right;

   ItemNode() : item(nullptr), left(nullptr), right(nullptr) {};
   ItemNode(Hashable* itemIn) : item(itemIn), left(nullptr), right(nullptr) {};
   
   ~ItemNode() {
      if (left != nullptr)
         delete left;
      if (right != nullptr)
         delete right;
      if (item != nullptr)
         delete item;
      
      left = nullptr;
      right = nullptr;
      item = nullptr;
   }
}; // end ItemNode

/** ------------------------ Destructor --------------------------
 * Deletes the root node of the tree, which will recursively delete
 *   all descendant nodes using its own destructor
 */
SearchTree::~SearchTree()
{
   if (root != nullptr) {  // Prevent segmentation fault on empty tree delete
      delete root;
      root = nullptr;
   }
} // end Destructor

/** ------------------- insert(Hashable*, ItemNode*&) ---------------------
 * Adds a new Hashable to BST
 * Recursively searches then inserts
 * @param key Hashable object being added to the BST
 * @param subRoot Node to start search at, for insertion
 * @pre    None
 * @post   Hashable key exists in the tree
 * @return Returns true if new insertion is made, false if key already exists
 */
bool SearchTree::insert(Hashable* key, ItemNode*& subRoot)
{
   if (subRoot == nullptr) {                 // No root for BST
      subRoot = new ItemNode(key);
      return true;

   } else if (*key == *subRoot->item) {      // Key found
      return false;

   } else if (*key < *subRoot->item) {       // Search lower priority nodes
      if (subRoot->left == nullptr) {        // Empty node where key should be
         subRoot->left = new ItemNode(key);
         return true;

      } else {
         return insert(key, subRoot->left);  // Continue search
      }

   } else {                                  // Search higher priority nodes
      if (subRoot->right == nullptr) {       // Empty node where key should be
         subRoot->right = new ItemNode(key);
         return true;

      } else {
         return insert(key, subRoot->right); // Continue search
      }
   }
} // end insert

/** ------------------------ retrieve(Hashable*) --------------------------
 * Finds node containing key and returns that Hashable object
 * @param key Hashable item to search for
 * @pre    None
 * @post   None
 * @return Returns key if found, nullptr if not found
 */
Hashable* SearchTree::retrieve(const Hashable* key) const
{
   if (root == nullptr) {     // No root for BST
      return nullptr;
   }

   ItemNode* cur = search(key);

   if (cur == nullptr) {      // Key not found
      return nullptr;
   }

   return cur->item;
} // end retrieve

/** ------------------------ search(Hashable*) --------------------------
 * Searches BST beginning at root for node containing key
 * @param key Hashable item to search for
 * @pre    None
 * @post   None
 * @return Returns node containing key if found, nullptr if not found
 */
SearchTree::ItemNode* SearchTree::search(const Hashable* key) const
{
   ItemNode* cur = root;      // Start search at root of BST

   while (cur != nullptr && *cur->item != *key) {  // Find key
      if (*key < *cur->item) {
         cur = cur->left;
      } else {
         cur = cur->right;
      }
   }

   return cur;                // Return results (nullptr if not found)
}

/** ------------------------ operator<< Helper --------------------------
 * Helper method for calling operator<<(ItemNode*) without exposing root
 */
ostream& operator<<(ostream& output, const SearchTree& tree)
{
   if (tree.root != nullptr) {   // Check for empty tree
      output << tree.root;       // Output if it contains data

   } else {
      output << "Tree is empty.";// Output message indicating empty tree
   }
   return output;
} // end operator<<() overload helper

/** ------------------------ operator<< --------------------------
 * Recursively prints to a list of each Hashable in the BST per line (inorder)
 * @param output  Ostream accepted and returned to allow chaining outputs
 * @param subRoot Node to print subtree at
 * @pre  None
 * @post Contents of tree are output
 */
ostream& operator<<(ostream& output, const SearchTree::ItemNode* subRoot)
{ // Inorder
   if (subRoot->left != nullptr) {
      output << subRoot->left;         // Print left branch
   }

   output << *subRoot->item << endl;   //Print node

   if (subRoot->right != nullptr) {
      output << subRoot->right;        // Print right branch
   }

   return output;
} //  end operator<< overload