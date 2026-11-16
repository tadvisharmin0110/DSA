
#include <iostream>
#include <string>
using namespace std;

// Node for each call record
struct Call
{
      string name;
      string phoneNumber;
      string date;
      string time;
      Call *next;
};

// Head pointer
Call *head = nullptr;

// Add a call record
void addCall()
{
      Call *newCall = new Call;

      cout << "\nEnter Name: ";
      cin >> newCall->name;

      cout << "Enter Phone Number: ";
      cin >> newCall->phoneNumber;

      cout << "Enter Date (DD/MM/YYYY): ";
      cin >> newCall->date;

      cout << "Enter Time: ";
      cin >> newCall->time;

      newCall->next = nullptr;

      if (head == nullptr)
      {
            head = newCall;
      }
      else
      {
            Call *temp = head;

            while (temp->next != nullptr)
            {
                  temp = temp->next;
            }

            temp->next = newCall;
      }

      cout << "\nCall added successfully!\n";
}

// Display all calls
void displayCalls()
{
      if (head == nullptr)
      {
            cout << "\nNo call records found.\n";
            return;
      }

      Call *temp = head;

      cout << "\n===== CALL LOG =====\n";

      while (temp != nullptr)
      {
            cout << "Name: " << temp->name << endl;
            cout << "Phone Number: " << temp->phoneNumber << endl;
            cout << "Date: " << temp->date << endl;
            cout << "Time: " << temp->time << endl;
            cout << "----------------------\n";

            temp = temp->next;
      }
}

// Search a call by phone number
void searchCall()
{
      if (head == nullptr)
      {
            cout << "\nNo call records found.\n";
            return;
      }

      string number;

      cout << "\nEnter phone number to search: ";
      cin >> number;

      Call *temp = head;

      while (temp != nullptr)
      {
            if (temp->phoneNumber == number)
            {
                  cout << "\nCall Found!\n";
                  cout << "Name: " << temp->name << endl;
                  cout << "Phone Number: " << temp->phoneNumber << endl;
                  cout << "Date: " << temp->date << endl;
                  cout << "Time: " << temp->time << endl;
                  return;
            }

            temp = temp->next;
      }

      cout << "\nCall record not found.\n";
}

// Delete a call
void deleteCall()
{
      if (head == nullptr)
      {
            cout << "\nNo call records found.\n";
            return;
      }

      string number;

      cout << "\nEnter phone number to delete: ";
      cin >> number;

      Call *temp = head;
      Call *prev = nullptr;

      while (temp != nullptr)
      {
            if (temp->phoneNumber == number)
            {
                  if (prev == nullptr)
                  {
                        head = temp->next;
                  }
                  else
                  {
                        prev->next = temp->next;
                  }

                  delete temp;

                  cout << "\nCall deleted successfully!\n";
                  return;
            }

            prev = temp;
            temp = temp->next;
      }

      cout << "\nCall record not found.\n";
}

// Clear the linked list
void clearList()
{
      Call *temp;

      while (head != nullptr)
      {
            temp = head;
            head = head->next;
            delete temp;
      }
}

// Main function
int main()
{
      int choice;

      do
      {
            cout << "\n\n===== CALL LOG MANAGEMENT =====";
            cout << "\n1. Add Call";
            cout << "\n2. Display Calls";
            cout << "\n3. Search Call";
            cout << "\n4. Delete Call";
            cout << "\n5. Exit";

            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  addCall();
                  break;

            case 2:
                  displayCalls();
                  break;

            case 3:
                  searchCall();
                  break;

            case 4:
                  deleteCall();
                  break;

            case 5:
                  clearList();
                  cout << "\nProgram ended.\n";
                  break;

            default:
                  cout << "\nInvalid choice!\n";
            }

      } while (choice != 5);

      return 0;
}
