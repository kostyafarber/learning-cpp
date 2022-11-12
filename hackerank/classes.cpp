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

    string get_name()
    {
        return m_name;
    }

    int get_fave_number()
    {
        return m_fav_number;
    }
};

int main()
{
    string eyes = "blue";
    string name = "kostya";
    Person me(eyes, name, 4);
    cout << me.get_name() << "'s "
                             "favourite number is "
         << me.get_fave_number() << " who also has " << me.get_eyes() << " eyes" << endl;
    return 0;
}