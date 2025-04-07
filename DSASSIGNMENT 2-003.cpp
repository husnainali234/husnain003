#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int arrival;
    string condition;
    int priority;

    Person(string n, int a, string c, int p) {
        name = n;
        arrival = a;
        condition = c;
        priority = p;
    }
};

class Node {
public:
    Person p;
    Node* next;

    Node(Person person) : p(person), next(nullptr) {}
};

void insert(Node*& head, Person p) {
    Node* new_node = new Node(p);

    if (head == nullptr) {
        head = new_node;
        return;
    }

    if (p.priority < head->p.priority || (p.priority == head->p.priority && p.arrival < head->p.arrival)) {
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && !(p.priority < current->next->p.priority || (p.priority == current->next->p.priority && p.arrival < current->next->p.arrival))) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

void display(Node* head) {
    Node* current = head;
    cout << "Current Order:\n";
    cout << "Name\tCondition\tPriority\n";
    while (current != nullptr) {
        cout << current->p.name << "\t" << current->p.condition << "\t" << current->p.priority << "\n";
        current = current->next;
    }
}

int main() {
    Node* head = nullptr;

    Person people[] = {
        Person("A", 1, "Fever", 3),
        Person("B", 2, "Heart Attack", 1),
        Person("C", 3, "Broken Leg", 2),
        Person("D", 4, "Mild Cold", 4),
        Person("E", 5, "Severe Burn", 2),
        Person("F", 6, "Small Cut", 4),
        Person("G", 7, "Stroke", 1),
        Person("H", 8, "Food Poisoning", 3),
        Person("I", 9, "Fractured Arm", 2),
        Person("J", 10, "Migraine", 3)
    };

    for (int i = 0; i < 10; i++) {
        cout << "Added " << people[i].name << ":\n";
        insert(head, people[i]);
        display(head);
        cout << "\n";
    }

    return 0;
}
