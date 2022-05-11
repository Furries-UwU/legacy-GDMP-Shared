#pragma once
#include <enet/enet.h>
#include <stdexcept>
#include <stdint.h>

void sendPacket(ENetPeer *peer, char* data);
