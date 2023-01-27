#include <iostream>

class String {
    char* str;
    int len;

    public:
        String(const char *new_str);
        String(const String& copy_str);
        String(const char c, int new_len);
        
        int strlen() { return len;}
        void strcat(const char *add_str);
        char* strstr(const char *find_str);
        int strsame(const char* cmp_str);
        int strcmp(const char* cmp_str);

        void showstr() { std::cout << str << std::endl;}
        ~String() { 
            std::cout << str << "의 소멸자 호출!" <<std::endl;
            delete[] str;
        };
};

int getStringLength(const char *str){
    int count = 0;
    for(int i=0; str[i] != '\0';i++){
        count ++;
    }
    return count;
}


String::String(const char *new_str){
    int new_len = getStringLength(new_str);
    str = new char[new_len+1];
    for (int i = 0; i <= new_len; i++)
    {
        str[i] = new_str[i];
    }
    len = new_len;
}
String::String(const String& copy_str){
    len = copy_str.len;
    str = new char[len+1];
    for (int i = 0; i <= len; i++)
    {
        str[i] = copy_str.str[i];
    }
}

String::String(const char c, int new_len){
    str = new char[new_len+1];
    int i;
    for (i = 0; i < new_len; i++)
    {
        str[i] = c;
    }
    str[i] = '\0';
    len = new_len;
}
void String::strcat(const char *add_str){
    int new_len = getStringLength(add_str);
    char * prev_string = str;
    str = new char[new_len + len + 1];
    int i;
    for ( i = 0; i < len; i++)
    {
        str[i] = prev_string[i];
    }
    for (i; i <= len+new_len; i++)
    {
        str[i] = add_str[i-len];
    }
    delete[] prev_string;
    len = new_len+len;
}

char* String::strstr(const char *find_str){
    int find_len = getStringLength(find_str);
    char *ret = NULL;
    bool find = false;
    for (int i = 0 ; !find && i <= len - find_len; i++)
    {
        int j=0;
        for ( int temp = i; str[temp] == find_str[j] && temp < i+find_len && j < find_len; temp++, j++);
        if( j ==find_len){
                ret = str+i;
                find = true;
        }
    }
    return ret;
}

int String::strsame(const char *cmp_str){
    int cmp_len = getStringLength(cmp_str);
    if(len != cmp_len) return -1;
    int i;
    for (i = 0; str[i] == cmp_str[i] && i < len; i++);
    if(i == len) return 1;
    else return -1;
}

int String::strcmp(const char *cmp_str){
    int cmp_len = getStringLength(cmp_str);
    int i;
    int new_len = (len < cmp_len) ? len : cmp_len;
    for ( i = 0; i < new_len; i++)
    {
        if(str[i] > cmp_str[i]) return 1;
        else if (str[i] < cmp_str[i]) return -1;
    }
    if(len == cmp_len) return 0;
    else if( len > cmp_len) return 1;
    else  return -1;
}

int main(){
    String str1("c++");
    String str2(str1);
    String str3('c', 10);

    str1.showstr();
    str2.showstr();
    str3.showstr();

    str1.strcat(" python");
    std::cout << str1.strlen() << std::endl;
    str1.showstr();

    std::cout << str1.strcmp("c++ python") << std::endl;
    std::cout << str1.strcmp("c++ java") << std::endl;
    std::cout << str1.strsame("c++ python") << std::endl;
    std::cout << str1.strsame("c++ java") << std::endl;
    std::cout << str1.strstr("python") << std::endl;
    
}