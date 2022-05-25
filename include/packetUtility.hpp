#pragma once
#include <packet.pb.h>
#include <enet/enet.h>
#include <vector>

class PacketUtility {
public:
    static void sendPacket(Packet, ENetPeer*);
};