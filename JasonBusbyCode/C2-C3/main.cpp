#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
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
    ifstream levelStream ("level");
    if(!levelStream)
    {
        cout << "Can not find level" << '\n';
        system("pause");
        return 1;
    }

    vector<string> levelMap;
    int levelWidth = 0;
    while(!levelStream.eof())
    {
        string line;
        getline(levelStream, line);
        levelWidth = levelWidth < line.size() ? levelWidth : line.size();
        levelMap.push_back(line);
    }

    levelStream.close();
    Level level(levelWidth, levelMap.size());

    BasicTile empty(' ', true);
    BasicTile wall('#', false);
    HealthPickupTile health('+', 100);
    WeaponPickupTile weapon1('%', new MultiFireball('^', level, 30));

    Player* player = NULL;

    for (auto y = 0; y < levelMap.size(); y++)
    {
        auto line = levelMap[y];
        for (auto x = 0; x < levelWidth; x++)
        {
            char currentCell = x < line.size() ? line[x] : ' ';
            switch (currentCell)
            {
            default:
                level.SetTile(empty, Vector2(x, y));
            case '#':
                level.SetTile(wall, Vector2(x, y));
                break;
            case '+':
                level.SetTile(health, Vector2(x, y));
                break;
            case '%':
                level.SetTile(weapon1, Vector2(x, y));
                break;
            case '$':
                level.SetTile(empty, Vector2(x, y));
                level.SetEntity(player = new Player(level, '$'), Vector2(x, y));
                break;
            case '!':
                level.SetTile(empty, Vector2(x, y));

                Enemy* enemy = NULL;
                level.SetEntity(enemy = new Enemy(level, '!'), Vector2(x, y));
                enemy->SetWeapon(new Fireball('*', level, 20));
                break;
            }
        }

    }


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