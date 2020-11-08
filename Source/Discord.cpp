#include "stdafx.h"
#include "discord.h"
#include "Discord/include/discord_rpc.h"
#include "Discord/include/discord_register.h"
#pragma comment(lib, "Discord/lib/discord-rpc.lib")

DiscordRichPresence discordPresence;
void UpdatePresence()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "Grand Theft Auto V";
    discordPresence.startTimestamp = 112343;
    discordPresence.largeImageKey = "512512";
    discordPresence.largeImageText = "Version : 1.0";
    discordPresence.smallImageKey = "512";
    discordPresence.smallImageText = "Private";
    discordPresence.partyId = "h";
    Discord_UpdatePresence(&discordPresence);
}

void Initialize()
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize("771715558172524544", &handlers, TRUE, nullptr);
}

void Shutdown()
{
	Discord_Shutdown();
}

void DiscordMain()
{
	Initialize();
	UpdatePresence();
}