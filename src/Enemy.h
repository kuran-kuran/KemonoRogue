#ifndef ENEMY_H
#define ENEMY_H

//	TinyScreen 256 Color picture data
//	CeruleanSmallBlue
//	24 x 12 dot
const unsigned char CeruleanSmallBlue[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0xAC, 0x20, 0x00, 0x20, 0xAC, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0xF0, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0xAC, 0x20, 0xAC, 0xF0, 0xF0, 0xF0, 0xAC, 0x20, 0xAC, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0xF0, 0xF5, 0xFF, 0xF5, 0xF0, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0xF0, 0xAC, 0x20, 0x20, 0x20, 0xAC, 0xF0, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0xF0, 0xFF, 0x20, 0xFF, 0xF0, 0x20, 0x00, 0x00, 0x00, 0x20, 0xAC, 0x20, 0xAC, 0xF0, 0xF0, 0xF0, 0xAC, 0x20, 0xAC, 0x20, 0x00,
	0x00, 0x00, 0x20, 0xAC, 0xF5, 0xFF, 0xF5, 0xAC, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xF0, 0xF5, 0xFF, 0xF5, 0xF0, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0xAC, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xF0, 0xFF, 0x20, 0xFF, 0xF0, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0xF0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xAC, 0xF5, 0xFF, 0xF5, 0xAC, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xAC, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanSmallGreen
//	24 x 12 dot
const unsigned char CeruleanSmallGreen[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x14, 0x20, 0x00, 0x20, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x1C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x1C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x14, 0x20, 0x14, 0x1C, 0x1C, 0x1C, 0x14, 0x20, 0x14, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x1C, 0x7E, 0xFF, 0x7E, 0x1C, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x1C, 0x14, 0x20, 0x20, 0x20, 0x14, 0x1C, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x1C, 0xFF, 0x20, 0xFF, 0x1C, 0x20, 0x00, 0x00, 0x00, 0x20, 0x14, 0x20, 0x14, 0x1C, 0x1C, 0x1C, 0x14, 0x20, 0x14, 0x20, 0x00,
	0x00, 0x00, 0x20, 0x14, 0x7E, 0xFF, 0x7E, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x1C, 0x7E, 0xFF, 0x7E, 0x1C, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0x14, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x1C, 0xFF, 0x20, 0xFF, 0x1C, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x1C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x14, 0x7E, 0xFF, 0x7E, 0x14, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x14, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanSmallYellow
//	24 x 12 dot
const unsigned char CeruleanSmallYellow[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x12, 0x20, 0x00, 0x20, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x1B, 0x20, 0x20, 0x20, 0x20, 0x20, 0x1B, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x12, 0x20, 0x12, 0x1B, 0x1B, 0x1B, 0x12, 0x20, 0x12, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x1B, 0x7F, 0xFF, 0x7F, 0x1B, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x1B, 0x12, 0x20, 0x20, 0x20, 0x12, 0x1B, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x1B, 0xFF, 0x20, 0xFF, 0x1B, 0x20, 0x00, 0x00, 0x00, 0x20, 0x12, 0x20, 0x12, 0x1B, 0x1B, 0x1B, 0x12, 0x20, 0x12, 0x20, 0x00,
	0x00, 0x00, 0x20, 0x12, 0x7F, 0xFF, 0x7F, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x1B, 0x7F, 0xFF, 0x7F, 0x1B, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0x12, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x1B, 0xFF, 0x20, 0xFF, 0x1B, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x1B, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x12, 0x7F, 0xFF, 0x7F, 0x12, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x12, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanSmallRed
//	24 x 12 dot
const unsigned char CeruleanSmallRed[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x02, 0x20, 0x00, 0x20, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x03, 0x20, 0x20, 0x20, 0x20, 0x20, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x02, 0x20, 0x02, 0x03, 0x03, 0x03, 0x02, 0x20, 0x02, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x03, 0x6F, 0xFF, 0x6F, 0x03, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x03, 0x02, 0x20, 0x20, 0x20, 0x02, 0x03, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x03, 0xFF, 0x20, 0xFF, 0x03, 0x20, 0x00, 0x00, 0x00, 0x20, 0x02, 0x20, 0x02, 0x03, 0x03, 0x03, 0x02, 0x20, 0x02, 0x20, 0x00,
	0x00, 0x00, 0x20, 0x02, 0x6F, 0xFF, 0x6F, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x03, 0x6F, 0xFF, 0x6F, 0x03, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0x02, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x03, 0xFF, 0x20, 0xFF, 0x03, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x6F, 0xFF, 0x6F, 0x02, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x02, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanSmallPurple
//	24 x 12 dot
const unsigned char CeruleanSmallPurple[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x20, 0xE6, 0x20, 0x00, 0x20, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0xF3, 0x20, 0x20, 0x20, 0x20, 0x20, 0xF3, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0xE6, 0x20, 0xE6, 0xF3, 0xF3, 0xF3, 0xE6, 0x20, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0xF3, 0xFB, 0xFF, 0xFB, 0xF3, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0xF3, 0xE6, 0x20, 0x20, 0x20, 0xE6, 0xF3, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0xF3, 0xFF, 0x20, 0xFF, 0xF3, 0x20, 0x00, 0x00, 0x00, 0x20, 0xE6, 0x20, 0xE6, 0xF3, 0xF3, 0xF3, 0xE6, 0x20, 0xE6, 0x20, 0x00,
	0x00, 0x00, 0x20, 0xE6, 0xFB, 0xFF, 0xFB, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xF3, 0xFB, 0xFF, 0xFB, 0xF3, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0xE6, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xF3, 0xFF, 0x20, 0xFF, 0xF3, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0xF3, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xFB, 0xFF, 0xFB, 0xE6, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xE6, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanMediumBlue
//	24 x 12 dot
const unsigned char CeruleanMediumBlue[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xAC, 0xF0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xF0, 0xAC, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0xAC, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xAC, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x00, 0x20, 0xAC, 0xF0, 0xF0, 0xAC, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xAC, 0xF0, 0xF0, 0xAC, 0x20, 0x00, 0x20, 0x00,
	0x20, 0xF0, 0x20, 0xAC, 0xF0, 0xFF, 0xFF, 0xF0, 0xAC, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0xAC, 0xF0, 0xFF, 0xFF, 0xF0, 0xAC, 0x20, 0xF0, 0x20,
	0x20, 0xF0, 0x20, 0xAC, 0xFF, 0xB7, 0x20, 0xFF, 0xAC, 0x20, 0xF0, 0x20, 0x20, 0xF0, 0x20, 0xAC, 0xFF, 0xB7, 0x20, 0xFF, 0xAC, 0x20, 0xF0, 0x20,
	0x20, 0xAC, 0xAC, 0xAC, 0xFF, 0x20, 0x20, 0xFF, 0xAC, 0x20, 0xAC, 0x20, 0x20, 0xAC, 0x20, 0xAC, 0xFF, 0x20, 0x20, 0xFF, 0xAC, 0xAC, 0xAC, 0x20,
	0x00, 0x20, 0x20, 0xAC, 0xAC, 0xFF, 0xFF, 0xAC, 0xAC, 0x20, 0xAC, 0x20, 0x20, 0xAC, 0x20, 0xAC, 0xAC, 0xFF, 0xFF, 0xAC, 0xAC, 0x20, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x20, 0xAC, 0xAC, 0xAC, 0xAC, 0x20, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x20, 0xAC, 0xAC, 0xAC, 0xAC, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xAC, 0xF0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xF0, 0xAC, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanMediumGreen
//	24 x 12 dot
const unsigned char CeruleanMediumGreen[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x14, 0x1C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x1C, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x14, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x00, 0x20, 0x14, 0x1C, 0x1C, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x14, 0x1C, 0x1C, 0x14, 0x20, 0x00, 0x20, 0x00,
	0x20, 0x1C, 0x20, 0x14, 0x1C, 0xFF, 0xFF, 0x1C, 0x14, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0x14, 0x1C, 0xFF, 0xFF, 0x1C, 0x14, 0x20, 0x1C, 0x20,
	0x20, 0x1C, 0x20, 0x14, 0xFF, 0xB7, 0x20, 0xFF, 0x14, 0x20, 0x1C, 0x20, 0x20, 0x1C, 0x20, 0x14, 0xFF, 0xB7, 0x20, 0xFF, 0x14, 0x20, 0x1C, 0x20,
	0x20, 0x14, 0x14, 0x14, 0xFF, 0x20, 0x20, 0xFF, 0x14, 0x20, 0x14, 0x20, 0x20, 0x14, 0x20, 0x14, 0xFF, 0x20, 0x20, 0xFF, 0x14, 0x14, 0x14, 0x20,
	0x00, 0x20, 0x20, 0x14, 0x14, 0xFF, 0xFF, 0x14, 0x14, 0x20, 0x14, 0x20, 0x20, 0x14, 0x20, 0x14, 0x14, 0xFF, 0xFF, 0x14, 0x14, 0x20, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x14, 0x14, 0x14, 0x14, 0x20, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x20, 0x14, 0x14, 0x14, 0x14, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x14, 0x1C, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x1C, 0x14, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanMediumYellow
//	24 x 12 dot
const unsigned char CeruleanMediumYellow[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x12, 0x1B, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x1B, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x12, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x00, 0x20, 0x12, 0x1B, 0x1B, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x12, 0x1B, 0x1B, 0x12, 0x20, 0x00, 0x20, 0x00,
	0x20, 0x1B, 0x20, 0x12, 0x1B, 0xFF, 0xFF, 0x1B, 0x12, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0x12, 0x1B, 0xFF, 0xFF, 0x1B, 0x12, 0x20, 0x1B, 0x20,
	0x20, 0x1B, 0x20, 0x12, 0xFF, 0xB7, 0x20, 0xFF, 0x12, 0x20, 0x1B, 0x20, 0x20, 0x1B, 0x20, 0x12, 0xFF, 0xB7, 0x20, 0xFF, 0x12, 0x20, 0x1B, 0x20,
	0x20, 0x12, 0x12, 0x12, 0xFF, 0x20, 0x20, 0xFF, 0x12, 0x20, 0x12, 0x20, 0x20, 0x12, 0x20, 0x12, 0xFF, 0x20, 0x20, 0xFF, 0x12, 0x12, 0x12, 0x20,
	0x00, 0x20, 0x20, 0x12, 0x12, 0xFF, 0xFF, 0x12, 0x12, 0x20, 0x12, 0x20, 0x20, 0x12, 0x20, 0x12, 0x12, 0xFF, 0xFF, 0x12, 0x12, 0x20, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x12, 0x12, 0x12, 0x12, 0x20, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x20, 0x12, 0x12, 0x12, 0x12, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x12, 0x1B, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x1B, 0x12, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanMediumRed
//	24 x 12 dot
const unsigned char CeruleanMediumRed[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x03, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x00, 0x20, 0x02, 0x03, 0x03, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x03, 0x03, 0x02, 0x20, 0x00, 0x20, 0x00,
	0x20, 0x03, 0x20, 0x02, 0x03, 0xFF, 0xFF, 0x03, 0x02, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0x02, 0x03, 0xFF, 0xFF, 0x03, 0x02, 0x20, 0x03, 0x20,
	0x20, 0x03, 0x20, 0x02, 0xFF, 0xB7, 0x20, 0xFF, 0x02, 0x20, 0x03, 0x20, 0x20, 0x03, 0x20, 0x02, 0xFF, 0xB7, 0x20, 0xFF, 0x02, 0x20, 0x03, 0x20,
	0x20, 0x02, 0x02, 0x02, 0xFF, 0x20, 0x20, 0xFF, 0x02, 0x20, 0x02, 0x20, 0x20, 0x02, 0x20, 0x02, 0xFF, 0x20, 0x20, 0xFF, 0x02, 0x02, 0x02, 0x20,
	0x00, 0x20, 0x20, 0x02, 0x02, 0xFF, 0xFF, 0x02, 0x02, 0x20, 0x02, 0x20, 0x20, 0x02, 0x20, 0x02, 0x02, 0xFF, 0xFF, 0x02, 0x02, 0x20, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x02, 0x02, 0x02, 0x02, 0x20, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x20, 0x02, 0x02, 0x02, 0x02, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x03, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanMediumPurple
//	24 x 12 dot
const unsigned char CeruleanMediumPurple[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xF3, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xF3, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x00, 0x20, 0xE6, 0xF3, 0xF3, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xF3, 0xF3, 0xE6, 0x20, 0x00, 0x20, 0x00,
	0x20, 0xF3, 0x20, 0xE6, 0xF3, 0xFF, 0xFF, 0xF3, 0xE6, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0xE6, 0xF3, 0xFF, 0xFF, 0xF3, 0xE6, 0x20, 0xF3, 0x20,
	0x20, 0xF3, 0x20, 0xE6, 0xFF, 0xB7, 0x20, 0xFF, 0xE6, 0x20, 0xF3, 0x20, 0x20, 0xF3, 0x20, 0xE6, 0xFF, 0xB7, 0x20, 0xFF, 0xE6, 0x20, 0xF3, 0x20,
	0x20, 0xE6, 0xE6, 0xE6, 0xFF, 0x20, 0x20, 0xFF, 0xE6, 0x20, 0xE6, 0x20, 0x20, 0xE6, 0x20, 0xE6, 0xFF, 0x20, 0x20, 0xFF, 0xE6, 0xE6, 0xE6, 0x20,
	0x00, 0x20, 0x20, 0xE6, 0xE6, 0xFF, 0xFF, 0xE6, 0xE6, 0x20, 0xE6, 0x20, 0x20, 0xE6, 0x20, 0xE6, 0xE6, 0xFF, 0xFF, 0xE6, 0xE6, 0x20, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x20, 0xE6, 0xE6, 0xE6, 0xE6, 0x20, 0x00, 0x20, 0x00, 0x00, 0x20, 0x00, 0x20, 0xE6, 0xE6, 0xE6, 0xE6, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xF3, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xF3, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanBigRed
//	24 x 12 dot
const unsigned char CeruleanBigRed[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x02, 0x02, 0x02, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x03, 0x03, 0x03, 0x02, 0x02, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0x02, 0x02, 0x02, 0x02, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x02, 0x6F, 0x03, 0x03, 0x03, 0x03, 0x01, 0x02, 0x20, 0x00,
	0x00, 0x20, 0x02, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x20, 0x00, 0x20, 0x02, 0x03, 0x03, 0x03, 0xFF, 0xFF, 0x03, 0x02, 0x02, 0x02, 0x20,
	0x20, 0x02, 0x03, 0x6F, 0x03, 0xFF, 0xFF, 0x03, 0x02, 0x02, 0x02, 0x20, 0x20, 0x02, 0x03, 0x03, 0xFF, 0xB7, 0x20, 0xFF, 0x02, 0x01, 0x02, 0x20,
	0x20, 0x02, 0x03, 0x03, 0xFF, 0xB7, 0x20, 0xFF, 0x02, 0x01, 0x02, 0x20, 0x20, 0x02, 0x02, 0x03, 0xFF, 0x20, 0x20, 0xFF, 0x02, 0x01, 0x02, 0x20,
	0x20, 0x02, 0x02, 0x03, 0xFF, 0x20, 0x20, 0xFF, 0x02, 0x01, 0x02, 0x20, 0x20, 0x02, 0x01, 0x02, 0x03, 0xFF, 0xFF, 0x02, 0x01, 0x01, 0x02, 0x20,
	0x20, 0x02, 0x01, 0x02, 0x03, 0xFF, 0xFF, 0x02, 0x01, 0x01, 0x02, 0x20, 0x00, 0x20, 0x02, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01, 0x02, 0x20, 0x00,
	0x00, 0x20, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x20, 0x00, 0x00, 0x00, 0x20, 0x02, 0x01, 0x01, 0x01, 0x01, 0x02, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0x02, 0x02, 0x02, 0x02, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x02, 0x02, 0x02, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanBigPurple
//	24 x 12 dot
const unsigned char CeruleanBigPurple[24 * 12] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xE6, 0xE6, 0xE6, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xF3, 0xF3, 0xF3, 0xE6, 0xE6, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0xE6, 0xE6, 0xE6, 0xE6, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xFB, 0xF3, 0xF3, 0xF3, 0xF3, 0xA5, 0xE6, 0x20, 0x00,
	0x00, 0x20, 0xE6, 0xF3, 0xF3, 0xF3, 0xF3, 0xE6, 0xE6, 0xE6, 0x20, 0x00, 0x20, 0xE6, 0xF3, 0xF3, 0xF3, 0xFF, 0xFF, 0xF3, 0xE6, 0xE6, 0xE6, 0x20,
	0x20, 0xE6, 0xF3, 0xFB, 0xF3, 0xFF, 0xFF, 0xF3, 0xE6, 0xE6, 0xE6, 0x20, 0x20, 0xE6, 0xF3, 0xF3, 0xFF, 0xB7, 0x20, 0xFF, 0xE6, 0xA5, 0xE6, 0x20,
	0x20, 0xE6, 0xF3, 0xF3, 0xFF, 0xB7, 0x20, 0xFF, 0xE6, 0xA5, 0xE6, 0x20, 0x20, 0xE6, 0xE6, 0xF3, 0xFF, 0x20, 0x20, 0xFF, 0xE6, 0xA5, 0xE6, 0x20,
	0x20, 0xE6, 0xE6, 0xF3, 0xFF, 0x20, 0x20, 0xFF, 0xE6, 0xA5, 0xE6, 0x20, 0x20, 0xE6, 0xA5, 0xE6, 0xF3, 0xFF, 0xFF, 0xE6, 0xA5, 0xA5, 0xE6, 0x20,
	0x20, 0xE6, 0xA5, 0xE6, 0xF3, 0xFF, 0xFF, 0xE6, 0xA5, 0xA5, 0xE6, 0x20, 0x00, 0x20, 0xE6, 0xA5, 0xE6, 0xE6, 0xA5, 0xA5, 0xA5, 0xE6, 0x20, 0x00,
	0x00, 0x20, 0xE6, 0xE6, 0xA5, 0xA5, 0xA5, 0xA5, 0xE6, 0xE6, 0x20, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xA5, 0xA5, 0xA5, 0xA5, 0xE6, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x20, 0xE6, 0xE6, 0xE6, 0xE6, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xE6, 0xE6, 0xE6, 0xE6, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00
};

//	TinyScreen 256 Color picture data
//	CeruleanBlack
//	96 x 12 dot
const unsigned char CeruleanBlack[96 * 12] =
{
	0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00, 0x00,
	0x00, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0x24, 0x24, 0x20, 0x00, 0x20, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0x24, 0x24, 0x20, 0x00, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00, 0x00, 0x20, 0x24, 0x24, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00, 0x20, 0x24, 0x24, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0x20, 0x00,
	0x00, 0x00, 0x20, 0x49, 0x24, 0x24, 0x24, 0x24, 0x49, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x49, 0x24, 0x24, 0x24, 0x24, 0x49, 0x20, 0x00, 0x00, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0xFF, 0x24, 0x20, 0x00, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x24, 0xFF, 0x24, 0x20, 0x00, 0x00, 0x20, 0x49, 0x24, 0x49, 0x49, 0x24, 0x49, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x49, 0x24, 0x49, 0x49, 0x24, 0x49, 0x20, 0x00, 0x00, 0x20, 0x24, 0xFF, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00, 0x20, 0x24, 0xFF, 0x24, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x00,
	0x00, 0x00, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x00, 0x00, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x92, 0x20, 0x92, 0x20, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x92, 0x20, 0x92, 0x20, 0x00, 0x00, 0x20, 0x24, 0x49, 0xFF, 0xFF, 0x49, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x49, 0xFF, 0xFF, 0x49, 0x24, 0x20, 0x00, 0x00, 0x20, 0x92, 0x20, 0x92, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x20, 0x92, 0x20, 0x92, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20,
	0x00, 0x00, 0x20, 0x24, 0x24, 0x49, 0x20, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x24, 0x49, 0x20, 0x24, 0x24, 0x20, 0x00, 0x00, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x24, 0xFF, 0x24, 0x20, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x24, 0xFF, 0x24, 0x20, 0x00, 0x00, 0x20, 0x24, 0xFF, 0xB7, 0x20, 0xFF, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0xFF, 0xB7, 0x20, 0xFF, 0x24, 0x20, 0x00, 0x00, 0x20, 0x24, 0xFF, 0x24, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x20, 0x24, 0xFF, 0x24, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20,
	0x00, 0x00, 0x20, 0x24, 0x24, 0x49, 0x20, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x24, 0x49, 0x20, 0x24, 0x24, 0x20, 0x00, 0x00, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x24, 0x24, 0x20, 0x00, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0xFF, 0x20, 0x20, 0xFF, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0xFF, 0x20, 0x20, 0xFF, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x24, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20, 0x00, 0x20, 0x24, 0x24, 0x20, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x20,
	0x00, 0x00, 0x20, 0x24, 0x49, 0x24, 0x20, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x24, 0x24, 0x49, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x24, 0xFF, 0xFF, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x24, 0xFF, 0xFF, 0x24, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00,
	0x00, 0x00, 0x20, 0x20, 0x24, 0x20, 0x24, 0x24, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x24, 0x24, 0x24, 0x24, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x24, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x24, 0x24, 0x24, 0x24, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x24, 0x24, 0x24, 0x24, 0x20, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x20, 0x24, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00,
	0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x20, 0x24, 0x20, 0x20, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x20, 0x20, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x20, 0x20, 0x24, 0x20, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x24, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00
};

#endif