/** @file TCustomer.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * TCustomer class:
 * Class encompassing the store function to output the purchase history
 *   of a particular Customer object.
 * Named TCustomer to distinguish from Customer class carrying customer data.
 * 
 * Assumptions:
 * Objects used in this method are valid and initialized.
 */
#include "Transaction.h"

class TCustomer : public Transaction {
public:
   /** ------------------------------ Default constructor ----------------------
    * No special operations needed.
    * @pre  None
    * @post Buy object created.
    */
   TCustomer() {};

   /** ------------------------------ Destructor -------------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   virtual ~TCustomer() {};

   /** ---------------- process(Inventory&, CustomerRegistry&, string) ---------
    * Outputs purchase history recorded in a Customer log.
    * @param inventory  Inventory object containing item data for the store
    * @param registry   CustomerRegistry object containing customer data.
    * @param input      String containing transaction details.
    * @pre    Registry contains Customer detailed in input string
    * @return Returns true if Customer was found, false if not.
    */
   bool process(Inventory& inventory, CustomerRegistry& registry, string input)
   { return registry.outputLog(stoi(input.substr(3, 6))); };
};
