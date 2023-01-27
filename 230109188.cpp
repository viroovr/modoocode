#include <iostream>
#include <string.h>

class String{
    char *str;
    int len;

    public:
    String(char c, int n);
    String(const char *s);
    String(const String &s);
    ~String();


    void showString(){
        std::cout << str << std::endl;
    }
    void addString(const String &s);
    void copyString(const String &s);
};

String::String(char c, int n){
    str = new char[n+1];
    len = n;
    for (int i = 0; i < n; i++)
    {
        str[i] = c;
    }
    str[n] = '\0';
}

String::String(const char *s){
    len = strlen(s);
    str = new char[len+1];
    strcpy(str, s);
}

String::String(const String &s){
    len = s.len;
    str = new char[len+1];
    strcpy(str, s.str);
}
String::~String()
{
    std::cout << str << "의 소멸자 호출!" << std::endl;
    delete[] str;
}
void String::addString(const String &s)
{
    len = len + s.len;
    std::cout << len << std::endl;
    char *temp = new char[len+1];
    strcpy(temp, str);
    strcat(temp, s.str);
    delete[] str;
    str = temp;
}
void String::copyString(const String &s)
{
    len = s.len;
    char *temp = new char[len+1];
    strcpy(temp, s.str);
    delete[] str;
    str = temp;
}

int main()
{
    String str1 = String('u', 5);
    String str2 = String("Starcraft is fun!");
    String str3 = String(str2);

    str1.showString();
    str2.showString();
    str3.showString();

    str1.addString(str2);
    str1.showString();

    str3.copyString(str1);
    str3.showString();

}