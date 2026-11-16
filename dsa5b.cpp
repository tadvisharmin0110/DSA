
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
      string exp;
      stack<int> st;

      cout << "Enter postfix expression: ";
      cin >> exp;

      for (char ch : exp)
      {
            if (ch >= '0' && ch <= '9')
            {
                  st.push(ch - '0');
            }
            else
            {
                  int b = st.top();
                  st.pop();
                  int a = st.top();
                  st.pop();

                  switch (ch)
                  {
                  case '+':
                        st.push(a + b);
                        break;
                  case '-':
                        st.push(a - b);
                        break;
                  case '*':
                        st.push(a * b);
                        break;
                  case '/':
                        if (b == 0)
                        {
                              cout << "Division by zero is invalid.";
                              return 0;
                        }
                        st.push(a / b);
                        break;
                  default:
                        cout << "Invalid operator.";
                        return 0;
                  }
            }
      }

      if (st.size() == 1)
            cout << "Result: " << st.top() << endl;
      else
            cout << "Invalid postfix expression." << endl;

      return 0;
}
