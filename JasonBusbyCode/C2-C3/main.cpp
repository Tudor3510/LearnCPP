#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Level.h"
#include "SingleProjectile.h"
#include "Player.h"
#include "Fireball.h"
#include "WeaponPickupTile.h"
#include "MultiFireball.h"
#include "Enemy.h"
#include "HealthPickupTile.h"

using namespace std;

class BasicTile : public ITile
{
private:
    char _character;
    bool _canEnter;

public:
    BasicTile(char ch, bool canEnter) : _character(ch), _canEnter(canEnter)
    {
    }

    char GetCharacter() const override { return _character; }
    bool CanEnter(IEntity& entity) override { return _canEnter; }
    void Enter(IEntity& entity) override {  }

};

class BasicEntity : public IEntity
{
    char _character;
    Vector2 _Vector2;

public:
    BasicEntity(char ch): _character(ch), _Vector2(0, 0)
    {
    }

    char GetCharacter() const override { return _character; }
    const Vector2& GetPosition() const override { return _Vector2; }
    void SetPosition(const Vector2& position) override { _Vector2 = position; }
    void Collide(IEntity& entity) override {  }
    void Update() override {  }
};


int main(){
    Level level(50, 20);

    BasicTile empty(' ', true);
    BasicTile wall('#', false);
    HealthPickupTile health('+', 100);
    WeaponPickupTile weapon1('%', new MultiFireball('^', level, 30));

    level.SetTiles(empty, Vector2(0, 0), Vector2(49, 19));
    level.SetTiles(wall, Vector2(0, 0), Vector2(0, 19));
    level.SetTiles(wall, Vector2(0, 0), Vector2(49, 0));
    level.SetTiles(wall, Vector2(49, 0), Vector2(49, 19));
    level.SetTiles(wall, Vector2(0, 19), Vector2(49, 19));

    level.SetTiles(wall, Vector2(4, 4), Vector2(6, 6));

    level.SetTile(weapon1, Vector2(8, 8));
    level.SetTile(health,Vector2(1, 1));

    auto player = new Player(level, '$');
    player->SetWeapon(new Fireball('*', level, 20));

    level.SetEntity(player, Vector2(1, 2));

    
    auto e1 = new Enemy(level, '!');
    e1->SetWeapon(new Fireball('*', level, 20));
    auto e2 = new Enemy(level, '!');
    e2->SetWeapon(new Fireball('*', level, 20));
    auto e3 = new Enemy(level, '!');
    e3->SetWeapon(new Fireball('*', level, 20));

    level.SetEntity(e1, Vector2(30, 15));
    level.SetEntity(e2, Vector2(31, 15));
    level.SetEntity(e3, Vector2(32, 15));
    


    level.RenderAll();

    char input = '\0';
    auto lastTime = timeGetTime();
    while(input != 27)
    {
        if (level.HasLevelEnded())
        {
            cout << "you died!";
            break;
        }

        auto currentElapsed = timeGetTime() - lastTime;
        if(currentElapsed > 33.3)
        {
            lastTime = timeGetTime();
            level.Update();
        }

        if (_kbhit())
        {
            input = _getch();

            auto pos = player->GetPosition();
            switch (input)
            {
            case 'w':
                player->Move(Vector2::North);
                break;
            case 'a':
                player->Move(Vector2::West);
                break;
            case 's':
                player->Move(Vector2::South);
                break;
            case 'd':
                player->Move(Vector2::East);
                break;
            case ' ':
                player->FireProjectile();
                break;
            }
        }
    }


    return 0;
}