/** @file SportsCard.cpp
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
#include "SportsCard.h"

/** ------------------------------ Default constructor ----------------------
* Data members are pre-initialized.
* @pre  None
* @post SportsCard object created with identifiable default data value.
*/
SportsCard::SportsCard()
{
   // Default construction is sufficient
}

/** ----------------------------- Parameter constructor ---------------------
* Accepts a string beginning with "S" and parses through it to create a new
*   object with given details as data members.
* @param details  String containing all details needed for a new object.
* @pre  Parameter string is pre-formatted and a single line, begins with "S"
* @post SportsCard object created with parameter data values.
*/
SportsCard::SportsCard(string details)
{
   int pos = details.find(',');
   details = details.substr(pos + 2);  // remove char code
   
   pos = details.find(',');
   stock = atoi(details.substr(0, pos).c_str()); // assign stock
   year = atoi(details.substr(pos + 2, pos + 6).c_str()); // assign year
   details = details.substr(pos + 8);  // remove stock/year
   
   pos = details.find(',');
   grade = details.substr(0, pos);     // assign grade
   details = details.substr(pos + 2);  // remove grade
   
   pos = details.find(',');
   name = details.substr(0, pos);      // assign name
   type = details.substr(pos + 2);     // assign type
}

/** ------------------------------ Destructor -------------------------------
* No special operations needed.
* @pre  None
* @post Data is deallocated after destruction.
*/
SportsCard::~SportsCard()
{
   // No additional memory is tied to this object
}

/** ----------------------------- hash() ---------------------
 * Uses descriptor to return a hash value.
 * @pre    Data members are valid and initialized.
 * @return A (hopefully) unique int value.
 */
int SportsCard::hash()
{
   int hashVal = 0;
   int len = descriptor.length();

   for (int i = 0; i < len; i++)
      hashVal += descriptor[i] % 3;

   while (hashVal > Collectible::UNIQUES)
      hashVal %= Collectible::UNIQUES;

   return hashVal;
}

/** ----------------------------- isLess(Hashable&) ---------------------
 * Main functionality for less-than operator used in SearchTree
 * @param  rhs  Other Hashable object being compared to.
 * @pre    Parameter is a SportsCard.
 * @return True if priority of this object is lower than that
 *           of rhs Hashable, false otherwise.
 */
bool SportsCard::isLess(const Hashable& rhs) const
{
   const SportsCard* temp = dynamic_cast<const SportsCard*>(&rhs);
   if (symbol != (*temp).symbol) {
      cerr << "Comparing different kinds of objects." << endl;
      return false;
   }
   if (name != (*temp).name) {
      return name < (*temp).name;
   }
   if (year != (*temp).year) {
      return year < (*temp).year;
   }
   if (type != (*temp).type) {
      return type < (*temp).type;
   }
   if (grade != (*temp).grade) {
      return grade < (*temp).grade;
   }

   // Objects are equal sorting priority
   return false;
}

/** ----------------------------- isEqual(Hashable&) ---------------------
 * Compares two Hashables to see if they are equal.
 * @param  rhs  Other Hashable object being compared to.
 * @pre    Parameter is a SportsCard.
 * @return True if this and rhs have equal data members (except for stock).
 */
bool SportsCard::isEqual(const Hashable& rhs) const
{
   if (this == &rhs) {
      return true;
   }
   const SportsCard* temp = dynamic_cast<const SportsCard*>(&rhs);
   
   bool symbolCheck = symbol == (*temp).symbol;
   bool nameCheck = name == (*temp).name;
   bool typeCheck = type == (*temp).type;
   bool gradeCheck = grade == (*temp).grade;
   bool yearCheck = year == (*temp).year;
   
   return symbolCheck && nameCheck && typeCheck && gradeCheck && yearCheck;
}

/** ----------------------------- updateStock(int) ---------------------
 * Changes the stock count of this object by the parameter amount.
 * Note that the current implementation only uses +1 and -1 as parameters.
 * @param  change Amount to change stock count by.
 * @pre    Stock is >= 0
 * @post   Stock is >= 0
 * @return True stock was changed without going below 0.
 */
bool SportsCard::updateStock(int change)
{
   if (this == nullptr) {
      cerr << "Item not found." << endl;
      return false;
   }
   
   stock += change;     // Apply change
   
   if (stock < 0) {
      cerr << "Item is out of stock, sale cancelled.\n" << endl;
      stock -= change;  // Undo if stock drops below 0
      return false;     // Return false on failure
   }
   return true;         // Return true on success
}

/** ----------------------------- print(ostream&) ---------------------
 * Main functionality of output operator<<
 * Outputs data on this object in a single, formatted line
 * @param  output Ostream object passed from operator<< overload in Hashable
 * @pre    Data members are valid and initialized.
 * @post   Information on this object is output.
 */
void SportsCard::print(ostream& output) const
{
   string sDescritpor = descriptor + ":";
   output << setw(16) << left << sDescritpor
      << setw(16) << left << name 
      << setw(12) << left << type
      << setw(12) << left << grade
      << setw(7) << left << year
      << setw(7) << left << stock;
}