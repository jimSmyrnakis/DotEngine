
#include "UbunduWindow.hpp"
#include "../../../Events/ApplicationEvent.hpp"
#include "../../../Events/KeyEvent.hpp"
#include "../../../Events/MouseEvent.hpp"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>


void for_glfw_resize_event(void* window , int width , int height ){
        //get User Specific data pointers (we send that pointer , we know wtf is that)
        dot::UbunduWindow::WindowData& ourData = *(dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        ourData.Width = width;
        ourData.Height = height;
        dot::WindowResizeEvent event(width , height);
        ourData.EventCallBack(event);
}


namespace dot {

    bool UbunduWindow::s_GLFWInitiallized = false;

    Window* Window::Create(const WindowProps& props){
        return new UbunduWindow(props);
    }

    UbunduWindow::UbunduWindow(const WindowProps& props) : Window()  { Init(props); }

    UbunduWindow::~UbunduWindow(void) { this->Shutdown(); }

    void UbunduWindow::OnUpdate(void) {
        
        
        m_Context->SwapBuffers();

        /* Poll for and process events */
        glfwPollEvents();

        

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
        

        if (s_GLFWInitiallized == false){
            int success = glfwInit();
            glfwSetErrorCallback(for_glfw_error_event);
            DOT_ENGINE_ASSERT(success , "Can't initiallize the glfw library !");
            
            s_GLFWInitiallized = true;
        }

        m_Window = glfwCreateWindow(m_Data.Width , m_Data.Height , m_Data.Title.c_str() , nullptr , nullptr);
        m_Context = new OpenGLContext(m_Window);
        m_Context->Init();

        glfwSetWindowUserPointer((GLFWwindow*)m_Window , &m_Data);
        SetVSync(true);
        // set glfw callbacks
        glfwSetWindowSizeCallback ((GLFWwindow*)m_Window , (void(*)(GLFWwindow*,int,int))for_glfw_resize_event);
        glfwSetWindowCloseCallback((GLFWwindow*)m_Window , (void(*)(GLFWwindow*))for_glfw_close_event );
        glfwSetKeyCallback        ((GLFWwindow*)m_Window , (void(*)(GLFWwindow*,int,int,int,int))for_glfw_key_events  );
        glfwSetMouseButtonCallback((GLFWwindow*)m_Window , (void(*)(GLFWwindow*,int,int,int))for_glfw_mouse_button_events);
        glfwSetScrollCallback     ((GLFWwindow*)m_Window , (void(*)(GLFWwindow*,double,double))for_glfw_mouse_scroll_event);
        glfwSetCursorPosCallback  ((GLFWwindow*)m_Window , (void(*)(GLFWwindow*,double,double))for_glfw_mouse_moved_event );
        glfwSetCharCallback       ((GLFWwindow*)m_Window , (void(*)(GLFWwindow*,unsigned int))for_glfw_key_typed_event   );

    }

    void UbunduWindow::Shutdown(void){
        glfwDestroyWindow((GLFWwindow*)m_Window);
    }

   /* // create glfw specific callbacks functions and pass the events
    void UbunduWindow::for_glfw_resize_event(void* window , int width , int height ){
        //get User Specific data pointers (we send that pointer , we know wtf is that)
        dot::UbunduWindow::WindowData& ourData = *(dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        ourData.Width = width;
        ourData.Height = height;
        dot::WindowResizeEvent event(width , height);
        ourData.EventCallBack(event);
    }
*/
    void UbunduWindow::for_glfw_close_event(void* window){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        dot::WindowCloseEvent event;
        ourData->EventCallBack(event);
        //glfwDestroyWindow(window);
    }

    void UbunduWindow::for_glfw_key_events (void* window , int key , int scancode , int action , int mode){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        
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

    void UbunduWindow::for_glfw_key_typed_event(void* window , unsigned int character){
        auto* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        dot::KeyTypedEvent e(character);
        ourData->EventCallBack(e);

    }

    void UbunduWindow::for_glfw_mouse_button_events (void* window , int key , int action , int mode){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        
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

    void UbunduWindow::for_glfw_mouse_scroll_event  (void* window , double xOffset , double yOffset){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        dot::MouseScrolledEvent event((float)xOffset , (float)yOffset);
        ourData->EventCallBack(event);
    }

    void UbunduWindow::for_glfw_mouse_moved_event (void* window , double xPos , double yPos){
        dot::UbunduWindow::WindowData* ourData = (dot::UbunduWindow::WindowData*)glfwGetWindowUserPointer((GLFWwindow*)window);
        dot::MouseMovedEvent event((float)xPos , (float)yPos);
        ourData->EventCallBack(event);
    }

    void UbunduWindow::for_glfw_error_event (int error , const char* description){
        DOT_ENGINE_ERROR(" GLFW Error Code => {0} and GLFW description => {1}" , error , description);
    }

    void* UbunduWindow::GetNativeWindow(void) const {
        return m_Window;
    }

}

