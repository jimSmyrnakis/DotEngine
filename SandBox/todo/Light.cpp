#include "Light.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
Light::Light(void)
:   m_Position(0.0f) , m_Rotation(0.0f)
{
    
}
Light::~Light(void);

void Light::SetPosition(const glm::vec3 position) { m_Position = position; }
void Light::SetRotation(const glm::vec3 rotation) { m_Rotation = rotation; }
        
glm::vec3 Light::GetPosition(void) const { return m_Position; }
glm::vec3 Light::GetRotation(void) const { return m_Rotation; }

glm::vec3 Light::GetCrossProduct(void) const{
    return glm::cross(position);
}
