
#include "ImguiLayer.hpp"
#include "../../Application.hpp"
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#define BIND_EVENT_FUN(x) DOT_ENGINE_BIND_FN(ImguiLayer , x) 
//std::bind(&ImguiLayer::x , this , std::placeholders::_1)

ImGuiKey ImGui_ImplGlfw_KeyToImGuiKey(int keycode, int scancode);

dot::ImguiLayer::ImguiLayer(void): Layer("Imgui Layer") {

}

dot::ImguiLayer::~ImguiLayer(void){

}

void dot::ImguiLayer::OnAttach(void) {
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // enable keyboard controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // enable gamepad controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;     // enable docking
    io.ConfigFlags &= ~ImGuiConfigFlags_ViewportsEnable;   // enable viewports - not possible for wayland :(
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable){
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    dot::Application& app = dot::Application::Get();
    GLFWwindow* win = (GLFWwindow*)app.GetWindow().GetNativeWindow();

    ImGui_ImplGlfw_InitForOpenGL(win , true);
    ImGui_ImplOpenGL3_Init("#version 410");

}

void dot::ImguiLayer::OnDetach(void) {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}


void dot::ImguiLayer::OnImGuiRender(void) {
    
    
    static bool show = true;
    ImGui::ShowDemoWindow(&show);

}

void dot::ImguiLayer::Begin(void){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
      
    
}

void dot::ImguiLayer::End(void){
    ImGuiIO& io = ImGui::GetIO();
    dot::Application& app = dot::Application::Get();
    io.DisplaySize = ImVec2(app.GetWindow().GetWidth() , app.GetWindow().GetHeight());

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable){
        GLFWwindow* win = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(win);
    }
}