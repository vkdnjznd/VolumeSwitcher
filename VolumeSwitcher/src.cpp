#include "pch.h"
#include <devicetopology.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <math.h>

#define EXIT_ON_ERROR(hres)  \
              if (FAILED(hres)) { goto Exit; }
#define SAFE_RELEASE(punk)  \
              if ((punk) != NULL)  \
                { (punk)->Release(); (punk) = NULL; }

HRESULT GetJackInfo(IMMDevice* pDevice,
    IKsJackDescription** ppJackDesc)
{
    HRESULT hr = S_OK;
    IDeviceTopology* pDeviceTopology = NULL;
    IConnector* pConnFrom = NULL;
    IConnector* pConnTo = NULL;
    IPart* pPart = NULL;
    IKsJackDescription* pJackDesc = NULL;

    if (NULL != ppJackDesc)
    {
        *ppJackDesc = NULL;
    }
    if (NULL == pDevice || NULL == ppJackDesc)
    {
        return E_POINTER;
    }

    // Get the endpoint device's IDeviceTopology interface.
    hr = pDevice->Activate(__uuidof(IDeviceTopology), CLSCTX_ALL,
        NULL, (void**)&pDeviceTopology);
    EXIT_ON_ERROR(hr)

        // The device topology for an endpoint device always
        // contains just one connector (connector number 0).
        hr = pDeviceTopology->GetConnector(0, &pConnFrom);
    EXIT_ON_ERROR(hr)

        // Step across the connection to the jack on the adapter.
        hr = pConnFrom->GetConnectedTo(&pConnTo);
    if (HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND) == hr)
    {
        // The adapter device is not currently active.
        hr = E_NOINTERFACE;
    }
    EXIT_ON_ERROR(hr)

        // Get the connector's IPart interface.
        hr = pConnTo->QueryInterface(__uuidof(IPart), (void**)&pPart);
    EXIT_ON_ERROR(hr)

        // Activate the connector's IKsJackDescription interface.
        hr = pPart->Activate(CLSCTX_INPROC_SERVER,
            __uuidof(IKsJackDescription), (void**)&pJackDesc);
    EXIT_ON_ERROR(hr)

        * ppJackDesc = pJackDesc;

Exit:
    SAFE_RELEASE(pDeviceTopology)
        SAFE_RELEASE(pConnFrom)
        SAFE_RELEASE(pConnTo)
        SAFE_RELEASE(pPart)
        return hr;
}

IMMDevice* GetDefaultDevice() {
    HRESULT hr;

    hr = CoInitialize(NULL);
    IMMDeviceEnumerator* deviceEnumerator = NULL;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID*)&deviceEnumerator);
    IMMDevice* defaultDevice = NULL;

    hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    deviceEnumerator = NULL;

    return defaultDevice;
}

int GetGreenJackCount() {
    HRESULT hr;

    IMMDevice* device = GetDefaultDevice();
    IKsJackDescription* IKD = NULL;
    hr = GetJackInfo(device, &IKD);
    if (hr != S_OK) {
        return -1;
    }

    UINT jackCnt;
    hr = IKD->GetJackCount(&jackCnt);

    KSJACK_DESCRIPTION pDescription;
    int greenJackCount = 0;
    for (UINT i = 0; i < jackCnt; i++) {
        hr = IKD->GetJackDescription(i, &pDescription);
        COLORREF color = pDescription.Color;
        if ((int)GetGValue(color) == 255)
            greenJackCount++;
    }

    device->Release();
    device = NULL;

    IKD->Release();
    IKD = NULL;

    CoUninitialize();
    return greenJackCount;
}



int GetVolume() {
    HRESULT hr;

    IMMDevice* defaultDevice = GetDefaultDevice();
    IAudioEndpointVolume* endpointVolume = NULL;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
    defaultDevice->Release();
    defaultDevice = NULL;

    float currentVolume = 0;
    hr = endpointVolume->GetMasterVolumeLevelScalar(&currentVolume);

    endpointVolume->Release();

    int ret = ceil(currentVolume * 100);
    return ret;
}

void SetVolume(double volume) {
    HRESULT hr;

    IMMDevice* defaultDevice = GetDefaultDevice();
    IAudioEndpointVolume* endpointVolume = NULL;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID*)&endpointVolume);
    defaultDevice->Release();
    defaultDevice = NULL;

    float newVolume = volume / 100.0;
    hr = endpointVolume->SetMasterVolumeLevelScalar(newVolume, NULL);

    endpointVolume->Release();
}