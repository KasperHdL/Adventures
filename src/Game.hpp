#pragma once

#include <string>
#include <vector>

#include "Engine.hpp"
#include "God.hpp"
#include "utils/SceneLoader.hpp"
#include "game/Player.hpp"


class Game{
    public:
        Engine* engine;
        Player* player;

        Game(){}
        ~Game(){}

        std::vector<Entity*> ents;

        void initialize(Engine* engine){
            this->engine = engine;
            player = new Player();
            player->entity->position = vec3(-3.3,-1.3,11.3);
            player->entity->rotation = vec3(0.15,6.5,0);

            SceneLoader::load_scene("standard.scene");
            God::entities[God::entities.count-1]->material.specularity = 0;

            Light* sun =  new (God::lights.create()) Light(Light::Type::Directional, vec3(0,-1,.25f), vec3(0,.1f,.5f), .15f);
            sun->set_ortho_scale(15);

            Light* l = new (God::lights.create()) Light(Light::Type::Spot, vec3(0,5,-10.2f),vec3(0,-0.01,.015),0, vec3(1,1,.8f), 1);
            l->create_shadow_map = true;
            l->falloff = 15;
            l->intensity = 1;
            l->attenuation = vec3(1, 0.1f, 0.001f);
            l->calc_influence_mesh();

        }

        float time = 0;

        void update(float delta_time){
            time += delta_time;

            player->update(delta_time);
        }

        void draw_debug(){


        }

};
