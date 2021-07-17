/** @file Buy.cpp
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
#include "Buy.h"

/** --------------- process(Inventory&, CustomerRegistry&, string) -----------
* Increases stock count for an item and adds it to the Customer's transaction log
* @param inventory  Inventory object containing item data for the store.
* @param registry   CustomerRegistry object containing customer data.
* @param input      String containing transaction details.
* @pre    Item and Customer detailed in input string both exist.
* @return Returns false if either of the operations fail.
*/
bool Buy::process(Inventory& inventory, CustomerRegistry& registry, string input)
{
   input.insert(11, "1, ");// This implementation only supports single-item transactions
   Factory fact;           // The insert specifies a count of 1 for the item being bought
   Collectible* temp = fact.create(input.substr(8));
   
   if (temp != nullptr && inventory.updateInventory(temp, 1)){
      if (registry.updateLog(temp, stoi(input.substr(3, 6)), 1)) // Update customer log
         return true;      // Return success
      
      else
         inventory.updateInventory(temp, -1); // Undo change if customer log is not updated
   }
   if (temp != nullptr)
      delete temp;
   return false;           // Return failure
}
