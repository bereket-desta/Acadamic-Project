#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
struct node
{
    int data;
    struct node* next;
    struct node* prev;
}*head;


class linked_llist
{
public:
    void create(int value);
    void insert_first(int value);
    void insert_last(int value);
    void insert_position(int value, int p);
    void delete_first();
    void delete_last();
    void delete_middle(int value);
    void display();

    linked_llist() {
        head = NULL;
    }
};


int main()
{
    int c, elm, pos;
    linked_llist dl;
    while (1)
    {
        cout << "\n\n\t\t menu";
        cout << "\n\t 1, create_list";
        cout << "\n\t 2, Insert_element";
        cout << "\n\t 3, Delete_element";
        cout << "\n\t 4, display";
        cout << "\n\t 5, exit";
        cout << "\n\t enter your choice \n";
        cin >> c;

        switch (c)
        {

        case 1:
            cout << "\n\n enter the element \n";
            cin >> elm;
            dl.create(elm);
            cout << endl;
            dl.display();
            break;

        case 2:
            cout << "\n\t 1,insert at beginning";
            cout << "\n\t 2,insert at middle";
            cout << "\n\t 3,insert at last \n";
            cout << "\t 4,back to menu \n";
            cin >> c;
            switch (c) {
            case 1:
                cout << "\n\n enter the element\n";
                cin >> elm;
                dl.insert_first(elm);
                cout << endl;
                dl.display();
                break;
            case 2:
                cout << "\n\n enter the element \n";
                cin >> elm;
                cout << "\n\n enter the position \n";
                cin >> pos;
                dl.insert_position(elm, pos);
                cout << endl;
                dl.display();
                break;
            case 3:
                cout << "\n\n enter the element\n";
                cin >> elm;
                dl.insert_last(elm);
                cout << endl;
                dl.display();
                break;
            case 4:
                break;

            default:
                cout << "\n wrong choice \n";
            }
            break;

        case 3:
            cout << "\n\t 1,delete first_element";
            cout << "\n\t 2,delete middle";
            cout << "\n\t 3,delete last_element \n";
            cout << "\t 4,back to menu \n";
            cin >> c;
            switch (c) {
            case 1:
                dl.delete_first();
                cout << endl;
                dl.display();
                break;
            case 2:
                cout << "\n\n enter the position of the element to delete\n";
                cin >> pos;
                dl.delete_middle(pos);
                cout << endl;
                dl.display();
                break;
            case 3:
                dl.delete_last();
                cout << endl;
                dl.display();
                break;
            case 4:
                break;

            default:
                cout << "\n wrong choice \n";
            }
            break;

        case 4:
            dl.display();
            break;

        case 5:
            exit(1);

        default:
            cout << "\n wrong choice \n";
        }
    }
    return 0;
}

void linked_llist::create(int value)
{
    struct node* s, * temp;
    temp = new(struct node);
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else {
        s = head;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

void linked_llist::insert_first(int value)
{
    if (head == NULL)
    {
        cout << "first create the list \n";
        return;
    }
    struct node* temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->data = value;
    temp->next = head;
    head->prev = temp;
    head = temp;
    cout << "element inserted :" << value << endl;
}

void linked_llist::insert_position(int value, int pos)
{
    if (head == NULL)
    {
        cout << "first create the list";
        return;
    }
    struct node* temp, * q;
    int i;
    q = head;
    for (i = 0; i < pos - 1; i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout << "there are less than " << pos << " elements. \n";
            return;
        }
    }

    temp = new(struct node);
    temp->data = value;
    if (q->next == NULL)
    {
        q->next = temp;
        temp->next = NULL;
        temp->prev = q;
    }
    else {
        temp->next = q->next;
        temp->next->prev = temp;
        q->next = temp;
        temp->prev = q;
    }
    cout << "element inserted :" << value << endl;
}

void linked_llist::insert_last(int value)
{
    if (head == NULL)
    {
        cout << "first create the list \n";
        return;
    }

    struct node* temp, * last;
    last = head;
    temp = new(struct node);
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
    temp->next = NULL;
    temp->data = value;
    temp->prev = last;
    cout << "element inserted :" << value << endl;
}

void linked_llist::display()
{
    struct node* q;
    if (head == NULL)
    {
        cout << "list empty";
        return;
    }

    q = head;
    cout << "the linked list is :";

    while (q != NULL)
    {
        cout << q->data << "<->";
        q = q->next;
    }
    cout << "NULL \n";
}

void linked_llist::delete_first()
{
    if (head == NULL) {
        cout << "the list is empty";
        return;
    }
    struct node* p;
    p = head;
    head = p->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    cout << "element deleted :" << p->data << endl;
    delete p;
}

void linked_llist::delete_last()
{
    if (head == NULL) {
        cout << "the list is empty";
        return;
    }

    struct node* last, * q;
    last = head;
    if (last->next == NULL) {
        delete last;
        head = NULL;
        cout << "element deleted :" << last->data << endl;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->prev->next = NULL;
    cout << "element deleted :" << last->data << endl;
    delete last;
}

void linked_llist::delete_middle(int pos)
{
    if (head == NULL) {
        cout << "the list is empty";
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            cout << "There are less than " << pos << " elements.\n";
            return;
        }
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp == head) {
        head = temp->next;
    }

    cout << "element deleted :" << temp->data << endl;
    delete temp;
}
