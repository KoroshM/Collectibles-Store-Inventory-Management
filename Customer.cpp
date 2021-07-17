/** @file Customer.cpp
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Customer class:
 * Stores data on an individual customer for CustomerStore operations.
 *
 * Assumptions:
 * ID from input file will be a unique 3 digit int
 */
#include "Customer.h"

/** ------------------------------ Default constructor ----------------------
* Data members are pre-initialized.
* @pre  None
* @post Customer object created with identifiable default data value.
*/
Customer::Customer()
{
   // Default construction is sufficient
}

/** ------------------------------ Destructor -------------------------------
* Transaction pointers are deleted.
* @pre  None
* @post Data is deallocated for destruction.
*/
Customer::~Customer()
{
   for (int i = 0; i < transactions.size(); i++) {
      if (transactions[i] != nullptr) {
         delete transactions[i];
         transactions[i] = nullptr;
      }
   }
}

/** ----------------------------- addTransaction() ---------------------
 * Adds an item to the transaction log for this customer.
 * @param item  Item to be added to the customer's log.
 * @param isBuy Whether item was bought from or sold to store.
 * @pre    Data members are valid and initialized.
 * @return True if item was added successfully (always true).
 */
bool Customer::addTransaction(Collectible* item, bool isBuy)
{
   transactions.push_back(item);
   txnTypes.push_back(isBuy);
   
   return true;
}

/** ----------------------------- isLess(Hashable&) ---------------------
 * Main functionality for less-than operator used in SearchTree
 * @param  rhs  Other Hashable object being compared to.
 * @pre    Parameter is a Customer.
 * @return True if priority of this object is lower than that
 *           of rhs Hashable, false otherwise.
 */
bool Customer::isLess(const Hashable& rhs) const
{
   const Customer* temp = dynamic_cast<const Customer*>(&rhs);
   
   if (name != (*temp).name)
      return name < (*temp).name;
   
   if (id != (*temp).id)
      return id < (*temp).id;
   
   // Objects are equal sorting priority
   return false;
}

/** ----------------------------- isEqual(Hashable&) ---------------------
 * Compares two Hashables to see if they are equal.
 * @param  rhs  Other Hashable object being compared to.
 * @pre    Parameter is a Customer.
 * @return True if this and rhs have equal data members (except for stock).
 */
bool Customer::isEqual(const Hashable& rhs) const
{
   const Customer* temp = dynamic_cast<const Customer*>(&rhs);
   bool nameCheck = name == (*temp).name;
   bool idCheck = id == (*temp).id;
   
   return nameCheck && idCheck;
}

/** ----------------------------- print(ostream&) ---------------------
 * Main functionality of output operator<<
 * Outputs customer name, ID, and transaction log details
 * @param  output Ostream object passed from operator<< overload in Hashable
 * @pre    Data members are valid and initialized.
 * @post   Information on this object is output.
 */
void Customer::print(ostream& output) const
{
   output << "Customer transaction log for: " 
      << setw(3) << right << setfill('0') // Leading 0s for >3 digit ID values
      << id << ", " << name 
      << left << setfill(' ') << endl;    // Undo output settings
   
   if (transactions.size() == 0)
      output << "This customer has no logged transactions.";
   
   for (int i = 0; i < transactions.size(); i++) {
      string t = txnTypes[i] ? "Bought a(n) " : "Sold a(n)   ";
      output << t << *transactions[i];
   }
   output << endl;
}