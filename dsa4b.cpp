
#include <iostream>
#include <string>
using namespace std;

struct Passenger
{
      int seatNo;
      string name;
      int age;
      string trainName;

      Passenger *prev;
      Passenger *next;
};

Passenger *head = nullptr;
Passenger *tail = nullptr;

// Add passenger
void addPassenger()
{
      Passenger *newPassenger = new Passenger;

      cout << "Enter Seat Number: ";
      cin >> newPassenger->seatNo;

      cout << "Enter Passenger Name: ";
      cin >> newPassenger->name;

      cout << "Enter Age: ";
      cin >> newPassenger->age;

      cout << "Enter Train Name: ";
      cin >> newPassenger->trainName;

      newPassenger->prev = nullptr;
      newPassenger->next = nullptr;

      if (head == nullptr)
      {
            head = tail = newPassenger;
      }
      else
      {
            tail->next = newPassenger;
            newPassenger->prev = tail;
            tail = newPassenger;
      }

      cout << "\nReservation added successfully!\n";
}

// Display from beginning to end
void displayForward()
{
      if (head == nullptr)
      {
            cout << "\nNo reservations found.\n";
            return;
      }

      Passenger *temp = head;

      cout << "\n===== TRAIN RESERVATIONS =====\n";

      while (temp != nullptr)
      {
            cout << "Seat Number: " << temp->seatNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Train: " << temp->trainName << endl;
            cout << "--------------------------\n";

            temp = temp->next;
      }
}

// Display from end to beginning
void displayBackward()
{
      if (tail == nullptr)
      {
            cout << "\nNo reservations found.\n";
            return;
      }

      Passenger *temp = tail;

      cout << "\n===== REVERSE RESERVATIONS =====\n";

      while (temp != nullptr)
      {
            cout << "Seat Number: " << temp->seatNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Train: " << temp->trainName << endl;
            cout << "--------------------------\n";

            temp = temp->prev;
      }
}

// Search passenger
void searchPassenger()
{
      int seat;

      cout << "Enter seat number to search: ";
      cin >> seat;

      Passenger *temp = head;

      while (temp != nullptr)
      {
            if (temp->seatNo == seat)
            {
                  cout << "\nReservation Found!\n";
                  cout << "Seat Number: " << temp->seatNo << endl;
                  cout << "Name: " << temp->name << endl;
                  cout << "Age: " << temp->age << endl;
                  cout << "Train: " << temp->trainName << endl;
                  return;
            }

            temp = temp->next;
      }

      cout << "\nReservation not found.\n";
}

// Cancel reservation
void cancelReservation()
{
      int seat;

      cout << "Enter seat number to cancel: ";
      cin >> seat;

      Passenger *temp = head;

      while (temp != nullptr)
      {
            if (temp->seatNo == seat)
            {

                  if (temp == head)
                        head = temp->next;

                  if (temp == tail)
                        tail = temp->prev;

                  if (temp->prev != nullptr)
                        temp->prev->next = temp->next;

                  if (temp->next != nullptr)
                        temp->next->prev = temp->prev;

                  delete temp;

                  cout << "\nReservation cancelled successfully!\n";
                  return;
            }

            temp = temp->next;
      }

      cout << "\nReservation not found.\n";
}

// Free memory
void clearList()
{
      Passenger *temp;

      while (head != nullptr)
      {
            temp = head;
            head = head->next;
            delete temp;
      }

      tail = nullptr;
}

// Main function
int main()
{
      int choice;

      do
      {
            cout << "\n\n===== TRAIN RESERVATION SYSTEM =====";
            cout << "\n1. Add Reservation";
            cout << "\n2. Display Reservations";
            cout << "\n3. Display Reverse";
            cout << "\n4. Search Reservation";
            cout << "\n5. Cancel Reservation";
            cout << "\n6. Exit";

            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  addPassenger();
                  break;

            case 2:
                  displayForward();
                  break;

            case 3:
                  displayBackward();
                  break;

            case 4:
                  searchPassenger();
                  break;

            case 5:
                  cancelReservation();
                  break;

            case 6:
                  clearList();
                  cout << "\nProgram ended.\n";
                  break;

            default:
                  cout << "\nInvalid choice!\n";
            }

      } while (choice != 6);

      return 0;
}
