#include "packetUtility.hpp"


void PacketUtility::sendPacket(ISteamNetworkingSockets* interface, HSteamNetConnection connection, const Packet &packet)
{
    if (interface == nullptr)
        return;
    const char* pData = packet.SerializeAsString().c_str();
    interface->SendMessageToConnection(connection, pData, (uint32)strlen(pData), k_nSteamNetworkingSend_Reliable, nullptr);
}

void PacketUtility::sendPacket(ISteamNetworkingSockets* interface, HSteamNetConnection connection, const IncomingPacket &packet)
{
    if (interface == nullptr)
        return;
    const char* pData = packet.SerializeAsString().c_str();
    interface->SendMessageToConnection(connection, pData, (uint32)strlen(pData), k_nSteamNetworkingSend_Reliable, nullptr);
}