#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Person
{
    string firstName;
    string lastName;
    string address;
    string groups;

    Person() {}
    Person(string firstName, string lastName, string address, string groups)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->address = address;
        this->groups = groups;
    }
};

typedef map<string, Person> PhoneBook;
typedef pair<string, Person> PhoneBookElement;

void PrintPhoneBook(PhoneBook phoneBook)
{
    for (auto item : phoneBook)
    {
        cout << item.first << " - ";
        cout << item.second.lastName << " " << item.second.firstName << endl;
        cout << item.second.address << endl;
        cout << item.second.groups << endl;
        cout << endl;
    }
}

PhoneBookElement Input()
{
    string phone, firstName, lastName, address, groups;

    cout << "Введите номер телефона: ";
    cin >> phone;
    cout << "Введите имя: ";
    cin >> firstName;
    cout << "Введите фамилию: ";
    cin >> lastName;
    cout << "Введите адрес: (Страна, область, город, улица, номер дома, квартира) ";
    getline(cin, address);
    cout << "Введите группы: (их может быть несколько)";
    getline(cin, groups);
    Person person(firstName, lastName, address, groups);

    PhoneBookElement phoneBookElement(phone, person);
    return phoneBookElement;
}

int main()
{
    system("chcp 65001");

    map<string, Person> phoneBook;

    char select;
    do
    {
        phoneBook.insert(Input());

        cout << "Желаете ли ввести ещё данные? ";
        cin >> select;
    } while (select == 'Y' || select == 'y');

    PrintPhoneBook(phoneBook);

    return