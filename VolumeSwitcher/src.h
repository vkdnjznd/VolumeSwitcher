#pragma once
#include <iostream>
#include <devicetopology.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>

HRESULT GetJackInfo(IMMDevice* pDevice, IKsJackDescription** ppJackDesc);
IMMDevice* GetDefaultDevice();
int GetVolume();
int GetGreenJackCount();
void SetVolume(double volume);