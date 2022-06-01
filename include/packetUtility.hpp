#pragma once
#include <enet/enet.h>
#include <packet.pb.h>
#include <vector>

class PacketUtility {
public:
    static void sendPacket(ENetPeer*, const Packet&);
    static void sendPacket(ENetPeer*, const IncomingPacket&);
};