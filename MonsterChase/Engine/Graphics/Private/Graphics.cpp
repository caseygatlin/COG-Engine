#include "../Public/Graphics.h"
#include "../Public/RenderData.h"
#include "../../Public/Engine.h"
#include "GLib.h"
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <Windows.h>


namespace Engine
{
    namespace Graphics
    {
        void Init(HINSTANCE i_hInstance, HINSTANCE i_hPrevInstance, LPWSTR i_lpCmdLine, int i_nCmdShow)
        {
            // IMPORTANT: first we need to initialize GLib
            bool bSuccess = GLib::Initialize(i_hInstance, i_nCmdShow, "MonsterChase", -1, 800, 600);

            if (bSuccess)
            {


                // Create a couple of sprites using our own helper routine CreateSprite
                GLib::Sprites::Sprite* texture1 = Engine::Graphics::CreateSprite("Content\\Ship.dds");
                GLib::Sprites::Sprite* texture2 = Engine::Graphics::CreateSprite("Content\\Asteroid.dds");

                RenderData rd1;
                rd1.Init(GetGameObject(0), texture1);

                RenderData rd2;
                rd2.Init(GetGameObject(1), texture2);

                renderData.push_back(rd1);
                renderData.push_back(rd2);

                
            }
        }

        void* LoadFile(const char* i_pFilename, size_t& o_sizeFile)
        {
            assert(i_pFilename != NULL);

            FILE* pFile = NULL;

            errno_t fopenError = fopen_s(&pFile, i_pFilename, "rb");
            if (fopenError != 0)
                return NULL;

            assert(pFile != NULL);

            int FileIOError = fseek(pFile, 0, SEEK_END);
            assert(FileIOError == 0);

            long FileSize = ftell(pFile);
            assert(FileSize >= 0);

            FileIOError = fseek(pFile, 0, SEEK_SET);
            assert(FileIOError == 0);

            uint8_t* pBuffer = new uint8_t[FileSize];
            assert(pBuffer);

            size_t FileRead = fread(pBuffer, 1, FileSize, pFile);
            assert(FileRead == FileSize);

            fclose(pFile);

            o_sizeFile = FileSize;

            return pBuffer;
        }

        GLib::Sprites::Sprite* CreateSprite(const char* i_pFilename)
        {
            assert(i_pFilename);

            size_t sizeTextureFile = 0;

            // Load the source file (texture data)
            void* pTextureFile = LoadFile(i_pFilename, sizeTextureFile);

            // Ask GLib to create a texture out of the data (assuming it was loaded successfully)
            GLib::Texture* pTexture = pTextureFile ? GLib::CreateTexture(pTextureFile, sizeTextureFile) : nullptr;

            // exit if something didn't work
            // probably need some debug logging in here!!!!
            if (pTextureFile)
                delete[] pTextureFile;

            if (pTexture == nullptr)
                return NULL;

            unsigned int width = 0;
            unsigned int height = 0;
            unsigned int depth = 0;

            // Get the dimensions of the texture. We'll use this to determine how big it is on screen
            bool result = GLib::GetDimensions(pTexture, width, height, depth);
            assert(result == true);
            assert((width > 0) && (height > 0));

            // Define the sprite edges
            GLib::Sprites::SpriteEdges	Edges = { -float(width / 2.0f), float(height), float(width / 2.0f), 0.0f };
            GLib::Sprites::SpriteUVs	UVs = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 0.0f, 1.0f }, { 1.0f, 1.0f } };
            GLib::RGBA							Color = { 255, 255, 255, 255 };

            // Create the sprite
            GLib::Sprites::Sprite* pSprite = GLib::Sprites::CreateSprite(Edges, 0.1f, Color, UVs);
            if (pSprite == nullptr)
            {
                GLib::Release(pTexture);
                return nullptr;
            }

            // Bind the texture to sprite
            GLib::Sprites::SetTexture(*pSprite, *pTexture);

            return pSprite;
        }

        void TestKeyCallback(unsigned int i_VKeyID, bool bWentDown)
        {
#ifdef _DEBUG
            const size_t	lenBuffer = 65;
            char			Buffer[lenBuffer];

            sprintf_s(Buffer, lenBuffer, "VKey 0x%04x went %s\n", i_VKeyID, bWentDown ? "down" : "up");
            OutputDebugStringA(Buffer);
#endif // __DEBUG
        }


        void Present()
        {

                // IMPORTANT: Tell GLib that we want to start rendering
                GLib::BeginRendering();
                // Tell GLib that we want to render some sprites
                GLib::Sprites::BeginRendering();


                for (int i = 0; i < renderData.size(); i++)
                {
                    renderData.at(i).Present();
                }


                // Tell GLib we're done rendering sprites
                GLib::Sprites::EndRendering();
                // IMPORTANT: Tell GLib we're done rendering
                GLib::EndRendering();

        }

        void Shutdown()
        {
            for (int i = 0; i < renderData.size(); i++)
            {
                renderData.at(i).ReleaseSprite();
            }

            for (int i = 0; i < renderData.size(); i++)
            {
                renderData.erase(renderData.begin());
            }

            // IMPORTANT:  Tell GLib to shutdown, releasing resources.
            GLib::Shutdown();
        }
    }
}