/** @file Customer.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Customer class:
 * Stores data on an individual customer for CustomerStore operations.
 *
 * Assumptions:
 * ID from input file will be a unique 3 digit int
 */
#pragma once
#include "Hashable.h"
#include "Collectible.h"
#include <vector>

using namespace std;

class Customer : public Hashable {
private:
   string name = "NULL_CUSTOMER";
   int id = 000;
   vector<Collectible*> transactions;
   vector<bool> txnTypes; // Buy = 1 vs Sell = 0

public:
   /** ------------------------------ Default constructor --------------------
    * Data members are pre-initialized.
    * @pre  None
    * @post Customer object created with identifiable default data value.
    */
   Customer();

   /** ----------------------------- Parameter constructor -------------------
    * Data members are pre-initialized.
    * @param nameIn Name to use when constructed.
    * @param idIn   ID to use when constructed.
    * @pre  None
    * @post Customer object created with identifiable default data value.
    */
   Customer(string nameIn, int idIn) : name(nameIn), id(idIn) {};

   /** ------------------------------ Destructor -------------------------------
   * Transaction pointers are deleted.
   * @pre  None
   * @post Data is deallocated for destruction.
   */
   virtual ~Customer();

   /** ----------------------------- hash() ---------------------
    * Uses data members to return a hash value.
    * @pre    Data members are valid and initialized.
    * @return A (hopefully) unique int value.
    */
   virtual int hash() { return id; };

   /** ----------------------------- addTransaction() ---------------------
    * Adds an item to the transaction log for this customer.
    * @param item  Item to be added to the customer's log.
    * @param isBuy Whether item was bought from or sold to store.
    * @pre    Data members are valid and initialized.
    * @return True if item was added successfully (always true).
    */
   bool addTransaction(Collectible* item, bool isBuy);

   /** ----------------------------- isLess(Hashable&) ---------------------
    * Main functionality for less-than operator used in SearchTree
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a Customer.
    * @return True if priority of this object is lower than that
    *           of rhs Hashable, false otherwise.
    */
   bool isLess(const Hashable& rhs) const;

   /** ----------------------------- isEqual(Hashable&) ---------------------
    * Compares two Hashables to see if they are equal.
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a Customer.
    * @return True if this and rhs have equal data members (except for stock).
    */
   bool isEqual(const Hashable& rhs) const;

   /** ----------------------------- print(ostream&) ---------------------
    * Main functionality of output operator<<
    * Outputs customer name, ID, and transaction log details
    * @param  output Ostream object passed from operator<< overload in Hashable
    * @pre    Data members are valid and initialized.
    * @post   Information on this object is output.
    */
   void print(ostream& output) const;
};