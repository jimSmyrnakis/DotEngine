#pragma once
#include <stdint.h>
#include <stddef.h>
#include <string>
#include <vector>
#include "MeshSettings.hpp"
#include "RenderApi/Shader.hpp"
#include "RenderApi/Buffer.hpp"
#include "../Core.hpp"

namespace dot{

    /*
    *
    *
    * Περιγραφή : Σκοπός της κλάσσης Mesh είναι να μπορεί να γενικεύση την προβολή ενός 3D αντικειμένου στην οθόνη 
    * μέσω αποστολής του στον renderer μας , με όσο γενικευμένο τρόπο μπορώ να σκεφτώ προς στιγμήν , ώστε κάποιος να μπορεί 
    * να γράψει Shaders με μεγάλη ελευθερία στην αποστολή και παραλαβή δεδομένων  , όπως πίνακες μετασχηματισμού , ίσος δεδομένα 
    * που μπορεί να ορίζουν Animation's και αλλά και χωρίς χρήση προκαθορισμένων Shaders  . Με άλλα λόγια , δεν θέλω να έχουμε ένα 
    * σύνολο απο διαφορετικούς Shaders που να αναγκάζει κάποιων να περιοριστή σε αυτούς για την κατασκευή του παιχνιδιού αλλά να του
    * δίνεται η ελευθερία να ορίση αυτός τους Shaders του (έναν για κάθε mesh) και τις επιπλέον πληροφορίες και δεδομένα του Mesh και να κάνει ότι θέλει 
    * με αυτά .
    * 
    *  
    */




    class Mesh{

        public:
        Mesh(void) : m_Shader(nullptr) , m_Settings() , m_VA(nullptr) {}
        ~Mesh(void) {} // will not delete them as they may be shared beetween multiple Meshes

        inline void SetShader(Shader& shad) { m_Shader = &shad;}
        inline void SetSettings(const MeshSettings& settings) { m_Settings = settings;}
        inline void SetVertexArray(VertexArray& va) { m_VA = &va;}

        inline Shader& GetShader(void) { 
            DOT_ENGINE_ASSERT(m_Shader , "No Shader for the mesh has set !");
            return (*m_Shader);
        }
        inline const Shader& GetShader(void) const {
            DOT_ENGINE_ASSERT(m_Shader , "No Shader for the mesh has set !");
            return (*m_Shader);
        }
        
        inline MeshSettings& GetSettings(void) { return m_Settings ; }
        inline const MeshSettings& GetSettings(void) const { return m_Settings; }

        inline VertexArray&  GetVertexArray(void) {
            DOT_ENGINE_ASSERT(m_VA , "No Vertex Array for the mesh has set !");
            return (*m_VA);
        }
        inline const VertexArray&  GetVertexArray(void) const {
            DOT_ENGINE_ASSERT(m_VA , "No Vertex Array for the mesh has set !");
            return (*m_VA);
        }

        private:
            Shader*      m_Shader  ;  
            MeshSettings m_Settings;
            VertexArray* m_VA      ;
    };
}
