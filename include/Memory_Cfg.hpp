#pragma once

inline const char* netVarOffsetSig = "4C 8B 1D ? ? ? ? 4D 85 DB 74 19";

inline const char* createInterfaceOffsetSig = "0F 84 92 00 00 00 33 D2 48 8D 0D ? ? ? ? FF 15";

inline const char* numEntitesOffsetSig = "48 8B 1D ? ? ? ? 48 8B C3";

inline const char* inputOffsetSig = "48 8B 05 ? ? ? ? 48 8D 0D ? ? ? ? 44 0F B6 CB";

inline const char* engineClientOffsetSig = "48 83 3D ? ? ? ? ? 48 8D 05 ? ? ? ? 48 89 05 ? ? ? ? 48 8D 0D ? ? ? ? 48 8D 05 ? ? ? ? 48 89 0D ? ? ? ?"; // 39

inline const char* gameMovementOffsetSig = "48 89 05 ? ? ? ? 48 85 C9 74 0D";