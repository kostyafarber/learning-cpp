#include <iostream>

using namespace std;
// learning classes

// useful link for classes https://courses.engr.illinois.edu/cs225/sp2022/resources/inheritance/

class Person
{
private: // specifier if we can access it from outside the class or not
    string m_eyes;
    string m_name;
    int m_fav_number;

public:
    Person(string eyes, string name, int fav_number)
        : m_eyes(eyes), m_name(name), m_fav_number(fav_number) {}

    string get_eyes()
    {
        return m_eyes;
    }

    string get_name() const
    {
        return m_name;
    }

    int get_fave_number() const
    {
        return m_fav_number;
    }
};

void hello_msg(const Person &person) {
    cout << "Hey there " << person.get_name() << ". It's cool your favourite number is: " << person.get_fave_number() << endl;
}

void hello_msg(Person *person) {
    cout << "Hey there " << person->get_name() << ". It's cool your favourite number is: " << person->get_fave_number() << endl;
}

int main()
{
    string eyes = "blue";
    string name = "kostya";
    Person me(eyes, name, 4);
    cout << me.get_name() << "'s "
                             "favourite number is "
         << me.get_fave_number() << " who also has " << me.get_eyes() << " eyes" << endl;

    Person *kostya_ptr = nullptr;
    kostya_ptr = &me;

    cout << "Printing pointer to me object: " << kostya_ptr << endl;
    cout << kostya_ptr->get_name() << endl; // using -> notation

    hello_msg(&me);
    cout << endl;
    hello_msg(kostya_ptr);


    cout << sizeof(me) << endl; // consider passing by reference, quite large
    long long large_num;
    cout << sizeof(large_num); // above object is 7x bigger than a long long. 

    return 0;
}