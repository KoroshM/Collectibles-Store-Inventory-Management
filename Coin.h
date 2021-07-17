/** @file Coin.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Coin class:
 * Class containing data members to identify unique Coin objects in Inventory.
 * Although the grade of a coin can be represented as an int, it will be
 *   stored as a string for this implementation.
 *
 * Assumptions:
 * Input will be 3 ints, and 1 string (split into 2) for data members.
 * Sorting priority is type -> year -> grade
 */
#include "Collectible.h"

class Coin : public Collectible {
private:
   string descriptor = "Coin";
   static const char symbol = 'M';
   string name = "NULL_COIN_NAME";
   string type = "NULL_COIN_TYPE";
   string grade = "NULL_COIN_GRADE";
   int stock = -1;
   int year = 2077;

public:
   /** ------------------------------ Default constructor ----------------------
    * Data members are pre-initialized.
    * @pre  None
    * @post Coin object created with identifiable default data values.
    */
   Coin();

   /** ----------------------------- Parameter constructor ---------------------
    * Accepts a string beginning with "M" and parses through it to create a new
    *   object with given details as data members.
    * @param details  String containing all details needed for a new object.
    * @pre  Parameter string is pre-formatted and a single line, begins with "M"
    * @post Coin object created with parameter data values.
    */
   Coin(string details);

   /** ----------------------------- create() ---------------------------------
    * Creates a new default-initialized Coin object.
    * @pre    None
    * @post   Coin object created with identifiable default data value.
    * @return Pointer to default-initialized Coin object.
    */
   virtual Coin* create() const { return new Coin; };

   /** ----------------------------- create(string) ---------------------------
    * Data members are pre-initialized, newly created Coin is returned.
    * Uses parameter constructor.
    * @param details  String containing all details needed for a new object.
    * @pre  Parameter string is pre-formatted and a single line, begins with "M"
    * @post Coin object created with parameter data values.
    * @return  Pointer to newly created Coin object.
    */
   virtual Coin* create(string details) { return new Coin(details); };

   /** ------------------------------ Destructor -------------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   ~Coin();

   /** ----------------------------- hash() ---------------------
    * Uses descriptor to return a hash value.
    * @pre    Data members are valid and initialized.
    * @return A (hopefully) unique int value.
    */
   virtual int hash();

   /** ----------------------------- isLess(Hashable&) ---------------------
    * Main functionality for less-than operator used in SearchTree
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a Coin.
    * @return True if priority of this object is lower than that
    *           of rhs Hashable, false otherwise.
    */
   bool isLess(const Hashable& rhs) const;

   /** ----------------------------- isEqual(Hashable&) ---------------------
    * Compares two Hashables to see if they are equal.
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a Coin.
    * @return True if this and rhs have equal data members (except for stock).
    */
   bool isEqual(const Hashable& rhs) const;

   /** ----------------------------- updateStock(int) ---------------------
    * Changes the stock count of this object by the parameter amount.
    * Note that the current implementation only uses +1 and -1 as parameters.
    * @param  change Amount to change stock count by.
    * @pre    Stock is >= 0
    * @post   Stock is >= 0
    * @return True stock was changed without going below 0.
    */
   bool updateStock(int change);

   /** ----------------------------- print(ostream&) ---------------------
    * Main functionality of output operator<<
    * Outputs data on this object in a single, formatted line
    * @param  output Ostream object passed from operator<< overload in Hashable
    * @pre    Data members are valid and initialized.
    * @post   Information on this object is output.
    */
   virtual void print(ostream& output) const;
};
