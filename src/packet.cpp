#include "packet.hpp"

Packet::Packet(uint8_t type, unsigned int length, uint8_t *data)
{
    this->type = type;
    this->length = length;
    this->data = data;
}

Packet::Packet(ISteamNetworkingMessage *incomingMessage)
{
    uint8_t *data = (uint8_t *)incomingMessage->m_pData;

    if (incomingMessage->m_cbSize < 5)
    {
        this->type = UNKNOWN;
        this->length = 0;
        this->data = nullptr;
    }
    else if (incomingMessage->m_cbSize == 5)
    {
        this->type = data[0];
        this->length = 0;
        this->data = nullptr;
    }
    else
    {
        this->type = data[0];
        this->length = data[1] | (data[2] << 8) | (data[3] << 16) | (data[4] << 24); // Util::uint_8_t_to_int doesn't work here for some reason
        this->data = data + 5;
    }
}

const uint8_t &Packet::operator[](int index)
{
    if (!index)
    {
        return this->type;
    }
    else if (index < 5)
    {
        return reinterpret_cast<uint8_t *>(&this->length)[index - 1];
    }
    else if (index < this->length + 5)
    {
        return this->data[index - 5];
    }
    else
    {
        throw std::out_of_range("Out of packet range");
    }
}

void Packet::send(ISteamNetworkingSockets *nInterface, HSteamNetConnection connection)
{
    int length = this->length + 5;

    uint8_t *data = new uint8_t[length];

    for (unsigned int i = 0; i < length; i++)
    {
        data[i] = this->operator[](i);
    }

    nInterface->SendMessageToConnection(connection, data, length, k_nSteamNetworkingSend_Reliable, nullptr);

    delete[] data;
}