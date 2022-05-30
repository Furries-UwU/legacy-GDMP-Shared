#pragma once
#include <steam/steamnetworkingsockets.h>
#include <steam/isteamnetworkingutils.h>
#include <packet.pb.h>
#include <vector>

class PacketUtility {
public:
    static void sendPacket(ISteamNetworkingSockets*, HSteamNetConnection, const Packet&);
    static void sendPacket(ISteamNetworkingSockets*, HSteamNetConnection, const IncomingPacket&);
};