/** @file Buy.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Buy class:
 * Class encompassing the store function to increase the inventory count
 *   of an existing item purchased from a customer and add the transaction
 *   to that customer's log.
 *
 * Assumptions:
 * Objects used in this method are valid and initialized.
 * Transactions are for 1 item at a time.
 */
#pragma once
#include "Transaction.h"

class Buy : public Transaction {
public:
   /** ------------------------------ Default constructor ----------------------
    * No special operations needed.
    * @pre  None
    * @post Buy object created.
    */
   Buy() {};

   /** ------------------------------ Destructor -------------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   virtual ~Buy() {};

   /** --------------- process(Inventory&, CustomerRegistry&, string) ---------
   * Increases stock count for an item and adds it to the Customer's transaction log
   * @param inventory  Inventory object containing item data for the store.
   * @param registry   CustomerRegistry object containing customer data.
   * @param input      String containing transaction details.
   * @pre    Item and Customer detailed in input string both exist.
   * @return Returns false if either of the operations fail.
   */
   bool process(Inventory& inventory, CustomerRegistry& registry, string input);
};
