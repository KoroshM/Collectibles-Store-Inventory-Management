/** @file CustomerRegistry.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * CustomerRegistry class:
 * Used to manage registered customers and their interactions with the store
 *   and its inventory.
 * 
 * Assumptions:
 * Only Customer objects and its subclasses will be hashed.
 * Input file includes IDs as 3-digit numbers with leading 0s if necessary.
 * Name will be saved and sorted as-is, including any extra spaces or characters.
 */
#pragma once
#include "Customer.h"
#include "Collectible.h"
#include "SearchTree.h"
#include <fstream>

class CustomerRegistry {
private:
   Customer* registry[1000];

   SearchTree* customers;

public:
   /** ------------------------------ Constructor ----------------------
    * Parses input file to create Customer objects and insert their pointers into
    *   both the SearchTree 'customers' and hash table 'registry'
    * @param fileName Name of the input file containing data on store Customers.
    * @pre  Pre-formatted and pre-determined file is in the same directory.
    * @post Only one instance of each Customer is create with pointers in both data
    *         members of this object.
    */
   CustomerRegistry(string fileName);

   /** ------------------------------ Destructor -------------------------------
    * SearchTree destructor is used to free memory.
    * @pre  None
    * @post Data is deallocated for destruction.
    */
   virtual ~CustomerRegistry();

   /** --------------------- updateLog(Collectible*, int, bool) -----------------
   * Adds parameter item to transaction vector in Customer object corresponding
   *   to the parameter id.
   * Adds bool value to txnType vector indicating whether the store bought from
   *   or sold to the customer.
   * @param item  Collectible object to add to Customer's transaction log.
   * @param id    Customer ID whose log to add this item to.
   * @param isBuy Whether the transaction is a buy or sell
   * @pre        Customer and item both exist in their respective tables.
   *             Calling method calls Inventory.updateInventory(item, -1) first
   *               to ensure there is enough stock.
   * @post       Item has been added to the transaction log of the Customer.
   *             Transaction type (buy/sell) has also been recorded in Customer.
   * @return     Returns true on successful execution, false on failure.
   */
   bool updateLog(Collectible* item, int id, bool isBuy);

   /** ----------------------------- outputLog(int) ---------------------
    * Finds Customer object with given ID and outputs items stored in its
    *   transactions vector as well as whether it was bought or sold.
    * In this implementation all customer transactions will be
    *   of quantity 1.
    * @param id Desired customer to print transaction log for.
    * @pre      Customer with given ID exists and is initialized.
    * @post     Items stored in transactions vector are output.
    * @return   True if desired Customer was found, false if not.
    */
   bool outputLog(int id);

   /** ----------------------------- outputAll() ---------------------
    * Calls the customers SearchTree's output operator to in-order traverse
    *   through each Customer and call their output operators.
    * @pre      None, tree will indicate if it is empty.
    * @post     Items stored in transactions vector of each customer
    *             are output, customers are listed in alphabetical order.
    * @return   True if all Customers were output, false if there is no tree.
    */
   bool outputAll();
};
