#include "ck_scripting.h"
#include <iostream>

extern "C" {
#include "../../src/vendor/luajit/src/lua.h"
#include "../../src/vendor/luajit/src/lualib.h"
#include "../../src/vendor/luajit/src/lauxlib.h"
}

// lua state global pointer, lives as long as game lives
lua_State* gLuaState = nullptr;

void ckScriptingInit() {
    std::cout << "[CK] Initializing LuaJIT backend..." << std::endl;

    gLuaState = luaL_newstate();
    if (gLuaState != nullptr) {
        luaL_openlibs(gLuaState);

        // try execute sample lua script
        int status = luaL_dofile(gLuaState, "mods/userspace/test.lua");
        if (status != 0) {
            std::cerr << "[CK] Lua Error: " << lua_tostring(gLuaState, -1) << std::endl;
        }
    } else {
        std::cerr << "[CK] Failed to initialize LuaJIT state!" << std::endl;
    }
}

void ckScriptingExit() {
    if (gLuaState != nullptr) {
        std::cout << "[CK] Shutting down LuaJIT backend..." << std::endl;
        lua_close(gLuaState);
        gLuaState = nullptr;
    }
}
