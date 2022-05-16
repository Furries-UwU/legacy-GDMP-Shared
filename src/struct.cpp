#include "struct.hpp"

void to_json(json &j, const Position &p) {
    j = json{{"x", p.x},
             {"y", p.y}};
};

void from_json(const json &j, Position &p) {
    j.at("x").get_to(p.x);
    j.at("y").get_to(p.y);
};

void to_json(json &j, const IconData &p) {
    j = json{{"cubeId",   p.cubeId},
             {"shipId",   p.shipId},
             {"ballId",   p.ballId},
             {"ufoId",    p.ufoId},
             {"waveId",   p.waveId},
             {"robotId",  p.robotId},
             {"spiderId", p.spiderId}};
};

void from_json(const json &j, IconData &p) {
    j.at("cubeId").get_to(p.cubeId);
    j.at("shipId").get_to(p.shipId);
    j.at("ballId").get_to(p.ballId);
    j.at("ufoId").get_to(p.ufoId);
    j.at("waveId").get_to(p.waveId);
    j.at("robotId").get_to(p.robotId);
    j.at("spiderId").get_to(p.spiderId);
};

void to_json(json &j, const ColorData &p) {
    j = json{{"primaryColor",   p.primaryColor},
             {"secondaryColor", p.secondaryColor},
             {"glow",           p.glow}};
};

void from_json(const json &j, ColorData &p) {
    j.at("primaryColor").get_to(p.primaryColor);
    j.at("secondaryColor").get_to(p.secondaryColor);
    j.at("glow").get_to(p.glow);
};

void to_json(json &j, const BaseRenderData &p) {
    j = json{{"position", p.position},
             {"rotation", p.rotation},
             {"scale",    p.scale},
             {"isShip",   p.isShip},
             {"isBall",   p.isBall},
             {"isUFO",    p.isUFO},
             {"isWave",   p.isWave},
             {"isRobot",  p.isRobot},
             {"isSpider", p.isSpider}};
}

void from_json(const json &j, BaseRenderData &p) {
    j.at("position").get_to(p.position);
    j.at("rotation").get_to(p.rotation);
    j.at("scale").get_to(p.scale);
    j.at("isShip").get_to(p.isShip);
    j.at("isBall").get_to(p.isBall);
    j.at("isUFO").get_to(p.isUFO);
    j.at("isWave").get_to(p.isWave);
    j.at("isRobot").get_to(p.isRobot);
    j.at("isSpider").get_to(p.isSpider);
};

void to_json(json &j, const RenderData &p) {
    j = json{{"playerOne", p.playerOne},
             {"playerTwo", p.playerTwo},
             {"isDual",    p.isDual},
             {"isVisible", p.isVisible}};
}

void from_json(const json &j, RenderData &p) {
    j.at("playerOne").get_to(p.playerOne);
    j.at("playerTwo").get_to(p.playerTwo);
    j.at("isDual").get_to(p.isDual);
    j.at("isVisible").get_to(p.isVisible);
}

void to_json(json &j, const IncomingIconData &p) {
    j = json{{"playerId", p.playerId},
             {"iconData", p.iconData}};
}

void from_json(const json &j, IncomingIconData &p) {
    j.at("playerId").get_to(p.playerId);
    j.at("iconData").get_to(p.iconData);
}

void to_json(json &j, const IncomingColorData &p) {
    j = json{{"playerId",  p.playerId},
             {"colorData", p.colorData}};
}

void from_json(const json &j, IncomingColorData &p) {
    j.at("playerId").get_to(p.playerId);
    j.at("colorData").get_to(p.colorData);
}

void to_json(json &j, const IncomingRenderData &p) {
    j = json{{"playerId",   p.playerId},
             {"renderData", p.renderData}};
};

void from_json(const json &j, IncomingRenderData &p) {
    j.at("playerId").get_to(p.playerId);
    j.at("renderData").get_to(p.renderData);
};

void to_json(json &j, const IncomingUsername &p) {
    j = json{{"playerId", p.playerId},
             {"username", p.username}};
};

void from_json(const json &j, IncomingUsername &p) {
    j.at("playerId").get_to(p.playerId);
    j.at("username").get_to(p.username);
};