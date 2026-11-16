
#include <iostream>
#include <stack>
using namespace std;

class Queue
{
      stack<int> s1, s2;

public:
      void enqueue(int value)
      {
            s1.push(value);
            cout << value << " inserted into queue.\n";
      }

      void dequeue()
      {
            if (s1.empty() && s2.empty())
            {
                  cout << "Queue is empty!\n";
                  return;
            }

            if (s2.empty())
            {
                  while (!s1.empty())
                  {
                        s2.push(s1.top());
                        s1.pop();
                  }
            }

            cout << "Deleted element: " << s2.top() << endl;
            s2.pop();
      }

      void display()
      {
            if (s1.empty() && s2.empty())
            {
                  cout << "Queue is empty!\n";
                  return;
            }

            cout << "Queue elements: ";

            stack<int> temp2 = s2;
            stack<int> temp1 = s1;

            // s2 contains the front of the queue at its top.
            while (!temp2.empty())
            {
                  cout << temp2.top() << " ";
                  temp2.pop();
            }

            // Reverse s1 temporarily to display older elements first.
            stack<int> temp3;
            while (!temp1.empty())
            {
                  temp3.push(temp1.top());
                  temp1.pop();
            }

            while (!temp3.empty())
            {
                  cout << temp3.top() << " ";
                  temp3.pop();
            }

            cout << endl;
      }
};

int main()
{
      Queue q;
      int choice, value;

      do
      {
            cout << "\n1. Enqueue\n2. Dequeue\n";
            cout << "3. Display\n4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  cout << "Enter value: ";
                  cin >> value;
                  q.enqueue(value);
                  break;

            case 2:
                  q.dequeue();
                  break;

            case 3:
                  q.display();
                  break;

            case 4:
                  cout << "Exiting...\n";
                  break;

            default:
                  cout << "Invalid choice!\n";
            }
      } while (choice != 4);

      return 0;
}
