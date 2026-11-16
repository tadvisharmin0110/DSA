
#include <iostream>
using namespace std;

struct Node
{
      int data;
      Node *next;
};

Node *topNode = nullptr;

void push(int value)
{
      Node *newNode = new Node{value, topNode};
      topNode = newNode;
      cout << value << " pushed successfully.\n";
}

void pop()
{
      if (topNode == nullptr)
      {
            cout << "Stack Underflow!\n";
            return;
      }

      Node *temp = topNode;
      cout << "Popped element: " << temp->data << endl;
      topNode = topNode->next;
      delete temp;
}

void display()
{
      if (topNode == nullptr)
      {
            cout << "Stack is empty.\n";
            return;
      }

      cout << "Stack elements: ";
      for (Node *p = topNode; p != nullptr; p = p->next)
            cout << p->data << " ";
      cout << endl;
}

int main()
{
      int choice, value;

      do
      {
            cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  cout << "Enter value: ";
                  cin >> value;
                  push(value);
                  break;
            case 2:
                  pop();
                  break;
            case 3:
                  display();
                  break;
            case 4:
                  cout << "Exiting...\n";
                  break;
            default:
                  cout << "Invalid choice!\n";
            }
      } while (choice != 4);

      while (topNode != nullptr)
            pop();

      return 0;
}
