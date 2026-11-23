#include <mod/amlmod.h>
#include <mod/logger.h>

MYMOD(net.user.freeaimctrl, FreeAimCtrl, 1.0.0, user)

static void* hGTASA = nullptr;
static void (*orig1)(void*) = nullptr;
static void (*orig2)(void*, void*, bool) = nullptr;

static void hook1(void* self) {}
static void hook2(void* self, void* e, bool d) {}

static bool HookSym(const char* sym, void* hook, void** orig)
{
    void* addr = aml->GetSym(hGTASA, sym);
    if (!addr) { logger->Error("Symbol not found: %s", sym); return false; }
    aml->Hook(addr, hook, orig);
    logger->Info("Hooked: %s", sym);
    return true;
}

extern "C" void OnModLoad()
{
    logger->SetTag("FreeAimCtrl");
    hGTASA = aml->GetLibHandle("libGTASA.so");
    if (!hGTASA) return;
    HookSym("_ZN10CPlayerPed22FindWeaponLockOnTargetEv", (void*)hook1, (void**)&orig1);
    HookSym("_ZN10CPlayerPed26FindNextWeaponLockOnTargetEP7CEntityb", (void*)hook2, (void**)&orig2);
}
