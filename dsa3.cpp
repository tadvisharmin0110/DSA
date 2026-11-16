
#include <iostream>
#include <string>
using namespace std;

class PhoneBook
{
private:
      string name[50];
      string mobile[50];
      int n;

public:
      PhoneBook()
      {
            n = 0;
      }

      // Insert friend in sorted order
      void insertFriend(string newName, string newMobile)
      {
            int pos = 0;

            while (pos < n && name[pos] < newName)
            {
                  pos++;
            }

            // Shift elements to the right
            for (int i = n; i > pos; i--)
            {
                  name[i] = name[i - 1];
                  mobile[i] = mobile[i - 1];
            }

            name[pos] = newName;
            mobile[pos] = newMobile;
            n++;

            cout << "Friend inserted successfully." << endl;
      }

      // Sentinel Search
      int sentinelSearch(string key)
      {
            if (n == 0)
                  return -1;

            string lastName = name[n - 1];
            string lastMobile = mobile[n - 1];

            // Place sentinel
            name[n - 1] = key;

            int i = 0;

            while (name[i] != key)
            {
                  i++;
            }

            // Restore last element
            name[n - 1] = lastName;
            mobile[n - 1] = lastMobile;

            if (i < n - 1 || lastName == key)
                  return i;

            return -1;
      }

      // Display phone book
      void display()
      {
            cout << "\n----- PHONE BOOK -----" << endl;

            for (int i = 0; i < n; i++)
            {
                  cout << name[i] << " : " << mobile[i] << endl;
            }
      }

      // Search and insert if not present
      void searchAndInsert()
      {
            string searchName;
            string searchMobile;

            cout << "\nEnter friend's name to search: ";
            cin >> searchName;

            int index = sentinelSearch(searchName);

            if (index != -1)
            {
                  cout << "Friend found!" << endl;
                  cout << "Name : " << name[index] << endl;
                  cout << "Mobile : " << mobile[index] << endl;
            }
            else
            {
                  cout << "Friend not found." << endl;

                  cout << "Enter mobile number: ";
                  cin >> searchMobile;

                  insertFriend(searchName, searchMobile);
            }
      }
};

int main()
{
      PhoneBook phoneBook;

      // Initial friends
      phoneBook.insertFriend("Shravasti", "7499280812");
      phoneBook.insertFriend("Chetana", "9356103643");
      phoneBook.insertFriend("Tanisha", "9529480232");
      phoneBook.insertFriend("Saloni", "7841093872");
      phoneBook.insertFriend("Utkarsha", "8329957695");

      phoneBook.display();

      // Search friend
      phoneBook.searchAndInsert();

      // Display updated phone book
      phoneBook.display();

      return 0;
}
