
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
using namespace std;

// Node of the Doubly Linked List
struct Node {
    string url;
    Node* prev;
    Node* next;

    Node(string page) {
        url = page;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;
    Node* current;
    int totalPages;

    // Delete all pages after the current page
    void clearForwardHistory() {
        if (current == nullptr) return;

        Node* temp = current->next;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            totalPages--;
            temp = nextNode;
        }

        current->next = nullptr;
        tail = current;
    }

    // Convert a string to lowercase for searching
    string toLowerCase(string text) {
        transform(text.begin(), text.end(), text.begin(),
                  [](unsigned char c) {
                      return static_cast<char>(tolower(c));
                  });
        return text;
    }

public:
    BrowserHistory() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        totalPages = 0;
    }

    // Module 1: Visit Page Module
    void visitPage(string url) {
        if (url.empty()) {
            cout << "URL cannot be empty.\n";
            return;
        }

        // A new visit removes the forward history
        if (current != nullptr) {
            clearForwardHistory();
        }

        Node* newNode = new Node(url);

        if (head == nullptr) {
            head = tail = current = newNode;
        } else {
            newNode->prev = current;
            current->next = newNode;
            tail = newNode;
            current = newNode;
        }

        totalPages++;
        cout << "Page visited successfully: " << url << "\n";
    }

    // Module 2: Back Navigation
    void goBack() {
        if (current == nullptr || current->prev == nullptr) {
            cout << "No previous page available.\n";
            return;
        }

        current = current->prev;
        cout << "Moved back to: " << current->url << "\n";
    }

    // Module 2: Forward Navigation
    void goForward() {
        if (current == nullptr || current->next == nullptr) {
            cout << "No forward page available.\n";
            return;
        }

        current = current->next;
        cout << "Moved forward to: " << current->url << "\n";
    }

    // Module 3: Display complete browsing history
    void displayHistory() {
        if (head == nullptr) {
            cout << "Browser history is empty.\n";
            return;
        }

        Node* temp = head;
        int position = 1;

        cout << "\n========== BROWSER HISTORY ==========\n";

        while (temp != nullptr) {
            cout << position << ". " << temp->url;

            if (temp == current) {
                cout << "  <-- CURRENT PAGE";
            }

            cout << "\n";
            temp = temp->next;
            position++;
        }

        cout << "=====================================\n";
    }

    // Module 3: Search history by URL or keyword
    void searchHistory(string keyword) {
        if (head == nullptr) {
            cout << "Browser history is empty.\n";
            return;
        }

        if (keyword.empty()) {
            cout << "Search keyword cannot be empty.\n";
            return;
        }

        string searchText = toLowerCase(keyword);
        Node* temp = head;
        int position = 1;
        bool found = false;

        while (temp != nullptr) {
            string page = toLowerCase(temp->url);

            if (page.find(searchText) != string::npos) {
                cout << position << ". " << temp->url << "\n";
                found = true;
            }

            temp = temp->next;
            position++;
        }

        if (!found) {
            cout << "No matching page found.\n";
        }
    }

    // Module 4: Delete a single history entry by position
    void deletePage(int position) {
        if (position < 1 || position > totalPages) {
            cout << "Invalid history position.\n";
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }

        Node* previousNode = temp->prev;
        Node* nextNode = temp->next;

        // Update the links
        if (previousNode != nullptr) {
            previousNode->next = nextNode;
        } else {
            head = nextNode;
        }

        if (nextNode != nullptr) {
            nextNode->prev = previousNode;
        } else {
            tail = previousNode;
        }

        // Update current page if it is being deleted
        if (current == temp) {
            if (nextNode != nullptr) {
                current = nextNode;
            } else {
                current = previousNode;
            }
        }

        cout << "Deleted page: " << temp->url << "\n";

        delete temp;
        totalPages--;

        if (totalPages == 0) {
            head = tail = current = nullptr;
        }
    }

    // Module 4: Delete history entries within a position range
    void deleteRange(int start, int end) {
        if (start < 1 || end > totalPages || start > end) {
            cout << "Invalid position range.\n";
            return;
        }

        for (int position = end; position >= start; position--) {
            deletePage(position);
        }

        cout << "Selected history range deleted successfully.\n";
    }

    // Module 4: Clear complete browsing history
    void clearHistory() {
        Node* temp = head;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        head = tail = current = nullptr;
        totalPages = 0;

        cout << "Complete browser history cleared.\n";
    }

    ~BrowserHistory() {
        clearHistory();
    }
};

int main() {
    BrowserHistory browser;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "     BROWSER HISTORY MANAGEMENT\n";
        cout << "====================================\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Go Forward\n";
        cout << "4. Display Browser History\n";
        cout << "5. Search History\n";
        cout << "6. Delete Single History Entry\n";
        cout << "7. Delete History by Range\n";
        cout << "8. Clear Complete History\n";
        cout << "9. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string url, keyword;
        int position, start, end;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                getline(cin, url);
                browser.visitPage(url);
                break;

            case 2:
                browser.goBack();
                break;

            case 3:
                browser.goForward();
                break;

            case 4:
                browser.displayHistory();
                break;

            case 5:
                cout << "Enter URL or keyword to search: ";
                getline(cin, keyword);
                browser.searchHistory(keyword);
                break;

            case 6:
                cout << "Enter history position to delete: ";
                if (cin >> position) {
                    browser.deletePage(position);
                } else {
                    cout << "Invalid input.\n";
                    cin.clear();
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;

            case 7:
                cout << "Enter starting position: ";
                if (!(cin >> start)) {
                    cout << "Invalid input.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Enter ending position: ";
                if (!(cin >> end)) {
                    cout << "Invalid input.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                browser.deleteRange(start, end);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;

            case 8:
                browser.clearHistory();
                break;

            case 9:
                cout << "Exiting Browser History Management System.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
