//
// Created by mechuon1 on 3/23/23.
//

#include "Game.h"

Game::Game(bool &res) {
    this->world = make_shared<World>();
    this->player = this->world->spawnPlayer();
    this->renderer = make_shared<Renderer>(world);
    res = true;
}

Game::Game(bool& res , string& saveData) {

    // init world;
  if(!GameLoader::loadGame(saveData, this->world, this->player)){
      res = false;
      return;
  }

    // init renderer
    this->renderer = make_shared<Renderer>(this->world);

    res = true;
}


// main game loop
void Game::Run() {
    if(this->renderer == nullptr){ return;}

    // run renderer
    this->renderer->start();



    auto actionTimeStamp =  chrono::system_clock::now();
    auto dayTimeTimeStamp = chrono::system_clock::now();


    while (true) {
        if(this->state == GAME_TERMINATED){
            this->renderer->terminate();
            clear();
            return;
        }

        // get current time
        auto current_time = chrono::system_clock::now();

        // trigger for periodic actions
        auto actionDuration = chrono::duration_cast<chrono::seconds>(current_time - actionTimeStamp).count();
        if (actionDuration >= PERIODIC_ACTION_INTERVAL) {
            for(auto &e : this->world->getEntities()){
                if(!e->isDead()){
                    e->moveRandom();
                }
                if(!this->player->jumpTimer->running()){
                    this->player->freeFall();
                }
            }
            actionTimeStamp = current_time;
        }

        // day phase checker
        auto dayPhaseDuration = chrono::duration_cast<chrono::minutes>(current_time - dayTimeTimeStamp).count();
        if(dayPhaseDuration >= DAY_PHASE_SWITCH_INTERVAL){
            this->world->switchDayPhase();
            dayTimeTimeStamp = current_time;
        }


        // Actions handler
       auto  act = Controller::getAction();
       if(act != nullopt){

           switch (act.value()) {
               case Action::moveJump:this->jump(); break;
               case Action::moveLeft:this->leftMove();break;
               case Action::moveRight:this->rightMove();break;
               case Action::actionUp:this->actionUp();break;
               case Action::actionDown:this->actionDown();break;
               case Action::actionLeft:this->actionLeft();break;
               case Action::actionRight:this->actionRight();break;
               case Action::controlQuit:this->quitGame();break;
               case Action::controlSave:this->saveGame();break;
               case Action::option0:this->inventorySelect(0);break;
               case Action::option1:this->inventorySelect(1);break;
               case Action::option2:this->inventorySelect(2);break;
               case Action::option3:this->inventorySelect(3);break;
               case Action::option4:this->inventorySelect(4);break;
               case Action::option5:this->inventorySelect(5);break;
               case Action::option6:this->inventorySelect(6);break;
               case Action::option7:this->inventorySelect(7);break;
               case Action::option8: this->inventorySelect(8);break;
               case Action::option9: this->inventorySelect(9); break;
               case Action::gameInventory:this->openInventory(); break;
               case Action::contextNext:this->selectInventoryNext();break;
               case Action::contextBack:this->selectInventoryPrev();break;
               case Action::gameCrafting:this->openCrafting(); break;
               default:break;
           }
       }

        // Finish game if player died
        if (this->player->death != nullptr) {
            auto  screen = make_shared<MessageScreen>(this->player->death->cause());
            this->openScreen(screen);
            return;
        }
    }
}

// controls
void Game::leftMove() {
    if(this->world == nullptr){ return;}
    this->world->moveLeft(this->player);
}
void Game::rightMove() {
    if(this->world == nullptr){ return;}
    this->world->moveRight(this->player);
}
void Game::jump() {
    if(this->world == nullptr){ return;}
    this->world->moveUp(this->player);
}

void Game::actionLeft() {
    if(this->player == nullptr || this->world == nullptr){ return;}
    this->player->getInventory()->useSelected(this->world, this->player,MoveDirection::left);
}
void Game::actionRight() {
    if(this->player == nullptr || this->world == nullptr){ return;}
    this->player->getInventory()->useSelected(this->world,this->player,MoveDirection::right);
}
void Game::actionUp() {
    if(this->player == nullptr || this->world == nullptr){ return;}
    this->player->getInventory()->useSelected(this->world,this->player,MoveDirection::up);
}
void Game::actionDown() {
    if(this->player == nullptr || this->world == nullptr){ return;}
    this->player->getInventory()->useSelected(this->world,this->player,MoveDirection::down);
}


void Game::inventorySelect(int index) {
    if(this->player == nullptr){ return;}
    this->player->getInventory()->selectAtIndex(index);
}

void Game::selectInventoryNext() {
    if(this->player == nullptr){ return;}
    this->player->getInventory()->selectNext();
}

void Game::selectInventoryPrev() {
    if(this->player == nullptr){ return;}
    this->player->getInventory()->selectPrev();
}


void Game::openInventory() {
    auto  screen = make_shared<InventoryScreen>(this->player->getInventory());
    this->openScreen(screen);
}

void Game::openCrafting() {
    auto  screen = make_shared<CraftingScreen>(this->player->getInventory());
    this->openScreen(screen);
}

void Game::openScreen(const shared_ptr<Screen>& screen) {
    this->renderer->pauseRendering();
    clear();
    screen->Run();
    clear();
    this->renderer->resumeRendering();
}




void Game::quitGame() {
    this->state = GAME_TERMINATED;
}
void Game::saveGame() {
    string data = this->toString();
    bool res = FileSaver::saveData(data,SAVE_FILE_NAME);
    string msg = (res) ? SAVE_SUCCESS:SAVE_FAILURE;
    auto screen = make_shared<MessageScreen>(msg);
    this->openScreen(screen);
}


string Game::toString() {
    string content;
    content += this->world->toString();
    content+=PRIMARY_DELIMETER;
    content+= this->player->toString();
    content+=PRIMARY_DELIMETER;
    content+= this->world->entitiesToString();
    return content;
}



Game::~Game() = default;



