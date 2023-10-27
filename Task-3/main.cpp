#include <iostream>
#include <string>

using namespace std;

class Contact {

private:

    string name;
    string phoneNumber;
    string emailAddress;
    Contact* prev;
    Contact* next;

public:

    Contact(const string& n, const string& phone, const string& email) : name(n), phoneNumber(phone), emailAddress(email), prev(nullptr), next(nullptr) {}

    string getName() const {
        return name;
    }
    string getPhoneNumber() const {
        return phoneNumber;
    }
    string getEmailAddress() const {
        return emailAddress;
    }
    Contact* getPrev() const {
        return prev;
    }
    Contact* getNext() const {
        return next;
    }

    void setName(const string& n) {
        name = n;
    }
    void setPhoneNumber(const string& phone) {
        phoneNumber = phone;
    }
    void setEmailAddress(const string& email) {
        emailAddress = email;
    }
    void setPrev(Contact* p) {
        prev = p;
    }
    void setNext(Contact* n) {
        next = n;
    }
};

class ContactList {

private:

    Contact* head;

public:

    ContactList() : head(nullptr) {}
    ~ContactList() {
        clearContacts();
    }

    void addContact(const string& name, const string& phoneNumber, const string& emailAddress) {
        Contact* newContact = new Contact(name, phoneNumber, emailAddress);

        if (head == nullptr) {
            head = newContact;
        }
        else {
            Contact* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newContact);
            newContact->setPrev(current);
        }

        cout << "\n-----Contact added successfully!-----\n";
    }
    void displayContacts() const {
        if (head == nullptr) {
            cout << "Contact list is empty.\n";
        }
        else {
            cout << "----------------\n";
            cout << "| Contact List |\n";
            cout << "----------------\n\n";
            const Contact* current = head;
            while (current != nullptr) {
                cout << "Name: " << current->getName() << "\n";
                cout << "Phone Number: " << current->getPhoneNumber() << "\n";
                cout << "Email Address: " << current->getEmailAddress() << "\n\n";
                current = current->getNext();
            }
        }
    }
    void deleteContact(const string& name) {
        if (head == nullptr) {
            cout << "\nContact list is empty.\n";
        }
        else {
            Contact* current = head;
            while (current != nullptr) {
                if (current->getName() == name) {
                    if (current->getPrev() != nullptr) {
                        current->getPrev()->setNext(current->getNext());
                    }
                    else {
                        head = current->getNext();
                    }

                    if (current->getNext() != nullptr) {
                        current->getNext()->setPrev(current->getPrev());
                    }

                    delete current;
                    cout << "\n-----Contact deleted successfully!-----\n\n";
                    return;
                }
                current = current->getNext();
            }
            cout << "\nContact not found.\n";
        }
    }
    void editContact(const string& name) {
        if (head == nullptr) {
            cout << "\nContact list is empty.\n";
        }
        else {
            Contact* current = head;
            while (current != nullptr) {
                if (current->getName() == name) {
                    string newPhoneNumber, newEmailAddress;
                    cout << "Enter new phone number: ";
                    cin >> newPhoneNumber;
                    current->setPhoneNumber(newPhoneNumber);
                    cout << "Enter new email address: ";
                    cin >> newEmailAddress;
                    current->setEmailAddress(newEmailAddress);
                    cout << "\n-----Contact edited successfully!-----\n\n";
                    return;
                }
                current = current->getNext();
            }
            cout << "Contact not found.\n";
        }
    }
    void clearContacts() {
        while (head != nullptr) {
            Contact* temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

int main() {
    
    ContactList contactList;

    int choice;
    string name, phoneNumber, emailAddress = "";

    cout << endl;    

    do {        
        cout << "-----------------------------" << endl;
        cout << "| Contact Management System |" << endl;
        cout << "-----------------------------" << endl;

        cout << endl;               

        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Edit Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        switch (choice) {
        case 1:
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Phone Number: ";
            cin >> phoneNumber;
            cout << "Enter Email Address: ";
            cin >> emailAddress;
            contactList.addContact(name, phoneNumber, emailAddress);
            break;
        case 2:
            contactList.displayContacts();
            break;
        case 3:
            cout << "Enter Name of contact to edit: ";
            cin >> name;
            contactList.editContact(name);
            break;
        case 4:
            cout << "Enter Name of contact to delete: ";
            cin >> name;
            contactList.deleteContact(name);
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid Choice! Please Enter Again.\n";
        }

    } while (choice != 5);

    return 0;
}