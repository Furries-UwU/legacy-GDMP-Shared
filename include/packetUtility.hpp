#pragma once
#include <packet.pb.h>
#include <enet/enet.h>
#include <vector>

class PacketUtility {
    static void sendPacket(Packet, ENetPeer*);
};