#include <iostream>
using namespace std;
const int SIZE = 10;
int hashFunction(int productCode)
{
      return productCode % SIZE;
}
void insertProduct(int inventory[], int productCode)
{
      int index = hashFunction(productCode);
      int start = index;
      while (inventory[index] != -1)
      {
            index = (index + 1) % SIZE;
            if (index == start)
            {
                  cout << "Inventory table is full.\n";
                  return;
            }
      }
      inventory[index] = productCode;
      cout << "Product " << productCode
           << " added at index " << index << endl;
}
void searchProduct(int inventory[], int productCode)
{
      int index = hashFunction(productCode);
      int start = index;
      while (inventory[index] != -1)
      {
            if (inventory[index] == productCode)
            {
                  cout << "Product " << productCode
                       << " found at index " << index << endl;
                  return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                  break;
      }
      cout << "Product " << productCode << " not found.\n";
}
void deleteProduct(int inventory[], int productCode)
{
      int index = hashFunction(productCode);
      int start = index;
      while (inventory[index] != -1)
      {
            if (inventory[index] == productCode)
            {
                  inventory[index] = -1;
                  cout << "Product " << productCode << " removed.\n";
                  return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                  break;
      }
      cout << "Product " << productCode << " not found.\n";
}
void display(int inventory[])
{
      cout << "\nInventory Hash Table:\n";
      for (int i = 0; i < SIZE; i++)
      {
            if (inventory[i] == -1)
                  cout << "Index " << i << ": Empty\n";
            else
                  cout << "Index " << i
                       << ": Product " << inventory[i] << endl;
      }
}
int main()
{
      int inventory[SIZE];
      for (int i = 0; i < SIZE; i++)
            inventory[i] = -1;
      insertProduct(inventory, 101);
      insertProduct(inventory, 111);
      insertProduct(inventory, 121);
      insertProduct(inventory, 205);
      display(inventory);
      searchProduct(inventory, 121);
      searchProduct(inventory, 999);
      deleteProduct(inventory, 111);
      display(inventory);
      return 0;
}