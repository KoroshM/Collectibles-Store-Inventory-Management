/** @file Inventory.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Inventory class:
 * Specialized HashTable class used to track inventory of items in
 *   CollectibleStore.
 * Reads from a file containing inventory data to build hash tables
 *   of various collectibles sold in the store.
 *
 * Assumptions:
 * Only Collectible objects and its subclasses will be handled by this class.
 */
#pragma once
#include "Factory.h"
#include "SearchTree.h "
#include <fstream>

class Inventory {
private:
   SearchTree* items[Collectible::UNIQUES];

public:
   /** ------------------------------ Constructor ----------------------
   * Uses Factory to construct subclasses of Collectible as needed based on
   *   data in the input file.
   * Adds items to corresponding SearchTrees for easy sorting.
   * @param fileName Name of the input file containing data on store items.
   * @pre  File is pre-formatted and in the same directory.
   * @post All items in the input file are parsed and created (when able) then
   *         added to its corresponding SearchTree within the hash table items[]
   */
   Inventory(string fileName);

   /** ------------------------------ Destructor -------------------------------
    * Every object in the table is deleted from memory.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   virtual ~Inventory();

   /** ----------------------------- updateInventory() ---------------------
   * Changes the stock count of an item by the amount indicated.
   * The current implementation only uses +1 and -1 for change.
   * @param item   Collectible object to update.
   * @param change Amount to change the stock count by. Note that this is a
   *                 change amount, not an absolute amount.
   * @pre          Parameter item already exists in Inventory.
   * @post         Stock count of item is increased by amount indicated
   *                 (decreased if negative).
   * @return       Returns true on successful execution, false on failure.
   */
   bool updateInventory(Collectible* item, int change);

   /** ----------------------------- outputAll() ---------------------
   * Traverses each tree in-order and outputs each item.
   * Tree priority is Coin -> Comic Book -> Sports Card
   * @pre      None.
   * @post     Details on each item stored is output in order, including items
   *             with zero stock count.
   * @return   True after all nodes of each tree have been visited.
   */
   bool outputAll();
};
