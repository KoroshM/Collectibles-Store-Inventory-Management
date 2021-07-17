/** @file History.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * History class:
 * Class encompassing the store function to output the purchase history
 *   of all Customer objects within CustomerRegistry.
 * 
 * 
 * Assumptions:
 * Objects used in this method are valid and initialized.
 */
#include "Transaction.h"

class History : public Transaction {
public:
   /** ------------------------------ Default constructor ----------------------
    * No special operations needed.
    * @pre  None
    * @post Buy object created.
    */
   History() {};

   /** ------------------------------ Destructor -------------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   virtual ~History() {};

   /** ---------------- process(Inventory&, CustomerRegistry&, string) ---------
   * Uses outputAll() method within CustomerRegistry to output all Customer
   *   transaction data.
   * @param inventory  Not used, remnant of parent class parameter.
   * @param registry   CustomerRegistry object containing customer data.
   * @param input      String containing any additional transaction details.
   * @pre    None, but will not output anything if registry is empty.
   * @return True if all Customers were output, false if Customer tree isn't initialized
   */
   bool process(Inventory& inventory, CustomerRegistry& registry, string input)
   { return registry.outputAll(); };
};
