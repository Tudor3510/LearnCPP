#include "Level.h"
#include <iostream>
#include <Windows.h>
using namespace std;



Level::Level(int width, int height)
    : _width(width), _height(height), _tiles(width * height), _isUpdating(false)
{
}

int Level::GetWidth() const { return _width; }
int Level::GetHeight() const { return _height; }

void Level::SetTile(ITile& tile, Vector2 pos)
{
    auto index = GetIndexForXY(pos.GetX(), pos.GetY());
    _tiles[index] = &tile;
}

void Level::SetTiles(ITile& tile, Vector2 from, Vector2 to)
{
    for (auto x = from.GetX(); x <= to.GetX(); x++)
    {
        for (auto y = from.GetY(); y <= to.GetY(); y++)
        {
            _tiles[GetIndexForXY(x, y)] = &tile;
        }
    }
}

void Level::SetEntity(IEntity* entity, Vector2 pos)
{
    auto tile = _tiles[GetIndexForXY(pos.GetX(), pos.GetY())];
    if (!tile->CanEnter(*entity))
    {
        return;
    }

    _entities.push_back(entity);
    entity->SetPosition(pos);

    SetCharacter(entity->GetCharacter(), pos.GetX(), pos.GetY());
}

void Level::RemoveEntity(IEntity* entity)
{
    if (_isUpdating)
    {
        _entitiesToRemove.push_back(entity);
        return;
    }

    Vector2 position = entity->GetPosition();
    auto tile = _tiles[GetIndexForXY(position.GetX(), position.GetY())];

    for (auto i = _entities.begin(); i != _entities.end(); i++)
    {
        if (*i != entity)
            continue;

        _entities.erase(i);
        break;
    }

    SetCharacter(tile->GetCharacter(), position.GetX(), position.GetY());
}

bool Level::MoveEntity(IEntity& entity, Vector2 pos)
{
    if (pos.GetX() < 0 || pos.GetX() >= _width || pos.GetY() < 0 || pos.GetY() >= _height)
        return false;

    auto tileToEnter = _tiles[GetIndexForXY(pos.GetX(), pos.GetY())];
    if (!tileToEnter->CanEnter(entity))
        return false;

    tileToEnter ->Enter(entity);

    auto oldPos = entity.GetPosition();
    auto oldTile = _tiles[GetIndexForXY(oldPos.GetX(), oldPos.GetY())];

    SetCharacter(oldTile->GetCharacter(), oldPos.GetX(), oldPos.GetY());
    SetCharacter(entity.GetCharacter(), pos.GetX(), pos.GetY());

    entity.SetPosition(pos);

    return true;    
}

void Level::RenderAll()
{
    for (auto x = 0; x < _width; x++)
    {
        for (auto y = 0; y < _height; y++)
        {
            auto tile = _tiles[GetIndexForXY(x, y)];
            SetCharacter(tile->GetCharacter(), x, y);
        }
    }

    for (auto i = _entities.begin(); i != _entities.end(); i++)
    {
        auto entity = *i;
        const Vector2& pos = entity->GetPosition();
        SetCharacter(entity->GetCharacter(), pos.GetX(), pos.GetY());
    }
}

void Level::Update()
{
    _isUpdating = true;

    for (auto i = _entities.begin(); i != _entities.end(); i++)
        (*i)->Update();

    _isUpdating = false;

    for (auto i = _entitiesToRemove.begin(); i != _entitiesToRemove.end(); i++)
        RemoveEntity(**i);

    _entitiesToRemove.clear();
}

int Level::GetIndexForXY (int x, int y) const
{
    return _width * y + x;
}

void Level::SetCharacter(char ch, int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
    cout    <<  ch;
}