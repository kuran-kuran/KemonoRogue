#ifndef CHARACTER_H
#define CHARACTER_H

//	TinyScreen 256 Color picture data
//	Path1
//	12 x 12 dot
const unsigned char Path1[12 * 12] =
{
	0x57, 0x77, 0x77, 0x77, 0x77, 0x57, 0x57, 0x57, 0x57, 0x57, 0x57, 0x57,
	0x77, 0x77, 0x77, 0x77, 0x77, 0x57, 0x57, 0x53, 0x53, 0x53, 0x53, 0x57,
	0x77, 0x77, 0x77, 0x77, 0x53, 0x57, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
	0x53, 0x77, 0x77, 0x53, 0x57, 0x57, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53,
	0x57, 0x53, 0x53, 0x57, 0x77, 0x77, 0x57, 0x57, 0x53, 0x53, 0x53, 0x53,
	0x57, 0x57, 0x57, 0x77, 0x77, 0x77, 0x77, 0x77, 0x57, 0x53, 0x53, 0x57,
	0x53, 0x57, 0x57, 0x77, 0x77, 0x77, 0x77, 0x77, 0x57, 0x57, 0x57, 0x57,
	0x53, 0x53, 0x57, 0x53, 0x77, 0x77, 0x77, 0x57, 0x77, 0x77, 0x77, 0x53,
	0x53, 0x53, 0x57, 0x57, 0x53, 0x53, 0x57, 0x77, 0x77, 0x77, 0x77, 0x53,
	0x53, 0x77, 0x57, 0x53, 0x53, 0x53, 0x77, 0x77, 0x77, 0x77, 0x53, 0x57,
	0x77, 0x77, 0x77, 0x53, 0x53, 0x53, 0x77, 0x77, 0x77, 0x77, 0x53, 0x57,
	0x77, 0x77, 0x77, 0x77, 0x57, 0x57, 0x57, 0x57, 0x53, 0x53, 0x57, 0x57
};

//	TinyScreen 256 Color picture data
//	Wall1
//	12 x 12 dot
const unsigned char Wall1[12 * 12] =
{
	0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25,
	0x25, 0x4E, 0x4E, 0x93, 0x4E, 0x4E, 0x4E, 0x4E, 0x93, 0x4E, 0x4E, 0x25,
	0x25, 0x4E, 0x4E, 0x4E, 0x93, 0x93, 0x93, 0x93, 0x4E, 0x4E, 0x4E, 0x25,
	0x25, 0x4E, 0x4E, 0x93, 0x4E, 0x93, 0x4E, 0x93, 0x93, 0x4E, 0x4E, 0x25,
	0x25, 0x4E, 0x4E, 0x93, 0x4E, 0x93, 0x4E, 0x93, 0x93, 0x4E, 0x4E, 0x25,
	0x25, 0x4E, 0x4E, 0x4E, 0x93, 0x93, 0x4E, 0x93, 0x4E, 0x4E, 0x4E, 0x25,
	0x25, 0x4E, 0x4E, 0x4E, 0x4E, 0x4E, 0x4E, 0x4E, 0x29, 0x29, 0x4E, 0x25,
	0x25, 0x29, 0x29, 0x29, 0x49, 0x49, 0x49, 0x49, 0x4E, 0x4E, 0x29, 0x25,
	0x25, 0x29, 0x29, 0x29, 0x49, 0x49, 0x49, 0x49, 0x49, 0x29, 0x29, 0x25,
	0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25,
	0x25, 0x29, 0x29, 0x49, 0x49, 0x25, 0x29, 0x29, 0x29, 0x29, 0x49, 0x25,
	0x25, 0x29, 0x29, 0x29, 0x29, 0x25, 0x29, 0x29, 0x29, 0x29, 0x29, 0x25
};

