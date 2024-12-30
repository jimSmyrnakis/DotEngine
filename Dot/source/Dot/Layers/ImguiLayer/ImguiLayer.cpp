#include "ImguiLayer.hpp"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include "../../Application.hpp"

dot::ImguiLayer::ImguiLayer(void): Layer("Imgui Layer") {

}

dot::ImguiLayer::~ImguiLayer(void){

}

void dot::ImguiLayer::OnAttach(void) {
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    ImGui_ImplOpenGL3_Init("#version 430");

}

void dot::ImguiLayer::OnDetach(void) {

}

void dot::ImguiLayer::OnUpdate(void) {

    ImGuiIO& io = ImGui::GetIO();
    float time = (float)glfwGetTime();
    io.DeltaTime = ((m_Time > 0.0f) ? (time - m_Time) : (1.0f/60.0f) );
    m_Time = time;
    dot::Application& app = dot::Application::Get();
    io.DisplaySize = ImVec2(app.GetWindow().GetWidth() , app.GetWindow().GetHeight());
    

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();


    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

} 

void dot::ImguiLayer::OnEvent(dot::Event& event) {

}