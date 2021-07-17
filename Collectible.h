/** @file Collectible.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Collectible class:
 * Abstract class
 * Serves as parent to Coin, ComicBook, and SportsCard classes.
 * Ensures there is a base class pointer for all inventory objects.
 * 
 * Assumptions:
 * Subclasses will include 1 char, 2 ints, and 2 strings as data members.
 * Input file is correctly formatted.
 */
#pragma once
#include "Hashable.h"
#include <string>

class Collectible : public Hashable {
protected:
   string descriptor = "Collectible";
   static const char symbol = '@';
   string name = "NULL_COLLECTIBLE";
   string type = "NULL_TYPE";
   string grade = "NULL_GRADE";
   int stock = -1;
   int year = 2077;

public:
   static const int UNIQUES = 29; // Next prime after 26 (letter identifiers)

   /** ------------------------------ Default constructor ----------------------
    * Data members are pre-initialized.
    * @pre  None
    * @post Collectible object created with identifiable default data value.
    */
   Collectible() {};

   /** ----------------------------- create() ---------------------------------
    * Creates a new default-initialized Collectible object.
    * @pre    None
    * @post   Collectible object created with identifiable default data value.
    * @return Pointer to default-initialized Collectible object.
    */
   virtual Collectible* create() const = 0;

   /** ----------------------------- create(string) ---------------------------
    * Data members are pre-initialized, newly created Collectible is returned.
    * Uses parameter constructor.
    * @param details  String containing all details needed for a new object.
    * @pre  Parameter string is pre-formatted and a single line, begins with "@"
    * @post Collectible object created with parameter data values.
    * @return  Pointer to newly created Collectible object.
    */
   virtual Collectible* create(string details) = 0;

   /** ------------------------------ Destructor -------------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   virtual ~Collectible() {};

   /** ----------------------------- hash() ---------------------
    * Uses descriptor to return a hash value.
    * Hash priority should order subclasses like so:
    *    Coin -> Comic Book -> Sports Card
    * @pre    Data members are valid and initialized.
    * @return A (hopefully) unique int value.
    */
   virtual int hash() = 0;

   /** ----------------------------- isLess(Hashable&) ---------------------
    * Main functionality for less-than operator used in SearchTree
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a Coin.
    * @return True if priority of this object is lower than that
    *           of rhs Hashable, false otherwise.
    */
   virtual bool isLess(const Hashable& rhs) const = 0;

   /** ----------------------------- isEqual(Hashable&) ---------------------
    * Compares two Hashables to see if they are equal.
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a Collectible.
    * @return True if this and rhs have equal data members (except for stock).
    */
   virtual bool isEqual(const Hashable& rhs) const = 0;;

   /** ----------------------------- updateStock(int) ---------------------
    * Changes the stock count of this object by the parameter amount.
    * Note that the current implementation only uses +1 and -1 as parameters.
    * @param  change Amount to change stock count by.
    * @pre    Stock is >= 0
    * @post   Stock is >= 0
    * @return True stock was changed without going below 0.
    */
   virtual bool updateStock(int change) = 0;

   /** ----------------------------- print(ostream&) ---------------------
    * Main functionality of output operator<<
    * Outputs data on this object in a single, formatted line
    * @param  output Ostream object passed from operator<< overload in Hashable
    * @pre    Data members are valid and initialized.
    * @post   Information on this object is output.
    */
   virtual void print(ostream& output) const = 0;
};