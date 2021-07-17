/** @file SportsCard.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * SportsCard class:
 * Class containing data members to identify unique sports card objects
 *   in Inventory.
 *
 * Assumptions:
 * Input will include 1 char, 2 ints, and 2 strings as data members.
 * Sorting priority is name -> year -> type -> grade
 */
#include "Collectible.h"

class SportsCard : public Collectible {
private:
   string descriptor = "Sports Card";
   static const char symbol = 'S';
   string name = "NULL_CARD_PLAYER";
   string type = "NULL_CARD_MANUFACTURER";
   string grade = "NULL_CARD_GRADE";
   int stock = -1;
   int year = 2077;

public:
   /** ------------------------------ Default constructor ----------------------
    * Data members are pre-initialized.
    * @pre  None
    * @post SportsCard object created with identifiable default data value.
    */
   SportsCard();

   /** ----------------------------- Parameter constructor ---------------------
   * Accepts a string beginning with "S" and parses through it to create a new
   *   object with given details as data members.
   * @param details  String containing all details needed for a new object.
   * @pre  Parameter string is pre-formatted and a single line, begins with "S"
   * @post SportsCard object created with parameter data values.
   */
   SportsCard(string details);

   /** ----------------------------- create() ---------------------------------
    * Creates a new default-initialized SportsCard object.
    * @pre    None
    * @post   SportsCard object created with identifiable default data value.
    * @return Pointer to default-initialized SportsCard object.
    */
   virtual SportsCard* create() const { return new SportsCard; };

   /** ----------------------------- create(string) ---------------------------
    * Data members are pre-initialized, newly created SportsCard is returned.
    * Uses parameter constructor.
    * @param details  String containing all details needed for a new object.
    * @pre  Parameter string is pre-formatted and a single line, begins with "S"
    * @post SportsCard object created with parameter data values.
    * @return  Pointer to newly created SportsCard object.
    */
   virtual SportsCard* create(string details) { return new SportsCard(details); };

   /** ------------------------------ Destructor -------------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   ~SportsCard();

   /** ----------------------------- hash() ---------------------
    * Uses descriptor to return a hash value.
    * @pre    Data members are valid and initialized.
    * @return A (hopefully) unique int value.
    */
   virtual int hash();

   /** ----------------------------- isLess(Hashable&) ---------------------
    * Main functionality for less-than operator used in SearchTree
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a SportsCard.
    * @return True if priority of this object is lower than that
    *           of rhs Hashable, false otherwise.
    */
   bool isLess(const Hashable& rhs) const;

   /** ----------------------------- isEqual(Hashable&) ---------------------
    * Compares two Hashables to see if they are equal.
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Parameter is a SportsCard.
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
