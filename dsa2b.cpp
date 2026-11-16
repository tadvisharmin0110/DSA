#include <iostream>
using namespace std;
const int SIZE = 10;
int hashFunction(int isbn)
{
      return isbn % SIZE;
}
void insertBook(int library[], int isbn)
{
      int index = hashFunction(isbn);
      int start = index;
      while (library[index] != -1)
      {
            index = (index + 1) % SIZE;
            if (index == start)
            {
                  cout << "Library table is full.\n";
                  return;
            }
      }
      library[index] = isbn;
      cout << "Book " << isbn << " stored at index "
           << index << endl;
}
void searchBook(int library[], int isbn)
{
      int index = hashFunction(isbn);
      int start = index;
      while (library[index] != -1)
      {
            if (library[index] == isbn)
            {
                  cout << "Book " << isbn
                       << " found at index " << index << endl;
                  return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                  break;
      }
      cout << "Book " << isbn << " not found.\n";
}
void deleteBook(int library[], int isbn)
{
      int index = hashFunction(isbn);
      int start = index;
      while (library[index] != -1)
      {
            if (library[index] == isbn)
            {
                  library[index] = -1;
                  cout << "Book " << isbn << " deleted.\n";
                  return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                  break;
      }
      cout << "Book " << isbn << " not found.\n";
}
void display(int library[])
{
      cout << "\nLibrary Hash Table:\n";
      for (int i = 0; i < SIZE; i++)
      {
            if (library[i] == -1)
                  cout << "Index " << i << ": Empty\n";
            else
                  cout << "Index " << i
                       << ": ISBN " << library[i] << endl;
      }
}
int main()
{
      int library[SIZE];
      for (int i = 0; i < SIZE; i++)
            library[i] = -1;
      insertBook(library, 101);
      insertBook(library, 111);
      insertBook(library, 205);
      insertBook(library, 315);
      display(library);
      searchBook(library, 111);
      searchBook(library, 999);
      deleteBook(library, 111);
      display(library);
      return 0;
}