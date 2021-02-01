#pragma once
#pragma comment (lib, "dsound.lib")
#pragma comment (lib, "legacy_stdio_definitions.lib")
#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <set>
#include <functional>
#include <string>
#include <time.h>
#include <chrono>
#include <algorithm>
#include "SDKsound.h"

using namespace std;
using namespace chrono;

using Vector2 = D3DXVECTOR2;
using Vector3 = D3DXVECTOR3;
using Vector4 = D3DXVECTOR4;
using Matrix = D3DXMATRIX;
using Quaternion = D3DXQUATERNION;
using Time = system_clock::time_point;
using Tag = int;

const static float WINSIZEX = 1920.0f;
const static float WINSIZEY = 1080.0f;

const static float GLOBALGRAVITY = 9.81f;
const static float BASEFLOOR = 0.f;

#define gDevice DXUTGetD3D9Device()
#define GetNowTime system_clock::now()
#define DeltaTime DXUTGetElapsedTime()

#ifdef _DEBUG()
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log)
#endif 

template <typename T>
void Lerp(T* target, const T& start, const T& end, float speed)
{
	*target = start + (end - start) * speed;
}
#pragma comment (linker, "/entry:wWinMainCRTStartup /subsystem:console")

#include "MeshLoader.h"
#include "Object.h"
#include "Collider.h"
#include "Scene.h"
#include "Schedule.h"
#include "Frame.h"

#include "ImageManager.h"
#include "CameraManager.h"
#include "CollisionManager.h"
#include "ObjectManager.h"
#include "SceneManager.h"	
#include "InputManager.h"
//#include "SoundManager.h"
#include "GameManager.h"
#include "FXManager.h"