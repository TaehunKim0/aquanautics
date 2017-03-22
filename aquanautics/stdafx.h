#pragma once


#define WIN32_LEAN_AND_MEAN

#define WINDOW_TITLE L"aqua"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#if _DEBUG 
#define WINDOW_MODE 1
#else
#define WINDOW_MODE 0
#endif

#define SAFE_DELETE(x) if(x) {delete x; x = nullptr;}
#define SAFE_RELEASE(x) if(x) {x->Release(); x = nullptr;}

#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<assert.h>

#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string>

#include"SingleTon.h"

#include"Object.h"
#include"Scene.h"

