//
// Created by Ondřej Měchura on 07/04/2020.
//

#include "Renderer.h"

#include <utility>

using namespace std;

Renderer::Renderer(shared_ptr<World>world) :shouldTerminate(false),worldData(std::move(world)),  threadRunning(false),shouldBeRunning(
        true){

}

 void Renderer::renderThread(Renderer *renderer){

   auto  world = renderer->worldData;

         while (renderer->shouldBeRunning) {
             if(renderer->shouldRender){
                 NCursesManager::lock();

                 clear();

                 int max_y, max_x;
                 getmaxyx(stdscr, max_y, max_x);

                 max_y = (int) (max_y * FRAME_HEIGHT);

                 map<int, shared_ptr<Chunk>>::iterator viewStartX;
                 map<int, shared_ptr<Chunk>>::iterator viewEndX;

                 auto  worldWidth = distance(world->chunks.begin(), world->chunks.end());

                 auto  playerChunkIndex = distance(world->chunks.begin(), world->player->currentChunk);
                 int halfScreenWidth = max_x / 2;

                 if (worldWidth <= max_x) {
                     viewStartX = world->chunks.begin();
                     viewEndX = world->chunks.end();
                 } else {
                     if (playerChunkIndex < halfScreenWidth) {
                         viewStartX = world->chunks.begin();
                         viewEndX = world->chunks.begin();
                         std::advance(viewEndX, max_x);
                     } else if (worldWidth - playerChunkIndex <= halfScreenWidth) {
                         viewEndX = world->chunks.end();
                         viewStartX = world->chunks.end();
                         std::advance(viewStartX, -max_x);
                     } else {
                         viewStartX = world->player->currentChunk;
                         std::advance(viewStartX, -halfScreenWidth);

                         viewEndX = world->player->currentChunk;
                         std::advance(viewEndX, max_x - halfScreenWidth);
                     }
                 }

                 int centerY = max_y / 2;
                 int viewStartY, viewEndY;

                 if (Cache::world_height < max_y) {
                     viewStartY = 0;
                     viewEndY = Cache::world_height;
                 } else {
                     if (world->player->y - centerY < 0) {
                         viewStartY = 0;
                     } else if (world->player->y - centerY >= Cache::world_height - max_y) {
                         viewStartY = Cache::world_height - max_y;
                     } else {
                         viewStartY = world->player->y - centerY;
                     }

                     if (world->player->y + centerY >= Cache::world_height) {
                         viewEndY = Cache::world_height;
                     } else if (world->player->y + centerY <= max_y) {
                         viewEndY = max_y;
                     } else {
                         viewEndY = world->player->y + centerY;
                     }
                 }

                 int renderX = 0, renderY = 0;

                 for (auto x = viewStartX; x != viewEndX; x++) {
                     for (int y = viewStartY; y < viewEndY; y++) {

                         if (x != world->chunks.end() && y >= 0 && y < (int)x->second->content.size()) {

                             auto id = x->second->content[y]->getId();

                             int colorID;

                             if(x->second->content[y]->getSpawnedEntity() == nullptr){
                                 if(id != AIR_ID){
                                     colorID = x->second->content[y]->getColorID();
                                 }else{
                                     colorID = (world->getPhase() == DayPhase::day)?Cache::day_background_color:Cache::night_background_color;
                                 }
                             }else{
                                 colorID = x->second->content[y]->getColorID();
                             }



                                 attron(COLOR_PAIR(colorID));
                                 mvaddch(renderY, renderX, ' ');
                                 attroff(COLOR_PAIR(colorID));


                         }

                         renderY++;
                     }
                     renderY = 0;
                     renderX++;
                 }

                 printw("\n");
                 world->player->print();
                 printw("\n");

                 world->player->getInventory()->printInventory();

                 NCursesManager::refreshContent();
                 NCursesManager::unlock();
             }
             usleep(REFRESH_RATE);
         }
         renderer->threadRunning = false;
}







void Renderer::start() {
    if (!threadRunning && shouldBeRunning) {
        threadRunning = true;
        thr = thread(renderThread, this);
    }
}



void Renderer::terminate() {
    shouldBeRunning = false;
    if (thr.joinable()) {
        thr.join();
    }
}
void Renderer::pauseRendering() {
    shouldRender = false;
}

void Renderer::resumeRendering() {
    shouldRender = true;
}



Renderer::~Renderer() {
     terminate();
}





