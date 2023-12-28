#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
    string name;
    int age;
    float height;

public:
    string getName() { return name; }
    int getAge() { return age; }
    float getHeight() { return height; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setHeight(float height) { this->height = height; }

    Human(int age, string name, float height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

template <typename T>
bool isCorrect(T& value)
{
    while (true)
    {
        cin >> value;
        if (cin.good())
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
        else
        {
            cout << "Incorrect value. Try again. " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main()
{
    string name;
    int age;
    float height;
    cout << "Standart Human " << endl;

    Human human(17, "Jack", 182.3);
    cout << "Name: " << human.getName() << endl;
    cout << "Age: " << human.getAge() << endl;
    cout << "Height: " << human.getHeight() << endl
        << endl;

    cout << "Enter your name: ";
    isCorrect(name);
    human.setName(name);

    cout << "Enter your age: ";
    isCorrect(age);
    human.setAge(age);

    cout << "Enter your height: ";
    isCorrect(height);
    human.setHeight(height);

    cout << endl;
    cout << "Your human" << endl
        << endl;
    cout << "Name: " << human.getName() << endl;
    cout << "Age: " << human.getAge() << endl;
    cout << "Height: " << human.getHeight() << endl;

    return 0;
}