//	TinyScreen 256 Color picture data
//	Path2
//	12 x 12 dot
const unsigned char Path2[12 * 12] =
{
	0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0x61, 0x61, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5,
	0xA5, 0xA5, 0xA5, 0xA5, 0x61, 0x61, 0x61, 0x61, 0xA5, 0xA5, 0xA5, 0xA5,
	0xA5, 0xA5, 0xA5, 0x61, 0x61, 0x85, 0x85, 0x61, 0x61, 0xA5, 0xA5, 0xA5,
	0xA5, 0xA5, 0x61, 0x85, 0x85, 0xA5, 0xA5, 0x85, 0x85, 0x61, 0xA5, 0xA5,
	0xA5, 0x61, 0x61, 0xA5, 0xA5, 0x61, 0x61, 0xA5, 0xA5, 0x61, 0x61, 0xA5,
	0x61, 0x61, 0x61, 0x61, 0x61, 0xA5, 0xA5, 0x61, 0x61, 0x61, 0x61, 0x61,
	0x61, 0x61, 0x61, 0x85, 0xA5, 0xA5, 0xA5, 0xA5, 0x85, 0x61, 0x61, 0x61,
	0xA5, 0x61, 0x61, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0x61, 0x61, 0xA5,
	0xA5, 0xA5, 0x61, 0x85, 0xA5, 0xA5, 0xA5, 0xA5, 0x85, 0x61, 0xA5, 0xA5,
	0xA5, 0xA5, 0xA5, 0x61, 0x85, 0xA5, 0xA5, 0x85, 0x61, 0xA5, 0xA5, 0xA5,
	0xA5, 0xA5, 0xA5, 0xA5, 0x61, 0x61, 0x61, 0x61, 0xA5, 0xA5, 0xA5, 0xA5,
	0xA5, 0xA5, 0xA5, 0xA5, 0xA5, 0x61, 0x61, 0xA5, 0xA5, 0xA5, 0xA5, 0xA5
};

//	TinyScreen 256 Color picture data
//	Wall2
//	12 x 12 dot
const unsigned char Wall2[12 * 12] =
{
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x20, 0x61, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0x61, 0x20,
	0x20, 0xE6, 0xE6, 0xEB, 0xE6, 0xE6, 0xE6, 0xE6, 0xEB, 0xE6, 0xE6, 0x20,
	0x20, 0xE6, 0xE6, 0xE6, 0xEB, 0xEB, 0xEB, 0xEB, 0xE6, 0xE6, 0xE6, 0x20,
	0x20, 0xE6, 0xE6, 0xEB, 0xE6, 0xEB, 0xE6, 0xEB, 0xEB, 0xE6, 0xE6, 0x20,
	0x20, 0xE6, 0xE6, 0xEB, 0xE6, 0xEB, 0xE6, 0xEB, 0xEB, 0xE6, 0xE6, 0x20,
	0x20, 0xE6, 0xE6, 0xE6, 0xEB, 0xEB, 0xE6, 0xEB, 0xE6, 0xE6, 0xE6, 0x20,
	0x20, 0xA5, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0x61, 0x20,
	0x20, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0x20,
	0x20, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0x20,
	0x20, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0x20,
	0x20, 0x20, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x61, 0xA5, 0x20, 0x20
};

//	TinyScreen 256 Color picture data
//	Path3
//	12 x 12 dot
const unsigned char Path3[12 * 12] =
{
	0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7,
	0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7,
	0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
	0xB7, 0xB7, 0xB7, 0x92, 0x96, 0x96, 0x96, 0x96, 0x96, 0xB7, 0xB7, 0xB7,
	0xB7, 0xB7, 0xB7, 0x92, 0x96, 0x96, 0x96, 0x96, 0x96, 0xB7, 0xB7, 0xB7,
	0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
	0x92, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x92, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7,
	0x92, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x92, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7,
	0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
	0xB7, 0xB7, 0xB7, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x92, 0xB7, 0xB7,
	0xB7, 0xB7, 0xB7, 0x96, 0x96, 0x96, 0x96, 0x96, 0x96, 0x92, 0xB7, 0xB7,
	0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92
};

//	TinyScreen 256 Color picture data
//	Wall3
//	12 x 12 dot
const unsigned char Wall3[12 * 12] =
{
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x20, 0x02, 0x02, 0x21, 0x21, 0x02, 0x02, 0x21, 0x21, 0x02, 0x02, 0x20,
	0x20, 0x21, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x20,
	0x20, 0x21, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x20,
	0x20, 0x02, 0x02, 0x21, 0x21, 0x02, 0x02, 0x21, 0x21, 0x02, 0x02, 0x20,
	0x20, 0x22, 0x22, 0x21, 0x21, 0x22, 0x22, 0x21, 0x21, 0x22, 0x22, 0x20,
	0x20, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x20,
	0x20, 0x22, 0x22, 0x01, 0x01, 0x22, 0x22, 0x01, 0x01, 0x22, 0x22, 0x20,
	0x20, 0x22, 0x22, 0x21, 0x21, 0x22, 0x22, 0x21, 0x21, 0x22, 0x22, 0x20,
	0x20, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x23, 0x20,
	0x20, 0x22, 0x22, 0x01, 0x01, 0x22, 0x22, 0x01, 0x01, 0x22, 0x22, 0x20,
	0x20, 0x22, 0x22, 0x21, 0x21, 0x22, 0x22, 0x21, 0x21, 0x22, 0x22, 0x20
};

