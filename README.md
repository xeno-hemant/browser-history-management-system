
# Browser History Management System

A menu-driven Browser History Management System developed in C++ using the **Doubly Linked List** data structure.

The project simulates basic browser navigation and history management operations, including visiting web pages, navigating backward and forward, searching browsing history, and deleting history entries.

## Project Information

| Detail | Information |
|---|---|
| Project Name | Browser History Management System |
| Project Number | 8 |
| Section | B |
| Programming Language | C++ |
| Main DSA Concept | Doubly Linked List |
| Project Type | DSA Lab Project |

## Team Members

| S. No. | Name | Roll Number |
|---|---|---|
| 1 | Hemant Gurjar | 25EGJCS090 |
| 2 | Himanshi Pancholi | 25EGJCS092 |
| 3 | Hemant Khandelwal | 25EGJCS091 |
| 4 | Harshpal Singh | 25EGJCS089 |

## Modules and Responsibilities

### Module 1: Visit Page Module
**Assigned to:** Hemant Gurjar

- Add new URL nodes when users visit pages.
- Connect pages using previous and next pointers.
- Clear forward history when a new page is visited after going back.

### Module 2: Back and Forward Navigation Module
**Assigned to:** Himanshi Pancholi

- Navigate to the previous page using the previous pointer.
- Navigate to the next page using the next pointer.
- Display the current page after navigation.

### Module 3: History Display and Search Module
**Assigned to:** Hemant Khandelwal

- Display complete browsing history.
- Identify the current page.
- Search browsing history using a URL or keyword.

### Module 4: History Deletion Module
**Assigned to:** Harshpal Singh

- Delete a single history entry.
- Delete multiple entries within a selected position range.
- Clear the complete browsing history.

## Features

1. Visit a new web page.
2. Navigate backward and forward.
3. Display complete browsing history.
4. Search URLs using keywords.
5. Delete a specific history entry.
6. Delete history entries by position range.
7. Clear all browsing history.
8. Track the currently active page.

## Data Structure Used

### Doubly Linked List

Each node stores:
- URL of the visited page.
- Pointer to the previous node.
- Pointer to the next node.

The `current` pointer tracks the currently active page.

### Node Structure

```cpp
struct Node {
    string url;
    Node* prev;
    Node* next;
};
```

## How to Run the Project

### Requirements
- C++ compiler (GCC, MinGW, or equivalent).
- C++11 or later.

### Compilation

```bash
g++ -std=c++17 main.cpp -o browser_history
```

### Execution

**Windows:**
```bash
browser_history.exe
```

**Linux / macOS:**
```bash
./browser_history
```

## Sample Operations

```text
1. Visit New Page
2. Go Back
3. Go Forward
4. Display Browser History
5. Search History
6. Delete Single History Entry
7. Delete History by Range
8. Clear Complete History
9. Exit
```

## Time Complexity

| Operation | Time Complexity |
|---|---|
| Visit New Page | O(1) |
| Go Back | O(1) |
| Go Forward | O(1) |
| Display History | O(n) |
| Search History | O(n) |
| Delete Single Entry by Position | O(n) |
| Delete History by Range | O(n) |
| Clear Complete History | O(n) |

Here, `n` represents the number of pages stored in browsing history.

## Future Improvements

- Store browsing history permanently using file handling.
- Add timestamps for visited pages.
- Add a graphical user interface.
- Support bookmarks and frequently visited pages.

## Conclusion

The Browser History Management System demonstrates the practical implementation of a Doubly Linked List in C++. It provides browser-like navigation and history management while demonstrating dynamic memory allocation, pointer manipulation, insertion, deletion, and searching operations.
