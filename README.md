# SinglyLinkedList-CPP

A modern C++ wrapper class for a Singly Linked List with full support for insertion, removal, deep copy, move semantics, and memory-safe destruction.
A modern, object-oriented C++ implementation of a singly linked list. This project supports basic and advanced operations such as:

- Insert at head
- Insert at tail
- Insert at specific position
- Remove from specific index
- Clear the list
- Copy constructor (deep copy)
- Move constructor (ownership transfer)

---

## 🚀 Features

- ✅ Clean, modular design
- ✅ Safe memory management (no leaks)
- ✅ Supports Rule of Five (copy/move constructor and assignment)
- ✅ Easy to integrate and test

---

## 🧱 Class Structure
```
namespace TadeebDS
{
class SinglyLinkedList
{
private:
class Node
{
private:
Node *next;
int num;
Node(int num)
{
//Some-code
}
friend class SinglyLinkedList;
};
Node *top, *bottom;
int size;

public:

SinglyLinkedList()
{
//Some-code
}

SinglyLinkedList(const SinglyLinkedList &other)
{
//Some-code
}

SinglyLinkedList(SinglyLinkedList &&other)
{
//Some-code
}

void add(int num)
{
//Some-code
}

void insertAtTop(int num)
{
//Some-code
}

void insertAt(int pos, int num)
{
//Some-code
}

int get(int index)
{
//Some-code
}

int getSize()
{
//Some-code
}

void removeAt(int index)
{
//Some-code
}

void clearAll()
{
//Some-code
}
};
};
```



