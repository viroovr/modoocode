#include <iostream>
#include <string.h>

class Photon_Cannon {
    int hp, shield;
    int coord_x, coord_y;
    int damage;

    char *name;

    public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(int x, int y, const char * cannon_name);
    ~Photon_Cannon();

    void showStatus();

};

Photon_Cannon::Photon_Cannon(int x, int y){
    std::cout << "생성자 호출" << std::endl;
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;
}
Photon_Cannon::Photon_Cannon(int x, int y, const char *cannon_name){
    hp = shield = 100;
    coord_x = x;
    coord_y = y;
    damage = 20;

    name = new char[strlen(cannon_name)+1];
    strcpy(name, cannon_name);
}
Photon_Cannon::~Photon_Cannon(){
    if (name)

    {
        delete[] name;
    }
    
}
void Photon_Cannon::showStatus(){
    std::cout << "Photon_Cannon " << std::endl;
    std::cout << " Location : ( " <<coord_x << " , " << coord_y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;

    pc1.showStatus();
    pc2.showStatus();
    
}

