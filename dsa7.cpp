
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task
{
      string name;
      int priority;
};

class TaskScheduler
{
      vector<Task> heap;

      void heapifyUp(int i)
      {
            while (i > 0)
            {
                  int parent = (i - 1) / 2;

                  if (heap[parent].priority >= heap[i].priority)
                        break;

                  swap(heap[parent], heap[i]);
                  i = parent;
            }
      }

      void heapifyDown(int i)
      {
            int n = heap.size();

            while (true)
            {
                  int largest = i;
                  int left = 2 * i + 1;
                  int right = 2 * i + 2;

                  if (left < n &&
                      heap[left].priority > heap[largest].priority)
                        largest = left;

                  if (right < n &&
                      heap[right].priority > heap[largest].priority)
                        largest = right;

                  if (largest == i)
                        break;

                  swap(heap[i], heap[largest]);
                  i = largest;
            }
      }

public:
      void addTask(string name, int priority)
      {
            heap.push_back({name, priority});
            heapifyUp(heap.size() - 1);
            cout << "Task added successfully.\n";
      }

      void processTask()
      {
            if (heap.empty())
            {
                  cout << "No tasks available.\n";
                  return;
            }

            cout << "Processing task: " << heap[0].name
                 << " (Priority: " << heap[0].priority << ")\n";

            heap[0] = heap.back();
            heap.pop_back();

            if (!heap.empty())
                  heapifyDown(0);
      }

      void displayTasks()
      {
            if (heap.empty())
            {
                  cout << "No tasks available.\n";
                  return;
            }

            cout << "\nPending tasks (heap order):\n";
            for (const Task &task : heap)
            {
                  cout << "Task: " << task.name
                       << ", Priority: " << task.priority << endl;
            }
      }
};

int main()
{
      TaskScheduler scheduler;
      int choice, priority;
      string name;

      do
      {
            cout << "\n--- Task Scheduler ---\n";
            cout << "1. Add Task\n";
            cout << "2. Process Highest-Priority Task\n";
            cout << "3. Display Tasks\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  cout << "Enter task name (no spaces): ";
                  cin >> name;

                  cout << "Enter priority (higher number = higher priority): ";
                  cin >> priority;

                  scheduler.addTask(name, priority);
                  break;

            case 2:
                  scheduler.processTask();
                  break;

            case 3:
                  scheduler.displayTasks();
                  break;

            case 4:
                  cout << "Exiting scheduler.\n";
                  break;

            default:
                  cout << "Invalid choice.\n";
            }
      } while (choice != 4);

      return 0;
}
