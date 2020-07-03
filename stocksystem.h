// Description: Declaration of a StockSystem class 

#ifndef _STOCKSYSTEM_H_
#define _STOCKSYSTEM_H_

#include <math.h>
#include <sstream>

#include "stockitem.h"
#include "redblacktree.h"

class StockSystem
{
private:
  RedBlackTree<StockItem> records;
  double balance; // how much money you have in the bank

public:
  /**
    *default constructor;
    *begin with a balance of $100,000.00
    */
  StockSystem();

  /**
    *returns the balance member
    */
  double GetBalance();

  /**
    *Add a new SKU to the system. Do not allow insertion of duplicate sku
    */
  bool StockNewItem(StockItem item);

  /**
    *Locate the item with key itemsku and update its description field.
    *Return false if itemsku is not found.
    */
  bool EditStockItemDescription(int itemsku, std::string desc);

  /**
    *Locate the item with key itemsku and update its description field.
    *Return false if itemsku is not found or retailprice is negative.
    */
  bool EditStockItemPrice(int itemsku, double retailprice);

  /**
    *Purchase quantity of item at unitprice each, to reach a maximum 
    *(post-purchase) on-hand stock quantity of 1000.
    *Return false if balance is not sufficient to make the purchase,
    *  or if SKU does not exist, or if quantity or unitprice are negative.
    *Otherwise, return true and increase the item's on-hand stock by quantity,
    *  and reduce balance by quantity*unitprice.
    */
  bool Restock(int itemsku, int quantity, double unitprice);

  /**
    *Sell an item to a customer, if quantity of stock is available and SKU 
    *exists.
    *Reduce stock by quantity, increase balance by quantity*price, and return 
    *true if stock available.
    *If partial stock (less than quantity) available, sell the available stock 
    *and return true.
    *If no stock, sku does not exist, or quantity is negative, return false.
    */
  bool Sell(int itemsku, int quantity);

  /**
    *Provides access to internal RedBlackTree.
    *Used for grading.
    *Note that this is dangerous in practice!
    */
  RedBlackTree<StockItem>& GetRecords()
  {
    return records;
  }
};
#endif