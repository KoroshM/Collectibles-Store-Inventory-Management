/** @file CollectibleStore.cpp
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * CollectibleStore class:
 * This class is the main driver of the program.
 * There is an initial constructed state after creation then all operations
 *   carry out automatically once beginProcessing() is called.
 *   This decision was made arbitrarily for ease of use, feel free to change it
 * There is room for future development and implementations.
 *
 * Assumptions:
 * All relevant input files are in the same directory as this.
 * Input file names are given in the order: Inventory, Customer, Transactions
 */
#include "CollectibleStore.h"

/** ------------------------------ Constructor ----------------------
* Assigns file names to private members so that this object is ready to
*   begin processing on command.
* @param invFileName  File containing data on the store's inventory.
* @param custFileName File containing data on the store's customers.
* @param txFileName   File containing data on the store's transactions.
* @pre  Files are correctly formatted and names are input via calling method.
* @post On completion of construction, this object will be ready to process
*         all the data included in the files.
*/
CollectibleStore::CollectibleStore(string invFileName, string custFileName, string txFileName)
{
   for (int i = 0; i < sizeof(actions) / sizeof(*actions); i++)
         actions[i] = nullptr;

   inventoryFile = invFileName;
   customerFile = custFileName;
   transactionFile = txFileName;
}

/** ----------------------------- Destructor ---------------------
* All dummy objects in actions[] are deleted and no more memory is tied
*   to this object.
* All other memory deallocation is taken care of by other classes.
* @pre   None
* @post  Memory tied to this CollectibleStore object is freed.
*/
CollectibleStore::~CollectibleStore()
{
   for (int i = 0; i < sizeof(actions) / sizeof(*actions); i++) {
      if (actions[i] != nullptr) {
         delete actions[i];
         actions[i] = nullptr;
      }
   }
}

/** ----------------------------- beginProcessing() ---------------------
* Manually create dummy Transaction subclass objects for quick access to
*   their process().
* Place them at the appropriate indeces within the hash table actions[]
* Same structure as Factory class, but not used to create new objects.
* Then call processTransactions()
*   Optionally, in future implementations this method can be decoupled for
*     further modification/customization of operations.
*   These methods were coupled for this implementation for ease of use due
*     to the fairly simple scope of the implementation.
* @pre  Inventory and CustomerRegistry are able to properly initialize and
*         read input files.
*       All currently supported Transaction subclasses are updated into the
*         implementation for this method.
* @post CollectibleStore can safely be destroyed as all operations are
*         complete at the end of this method in this implementation.
*/
void CollectibleStore::beginProcessing()
{
   Inventory inv(inventoryFile);          // Build inventory
   CustomerRegistry cust(customerFile);   // Build customer registry

   actions[hash('B')] = new Buy;          // Build hash table of functions
   actions[hash('S')] = new Sell;
   actions[hash('D')] = new Display;
   actions[hash('C')] = new TCustomer;
   actions[hash('H')] = new History;

   processTransactions(inv, cust);        // Process transactions
}

/** ----------------------------- processTransactions() ---------------------
* Reads transactions input file and processes it line-by-line.
* Uses actions[] to call correct operations based on input file commands.
* @pre  Transactions input file is accessible and correctly formatted.
* @post All operations are carried out and outputs are output to console.
*/
void CollectibleStore::processTransactions(Inventory& inv, CustomerRegistry& cust)
{
   ifstream input(transactionFile);
   
   while (input.peek() != EOF) {
      string fileInput;
      getline(input, fileInput);
      
      if (actions[hash(fileInput[0])] == nullptr) {   
         cout << "Unrecognized Transaction entered.\n" << endl;
         continue;   // nullptr = transaction not found in actions[], skip
      }
      actions[hash(fileInput[0])]->process(inv, cust, fileInput);
   }
}