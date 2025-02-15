#pragma once 
#include "Mesh.hpp"
#include <glm/glm.hpp> // vec3, vec4, ivec4, mat4
#include <glm/gtc/matrix_transform.hpp> // translate, rotate, scale, perspective

namespace dot{

    class Model{

        public:
            virtual const glm::mat4& GetModelMatrix(void)     const     = 0;
            virtual glm::mat4& GetModelMatrix(void)                     = 0;
            
            

    };
    /*
     *
     *
     * Model : Περιέχει τις βασικές συναρτήσεις που ο renderer θα καλέσει για να πάρει όλα τα δεδομένα για την προβολή του
     * Επιδή ένα μοντέλο μπορεί να αναπαραστή 3D , 2D κλπ αντικείμενα θεωρώ σοφότερο να το φτειάξω ώς μία abstract class 
     * που ορίζει το βασικό σύνολο μεθόδων που παρέχουν όλες τις λεπτομέριες προβολής . Θεωρώ ότι ένα μοντέλο μπορεί να 
     * αποτελείται απο πολλά meshes καθένα το οποίο μπορεί να έχει τους δικόυς του Shader's .
     * 
     *  
    */

    class Model3D : Model{

        public:

            Model3D(const glm::vec3& position = glm::vec3(0.0f) , 
                    const glm::vec3& rotation = glm::vec3(0.0f) ,
                    const glm::vec3& scale    = glm::vec3(1.0f) ) : 
                    Model() , 
                    m_ModelMatrix(1.0f) , 
                    m_Position(position),
                    m_Rotation(rotation),
                    m_Scale(scale)      {
                        
                    }

            inline virtual glm::mat4& GetModelMatrix(void)              override { 
                CalculateModelMatrix();
                return m_ModelMatrix; 
            }
            inline virtual const glm::mat4& GetModelMatrix(void) const  override { 
                CalculateModelMatrix();
                return m_ModelMatrix; 
            }

            inline void SetPosition(const glm::vec3& position) { m_Position = position ;}
            inline void SetRotation(const glm::vec3& rotation) { m_Rotation = rotation ;}
	    inline void SetScale(const glm::vec3& scale)       { m_Scale    = scale    ;}

            inline glm::vec3 GetPosition(void) const { return m_Position; }
            inline glm::vec3 GetRotation(void) const { return m_Rotation; }
            inline glm::vec3 GetScaling(void)  const { return m_Scale;    } 

        private:
            mutable glm::mat4   m_ModelMatrix;
            glm::vec3           m_Position;
            glm::vec3           m_Rotation;
            glm::vec3 		m_Scale   ;
        private:
            inline void CalculateModelMatrix(void) const {
                glm::mat4 translate = glm::translate(glm::mat4(1.0f) , m_Position);
                glm::mat4 rotateX   = glm::rotate(glm::mat4(1.0f) , glm::radians(m_Rotation.x) , glm::vec3(1.0f , 0.0f , 0.0f));
                glm::mat4 rotateY   = glm::rotate(glm::mat4(1.0f) , glm::radians(m_Rotation.y) , glm::vec3(0.0f , 1.0f , 0.0f));
                glm::mat4 rotateZ   = glm::rotate(glm::mat4(1.0f) , glm::radians(m_Rotation.z) , glm::vec3(0.0f , 0.0f , 1.0f));
                glm::mat4 scale     = glm::scale(glm::mat4(1.0f) , m_Scale);
                m_ModelMatrix = translate * rotateY * rotateX * rotateZ  * scale; 
            }
    };
}
