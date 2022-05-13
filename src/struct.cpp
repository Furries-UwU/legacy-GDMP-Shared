#include "struct.hpp"

void to_json(json& j, const ServerPlayerData& p) {
	j = json{ {"username", p.username}, {"ship", p.ship}, {"ball", p.ball}, {"bird", p.bird}, {"dart", p.dart}, {"robot", p.robot}, {"spider", p.spider}, {"glow", p.glow}, {"color", p.color}, {"color2", p.color2} };
}

void from_json(const json& j, ServerPlayerData& p) {
	j.at("username").get_to(p.username);
	j.at("ship").get_to(p.ship);
	j.at("ball").get_to(p.ball);
	j.at("bird").get_to(p.bird);
	j.at("dart").get_to(p.dart);
	j.at("robot").get_to(p.robot);
	j.at("spider").get_to(p.spider);
	j.at("glow").get_to(p.glow);
	j.at("color").get_to(p.color);
	j.at("color2").get_to(p.color2);
}

void to_json(json& j, const ClientPlayerData& p) {
	j = json{ {"playerId", p.playerId}, {"username", p.username}, {"ship", p.ship}, {"ball", p.ball}, {"bird", p.bird}, {"dart", p.dart}, {"robot", p.robot}, {"spider", p.spider}, {"glow", p.glow}, {"color", p.color}, {"color2", p.color2} };
}

void from_json(const json& j, ClientPlayerData& p) {
	j.at("playerId").get_to(p.playerId);
	j.at("username").get_to(p.username);
	j.at("ship").get_to(p.ship);
	j.at("ball").get_to(p.ball);
	j.at("bird").get_to(p.bird);
	j.at("dart").get_to(p.dart);
	j.at("robot").get_to(p.robot);
	j.at("spider").get_to(p.spider);
	j.at("glow").get_to(p.glow);
	j.at("color").get_to(p.color);
	j.at("color2").get_to(p.color2);
}