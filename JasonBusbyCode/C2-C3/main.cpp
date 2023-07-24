#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Level.h"
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

    char GetCharacter() { return _character; }
    bool CanEnter(IEntity& entity) { return _canEnter; }
    void Enter(IEntity& entity) {  }

};

class BasicEntity : public IEntity
{
    char _character;
    Position _position;

public:
    BasicEntity(char ch): _character(ch), _position(0, 0)
    {
    }

    char GetCharacter() { return _character; }
    const Position& GetPosition() { return _position; }
    void SetPosition(const Position& position) { _position = position; }
    void Collide(IEntity& entity) {  }
    void Update() {  }
};


int main(){
    Level level(20, 20);
    BasicTile empty(' ', true);
    BasicTile wall('#', false);

    level.SetTiles(empty, Position(0, 0), Position(19, 19));
    level.SetTiles(wall, Position(0, 0), Position(0, 19));
    level.SetTiles(wall, Position(0, 0), Position(19, 0));
    level.SetTiles(wall, Position(19, 0), Position(19, 19));
    level.SetTiles(wall, Position(0, 19), Position(19, 19));

    level.SetTiles(wall, Position(4, 4), Position(6, 6));

    BasicEntity player('$');
    level.SetEntity(player, Position(1, 1));

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
                level.MoveEntity(player, Position(pos.GetX(), pos.GetY() - 1));
                break;
            case 'a':
                level.MoveEntity(player, Position(pos.GetX() - 1, pos.GetY()));
                break;
            case 's':
                level.MoveEntity(player, Position(pos.GetX(), pos.GetY() + 1));
                break;
            case 'd':
                level.MoveEntity(player, Position(pos.GetX() + 1, pos.GetY()));
                break;
            }
        }
    }


    return 0;
}