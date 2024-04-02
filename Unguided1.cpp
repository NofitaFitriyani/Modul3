#include <iostream>
using namespace std;

// NOFITA FITRIYANI_2311102001_IF11A
class Node
{
public:
    string name;
    int age;
    Node *next;
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void insertAtFront(string name, int age)
    {
        Node *newNode = new Node();
        newNode->name = name;
        newNode->age = age;
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(string name, int age)
    {
        Node *newNode = new Node();
        newNode->name = name;
        newNode->age = age;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void insertAfter(string name, int age, string keyName)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == keyName)
            {
                Node *newNode = new Node();
                newNode->name = name;
                newNode->age = age;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << keyName << " not found in the list." << endl;
    }
    void updateNode(string name, int age)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                temp->age = age;
                return;
            }
            temp = temp->next;
        }
        cout << name << " not found in the list." << endl;
    }
    void deleteNode(string name)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->name == name)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << name << " not found in the list." << endl;
    }
    void clearAll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
    }
    // Display all nodes
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->name << "\t" << temp->age << endl;
            temp = temp->next;
        }
    }
};
// Main function
int main()
{
    LinkedList list;
    int choice;
    string name, keyName;
    int age;
    do
    {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Add data" << endl;
        cout << "2. Update data" << endl;
        cout << "3. Delete data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Tambah Data diawal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 8; ++i)
            {
                cout << "Enter name " << i + 1 << ": ";
                cin >> name;
                cout << "Enter age " << i + 1 << ": ";
                cin >> age;
                list.insertAtEnd(name, age);
            }
            cout << "Data sudah ditambahkan" << endl;
            break;
        case 2:
            cout << "Enter name to update: ";
            cin >> name;
            if (name == "Michael")
            {
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new age: ";
                cin >> age;
                list.updateNode(name, age);
            }
            else
            {
                cout << "Name not found in the list." << endl;
            }
            break;
        case 3:
            cout << "Enter name to delete: ";
            cin >> name;
            list.deleteNode(name);
            break;
        case 4:
            list.clearAll();
            break;
        case 5:
            list.display();
            break;
        case 6:
            cout << "Enter additional data to add at the beginning:" << endl;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            list.insertAtFront(name, age);
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 7);
    return 0;
}