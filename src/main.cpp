#include "main.h"

#include <stdio.h>

ModMeta __stdcall GetModInfo() {
    static ModMeta meta = {
        "Background Render",
        "BgRender",
        "1.0.0",
        "Kapilarny"
    };

    return meta;
}

typedef __int64(__fastcall* sub_744E70)(__int64 a1, int a2);
sub_744E70 sub_744E70_Original;

__int64 __fastcall sub_744E70_Hook(__int64 a1, int a2) {
    return 0;
}

void __stdcall ModInit() {
    JAPI_LogInfo("Loaded!");

    Hook hook = {
        (void*)0x744EC0,
        (void*)sub_744E70_Hook,
        (void**)&sub_744E70_Original,
    };

    if(!JAPI_HookASBRFunction(&hook)) {
        JAPI_LogError("Failed to hook function!");
    }
}