//	TinyScreen 256 Color picture data
//	Exit
//	12 x 12 dot
const unsigned char Exit[12 * 12] =
{
	0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x20, 0x20, 0x20, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x20, 0x20, 0x20, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x49, 0x49, 0x49, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x49, 0x49, 0x49, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x49, 0x49, 0x49, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x49, 0x49, 0x49, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x49, 0x49, 0x49, 0x20, 0x25,
	0x25, 0xB7, 0xB7, 0xB7, 0x92, 0x92, 0x92, 0x49, 0x49, 0x49, 0x20, 0x25,
	0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25
};

//	TinyScreen 256 Color picture data
//	Treasure
//	12 x 12 dot
const unsigned char Treasure[12 * 12] =
{
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x20, 0x3F, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x3F, 0x20,
	0x20, 0xDF, 0xB3, 0xDF, 0xB3, 0xB3, 0xB3, 0xB3, 0x3F, 0xB3, 0xDF, 0x20,
	0x20, 0xDF, 0x23, 0x23, 0x3F, 0x23, 0x23, 0xDF, 0x23, 0x23, 0xDF, 0x20,
	0x20, 0x3F, 0x23, 0x3F, 0x23, 0x23, 0x23, 0x23, 0x3F, 0x23, 0x3F, 0x20,
	0x20, 0x3F, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x3F, 0x20,
	0x20, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x20,
	0x20, 0x53, 0x02, 0x02, 0x02, 0x3F, 0x3F, 0x02, 0x02, 0x02, 0x53, 0x20,
	0x20, 0x53, 0x22, 0x53, 0x22, 0x53, 0x53, 0x02, 0x53, 0x22, 0x53, 0x20,
	0x20, 0x53, 0x53, 0x53, 0x22, 0x02, 0x02, 0x02, 0x53, 0x53, 0x53, 0x20,
	0x20, 0x53, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x53, 0x20,
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
};

//	TinyScreen 256 Color picture data
//	TreasureOpen
//	12 x 12 dot
const unsigned char TreasureOpen[12 * 12] =
{
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
	0x20, 0xDF, 0xB3, 0xB3, 0xDF, 0xB3, 0xB3, 0xDF, 0xB3, 0xB3, 0xDF, 0x20,
	0x20, 0x3F, 0x23, 0x3F, 0x23, 0x23, 0x23, 0x23, 0x3F, 0x23, 0x3F, 0x20,
	0x20, 0x53, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x53, 0x20,
	0x20, 0x3F, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x53, 0x20,
	0x20, 0x3F, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x53, 0x20,
	0x20, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x20,
	0x20, 0x53, 0x02, 0x02, 0x02, 0x3F, 0x3F, 0x02, 0x02, 0x02, 0x53, 0x20,
	0x20, 0x53, 0x22, 0x53, 0x22, 0x53, 0x53, 0x02, 0x53, 0x22, 0x53, 0x20,
	0x20, 0x53, 0x53, 0x53, 0x22, 0x02, 0x02, 0x02, 0x53, 0x53, 0x53, 0x20,
	0x20, 0x53, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x53, 0x20,
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
};

//	TinyScreen 256 Color picture data
//	SwitchOff
//	12 x 12 dot
const unsigned char SwitchOff[12 * 12] =
{
	0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7,
	0xB7, 0x92, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0xB7, 0xB7, 0x49, 0x49, 0xB7, 0xB7, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0x49, 0x49, 0x92, 0x92, 0x49, 0x49, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x20, 0x92, 0xB7,
	0xB7, 0x92, 0x20, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x20, 0x92, 0xB7,
	0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7
};

//	TinyScreen 256 Color picture data
//	SwitchOn
//	12 x 12 dot
const unsigned char SwitchOn[12 * 12] =
{
	0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7,
	0xB7, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xB7,
	0xB7, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xB7,
	0xB7, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0xB7,
	0xB7, 0x92, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x92, 0xB7,
	0xB7, 0x92, 0x49, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x49, 0x92, 0xB7,
	0xB7, 0x92, 0x49, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x49, 0x92, 0xB7,
	0xB7, 0x92, 0x49, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x49, 0x92, 0xB7,
	0xB7, 0x92, 0x49, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0x49, 0x92, 0xB7,
	0xB7, 0x92, 0x49, 0xB7, 0xB7, 0x49, 0x49, 0xB7, 0xB7, 0x49, 0x92, 0xB7,
	0xB7, 0x92, 0x49, 0x25, 0x25, 0x25, 0x25, 0x25, 0x25, 0x49, 0x92, 0xB7,
	0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7, 0xB7
};

#endif
