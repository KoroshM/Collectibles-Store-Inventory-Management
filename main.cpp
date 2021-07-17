/** @file main.cpp
 * @author Korosh Moosavi
 * @date 2021-03-12
 * 
 * Executes the CollectibleStore class by reading data from:
 * "inventory.txt" - Collectible inventory data
 *                   Format: S, 9, 1989, Near Mint, Ken Griffey Jr., Upper Deck
 * "customers.txt" - Registered customer data
 *                   Format: 001, Michael Jordan
 * "commands.txt"  - Transactions and operations to be processed
 *                   Format: S, 001, S, 1989, Near Mint, Ken Griffey Jr., Upper Deck
 *
 * Preconditions:   Each of the input files must strictly follow their
 *                  pre-established formats.
 * Postconditions:  All recognized items and customers will be tracked as the
 *                  as the various operations are performed on these objects.
 */
#include "CollectibleStore.h"
using namespace std;

int main() {
   CollectibleStore store1("inventory.txt", "customers.txt", "commands.txt");
   store1.beginProcessing();

   return 0;
}