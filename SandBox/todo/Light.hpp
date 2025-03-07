#include <stdint.h>
#include <stddef.h>
#include <glm/glm.hpp>

class Light{

    public:
        Light(void);
        ~Light(void);

        void SetPosition(const glm::vec3 position);
        void SetRotation(const glm::vec3 rotation);
        
        glm::vec3 GetPosition(void) const;
        glm::vec3 GetRotation(void) const;

        glm::vec3 GetCrossProduct(void) const;

    private:
        glm::vec3 m_Position;
        glm::vec3 m_Rotation;

}