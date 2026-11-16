
#include <iostream>
#include <string>
using namespace std;

struct Node
{
      string song;
      Node *next;
};

Node *head = NULL;

// Add a song
void addSong(string name)
{
      Node *newNode = new Node;
      newNode->song = name;

      if (head == NULL)
      {
            head = newNode;
            newNode->next = head;
      }
      else
      {
            Node *temp = head;

            while (temp->next != head)
            {
                  temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
      }

      cout << "Song added successfully.\n";
}

// Display playlist
void displayPlaylist()
{
      if (head == NULL)
      {
            cout << "Playlist is empty.\n";
            return;
      }

      Node *temp = head;

      cout << "\nMusic Playlist:\n";

      do
      {
            cout << temp->song << " -> ";
            temp = temp->next;
      } while (temp != head);

      cout << "(Back to first song)\n";
}

// Delete a song
void deleteSong(string name)
{
      if (head == NULL)
      {
            cout << "Playlist is empty.\n";
            return;
      }

      Node *current = head;
      Node *previous = NULL;

      // If first song is to be deleted
      if (head->song == name)
      {

            // Only one node
            if (head->next == head)
            {
                  delete head;
                  head = NULL;
            }
            else
            {
                  Node *last = head;

                  while (last->next != head)
                  {
                        last = last->next;
                  }

                  head = head->next;
                  last->next = head;

                  delete current;
            }

            cout << "Song deleted successfully.\n";
            return;
      }

      // Search for song
      previous = head;
      current = head->next;

      while (current != head)
      {
            if (current->song == name)
            {
                  previous->next = current->next;
                  delete current;

                  cout << "Song deleted successfully.\n";
                  return;
            }

            previous = current;
            current = current->next;
      }

      cout << "Song not found.\n";
}

// Main function
int main()
{
      int choice;
      string name;

      do
      {
            cout << "\n===== MUSIC PLAYLIST =====\n";
            cout << "1. Add Song\n";
            cout << "2. Display Playlist\n";
            cout << "3. Delete Song\n";
            cout << "4. Exit\n";

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  cout << "Enter song name: ";
                  cin.ignore();
                  getline(cin, name);
                  addSong(name);
                  break;

            case 2:
                  displayPlaylist();
                  break;

            case 3:
                  cout << "Enter song name to delete: ";
                  cin.ignore();
                  getline(cin, name);
                  deleteSong(name);
                  break;

            case 4:
                  cout << "Exiting playlist...\n";
                  break;

            default:
                  cout << "Invalid choice!\n";
            }

      } while (choice != 4);

      return 0;
}
