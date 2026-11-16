#include <iostream>
using namespace std;
int main()
{
      int stock[100] = {25, 40, 15, 30, 20};
      int n = 5;
      // Traversal
      cout << "Inventory: ";
      for (int i = 0; i < n; i++)
            cout << stock[i] << " ";
      cout << endl;
      // Insertion
      stock[n] = 35;
      n++;
      cout << "After Adding Product: ";
      for (int i = 0; i < n; i++)
            cout << stock[i] << " ";
      cout << endl;
      // Searching
      int searchStock = 30;
      int found = -1;
      for (int i = 0; i < n; i++)
      {
            if (stock[i] == searchStock)
            {
                  found = i;
                  break;
            }
      }
      if (found != -1)
            cout << "Product stock found at index " << found << endl;
      else
            cout << "Product not found" << endl;
      // Deletion
      int deletePosition = 2;
      for (int i = deletePosition; i < n - 1; i++)
            stock[i] = stock[i + 1];
      n--;
      cout << "After Removing Product: ";
      for (int i = 0; i < n; i++)
            cout << stock[i] << " ";
      return 0;
}