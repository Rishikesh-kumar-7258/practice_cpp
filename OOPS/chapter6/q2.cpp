#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class String{

private:
    char *str;
    int length;

public:
    String();
    String(char *);
    String(String &);

    ~String();

    void concatenate(String &, String &);
    void display() const;
};

class practice{
    int data;

    public:
        practice();
        practice(int val){ data = val;}
        void display() {cout << data << endl;}
};


int main()
{
    String a;
    String b("Namastey Duniya");
    String c = b;

    a.display();
    b.display();
    c.display();

    // practice d1(5);
    // d1.display();

    return 0;
}

String :: String(char *arr)
{
    length = strlen(arr);
    str = new char[length + 1];
    strcpy(str, arr);
}

String :: String()
{
    length = 0;
    str = new char[length + 1];
}

String :: String(String &a)
{
    length = strlen(a.str);
    str = new char[length + 1];
    strcpy(str, a.str);
}

void String :: concatenate(String &a, String &b)
{
    length = a.length + b.length;
    delete str;
    str = new char[length + 1];

    strcpy(str, a.str);
    strcat(str, b.str);

}

String :: ~String()
{
    length = 0;
    delete str;
}