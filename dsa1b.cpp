#include <iostream>
using namespace std;
int main()
{
      int seats[100] = {0, 1, 0, 1, 0};
      int n = 5;
      // Traversal
      cout << "Seat Status: ";
      for (int i = 0; i < n; i++)
            cout << seats[i] << " ";
      cout << endl;
      // Insertion / Booking a new seat
      seats[n] = 1;
      n++;
      cout << "After Booking: ";
      for (int i = 0; i < n; i++)
            cout << seats[i] << " ";
      cout << endl;
      // Searching
      int seat = 1;
      int found = -1;
      for (int i = 0; i < n; i++)
      {
            if (seats[i] == seat)
            {
                  found = i;
                  break;
            }
      }
      if (found != -1)
            cout << "Booked seat found at index " << found << endl;
      else
            cout << "Seat not found" << endl;
      // Deletion / Cancellation
      int deletePosition = 1;
      for (int i = deletePosition; i < n - 1; i++)
            seats[i] = seats[i + 1];
      n--;
      cout << "After Cancellation: ";
      for (int i = 0; i < n; i++)
            cout << seats[i] << " ";
      return 0;
}