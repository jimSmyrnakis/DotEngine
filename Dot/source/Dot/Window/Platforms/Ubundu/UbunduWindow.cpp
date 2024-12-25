#include "UbunduWindow.hpp"



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
        m_Data.EventCallBack  = nullptr;

        DOT_ENGINE_INFO("Creating Ubundu(glfw) Window {0} ({1}, {2})" , m_Data.Title , m_Data.Width , m_Data.Height);

        if (s_GLFWInitiallized == false){
            int success = glfwInit();
            DOT_ENGINE_ASSERT(success , "Can't initiallize the glfw library !");
            s_GLFWInitiallized = true;
        }

        m_Window = glfwCreateWindow(props.Width , props.Height , m_Data.Title.c_str() , nullptr , nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window , &m_Data);
        SetVSync(true);
    }

    void UbunduWindow::Shutdown(void){
        glfwDestroyWindow(m_Window);
    }

}