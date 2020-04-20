// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/ac/ac_u.h"

namespace Service::AC {

AC_U::AC_U(std::shared_ptr<Module> ac) : Module::Interface(std::move(ac), "ac:u", 10) {
    static const FunctionInfo functions[] = {
        {0x00010000, &AC_U::CreateDefaultConfig, "CreateDefaultConfig"},
        {0x00040006, &AC_U::ConnectAsync, "ConnectAsync"},
        {0x00050002, &AC_U::GetConnectResult, "GetConnectResult"},
        {0x00070002, nullptr, "CancelConnectAsync"},
        {0x00080004, &AC_U::CloseAsync, "CloseAsync"},
        {0x00090002, &AC_U::GetCloseResult, "GetCloseResult"},
        {0x000A0000, nullptr, "GetLastErrorCode"},
        {0x000C0000, nullptr, "GetStatus"},
        {0x000D0000, &AC_U::GetWifiStatus, "GetWifiStatus"},
        {0x000E0042, nullptr, "GetCurrentAPInfo"},
        {0x00100042, nullptr, "GetCurrentNZoneInfo"},
        {0x00110042, nullptr, "GetNZoneApNumService"},
        {0x001D0042, nullptr, "ScanAPs"},
        {0x00240042, nullptr, "AddDenyApType"},
        {0x00270002, &AC_U::GetInfraPriority, "GetInfraPriority"},
        {0x002D0082, &AC_U::SetRequestEulaVersion, "SetRequestEulaVersion"},
        {0x00300004, &AC_U::RegisterDisconnectEvent, "RegisterDisconnectEvent"},
        {0x003C0042, nullptr, "GetAPSSIDList"},
        {0x003E0042, &AC_U::IsConnected, "IsConnected"},
        {0x00400042, &AC_U::SetClientVersion, "SetClientVersion"},
    };
    RegisterHandlers(functions);
}

} // namespace Service::AC

SERIALIZE_EXPORT_IMPL(Service::AC::AC_U)
