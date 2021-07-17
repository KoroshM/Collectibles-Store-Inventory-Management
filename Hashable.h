/** @file Hashable.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Hashable class:
 * Abstract class
 * Serves as parent to Collectible and Customer classes
 * Ensures necessary methods are implemented for use in CollectibleStore.
 * 
 * Assumptions:
 * Subclasses will include at least 1 string data member and will be used
 *   within Collectible store and its many data structures
 */
#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Hashable {
private:
   string name = "NULL_HASHABLE";

public:
   /** ------------------------------ Default constructor --------------------
    * Data members are pre-initialized.
    * @pre  None
    * @post Hashable object created with identifiable default data value.
    */
   Hashable() {};

   /** ------------------------------ Destructor -----------------------------
    * No special operations needed.
    * @pre  None
    * @post Data is deallocated after destruction.
    */
   virtual ~Hashable() {};

   /** ----------------------------- hash() ---------------------
   * Uses data member to return a hash value.
   * @pre    Data member is valid and initialized.
   * @return A (hopefully) unique int value.
   */
   virtual int hash() = 0;

   /** ----------------------------- operator< ---------------------
    * Provides sorting priority based on name data member.
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Data member is valid and initialized.
    * @return True if ASCII value of name in this object is lower than that
    *           of rhs Hashable, false otherwise.
    */
   bool operator<(const Hashable& rhs) const { return isLess(rhs); };;

   /** ----------------------------- isLess(Hashable) ---------------------
    * Main functionality for less-than operator to be implemented in subclasses
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Data member is valid and initialized.
    * @return True if ASCII value of name in this object is lower than that
    *           of rhs Hashable, false otherwise.
    */
   virtual bool isLess(const Hashable& rhs) const = 0;

   /** ------------------- operators == and != ---------------------
    * Compares two Hashables to see if they are equal.
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Data member is valid and initialized.
    * @return == returns isEqual, != inverts isEqual.
    */
   bool operator==(const Hashable& rhs) const { return isEqual(rhs); };
   bool operator!=(const Hashable& rhs) const { return !(isEqual(rhs)); };

   /** ----------------------------- isEqual(Hashable) ---------------------
    * Main functionality for equality operator to be implemented in subclasses
    * @param  rhs  Other Hashable object being compared to.
    * @pre    Data member is valid and initialized.
    * @return True if name is equal to rhs name.
    */
   virtual bool isEqual(const Hashable& rhs) const = 0;

   /** ----------------------------- print(ostream&) ---------------------
    * Main functionality of output operator<<
    * Outputs data on this object in a single, formatted line
    * @param  output Ostream object passed from operator<< overload below
    * @pre    Data members are valid and initialized.
    * @post   Information on this object is output.
    */
   virtual void print(ostream& output) const = 0;

   /** ------------------- operator<<(ostream&, Hashable&) -----------------
    * Uses print() method implemented in subclasses to output object details.
    * @pre  Data members are valid and initialized.
    * @post Object details are output in an appropriate way for the subclass.
    */
   friend ostream& operator<<(ostream& output, const Hashable& item)
   {
      item.print(output);
      return output;
   };
};

ostream& operator<<(ostream& output, const Hashable& item);