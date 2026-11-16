
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
      string str;
      deque<char> dq;

      cout << "Enter a string: ";
      cin >> str;

      for (char ch : str)
      {
            dq.push_back(ch);
      }

      bool palindrome = true;

      while (dq.size() > 1)
      {
            char frontChar = dq.front();
            char backChar = dq.back();

            if (frontChar != backChar)
            {
                  palindrome = false;
                  break;
            }

            dq.pop_front();
            dq.pop_back();
      }

      if (palindrome)
            cout << str << " is a palindrome." << endl;
      else
            cout << str << " is not a palindrome." << endl;

      return 0;
}
