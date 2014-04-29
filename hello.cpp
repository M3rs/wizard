// barebones load lua and do a file
#include <iostream>
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int main ()
{
    lua_State * L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dofile(L,"t.lua");
    lua_close(L);
}
