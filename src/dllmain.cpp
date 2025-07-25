// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include "HookHandler.hpp"
#include "EntityList.hpp"
#include "LocalPlayer.hpp"
#include "AimBot.hpp"
#include "OffsetHandler.hpp"
#include "EngineClient.hpp"


void Console(void)
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    freopen_s(&f, "CONIN$", "r", stdin);
    HookHandler& hookHandler = HookHandler::GetInstance();
    hookHandler.LoadInterfaces();
    CEngineClient* engineClient = hookHandler.GetEngineClient();
    std::cout << "Engine Client Address value: " << engineClient << std::endl;
    CEntityList* entityList = hookHandler.GetEntityList();
    std::cout << "EntityList Address: " << entityList << std::endl;
    for (;;)
    {
        if (entityList)
            entityList->PrintEntityList();
        //std::cout << "Unknown 1: " << engineClient->Unknown0001() << std::endl;
        //std::cout << "Unknown 2: " << engineClient->Unknown0002() << std::endl;
        //std::cout << "Unknown 3: " << engineClient->Unknown0003() << std::endl;
        std::cout << "Unknown 4: " << engineClient->Unknown0004() << std::endl;
        //OffsetHandler& offsetHandler = OffsetHandler::GetInstance();
        //uintptr_t health = offsetHandler.GetOffset("DT_Player", "m_iHealth");
        //uintptr_t eyePosOffset = offsetHandler.GetOffset("lol", "lol");
        //std::cout << "Eye Pos Offset: " << eyePosOffset << std::endl;
        //CEntity& entity = CEntity::GetInstance();
        //entity.LoadEnemyList();
        ////entity.PrintEntityList();
        //AimBot aimBot = AimBot::GetInstance();
        //aimBot.AimBotMain();
        //Sleep(1);
        //std::string input;
        //std::cin >> input;
        //if (input == "lookup")
        //{
        //    std::cout << "get View Angle function address: " << (uintptr_t)engineClient->GetVtableFunctionAddress(58) - hookHandler.GetModuleBaseAddress();
        //    ViewAngle viewAngle = engineClient->GetViewAngle();
        //    std::cout << "view angle: " << viewAngle << std::endl;
        //    viewAngle.pitch += 10;
        //    std::cout << "set View Angle function address: " << (uintptr_t)engineClient->GetVtableFunctionAddress(59) - hookHandler.GetModuleBaseAddress();
        //    engineClient->SetViewAngle(viewAngle);
        //}
        //else if (input == "lookright")
        //{
        //    std::cout << "get View Angle function address: " << (uintptr_t)engineClient->GetVtableFunctionAddress(58) - hookHandler.GetModuleBaseAddress();
        //    ViewAngle viewAngle = engineClient->GetViewAngle();
        //    std::cout << "view angle: " << viewAngle << std::endl;
        //    viewAngle.yaw += 10;
        //    std::cout << "set View Angle function address: " << (uintptr_t)engineClient->GetVtableFunctionAddress(59) - hookHandler.GetModuleBaseAddress();
        //    engineClient->SetViewAngle(viewAngle);
        //}

        /*if (input == "exit")
            break;
        if (input == "moveup")
        {
            CLocalPlayer& localPlayer = CLocalPlayer::GetInstance();
            localPlayer.GetPosition()->z += 10;
        }
        if (input == "movedown")
        {
            CLocalPlayer& localPlayer = CLocalPlayer::GetInstance();
            localPlayer.GetPosition()->z -= 100;
        }*/
        /*if (input == "print")
        {
            CLocalPlayer& localPlayer = CLocalPlayer::GetInstance();
            localPlayer.PrintPlayerInfo();
        }
        else if (input == "lookup")
        {
            CLocalPlayer& localPlayer = CLocalPlayer::GetInstance();
            ViewAngle* viewAngle = localPlayer.GetCameraViewAngle();
            viewAngle->pitch += 10;
        }
        else if (input == "lookright")
        {
            CLocalPlayer& localPlayer = CLocalPlayer::GetInstance();
            ViewAngle* viewAngle = localPlayer.GetCameraViewAngle();
            viewAngle->yaw += 10;
        }
        else if (input == "printEntity")
        {
            CEntity& entity = CEntity::GetInstance();
            entity.LoadEnemyList();
            entity.PrintEntityList();
        }*/
    }
    FreeConsole();
}

void Hook()
{
    HookHandler& hookHandler = HookHandler::GetInstance();
    //hookHandler.HookMain();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    //HookHandler* hookHandle = HookHandler::GetInstance();
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Console, nullptr, 0, nullptr);
        //CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Hook, nullptr, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    //HookHandler::DeleteInstance();
    return TRUE;
}

