#pragma once

#include <string>

#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include "SDL.h"

#include "../utils/Input.hpp"
#include "../renderer/imgui/imgui_impl_sdl_gl3.hpp"
#include "../renderer/Mesh.hpp"
#include "../renderer/Material.hpp"

using namespace glm;

class Entity
{
public:
    bool debug_control = false;
    std::string name;

    Mesh* mesh = nullptr;

    //Transform
    vec3 position;
    vec3 scale;
    vec3 rotation;

    //Render Properties
    Material material;

    Entity(){

    }

    ~Entity(){

    }

    void draw_debug_inspector(float dt, float control_speed){
        if(ImGui::TreeNode(name.c_str())){
            ImGui::Checkbox("Control", &debug_control);
            if(debug_control){
                float s = control_speed;

                if(Input::get_key_down(SDL_SCANCODE_LSHIFT))
                    s *= 3;

                if(Input::get_key_down(SDL_SCANCODE_W))
                    position.z += control_speed * dt;
                 if(Input::get_key_down(SDL_SCANCODE_A))
                    position.x += control_speed * dt;
                if(Input::get_key_down(SDL_SCANCODE_S))
                    position.z -= control_speed * dt;
                if(Input::get_key_down(SDL_SCANCODE_D))
                    position.x -= control_speed * dt;
                if(Input::get_key_down(SDL_SCANCODE_SPACE))
                    position.y += control_speed * dt;
                if(Input::get_key_down(SDL_SCANCODE_LCTRL))
                    position.y -= control_speed * dt;
            }

            ImGui::DragFloat3("Position"   , &position.x    , 0.1f);
            ImGui::DragFloat3("Scale"      , &scale.x       , 0.1f);
            ImGui::DragFloat3("Rotation"   , &rotation.x    , 0.01f);
            ImGui::ColorEdit3("Color"      , &material.tint.r);
            ImGui::DragFloat ("Specularity", &material.specularity);

            ImGui::TreePop();
        }
    }
};
