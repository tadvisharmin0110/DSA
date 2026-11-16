#include <iostream>
using namespace std;
int main()
{
      int marks[100] = {78, 85, 92, 67, 88};
      int n = 5;
      // Traversal
      cout << "Student Marks: ";
      for (int i = 0; i < n; i++)
      {
            cout << marks[i] << " ";
      }
      cout << endl;
      // Insertion
      int position = 5;
      int newMark = 95;
      marks[position] = newMark;
      n++;
      cout << "After Insertion: ";
      for (int i = 0; i < n; i++)
      {
            cout << marks[i] << " ";
      }
      cout << endl;
      // Searching
      int searchMark = 92;
      int found = -1;
      for (int i = 0; i < n; i++)
      {
            if (marks[i] == searchMark)
            {
                  found = i;
                  break;
            }
      }
      if (found != -1)
            cout << searchMark << " found at index " << found << endl;
      else
            cout << searchMark << " not found" << endl;
      // Deletion
      int deletePosition = 3;
      for (int i = deletePosition; i < n - 1; i++)
      {
            marks[i] = marks[i + 1];
      }
      n--;
      cout << "After Deletion: ";
      for (int i = 0; i < n; i++)
      {
            cout << marks[i] << " ";
      }
      cout << endl;
      return 0;
}