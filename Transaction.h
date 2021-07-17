/** @file Transaction.h
 * @author Korosh Moosavi
 * @date 2021-03-12
 *
 * Transaction class:
 * Abstract class
 * Parent class to the transaction classes used to carry out
 *   CollectibleStore operations.
 * 
 * Assumptions:
 * Objects used in this method are valid and initialized.
 */
#pragma once
#include "Inventory.h"
#include "CustomerRegistry.h"
#include "Factory.h"

class Transaction {
public:
   /** ----------- process(Inventory&, CustomerRegistry&, string) ---------
   * Carry out specialized operation. These parameters were chosen as standard
   *   input parameters for current functions, future implementations, and
   *   modifications in mind. Not every subclass will use all parameters.
   * @param inventory  Inventory object containing item data for the store.
   * @param registry   CustomerRegistry object containing customer data.
   * @param input      String containing any additional transaction details.
   * @pre    Parameters are valid and initialized.
   * @return Returns true if the operation was carried out successfully.
   */
   virtual bool process(Inventory& inventory, CustomerRegistry& registry, string input) = 0;
};
