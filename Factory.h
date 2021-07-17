/** @file Factory.h
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
#pragma once
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"

class Factory {
private:
   Collectible* itemFactory[Collectible::UNIQUES] = { nullptr };

   /** ----------------------------- hash(char) ---------------------
   * Items are identified by a single capital letter
   * The base Collectible class is identified by the @ symbol, but is not used
   *   This comes right before 'A' on the ASCII table
   * As a result, the first element of itemFactory[] is left empty 
   *   in this implementation due to Collectible being an abstract class
   * @pre    c is between @ and Z (64 and 90)
   * @return A unique int value between 0 and 26 inclusive
   */
   int hash(char c) const { return c - '@'; };

public:
   /** ----------------------------- Constructor ---------------------
   * Manually create new dummy subclass objects at the appropriate indeces
   *   within the hash table itemFactory[].
   * @pre  All subclasses have a unique char symbol
   * @post Factory is able to create any subclass object using its own create()
   *        given its corresponding symbol
   */
   Factory();

   /** ----------------------------- Destructor ---------------------
   * All dummy objects in itemFactory[] are deleted and no more memory is tied
   *   to this object.
   * @pre   None
   * @post  Memory tied to this Factory object is freed.
   */
   ~Factory();

   /** ----------------------------- create(string) --------------------------
   * Uses hash(char) to determine which subclass to create and return.
   * Passes string along for parameter construction.
   * @pre    All subclasses are properly hashed and have create(string) method
   * @post   An indicated subclass is parameter constructed
   * @return A pointer to the newly created indicated subclass
   */
   Collectible* create(string details) const;
};