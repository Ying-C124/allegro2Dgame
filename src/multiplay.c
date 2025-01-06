#include <myheader.h>

bool init_enet() {
    if (enet_initialize() != 0) {
        fprintf(stderr, "ENet failed to initialize.\n");
        return false;
    }
    return true;
}

ENetHost* create_server(unsigned short port) {
    ENetAddress address;
    enet_address_set_host(&address, "0.0.0.0");
    address.port = port;
    return enet_host_create(&address, 2, 2, 0, 0);
}

ENetHost* create_client() {
    return enet_host_create(NULL, 1, 2, 0, 0);
}

void send_player_state(ENetHost* host, ENetPeer* peer, Player* player, int playerIndex) {
    if (!peer) return;
    ENetPacket* packet;
    float data[4];
    data[0] = (float)player->x;
    data[1] = (float)player->y;
    data[2] = (float)player->verticalSpeed;
    data[3] = (float)playerIndex; 
    packet = enet_packet_create(data, sizeof(data), ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(peer, 0, packet);
    enet_host_flush(host);
}

void receive_updates(ENetHost* host, GameState* gameState) {
    ENetEvent event;
    while (enet_host_service(host, &event, 0) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_RECEIVE: {
                float* data = (float*)event.packet->data;
                int idx = (int)data[3];
                gameState->players[idx].x = data[0];
                gameState->players[idx].y = data[1];
                gameState->players[idx].verticalSpeed = data[2];
                enet_packet_destroy(event.packet);
                break;
            }
            default: break;
        }
    }
}

void shutdown_enet(ENetHost* host) {
    if (host) enet_host_destroy(host);
    enet_deinitialize();
}