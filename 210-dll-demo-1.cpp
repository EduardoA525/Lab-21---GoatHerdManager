//Eduardo Avila
//COMSC - 210 - 5293
//Lab 21 - Goat Herd Manager 3000

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int MIN_LS = 5, MAX_LS = 20;

class Goat {
private:
    int age;
    string name;
    string color;

    //array for random goat name
    string goatNames[15] = { "Billy", "Clover", "Daisy", 
        "Duke", "Fern", "Ginger", "Hazel", "Maple", 
        "Milo", "Oreo", "Pepper", "Poppy", "Rosie", "Shadow", "Willow"
    };

    //array for random goat color
    string goatColors[15] = { "White", "Black", "Brown", 
        "Gray", "Tan", "Cream", "Golden", "Spotted", "Red", 
        "Chocolate", "Silver", "Charcoal", "Beige", "Rust", "Black and White"
    };

public:
    //Default constructor with randos
    Goat() {
        age = rand() % 20 + 1;

        int nameNum = rand() % 15;
        int colorNum = rand() % 15;

        name = goatNames[nameNum];
        color = goatColors[colorNum];
    }

    //parameters
    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }
    //personal print function so goat members dont have to go public
    void print() {
        cout << name << " (" << color << ", " << age << " )";
    }

};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;

        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);

        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);

        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    /*void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_node(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }
        */

    void print() {
        Node* current = head;

        if (!current) {
            cout << "List is empty" << endl;
            return;
        }

        while (current) {
            cout << "    ";
            current->data.print();
            cout << endl;

            current = current->next;
        }
    }

    void print_reverse() {
        Node* current = tail;

        if (!current) {
            cout << "List is empty" << endl;
            return;
        }

        while (current) {
            cout << "    ";
            current->data.print();
            cout << endl;

            current = current->prev;
        }
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));

    DoublyLinkedList list;

    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i){
        Goat newGoat;
        list.push_back(newGoat);
    }

    cout << "List forward: " << endl;
    list.print();

    cout << endl;

    cout << "List backward: " << endl;
    list.print_reverse();

    /*cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();*/

    return 0;
}
