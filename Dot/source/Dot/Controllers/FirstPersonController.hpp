#pragma once
#include "../Core.hpp"
#include "../Renderer/Camera.hpp"

namespace dot{
    class FirstPersonController{ // TODO
        public:
            FirstPersonController(PerspectiveCamera& camera);
            ~FirstPersonController(void) ;

            PerspectiveCamera&          GetCamera(void) ;
            const PerspectiveCamera&    GetCamera(void) const ;
            
            float GetMoveSpeed(void)    const;
            float GetRotateSpeed(void)  const;
            float GetDeltaTime(void)    const;
            float GetZoom(void)         const;

            void  SetMoveSpeed(float speed);
            void  SetRotateSpeed(float speed);
            void  SetDeltaTime(float deltaTimeSec);
            void  SetZoom(float zoomLevel);

            void MoveLeft(void) ;
            void MoveUp(void)   ;
            void MoveRight(void);
            void MoveDown(void) ;
            void MoveFront(void);
            void MoveBack(void) ;

            void RotateLeft(void)   ;
            void RotateRight(void)  ;
            void RotateUp(void)     ;
            void RotateDown(void)   ;


        private:
            PerspectiveCamera*  m_Camera;
            float               m_MoveSpeed;
            float               m_RotateSpeed;
            float               m_DeltaTime;
            float               m_Zoom;
    };
}