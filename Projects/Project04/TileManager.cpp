#include "TileManager.h"
#include <SDL2/SDL.h>

TileManager::TileManager(SDL_Renderer* renderer)
    : renderer(renderer) {}

void TileManager::addTile(const Tile& tile) {
    tiles.push_back(tile);
}

void TileManager::drawTiles() const {
    for (const Tile& tile : tiles) {
        
        tile.render(renderer);
    }
}

Tile& TileManager::getTile(int index) {
    return tiles.at(index);  
}

const Tile& TileManager::getTile(int index) const {
    return tiles.at(index);  
}

int TileManager::getNumTiles() const {
    return tiles.size();
}
