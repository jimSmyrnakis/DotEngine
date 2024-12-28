#include "UbunduWindow.hpp"
#include "../../../Events/ApplicationEvent.hpp"
#include "../../../Events/KeyEvent.hpp"
#include "../../../Events/MouseEvent.hpp"
#include <glad/glad.h>

namespace dot {

    bool UbunduWindow::s_GLFWInitiallized = false;

    Window* Window::Create(const WindowProps& props){
        return new UbunduWindow(props);
    }

    UbunduWindow::UbunduWindow(const WindowProps& props) : Window() { Init(props); }

    UbunduWindow::~UbunduWindow(void) { this->Shutdown(); }

    void UbunduWindow::OnUpdate(void) {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    uint32_t UbunduWindow::GetWidth(void)  const { return m_Data.Width; }
    uint32_t UbunduWindow::GetHeight(void) const { return m_Data.Height;}


    void UbunduWindow::SetEventCallBack(const EventCallBackFn& callback) {
        m_Data.EventCallBack = callback;
    }

    void UbunduWindow::SetVSync(bool enabled) {
        glfwSwapInterval((enabled ? 1 : 0));
        m_Data.VSync = enabled;
    }

    bool UbunduWindow::IsVSync() const { return m_Data.VSync; }

    void UbunduWindow::Init(const WindowProps& props){
        m_Data.Title  = props.Title;
        m_Data.Height = props.Height;
        m_Data.Width  = props.Width;
        //m_Data.EventCallBack  = nullptr;

        DOT_ENGINE_INFO("Creating Ubundu(glfw) Window {0} ({1}, {2})" , m_Data.Title , m_Data.Width , m_Data.Height);

        if (s_GLFWInitiallized == false){
            int success = glfwInit();
            glfwSetErrorCallback(for_glfw_error_event);
            DOT_ENGINE_ASSERT(success , "Can't initiallize the glfw library !");
            s_GLFWInitiallized = true;
        }

        m_Window = glfwCreateWindow(m_Data.Width , m_Data.Height , m_Data.Title.c_str() , nullptr , nullptr);
        glfwMakeContextCurrent(m_Window);

        //try initiallize glad 
        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        DOT_ENGINE_ASSERT(status , "Failed to initiallize glad !!!");

        glfwSetWindowUserPointer(m_Window , &m_Data);
        SetVSync(true);

        // set glfw callbacks
        glfwSetWindowSizeCallback (m_Window , for_glfw_resize_event);
        glfwSetWindowCloseCallback(m_Window , for_glfw_close_event );
        glfwSetKeyCallback        (m_Window , for_glfw_key_events  );
        glfwSetMouseButtonCallback(m_Window , for_glfw_mouse_button_events);
        glfwSetScrollCallback     (m_Window , for_glfw_mouse_scroll_event);
        glfwSetCursorPosCallback  (m_Window , for_glfw_mouse_moved_event );

    }

    void UbunduWindow::Shutdown(void){
        glfwDestroyWindow(m_Window);
    }

    // create glfw specific callbacks functions and pass the events
    void UbunduWindow::for_glfw_resize_event(GLFWwindow* window , int width , int height ){
        //get User Specific data pointers (we send that pointer , we know wtf is that)
        dot::UbunduWindow::WindowData& ourData = *(dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer(window);
        ourData.Width = width;
        ourData.Height = height;
        dot::WindowResizeEvent event(width , height);
        ourData.EventCallBack(event);
    }

    void UbunduWindow::for_glfw_close_event(GLFWwindow* window){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer(window);
        dot::WindowCloseEvent event;
        ourData->EventCallBack(event);
        //glfwDestroyWindow(window);
    }

    void UbunduWindow::for_glfw_key_events (GLFWwindow* window , int key , int scancode , int action , int mode){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer(window);
        
        dot::Event* key_events = nullptr;
        switch(action){
            case GLFW_PRESS: {
                dot::KeyPressedEvent event(key , 0);
                ourData->EventCallBack(event);
                break;
            }
            case GLFW_RELEASE: {
                dot::KeyReleasedEvent event(key);
                ourData->EventCallBack(event);
                break;
            }
            case GLFW_REPEAT: {
                dot::KeyPressedEvent event(key , 1);
                ourData->EventCallBack(event);
                break;
            }
        };

    }

    void UbunduWindow::for_glfw_mouse_button_events (GLFWwindow* window , int key , int action , int mode){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer(window);
        
        switch(action){
            case GLFW_PRESS: {
                dot::MouseButtonPressedEvent event(key , 0);
                ourData->EventCallBack(event);
                break;
            }
            case GLFW_RELEASE: {
                dot::MouseButtonReleasedEvent event(key);
                ourData->EventCallBack(event);
                break;
            }
        };

    }

    void UbunduWindow::for_glfw_mouse_scroll_event  (GLFWwindow* window , double xOffset , double yOffset){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer(window);
        dot::MouseScrolledEvent event((float)xOffset , (float)yOffset);
        ourData->EventCallBack(event);
    }

    void UbunduWindow::for_glfw_mouse_moved_event (GLFWwindow* window , double xPos , double yPos){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer(window);
        dot::MouseMovedEvent event((float)xPos , (float)yPos);
        ourData->EventCallBack(event);
    }

    void UbunduWindow::for_glfw_error_event (int error , const char* description){
        DOT_ENGINE_ERROR(" GLFW Error Code => {0} and GLFW description => {1}" , error , description);
    }

}

