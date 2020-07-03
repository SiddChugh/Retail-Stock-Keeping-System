
#include "stocksystem.h"

StockSystem::StockSystem() : records(), balance(100000)
{
}

double StockSystem::GetBalance()
{
  return balance;
}
bool StockSystem::StockNewItem(StockItem item)
{
  return records.Insert(item);
}

bool StockSystem::EditStockItemDescription(int itemsku, std::string desc)
{
  StockItem requested_item(itemsku, "225", 0);

  if (records.Contains(requested_item))
  {
    StockItem* found_item = records.Retrieve(requested_item);
    return found_item->SetDescription(desc);
  }

  return false;
}

bool StockSystem::EditStockItemPrice(int itemsku, double retailprice)
{
  StockItem requested_item(itemsku, "225", 0);

  if (records.Contains(requested_item) && retailprice >= 0)
   {
    StockItem* found_item = records.Retrieve(requested_item);
    return found_item->SetPrice(retailprice);
  }

  return false;
}

bool StockSystem::Restock(int itemsku, int quantity, double unitprice)
{
  if (quantity < 0 || unitprice < 0)
  {
    return false;
  }

  double cost = quantity*unitprice;
  StockItem requested_item(itemsku, "225", 0);

  if (records.Contains(requested_item) && (balance - cost) >= 0)
  {
    StockItem* found_item = records.Retrieve(requested_item);
    balance = balance - cost;
    return found_item->SetStock(found_item->GetStock() + quantity);
  }

  return false;
}

bool StockSystem::Sell(int itemsku, int quantity)
{
  StockItem requested_item(itemsku, "225", 0);

  if (records.Contains(requested_item) && quantity >= 0)
  {
    StockItem* found_item = records.Retrieve(requested_item);
    int current_stock = found_item->GetStock();

    if (quantity > current_stock)
    {
      balance = balance + current_stock*found_item->GetPrice();
      current_stock = 0;
    }

    else
    {
      balance = balance + quantity*found_item->GetPrice();
      current_stock = current_stock - quantity;
    }

    return found_item->SetStock(current_stock);
  }

  return false;
}
