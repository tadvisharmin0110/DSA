#include <iostream>
using namespace std;
const int SIZE = 10;
int hashFunction(int carNumber)
{
      return carNumber % SIZE;
}
// Insertion using Linear Probing
void insertCar(int parking[], int carNumber)
{
      int index = hashFunction(carNumber);
      int start = index;
      while (parking[index] != -1)
      {
            index = (index + 1) % SIZE;
            if (index == start)
            {
                  cout << "Parking lot is full.\n";
                  return;
            }
      }
      parking[index] = carNumber;
      cout << "Car " << carNumber << " parked at slot " << index << endl;
}
// Searching
void searchCar(int parking[], int carNumber)
{
      int index = hashFunction(carNumber);
      int start = index;
      while (parking[index] != -1)
      {
            if (parking[index] == carNumber)
            {
                  cout << "Car " << carNumber
                       << " found at slot " << index << endl;
                  return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                  break;
      }
      cout << "Car " << carNumber << " not found.\n";
}
// Deletion
void deleteCar(int parking[], int carNumber)
{
      int index = hashFunction(carNumber);
      int start = index;
      while (parking[index] != -1)
      {
            if (parking[index] == carNumber)
            {
                  parking[index] = -1;
                  cout << "Car " << carNumber << " removed from slot "
                       << index << endl;
                  return;
            }
            index = (index + 1) % SIZE;
            if (index == start)
                  break;
      }
      cout << "Car " << carNumber << " not found.\n";
}
// Traversal
void displayParking(int parking[])
{
      cout << "\nParking Lot:\n";
      for (int i = 0; i < SIZE; i++)
      {
            if (parking[i] == -1)
                  cout << "Slot " << i << ": Empty\n";
            else
                  cout << "Slot " << i << ": Car " << parking[i] << endl;
      }
}
int main()
{
      int parking[SIZE];
      // Initialize hash table
      for (int i = 0; i < SIZE; i++)
            parking[i] = -1;
      // Insertion
      insertCar(parking, 101);
      insertCar(parking, 111);
      insertCar(parking, 121);
      insertCar(parking, 205);
      // Traversal
      displayParking(parking);
      // Searching
      searchCar(parking, 111);
      searchCar(parking, 999);
      // Deletion
      deleteCar(parking, 111);
      // Traversal after deletion
      displayParking(parking);
      return 0;
}