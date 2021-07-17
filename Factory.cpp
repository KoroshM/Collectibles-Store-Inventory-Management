/** @file Factory.cpp
 * @author Korosh Moosavi
 * @date 2021-03-12
 * 
 * Factory class:
 * Class used to create various subclasses of Collectible.
 * Return is dependent on string parameter containing details of object
 *   to be created.
 *
 * Assumptions:
 * All subclasses of Collectible that are to be used by the program must be
 *   manually entered into the constructor of this class.
 * Each subclass has implemented create() and create(string) methods where
 *   create(string) accepts a string containing all of the object details
 * Each subclass has a unique identifying char symbol between '@' and 'Z'
 * Input string begins with char symbol for the desired object
 */
#include "Factory.h"

/** ----------------------------- Constructor ---------------------
* Manually create new dummy subclass objects at the appropriate indeces
*   within the hash table itemFactory[].
* @pre  All subclasses have a unique char symbol
* @post Factory is able to create any subclass object using its own create()
*        given its corresponding symbol
*/
Factory::Factory()
{
   itemFactory[hash('M')] = new Coin;
   itemFactory[hash('C')] = new ComicBook;
   itemFactory[hash('S')] = new SportsCard;
}

/** ----------------------------- Destructor ---------------------
* All dummy objects in itemFactory[] are deleted and no more memory is tied
*   to this object.
* @pre   None
* @post  Memory tied to this Factory object is freed.
*/
Factory::~Factory()
{
   for (int i = 0; i < sizeof(itemFactory) / sizeof(*itemFactory); i++) {
      if (itemFactory[i] != nullptr) {
         delete itemFactory[i];
         itemFactory[i] = nullptr;
      }
   }
}

/** ----------------------------- create(string) --------------------------
* Uses hash(char) to determine which subclass to create and return. 
* Passes string along for parameter construction.
* @pre    All subclasses are properly hashed and have a create(string) method
* @post   An indicated subclass is parameter constructed
* @return A pointer to the newly created indicated subclass
*/
Collectible* Factory::create(string details) const
{
   if(itemFactory[hash(details[0])] != nullptr)
      return itemFactory[hash(details[0])]->create(details);
   
   cerr << "Unrecognized Collectible entered.\n" << endl;
   return nullptr;
}