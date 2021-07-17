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
#include "Display.h"

/** ----------------------- process(Inventory&, CustomerRegistry&) ---------
* Uses outputAll() method within Inventory to output details on all the 
*   Collectible objects it has stored.
* @param inventory  Inventory storing data on the store's current items.
* @param registry   Not used, remnant of parent class parameter.
* @param input      String containing any additional transaction details.
* @pre    None, but will not output anything if inventory is empty.
* @return Returns true once output is complete.
*/
bool Display::process(Inventory& inventory, CustomerRegistry& registry, string input)
{
   cout << "Current inventory: " << endl;
   return inventory.outputAll();
}
