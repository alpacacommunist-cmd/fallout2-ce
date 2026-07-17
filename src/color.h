#ifndef COLOR_H
#define COLOR_H

namespace fallout { 

typedef unsigned char Color;
typedef const char*(ColorFileNameManger)(const char*);
typedef void(ColorTransitionCallback)();

extern unsigned char _cmap[768];

extern unsigned char _systemCmap[256 * 3];
extern unsigned char _currentGammaTable[64];
extern unsigned char* _blendTable[256];
extern unsigned char _mappedColor[256];
extern Color colorMixAddTable[256][256];
extern Color intensityColorTable[256][256];
extern Color colorMixMulTable[256][256];
extern unsigned char _colorTable[32768];

int _calculateColor(int intensity, Color color);
int Color2RGB(Color c);
void colorPaletteFadeBetween(unsigned char* oldPalette, unsigned char* newPalette, int steps);
void colorPaletteSetTransitionCallback(ColorTransitionCallback* callback);
void _setSystemPalette(unsigned char* palette);
unsigned char* _getSystemPalette();
void _setSystemPaletteEntries(unsigned char* palette, int start, int end);
bool colorPaletteLoad(const char* path);
char* _colorError();
unsigned char* _getColorBlendTable(int ch);
void _freeColorBlendTable(int color);
void colorSetBrightness(double value);
bool _initColors();
void _colorsClose();

#define COLOR_LIGHT_RED _colorTable[0x7D4A]
#define COLOR_RED _colorTable[0x7C00]
#define COLOR_RED_2 _colorTable[0x7000]
#define COLOR_DARK_RED _colorTable[0x5C48]

#define COLOR_WHITE _colorTable[0x7FFF]
#define COLOR_WHITE_2 _colorTable[0x635F]

#define COLOR_LIGHT_GREY _colorTable[0x5294]
#define COLOR_LIGHT_GREY_2 _colorTable[0x4E54]
#define COLOR_GREY _colorTable[0x4631]
#define COLOR_GREY_2 _colorTable[0x3DEF]
#define COLOR_DARK_GREY _colorTable[0x2108]
#define COLOR_DARK_GREY_2 _colorTable[0x294A]
#define COLOR_DARK_GREY_3 _colorTable[0x1084]

#define COLOR_BLACK _colorTable[0x0000]
#define COLOR_BLACK_2 _colorTable[0x0002]

#define COLOR_LIGHT_PURPLE _colorTable[0x27FF]
#define COLOR_LIGHT_BLUE _colorTable[0x1971]
#define COLOR_BLUE _colorTable[0x001F]
#define COLOR_BLUE_2 _colorTable[0x0015]
#define COLOR_DULL_BLUE _colorTable[0x46F1]

#define COLOR_LIGHT_PINK _colorTable[0x7DEF]
#define COLOR_PINK _colorTable[0x7C1F]
#define COLOR_DULL_PINK _colorTable[0x79EF]

#define COLOR_LIGHT_GREEN _colorTable[0x01C0]
#define COLOR_LIGHT_GREEN_2 _colorTable[0x2264]
#define COLOR_LIGHT_GREEN_3 _colorTable[0x0300]
#define COLOR_GREEN _colorTable[0x03E0]
#define COLOR_DARK_GREEN _colorTable[0x01E0]
#define COLOR_DARK_GREEN_2 _colorTable[0x0521]
#define COLOR_GRASS_GREEN _colorTable[0x3DE5]

#define COLOR_LIGHT_YELLOW _colorTable[0x7FEB]
#define COLOR_LIGHT_GOLD _colorTable[0x7BA2]
#define COLOR_LIGHT_GOLD_2 _colorTable[0x77A8]
#define COLOR_YELLOW _colorTable[0x7E48]
#define COLOR_YELLOW_2 _colorTable[0x5263]
#define COLOR_SAND _colorTable[0x5609]
#define COLOR_GOLD _colorTable[0x77E1]
#define COLOR_DARK_YELLOW _colorTable[0x4A23]
#define COLOR_DARK_YELLOW_2 _colorTable[0x3983]
#define COLOR_DARK_YELLOW_3 _colorTable[0x49E5]
#define COLOR_DARK_YELLOW_4 _colorTable[0x4A21]
#define COLOR_DULL_YELLOW _colorTable[0x7EEF]

#define COLOR_LIGHT_BROWN _colorTable[0x3102]
#define COLOR_LIGHT_BROWN_2 _colorTable[0x56AB]
#define COLOR_DULL_BROWN _colorTable[0x3569]

} // namespace fallout

#endif /* COLOR_H */
