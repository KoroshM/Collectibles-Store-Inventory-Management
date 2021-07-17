/** @file Display.cpp
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Display class:
 * Class encompassing the store function to output details of the store's
 *   current inventory state.
 *
 * Assumptions:
 * Objects used in this method are valid and initialized.
 */
#include "Transaction.h"

class Display : public Transaction {
public:
   /** ------------------------------ Default constructor ----------------------
    * No special operations needed.
    * @pre  None
    * @post Display object created.
    */
   Display() {};

   /** ------------------------------ Destructor -------------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   virtual ~Display() {};

   /** -------------- process(Inventory&, CustomerRegistry&, string) ---------
   * Uses outputAll() method within Inventory to output details on all the
   *   Collectible objects it has stored.
   * @param inventory  Inventory storing data on the store's current items.
   * @param registry   Not used, remnant of parent class parameter.
   * @param input      String containing any additional transaction details.
   * @pre    None, but will not output anything if inventory is empty.
   * @return Returns true once output is complete.
   */
   bool process(Inventory& inventory, CustomerRegistry& registry, string input);
};
