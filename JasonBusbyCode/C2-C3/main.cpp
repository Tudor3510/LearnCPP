#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Level.h"
#include "SingleProjectile.h"
#include "Player.h"
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

    char GetCharacter() const { return _character; }
    bool CanEnter(IEntity& entity) { return _canEnter; }
    void Enter(IEntity& entity) {  }

};

class BasicEntity : public IEntity
{
    char _character;
    Vector2 _Vector2;

public:
    BasicEntity(char ch): _character(ch), _Vector2(0, 0)
    {
    }

    char GetCharacter() const { return _character; }
    const Vector2& GetPosition() const { return _Vector2; }
    void SetPosition(const Vector2& position) { _Vector2 = position; }
    void Collide(IEntity& entity) {  }
    void Update() {  }
};


int main(){
    Level level(20, 20);
    BasicTile empty(' ', true);
    BasicTile wall('#', false);

    level.SetTiles(empty, Vector2(0, 0), Vector2(19, 19));
    level.SetTiles(wall, Vector2(0, 0), Vector2(0, 19));
    level.SetTiles(wall, Vector2(0, 0), Vector2(19, 0));
    level.SetTiles(wall, Vector2(19, 0), Vector2(19, 19));
    level.SetTiles(wall, Vector2(0, 19), Vector2(19, 19));

    level.SetTiles(wall, Vector2(4, 4), Vector2(6, 6));

    Player player(level, '$');
    level.SetEntity(player, Vector2(1, 1));

    level.RenderAll();

    char input = '\0';
    auto lastTime = timeGetTime();
    while(input != 27)
    {
        auto currentElapsed = timeGetTime() - lastTime;
        if(currentElapsed > 33.3)
        {
            lastTime = timeGetTime();
            level.Update();
        }

        if (_kbhit())
        {
            input = _getch();

            auto pos = player.GetPosition();
            switch (input)
            {
            case 'w':
                player.Move(Vector2::North);
                break;
            case 'a':
                player.Move(Vector2::West);
                break;
            case 's':
                player.Move(Vector2::South);
                break;
            case 'd':
                player.Move(Vector2::East);
                break;
            case ' ':
                player.FireProjectile();
                break;
            }
        }
    }


    return 0;
}